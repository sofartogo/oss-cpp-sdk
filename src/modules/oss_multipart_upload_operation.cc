/*
 * =============================================================================
 *
 *       Filename:  oss_multipart_upload_operation.cc
 *
 *    Description:  oss multipart upload routines.
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

#include "oss_multipart_upload_operation.h"
#include "oss_callback.h"
#include "oss_request_param.h"

#define _OSS_CLIENT_H
#include <osscpp/modules/oss_client.h>
#undef _OSS_CLIENT_H


namespace osscpp {

void MultipartUploadOperation::DoRequest(const std::string method,
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
		if (method == OSS_HTTP_DELETE) {
			curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method.c_str());
		} else if (method  == OSS_HTTP_POST) {
			curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method.c_str());
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, send_buffer->ptr);
		} else if (method == OSS_HTTP_PUT) {
			curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method.c_str());
			curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
			curl_easy_setopt(curl, CURLOPT_INFILESIZE, send_buffer->allocated);
			curl_easy_setopt(curl, CURLOPT_READFUNCTION, Callback::GeneralOperationSendCallback2nd);
			curl_easy_setopt(curl, CURLOPT_READDATA, send_buffer);
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

void MultipartUploadOperation::DoRequest2nd(const std::string method,
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
		if (method == OSS_HTTP_DELETE) {
			curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method.c_str());
		} else if (method  == OSS_HTTP_POST) {
			curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method.c_str());
		} else if (method == OSS_HTTP_PUT) {
			curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method.c_str());
			curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
			curl_easy_setopt(curl, CURLOPT_INFILESIZE, send_buffer->allocated);
			curl_easy_setopt(curl, CURLOPT_READFUNCTION, Callback::GeneralOperationSendCallback2nd);
			curl_easy_setopt(curl, CURLOPT_READDATA, send_buffer);
		} else if (method == OSS_HTTP_GET) {
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Callback::GeneralOperationRecvCallback);
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

InitiateMultipartUploadResult
MultipartUploadOperation::ConstructInitiateMultipartUploadResponse(Request *user_data)
{
	InitiateMultipartUploadResult result;
	const char *strxml = user_data->recv_buffer()->ptr;
	XmlNode *xml = xml_load_buffer(strxml, strlen(strxml));
	XmlNode *tmp = NULL;

	tmp = xml_find(xml, "Bucket");
	result.set_bucket_name(*(tmp->child->attrib));
	tmp = xml_find(xml, "Key");
	result.set_key(*(tmp->child->attrib));
	tmp = xml_find(xml, "UploadId");
	result.set_upload_id(*(tmp->child->attrib));

	xml_free(xml);
	delete user_data;
	return result;
}

PartListing
MultipartUploadOperation::ConstructListPartsResponse(Request *user_data)
{
	PartListing listing;
	const char *strxml = user_data->recv_buffer()->ptr;
	XmlNode *xml = xml_load_buffer(strxml, strlen(strxml));
	XmlNode *tmp = NULL;
	XmlNode *tmp2 = NULL;
	int i = 0;

	tmp = xml_find(xml, "Bucket");
	if ((tmp->child) != NULL) {
		listing.set_bucket_name(*(tmp->child->attrib));
	}

	tmp = xml_find(xml, "Key");
	if ((tmp->child) != NULL) {
		listing.set_key(*(tmp->child->attrib));
	}

	tmp = xml_find(xml, "UploadId");
	if ((tmp->child) != NULL) {
		listing.set_upload_id(*(tmp->child->attrib));
	}

	tmp = xml_find(xml, "StorageClass");
	if ((tmp->child) != NULL) {
		listing.set_storage_class(*(tmp->child->attrib));
	}

	tmp = xml_find(xml, "PartNumberMarker");
	if ((tmp->child) != NULL) {
		int part_number_marker = atoi(*(tmp->child->attrib));
		listing.set_part_number_marker(part_number_marker);
	}

	tmp = xml_find(xml, "NextPartNumberMarker");
	if ((tmp->child) != NULL) {
		int next_part_number_marker = atoi(*(tmp->child->attrib));
		listing.set_next_part_number_marker(next_part_number_marker);
	}

	tmp = xml_find(xml, "MaxParts");
	if ((tmp->child) != NULL) {
		int max_parts = atoi(*(tmp->child->attrib));
		listing.set_max_parts(max_parts);
	}

	tmp = xml_find(xml, "IsTruncated");
	if ((tmp->child) != NULL) {
		if (strcmp(*(tmp->child->attrib), "false") == 0) {
			listing.set_is_truncated(0);
		} else {
			listing.set_is_truncated(1);
		}
	}

	tmp = xml_find(xml, "Part");
	unsigned int part_counts = 0;
	tmp2 = tmp;
	if (tmp2 != NULL) {
		part_counts = 1;
		while (tmp2->next != NULL) {
			tmp2 = tmp2->next;
			part_counts++;
		}

		vector<PartSummary> parts;

		tmp2 = tmp;
		for (i = 0; i < part_counts; i++) {
			PartSummary part;
			part.set_part_number(atoi(*(tmp2->child->child->attrib)));
			part.set_last_modified(*(tmp2->child->next->child->attrib));
			part.set_etag(*(tmp2->child->next->next->child->attrib));
			part.set_size(atoi(*(tmp2->child->next->next->next->child->attrib)));
			parts.push_back(part);
			tmp2 = tmp2->next;
		}

		listing.set_parts(parts);
	}

	xml_free(xml);
	delete user_data;
	return listing;
}

MultipartUploadListing
MultipartUploadOperation::ConstructListMultipartUploadsResponse(Request *user_data)
{
	MultipartUploadListing listing;
	const char *strxml = user_data->recv_buffer()->ptr;
	XmlNode *xml = xml_load_buffer(strxml, strlen(strxml));
	XmlNode *tmp = NULL;
	XmlNode *tmp2 = NULL;
	int i = 0;

	tmp = xml_find(xml, "Bucket");
	if ((tmp->child) != NULL) {
		listing.set_bucket_name(*(tmp->child->attrib));
	}

	tmp = xml_find(xml, "KeyMarker");
	if ((tmp->child) != NULL) {
		listing.set_key_marker(*(tmp->child->attrib));
	}

	tmp = xml_find(xml, "UploadIdMarker");
	if ((tmp->child) != NULL) {
		listing.set_upload_id_marker(*(tmp->child->attrib));
	}

	tmp = xml_find(xml, "NextKeyMarker");
	if ((tmp->child) != NULL) {
		listing.set_next_key_marker(*(tmp->child->attrib));
	}

	tmp = xml_find(xml, "NextUploadIdMarker");
	if ((tmp->child) != NULL) {
		listing.set_next_upload_id_marker(*(tmp->child->attrib));
	}

	tmp = xml_find(xml, "Delimiter");
	if ((tmp->child) != NULL) {
		listing.set_delimiter(*(tmp->child->attrib));
	}

	tmp = xml_find(xml, "Prefix");
	if ((tmp->child) != NULL) {
		listing.set_prefix(*(tmp->child->attrib));
	}

	tmp = xml_find(xml, "MaxUploads");
	if ((tmp->child) != NULL) {
		listing.set_max_uploads(*(tmp->child->attrib));
	}

	tmp = xml_find(xml, "IsTruncated");
	if ((tmp->child) != NULL) {
		if (strcmp(*(tmp->child->attrib), "false") == 0) {
			listing.set_is_truncated(0);
		} else {
			listing.set_is_truncated(1);
		}
	}

	tmp = xml_find(xml, "Upload");
	unsigned int upload_counts = 0;
	tmp2 = tmp;
	if (tmp2 != NULL) upload_counts = 1;
	while (tmp2->next != NULL) {
		tmp2 = tmp2->next;
		upload_counts++;
	}
	vector<MultipartUpload> uploads;

	tmp2 = tmp;
	for (i = 0; i < upload_counts; i++) {
		MultipartUpload upload;
		upload.set_key(*(tmp2->child->child->attrib));
		upload.set_upload_id(*(tmp2->child->next->child->attrib));
		upload.set_storage_class(*(tmp2->child->next->next->child->attrib));
		upload.set_initiated(*(tmp2->child->next->next->next->child->attrib));
		uploads.push_back(upload);
		tmp2 = tmp2->next;
	}

	listing.set_multipart_uploads(uploads);

	xml_free(xml);
	delete user_data;
	return listing;
}


CompleteMultipartUploadResult
MultipartUploadOperation::ConstructCompleteMultipartUploadResponse(Request* user_data)
{
	CompleteMultipartUploadResult  result;
	const char * strxml = user_data->recv_buffer()->ptr;
	XmlNode *xml = xml_load_buffer(strxml, strlen(strxml));
	XmlNode *tmp = NULL;

	tmp = xml_find(xml, "Location");
	result.set_location(*(tmp->child->attrib));
	tmp = xml_find(xml, "Bucket");
	result.set_bucket_name(*(tmp->child->attrib));
	tmp = xml_find(xml, "Key");
	result.set_key(*(tmp->child->attrib));
	tmp = xml_find(xml, "ETag");
	result.set_etag(*(tmp->child->attrib));

	xml_free(xml);
	delete user_data;
	return result;
}

UploadPartResult
MultipartUploadOperation::ConstructUploadPartResponse(Request *user_data)
{
	const char *etag = user_data->header_buffer()->ptr;
	UploadPartResult result;
	result.set_etag(etag);
	delete user_data;
	return result;
}
}

