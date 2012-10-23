/*
 * =============================================================================
 *
 *       Filename:  oss_post_object_group_result.h
 *
 *    Description:  oss post_object_group_result
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#ifndef _OSS_POST_OBJECT_GROUP_RESULT_H
# error Never include <ossc/modules/oss_post_object_group_result.h> directly, use <ossc/client.h> instead.
#endif

#ifndef OSS_POST_OBJECT_GROUP_RESULT_H
#define OSS_POST_OBJECT_GROUP_RESULT_H

#include <string>

using namespace std;

namespace osscpp {

/**
 * @defgroup PostObjectGroupResult PostObjectGroupResult
 * @{
 */

/**
 * 创建对象组（Object Group）返回的结果
 */
class PostObjectGroupResult {
	
	private :
		string bucket_name_;      /**< Bucket名称 */
		string key_;              /**< Object名称*/
		string etag_;             /**< Object的etag值*/
		size_t size_;            /**< Object的大小*/

		//PostObjectGroupResult(const PostObjectGroupResult&);
		//void operator=(const PostObjectGroupResult&);

	public :
		/**
		 * PostObjectGroupResult构造函数
		 */
		PostObjectGroupResult()
		{
			size_ = 0;
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
		 * 获得Object的etag值
		 * @return Object的etag值
		 * @retval const string 
		 */
		inline const string  etag() const 
		{ return etag_; }

		/**
		 * 设置Object的etag值
		 * @param etag [in] Object的etag值
		 * @retval void
		 */
		inline void set_etag(const string &etag)
		{ etag_ = etag; }

		/**
		 * 获得Object的大小
		 * @return Object的大小
		 * @retval size_t
		 */
		inline size_t size() const 
		{ return size_; }

		/**
		 * 设置Object的大小
		 * @param size [in] Object的大小
		 * @retval void
		 */
		inline void set_size(size_t size)
		{ size_ = size; }

};
}


/**@}*/
#endif // OSS_POST_OBJECT_GROUP_RESULT_H

