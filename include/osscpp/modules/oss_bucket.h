/*
 * =============================================================================
 *
 *       Filename:  oss_bucket.h
 *
 *    Description:  oss_bucket.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#ifndef _OSS_BUCKET_H
# error Never include <ossc/modules/oss_bucket.h> directly, use <ossc/client.h> instead.
#endif

#ifndef OSS_BUCKET_H
#define OSS_BUCKET_H

#define _OSS_OWNER_H
#include  "oss_owner.h"
#undef _OSS_OWNER_H

#include <string>

using namespace std;

namespace osscpp {

/**
 * @defgroup Bucket Bucket
 * @{
 */

/**
 * Bucket是OSS上的命名空间 \n
 * Bucket名在整个 OSS 中具有全局唯一性,且不能修改；
 * 存储在OSS上的每个Object必须都包含在某个Bucket中。
 * 一个应用，例如图片分享网站，可以对应一个或多个 Bucket。
 * 一个用户最多可创建 10 个Bucket, 但每个Bucket中存放的Object的数量和大小总和没有限制,
 * 用户不需要考虑数据的可扩展性。\n
 * Bucket 命名规范
 * - 只能包括小写字母，数字，下划线（_）和短横线（-）
 * - 必须以小写字母或者数字开头
 * - 长度必须在 3-255 字节之间
 */
class Bucket {

	private :
		string create_date_;  /**< Bucket的创建时间 */
		string name_;         /**< Bucket的名称 */
		Owner owner_; /**< Bucket的所有者 */

		//Bucket(const Bucket&);
		//void operator=(const Bucket&);

	public :
		/**
		 * Bucket 构造函数
		 */
		Bucket(void)
		{
			owner_ = Owner();
		}
		
		/**
		 * Bucket 带bucket_name参数的构造函数
		 */
		Bucket(const string &name)
		{
			name_ = name;
			owner_ = Owner();
		}
		
		/**
		 * 返回Bucket的创建时间
		 * @retval const string 
		 * @return Bucket的创建时间
		 */
		inline const string create_date() const 
		{ return create_date_; }

		/**
		 * 设置Bucket的创建时间
		 * @param create_date [in] Bucket的创建时间
		 * @retval void
		 */
		inline void set_create_date(const string &create_date) 
		{ create_date_ = create_date; }

		/**
		 * 返回Bucket的名称
		 * @retval const string 
		 * @return Bucket的名称
		 */
		inline const string name() const 
		{ return name_; }

		/**
		 * 设置Bucket的名称
		 * @param name [in] Bucket的名称
		 * @retval void
		 */
		inline void set_name(const string &name)
		{ name_ = name; }

		/**
		 * 返回Bucket的所有者
		 * @retval Owner *
		 * @return Bucket的所有者
		 */
		inline Owner owner() const 
		{ return owner_; }

		/**
		 * 设置Bucket的所有者
		 * @param owner [in] Bucket的所有者
		 * @retval void
		 */
		inline void set_owner(Owner &owner)
		{ owner_ = owner; }
};
}
/**@}*/

#endif
