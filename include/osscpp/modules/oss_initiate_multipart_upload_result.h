/*
 * =============================================================================
 *
 *       Filename:  oss_initiate_multipart_upload_result.h
 *
 *    Description:  initiate multipart upload result implementation.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#ifndef _OSS_INITIATE_MULTIPART_UPLOAD_RESULT_H
# error Never include <ossc/modules/oss_initiate_multipart_upload_result.h> directly
# error use <ossc/client.h> instead.
#endif

#ifndef OSS_INITIATE_MULTIPART_UPLOAD_RESULT_H 
#define OSS_INITIATE_MULTIPART_UPLOAD_RESULT_H

#include <string>

using namespace std;

namespace osscpp {

/**
 * @defgroup InitiateMultipartUploadResult InitiateMultipartUploadResult
 * @{
 */

/**
 * 包含初始化一个Multipart上传事件的结果参数
 */
struct InitiateMultipartUploadResult {

	private :
		string bucket_name_;        /**< Bucket名称 */
		string key_;                /**< Object名称 */
		string upload_id_;          /** 标识Multipart上传事件的Upload ID */
		
		//InitiateMultipartUploadResult(const InitiateMultipartUploadResult&);
		//void operator=(const InitiateMultipartUploadResult&);

	public :
		/**
		 * InitiateMultipartUploadResult构造函数
		 */
		InitiateMultipartUploadResult(void)
		{}

		/**
		 * 获得Bucket名称
		 * @return Bucket名称
		 * @retval const string 
		 */
		inline const string  bucket_name() const 
		{ return bucket_name_; }

		/**
		 * 获得Object名称
		 * @return Object名称
		 * @retval const string 
		 */
		inline const string  key() const 
		{ return key_; }

		/**
		 * 获得Upload ID
		 * @return Upload ID
		 * @retval const string 
		 */
		inline const string  upload_id() const 
		{ return upload_id_; }

		/**
		 * 设置Bucket名称
		 * @param bucket_name [in] Bucket名称
		 * @retval void
		 */
		inline void set_bucket_name(const string &bucket_name)
		{ bucket_name_ = bucket_name; }

		/**
		 * 设置Object名称
		 * @param key [in] Object名称
		 * @retval void
		 */
		inline void set_key(const string &key)
		{ key_ = key; }

		/**
		 * 设置Upload ID
		 * @param upload_id [in] Upload ID
		 * @retval void
		 */
		inline void set_upload_id(const string &upload_id)
		{ upload_id_ = upload_id; }
};
}
/**@}*/
#endif // OSS_INITIATE_MULTIPART_UPLOAD_RESULT_H
