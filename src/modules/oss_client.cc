/*
 * =============================================================================
 *
 *       Filename:  oss_client.cc
 *
 *    Description:  Client.
 *
 *        Created:  09/25/2012 03:27:52 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <curl/curl.h>

#include "oss_bucket_operation.h"
#include "oss_object_operation.h"
#include "oss_multipart_upload_operation.h"
#include "oss_object_group_operation.h"
#include "oss_request_param.h"
#include "oss_callback.h"

#define _OSS_CLIENT_H
#include <osscpp/modules/oss_client.h>
#undef _OSS_CLIENT_H

namespace osscpp {

using namespace std;

void Client::CreateBucket(const string &bucket_name,
		OSS_ERROR_CODE &retcode)
{
	retcode = (OSS_ERROR_CODE)-1;

	Request *user_data = new Request(0, MAX_RECV_BUFFER_SIZE, MAX_HEADER_BUFFER_SIZE);
	
	string resource = "/";
	string url = endpoint_;
	string header_host = "Host: ";
	string header_date = "Date: ";
	string now = Util::GetGmtTime();

	resource += bucket_name;
	url += resource;
	header_host += endpoint_;
	header_date += now;

	map<string, string> user_headers;
	map<string, string> default_headers;
	default_headers.insert(pair<string, string>(OSS_DATE, now));

	string sign = Util::GenerateAuthentication(access_key_, OSS_HTTP_PUT, default_headers, user_headers, resource);
	string header_auth = "Authorization: OSS " + access_id_ + ":" + sign;

	struct curl_slist *http_headers = NULL;
	http_headers = curl_slist_append(http_headers, header_host.c_str());
	http_headers = curl_slist_append(http_headers, header_date.c_str());
	http_headers = curl_slist_append(http_headers, header_auth.c_str());

	/**
	 * 发送请求
	 */
	BucketOperation::DoRequest(OSS_HTTP_PUT, resource, url, http_headers, user_data);
	curl_slist_free_all(http_headers);

	if (user_data->header_buffer()->code == 200) {
		retcode = OK;
	} else {
		retcode = Util::GetRetcodeFromResponse(user_data->recv_buffer()->ptr);
	}
	delete user_data;
}

vector<Bucket>
Client::ListBuckets(OSS_ERROR_CODE &retcode)
{
	retcode = (OSS_ERROR_CODE)-1;

	Request *user_data = new Request(0, MAX_RECV_BUFFER_SIZE, MAX_HEADER_BUFFER_SIZE);
	
	string resource = "/";
	string url = endpoint_;
	string header_host = "Host: ";
	string header_date = "Date: ";
	string now = Util::GetGmtTime();

	header_host += endpoint_;
	header_date += now;

	map<string, string> user_headers;
	map<string, string> default_headers;
	default_headers.insert(pair<string, string>(OSS_DATE, now));

	string sign = Util::GenerateAuthentication(access_key_, OSS_HTTP_GET, default_headers, user_headers, resource);
	string header_auth = "Authorization: OSS " + access_id_ + ":" + sign;

	struct curl_slist *http_headers = NULL;
	http_headers = curl_slist_append(http_headers, header_host.c_str());
	http_headers = curl_slist_append(http_headers, header_date.c_str());
	http_headers = curl_slist_append(http_headers, header_auth.c_str());

	/**
	 * 发送请求
	 */
	BucketOperation::DoRequest(OSS_HTTP_GET, resource, url, http_headers, user_data);
	curl_slist_free_all(http_headers);

	if (user_data->header_buffer()->code == 200) {
		retcode = OK;
		return BucketOperation::ConstructListBucketsResponse(user_data);
	} else {
		retcode = Util::GetRetcodeFromResponse(user_data->recv_buffer()->ptr);
		delete user_data;
		vector<Bucket> buckets;
		return buckets;
	}
}

void
Client::SetBucketAcl(
		const string &bucket_name,
		const string &acl,
		OSS_ERROR_CODE &retcode)
{
	retcode = (OSS_ERROR_CODE)-1;

	Request *user_data = new Request(0, MAX_RECV_BUFFER_SIZE, MAX_HEADER_BUFFER_SIZE);
	
	string resource = "/";
	string url = endpoint_;
	string header_host = "Host: ";
	string header_date = "Date: ";
	string now = Util::GetGmtTime();
	string header_acl = "x-oss-acl: ";

	resource += bucket_name;
	url += "/" + bucket_name;
	header_host += endpoint_;
	header_date += now;
	header_acl += acl;

	map<string, string> user_headers;
	map<string, string> default_headers;
	default_headers.insert(pair<string, string>(OSS_DATE, now));
	user_headers.insert(pair<string, string>(OSS_ACL, acl));

	string sign = Util::GenerateAuthentication(access_key_, OSS_HTTP_PUT, default_headers, user_headers, resource);
	string header_auth = "Authorization: OSS " + access_id_ + ":" + sign;

	struct curl_slist *http_headers = NULL;
	http_headers = curl_slist_append(http_headers, header_host.c_str());
	http_headers = curl_slist_append(http_headers, header_date.c_str());
	http_headers = curl_slist_append(http_headers, header_auth.c_str());
	http_headers = curl_slist_append(http_headers, header_acl.c_str());

	/**
	 * 发送请求
	 */
	BucketOperation::DoRequest(OSS_HTTP_PUT, resource, url, http_headers, user_data);
	curl_slist_free_all(http_headers);

	if (user_data->header_buffer()->code == 200) {
		retcode = OK;
	} else {
		retcode = Util::GetRetcodeFromResponse(user_data->recv_buffer()->ptr);
	}
	delete user_data;
}
	
AccessControlList
Client::GetBucketAcl(
		const string &bucket_name,
		OSS_ERROR_CODE &retcode)
{
	retcode = (OSS_ERROR_CODE)-1;

	Request *user_data = new Request(0, MAX_RECV_BUFFER_SIZE, MAX_HEADER_BUFFER_SIZE);
	
	string resource = "/";
	string url = endpoint_;
	string header_host = "Host: ";
	string header_date = "Date: ";
	string now = Util::GetGmtTime();

	resource = resource +  bucket_name + "?acl";
	url += resource;
	header_host += endpoint_;
	header_date += now;

	map<string, string> user_headers;
	map<string, string> default_headers;
	default_headers.insert(pair<string, string>(OSS_DATE, now));

	string sign = Util::GenerateAuthentication(access_key_, OSS_HTTP_GET, default_headers, user_headers, resource);
	string header_auth = "Authorization: OSS " + access_id_ + ":" + sign;

	struct curl_slist *http_headers = NULL;
	http_headers = curl_slist_append(http_headers, header_host.c_str());
	http_headers = curl_slist_append(http_headers, header_date.c_str());
	http_headers = curl_slist_append(http_headers, header_auth.c_str());

	/**
	 * 发送请求
	 */
	BucketOperation::DoRequest(OSS_HTTP_GET, resource, url, http_headers, user_data);
	curl_slist_free_all(http_headers);

	if (user_data->header_buffer()->code == 200) {
		retcode = OK;
		return BucketOperation::ConstructGetBucketAclResponse(user_data);
	} else {
		retcode = Util::GetRetcodeFromResponse(user_data->recv_buffer()->ptr);
		delete user_data;
		AccessControlList acl;
		return acl;
	}
}

ObjectListing
Client::ListObjects(
		const string &bucket_name,
		OSS_ERROR_CODE &retcode)
{
	retcode = (OSS_ERROR_CODE)-1;

	Request *user_data = new Request(0, MAX_RECV_BUFFER_SIZE, MAX_HEADER_BUFFER_SIZE);
	
	string resource = "/";
	string url = endpoint_;
	string header_host = "Host: ";
	string header_date = "Date: ";
	string now = Util::GetGmtTime();

	resource += bucket_name;
	url += resource;
	header_host += endpoint_;
	header_date += now;

	map<string, string> user_headers;
	map<string, string> default_headers;
	default_headers.insert(pair<string, string>(OSS_DATE, now));

	string sign = Util::GenerateAuthentication(access_key_, OSS_HTTP_GET, default_headers, user_headers, resource);
	string header_auth = "Authorization: OSS " + access_id_ + ":" + sign;

	struct curl_slist *http_headers = NULL;
	http_headers = curl_slist_append(http_headers, header_host.c_str());
	http_headers = curl_slist_append(http_headers, header_date.c_str());
	http_headers = curl_slist_append(http_headers, header_auth.c_str());

	/**
	 * 发送请求
	 */
	BucketOperation::DoRequest(OSS_HTTP_GET, resource, url, http_headers, user_data);
	curl_slist_free_all(http_headers);

	if (user_data->header_buffer()->code == 200) {
		retcode = OK;
		return BucketOperation::ConstructListObjectsResponse(user_data);
	} else {
		retcode = Util::GetRetcodeFromResponse(user_data->recv_buffer()->ptr);
		delete user_data;
		ObjectListing listing;
		return listing;
	}

}
		
ObjectListing
Client::ListObjects(
		const string &bucket_name,
		const string &prefix,
		OSS_ERROR_CODE &retcode)
{
	retcode = (OSS_ERROR_CODE)-1;

	Request *user_data = new Request(0, MAX_RECV_BUFFER_SIZE, MAX_HEADER_BUFFER_SIZE);
	
	string resource = "/";
	string url = endpoint_;
	string header_host = "Host: ";
	string header_date = "Date: ";
	string now = Util::GetGmtTime();

	resource += bucket_name;
	url = url + resource + "?prefix=" + prefix;
	header_host += endpoint_;
	header_date += now;

	map<string, string> user_headers;
	map<string, string> default_headers;
	default_headers.insert(pair<string, string>(OSS_DATE, now));

	string sign = Util::GenerateAuthentication(access_key_, OSS_HTTP_GET, default_headers, user_headers, resource);
	string header_auth = "Authorization: OSS " + access_id_ + ":" + sign;

	struct curl_slist *http_headers = NULL;
	http_headers = curl_slist_append(http_headers, header_host.c_str());
	http_headers = curl_slist_append(http_headers, header_date.c_str());
	http_headers = curl_slist_append(http_headers, header_auth.c_str());

	/**
	 * 发送请求
	 */
	BucketOperation::DoRequest(OSS_HTTP_GET, resource, url, http_headers, user_data);
	curl_slist_free_all(http_headers);

	if (user_data->header_buffer()->code == 200) {
		retcode = OK;
		return BucketOperation::ConstructListObjectsResponse(user_data);
	} else {
		retcode = Util::GetRetcodeFromResponse(user_data->recv_buffer()->ptr);
		delete user_data;
		ObjectListing listing;
		return listing;
	}

}

ObjectListing
Client::ListObjects(
		ListObjectsRequest &request,
		OSS_ERROR_CODE &retcode)
{
	retcode = (OSS_ERROR_CODE)-1;
	int is_first_param = 0;

	Request *user_data = new Request(0, MAX_RECV_BUFFER_SIZE, MAX_HEADER_BUFFER_SIZE);
	
	string resource = "/";
	string url = endpoint_;
	string header_host = "Host: ";
	string header_date = "Date: ";
	string now = Util::GetGmtTime();

	resource += request.bucket_name();
	url += resource;
	if(request.prefix() != "") {
			url = url + "?prefix=" + request.prefix();
			is_first_param = 1;
	}	
	if(request.delimiter() != "") {
		if(is_first_param == 0) {
			url = url + "?delimiter=" + request.delimiter();
			is_first_param = 1;
		} else 
			url = url + "&delimiter=" + request.delimiter();
	}
	if(request.marker() != "") {
		if(is_first_param == 0) {
			url = url + "?marker=" + request.marker();
			is_first_param = 1;
		} else 
			url = url + "&marker=" + request.marker();
	}
	if(request.max_keys() != 0) {
		stringstream ss;
		ss << request.max_keys();
		string tmp;
		ss >> tmp;
		ss.clear();
		if(is_first_param == 0) {
			url = url + "?=max-keys" + tmp;
			is_first_param = 1;
		} else 
			url = url + "&max-keys=" + tmp;
	}
	
	header_host += endpoint_;
	header_date += now;

	map<string, string> user_headers;
	map<string, string> default_headers;
	default_headers.insert(pair<string, string>(OSS_DATE, now));

	string sign = Util::GenerateAuthentication(access_key_, OSS_HTTP_GET, default_headers, user_headers, resource);
	string header_auth = "Authorization: OSS " + access_id_ + ":" + sign;

	struct curl_slist *http_headers = NULL;
	http_headers = curl_slist_append(http_headers, header_host.c_str());
	http_headers = curl_slist_append(http_headers, header_date.c_str());
	http_headers = curl_slist_append(http_headers, header_auth.c_str());

	/**
	 * 发送请求
	 */
	BucketOperation::DoRequest(OSS_HTTP_GET, resource, url, http_headers, user_data);
	curl_slist_free_all(http_headers);

	if (user_data->header_buffer()->code == 200) {
		retcode = OK;
		return BucketOperation::ConstructListObjectsResponse(user_data);
	} else {
		retcode = Util::GetRetcodeFromResponse(user_data->recv_buffer()->ptr);
		delete user_data;
		ObjectListing listing;
		return listing;
	}
}
		
bool
Client::IsBucketExist(
		const string &bucket_name)
{
	OSS_ERROR_CODE retcode;
	GetBucketAcl(bucket_name, retcode);
	if(retcode == OK) {
		return true;
	} else {
		return false;
	}
}
		
void 
Client::DeleteBucket(
		const string &bucket_name,
		OSS_ERROR_CODE &retcode)
{
	retcode = (OSS_ERROR_CODE)-1;

	Request *user_data = new Request(0, MAX_RECV_BUFFER_SIZE, MAX_HEADER_BUFFER_SIZE);
	
	string resource = "/";
	string url = endpoint_;
	string header_host = "Host: ";
	string header_date = "Date: ";
	string now = Util::GetGmtTime();

	resource += bucket_name;
	url += resource;
	header_host += endpoint_;
	header_date += now;

	map<string, string> user_headers;
	map<string, string> default_headers;
	default_headers.insert(pair<string, string>(OSS_DATE, now));

	string sign = Util::GenerateAuthentication(access_key_, OSS_HTTP_DELETE, default_headers, user_headers, resource);
	string header_auth = "Authorization: OSS " + access_id_ + ":" + sign;

	struct curl_slist *http_headers = NULL;
	http_headers = curl_slist_append(http_headers, header_host.c_str());
	http_headers = curl_slist_append(http_headers, header_date.c_str());
	http_headers = curl_slist_append(http_headers, header_auth.c_str());

	/**
	 * 发送请求
	 */
	BucketOperation::DoRequest(OSS_HTTP_DELETE, resource, url, http_headers, user_data);
	curl_slist_free_all(http_headers);

	if (user_data->header_buffer()->code == 204) {
		retcode = NO_CONTENT;
	} else {
		retcode = Util::GetRetcodeFromResponse(user_data->recv_buffer()->ptr);
	}
	delete user_data;

}

CopyObjectResult Client::CopyObject(
		CopyObjectRequest &request,
		OSS_ERROR_CODE &retcode)
{
	retcode = (OSS_ERROR_CODE)-1;

	Request *user_data = new Request(0, MAX_RECV_BUFFER_SIZE, MAX_HEADER_BUFFER_SIZE);
	
	string resource = "/";
	string url = endpoint_;
	string copy_source = "/" + request.source_bucket_name() + "/"
		+ request.source_key();
	string header_host = "Host: ";
	string header_date = "Date: ";
	string header_copy_source = "x-oss-copy-source: " + copy_source;
	string now = Util::GetGmtTime();

	resource += request.destination_bucket_name() +
		"/" + request.destination_key();
	url += resource;
	header_host += endpoint_;
	header_date += now;


	map<string, string> user_headers;
	map<string, string> default_headers;
	user_headers.insert(pair<string, string>(OSS_COPY_SOURCE, copy_source));
	default_headers.insert(pair<string, string>(OSS_DATE, now));

	string sign = Util::GenerateAuthentication(access_key_, OSS_HTTP_PUT, default_headers, user_headers, resource);
	string header_auth = "Authorization: OSS " + access_id_ + ":" + sign;

	struct curl_slist *http_headers = NULL;
	http_headers = curl_slist_append(http_headers, header_host.c_str());
	http_headers = curl_slist_append(http_headers, header_date.c_str());
	http_headers = curl_slist_append(http_headers, header_auth.c_str());
	http_headers = curl_slist_append(http_headers, header_copy_source.c_str());

	/**
	 * 发送请求
	 */
	ObjectOperation::DoRequest(OSS_HTTP_PUT, resource, url, http_headers, user_data);

	curl_slist_free_all(http_headers);
	if (user_data->header_buffer()->code == 200) {
		retcode = OK;
		return ObjectOperation::ConstructCopyObjectResponse(user_data);
	} else {
		retcode = Util::GetRetcodeFromResponse(user_data->recv_buffer()->ptr);
		delete user_data;
		CopyObjectResult result;
		result.set_last_modified("");
		result.set_etag("");
		return result;
	}
}


CopyObjectResult Client::CopyObject(
		const string &source_bucket_name,
		const string &source_key,
		const string &destination_bucket_name,
		const string &destination_key,
		OSS_ERROR_CODE &retcode)
{
	retcode = (OSS_ERROR_CODE)-1;

	Request *user_data = new Request(0, MAX_RECV_BUFFER_SIZE, MAX_HEADER_BUFFER_SIZE);
	
	string resource = "/";
	string url = endpoint_;
	string copy_source = "/" + source_bucket_name + "/"
		+ source_key;
	string header_host = "Host: ";
	string header_date = "Date: ";
	string header_copy_source = "x-oss-copy-source: " + copy_source;
	string now = Util::GetGmtTime();

	resource += destination_bucket_name +
		"/" + destination_key;
	url += resource;
	header_host += endpoint_;
	header_date += now;


	map<string, string> user_headers;
	map<string, string> default_headers;
	user_headers.insert(pair<string, string>(OSS_COPY_SOURCE, copy_source));
	default_headers.insert(pair<string, string>(OSS_DATE, now));

	string sign = Util::GenerateAuthentication(access_key_, OSS_HTTP_PUT, default_headers, user_headers, resource);
	string header_auth = "Authorization: OSS " + access_id_ + ":" + sign;

	struct curl_slist *http_headers = NULL;
	http_headers = curl_slist_append(http_headers, header_host.c_str());
	http_headers = curl_slist_append(http_headers, header_date.c_str());
	http_headers = curl_slist_append(http_headers, header_auth.c_str());
	http_headers = curl_slist_append(http_headers, header_copy_source.c_str());

	/**
	 * 发送请求
	 */
	ObjectOperation::DoRequest(OSS_HTTP_PUT, resource, url, http_headers, user_data);

	curl_slist_free_all(http_headers);
	if (user_data->header_buffer()->code == 200) {
		retcode = OK;
		return ObjectOperation::ConstructCopyObjectResponse(user_data);
	} else {
		retcode = Util::GetRetcodeFromResponse(user_data->recv_buffer()->ptr);
		delete user_data;
		CopyObjectResult result;
		result.set_last_modified("");
		result.set_etag("");
		return result;
	}
}

PutObjectResult Client::PutObjectFromFile(
		const string &bucket_name,
		const string &key,
		const string &file_name,
		ObjectMetadata &metadata,
		OSS_ERROR_CODE &retcode)
{
	PutObjectResult result;
	FILE *fp = NULL;
	long file_len = 0;
	size_t retsize = -1;
	char *buffer = NULL;

	fp = fopen(file_name.c_str(), "r");
	if (fp == NULL) {
		retcode = IO_ERROR;
		return result;
	}

	file_len = Util::GetFileSize(fp);
	buffer = (char *)malloc(sizeof(char) * file_len + 1);
	memset(buffer, '\0', file_len + 1);

	retsize = fread(buffer, 1, file_len, fp);
	if (retsize < 0) {
		retcode = IO_ERROR;
		return result;
	}
	result = PutObjectFromBuffer(bucket_name, key, buffer, file_len, metadata, retcode);

	free(buffer);
	return result;
}

PutObjectResult Client::PutObjectFromBuffer(
		const string &bucket_name,
		const string &key,
		void *buffer,
		unsigned int buffer_len,
		ObjectMetadata &metadata,
		OSS_ERROR_CODE &retcode)
{

	retcode = (OSS_ERROR_CODE)-1;
	
	string resource = "/";
	string url = endpoint_;
	string header_host = "Host: ";
	string header_date = "Date: ";
	string header_content_type = "Content-Type: ";
	string now = Util::GetGmtTime();

	resource += bucket_name + "/" + key;
	url += resource;
	header_host += endpoint_;
	header_date += now;
	header_content_type += "application/octet-stream";

	map<string, string> user_headers;
	map<string, string> default_headers;
	default_headers.insert(pair<string, string>(OSS_DATE, now));
	default_headers.insert(pair<string, string>(OSS_CONTENT_TYPE, "application/octet-stream"));

	Request *user_data = new Request(0, MAX_RECV_BUFFER_SIZE, MAX_HEADER_BUFFER_SIZE);
	ParamBuffer *send_buffer = (ParamBuffer *) malloc(sizeof(ParamBuffer));
	if (send_buffer == NULL) exit(-1);
	memset(send_buffer, 0, sizeof(ParamBuffer));
	send_buffer->ptr = new char[buffer_len];
	memset(send_buffer->ptr, 0, buffer_len);
	memcpy(send_buffer->ptr, buffer, buffer_len);
	send_buffer->left = buffer_len;
	send_buffer->allocated = buffer_len;
	send_buffer->code = -1;
	user_data->set_send_buffer(send_buffer);

	string sign = Util::GenerateAuthentication(access_key_, OSS_HTTP_PUT, default_headers, user_headers, resource);
	string header_auth = "Authorization: OSS " + access_id_ + ":" + sign;

	struct curl_slist *http_headers = NULL;
	http_headers = curl_slist_append(http_headers, header_host.c_str());
	http_headers = curl_slist_append(http_headers, header_date.c_str());
	http_headers = curl_slist_append(http_headers, header_auth.c_str());
	http_headers = curl_slist_append(http_headers, header_content_type.c_str());

	/**
	 * 发送请求
	 */
	ObjectOperation::DoRequest2nd(OSS_HTTP_PUT, resource, url, http_headers, user_data);
	curl_slist_free_all(http_headers);
	if (user_data->header_buffer()->code == 200) {
		retcode = OK;
		return ObjectOperation::ConstructPutObjectResponse(user_data);
	} else {
		retcode = Util::GetRetcodeFromResponse(user_data->recv_buffer()->ptr);
		delete user_data;
		PutObjectResult result;
		return result;
	}
}

void Client::DeleteObject(
		const string &bucket_name,
		const string &key,
		OSS_ERROR_CODE &retcode)
{

	retcode = (OSS_ERROR_CODE)-1;

	Request *user_data = new Request(0, MAX_RECV_BUFFER_SIZE, MAX_HEADER_BUFFER_SIZE);
	
	string resource = "/";
	string url = endpoint_;
	string header_host = "Host: ";
	string header_date = "Date: ";
	string now = Util::GetGmtTime();

	resource += bucket_name + "/" + key;
	url += resource;
	header_host += endpoint_;
	header_date += now;


	map<string, string> user_headers;
	map<string, string> default_headers;
	default_headers.insert(pair<string, string>(OSS_DATE, now));

	string sign = Util::GenerateAuthentication(access_key_, OSS_HTTP_DELETE, default_headers, user_headers, resource);
	string header_auth = "Authorization: OSS " + access_id_ + ":" + sign;

	struct curl_slist *http_headers = NULL;
	http_headers = curl_slist_append(http_headers, header_host.c_str());
	http_headers = curl_slist_append(http_headers, header_date.c_str());
	http_headers = curl_slist_append(http_headers, header_auth.c_str());

	/**
	 * 发送请求
	 */
	ObjectOperation::DoRequest(OSS_HTTP_DELETE, resource, url, http_headers, user_data);
	if (user_data->header_buffer()->code == 204) {
		retcode = OK;
		cout << user_data->recv_buffer()->ptr << endl;
	} else {
		cout << user_data->recv_buffer()->ptr << endl;
		retcode = Util::GetRetcodeFromResponse(user_data->recv_buffer()->ptr);
	}
	curl_slist_free_all(http_headers);
	delete user_data;
}


void Client::DeleteMultipleObject(
		DeleteMultipleObjectRequest &request,
		OSS_ERROR_CODE &retcode)
{

	retcode = (OSS_ERROR_CODE)-1;
	
	string resource = "/";
	string url = endpoint_;
	string header_host = "Host: ";
	string header_date = "Date: ";
	string header_md5 = "Content-MD5: ";
	string header_content_type = "Content-Type: ";
	string now = Util::GetGmtTime();

	resource += request.bucket_name() + "?delete";
	url += resource;
	header_host += endpoint_;
	header_date += now;

	vector<string> vkeys = request.keys();
	string str_delete_keys = "<Delete>";
	if (request.mode() == true) {
		str_delete_keys += "<Quiet>true</Quiet>";
	} else {
		str_delete_keys += "<Quiet>false</Quiet>";
	}
	vector<string>::iterator iter = vkeys.begin();
	for (iter = vkeys.begin(); iter != vkeys.end(); iter++) {
		str_delete_keys += "<Object><Key>" + *iter + "</Key></Object>";
	}
	str_delete_keys += "</Delete>";
	size_t str_delete_keys_len = str_delete_keys.length();
	char *content_md5 = (char *)Util::ComputeMD5Digest(str_delete_keys.c_str(), str_delete_keys_len);
	header_md5 += content_md5;
	header_content_type += "application/octet-stream";


	map<string, string> user_headers;
	map<string, string> default_headers;
	default_headers.insert(pair<string, string>(OSS_DATE, now));
	default_headers.insert(pair<string, string>(OSS_CONTENT_TYPE, "application/octet-stream"));
	default_headers.insert(pair<string, string>(OSS_CONTENT_MD5, content_md5));

	Request *user_data = new Request(0, MAX_RECV_BUFFER_SIZE, MAX_HEADER_BUFFER_SIZE);
	ParamBuffer *send_buffer = (ParamBuffer *) malloc(sizeof(ParamBuffer));
	if (send_buffer == NULL) exit(-1);
	memset(send_buffer, 0, sizeof(ParamBuffer));
	send_buffer->ptr = new char[str_delete_keys_len];
	memset(send_buffer->ptr, 0, str_delete_keys_len);
	memcpy(send_buffer->ptr, str_delete_keys.c_str(), str_delete_keys_len);
	send_buffer->left = str_delete_keys_len;
	send_buffer->allocated = str_delete_keys_len;
	send_buffer->code = -1;
	user_data->set_send_buffer(send_buffer);

	string sign = Util::GenerateAuthentication(access_key_, OSS_HTTP_POST, default_headers, user_headers, resource);
	string header_auth = "Authorization: OSS " + access_id_ + ":" + sign;

	struct curl_slist *http_headers = NULL;
	http_headers = curl_slist_append(http_headers, header_host.c_str());
	http_headers = curl_slist_append(http_headers, header_date.c_str());
	http_headers = curl_slist_append(http_headers, header_auth.c_str());
	http_headers = curl_slist_append(http_headers, header_md5.c_str());
	http_headers = curl_slist_append(http_headers, header_content_type.c_str());

	/**
	 * 发送请求
	 */
	ObjectOperation::DoRequest(OSS_HTTP_POST, resource, url, http_headers, user_data);
	curl_slist_free_all(http_headers);
	if (user_data->header_buffer()->code == 200) {
		retcode = OK;
	} else {
		retcode = Util::GetRetcodeFromResponse(user_data->recv_buffer()->ptr);
	}

	free(content_md5);
	delete user_data;
}

ObjectMetadata Client::GetObjectMetadata(
		const string &bucket_name,
		const string &key,
		OSS_ERROR_CODE &retcode)
{
	retcode = (OSS_ERROR_CODE)-1;

	Request *user_data = new Request(0, MAX_RECV_BUFFER_SIZE, MAX_HEADER_BUFFER_SIZE);
	
	string resource = "/";
	string url = endpoint_;
	string header_host = "Host: ";
	string header_date = "Date: ";
	string now = Util::GetGmtTime();

	resource += bucket_name + "/" + key;
	url += resource;
	header_host += endpoint_;
	header_date += now;


	map<string, string> user_headers;
	map<string, string> default_headers;
	default_headers.insert(pair<string, string>(OSS_DATE, now));

	string sign = Util::GenerateAuthentication(access_key_, OSS_HTTP_HEAD, default_headers, user_headers, resource);
	string header_auth = "Authorization: OSS " + access_id_ + ":" + sign;

	struct curl_slist *http_headers = NULL;
	http_headers = curl_slist_append(http_headers, header_host.c_str());
	http_headers = curl_slist_append(http_headers, header_date.c_str());
	http_headers = curl_slist_append(http_headers, header_auth.c_str());

	/**
	 * 发送请求
	 */
	ObjectOperation::DoRequest(OSS_HTTP_HEAD, resource, url, http_headers, user_data);

	curl_slist_free_all(http_headers);
	if (user_data->header_buffer()->code == 200) {
		retcode = OK;
		return ObjectOperation::ConstructGetObjectMetadataResponse(user_data);
	} else {
		if (user_data->header_buffer()->code == 404) {
			retcode = FILE_NOT_FOUND;
		} else if (user_data->header_buffer()->code == 403) {
			retcode = ACCESS_DENIED;
		} else if (user_data->header_buffer()->code == 304) {
			retcode = NOT_MODIFIED;
		} else if (user_data->header_buffer()->code == 412) {
			retcode = PRECONDITION_FAILED;
		} else {
			retcode = (OSS_ERROR_CODE)1000;
		}
	}
	delete user_data;
	ObjectMetadata metadata;
	return metadata;
}

ObjectMetadata Client::GetObject(
		GetObjectRequest &request,
		string &file_name,
		OSS_ERROR_CODE &retcode)
{
	void *buffer = NULL;
	unsigned int buffer_len = 0;
	std::ofstream ofs(file_name.c_str(), ofstream::binary);
	ObjectMetadata metadata = GetObject(request, &buffer, buffer_len, retcode);
	ofs.write(static_cast<char *>(buffer), buffer_len);
	ofs.close();
	return metadata;
}

ObjectMetadata Client::GetObject(
		GetObjectRequest &request,
		void **buffer,
		unsigned int &buffer_len,
		OSS_ERROR_CODE &retcode)
{

	retcode = (OSS_ERROR_CODE)-1;

	Request *user_data = new Request(0, 0, MAX_HEADER_BUFFER_SIZE);
	
	string resource = "/";
	string url = endpoint_;
	string header_host = "Host: ";
	string header_date = "Date: ";
	string now = Util::GetGmtTime();

	resource += request.bucket_name() + "/" + request.key();
	url += resource;
	header_host += endpoint_;
	header_date += now;


	map<string, string> user_headers;
	map<string, string> default_headers;
	default_headers.insert(pair<string, string>(OSS_DATE, now));

	string sign = Util::GenerateAuthentication(access_key_, OSS_HTTP_GET, default_headers, user_headers, resource);
	string header_auth = "Authorization: OSS " + access_id_ + ":" + sign;

	struct curl_slist *http_headers = NULL;
	http_headers = curl_slist_append(http_headers, header_host.c_str());
	http_headers = curl_slist_append(http_headers, header_date.c_str());
	http_headers = curl_slist_append(http_headers, header_auth.c_str());

	/**
	 * 发送请求
	 */
	ObjectOperation::DoRequest(OSS_HTTP_GET, resource, url, http_headers, user_data);

	curl_slist_free_all(http_headers);

	if (user_data->header_buffer()->code == 200) {
		retcode = OK;
		buffer_len = user_data->recv_buffer()->allocated;
		*buffer= (char *)malloc(sizeof(char) * (buffer_len + 1));
		memset(*buffer, 0, (buffer_len + 1));
		memcpy(*buffer, user_data->recv_buffer()->ptr, buffer_len);
		return ObjectOperation::ConstructGetObjectMetadataResponse(user_data);
	} else {
		*buffer= NULL;
		buffer_len = 0;
		retcode = Util::GetRetcodeFromResponse(user_data->recv_buffer()->ptr);
		delete user_data;
		ObjectMetadata metadata;
		return metadata;
	}
}

InitiateMultipartUploadResult  Client::InitiateMultipartUpload(
		InitiateMultipartUploadRequest &request,
		OSS_ERROR_CODE &retcode)
{

	retcode = (OSS_ERROR_CODE)-1;
	
	string resource = "/";
	string url = endpoint_;
	string header_host = "Host: ";
	string header_date = "Date: ";
	string now = Util::GetGmtTime();

	resource += request.bucket_name() + "/" + request.key() + "?uploads";
	url += resource;
	header_host += endpoint_;
	header_date += now;

	map<string, string> user_headers = request.object_metadata().user_metadata();
	map<string, string> default_headers;
	default_headers.insert(pair<string, string>(OSS_DATE, now));

	Request *user_data = new Request(0, MAX_RECV_BUFFER_SIZE, MAX_HEADER_BUFFER_SIZE);
	
	string sign = Util::GenerateAuthentication(access_key_, OSS_HTTP_POST, default_headers, user_headers, resource);
	string header_auth = "Authorization: OSS " + access_id_ + ":" + sign;

	struct curl_slist *http_headers = NULL;
	http_headers = curl_slist_append(http_headers, header_host.c_str());
	http_headers = curl_slist_append(http_headers, header_date.c_str());
	http_headers = curl_slist_append(http_headers, header_auth.c_str());

	/**
	 * 发送请求
	 */
	MultipartUploadOperation::DoRequest2nd(OSS_HTTP_POST, resource, url, http_headers, user_data);
	curl_slist_free_all(http_headers);
	if (user_data->header_buffer()->code == 200) {
		retcode = OK;
		return MultipartUploadOperation::ConstructInitiateMultipartUploadResponse(user_data);
	} else {
		retcode = Util::GetRetcodeFromResponse(user_data->recv_buffer()->ptr);
		delete user_data;
		InitiateMultipartUploadResult result;
		return result;
	}

}

UploadPartResult Client::UploadPart(
		UploadPartRequest &request,
		OSS_ERROR_CODE &retcode)
{
	UploadPartResult result;
	retcode = (OSS_ERROR_CODE)-1;
	
	string resource = "/";
	string url = endpoint_;
	string header_host = "Host: ";
	string header_date = "Date: ";
	string header_content_type = "Content-Type: ";
	string now = Util::GetGmtTime();
	stringstream part_number;
	part_number << request.part_number();

	resource += request.bucket_name() + "/" + request.key() +
		"?partNumber=" + part_number.str() + 
		"&uploadId=" + request.upload_id();
	url += resource;
	header_host += endpoint_;
	header_date += now;
	header_content_type += "application/octet-stream";

	map<string, string> user_headers;
	map<string, string> default_headers;
	default_headers.insert(pair<string, string>(OSS_DATE, now));
	default_headers.insert(pair<string, string>(OSS_CONTENT_TYPE, "application/octet-stream"));

	Request *user_data = new Request(0, MAX_RECV_BUFFER_SIZE, MAX_HEADER_BUFFER_SIZE);
	ParamBuffer *send_buffer = (ParamBuffer *) malloc(sizeof(ParamBuffer));
	if (send_buffer == NULL) exit(-1);
	memset(send_buffer, 0, sizeof(ParamBuffer));
	send_buffer->ptr = new char[request.part_size()];
	memset(send_buffer->ptr, 0, request.part_size());
	memcpy(send_buffer->ptr, request.input_stream(), request.part_size());
	send_buffer->left = request.part_size();
	send_buffer->allocated = request.part_size();
	send_buffer->code = -1;
	user_data->set_send_buffer(send_buffer);

	string sign = Util::GenerateAuthentication(access_key_, OSS_HTTP_PUT, default_headers, user_headers, resource);
	string header_auth = "Authorization: OSS " + access_id_ + ":" + sign;

	struct curl_slist *http_headers = NULL;
	http_headers = curl_slist_append(http_headers, header_host.c_str());
	http_headers = curl_slist_append(http_headers, header_date.c_str());
	http_headers = curl_slist_append(http_headers, header_auth.c_str());
	http_headers = curl_slist_append(http_headers, header_content_type.c_str());

	/**
	 * 发送请求
	 */
	MultipartUploadOperation::DoRequest(OSS_HTTP_PUT, resource, url, http_headers, user_data);
	curl_slist_free_all(http_headers);
	if (user_data->header_buffer()->code == 200) {
		retcode = OK;
		result = MultipartUploadOperation::ConstructUploadPartResponse(user_data);
		result.set_part_number(request.part_number());
		return result;
	} else {
		retcode = Util::GetRetcodeFromResponse(user_data->recv_buffer()->ptr);
		delete user_data;
		return result;
	}

}

void
Client::AbortMultipartUpload(
		AbortMultipartUploadRequest &request,
		OSS_ERROR_CODE &retcode)
{
	retcode = (OSS_ERROR_CODE)-1;
	
	string resource = "/";
	string url = endpoint_;
	string header_host = "Host: ";
	string header_date = "Date: ";
	string now = Util::GetGmtTime();

	resource += request.bucket_name() + "/" + request.key()
		+ "?uploadId=" + request.upload_id();
	url += resource;
	header_host += endpoint_;
	header_date += now;

	map<string, string> user_headers; 
	map<string, string> default_headers;
	default_headers.insert(pair<string, string>(OSS_DATE, now));

	Request *user_data = new Request(0, MAX_RECV_BUFFER_SIZE, MAX_HEADER_BUFFER_SIZE);
	
	string sign = Util::GenerateAuthentication(access_key_, OSS_HTTP_DELETE, default_headers, user_headers, resource);
	string header_auth = "Authorization: OSS " + access_id_ + ":" + sign;

	struct curl_slist *http_headers = NULL;
	http_headers = curl_slist_append(http_headers, header_host.c_str());
	http_headers = curl_slist_append(http_headers, header_date.c_str());
	http_headers = curl_slist_append(http_headers, header_auth.c_str());

	/**
	 * 发送请求
	 */
	MultipartUploadOperation::DoRequest(OSS_HTTP_DELETE, resource, url, http_headers, user_data);
	curl_slist_free_all(http_headers);
	if (user_data->header_buffer()->code == 200) {
		retcode = OK;
	} else {
		retcode = Util::GetRetcodeFromResponse(user_data->recv_buffer()->ptr);
		delete user_data;
	}
}

CompleteMultipartUploadResult
Client::CompleteMultipartUpload(
		CompleteMultipartUploadRequest &request,
		OSS_ERROR_CODE &retcode)
{

	retcode = (OSS_ERROR_CODE)-1;
	
	string resource = "/";
	string url = endpoint_;
	string header_host = "Host: ";
	string header_date = "Date: ";
	string header_md5 = "Content-MD5: ";
	string header_content_type = "Content-Type: ";
	string now = Util::GetGmtTime();

	resource += request.bucket_name() + "/" + request.key() +
		"?uploadId=" + request.upload_id();
	url += resource;
	header_host += endpoint_;
	header_date += now;

	vector<PartEtag> vparts= request.part_etags();
	string str_parts = "<CompleteMultipartUpload>";
	
	vector<PartEtag>::iterator iter = vparts.begin();
	for (iter = vparts.begin(); iter != vparts.end(); iter++) {
		stringstream ss;
		ss << (*iter).part_number();
		str_parts.append("<Part><PartNumber>").append(ss.str()).
			append("</PartNumber><ETag>").append("\"").append((*iter).etag()).
			append("\"").append("</ETag></Part>");
	}
	str_parts.append("</CompleteMultipartUpload>");
	size_t str_parts_len = str_parts.length();
	char *content_md5 = (char *)Util::ComputeMD5Digest(str_parts.c_str(), str_parts_len);
	header_md5 += content_md5;
	header_content_type += "application/octet-stream";


	map<string, string> user_headers;
	map<string, string> default_headers;
	default_headers.insert(pair<string, string>(OSS_DATE, now));
	default_headers.insert(pair<string, string>(OSS_CONTENT_TYPE, "application/octet-stream"));
	default_headers.insert(pair<string, string>(OSS_CONTENT_MD5, content_md5));

	Request *user_data = new Request(0, MAX_RECV_BUFFER_SIZE, MAX_HEADER_BUFFER_SIZE);
	ParamBuffer *send_buffer = (ParamBuffer *) malloc(sizeof(ParamBuffer));
	if (send_buffer == NULL) exit(-1);
	memset(send_buffer, 0, sizeof(ParamBuffer));
	send_buffer->ptr = new char[str_parts_len];
	memset(send_buffer->ptr, 0, str_parts_len);
	memcpy(send_buffer->ptr, str_parts.c_str(), str_parts_len);
	send_buffer->left = str_parts_len;
	send_buffer->allocated = str_parts_len;
	send_buffer->code = -1;
	user_data->set_send_buffer(send_buffer);

	string sign = Util::GenerateAuthentication(access_key_, OSS_HTTP_POST, default_headers, user_headers, resource);
	string header_auth = "Authorization: OSS " + access_id_ + ":" + sign;

	struct curl_slist *http_headers = NULL;
	http_headers = curl_slist_append(http_headers, header_host.c_str());
	http_headers = curl_slist_append(http_headers, header_date.c_str());
	http_headers = curl_slist_append(http_headers, header_auth.c_str());
	http_headers = curl_slist_append(http_headers, header_md5.c_str());
	http_headers = curl_slist_append(http_headers, header_content_type.c_str());

	/**
	 * 发送请求
	 */
	MultipartUploadOperation::DoRequest(OSS_HTTP_POST, resource, url, http_headers, user_data);
	curl_slist_free_all(http_headers);
	free(content_md5);
	if (user_data->header_buffer()->code == 200) {
		retcode = OK;
		return MultipartUploadOperation::ConstructCompleteMultipartUploadResponse(user_data);
	} else {
		retcode = Util::GetRetcodeFromResponse(user_data->recv_buffer()->ptr);
		delete user_data;
		CompleteMultipartUploadResult result;
		return result;
	}

}

MultipartUploadListing Client::ListMultipartUploads(
		ListMultipartUploadsRequest &request,
		OSS_ERROR_CODE &retcode)
{
	retcode = (OSS_ERROR_CODE)-1;
	
	string resource = "/";
	string url = endpoint_;
	string header_host = "Host: ";
	string header_date = "Date: ";
	string now = Util::GetGmtTime();

	resource += request.bucket_name() + "?uploads";
	url += resource;
	header_host += endpoint_;
	header_date += now;

	map<string, string> user_headers; 
	map<string, string> default_headers;
	default_headers.insert(pair<string, string>(OSS_DATE, now));

	Request *user_data = new Request(0, MAX_RECV_BUFFER_SIZE, MAX_HEADER_BUFFER_SIZE);
	
	string sign = Util::GenerateAuthentication(access_key_, OSS_HTTP_GET, default_headers, user_headers, resource);
	string header_auth = "Authorization: OSS " + access_id_ + ":" + sign;

	struct curl_slist *http_headers = NULL;
	http_headers = curl_slist_append(http_headers, header_host.c_str());
	http_headers = curl_slist_append(http_headers, header_date.c_str());
	http_headers = curl_slist_append(http_headers, header_auth.c_str());

	/**
	 * 发送请求
	 */
	MultipartUploadOperation::DoRequest2nd(OSS_HTTP_GET, resource, url, http_headers, user_data);
	curl_slist_free_all(http_headers);
	if (user_data->header_buffer()->code == 200) {
		retcode = OK;
		return MultipartUploadOperation::ConstructListMultipartUploadsResponse(user_data);
	} else {
		delete user_data;
		retcode = Util::GetRetcodeFromResponse(user_data->recv_buffer()->ptr);
		MultipartUploadListing listing;
		return listing;
	}
}

PartListing Client::ListParts(ListPartsRequest &request,
				OSS_ERROR_CODE &retcode)
{

	retcode = (OSS_ERROR_CODE)-1;
	
	string resource = "/";
	string url = endpoint_;
	string header_host = "Host: ";
	string header_date = "Date: ";
	string now = Util::GetGmtTime();

	resource += request.bucket_name() + "/" + request.key()
		+ "?uploadId=" + request.upload_id();
	url += resource;
	header_host += endpoint_;
	header_date += now;

	map<string, string> user_headers; 
	map<string, string> default_headers;
	default_headers.insert(pair<string, string>(OSS_DATE, now));

	Request *user_data = new Request(0, MAX_RECV_BUFFER_SIZE, MAX_HEADER_BUFFER_SIZE);
	
	string sign = Util::GenerateAuthentication(access_key_, OSS_HTTP_GET, default_headers, user_headers, resource);
	string header_auth = "Authorization: OSS " + access_id_ + ":" + sign;

	struct curl_slist *http_headers = NULL;
	http_headers = curl_slist_append(http_headers, header_host.c_str());
	http_headers = curl_slist_append(http_headers, header_date.c_str());
	http_headers = curl_slist_append(http_headers, header_auth.c_str());

	/**
	 * 发送请求
	 */
	MultipartUploadOperation::DoRequest2nd(OSS_HTTP_GET, resource, url, http_headers, user_data);
	curl_slist_free_all(http_headers);
	if (user_data->header_buffer()->code == 200) {
		retcode = OK;
		return MultipartUploadOperation::ConstructListPartsResponse(user_data);
	} else {
		retcode = Util::GetRetcodeFromResponse(user_data->recv_buffer()->ptr);
		delete user_data;
		PartListing listing;
		return listing;
	}
}

PostObjectGroupResult 
Client::PostObjectGroup(
		PostObjectGroupRequest &request,
		OSS_ERROR_CODE &retcode)
{
	retcode = (OSS_ERROR_CODE)-1;

	Request *user_data = new Request(0, MAX_RECV_BUFFER_SIZE, MAX_HEADER_BUFFER_SIZE);
	
	string resource = "/";
	string url = endpoint_;
	string header_host = "Host: ";
	string header_date = "Date: ";
	string now = Util::GetGmtTime();

	resource = resource + request.bucket_name() + "/" + request.key() + "?group";
	url += resource;
	header_host += endpoint_;
	header_date += now;

	map<string, string> user_headers;
	map<string, string> default_headers;
	default_headers.insert(pair<string, string>(OSS_DATE, now));
	default_headers.insert(pair<string, string>(OSS_CONTENT_TYPE, "application/x-www-form-urlencoded"));

	string sign = Util::GenerateAuthentication(access_key_, OSS_HTTP_POST, default_headers, user_headers, resource);
	string header_auth = "Authorization: OSS " + access_id_ + ":" + sign;

	vector<ObjectGroupItem> part_item = request.items();
	string part_item_str = "<CreateFileGroup>";
	for (int i = 0; i < part_item.size(); i++) {
		stringstream ss;
		ss << part_item[i].part_number();
		string tmp;
		ss >> tmp;
		ss.clear();
		part_item_str = part_item_str + "<Part><PartNumber>" + tmp + "</PartNumber><PartName>" + part_item[i].part_name() + "</PartName><ETag>" + part_item[i].etag() + "</ETag></Part>";
	}
	part_item_str += "</CreateFileGroup>\n";
	unsigned int tmp_len = part_item_str.size();
	char *tmp = (char *)malloc(sizeof(char) * (tmp_len + 1));
	strncpy(tmp, part_item_str.c_str(), tmp_len);
	tmp[tmp_len] = '\0';

	
	user_data->send_buffer()->ptr = tmp;
	user_data->send_buffer()->left = part_item_str.size();
	user_data->send_buffer()->allocated = part_item_str.size();


	struct curl_slist *http_headers = NULL;
	http_headers = curl_slist_append(http_headers, header_host.c_str());
	http_headers = curl_slist_append(http_headers, header_date.c_str());
	http_headers = curl_slist_append(http_headers, header_auth.c_str());

	/**
	 * 发送请求
	 */
	ObjectGroupOperation::DoRequest(OSS_HTTP_POST, resource, url, http_headers, user_data);
	curl_slist_free_all(http_headers);

	if (user_data->header_buffer()->code == 200) {
		retcode = OK;
		return ObjectGroupOperation::ConstructPostObjectGroupResponse(user_data);
	} else {
		retcode = Util::GetRetcodeFromResponse(user_data->recv_buffer()->ptr);
		delete user_data;
		PostObjectGroupResult result;
		return result;
	}

}
		
ObjectMetadata
Client::GetObjectGroupToBuffer(
		GetObjectGroupRequest &request,
		string &output,
		OSS_ERROR_CODE &retcode)
{
	retcode = (OSS_ERROR_CODE)-1;

	Request *user_data = new Request(0, 0, MAX_HEADER_BUFFER_SIZE);
	
	string resource = "/";
	string url = endpoint_;
	string header_host = "Host: ";
	string header_date = "Date: ";
	string now = Util::GetGmtTime();

	resource = resource + request.bucket_name() + "/" + request.key();
	url += resource;
	header_host += endpoint_;
	header_date += now;

	map<string, string> user_headers;
	map<string, string> default_headers;
	default_headers.insert(pair<string, string>(OSS_DATE, now));

	string sign = Util::GenerateAuthentication(access_key_, OSS_HTTP_GET, default_headers, user_headers, resource);
	string header_auth = "Authorization: OSS " + access_id_ + ":" + sign;

	string header_if_modified_since;
	string header_if_unmodified_since;
	string header_range;
	long start, length;
	struct curl_slist *http_headers = NULL;
	if (request.modified_since_constraint() != "") {
		header_if_modified_since = "If-Modified-Since: " + request.modified_since_constraint();
		http_headers = curl_slist_append(http_headers, header_if_modified_since.c_str());
	}
	if (request.unmodified_since_constraint() != "") {
		header_if_unmodified_since = "If-Unmodified-Since: " + request.unmodified_since_constraint();
		http_headers = curl_slist_append(http_headers, header_if_unmodified_since.c_str());
	}
	request.range(start, length);
	if (start > 0 && length > 0) {
		stringstream ss;
		string start_tmp, end_tmp;
		ss << start;
		ss >> start_tmp;
		ss.clear();
		ss << (start + length);
		ss >> end_tmp;
		ss.clear();
		header_range = "Range: " + start_tmp + "-" + end_tmp;
		http_headers = curl_slist_append(http_headers, header_range.c_str());
	}


	http_headers = curl_slist_append(http_headers, header_host.c_str());
	http_headers = curl_slist_append(http_headers, header_date.c_str());
	http_headers = curl_slist_append(http_headers, header_auth.c_str());

	/**
	 * 发送请求
	 */
	ObjectGroupOperation::DoRequest(OSS_HTTP_GET, resource, url, http_headers, user_data);
	curl_slist_free_all(http_headers);

	if (user_data->header_buffer()->code == 200) {
		retcode = OK;
		output = user_data->recv_buffer()->ptr;
		return ObjectGroupOperation::ConstructGetObjectGroupToBufferResponse(user_data);
	} else {
		retcode = Util::GetRetcodeFromResponse(user_data->recv_buffer()->ptr);
		delete user_data;
		ObjectMetadata metadata;
		return metadata;
	}
}

ObjectMetadata 
Client::GetObjectGroupToFile(
		GetObjectGroupRequest &request,
		const string &file_name,
		OSS_ERROR_CODE &retcode)
{
	FILE *fp;
	if((fp = fopen(file_name.c_str(), "w+")) == NULL) {
		printf("open file failed.\n");
		exit(-1);
	}

	string buffer;
	ObjectMetadata result = GetObjectGroupToBuffer(request, buffer, retcode);
	fwrite(buffer.c_str(), sizeof(char), buffer.size(), fp);
	return result;
}
		
GetObjectGroupIndexResult
Client::GetObjectGroupIndex(
		const string &bucket_name,
		const string &key,
		OSS_ERROR_CODE &retcode)
{
	retcode = (OSS_ERROR_CODE)-1;

	Request *user_data = new Request(0, 0, MAX_HEADER_BUFFER_SIZE);
	
	string resource = "/";
	string url = endpoint_;
	string header_host = "Host: ";
	string header_date = "Date: ";
	string now = Util::GetGmtTime();
	string header_group = OSS_OBJECT_GROUP;

	resource = resource + bucket_name + "/" + key;
	url += resource;
	header_host += endpoint_;
	header_date += now;
	header_group += ":I'm NULL. ^ ^";

	map<string, string> user_headers;
	map<string, string> default_headers;
	default_headers.insert(pair<string, string>(OSS_DATE, now));
	user_headers.insert(pair<string, string>(OSS_OBJECT_GROUP, "I'm NULL. ^ ^"));

	string sign = Util::GenerateAuthentication(access_key_, OSS_HTTP_GET, default_headers, user_headers, resource);
	string header_auth = "Authorization: OSS " + access_id_ + ":" + sign;

	struct curl_slist *http_headers = NULL;
	http_headers = curl_slist_append(http_headers, header_host.c_str());
	http_headers = curl_slist_append(http_headers, header_date.c_str());
	http_headers = curl_slist_append(http_headers, header_auth.c_str());
	http_headers = curl_slist_append(http_headers, header_group.c_str());
	/**
	 * 发送请求
	 */
	ObjectGroupOperation::DoRequest(OSS_HTTP_GET, resource, url, http_headers, user_data);
	curl_slist_free_all(http_headers);

	if (user_data->header_buffer()->code == 200) {
		retcode = OK;
		return ObjectGroupOperation::ConstructGetObjectGroupIndexResponse(user_data);
	} else {
		retcode = Util::GetRetcodeFromResponse(user_data->recv_buffer()->ptr);
		delete user_data;
		GetObjectGroupIndexResult result;
		return result;
	}

}
		
ObjectMetadata 
Client::HeadObjectGroup(
		GetObjectGroupRequest &request,
		OSS_ERROR_CODE &retcode)
{
	retcode = (OSS_ERROR_CODE)-1;

	Request *user_data = new Request(0, MAX_RECV_BUFFER_SIZE, MAX_HEADER_BUFFER_SIZE);
	
	string resource = "/";
	string url = endpoint_;
	string header_host = "Host: ";
	string header_date = "Date: ";
	string now = Util::GetGmtTime();

	resource = resource + request.bucket_name() + "/" + request.key();
	url += resource;
	header_host += endpoint_;
	header_date += now;

	map<string, string> user_headers;
	map<string, string> default_headers;
	default_headers.insert(pair<string, string>(OSS_DATE, now));

	string sign = Util::GenerateAuthentication(access_key_, OSS_HTTP_HEAD, default_headers, user_headers, resource);
	string header_auth = "Authorization: OSS " + access_id_ + ":" + sign;

	struct curl_slist *http_headers = NULL;
	http_headers = curl_slist_append(http_headers, header_host.c_str());
	http_headers = curl_slist_append(http_headers, header_date.c_str());
	http_headers = curl_slist_append(http_headers, header_auth.c_str());

	if (request.modified_since_constraint() != "") {
		string header_if_modified_since = "If-Modified-Since: " + request.modified_since_constraint();
		http_headers = curl_slist_append(http_headers, header_if_modified_since.c_str());
	}
	if (request.unmodified_since_constraint() != "") {
		string header_if_unmodified_since = "If-Unmodified-Since: " + request.unmodified_since_constraint();
		http_headers = curl_slist_append(http_headers, header_if_unmodified_since.c_str());
	}

	/**
	 * 发送请求
	 */
	ObjectGroupOperation::DoRequest(OSS_HTTP_HEAD, resource, url, http_headers, user_data);
	curl_slist_free_all(http_headers);

	if (user_data->header_buffer()->code == 200) {
		retcode = OK;
		return ObjectGroupOperation::ConstructHeadObjectGroupResponse(user_data);
	} else {
		unsigned short tmp = user_data->header_buffer()->code;
		if(tmp == 404) {
			retcode = FILE_NOT_FOUND;
		} else if(tmp == 304) {
			retcode = NOT_MODIFIED;
		} else if(tmp == 412) {
			retcode = PRECONDITION_FAILED;
		} else if(tmp == 403) {
			retcode = ACCESS_DENIED;
		} else {
			retcode = (OSS_ERROR_CODE)-1;
		}
		delete user_data;
		ObjectMetadata metadata;
		return metadata;
	}
}
		
void 
Client::DeleteObjectGroup(
		const string &bucket_name,
		const string &key,
		OSS_ERROR_CODE &retcode)
{
	retcode = (OSS_ERROR_CODE)-1;

	Request *user_data = new Request(0, MAX_RECV_BUFFER_SIZE, MAX_HEADER_BUFFER_SIZE);
	
	string resource = "/";
	string url = endpoint_;
	string header_host = "Host: ";
	string header_date = "Date: ";
	string now = Util::GetGmtTime();

	resource = resource + bucket_name + "/" + key;
	url += resource;
	header_host += endpoint_;
	header_date += now;

	map<string, string> user_headers;
	map<string, string> default_headers;
	default_headers.insert(pair<string, string>(OSS_DATE, now));

	string sign = Util::GenerateAuthentication(access_key_, OSS_HTTP_DELETE, default_headers, user_headers, resource);
	string header_auth = "Authorization: OSS " + access_id_ + ":" + sign;

	struct curl_slist *http_headers = NULL;
	http_headers = curl_slist_append(http_headers, header_host.c_str());
	http_headers = curl_slist_append(http_headers, header_date.c_str());
	http_headers = curl_slist_append(http_headers, header_auth.c_str());

	/**
	 * 发送请求
	 */
	ObjectGroupOperation::DoRequest(OSS_HTTP_DELETE, resource, url, http_headers, user_data);
	curl_slist_free_all(http_headers);

	if (user_data->header_buffer()->code == 204) {
		retcode = NO_CONTENT;
	} else {
		retcode = Util::GetRetcodeFromResponse(user_data->recv_buffer()->ptr);
	}

	delete user_data;
}

const string 
Client::GeneratePresignedUrl(
		const string &bucket_name,
		const string &key,
		const string &expiration)
{

	char curl[1024] = {0};
	string resource = "/";

	resource = resource + bucket_name + "/" + key;

	map<string, string> user_headers;
	map<string, string> default_headers;
	default_headers.insert(pair<string, string>(OSS_DATE, expiration));

	string sign = Util::GenerateAuthentication(access_key_, OSS_HTTP_GET, default_headers, user_headers, resource);

	sprintf(curl, "http://%s%s?OSSAccessKeyId=%s&Expires=%s&Signature=%s",
			endpoint_.c_str(), resource.c_str(), access_id_.c_str(), expiration.c_str(), sign.c_str());
	string signed_url = curl;
	
	return signed_url;
}


const string 
Client::GeneratePresignedUrl(
		const string &bucket_name,
		const string &key,
		const string &expiration,
		const string &method)
{

	char curl[1024] = {0};
	string resource = "/";

	resource = resource + bucket_name + "/" + key;

	map<string, string> user_headers;
	map<string, string> default_headers;
	default_headers.insert(pair<string, string>(OSS_DATE, expiration));

	string sign = Util::GenerateAuthentication(access_key_, method, default_headers, user_headers, resource);

	sprintf(curl, "http://%s%s?OSSAccessKeyId=%s&Expires=%s&Signature=%s",
			endpoint_.c_str(), resource.c_str(), access_id_.c_str(), expiration.c_str(), sign.c_str());
	string signed_url = curl;
	
	return signed_url;
}

}
