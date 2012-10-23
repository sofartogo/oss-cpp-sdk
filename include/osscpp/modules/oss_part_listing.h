/*
 * =============================================================================
 *
 *       Filename:  oss_part_listing.h
 *
 *    Description:  oss_part_listing.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_PART_LISTING_H
# error Never include <ossc/modules/oss_part_listing.h> directly, use <ossc/client.h> instead.
#endif

#ifndef OSS_PART_LISTING_H
#define OSS_PART_LISTING_H

#define _OSS_OWNER_H
#include  "oss_owner.h"
#undef _OSS_OWNER_H

#define _OSS_PART_SUMMARY_H
#include "oss_part_summary.h"
#undef _OSS_PART_SUMMARY_H

#include <string>
#include <vector>
using namespace std;

namespace osscpp {

/**
 * @defgroup PartListing PartListing
 * @{
 */

/**
 * 包含Multipart上传Part的表示
 */
class PartListing {

	private :
		string bucket_name_;                  /**< Bucket名称 */
		Owner initiator_;             /**< Object的的初始化者 */
		bool is_truncated_;                  /**< 标识结果是否被截取 */
		string key_;                          /**< Object的名称 */
		int max_parts_;                      /**< 请求中指定返回Part的最大个数 */
		int next_part_number_marker_;        /**< 如果返回结果被截取，那么下一个Part的号码是多少 */
		Owner owner_;                 /**< Object的所有者 */
		int part_number_marker_;             /**< 标识从哪里显示 */
		vector<PartSummary> parts_;         /**< PartSummary的列表 */
		string storage_class_;                /**< Object的存储类别 */
		string upload_id_;                    /**< 标识Multipart上传事件的Upload ID */

		//PartListing(const PartListing&);
		//void operator=(const PartListing&);

	public :
		/**
		 * PartListing构造函数
		 */
		PartListing(void)
		{
			initiator_ = Owner();
			owner_ = Owner();
			is_truncated_ = false;
			max_parts_ = 0;
			next_part_number_marker_ = 0;
			part_number_marker_ = 0;
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
		 * 获得Object的名称
		 * @return Object的名称
		 * @retval const string 
		 */
		inline const string get_key() const 
		{ return key_; }

		/**
		 * 设置Object的名称
		 * @param key [in] Object的名称
		 * @retval void
		 */
		inline void set_key(const string &key)
		{ key_ = key; }

		/**
		 * 获得Upload ID
		 * @return Upload ID
		 * @retval const string 
		 */
		inline const string upload_id() const 
		{ return upload_id_; }

		/**
		 * 设置Upload ID
		 * @param upload_id [in] Upload ID
		 * @retval void
		 */
		inline void set_upload_id(const string &upload_id)
		{ upload_id_ = upload_id; }

		/**
		 * 获得Object的存储类别
		 * @return Object的存储类别
		 * @retval const string 
		 */
		inline const string storage_class() const 
		{ return storage_class_; } 

		/**
		 * 设置Object的存储类别
		 * @param storage_class [in] Object的存储类别
		 * @retval void
		 */
		inline void set_storage_class(const string &storage_class)
		{ storage_class_ = storage_class; }

		/**
		 * 获得Object的的初始化者
		 * @return Object的的初始化者
		 * @retval 非空 表示成功
		 * @retval NULL 表示失败
		 */
		inline Owner initiator() const 
		{ return initiator_; }

		/**
		 * 设置Object的的初始化者
		 * @param initiator [in] Object的的初始化者
		 * @retval void
		 */
		inline void set_initiator(Owner &initiator)
		{ initiator_ = initiator; }

		/**
		 * 获得请求中指定返回Part的最大个数
		 * @return 请求中指定返回Part的最大个数
		 * @retval int
		 */
		inline int max_parts() const 
		{ return max_parts_; }

		/**
		 * 设置请求中指定返回Part的最大个数
		 * @param max_parts [in] 请求中指定返回Part的最大个数
		 * @retval void
		 */
		inline void set_max_parts(int max_parts) 
		{ max_parts_ = max_parts; }

		/**
		 * 获得is_truncated
		 * @return is_truncated
		 * @retval bool
		 */
		inline bool is_truncated() const 
		{ return is_truncated_; }

		/**
		 * 设置is_truncated
		 * @param is_truncated [in] is_truncated
		 * @retval void
		 */
		inline void set_is_truncated(bool is_truncated)
		{ is_truncated_ = is_truncated; }

		/**
		 * 获得PartSummary的列表
		 * @return 返回一个PartSummary结构指针
		 * @retval 非空 表示成功
		 * @retval NULL 表示失败
		 */
		inline vector<PartSummary> parts() const
		{ return parts_; }

		/**
		 * 设置PartSummary的列表
		 * @param parts [in] PartSummary的列表
		 * @retval void
		 */
		inline void set_parts(vector<PartSummary> &parts)
		{ parts_ =parts; }

		/**
		 * 获得next_part_number_marker
		 * @return next_part_number_marker
		 * @retval int
		 */
		inline int next_part_number_marker() const 
		{ return next_part_number_marker_; }

		/**
		 * 设置next_part_number_marker
		 * @param next_part_number_marker [in] next_part_number_marker
		 * @retval void
		 */
		inline void set_next_part_number_marker(int next_part_number_marker)
		{ next_part_number_marker_ = next_part_number_marker; }

		/**
		 * 获得Object的所有者
		 * @return Object的的所有者
		 * @retval Owner
		 */
		inline Owner owner() const 
		{ return owner_; }

		/**
		 * 设置Object的所有者
		 * @param owner [in] bject的所有者
		 * @retval void
		 */
		inline void set_owner(Owner &owner)
		{ owner_ = owner; }
		
		/**
		 * 获得part_number_marker
		 * @return part_number_marker
		 * @retval int
		 */
		inline int part_number_marker() const 
		{ return part_number_marker_; }

		/**
		 * 设置part_number_marker
		 * @param part_number_marker [in] part_number_marker
		 * @retval void
		 */
		inline void set_part_number_marker(int part_number_marker)
		{ part_number_marker_ = part_number_marker; }



};
}
/**@}*/
#endif
