/*
 * =============================================================================
 *
 *       Filename:  oss_list_objects_request.h
 *
 *    Description:  list object request implementation. 
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#ifndef _OSS_LIST_OBJECTS_REQUEST_H
# error Never include <ossc/modules/oss_list_objects_request_h> directly
# error use <ossc/client.h> instead.
#endif

#ifndef OSS_LIST_OBJECTS_REQUEST_H
#define OSS_LIST_OBJECTS_REQUEST_H

#include <string>

using namespace std;

namespace osscpp {

/**
 * @defgroup ListObjectsRequest ListObjectsRequest
 * @{
 */

/**
 * 包含获取object列表的请求信息
 */
class ListObjectsRequest {

	private :
		string bucket_name_;          /**< Bucket名称 */
		string delimiter_;            /**< 分隔符 */
		string marker_;               /**< 标识表示从哪里返回列表 */
		unsigned int max_keys_;      /**< 限制的最大返回记录数 */
		string prefix_;               /**< 前缀 */

		ListObjectsRequest(const ListObjectsRequest&);
		void operator=(const ListObjectsRequest&);

	public :
		/**
		 * ListObjectsRequest构造函数
		 */
		ListObjectsRequest(void)
		{ max_keys_ = 0; }
		
		/**
		 * ListObjectsRequest带bucket_name的构造函数
		 * @param bucket_name [in] Bucket名称
		 */
		ListObjectsRequest(const string &bucket_name)
		{
			bucket_name_ = bucket_name;
			max_keys_ = 0;
		}
		
		/**
		 * ListObjectsRequest带多参数的构造函数
		 * @param bucket_name [in] Bucket名称
		 * @param prefix [in] 前缀
		 * @param marker [in] 标识表示从哪里返回列表
		 * @param delimiter [in] 分隔符
		 * @param max_keys [in] 限制的最大返回记录数
		 */
		ListObjectsRequest(const string &bucket_name,
				const string &prefix,
				const string &marker,
				const string &delimiter,
				unsigned int max_keys)
		{
			bucket_name_ = bucket_name;
			prefix_ = prefix;
			marker_ = marker;
			delimiter_ = delimiter;
			max_keys_ = max_keys;
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
		inline const string  delimiter() const 
		{ return delimiter_; }

		/**
		 * 获得marker
		 * @return marker
		 * @retval const string 
		 */
		inline const string marker() const 
		{ return marker_; }

		/**
		 * 获得最大返回记录数
		 * @return max_keys
		 * @retval unsigned int
		 */
		inline unsigned int max_keys() const 
		{ return max_keys_; }

		/**
		 * 获得前缀
		 * @return 前缀
		 * @retval const string 
		 */
		inline const string prefix() const 
		{ return prefix_; }

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
		 * 设置marker
		 * @param marker [in] marker
		 * @retval void
		 */
		inline void set_marker(const string &marker)
		{ marker_ = marker; }

		/**
		 * 设置max_keys
		 * @param max_keys [in] max_keys
		 * @retval void
		 */
		inline void set_max_keys(unsigned int max_keys)
		{ max_keys_ = max_keys; }

		/**
		 * 设置前缀
		 * @param prefix [in] 前缀
		 * @retval void
		 */
		inline void set_prefix(const string &prefix)
		{ prefix_ = prefix; }
};
}
/**@}*/
#endif // OSS_LIST_OBJECTS_REQUEST_H 

