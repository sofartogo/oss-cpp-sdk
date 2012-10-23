/*
 * =============================================================================
 *
 *       Filename:  oss_copy_object_request.h
 *
 *    Description:  oss copy object request.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#ifndef _OSS_COPY_OBJECT_REQUEST_H
# error Never include <ossc/modules/oss_copy_object_result.h> directly, use <ossc/client.h> instead.
#endif

#ifndef OSS_COPY_OBJECT_REQUEST_H
#define OSS_COPY_OBJECT_REQUEST_H

#define _OSS_OBJECT_METADATA_H
#include "oss_object_metadata.h"
#undef _OSS_OBJECT_METADATA_H

#include <string>
#include <vector>

using namespace std;

namespace osscpp {

/**
 * @defgroup CopyObjectRequest CopyObjectRequest
 * @{
 */

/**
 * 拷贝一个在OSS上已经存在的Object成另外一个Object的请求参数
 */
class CopyObjectRequest {

	private :
		string destination_bucket_name_;    /**< 目标Bucket的名称 */
		string destination_key_;            /**< 目标Object的名称 */
		vector<string> matching_etag_constraints_; /**< ETag限定值的列表 */
		string modified_since_constraints_; /**< 一个时间，如果源Object自从该时间以后被修改过，则执行拷贝操作； 否则抛出异常 */
		ObjectMetadata object_metadata_; /**< 目标Object的ObjectMetadata信息 */
		vector<string> no_matching_etag_constraints_; /**< 限定Object的ETag限定必须不匹配给定值的列表 */
		string source_bucket_name_; /**< 源Bucket的名称 */
		string source_key_;         /**< 源Object的名称 */
		string unmodified_since_constraints_;   /**< 一个时间，如果该时间等于或者晚于文件实际修改时间，则正常传输文件； 否则抛出异常 */
	
		CopyObjectRequest(const CopyObjectRequest&);
		void operator=(const CopyObjectRequest&);

	public :
		/**
		 * CopyObjectRequest 构造函数
		 * @param source_bucket_name [in] 源Bucket的名称
		 * @param source_key [in] 源Object的名称
		 * @param destination_bucket_name [in] 目标Bucket的名称
		 * @param destination_key [in] 目标Object的名称
		 */
		CopyObjectRequest(const string &source_bucket_name,
				const string &source_key,
				const string &destination_bucket_name,
				const string &destination_key)
		{
			source_bucket_name_ = source_bucket_name;
			source_key_ = source_key;
			destination_bucket_name_ = destination_bucket_name;
			destination_key_ = destination_key;
			object_metadata_ = ObjectMetadata();
		}
		
		/**
		 * 获得目标Bucket的名称
		 * @return 目标Bucket的名称
		 * @retval const string 
		 */
		inline const string destination_bucket_name() const 
		{ return destination_bucket_name_; }

		/**
		 * 获得目标Object的名称
		 * @return 目标Object的名称
		 * @retval const string 
		 */
		inline const string destination_key() const 
		{ return destination_key_; }

		/**
		 * 获得ETag限定值的列表
		 * @return ETag限定值的列表
		 * @retval const string *
		 */
		inline vector<string>  matching_etag_constraints() const
		{ return matching_etag_constraints_; }

		/**
		 * 获得modified_since_constraints时间
		 * @return modified_since_constraints时间
		 * @retval const string 
		 */
		inline const string modified_since_constraints() const 
		{ return modified_since_constraints_; }

		/**
		 * 获得目标Object的ObjectMetadata信息
		 * @return 目标Object的ObjectMetadata信息
		 * @retval 返回一个ObjectMetadata的结构指针
		 * @retval 非空 表示成功
		 * @retval NULL 表示失败
		 */
		inline ObjectMetadata object_metadata() const 
		{ return object_metadata_; }

		/**
		 * 获得限定Object的ETag限定必须不匹配给定值的列表
		 * @return 限定Object的ETag限定必须不匹配给定值的列表
		 * @retval const string *
		 */
		inline vector<string> no_matching_etag_constraints() const
		{ return no_matching_etag_constraints_; }

		/**
		 * 获得源Bucket的名称
		 * @return 源Bucket的名称
		 * @retval const string 
		 */
		inline const string source_bucket_name() const 
		{ return source_bucket_name_; }

		/**
		 * 获得源Object的名称
		 * @return 源Object的名称
		 * @retval const string 
		 */
		inline const string source_key() const 
		{ return source_key_; }

		/**
		 * 获得unmodified_since_constraints时间
		 * @return unmodified_since_constraints时间
		 * @retval const string 
		 */
		inline const string unmodified_since_constraints() const 
		{ return unmodified_since_constraints_; }


		/**
		 * 设置目标Bucket的名称
		 * @param destination_bucket_name [in] 目标Bucket的名称
		 * @retval void
		 */
		inline void set_destination_bucket_name(const string &destination_bucket_name)
		{ destination_bucket_name_ = destination_bucket_name; }

		/**
		 * 设置目标Object的名称
		 * @param destination_key [in] 目标Object的名称
		 * @retval void
		 */
		inline void set_destination_key(const string &destination_key) 
		{ destination_key_ = destination_key; }

		/**
		 * 设置ETag限定值的列表
		 * @param matching_etag_constraints [in] ETag限定值的列表
		 * @retval void
		 */
		inline void set_matching_etag_constraints(vector<string> &matching_etag_constraints)
		{ matching_etag_constraints_ = matching_etag_constraints; }

		/**
		 * 设置modified_since_constraints时间
		 * @param modified_since_constraints [in] modified_since_constraints时间
		 * @retval void
		 */
		inline void set_modified_since_constraints(const string &modified_since_constraints)
		{ modified_since_constraints_ = modified_since_constraints;}

		/**
		 * 设置目标Object的ObjectMetadata信息
		 * @param object_metadata [in] 目标Object的ObjectMetadata信息
		 * @retval void
		 */
		inline void set_new_object_metadata(ObjectMetadata &object_metadata)
		{ object_metadata_ = object_metadata; }

		/**
		 * 设置限定Object的ETag限定必须不匹配给定值的列表
		 * @param no_matching_etag_constraints [in] 限定Object的ETag限定必须不匹配给定值的列表
		 * @retval void
		 */
		inline void set_no_matching_etag_constraints(vector<string> &no_matching_etag_constraints)
		{ no_matching_etag_constraints_ = no_matching_etag_constraints; }

		/**
		 * 设置源Bucket的名称
		 * @param source_bucket_name [in] 源Bucket的名称
		 * @retval void
		 */
		inline void set_source_bucket_name(const string &source_bucket_name)
		{ source_bucket_name_ = source_bucket_name; }

		/**
		 * 设置源Object的名称
		 * @param source_key [in] 源Object的名称
		 * @retval void
		 */
		inline void set_source_key(const string &source_key)
		{ source_key_ = source_key; }

		/**
		 * 设置unmodified_since_constraints时间
		 * @param unmodified_since_constraints [in] unmodified_since_constraints时间
		 * @retval void
		 */
		inline void set_unmodified_since_constraints(const string &unmodified_since_constraints)
		{ unmodified_since_constraints_ = unmodified_since_constraints; }
};
}
/**@}*/
#endif // OSS_COPY_OBJECT_REQUEST_H 

