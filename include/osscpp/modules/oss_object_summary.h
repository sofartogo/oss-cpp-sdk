/*
 * =============================================================================
 *
 *       Filename:  oss_object_summary.h
 *
 *    Description:  oss_object_summary.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_OBJECT_SUMMARY_H
# error Never include <ossc/modules/oss_object_summary.h> directly, use <ossc/client.h> instead.
#endif

#ifndef OSS_OBJECT_SUMMARY_H
#define OSS_OBJECT_SUMMARY_H

#define _OSS_OWNER_H
#include  "oss_owner.h"
#undef _OSS_OWNER_H

#include <string.h>

using namespace std;

namespace osscpp {

/**
 * @defgroup ObjectSummary ObjectSummary
 * @{
 */

/**
 * OSSObject摘要信息
 */
class ObjectSummary {

	private :
		string type_;               /**< Object的类别 */
		string etag_;               /**< Object的etag */
		string key_;                /**< Object的名称 */
		string last_modified_;      /**< Object上次修改的时间 */
		Owner owner_;       /**< Object的所有者 */
		long size_;                /**< Object的大小 */
		string storage_class_;      /**< Object的存储类别 */

		//ObjectSummary(const ObjectSummary&);
		//void operator=(const ObjectSummary&);

	public :
		/**
		 * ObjectSummary构造函数
		 */
		ObjectSummary(void)
		{
			owner_ = Owner();
			size_ = 0;
		}
		
		/**
		 * 获得Object的类别
		 * @return Object的类别
		 * @retval const string 
		 */
		inline const string type() const 
		{ return type_; }

		/**
		 * 设置Object的类别
		 * @param type [in] Object的类别
		 * @retval void
		 */
		inline void set_type(const string &type)
		{ type_ = type; }

		/**
		 * 获得Object的etag
		 * @return Object的etag
		 * @retval const string 
		 */
		inline const string etag() const 
		{ return etag_; }

		/**
		 * 设置Object的etag
		 * @param etag [in] Object的etag
		 * @retval void
		 */
		inline void set_etag(const string &etag)
		{ etag_ = etag; }

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
		 * 获得Object上次修改的时间
		 * @return Object上次修改的时间
		 * @retval const string 
		 */
		inline const string  last_modified() const 
		{ return last_modified_; }

		/**
		 * 设置Object上次修改的时间
		 * @param last_modified [in] bject上次修改的时间
		 * @retval void
		 */
		inline void set_last_modified(const string &last_modified)
		{ last_modified_ = last_modified; }

		/**
		 * 获得Object的所有者
		 * @return 返回一个Owner对象
		 * @retval 非空 表示成功
		 * @retval NULL 表示失败
		 */
		inline Owner owner() const 
		{ return owner_; }

		/**
		 * 设置Object的所有者
		 * @param owner [in] Object的所有者
		 * @retval void
		 */
		inline void set_owner(Owner &owner)
		{ owner_ = owner; }
		
		/**
		 * 获得Object的大小
		 * @return Object的大小
		 * @retval long
		 */
		inline long size() const 
		{ return size_; }

		/**
		 * 设置Object的大小
		 * @param size [in] Object的大小
		 * @retval void
		 */
		inline void set_size(long size)
		{ size_ = size; }

		/**
		 * 获得Object的存储类别
		 * @return Object的存储类别
		 * @retval const string 
		 */
		inline const string storage_class() const 
		{ return storage_class_; }

		/**
		 * 设置Object的存储类别
		 * @param storage_class [in] bject的存储类别
		 * @retval void
		 */
		inline void set_storage_class(const string &storage_class)
		{ storage_class_ = storage_class; }
};
}
/**@}*/
#endif
