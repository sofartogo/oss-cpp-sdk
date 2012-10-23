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

#include "oss_object_group_operation.h"

namespace osscpp {

void ObjectGroupOperation::DoRequest(const std::string method,
		const std::string resource,
		const std::string url,
		struct curl_slist *http_headers,
		void *user_data)
{
	assert(http_headers != NULL);
	assert(user_data != NULL);

	CURL *curl = NULL;
	curl_request_param_t *params = (curl_request_param_t *)user_data;

	param_buffer_t *recv_buffer = params->recv_buffer;
	param_buffer_t *header_buffer = params->header_buffer;

	curl = curl_easy_init();
	if (curl != NULL) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, static_cast<CURLoption>(CURL_HTTP_VERSION_1_1), 1L);
		if (method == OSS_HTTP_POST) {
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, params->send_buffer->ptr);
			curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method.c_str());
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Callback::GeneralOperationRecvCallback);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, recv_buffer);
			curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, Callback::GeneralOperationHeaderCallback2nd);
			curl_easy_setopt(curl, CURLOPT_HEADERDATA, header_buffer);
		} else if (method == OSS_HTTP_DELETE || method == OSS_HTTP_HEAD) {
			curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method.c_str());
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Callback::GeneralOperationRecvCallback);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, recv_buffer);
			curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, Callback::GeneralOperationHeaderCallback2nd);
			curl_easy_setopt(curl, CURLOPT_HEADERDATA, header_buffer);

		}
		else if (method == OSS_HTTP_GET) {
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Callback::GeneralOperationRecvCallback2nd);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, recv_buffer);
			curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, Callback::GeneralOperationHeaderCallback2nd);
			curl_easy_setopt(curl, CURLOPT_HEADERDATA, header_buffer);

		}

		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, http_headers);

		curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
}

PostObjectGroupResult
ObjectGroupOperation::ConstructPostObjectGroupResponse(Request *user_data)
{
	const char *response = user_data->recv_buffer()->ptr;
	assert(response != NULL);
	XmlNode *xml, *bucket_tag, *key_tag, *etag_tag, *size_tag;
	unsigned int response_len = strlen(response); 
	xml = xml_load_buffer(response, response_len);

	PostObjectGroupResult result;
	bucket_tag = xml_find(xml, "Bucket");
	result.set_bucket_name(*bucket_tag->child->attrib);
	key_tag = xml_find(xml, "Key");
	result.set_key(*key_tag->child->attrib);
 	etag_tag = xml_find(xml, "ETag");
	result.set_etag(*etag_tag->child->attrib);
	size_tag = xml_find(xml,"Size");
	unsigned int size = (unsigned int)atoi(*size_tag->child->attrib);
	result.set_size(size);
 
	delete user_data;
 	xml_free(xml);

	return result;
}

ObjectMetadata
ObjectGroupOperation::ConstructGetObjectGroupToBufferResponse(Request *user_data)
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

GetObjectGroupIndexResult 
ObjectGroupOperation::ConstructGetObjectGroupIndexResponse(Request *user_data)
{
	const char *response = user_data->recv_buffer()->ptr;
	assert(response != NULL);
	int i;
	XmlNode *xml, *bucket_tag, *key_tag, *etag_tag, *length_tag, *file_part_tag, *part_tag, *part_tmp;
	unsigned int response_len = strlen(response); 
	xml = xml_load_buffer(response, response_len);

	GetObjectGroupIndexResult result;
	bucket_tag = xml_find(xml, "Bucket");
	result.set_bucket_name(*bucket_tag->child->attrib);
	key_tag = xml_find(xml, "Key");
	result.set_key(*key_tag->child->attrib);
	etag_tag = xml_find(xml, "ETag");
	result.set_etag(*etag_tag->child->attrib);
	length_tag = xml_find(xml, "FileLength");
	unsigned int file_length = (unsigned int)atoi(*length_tag->child->attrib);
	result.set_file_length(file_length);
	
	file_part_tag = xml_find(xml, "FilePart");
	if(file_part_tag != NULL) {
		part_tag = file_part_tag->child;
	} else {
		part_tag = NULL;
	}
	if(part_tag != NULL) {
		part_tmp = part_tag;
		vector<MultipartObjectGroup> group;
		for(; part_tmp != NULL; part_tmp = part_tmp->next) {
			MultipartObjectGroup tmp;
			tmp.set_etag(*part_tmp->child->child->attrib);
			tmp.set_part_name(*part_tmp->child->next->child->attrib);
			int part_number = atoi(*part_tmp->child->next->next->child->attrib);
			tmp.set_part_number(part_number);
			unsigned int part_size = (unsigned int)(atoi(*part_tmp->child->next->next->next->child->attrib));
			tmp.set_part_size(part_size);
			group.push_back(tmp);
		}
		result.set_group(group);
	}
	
	delete user_data;
 	xml_free(xml);

	return result;
}

ObjectMetadata
ObjectGroupOperation::ConstructHeadObjectGroupResponse(Request *user_data)
{
	ObjectMetadata result;
	const char *key, *value;
	int flag = 1;
	char *ptr = user_data->header_buffer()->ptr;
	while(*ptr != '\0') {
		char *tmp = strchr(ptr, '#');
		*tmp = '\0';
		if(flag % 2) {
			key = ptr;
		} else {
			value = ptr;
			result.add_default_metadata(key, value);
		}
		ptr = tmp + 1;
		flag ++;
	}
	delete user_data;
	return result;
}

}

