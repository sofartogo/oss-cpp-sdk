/*
 * =============================================================================
 *
 *       Filename:  oss_get_object_group_request.h
 *
 *    Description:  oss_get_object_group_request.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_GET_OBJECT_GROUP_REQUEST_H
# error Never include <ossc/modules/oss_get_object_group_request.h> directly,
# error use <ossc/client.h> instead.
#endif

#ifndef OSS_GET_OBJECT_GROUP_REQUEST_H
#define OSS_GET_OBJECT_GROUP_REQUEST_H

#define _OSS_RESPONSE_HEADER_OVERRIDES_H
#include "oss_response_header_overrides.h"
#undef _OSS_RESPONSE_HEADER_OVERRIDES_H

#include <string>
#include <vector>

using namespace std;

namespace osscpp {

/**
 * @defgroup GetObjectGroupRequest GetObjectGroupRequest
 * @{
 */

/**
 * 指定从OSS下载Object group的请求参数
 */
class GetObjectGroupRequest {

	private :
		string bucket_name_;          /**< Bucket名称 */
		string key_;                  /**< Object名称 */
		string modified_since_constraint_;    /**< 一个时间，如果源Object自从该时间以后被修改过，则执行拷贝操作； 否则抛出异常 */
		long start_;              /**< Object内容的起始位置 */
		long length_;             /**< Object内容的长度 */
		ResponseHeaderOverrides response_headers_; /**< 要重载的返回请求头 */
		string unmodified_since_constraint_;      /**< 一个时间，如果该时间等于或者晚于文件实际修改时间，则正常传输文件； 否则抛出异常 */
		vector<string> matching_etag_constraints_;      /**< ETag限定值的列表 */
		vector<string> no_matching_etag_constraints_;   /**< 限定Object的ETag限定必须不匹配给定值的列表 */

		GetObjectGroupRequest(const GetObjectGroupRequest&);
		void operator=(const GetObjectGroupRequest&);

	public :
		/**
		 * GetObjectGroupRequest构造函数
		 * @param bucket_name [in] Bucket名称
		 * @param key [in] Object名称
		 */
		GetObjectGroupRequest(const string &bucket_name, 
				const string &key)
		{
			bucket_name_ = bucket_name;
			key_ = key;
			start_ = 0;
			length_ = 0;
			response_headers_ = ResponseHeaderOverrides();
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
		 * 获得Object名称
		 * @return Object名称
		 * @retval const string 
		 */
		inline const string key() const 
		{ return key_; }

		/**
		 * 设置Object名称
		 * @param key [in] Object名称
		 * @retval void
		 */
		inline void set_key(const string &key)
		{ key_ = key; }

		/**
		 * 获得modified_since_constraint时间
		 * @return modified_since_constraint时间
		 * @retval const string 
		 */
		inline const string modified_since_constraint() const 
		{ return modified_since_constraint_; }

		/**
		 * 设置modified_since_constraint时间
		 * @param modified_since_constraint [in] modified_since_constraint时间
		 * @retval void
		 */
		inline void set_modified_since_constraint(const string &modified_since_constraint)
		{ modified_since_constraint_ = modified_since_constraint; }

		/**
		 * 获得Object内容的start和length
		 * @param start [out] Object内容的起始位置
		 * @param length [out] Object内容的长度
		 * @retval void
		 */
		inline void range(long &start, long &length) const 
		{
			start = start_;
			length = length_;
		}

		/**
		 * 设置Object内容的start和length
		 * @param start [in] Object内容的起始位置
		 * @param length [in] Object内容的长度
		 * @retval void
		 */
		inline void set_range(long start, long length)
		{
			start_ = start;
			length_ = length; 
		}

		/**
		 * 获得要重载的返回请求头
		 * @return 要重载的返回请求头
		 * @retval 非空 表示成功
		 * @retval NULL 表示失败
		 */
		inline ResponseHeaderOverrides response_headers() const 
		{ return response_headers_; }

		/**
		 * 设置要重载的返回请求头
		 * @param response_headers [in] 要重载的返回请求头
		 * @retval void
		 */
		inline void set_response_headers(ResponseHeaderOverrides &response_headers)
		{ response_headers_ = response_headers; }

		/**
		 * 获得unmodified_since_constraint时间
		 * @return unmodified_since_constraint时间
		 * @retval const string 
		 */
		inline const string unmodified_since_constraint() const 
		{ return unmodified_since_constraint_; }

		/**
		 * 设置unmodified_since_constraint时间
		 * @param unmodified_since_constraint [in] unmodified_since_constraint时间
		 * @retval void
		 */
		inline void set_unmodified_since_constraint(const string &unmodified_since_constraint)
		{ unmodified_since_constraint_ = unmodified_since_constraint; }

		/**
		 * 获得ETag限定值的列表
		 * @return ETag限定值的列表
		 * @retval const string *
		 */
		inline vector<string>  matching_etag_constraints() const
		{ return matching_etag_constraints_; }

		/**
		 * 设置ETag限定值的列表
		 * @param matching_etag_constraints [in] 设置ETag限定值的列表
		 * @retval void
		 */
		inline void set_matching_etag_constraints(vector<string> &matching_etag_constraints)
		{ matching_etag_constraints_ = matching_etag_constraints; }

		/**
		 * 获得限定Object的ETag限定必须不匹配给定值的列表
		 * @return 限定Object的ETag限定必须不匹配给定值的列表
		 * @retval const string *
		 */
		inline vector<string> no_matching_etag_constraints() const
		{ return no_matching_etag_constraints_; }

		/**
		 * 设置限定Object的ETag限定必须不匹配给定值的列表
		 * @param no_matching_etag_constraints [in] 限定Object的ETag限定必须不匹配给定值的列表
		 * @retval void
		 */
		inline void set_no_matching_etag_constraints(vector<string> &no_matching_etag_constraints)
		{ no_matching_etag_constraints_ = no_matching_etag_constraints; }
};
}
/**@}*/
#endif
