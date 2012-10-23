/*
 * =============================================================================
 *
 *       Filename:  oss_response_header_overrides.h
 *
 *    Description:  oss_response_header_overrides.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_RESPONSE_HEADER_OVERRIDES_H
# error Never include <modules/oss_response_header_overrides.h> directly, use <ossc/client.h> instead.
#endif

#ifndef OSS_RESPONSE_HEADER_OVERRIDES_H
#define OSS_RESPONSE_HEADER_OVERRIDES_H

#include <string>

using namespace std;

namespace osscpp {

/**
 * @defgroup ResponseHeaderOverrides ResponseHeaderOverrides
 * @{
 */

/**
 * ResponseHeaderOverrides 包含了在发送OSS GET请求时可以重载的返回请求头
 */
class ResponseHeaderOverrides {

	private :
		string cache_control_;  /**< 重载的cacheControl返回请求头*/
		string content_disposition_;  /**< 重载的contentDisposition返回请求头*/
		string content_encoding_;  /**< 重载的contentEncoding返回请求头*/
		string content_language_; /**< 重载的content language返回请求头*/
		string content_type_;  /**< 重载的content type返回请求头*/
		string expires_; /**< 重载的expires返回请求头*/

		//ResponseHeaderOverrides(const ResponseHeaderOverrides&);
		//void operator=(const ResponseHeaderOverrides&);

	public :
		/**
		 * ResponseHeaderOverrides 构造函数
		 */
		ResponseHeaderOverrides(void)
		{}

		/**
		 * 获得重载的cacheControl返回请求头
		 * @return 重载的cacheControl返回请求头
		 * @retval const string 
		 */
		inline const string cache_control() const 
		{ return cache_control_; }

		/**
		 * 设置重载的cacheControl返回请求头
		 * @param cache_control [in] 重载的cacheControl返回请求头
		 * @retval void
		 */
		inline void set_cache_control(const string &cache_control) 
		{ cache_control_ = cache_control; }

		/**
		 * 获得重载的contentDisposition返回请求头
		 * @return 返回重载的contentDisposition返回请求头
		 * @retval const string 
		 */
		inline const string content_disposition() const 
		{ return content_disposition_; }

		/**
		 * 设置重载的contentDisposition返回请求头
		 * @param content_disposition [in] 重载的contentDisposition返回请求头
		 * @retval void
		 */
		inline void set_content_disposition(const string &content_disposition)
		{ content_disposition_ = content_disposition; }

		/**
		 * 获得重载的contentEncoding返回请求头
		 * @return 重载的contentEncoding返回请求头
		 * @retval const string 
		 */
		inline const string get_content_encoding() const 
		{ return content_encoding_; }

		/**
		 * 设置重载的contentEncoding返回请求头
		 * @param content_encoding [in] 重载的contentEncoding返回请求头
		 * @retval void
		 */
		inline void set_content_encoding(const string &content_encoding) 
		{ content_encoding_ = content_encoding; }

		/**
		 * 获得重载的content language返回请求头
		 * @return 返回重载的content language返回请求头
		 * @retval const string 
		 */
		inline const string content_language() const 
		{ return content_language_; }

		/**
		 * 设置重载的content language返回请求头
		 * @param content_language [in] 重载的content language返回请求头
		 * @retval void
		 */
		inline void set_content_language(const string &content_language)
		{ content_language_ = content_language; }

		/**
		 * 获得重载的content type返回请求头
		 * @return 重载的content type返回请求头
		 * @retval const string 
		 */
		inline const string content_type() const 
		{ return content_type_; }

		/**
		 * 设置重载的content type返回请求头
		 * @param content_type [in] 重载的content type返回请求头
		 * @retval void
		 */
		inline void set_content_type(const string &content_type)
		{ content_type_ = content_type; }

		/**
		 * 获得重载的expires返回请求头
		 * @return 重载的expires返回请求头
		 * retval const string 
		 */
		inline const string expires() const 
		{ return expires_; }

		/**
		 * 设置重载的expires返回请求头
		 * @param expires  [in] 设置重载的expires返回请求头
		 * @retval void
		 */
		inline void set_expires(const string &expires) 
		{ expires_ = expires; }
};
}

/**@}*/
#endif
