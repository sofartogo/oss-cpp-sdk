/*
 * =============================================================================
 *
 *       Filename:  oss_multipart_upload.h
 *
 *    Description:  oss_multipart_upload.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_MULTIPART_UPLOAD_H
# error Never include <ossc/modules/oss_multipart_upload.h> directly, use <ossc/client.h> instead.
#endif

#ifndef OSS_MULTIPART_UPLOAD_H
#define OSS_MULTIPART_UPLOAD_H

#include <string>

using namespace std;

namespace osscpp {
/**
 * @defgroup MultipartUpload MultipartUpload
 * @{
 */

/**
 * multipart upload的信息
 */
class MultipartUpload {

	private :
		string initiated_;           /**< 初始化的时间 */
		string storage_class_;       /**< Object的类型 */
		string upload_id_;           /**< Upload ID */
		string key_;                 /**< Object名称 */

		//MultipartUpload(const MultipartUpload&);
		//void operator=(const MultipartUpload&);

	public :
		/**
		 * MultipartUpload构造函数
		 */
		MultipartUpload(void)
		{}
		
		/**
		 * 获得初始化的时间
		 * @return 初始化的时间
		 * @retval const string 
		 */
		inline const string initiated() const 
		{ return initiated_; }

		/**
		 * 设置初始化的时间
		 * @param initiated [in] 初始化的时间
		 * @retval void
		 */
		inline void set_initiated(const string &initiated)
		{ initiated_ = initiated; }

		/**
		 * 获得Object的类型
		 * @return Object的类型
		 * @retval const string 
		 */
		inline const string storage_class() const 
		{ return storage_class_; }

		/**
		 * 设置Object的类型
		 * @param storage_class [in] Object的类型
		 * @retval void
		 */
		inline void set_storage_class(const string &storage_class)
		{ storage_class_ = storage_class; }

		/**
		 * 获得Upload ID
		 * @return Upload ID
		 * @retval const string 
		 */
		inline const string upload_id() const 
		{ return upload_id_; }

		/**
		 * 设置Upload ID
		 * @param upload_id [in]
		 * @retval void
		 */
		inline void set_upload_id(const string &upload_id)
		{ upload_id_ = upload_id; }

		/**
		 * 获得Object名称
		 * @return Object名称
		 * @retval const string 
		 */
		inline const string key() const 
		{ return key_; }

		/**
		 * 设置Object名称
		 * @param key Object名称
		 * @retval void
		 */
		inline void set_key(const string &key)
		{ key_ = key; }
};
}
/**@}*/
#endif
