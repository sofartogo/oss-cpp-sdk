/*
 * =============================================================================
 *
 *       Filename:  oss_object_operation.cc
 *
 *    Description:  oss object operation routines.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include <curl/curl.h>

#include <lib/oss_ttxml.h>

#include "oss_object_operation.h"
#include "oss_callback.h"
#include "oss_request_param.h"

#define _OSS_CLIENT_H
#include <osscpp/modules/oss_client.h>
#undef _OSS_CLIENT_H


namespace osscpp {

void ObjectOperation::DoRequest(const std::string method,
		const std::string resource,
		const std::string url,
		struct curl_slist *http_headers,
		void *user_data)
{
	assert(http_headers != NULL);
	assert(user_data != NULL);

	CURL *curl = NULL;
	Request *params = (Request *)user_data;

	ParamBuffer *send_buffer = params->send_buffer();
	ParamBuffer *recv_buffer = params->recv_buffer();
	ParamBuffer *header_buffer = params->header_buffer();

	curl = curl_easy_init();
	if (curl != NULL) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, static_cast<CURLoption>(CURL_HTTP_VERSION_1_1), 1L);
		if (method == OSS_HTTP_PUT || method == OSS_HTTP_DELETE) {
			curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method.c_str());
		} else if (method  == OSS_HTTP_POST) {
			curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method.c_str());
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, send_buffer->ptr);
		} else if (method  == OSS_HTTP_HEAD) {
			curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method.c_str());
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Callback::GeneralOperationRecvCallback);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, recv_buffer);
			curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, Callback::GeneralOperationHeaderCallback2nd);
			curl_easy_setopt(curl, CURLOPT_HEADERDATA, header_buffer);
			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, http_headers);
			curl_easy_perform(curl);
			curl_easy_cleanup(curl);
			return;
		} else if (method == OSS_HTTP_GET) {
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Callback::GeneralOperationRecvCallback2nd);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, recv_buffer);
			curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, Callback::GeneralOperationHeaderCallback2nd);
			curl_easy_setopt(curl, CURLOPT_HEADERDATA, header_buffer);
			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, http_headers);
			curl_easy_perform(curl);
			curl_easy_cleanup(curl);
			return;
		}

		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Callback::GeneralOperationRecvCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, recv_buffer);
		curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, Callback::GeneralOperationHeaderCallback);
		curl_easy_setopt(curl, CURLOPT_HEADERDATA, header_buffer);
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, http_headers);
		curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
}

void ObjectOperation::DoRequest2nd(const std::string method,
		const std::string resource,
		const std::string url,
		struct curl_slist *http_headers,
		void *user_data)
{
	assert(http_headers != NULL);
	assert(user_data != NULL);

	CURL *curl = NULL;
	Request *params = (Request *)user_data;

	ParamBuffer *send_buffer = params->send_buffer();
	ParamBuffer *recv_buffer = params->recv_buffer();
	ParamBuffer *header_buffer = params->header_buffer();

	curl = curl_easy_init();
	if (curl != NULL) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, static_cast<CURLoption>(CURL_HTTP_VERSION_1_1), 1L);
		if (method == OSS_HTTP_PUT) {
			curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method.c_str());
			curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
			curl_easy_setopt(curl, CURLOPT_INFILESIZE, send_buffer->allocated);
			curl_easy_setopt(curl, CURLOPT_READFUNCTION, Callback::GeneralOperationSendCallback2nd);
			curl_easy_setopt(curl, CURLOPT_READDATA, send_buffer);
		} 
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Callback::GeneralOperationRecvCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, recv_buffer);
		curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, Callback::GeneralOperationHeaderCallback);
		curl_easy_setopt(curl, CURLOPT_HEADERDATA, header_buffer);
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, http_headers);
		curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
}

ObjectMetadata ObjectOperation::ConstructGetObjectMetadataResponse(
		Request *user_data)
{
	char *headers = user_data->header_buffer()->ptr;
	ObjectMetadata metadata;
	char tmpbuf[64] = {0};
	char *iter = NULL;
	iter = strtok(headers, "#");
	int flag = 0;
	while (iter != NULL) {
		if (flag % 2 == 0) {
			memset(tmpbuf, 0, 64);
			strncpy(tmpbuf, iter, 64);
		} else {
			metadata.add_default_metadata(tmpbuf, iter);
		}
		iter = strtok(NULL, "#");
		flag++;
	}
	delete user_data;
	return metadata;
}

CopyObjectResult ObjectOperation::ConstructCopyObjectResponse(Request *user_data)
{
	const char *strxml = user_data->recv_buffer()->ptr;
	CopyObjectResult result;

	XmlNode *xml = xml_load_buffer(strxml, strlen(strxml));
	XmlNode *tmp = NULL;

	tmp = xml_find(xml, "LastModified");
	if (tmp != NULL && tmp->child != NULL) {
		result.set_last_modified(*(tmp->child->attrib));
	} else {
		result.set_last_modified("");
	}
	tmp = xml_find(xml, "ETag");
	if (tmp != NULL && tmp->child != NULL) {
		result.set_etag(*(tmp->child->attrib));
	} else {
		result.set_etag("");
	}
	
	xml_free(xml);

	delete user_data;
	return result;
}

PutObjectResult ObjectOperation::ConstructPutObjectResponse(Request *user_data)
{
	const char *etag = user_data->header_buffer()->ptr;
	PutObjectResult result;
	result.set_etag(etag);
	delete user_data;
	return result;
}
}

