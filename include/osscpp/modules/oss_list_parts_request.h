/*
 * =============================================================================
 *
 *       Filename:  oss_list_parts_request.h
 *
 *    Description:  list parts request implementation.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#ifndef _OSS_LIST_PARTS_REQUEST_H
# error Never include <ossc/modules/oss_list_parts_request_h> directly
# error use <ossc/client.h> instead.
#endif

#ifndef OSS_LIST_PARTS_REQUEST_H
#define OSS_LIST_PARTS_REQUEST_H

#include <string>

using namespace std;

namespace osscpp {

/**
 * @defgroup ListPartsRequest ListPartsRequest
 * @{
 */

/**
 * 包含列出Part的请求参数
 */	
class ListPartsRequest {

	private : 
		string bucket_name_;         /**< Bucket名称 */
		string key_;                 /**< Object名称 */
		unsigned int max_parts_;    /**< 表示最大返回多少条记录*/
		unsigned int part_number_marker_;    /**< 表示从哪个Part号码开始获取列表 */
		string upload_id_;           /** 标识Multipart上传事件的Upload ID */

		ListPartsRequest(const ListPartsRequest&);
		void operator=(const ListPartsRequest&);

	public :
		/**
		 * ListPartsRequest构造函数
		 * @param bucket_name [in] Bucket名称
		 * @param key [in] Object名称
		 * @param upload_id [in] Upload ID
		 */
		ListPartsRequest(const string &bucket_name,
				const string &key,
				const string &upload_id)
		{
			bucket_name_ = bucket_name;
			key_ = key;
			upload_id_ = upload_id;
			max_parts_ = 0;
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
		 * 获得Object名称
		 * @return Object名称
		 * @retval const string
		 */
		inline const string key() const 
		{ return key_; }

		/**
		 * 获得max_parts
		 * @return max_parts
		 * @retval unsigned int
		 */
		inline unsigned int max_parts() const 
		{ return max_parts_; }

		/**
		 * 获得part_number_marker
		 * @return part_number_marker
		 * @retval unsigned int
		 */
		inline unsigned int part_number_marker() const 
		{ return part_number_marker_; }

		/**
		 * 获得Upload ID
		 * @return Upload ID
		 * @retval const string
		 */
		inline const string upload_id() const 
		{ return upload_id_; }

		/**
		 * 设置Bucket名称
		 * @param bucket_name [in] Bucket名称
		 * @retval void
		 */
		inline void set_bucket_name(const string &bucket_name)
		{ bucket_name_ = bucket_name; }

		/**
		 * 设置Object名称
		 * @param key [in] Object名称
		 * @retval void
		 */
		inline void set_key(const string &key)
		{ key_ = key; }

		/**
		 * 设置max_parts
		 * @param max_parts [in] max_parts
		 * @retval void
		 */
		inline void set_max_parts(unsigned int max_parts)
		{ max_parts_ = max_parts; }

		/**
		 * 设置part_number_marker
		 * @param part_number_marker [in] part_number_marker
		 * @retval void
		 */
		inline void set_part_number_marker(unsigned int part_number_marker)
		{ part_number_marker_ = part_number_marker; }

		/**
		 * 设置Upload ID
		 * @param upload_id [in] Upload ID
		 * @retval void
		 */
		inline void set_upload_id(const string &upload_id)
		{ upload_id_ = upload_id; }
};
}

/**@}*/
#endif // OSS_LIST_PARTS_REQUEST_H 
