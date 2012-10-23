/*
 * =============================================================================
 *
 *       Filename:  oss_generate_presigned_url_request.h
 *
 *    Description:  oss_generate_presigned_url_request.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_GENERATE_PRESIGNED_URL_REQUEST_H
# error Never include <ossc/modules/oss_generate_presigned_url_request.h> directly, use <ossc/client.h> instead.
#endif

#ifndef OSS_GENERATE_PRESIGNED_URL_REQUEST_H
#define OSS_GENERATE_PRESIGNED_URL_REQUEST_H

#define _OSS_RESPONSE_HEADER_OVERRIDES_H
#include "oss_response_header_overrides.h"
#undef _OSS_RESPONSE_HEADER_OVERRIDES_H

#include <string.h>
#include <map>

using namespace std;

namespace osscpp {

/**
 * @defgroup GeneratePresignedUrlRequest GeneratePresignedUrlRequest
 * @{
 */

/**
 * 生成带有签名信息的URL的请求
 */
class GeneratePresignedUrlRequest {

	private :
		string bucket_name_;      /**< Bucket名称 */
		string expiration_;       /**< 过期时间 */
		string key_;              /**< Object名称 */
		string method_;           /**< HTTP方法 */
		ResponseHeaderOverrides response_headers_;   /**< 要重载的返回请求头 */
		map<string, string> user_metadata_;      /**< 用户自定义的元数据 */

		GeneratePresignedUrlRequest(const GeneratePresignedUrlRequest&);
		void operator=(const GeneratePresignedUrlRequest&);

	public :
		/**
		 * GeneratePresignedUrlRequest 构造函数
		 * @param bucket_name [in] Bucket名称
		 * @param key [in] Object名称
		 */
		GeneratePresignedUrlRequest(const string &bucket_name,
				const string &key)
		{
			bucket_name_ = bucket_name;
			key_ = key;
			response_headers_ = ResponseHeaderOverrides();
		}
		
		/**
		 * GeneratePresignedUrlRequest带http方法的构造函数
		 * @param bucket_name [in] Bucket名称
		 * @param key [in] Object名称
		 * @param method [in] http方法
		 */
		GeneratePresignedUrlRequest(const string &bucket_name,
				const string &key,
				const string &method)
		{
			bucket_name_ = bucket_name;
			key_ = key;
			method_ = method;
			response_headers_ = ResponseHeaderOverrides();
		}
		
		/**
		 * 增加用户自定义的元数据
		 * @param key [in] 元数据的key
		 * @param value [in] 元数据的value
		 * @retval void
		 */
		inline void add_user_metadata(const string &key, const string &value)
		{ user_metadata_.insert(pair<string, string>(key, value)); }
	
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
		 * 获得过期时间
		 * @return 过期时间
		 * @retval const string 
		 */
		inline const string expiration() const 
		{ return expiration_; }
	
		/**
		 * 设置过期时间
		 * @param expiration [in] 过期时间
		 * @retval void
		 */
		inline void set_expiration(const string &expiration)
		{ expiration_ = expiration; }
	
		/**
		 * 获得Object名称
		 * @return Object名称
		 * @retval const string 
		 */
		inline const string key() const 
		{ return key_; }
	
		/**
		 * 设置Object名称
		 * @param key [in] Object名称
		 * @retval void
		 */
		inline void set_key(const string &key)
		{ key_ = key; }
	
		/**
		 * 获得HTTP方法
		 * @return HTTP方法
		 * @retval const string 
		 */
		inline const string method() const 
		{ return method_; }
	
		/**
		 * 设置HTTP方法
		 * @param method [in] HTTP方法
		 * @retval void
		 */
		inline void set_method(const string &method) 
		{ method_ = method; }
	
		/**
		 * 获得要重载的返回请求头
		 * @return 要重载的返回请求头
		 * @retval 非空 表示成功
		 * @retval NULL 表示失败
		 */
		inline ResponseHeaderOverrides response_headers() const 
		{ return response_headers_; }
	
		/**
		 * 设置要重载的返回请求头
		 * @param response_headers [in] 要重载的返回请求头
		 * @retval void
		 */
		inline void set_response_headers(ResponseHeaderOverrides &response_headers)
		{ response_headers_ = response_headers; }
	
		/**
		 * 获得用户自定义的元数据
		 * @return 用户自定义的元数据
		 * @retval 非空 表示成功
		 * @retval NULL 表示失败
		 */
		inline map<string, string> get_user_metadata() const
		{ return user_metadata_; }
	
		/**
		 * 设置用户自定义的元数据
		 * @param user_metadata [in] 用户自定义的元数据
		 * @retval void
		 */
		inline void set_user_metadata(map<string, string> &user_metadata)
		{ user_metadata_ = user_metadata; }
	

};
}

/**@}*/
#endif
