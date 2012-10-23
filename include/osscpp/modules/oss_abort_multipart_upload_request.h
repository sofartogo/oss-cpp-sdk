/*
 * =============================================================================
 *
 *       Filename:  oss_abort_multipart_upload_request.h
 *
 *    Description:  abort multipart upload request class.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

/* 内部使用的头文件，用户开发应包含<ossc/client.h> */
#ifndef _OSS_ABORT_MULTIPART_UPLOAD_REQUEST_H
# error Never include <ossc/modules/oss_abort_multipart_upload_request.h> directly
# error use <ossc/client.h> instead.
#endif

/* 头文件保护 */
#ifndef OSS_ABORT_MULTIPART_UPLOAD_REQUEST_H 
#define OSS_ABORT_MULTIPART_UPLOAD_REQUEST_H

#include <string>

using namespace std;

namespace osscpp {

/**
 * @defgroup AbortMultipartUploadRequest AbortMultipartUploadRequest
 * @{
 */

/**
 *AbortMultipartUploadRequest 包含终止一个 Multipart 上传事件的请求参数
 */
class AbortMultipartUploadRequest {
	
	private :
		string bucket_name_;       /**< Bucket 名称 */
		string key_;               /**< Object 名称 */
		string upload_id_;         /**< 标识 Multipart 上传事件的Upload ID */

		AbortMultipartUploadRequest(const AbortMultipartUploadRequest&);
		void operator=(const AbortMultipartUploadRequest&);

	public :
		/**
		 * AbortMultipartUploadRequest 构造函数
		 * @param [in] bucket_name Bucket名称
		 * @param [in] key object名称
		 * @param [in] upload_id 标识 Multipart 上传事件的Upload ID
		 */
		AbortMultipartUploadRequest(const string &bucket_name,
				const string &key,
				const string &upload_id)
		{
			bucket_name_ = bucket_name;
			key_ = key;
			upload_id_ = upload_id;
		}
		
		/**
		 * 返回 Bucket 名称
		 * @retval const string
		 * @return Bucket 名称
		 */
		inline const string bucket_name() const
		{ return bucket_name_; }

		/**
		 * 返回 Object 名称
		 * @retval const string
		 * @return Object 名称
		 */
		inline const string key() const 
		{ return key_; }

		/**
		 * 返回 标识 Multipart 上传事件的Upload ID
		 * @retval const string
		 * @return Upload ID
		 */
		inline const string upload_id() const 
		{ return upload_id_; }

		/**
		 * 设置 Bucket 名称
		 * @param bucket_name [in] Bucket 名称
		 * @retval void
		 */
		inline void set_bucket_name(const string &bucket_name)
		{ bucket_name_ = bucket_name; }

		/**
		 * 设置 Object 名称
		 * @param key [in] Object 名称
		 * @retval void
		 */
		inline void set_key(const string &key)
		{ key_ = key; }

		/**
		 * 设置 标识 Multipart 上传事件的Upload ID
		 * @param upload_id [in] Upload ID 内容
		 * @retval void
		 */
		inline void set_upload_id(const string &upload_id)
		{ upload_id_ = upload_id; }
};
}
/** @}*/


#endif // OSS_ABORT_MULTIPART_UPLOAD_REQUEST_H
