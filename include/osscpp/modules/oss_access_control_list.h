/*
 * =============================================================================
 *
 *       Filename:  oss_access_control_list.h
 *
 *    Description:  oss_access_control_list.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

 /* 内部使用的头文件，用户开发应包含<ossc/client.h> */
#ifndef _OSS_ACCESS_CONTROL_LIST_H
# error Never include <ossc/modules/oss_access_control_list.h> directly, use <ossc/client.h> instead.
#endif

/* 头文件保护 */
#ifndef OSS_ACCESS_CONTROL_LIST_H
#define OSS_ACCESS_CONTROL_LIST_H

#define _OSS_OWNER_H
#include "oss_owner.h"
#undef _OSS_OWNER_H

#include <string>

using namespace std;

namespace osscpp {

/**
 * @defgroup AccessControlList AccessControlList
 * @{
 */

/**
 * 表示OSS的访问控制列表（Access Control List, ACL),
 * 包含了一组为指定被授权者(Grantee)分配特定权限(Permission)的集合
 */
class AccessControlList {

	private :
		Owner owner_;     /**< Bucket 所有者*/
		string grant_;            /**< 授权信息*/

		//AccessControlList(const AccessControlList&);
		//void operator=(const AccessControlList&);

	public :
		/**
		 * AccessControlList 构造函数
		 */
		AccessControlList(void)
		{
			owner_ = Owner();
		}
		
		/**
		 * 返回所有者 Owner
		 * @retval 非空 表示成功
		 * @retval NULL 表示失败
		 * @return 返回一个Owner对象
		 */
		inline Owner owner() const 
		{ return owner_; }

		/**
		 * 设置所有者Owner
		 * @param owner [in] 所有者Owner对象
		 * @retval void
		 */
		inline void set_owner(Owner &owner)
		{ owner_ = owner; }

		/**
		 * 返回该AccessControlList中包含的所有授权信息Grant
		 * @retval const string 
		 * @return AccessControlList中包含的所有授权信息Grant
		 */
		inline const string grant() const 
		{ return grant_; }

		/**
		 * 设置所有授权信息Grant
		 * @param grant [in] 所有授权信息内容
		 * @retval void
		 */
		inline void set_grant(const string &grant) 
		{ grant_ = grant; }
};
}

/** @} */

#endif
