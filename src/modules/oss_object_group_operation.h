/*
 * =============================================================================
 *
 *       Filename:  oss_object_group_operation.h
 *
 *    Description:  oss object group operation routines.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#ifndef OSS_OBJECT_GROUP_OPERATION_H
#define OSS_OBJECT_GROUP_OPERATION_H

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

class ObjectGroupOperation {
	public:
		static void DoRequest(const std::string method,
				const std::string resource,
				const std::string url,
				struct curl_slist *http_headers,
				void *user_data);
		
		static PostObjectGroupResult ConstructPostObjectGroupResponse(Request *user_data);

		static ObjectMetadata ConstructGetObjectGroupToBufferResponse(Request *user_data);

		static GetObjectGroupIndexResult ConstructGetObjectGroupIndexResponse(Request *user_data);

		static ObjectMetadata ConstructHeadObjectGroupResponse(Request *user_data);
};

}

#endif // OSS_OBJECT_OPERATION_H 

