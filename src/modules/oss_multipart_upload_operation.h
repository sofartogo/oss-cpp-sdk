/*
 * =============================================================================
 *
 *       Filename:  oss_multipart_upload_operation.h
 *
 *    Description:  oss multipart upload operation routines.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#ifndef OSS_MULTIPART_UPLOAD_OPERATION_H
#define OSS_MULTIPART_UPLOAD_OPERATION_H

#include <curl/curl.h>
#include <string>


namespace osscpp {

class Request;
class CompleteMultipartUploadResult;
class InitiateMultipartUploadResult;
class PartListing;
class MultipartUploadListing;
class UploadPartResult;

class MultipartUploadOperation {
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

		static InitiateMultipartUploadResult ConstructInitiateMultipartUploadResponse(Request *user_data);
		static PartListing ConstructListPartsResponse(Request *user_data);
		static MultipartUploadListing ConstructListMultipartUploadsResponse(Request *user_data);
		static CompleteMultipartUploadResult ConstructCompleteMultipartUploadResponse(Request* user_data);
		static UploadPartResult ConstructUploadPartResponse(Request *user_data);
};

}

#endif // OSS_OBJECT_OPERATION_H 

