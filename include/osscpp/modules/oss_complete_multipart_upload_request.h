/*
 * =============================================================================
 *
 *       Filename:  oss_complete_multipart_upload_request.h
 *
 *    Description:  oss_complete_multipart_upload_request.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_COMPLETE_MULTIPART_UPLOAD_REQUEST_H
# error Never include <ossc/modules/oss_complete_multipart_upload_request.h> directly, use <ossc/client.h> instead.
#endif

#ifndef OSS_COMPLETE_MULTIPART_UPLOAD_REQUEST_H
#define OSS_COMPLETE_MULTIPART_UPLOAD_REQUEST_H

#define _OSS_PART_ETAG_H
#include "oss_part_etag.h"
#undef _OSS_PART_ETAG_H

#include <string>
#include <vector>

using namespace std;

namespace osscpp {

/**
 * @defgroup CompleteMultipartUploadRequest CompleteMultipartUploadRequest
 * @{
 */

/**
 * 包含完成一个Multipart上传事件的请求参数
 */
class CompleteMultipartUploadRequest {

	private :
		string bucket_name_;      /**< Bucket 名称 */
		string key_;              /**< Object 名称 */
		vector<PartEtag> part_etags_;     /**< 标识上传Part结果的PartETag列表 */
		string upload_id_;         /** 标识Multipart上传事件的Upload ID */

		CompleteMultipartUploadRequest(const CompleteMultipartUploadRequest&);
		void operator=(const CompleteMultipartUploadRequest&);

	public :
		/**
		 * CompleteMultipartUploadRequest 构造函数
		 * @param bucket_name [in] Bucket的名称
		 * @param key [in] Object的名称
		 * @param upload_id [in] Upload ID的内容
		 * @param part_etags [in] 标识一个PartEtag的双重指针
		 */
		CompleteMultipartUploadRequest(const string &bucket_name,
				const string &key,
				const string &upload_id,
				vector<PartEtag> &part_etags)
		{
			bucket_name_ = bucket_name;
			key_ = key;
			upload_id_ = upload_id;
			part_etags_ = part_etags;
		}

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
		 * 获得PartETag列表内容
		 * @return 返回一个PartEtag的vector
		 * @retval 非空 表示成功
		 * @retval NULL 表示失败
		 */
		inline vector<PartEtag> part_etags() const
		{ return part_etags_; }

		/**
		 * 设置PartETag列表内容
		 * @param part_etags [in] 标识一个PartEtag的数组
		 * retval void
		 */
		inline void set_part_etags(vector<PartEtag> &part_etags)
		{ part_etags_ = part_etags; }

		/**
		 * 获得Upload ID的内容
		 * @return Upload ID的内容
		 * @retval const string 
		 */
		inline const string upload_id() const 
		{ return upload_id_; }

		/**
		 * 设置Upload ID的内容
		 * @param upload_id [in] Upload ID的内容
		 * @retval void
		 */
		inline void set_upload_id(const string &upload_id)
		{ upload_id_ = upload_id; }
};
}

/**@}*/
#endif
