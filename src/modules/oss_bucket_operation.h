/*
 * =============================================================================
 *
 *       Filename:  oss_bucket_operation.h
 *
 *    Description:  bucket operation routines.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#ifndef OSS_BUCKET_OPERATION_H
#define OSS_BUCKET_OPERATION_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include <curl/curl.h>

#include "oss_callback.h"
#include "oss_request_param.h"
#include <lib/oss_ttxml.h>

#define _OSS_CLIENT_H
#include <osscpp/modules/oss_client.h>
#undef _OSS_CLIENT_H

namespace osscpp {

class BucketOperation {
	public:
		static void DoRequest(const std::string method,
				const std::string resource,
				const std::string url,
				struct curl_slist *http_headers,
				void *user_data);

		static vector<Bucket> ConstructListBucketsResponse(Request *user_data);
		static AccessControlList ConstructGetBucketAclResponse(Request *user_data);
		static ObjectListing ConstructListObjectsResponse(Request *user_data);
};
}

#endif // OSS_BUCKET_OPERATION_H

