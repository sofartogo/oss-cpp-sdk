/*
 * =============================================================================
 *
 *       Filename:  oss_initiate_multipart_upload_request.h
 *
 *    Description:  initiate multipart upload request.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#ifndef _OSS_INITIATE_MULTIPART_UPLOAD_REQUEST_H
# error Never include <ossc/modules/oss_initiate_multipart_upload_request.h> directly
# error use <ossc/client.h> instead.
#endif

#ifndef OSS_INITIATE_MULTIPART_UPLOAD_REQUEST_H 
#define OSS_INITIATE_MULTIPART_UPLOAD_REQUEST_H

#define _OSS_OBJECT_METADATA_H
#include "oss_object_metadata.h"
#undef _OSS_OBJECT_METADATA_H

#include <string.h>

using namespace std;

namespace osscpp {

/**
 * @defgroup InitiateMultipartUploadRequest InitiateMultipartUploadRequest
 * @{
 */

/**
 * 包含初始化一个Multipart上传事件的请求参数
 */
class InitiateMultipartUploadRequest {

	private :
		string bucket_name_;       /**< Bucket名称 */
		string key_;               /**< Object名称 */
		ObjectMetadata object_metadata_;     /**< Object的元信息 */

		//InitiateMultipartUploadRequest(const InitiateMultipartUploadRequest&);
		//void operator=(const InitiateMultipartUploadRequest&);

	public :
		/**
		 * InitiateMultipartUploadRequest构造函数
		 * @param bucket_name [in] Bucket名称
		 * @param key [in] Object名称
		 */
		InitiateMultipartUploadRequest(const string &bucket_name,
				const string &key)
		{
			bucket_name_ = bucket_name;
			key_ = key;
			object_metadata_ = ObjectMetadata();
		}
		
		/**
		 * InitiateMultipartUploadRequest带元信息的构造函数
		 * @param bucket_name [in] Bucket名称
		 * @param key [in] Object名称
		 * @param object_metadata [in] Object的元信息
		 */
		InitiateMultipartUploadRequest(const string &bucket_name,
				const string &key,
				ObjectMetadata &object_metadata)
		{
			bucket_name_ = bucket_name;
			key_ = key;
			object_metadata_ = object_metadata;
		}
		
		/**
		 * 获得Bucket名称
		 * @return Bucket名称
		 * @retval const string 
		 */
		inline const string bucket_name() const 
		{ return bucket_name_; }

		/**
		 * 获得Object名称
		 * @return Object名称
		 * @retval const string 
		 */
		inline const string  key() const 
		{ return key_; }

		/**
		 * 获得Object的元信息
		 * @return Object的元信息
		 * @retval 非空 表示成功
		 * @retval NULL 标识失败
		 */
		inline ObjectMetadata object_metadata() const 
		{ return object_metadata_; }

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
		 * 设置Object的元信息
		 * @param object_metadata [in] Object的元信息
		 * @retval void
		 */
		inline void set_object_metadata(ObjectMetadata &object_metadata)
		{ object_metadata_ = object_metadata; }
};
}

/**@}*/
#endif // OSS_INITIATE_MULTIPART_UPLOAD_REQUEST_H

