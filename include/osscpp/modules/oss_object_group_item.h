/*
 * =============================================================================
 *
 *       Filename:  oss_object_group_item.h
 *
 *    Description:  oss object_group_item
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#ifndef _OSS_OBJECT_GROUP_ITEM_H
# error Never include <ossc/modules/oss_object_group_item.h> directly, use <ossc/client.h> instead.
#endif

#ifndef OSS_OBJECT_GROUP_ITEM_H 
#define OSS_OBJECT_GROUP_ITEM_H

#include <string>

using namespace std;

namespace osscpp {

/**
 * @defgroup ObjectGroupItem ObjectGroupItem
 * @{
 */

/**
 * post object group 需要提供的 Object 信息
 */
class ObjectGroupItem {

	private :
		string etag_;            /**< Object的etag */
		string part_name_;       /**< Object的name */
		int part_number_;       /**< Object的number */

		//ObjectGroupItem(const ObjectGroupItem&);
		//void operator=(const ObjectGroupItem&);

	public :
		/**
		 * ObjectGroupItem构造函数
		 */
		ObjectGroupItem()
		{
			part_number_ = 0;
		}
		
		/**
		 * ObjectGroupItem带参数的构造函数
		 */
		ObjectGroupItem(const string &etag, const string &part_name, int part_number)
		{
			etag_ = etag;
			part_name_ = part_name;
			part_number_ = part_number;
		}

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
		 * 获得Object的name
		 * @return Object的name
		 * @retval const string 
		 */
		inline const string part_name() const 
		{ return part_name_; }

		/**
		 * 设置Object的name
		 * @param part_name [in] Object的name
		 * @retval void
		 */
		inline void set_part_name(const string &part_name)
		{ part_name_ = part_name; }

		/**
		 * 获得Object的number
		 * @return Object的number
		 * @retval int
		 */
		inline int part_number() const
		{ return part_number_; }

		/**
		 * 设置Object的number
		 * @param part_number [in] Object的number
		 * @retval void
		 */
		inline void set_part_number(int part_number)
		{ part_number_ = part_number; }
};
}
/**@}*/
#endif // OSS_OBJECT_GROUP_ITEM_H 

