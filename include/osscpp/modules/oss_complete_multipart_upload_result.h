/*
 * =============================================================================
 *
 *       Filename:  oss_complete_multipart_upload_result.h
 *
 *    Description:  oss_complete_multipart_upload_result.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */

#ifndef _OSS_COMPLETE_MULTIPART_UPLOAD_RESULT_H
# error Never include <ossc/modules/oss_complete_multipart_upload_result.h> directly,
# error use <ossc/client.h> instead.
#endif

#ifndef OSS_COMPLETE_MULTIPART_UPLOAD_RESULT_H
#define OSS_COMPLETE_MULTIPART_UPLOAD_RESULT_H

#include <string.h>

using namespace std;

namespace osscpp {

/**
 * @defgroup CompleteMultipartUploadResult CompleteMultipartUploadResult
 * @{
 */

/**
 * 包含完成一个Multipart上传事件的返回结果
 */
class CompleteMultipartUploadResult {

	private:
		string bucket_name_;  /**< Bucket 名称 */
		string etag_;         /**< Object 的MD5值 */
		string key_;          /**< Object 名称 */
		string location_;     /**< Object 的URL地址 */

		//CompleteMultipartUploadResult(const CompleteMultipartUploadResult&);
		//void operator=(const CompleteMultipartUploadResult&);

	public:
		/**
		 * CompleteMultipartUploadResult 构造函数
		 */
		CompleteMultipartUploadResult(void)
		{}


		/**
		 * 获得Bucket的名称
		 * @return Bucket的名称
		 * @retval const string
		 */
		inline const string bucket_name() const
		{ return bucket_name_; }

		/**
		 * 设置Bucket的名称
		 * @param bucket_name [in] Bucket的名称
		 * @retval void
		 */
		inline void set_bucket_name(const string &bucket_name)
		{ bucket_name_ = bucket_name; }

		/**
		 * 获得Object的MD5值
		 * @return Object的MD5值
		 * @retval const string
		 */
		inline const string etag() const 
		{ return etag_; }

		/**
		 * 设置Object的MD5值
		 * @param etag [in] Object的MD5值
		 * @retval void
		 */
		inline void set_etag(const string &etag)
		{ etag_ = etag; }

		/**
		 * 获得Object的名称
		 * @return Object的名称
		 * @retval const string
		 */
		inline const string key() const 
		{ return key_; }

		/**
		 * 设置Object的名称
		 * @param key [in] Object的名称
		 * @retval void
		 */
		inline void set_key(const string &key)
		{ key_ = key; }

		/**
		 * 获得Object 的URL地址
		 * @return Object 的URL地址
		 * @retval const string
		 */
		inline const string location() const 
		{ return location_; }

		/**
		 * 设置Object 的URL地址
		 * @param location [in] Object 的URL地址
		 * @retval void
		 */
		inline void set_location(const string &location)
		{ location_ = location; }
};
}

/**@}*/
#endif
