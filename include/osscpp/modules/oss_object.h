/*
 * =============================================================================
 *
 *       Filename:  oss_object.h
 *
 *    Description:  oss object
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#ifndef _OSS_OBJECT_H
# error Never include <ossc/modules/oss_object.h> directly, use <ossc/client.h> instead.
#endif
#ifndef OSS_OBJECT_H
#define OSS_OBJECT_H

#define _OSS_OBJECT_METADATA_H
#include "oss_object_metadata.h"
#undef _OSS_OBJECT_METADATA_H

#include <string.h>

using namespace std;

namespace osscpp {

/**
 * @defgroup Object Object
 * @{
 */

/**
 * 表示OSS中的Object\n
 *
 * 在 OSS 中，用户的每个文件都是一个 Object，每个文件需小于 5G。 Object包含key、data和user meta。其中，key是Object 的名字； data是Object 的数据；user meta是用户对该object的描述。
 *
 * Object 命名规范:
 *
 * - 使用UTF-8编码
 * - 规则长度必须在 1-1023字节之间
 */
class Object {

	private :
		string bucket_name_;                       /**< Object的所在Bucket的名称 */
		string key_;                               /**< Object的名称 */
		string object_content_;                    /**< Object的内容 */
		ObjectMetadata object_metadata_;  /**< Object的元数据 */

		Object(const Object&);
		void operator=(const Object&);

	public :
		/**
		 * Object构造函数
		 */
		Object()
		{
			object_metadata_ = ObjectMetadata();
		}
		
		/**
		 * 获得Object的所在Bucket的名称
		 * @return Object的所在Bucket的名称
		 * @retval const string 
		 */
		inline const string bucket_name() const 
		{ return bucket_name_; }

		/**
		 * 获得Object的名称
		 * @return Object的名称
		 * @retval const string 
		 */
		inline const string  key() const 
		{ return key_; }

		/**
		 * 获得Object的内容
		 * @return Object的内容
		 * @retval const string 
		 */
		inline const string  object_content() const
		{
			return object_content_;
		}

		/**
		 * 获得Object的元数据
		 * @return 返回一个ObjectMetadata结构指针
		 * @retval 非空 表示成功
		 * @retval NULL 表示失败
		 */
		inline ObjectMetadata object_metadata() const 
		{ return object_metadata_; }

		/**
		 * 设置Object的所在Bucket的名称
		 * @param bucket_name [in] Object的所在Bucket的名称
		 * @retval void
		 */
		inline void set_bucket_name(const string &bucket_name)
		{ bucket_name_ = bucket_name; }

		/**
		 * 设置Object的名称
		 * @param key [in] Object的名称
		 * @retval void
		 */
		inline void set_key(const string &key)
		{ key_ = key; }

		/**
		 * 设置Object的内容
		 * @param object_content [in] Object的内容
		 * @retval void
		 */
		inline void set_object_content(const string &object_content)
		{
			object_content_ = object_content;
		}

		/**
		 * 设置Object的元数据
		 * @param object_metadata [in] Object的元数据
		 * @retval void
		 */
		inline void set_object_metadata(ObjectMetadata &object_metadata)
		{ object_metadata_ = object_metadata; }
};
}
/**@}*/
#endif // OSS_OBJECT_H

