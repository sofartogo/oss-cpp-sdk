/*
 * =============================================================================
 *
 *       Filename:  oss_multipart_upload_listing.h
 *
 *    Description:  oss_multipart_upload_listing.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_MULTIPART_UPLOAD_LISTING_H
# error Never include <ossc/modules/oss_multipart_upload_listing.h> directly, use <ossc/client.h> instead.
#endif

#ifndef OSS_MULTIPART_UPLOAD_LISTING_H
#define OSS_MULTIPART_UPLOAD_LISTING_H

#define _OSS_MULTIPART_UPLOAD_H
#include "oss_multipart_upload.h"
#undef _OSS_MULTIPART_UPLOAD_H

#include <string>
#include <vector>

using namespace std;

namespace osscpp {
/**
 * @defgroup MultipartUploadListing MultipartUploadListing
 * @{
 */

/**
 * 包含Multipart上传事件的列表
 */
class MultipartUploadListing {

	private :
		string bucket_name_;               /**< Bucket名称 */
		vector<string> common_prefixs_;    /**< 包含指定的前缀且第一次出现 delimiter 字符之间的object */
		string key_marker_;             /**< 标识表示从哪里返回列表 */
		string upload_id_marker_;       /**< 标识表示从哪里返回列表 */
		string next_key_marker_;        /**< 标识返回列表到哪里终止 */
		string next_upload_id_marker_;  /**< 标识返回列表到哪里终止 */
		string max_uploads_;            /**< 返回 Multipart Uploads 事件的最大数目 */
		vector<MultipartUpload> multipart_uploads_;    /**< 各个multipart upload 的信息 */
		bool is_truncated_;            /**< 标识是否还有其他multipart upload */
		string delimiter_;              /**< 分隔符*/
		string prefix_;                 /**< 前缀 */

		//MultipartUploadListing(const MultipartUploadListing&);
		//void operator=(const MultipartUploadListing&);

	public :
		/**
		 * MultipartUploadvectoring构造函数
		 */
		MultipartUploadListing(void)
		{
			is_truncated_ = false;
		}

		/**
		 * 获得Bucket名称
		 * @return Bucket名称
		 * @retval const string 
		 */
		inline const string bucket_name() const 
		{ return bucket_name_; }

		/**
		 * 设置Bucket名称
		 * @param bucket_name [in] Bucket名称
		 * @retval void
		 */
		inline void set_bucket_name(const string &bucket_name)
		{ bucket_name_ = bucket_name; }

		/**
		 * 获得key_marker
		 * @return key_marker
		 * @retval const string 
		 */
		inline const string key_marker() const 
		{ return key_marker_; }

		/**
		 * 设置key_marker
		 * @param key_marker [in] 标识表示从哪里返回列表
		 * @retval void
		 */
		inline void set_key_marker(const string &key_marker)
		{ key_marker_ = key_marker; }

		/**
		 * 获得upload_id_marker
		 * @return upload_id_marker
		 * @retval const string 
		 */
		inline const string upload_id_marker() const 
		{ return upload_id_marker_; }

		/**
		 * 设置upload_id_marker
		 * @param upload_id_marker [in] 标识表示从哪里返回列表
		 * @retval void
		 */
		inline void set_upload_id_marker(const string &upload_id_marker)
		{ upload_id_marker_ = upload_id_marker; }

		/**
		 * 获得next_key_marker
		 * @return next_key_marker
		 * @retval const string 
		 */
		inline const string next_key_marker() const 
		{ return next_key_marker_; }

		/**
		 * 设置next_key_marker
		 * @param next_key_marker [in] 标识返回列表到哪里终止
		 * @retval void
		 */
		inline void set_next_key_marker(const string &next_key_marker)
		{ next_key_marker_ = next_key_marker; }

		/**
		 * 获得next_upload_id_marker
		 * @return next_upload_id_marker
		 * @retval const string 
		 */
		inline const string next_upload_id_marker() const 
		{ return next_upload_id_marker_; }

		/**
		 * 设置next_upload_id_marker
		 * @param next_upload_id_marker [in] 标识返回列表到哪里终止
		 * @retval void
		 */
		inline void set_next_upload_id_marker(const string &next_upload_id_marker)
		{ next_upload_id_marker_ = next_upload_id_marker; }

		/**
		 * 获得max_uploads
		 * @return Multipart Uploads 事件的最大数目
		 * @retval const string 
		 */
		inline const string  max_uploads() const 
		{ return max_uploads_; }

		/**
		 * 设置max_uploads
		 * @param max_uploads [in] Multipart Uploads 事件的最大数目
		 * @retval void
		 */
		inline void set_max_uploads(const string &max_uploads) 
		{ max_uploads_ = max_uploads; } 

		/**
		 * 获得is_truncated
		 * @return is_truncated
		 * @retval bool
		 */
		inline bool is_truncated() const 
		{ return is_truncated_; }

		/**
		 * 设置is_truncated
		 * @param is_truncated [in] 标识是否还有其他multipart upload
		 * @retval void
		 */
		inline void set_is_truncated(bool is_truncated)
		{ is_truncated_ = is_truncated; }

		/**
		 * 获得各个multipart upload 的信息
		 * @return 返回一个MultipartUpload结构指针
		 * @retval 非空 标识成功
		 * @retval NULL 标识失败
		 */
		inline vector<MultipartUpload> multipart_uploads() const
		{ return multipart_uploads_; }

		/**
		 * 设置各个multipart upload 的信息
		 * @param multipart_uploads [in] 各个multipart upload 的信息
		 * @retval void
		 */
		inline void set_multipart_uploads(vector<MultipartUpload> &multipart_uploads)
		{ multipart_uploads_ = multipart_uploads; }

		/**
		 * 获得common_prefixs
		 * @return const string *
		 */
		inline vector<string> common_prefixs() const
		{ return common_prefixs_; }

		/**
		 * 设置common_prefixs
		 * @param common_prefixs [in] common_prefixs
		 * @retval void
		 */
		inline void set_common_prefixs(vector<string> &common_prefixs)
		{ common_prefixs_ = common_prefixs; }

		/**
		 * 获得分隔符
		 * @return 分隔符
		 * @return const string 
		 */
		inline const string delimiter() const 
		{ return delimiter_; }

		/**
		 * 设置分隔符
		 * @param delimiter [in] 分隔符
		 * @retval void
		 */
		inline void set_delimiter(const string delimiter)
		{ delimiter_ = delimiter; }

		/**
		 * 获得前缀
		 * @return 前缀
		 * @return const string 
		 */
		inline const string prefix() const 
		{ return prefix_; }

		/**
		 * 设置前缀
		 * @param prefix [in] 前缀
		 * @retval void
		 */
		inline void set_prefix(const string prefix) 
		{ prefix_ = prefix; }
};
}
/**@}*/
#endif
