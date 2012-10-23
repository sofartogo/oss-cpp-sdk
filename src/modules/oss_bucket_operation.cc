/*
 * =============================================================================
 *
 *       Filename:  oss_bucket_operation.cc
 *
 *    Description:  oss bucket operation routines.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#include "oss_bucket_operation.h"

namespace osscpp {

void BucketOperation::DoRequest(const std::string method,
		const std::string resource,
		const std::string url,
		struct curl_slist *http_headers,
		void *user_data)
{
	assert(http_headers != NULL);
	assert(user_data != NULL);

	CURL *curl = NULL;
	Request *params = (Request *)user_data;

	ParamBuffer *recv_buffer = params->recv_buffer();
	ParamBuffer *header_buffer = params->header_buffer();

	curl = curl_easy_init();
	if (curl != NULL) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, static_cast<CURLoption>(CURL_HTTP_VERSION_1_1), 1L);
		if (method == OSS_HTTP_PUT || method == OSS_HTTP_DELETE) {
			curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method.c_str());
		}
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Callback::GeneralOperationRecvCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, recv_buffer);
		curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, Callback::GeneralOperationHeaderCallback);
		curl_easy_setopt(curl, CURLOPT_HEADERDATA, header_buffer);
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, http_headers);

		//
		//curl_easy_setopt(curl, CURLOPT_HEADER, 1L);
		//curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
		//

		curl_easy_perform(curl);

		curl_easy_cleanup(curl);
	}
}

vector<Bucket>
BucketOperation::ConstructListBucketsResponse(Request *user_data)
{
	const char *response = user_data->recv_buffer()->ptr;
	assert(response != NULL);
	XmlNode *xml, *buckets_tag, *bucket_tag, *owner_tag;
	int i, buckets_number = 0;
	unsigned int response_len = strlen(response); 
	xml = xml_load_buffer(response, response_len);

	vector<Bucket> buckets;
	
	buckets_tag = xml_find(xml, "Buckets");
	if(buckets_tag != NULL) {
		bucket_tag = buckets_tag->child;
	} else {
		bucket_tag = NULL;
	}
	for(; bucket_tag != NULL; bucket_tag = bucket_tag->next) {
		buckets_number++;
	}
	
	if(buckets_number > 0) {
		owner_tag = xml_find(xml, "Owner");
		Owner owner(*owner_tag->child->child->attrib,
			*owner_tag->child->next->child->attrib);

		for(i = 0, bucket_tag = buckets_tag->child;
				i < buckets_number; i++, bucket_tag = bucket_tag->next) {
			Bucket bucket;
			bucket.set_name(*bucket_tag->child->child->attrib);
			bucket.set_create_date(*bucket_tag->child->next->child->attrib);
			bucket.set_owner(owner);
			buckets.push_back(bucket);
		}
	}
 
	delete user_data;
 	xml_free(xml);

	return buckets;
	
}

AccessControlList 
BucketOperation::ConstructGetBucketAclResponse(Request *user_data)
{
	const char *response = user_data->recv_buffer()->ptr;
	assert(response != NULL);
	XmlNode *xml, *grant_tag, *owner_tag;
	unsigned int response_len = strlen(response); 
	xml = xml_load_buffer(response, response_len);

	owner_tag = xml_find(xml, "Owner");
	Owner owner(*owner_tag->child->child->attrib,
			*owner_tag->child->next->child->attrib);

 	grant_tag = xml_find(xml, "Grant");
	
	AccessControlList acl;
	acl.set_grant(*grant_tag->child->attrib);
	acl.set_owner(owner);
	
	delete user_data;
 	xml_free(xml);

	return acl;
	
}

ObjectListing 
BucketOperation::ConstructListObjectsResponse(Request *user_data)
{
	const char *response = user_data->recv_buffer()->ptr;
	int i;
	XmlNode *xml = NULL;
	XmlNode *name_tag, *prefix_tag, *marker_tag, *max_keys_tag;
	XmlNode *delimiter_tag, *is_truncated_tag, *next_marker_tag;
	XmlNode *contents_tag, *common_prefixes_tag, *contents_tmp;
	XmlNode *common_prefixes_tmp = NULL;

	unsigned int response_len = strlen(response); 
	xml = xml_load_buffer(response, response_len);
	ObjectListing object_listing;

	name_tag = xml_find(xml, "Name");
	object_listing.set_bucket_name(*name_tag->child->attrib);

	prefix_tag = xml_find(xml, "Prefix");
	if(prefix_tag->child == NULL) {
		object_listing.set_prefix("");
	} else {
		object_listing.set_prefix(*prefix_tag->child->attrib);
	}

	marker_tag = xml_find(xml, "Marker");
	if(marker_tag->child == NULL) {
		object_listing.set_marker("");
	} else {
		object_listing.set_marker(*marker_tag->child->attrib);
	}

	next_marker_tag = xml_find(xml, "NextMarker");
	if(next_marker_tag == NULL) {
		object_listing.set_next_marker("");
	} else {
		if(next_marker_tag->child == NULL) {
			object_listing.set_next_marker("");
		} else {
			object_listing.set_next_marker(*next_marker_tag->child->attrib);
		}
	}

	max_keys_tag = xml_find(xml, "MaxKeys");
	if(max_keys_tag->child == NULL)
	{
		object_listing.set_max_keys(0);
	} else {
		int max_keys = atoi(*max_keys_tag->child->attrib);
		object_listing.set_max_keys(max_keys);
	}

	delimiter_tag = xml_find(xml, "Delimiter");
	if(delimiter_tag->child == NULL) {
		object_listing.set_delimiter("");
	} else {
		object_listing.set_delimiter(*delimiter_tag->child->attrib);
	}

	is_truncated_tag = xml_find(xml, "IsTruncated");
	if(is_truncated_tag->child == NULL) {
		object_listing.set_is_truncated(false);
	} else {
		if(strcmp(*is_truncated_tag->child->attrib, "false") == 0) {
			object_listing.set_is_truncated(false);
		} else {
			object_listing.set_is_truncated(true);
		}
	}
	
	contents_tag = xml_find(xml, "Contents");
	if(contents_tag != NULL) {
		contents_tmp = contents_tag;
		vector<ObjectSummary> summaries;
		for(; contents_tmp != NULL; contents_tmp = contents_tmp->next) {
			if(strcmp(contents_tmp->name, "Contents") == 0) {
				ObjectSummary object_summary;
				object_summary.set_key(*contents_tmp->child->child->attrib);
				object_summary.set_last_modified(*contents_tmp->child->next->child->attrib);
				object_summary.set_etag(*contents_tmp->child->next->next->child->attrib);
				object_summary.set_type(*contents_tmp->child->next->next->next->child->attrib);
				long size = atol(*contents_tmp->child->next->next->next->next->child->attrib);
				object_summary.set_size(size);
				object_summary.set_storage_class(*contents_tmp->child->next->next->next->next->next->child->attrib);
				Owner owner(
						*contents_tmp->child->next->next->next->next->next->next->child->child->attrib,
						*contents_tmp->child->next->next->next->next->next->next->child->next->child->attrib);		
				object_summary.set_owner(owner);
				summaries.push_back(object_summary);
			} else
				break;
		}
		object_listing.set_summaries(summaries);
	}

	common_prefixes_tag = xml_find(xml, "CommonPrefixes");
	if(common_prefixes_tag != NULL) {
		vector<string> prefixes;
		common_prefixes_tmp = common_prefixes_tag;
		for(; common_prefixes_tmp != NULL; 
				common_prefixes_tmp = common_prefixes_tmp->next) {
			const string tmp = *common_prefixes_tmp->child->child->attrib;
			prefixes.push_back(tmp);
		}
		object_listing.set_common_prefixes(prefixes);
	}
 
	delete user_data;
 	xml_free(xml);

	return object_listing;
}

}
