/*
 * =============================================================================
 *
 *       Filename:  oss_object_metadata.h
 *
 *    Description:  object metadata structure and implementation.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#ifndef _OSS_OBJECT_METADATA_H
# error Never include <ossc/modules/oss_object_metadata.h> directly, use <ossc/client.h> instead.
#endif

#ifndef OSS_OBJECT_METADATA_H
#define OSS_OBJECT_METADATA_H

#include <string>
#include <map>

//#define _OSS_CONSTANTS_H
//#include <ossc/oss_constants.h>
//#undef _OSS_CONSTANTS_H

using namespace std;

namespace osscpp {
/**
 * @defgroup ObjectMetadata ObjectMetadata
 * @{
 */

/**
 * OSS中Object的元数据.包含了用户自定义的元数据,也包含了OSS发送的标准HTTP头(如Content-Length, ETag等）
 */
class ObjectMetadata {
	
	private :
		map<string, string> metadata_;      /**< Http 标准头部 */
		map<string, string> user_metadata_;      /**< Http 用户自定义头部 */

		//ObjectMetadata(const ObjectMetadata&);
		//void operator=(const ObjectMetadata&);

	public :
		/**
		 * ObjectMetadata构造函数
		 */
		ObjectMetadata()
		{}

		/**
		 * 增加一个用户自定义头部键值对
		 * @param key [in] 用户自定义头部键
		 * @param value [in] 用户自定义头部值
		 * @retval void
		 */
		inline void add_user_metadata(const string &key,
				const string &value)
		{
			user_metadata_.insert(pair<string, string>(key, value));
		}

		/**
		 * 增加一个标准头部键值对
		 * @param key [in] 标准头部的键
		 * @param value [in] 标准头部的值
		 * @retval void
		 */
		inline void add_default_metadata(const string &key,
				const string &value)
		{
			metadata_.insert(pair<string, string>(key, value));
		}

		/**
		 * 获取Cache-Control请求头，表示用户指定的HTTP请求/回复链的缓存行为
		 * @return Cache-Control请求头
		 * @retval const string 
		 */
		inline const string cache_control() 
		{ return metadata_["Cache-Control"]; }

		/**
		 * 获取Content-Disposition请求头，表示MIME用户代理如何显示附加的文件
		 * @return Content-Disposition请求头
		 * @retval const string 
		 */
		inline const string content_disposition() 
		{ return metadata_["Content-Disposition"]; }

		/**
		 * 获取Content-Encoding请求头，表示Object内容的编码方式
		 * @return Content-Encoding请求头
		 * @retval const string 
		 */
		inline const string content_encoding() 
		{ return metadata_["Content-Encoding"]; }

		/**
		 * 获取Content-Length请求头，表示Object内容的大小
		 * @return Content-Length请求头
		 * @retval long
		 */
		inline const string content_length() 
		{ return metadata_["Content-Length"]; }

		/**
		 * 获取Content-Type请求头，表示Object内容的类型，为标准的MIME类型
		 * @return Content-Type请求头
		 * @retval const string 
		 */
		inline const string content_type() 
		{ return metadata_["Content-Type"]; }

		/**
		 * 获取一个值表示与Object相关的hex编码的128位MD5摘要
		 * @return Object的etag值
		 * @retval const string 
		 */

		inline const string etag() 
		{ return metadata_["Content-Md5"]; }

		/**
		 * 获取Expires请求头
		 * @return Expires请求头
		 * @retval const string 
		 */
		inline const string expiration_time() 
		{ return metadata_["Expires"]; }

		/**
		 * 获取Last-Modified请求头的值，表示Object最后一次修改的时间
		 * @return Last-Modified请求头
		 * @retval const string 
		 */
		inline const string last_modified() 
		{ return metadata_["Last-Modified"]; }

		/**
		 * 返回内部保存的请求头的元数据（内部使用）
		 * @return 返回一个map结构指针
		 * @retval 非空 表示成功
		 * @retval NULL 表示失败
		 */
		map<string, string>  raw_metadata() const 
		{ return metadata_; }

		/**
		 * 获取用户自定义的元数据
		 * @return 返回一个oss_map_t结构指针
		 * @retval 非空 表示成功
		 * @retval NULL 表示失败
		 */
		map<string, string>  user_metadata() const 
		{ return user_metadata_; }

		/**
		 * 设置Cache-Control请求头，表示用户指定的HTTP请求/回复链的缓存行为
		 * @param cache_control [in] Cache-Control请求头
		 * @retval void
		 */
		inline void set_cache_control(const string &cache_control)
		{ metadata_["Cache-Control"] = cache_control; }

		/**
		 * 设置Content-Disposition请求头，表示MIME用户代理如何显示附加的文件
		 * @param disposition [in] Content-Disposition请求头
		 * @retval void
		 */
		inline void set_content_disposition(const string &disposition)
		{ metadata_["Content-Disposition"] = disposition; }

		/**
		 * 设置Content-Encoding请求头，表示Object内容的编码方式
		 * @param encoding [in]Content-Encoding请求头
		 * @retval void
		 */
		inline void set_content_encoding(const string &encoding)
		{ metadata_["Content-Encoding"] = encoding; }

		/**
		 * 设置Content-Length请求头，表示Object内容的大小
		 * @param content_length [in] Content-Length请求头
		 * @retval void
		 */
		inline void set_content_length(const string &content_length)
		{ metadata_["Content-Length"] = content_length; }

		/**
		 * 设置Content-Type请求头，表示Object内容的类型，为标准的MIME类型
		 * @param content_type [in] Content-Type请求头
		 * @retval void
		 */
		inline void set_content_type(const string &content_type)
		{ metadata_["Content-Type"] = content_type; }

		/**
		 * 设置Expires请求头
		 * @param expiration_time [in]Expires请求头
		 * @retval void
		 */
		inline void set_expiration_time(const string &expiration_time)
		{ metadata_["Expires"] = expiration_time; }

		/**
		 * 设置Object的etag
		 * @param etag [in] Object的etag
		 * @retval void
		 */
		inline void set_etag(const string &etag)
		{ metadata_["Content-Md5"] = etag; }

		/**
		 * 设置请求头（内部使用）
		 * @param key [in] 请求头的键
		 * @param value [in] 请求头的值
		 * @retval void
		 */
		inline void set_header(const string &key,
				const string &value)
		{ metadata_.insert(pair<string, string>(key, value)); }

		/**
		 * 设置Last-Modified请求头的值，表示Object最后一次修改的时间（内部使用）
		 * @param last_modified [in] Last-Modified请求头
		 * @retval void
		 */
		inline void set_last_modified(const string &last_modified)
		{ metadata_["Last-Modified"] = last_modified; }

		/**
		 * 设置用户自定义的元数据，表示以x-oss-meta-为前缀的请求头
		 * @param user_metadata 标识一个oss_map_t结构指针
		 * @retval void
		 */
		inline void set_user_metadata(map<string, string> &user_metadata)
		{ user_metadata_ = user_metadata; }
};
}
/**@}*/
#endif // OSS_OBJECT_METADATA_H

