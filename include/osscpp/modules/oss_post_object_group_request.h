/*
 * =============================================================================
 *
 *       Filename:  oss_post_object_group_request.h
 *
 *    Description:  oss post object group request.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#ifndef _OSS_POST_OBJECT_GROUP_REQUEST_H
# error Never include <ossc/modules/oss_post_object_group_request.h> directly,
# error use <ossc/client.h> instead.
#endif

#ifndef OSS_POST_OBJECT_GROUP_REQUEST_H 
#define OSS_POST_OBJECT_GROUP_REQUEST_H 

#define _OSS_OBJECT_GROUP_ITEM_H
#include "oss_object_group_item.h"
#undef _OSS_OBJECT_GROUP_ITEM_H 

#include <string>
#include <vector>
using namespace std;

namespace osscpp {

/**
 * @defgroup PostObjectGroupRequest PostObjectGroupRequest
 * @{
 */

/**
 * Object Group 是由一个或多个 Object 组成的松散的集合,它的数据长度是其
 * 所属 Object 的数据长度的总和。用户可以指定在同一个 Bucket 下的一个或多个Object,
 * 将其在 OSS 服务器上创建出一个 Object Group。一旦 Object Group 创建成功,
 * 用户可以像操作普通 Object 一样去操作 Object Group,这些操作包括 get,range query,
 * delete,list,但 Object Group 的数据和所包含 Object 的数据不是紧密联系的。
 * 通过 Object Group,用户可以实现 Object 的软连接,超大文件的多线程操作,以及断点续传等功能。
 *
 */

/**
 * Post Object Group 操作将根据用户提供的 Object 信息,在 OSS 服务器端创
 * 建出一个新的 Object Group。用户需要将创建该 Object Group 所需的 Object Name,
 * E-tag 以及标识该 Object 在整个 Group 中相对位置的 Part ID 按照规定的 XML 格式发给 OSS。
 *
 */
class PostObjectGroupRequest {

	private :
		string bucket_name_;      /**< Bucket 名称*/
		string key_;              /**< Oject 名称*/
		vector<ObjectGroupItem> items_;  /**< 一个或多个 Object 组成的松散的集合*/

		PostObjectGroupRequest(const PostObjectGroupRequest&);
		void operator=(const PostObjectGroupRequest&);
		
	public :
		/**
		 * PostObjectGroupRequest 构造函数
		 */
		PostObjectGroupRequest(const string &bucket_name, 
				const string &key,
				vector<ObjectGroupItem> &items)
		{
			bucket_name_ = bucket_name;
			key_ = key; 
			items_ = items;
		}

		/**
		 * 获得 Bucket 名称
		 * @return Bucket 名称
		 * @retval const string 
		 */
		inline const string bucket_name() const 
		{ return bucket_name_; }

		/**
		 * 设置 Bucket 名称
		 * @param bucket_name [in] Bucket 名称
		 * @retval void
		 */
		inline void set_bucket_name(const string &bucket_name)
		{ bucket_name_ = bucket_name; }

		/**
		 * 获得 Object 名称
		 * @return Object 名称
		 * @retval const string 
		 */
		inline const string key() const 
		{ return key_; }

		/**
		 * 设置Object 名称
		 * @param key [in] Object 名称
		 * @retval void
		 */
		inline void set_key(const string &key)
		{ key_ = key; }

		/**
		 * 获得一个或多个 Object 组成的松散的集合
		 * @return 返回一个ObjectGroupItem结构指针
		 * @retval 非空 表示成功
		 * @retval NULL 表示失败
		 */
		inline vector<ObjectGroupItem> items() const 
		{ return items_; }

		/**
		 * 设置一个或多个 Object 组成的松散的集合
		 * @param items  [in] 一个或多个 Object 组成的松散的集合
		 */
		inline void set_items(vector<ObjectGroupItem> &items)
		{ items_ = items; }
	
};
}
/**@}*/
#endif // OSS_POST_OBJECT_GROUP_REQUEST_H

