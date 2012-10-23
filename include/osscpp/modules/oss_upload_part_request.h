/*
 * =============================================================================
 *
 *       Filename:  oss_upload_part_request.h
 *
 *    Description:  oss_upload_part_request.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_UPLOAD_PART_REQUEST_H
# error Never include <ossc/modules/oss_upload_part_request.h> directly, use <ossc/client.h> instead.
#endif

#ifndef OSS_UPLOAD_PART_REQUEST_H
#define OSS_UPLOAD_PART_REQUEST_H

#include <string>

using namespace std;

namespace osscpp {

/**
 * @defgroup UploadPartRequest UploadPartRequest
 * @{
 */

/**
 * 包含上传Multipart分块（Part）参数
 */
class UploadPartRequest {

	private :
		string bucket_name_; /**< Bucket名称*/
		void *input_stream_; /**< 包含上传分块内容的数据流*/
		string key_; /**< OSSObject key*/
		string md5_digest_; /**< 分块（Part）数据的MD5校验值*/
		int part_number_; /**< 上传分块（Part）的标识号码（Part Number）*/
		long part_size_; /**< 分块（Part）数据的字节数*/
		string upload_id_; /**< 标识Multipart上传事件的Upload ID*/

		UploadPartRequest(const UploadPartRequest&);
		void operator=(const UploadPartRequest&);

	public :
		/**
		 * UploadPartRequest 构造函数
		 */
		UploadPartRequest(void)
		{
			part_number_ = 0;
			part_size_ = 0;
		}

		/**
		 * 获得Bucket名称
		 * @return 返回Bucket名称
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
		 * 获得OSSObject key
		 * @return OSSObject key
		 * @retval const string 
		 */
		inline const string key() const 
		{ return key_; }

		/**
		 * 设置OSSObject key
		 * @param key [in] OSSObject key
		 * @retval void
		 */
		inline void set_key(const string &key)
		{ key_ = key; }

		/**
		 * 获得分块（Part）数据的MD5校验值
		 * @return  分块（Part）数据的MD5校验值
		 * @retval const string 
		 */
		inline const string md5_digest() const 
		{ return md5_digest_; }

		/**
		 * 设置分块（Part）数据的MD5校验值
		 * @param md5_digest [in] 分块（Part）数据的MD5校验值
		 * @retval void
		 */
		inline void set_md5_digest(const string &md5_digest)
		{ md5_digest_ = md5_digest; }

		/**
		 * 获得包含上传分块内容的数据流
		 * @return 包含上传分块内容的数据流
		 * @retval const string 
		 */
		inline const void *input_stream() const
		{
			return input_stream_;
		}

		/**
		 * 设置包含上传分块内容的数据流
		 * @param input_stream [in] 包含上传分块内容的数据流
		 * @retval void
		 */
		inline void set_input_stream(void *input_stream)
		{
			input_stream_ = input_stream;
		}

		/**
		 * 获得标识Multipart上传事件的Upload ID
		 * @return 标识Multipart上传事件的Upload ID
		 * @retval const string 
		 */
		inline const string  upload_id() const 
		{ return upload_id_; }

		/**
		 * 设置标识Multipart上传事件的Upload ID
		 * @param upload_id [in] 标识Multipart上传事件的Upload ID
		 * @retval void
		 */
		inline void set_upload_id(const string &upload_id) 
		{ upload_id_ = upload_id; }

		/**
		 * 获得上传分块（Part）的标识号码（Part Number）
		 * @return 上传分块（Part）的标识号码（Part Number）
		 * @retval const string 
		 */
		inline int part_number() const 
		{ return part_number_; }

		/**
		 * 设置上传分块（Part）的标识号码（Part Number）
		 * @param part_number [in] 上传分块（Part）的标识号码（Part Number）
		 * @retval void
		 */
		inline void set_part_number(int part_number)
		{ part_number_ = part_number; }

		/**
		 * 返回分块（Part）数据的字节数
		 * @return 分块（Part）数据的字节数
		 * @retval long
		 */
		inline long part_size() const 
		{ return part_size_; }

		/**
		 * 设置返回分块（Part）数据的字节数
		 * @param part_size [in] 分块（Part）数据的字节数
		 * @retval void
		 */
		inline void set_part_size(long part_size)
		{ part_size_ = part_size; }
};
}


/**@}*/
#endif
