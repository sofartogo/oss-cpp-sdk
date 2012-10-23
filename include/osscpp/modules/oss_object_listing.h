/*
 * =============================================================================
 *
 *       Filename:  oss_object_listing.h
 *
 *    Description:  oss_object_listing.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_OBJECT_LISTING_H
# error Never include <ossc/modules/oss_object_listing.h> directly, use <ossc/client.h> instead.
#endif

#ifndef OSS_OBJECT_vectorING_H
#define OSS_OBJECT_vectorING_H
#define _OSS_OBJECT_SUMMARY_H
#include "oss_object_summary.h"
#undef _OSS_OBJECT_SUMMARY_H

#include <string>
#include <vector>
using namespace std;

namespace osscpp {

/**
 * @defgroup ObjectListing ObjectListing
 * @{
 */

/**
 * 一个Bucket中所有的Object信息
 */
class ObjectListing {

	private :
		string bucket_name_;       /**< Bucket名称 */
		string next_marker_;       /**< 如果因为 max-keys 的设定无法一次完成 vectoring,返回结果会附加一个NextMarker */
		string prefix_;            /**< 前缀 */
		string marker_;            /**< 标识表示从哪里返回列表 */
		int max_keys_;            /**< 返回 object 的最大数 */
		string  delimiter_;        /**< 分隔符 */
		bool is_truncated_;       /**< 标识是否有未显示的Object */

		vector<ObjectSummary> summaries_;      /**< 所有的Object信息 */
		vector<string> common_prefixes_;       /**< 名字包含指定的前缀且第一次出现 delimiter 字符之间的 object */

		//ObjectListing(const ObjectListing&);
		//void operator=(const ObjectListing&);

	public :
		/**
		 * Objectvectoring构造函数
		 */
		ObjectListing(void)
		{
			max_keys_ = 0;
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
		 * 获得next_marker
		 * @return next_marker
		 * @retval const string 
		 */
		inline const string next_marker() const 
		{ return next_marker_; }

		/**
		 * 设置next_marker
		 * @param next_marker [in] next_marker
		 * @retval void
		 */
		inline void set_next_marker(const string &next_marker) 
		{ next_marker_ = next_marker; }

		/**
		 * 获得前缀
		 * @return 前缀
		 * @retval const string 
		 */
		inline const string prefix() const 
		{ return prefix_; }

		/**
		 * 设置前缀
		 * @param prefix [in] 前缀
		 * @retval void
		 */
		inline void set_prefix(const string &prefix)
		{ prefix_ = prefix; }

		/**
		 * 获得marker
		 * @return marker
		 * @retval const string 
		 */
		inline const string  marker() const 
		{ return marker_; }

		/**
		 * 设置marker
		 * @param marker [in] marker
		 * @retval void
		 */
		inline void set_marker(const string &marker)
		{ marker_ = marker; }

		/**
		 * 获得max_keys
		 * @return max_keys
		 * @retval int
		 */
		inline int max_keys() const 
		{ return max_keys_; }

		/**
		 * 设置max_keys
		 * @param max_keys [in] max_keys
		 * @retval void
		 */
		inline void set_max_keys(int max_keys)
		{ max_keys_ = max_keys; }

		/**
		 * 获得分隔符
		 * @return 分隔符
		 * @retval const string 
		 */
		inline const string  delimiter() const 
		{ return delimiter_; }

		/**
		 * 设置分隔符
		 * @param delimiter [in] 分隔符
		 * @retval void
		 */
		inline void set_delimiter(const string &delimiter)
		{ delimiter_ = delimiter; }

		/**
		 * 获得is_truncated
		 * @return is_truncated
		 * @retval bool
		 */
		inline bool is_truncated() const
		{ return is_truncated_; }

		/**
		 * 设置is_truncated
		 * @param is_truncated [in] is_truncated
		 * @retval void
		 */
		inline void set_is_truncated(bool is_truncated)
		{ is_truncated_ = is_truncated; }

		/**
		 * 获得common_prefixes
		 * @return common_prefixes
		 * @retval const string *
		 */
		inline vector<string> common_prefixes() const
		{ return common_prefixes_; }

		/**
		 * 设置common_prefixes
		 * @param common_prefixes [in] common_prefixes
		 * @retval void
		 */
		inline void set_common_prefixes(vector<string> &common_prefixes)
		{ common_prefixes_ = common_prefixes; }

		/**
		 * 获得所有的Object信息
		 * @return 返回一个ObjectSummary结构指针
		 * @retval 非空 表示成功
		 * @retval NULL 表示失败
		 */
		inline vector<ObjectSummary> summaries() const
		{ return summaries_; }

		/**
		 * 设置summaries
		 * @param summaries [in] summaries
		 * @retval void
		 */
		inline void set_summaries(vector<ObjectSummary> &summaries)
		{ summaries_ = summaries; }
};
}
/**@}*/
#endif
