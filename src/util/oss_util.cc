/*
 * =============================================================================
 *
 *       Filename:  generate_authentication.c
 *
 *    Description:  generate authentication
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#include <assert.h>

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <map>

#define _OSS_CONSTANTS_H
#include <osscpp/oss_constants.h>
#undef _OSS_CONSTANTS_H

#include <osscpp/util/oss_util.h>

#include <src/lib/base64.h>
#include <src/lib/hmac.h>
#include <src/lib/memxor.h>
#include <src/lib/md5.h>
#include <src/lib/sha1.h>
#include <src/lib/tinyxml2.h>

#define HMAC_SHA1_OUT_LEN 21
#define SIGNED_VALUE_LEN 65

using namespace std;
using namespace tinyxml2;

namespace osscpp {

const string 
Util::GenerateAuthentication(const string &access_key, 
		const string &method,
		map<string, string> &default_headers,
		map<string, string> &user_headers,
		const string &resource)
{

	string content_md5;
	string content_type;
	string date;
    string canonicalized_headers;
	string string_to_sign;

	/* *
	 * hmac-sha1 结果存放
	 * */
	unsigned char *hmac_sha1_out = (unsigned char *)malloc(sizeof(unsigned char) * HMAC_SHA1_OUT_LEN);

	/* *
	 * base64 处理后的签名返回值
	 * */
	char *signed_value = (char *)malloc(sizeof(char) * SIGNED_VALUE_LEN);

	content_md5 = default_headers[OSS_CONTENT_MD5];
	content_type = default_headers[OSS_CONTENT_TYPE];
	date = default_headers[OSS_DATE];
	
	map<string, string> user_headers_new;

	if (user_headers.size() != 0) {
		map<string, string>::iterator iter;
		for(iter = user_headers.begin(); iter != user_headers.end(); iter ++) {
			string key = (iter->first);
			string value = (iter->second);
			transform(key.begin(), key.end(), key.begin(), ::tolower);
			user_headers_new.insert(pair<string, string>(key, value));
		}
		for(iter = user_headers_new.begin(); iter != user_headers_new.end(); iter++) {
			canonicalized_headers += iter->first + ":" + iter->second + "\n";
		}
	}

	if (content_md5 != "" && content_type != "") {
		string_to_sign = method + "\n" + content_md5 + "\n" +content_type +
			"\n" + date + "\n" + canonicalized_headers + resource;
	} else if (content_md5 == "" && content_type != "") {
		string_to_sign = method + "\n" + "\n" +content_type +
			"\n" + date + "\n" + canonicalized_headers + resource;
	} else if (content_md5 == "" && content_type == "") {
		string_to_sign = method + "\n" + "\n" +
			"\n" + date + "\n" + canonicalized_headers + resource;
	}

	hmac_sha1((const char *)access_key.c_str(), access_key.size(), 
			(const char *)string_to_sign.c_str(),
			string_to_sign.size(), hmac_sha1_out);
	base64_encode((const char *)hmac_sha1_out, HMAC_SHA1_OUT_LEN - 1, signed_value, SIGNED_VALUE_LEN);

	string ret = signed_value;
	/* *
	 * clean up.
	 * */
	free(hmac_sha1_out);
	free(signed_value);

	return ret;
}

const char *
Util::GetMessageFromRetcode(OSS_ERROR_CODE retcode)
{
	if (retcode == OK) {
		return "OK";
	} else if(retcode == ACCESS_DENIED) {
		return "AccessDenied";
	} else if(retcode == BUCKET_ALREADY_EXISTS) {
		return "BucketAlreadyExists";
	} else if(retcode == BUCKET_NOT_EMPTY) {
		return "BucketNotEmpty";
	} else if(retcode == ENTITY_TOO_LARGE) {
		return "EntityTooLarge";
	} else if(retcode == ENTITY_TOO_SMALL) {
		return "EntityTooSmall";
	} else if(retcode == FILE_GROUP_TOO_LARGE) {
		return "FileGroupTooLarge";
	} else if(retcode == FILE_PART_NOT_EXIST) {
		return "FilePartNotExist";
	} else if(retcode == FILE_PART_STALE) {
		return "FilePartStale";
	} else if(retcode == INTERNAL_ERROR) {
		return "InternalError";
	} else if(retcode == INVALID_ACCESS_KEY_ID) {
		return "InvalidAccessKeyId";
	} else if(retcode == INVALID_ARGUMENT) {
		return "InvalidArgument";
	} else if(retcode == INVALID_BUCKET_NAME) {
		return "InvalidBucketName";
	} else if(retcode == INVALID_DIGEST) {
		return "InvalidDigest";
	} else if(retcode == INVALID_OBJECT_NAME) {
		return "InvalidObjectName";
	} else if(retcode == INVALID_PART) {
		return "InvalidPart";
	} else if(retcode == INVALID_PART_ORDER) {
		return "InvalidPartOrder";
	} else if(retcode == MALFORMED_XML) {
		return "MalformedXML";
	} else if(retcode == METHOD_NOT_ALLOWED) {
		return "MethodNotAllowed";
	} else if(retcode == MISSING_ARGUMENT) {
		return "MissingArgument";
	} else if(retcode == MISSING_CONTENT_LENGTH) {
		return "MissingContentLength";
	} else if (retcode == NO_CONTENT) {
		return "NoContent";
	}else if(retcode == NO_SUCH_BUCKET) {
		return "NoSuchBucket";
	} else if(retcode == NO_SUCH_KEY) {
		return "NoSuchKey";
	} else if(retcode == NO_SUCH_UPLOAD) {
		return "NoSuchUpload";
	} else if(retcode == NOT_IMPLEMENTED) {
		return "NotImplemented";
	} else if(retcode == PRECONDITION_FAILED) {
		return "PreconditionFailed";
	} else if(retcode == REQUEST_TIME_TOO_SKEWED) {
		return "RequestTimeTooSkewed";
	} else if(retcode == REQUEST_TIMEOUT) {
		return "RequestTimeout";
	} else if(retcode ==SIGNATURE_DOES_NOT_MATCH) {
		return "SignatureDoesNotMatch";
	} else if(retcode == TOO_MANY_BUCKETS) {
		return "TooManyBuckets";
	} else if(retcode == FILE_PART_INTERITY) {
		return "FilePartInterity";
	} else if(retcode == FILE_NOT_FOUND) {
		return "FileNotFound";
	} else if(retcode == NOT_MODIFIED) {
		return "NotModified";
	} else if(retcode == FILE_TOO_LARGE) {
		return "FileTooLarge";
	} else if(retcode == IO_ERROR) {
		return "IOError";
	} else {
		return "UnknowError";
	}
}

OSS_ERROR_CODE
Util::GetRetcodeFromResponse(const char *response)
{
	if (response != NULL && strlen(response) == 0)
		return (OSS_ERROR_CODE)-1;

	OSS_ERROR_CODE ret;

	XMLDocument doc;
	doc.Parse(response);
	XMLElement *codeElement = doc.FirstChildElement("Error")->FirstChildElement("Code");
	const char *code = codeElement->GetText();

	ret = GetRetcodeFromRetinfo(code);

	return ret;
}

OSS_ERROR_CODE
Util::GetRetcodeFromRetinfo(const char *retinfo) 
{
	OSS_ERROR_CODE retcode;
	if(strcmp(retinfo, "AccessDenied") == 0) {
		retcode = ACCESS_DENIED;
	} else if(strcmp(retinfo, "BucketAlreadyExists") == 0) {
		retcode = BUCKET_ALREADY_EXISTS;
	} else if(strcmp(retinfo, "BucketNotEmpty") == 0) {
		retcode = BUCKET_NOT_EMPTY;
	} else if(strcmp(retinfo, "EntityTooLarge") == 0) {
		retcode = ENTITY_TOO_LARGE;
	} else if(strcmp(retinfo, "EntityTooSmall") == 0) {
		retcode = ENTITY_TOO_SMALL;
	} else if(strcmp(retinfo, "FileGroupTooLarge") == 0) {
		retcode = FILE_GROUP_TOO_LARGE;
	} else if(strcmp(retinfo, "FilePartNotExist") == 0) {
		retcode = FILE_PART_NOT_EXIST;
	} else if(strcmp(retinfo, "FilePartStale") == 0) {
		retcode = FILE_PART_STALE;
	} else if(strcmp(retinfo, "InternalError") == 0) {
		retcode = INTERNAL_ERROR;
	} else if(strcmp(retinfo, "InvalidAccessKeyId") == 0) {
		retcode = INVALID_ACCESS_KEY_ID;
	} else if(strcmp(retinfo, "InvalidArgument") == 0) {
		retcode = INVALID_ARGUMENT;
	} else if(strcmp(retinfo, "InvalidBucketName") == 0) {
		retcode = INVALID_BUCKET_NAME;
	} else if(strcmp(retinfo, "InvalidDigest") == 0) {
		retcode = INVALID_DIGEST;
	} else if(strcmp(retinfo, "InvalidObjectName") == 0) {
		retcode = INVALID_OBJECT_NAME;
	} else if(strcmp(retinfo, "InvalidPart") == 0) {
		retcode = INVALID_PART;
	} else if(strcmp(retinfo, "InvalidPartOrder") == 0) {
		retcode = INVALID_PART_ORDER;
	} else if(strcmp(retinfo, "MalformedXML") == 0) {
		retcode = MALFORMED_XML;
	} else if(strcmp(retinfo, "MethodNotAllowed") == 0) {
		retcode = METHOD_NOT_ALLOWED;
	} else if(strcmp(retinfo, "MissingArgument") == 0) {
		retcode = MISSING_ARGUMENT;
	} else if(strcmp(retinfo, "MissingContentLength") == 0) {
		retcode = MISSING_CONTENT_LENGTH;
	} else if(strcmp(retinfo, "NoSuchBucket") == 0) {
		retcode = NO_SUCH_BUCKET;
	} else if(strcmp(retinfo, "NoSuchKey") == 0) {
		retcode = NO_SUCH_KEY;
	} else if(strcmp(retinfo, "NoSuchUpload") == 0) {
		retcode = NO_SUCH_UPLOAD;
	} else if(strcmp(retinfo, "NotImplemented") == 0) {
		retcode = NOT_IMPLEMENTED;
	} else if(strcmp(retinfo, "PreconditionFailed") == 0) {
		retcode = PRECONDITION_FAILED;
	} else if(strcmp(retinfo, "RequestTimeTooSkewed") == 0) {
		retcode = REQUEST_TIME_TOO_SKEWED;
	} else if(strcmp(retinfo, "RequestTimeout") == 0) {
		retcode = REQUEST_TIMEOUT;
	} else if(strcmp(retinfo, "SignatureDoesNotMatch") == 0) {
		retcode = SIGNATURE_DOES_NOT_MATCH;
	} else if(strcmp(retinfo, "TooManyBuckets") == 0) {
		retcode = TOO_MANY_BUCKETS;
	} else if(strcmp(retinfo, "FilePartInterity") == 0) {
		retcode = FILE_PART_INTERITY;
	} else if(strcmp(retinfo, "FileNotFound") == 0) {
		retcode = FILE_NOT_FOUND;
	} else if(strcmp(retinfo, "NotModified") == 0) {
		retcode = NOT_MODIFIED;
	} else if(strcmp(retinfo, "FileTooLarge") == 0) {
		retcode = FILE_TOO_LARGE;
	} else if(strcmp(retinfo, "IOError") == 0) {
		retcode = IO_ERROR;
	}else {
		retcode = (OSS_ERROR_CODE) 1000;
	}
	return retcode;
}

long Util::GetFileSize(FILE *fp)
{
    long int save_pos;
    long size_of_file;
    /* Save the current position. */
    save_pos = ftell(fp);
    /* Jump to the end of the file. */
    fseek(fp, 0L, SEEK_END);
    /* Get the end position. */
    size_of_file = ftell(fp);
    /* Jump back to the original position. */
    fseek(fp, save_pos, SEEK_SET);
    return size_of_file;
}

char * Util::ComputeMD5Digest(const void *ptr, unsigned int len)
{
	char md5_digest[17];
	md5_state_t md5_state;

	char *base64_md5 = NULL;

	memset(md5_digest, '\0', 17);

	md5_init(&md5_state);
	md5_append(&md5_state, static_cast<const md5_byte_t *>(ptr), len);
	md5_finish(&md5_state, (md5_byte_t *)md5_digest);

	base64_md5 = (char *) malloc(sizeof(char) * 65);
	memset(base64_md5, 0, 65);
	base64_encode(md5_digest, 16, base64_md5, 65);

	return base64_md5;
}
}
