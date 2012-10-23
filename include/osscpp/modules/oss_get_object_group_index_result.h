/*
 * =============================================================================
 *
 *       Filename:  oss_get_object_group_index_result.h
 *
 *    Description:  oss get_object_group_index_result
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#ifndef _OSS_GET_OBJECT_GROUP_INDEX_RESULT_H
# error Never include <ossc/modules/oss_get_object_group_index_result.h> directly, use <ossc/client.h> instead.
#endif

#ifndef OSS_GET_OBJECT_GROUP_INDEX_RESULT_H
#define OSS_GET_OBJECT_GROUP_INDEX_RESULT_H

#define _OSS_MULTIPART_OBJECT_GROUP_H
#include "oss_multipart_object_group.h"
#undef _OSS_MULTIPART_OBJECT_GROUP_H

#include <string>
#include <vector>

using namespace std;

namespace osscpp {
/**
 * @defgroup GetObjectGroupIndexResult GetObjectGroupIndexResult
 * @{
 */

/**
 * 用于返回 Object Group 中的 Object vector 信息
 */
class GetObjectGroupIndexResult {

	private :
		string bucket_name_;               /**< Bucket名称 */
		string key_;                       /**< Object名称 */
		string etag_;                      /**< Object的MD5值 */
		vector<MultipartObjectGroup> group_;  /**< object group中的多个object列表 */
		size_t file_length_;              /**< 文件长度 */


		//GetObjectGroupIndexResult(const GetObjectGroupIndexResult&);
		//void operator=(const GetObjectGroupIndexResult&);

	public :
		/**
		 * GetObjectGroupIndexResult构造函数
		 */
		GetObjectGroupIndexResult()
		{
			file_length_ = 0;
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
		 * 获得object group中的多个object列表
		 * @return object group中的多个object列表
		 * @retval 非空 表示成功
		 * @retval NULL 表示失败
		 */
		inline vector<MultipartObjectGroup> group() const
		{ return group_; } 

		/**
		 * 设置object group中的多个object列表
		 * @param group [in] object group中的多个object列表
		 * @retval void
		 */
		inline void set_group(vector<MultipartObjectGroup> &group)
		{ group_ = group; }
		
		/**
		 * 获得Object的文件长度
		 * @return Object的文件长度
		 * @retval size_t
		 */
		inline size_t file_length() const 
		{ return file_length_; }

		/**
		 * 设置Object的文件长度
		 * @param file_length [in] Object的文件长度
		 * @retval void
		 */
		inline void set_file_length(size_t file_length)
		{ file_length_ = file_length; }

};
}
/**@}*/
#endif // OSS_GET_OBJECT_GROUP_INDEX_RESULT_H

