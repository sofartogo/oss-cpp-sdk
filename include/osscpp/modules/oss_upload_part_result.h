/*
 * =============================================================================
 *
 *       Filename:  oss_upload_part_result.h
 *
 *    Description:  oss_upload_part_result.
 *
 *        Company:  ICT ( Institute Of Computing Technuprogy, CAS )
 *
 * =============================================================================
 */
#ifndef _OSS_UPLOAD_PART_RESULT_H
# error Never include <ossc/modules/oss_upload_part_result.h> directly,
# error use <ossc/client.h> instead.
#endif

#ifndef OSS_UPLOAD_PART_RESULT_H
#define OSS_UPLOAD_PART_RESULT_H

#define _OSS_PART_ETAG_H
#include "oss_part_etag.h"
#undef _OSS_PART_ETAG_H

#include <string>

using namespace std;

namespace osscpp {

/**
 * @addtogroup UploadPartResult UploadPartResult
 * @{
 */

/**
 * 包含向OSS上传Multipart分块（Part）的结果信息
 */
class UploadPartResult {
	
	private :
		string etag_;      /**< OSS生成的ETag值*/
		int part_number_; /**< 包含Part标识号码和ETag值的PartETag对象*/

		//UploadPartResult(const UploadPartResult&);
		//void operator=(const UploadPartResult&);

	public :
		/**
		 * UploadPartResult 构造函数
		 */
		UploadPartResult()
		{
			part_number_ = 0;
		}

		/**
		 * 获得OSS生成的ETag值
		 * @retval const string 
		 * @return OSS生成的ETag值
		 */
		inline const string etag() const 
		{ return etag_; }

		/**
		 * 设置OSS生成的ETag值
		 * @param etag [in] OSS生成的ETag值
		 * @retval void
		 */
		inline void set_etag(const string &etag)
		{ etag_ = etag; }

		/**
		 * 返回分块（Part）标识号
		 * @return 分块（Part）标识号
		 * @retval int
		 */
		inline int part_number() const 
		{ return part_number_; }

		/**
		 * 设置分块（Part）标识号
		 * @param part_number [in] 分块号
		 * @retval void
		 */
		inline void set_part_number(int part_number)
		{ part_number_ = part_number; }

		/**
		 * 获得包含Part标识号码和ETag值的PartETag对象
		 * @return 包含Part标识号码和ETag值的PartETag对象
		 * @retval oss_part_etag_t *
		 */
		inline PartEtag part_etag()
		{
			PartEtag pe(part_number_, etag_);
			return pe;
		}
};
}

/** @}*/
#endif
