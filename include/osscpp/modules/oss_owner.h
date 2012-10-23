/*
 * =============================================================================
 *
 *       Filename:  oss_owner.h
 *
 *    Description:  oss owner.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#ifndef _OSS_OWNER_H
# error Never include <ossc/modules/oss_owner.h> directly, use <ossc/client.h> instead.
#endif

#ifndef OSS_OWNER_H
#define OSS_OWNER_H

#include <string>

using namespace std;

namespace osscpp {

/**
 * @defgroup Owner Owner
 * @{
 */

/**
 * 表示OSS Bucket的所有者
 */
class Owner {

	private :
		string id_;                /**< 所有者的ID */
		string display_name_;      /**< 所有者的显示名称 */
	
		//Owner(const Owner&);
		//void operator=(const Owner&);

	public :
		/**
		 * Owner构造函数
		 */
		Owner(void)
		{}
		
		/**
		 * Owner带ID 和display name的构造函数
		 * @param id [in] 所有者的ID
		 * @param name [in] 所有者的显示名称
		 */
		Owner(const string &id,
				const string &name)
		{
			id_ = id;
			display_name_ = name;
		}
		
		/**
		 * 获得所有者的ID
		 * @return 所有者的ID
		 * @retval const string 
		 */
		inline const string id() const 
		{ return id_; }

		/**
		 * 获得所有者的显示名称
		 * @return 所有者的显示名称
		 * @retval const string 
		 */
		inline const string display_name() const 
		{ return display_name_; }

		/**
		 * 设置所有者的ID
		 * @param id [in] 所有者的ID
		 * @retval void
		 */
		inline void set_id(const string &id)
		{ id_ = id; }

		/**
		 * 设置所有者的显示名称
		 * @param name [in] 所有者的显示名称
		 * @retval void
		 */
		inline void set_display_name(const string &name)
		{ display_name_ = name; }
};
}
/**@}*/
#endif
