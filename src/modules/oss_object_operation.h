/*
 * =============================================================================
 *
 *       Filename:  oss_object_operation.h
 *
 *    Description:  oss object operation routines.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#ifndef OSS_OBJECT_OPERATION_H
#define OSS_OBJECT_OPERATION_H

#include <curl/curl.h>
#include <string>


namespace osscpp {
class CopyObjectResult;
class ObjectMetadata;
class PutObjectResult;
class Request;

class ObjectOperation {
	public:
		static void DoRequest(const std::string method,
				const std::string resource,
				const std::string url,
				struct curl_slist *http_headers,
				void *user_data);
		
		static void DoRequest2nd(const std::string method,
				const std::string resource,
				const std::string url,
				struct curl_slist *http_headers,
				void *user_data);

		static ObjectMetadata ConstructGetObjectMetadataResponse(Request *user_data);
		static CopyObjectResult ConstructCopyObjectResponse(Request *user_data);
		static PutObjectResult ConstructPutObjectResponse(Request *user_data);
};

}

#endif // OSS_OBJECT_OPERATION_H 

