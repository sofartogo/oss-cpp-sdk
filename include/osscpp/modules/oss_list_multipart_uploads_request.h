/*
 * =============================================================================
 *
 *       Filename:  oss_list_multipart_uploads_request.h
 *
 *    Description:  list multipart uploads request implementation.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#ifndef _OSS_LIST_MULTIPART_UPLOADS_REQUEST_H
# error Never include <ossc/modules/oss_list_multipart_uploads_request_h> directly
# error use <ossc/client.h> instead.
#endif

#ifndef OSS_LIST_MULTIPART_UPLOADS_REQUEST_H
#define OSS_LIST_MULTIPART_UPLOADS_REQUEST_H

#include <string>

using namespace std;

namespace osscpp {
/**
 * @defgroup ListMultipartUploadsRequest ListMultipartUploadsRequest
 * @{
 */

/**
 * 包含列出所有执行中Multipart上传事件的请求参数
 */
class ListMultipartUploadsRequest {

	private :
		string bucket_name_;            /**< Bucket名称 */
		string delimiter_;              /**< 分隔符 */
		string key_marker_;             /**< 标识表示从哪里返回列表 */
		unsigned int max_uploads_;     /**< 限制的最大返回记录数 */
		string prefix_;                 /**< 前缀 */
		string upload_id_marker_;       /**< 标识表示从哪里返回列表 */

		ListMultipartUploadsRequest(const ListMultipartUploadsRequest&);
		void operator=(const ListMultipartUploadsRequest&);

	public :
		/**
		 * ListMultipartUploadsRequest构造函数
		 * @param bucket_name [in] Bucket名称
		 */
		ListMultipartUploadsRequest(const string &bucket_name)
		{
			bucket_name_ = bucket_name;
			max_uploads_ = 0;
		}

		/**
		 * 获得Bucket名称
		 * @return Bucket名称
		 * @retval const string 
		 */
		inline const string bucket_name() const 
		{ return bucket_name_; }

		/**
		 * 获得分隔符
		 * @return delimiter
		 * @retval const string 
		 */
		inline const string delimiter() const
		{ return delimiter_; }

		/**
		 * 获得key_marker
		 * @return key_marker
		 * @retval const string 
		 */
		inline const string key_marker() const 
		{ return key_marker_; }

		/**
		 * 获得最大返回记录数
		 * @return 最大返回记录数
		 * @retval unsigned int
		 */
		inline unsigned int max_uploads() const 
		{ return max_uploads_; }

		/**
		 * 获得前缀
		 * @return 前缀
		 * @retval const string 
		 */
		inline const string prefix() const 
		{ return prefix_; }

		/**
		 * 获得upload_id_marker
		 * @return upload_id_marker
		 * @retval const string 
		 */
		inline const string upload_id_marker() const 
		{ return upload_id_marker_; }

		/**
		 * 设置Bucket名称
		 * @param bucket_name [in] Bucket名称
		 * @retval void
		 */
		inline void set_bucket_name(const string &bucket_name)
		{ bucket_name_ = bucket_name; }

		/**
		 * 设置分隔符
		 * @param delimiter [in] 分隔符
		 * @retval void
		 */
		inline void set_delimiter(const string &delimiter)
		{ delimiter_ = delimiter; }

		/**
		 * 设置key_marker
		 * @param key_marker [in] 标识表示从哪里返回列表
		 * @retval void
		 */
		inline void set_key_marker(const string &key_marker)
		{ key_marker_ = key_marker; }

		/**
		 * 设置最大返回记录数
		 * @param max_uploads [in] 最大返回记录数
		 * @retval void
		 */
		inline void set_max_uploads(unsigned int max_uploads)
		{ max_uploads_ = max_uploads; }

		/**
		 * 设置前缀
		 * @param prefix [in] 前缀
		 * @retval void
		 */
		inline void set_prefix(const string &prefix)
		{ prefix_ = prefix; }

		/**
		 * 设置 upload_id_marker
		 * @param upload_id_marker [in] 标识表示从哪里返回列表
		 * @retval void
		 */
		inline void set_upload_id_marker(const string &upload_id_marker)
		{ upload_id_marker_ = upload_id_marker; }
};
}
/**@}*/

#endif // OSS_LIST_MULTIPART_UPLOADS_REQUEST_H 


