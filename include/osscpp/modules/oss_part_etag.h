/*
 * =============================================================================
 *
 *       Filename:  oss_part_etag.h
 *
 *    Description:  oss_part_etag.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_PART_ETAG_H
# error Never include <ossc/modules/oss_part_etag.h> directly, use <ossc/client.h> instead.
#endif

#ifndef OSS_PART_ETAG_H
#define OSS_PART_ETAG_H

#include <string>

using namespace std;

namespace osscpp {

/**
 * @defgroup PartEtag PartEtag
 * @{
 */

/**
 * 包含Multipart上传的Part的返回结果信息
 */
class PartEtag {

	private :
		string etag_;             /**< Part的ETag值 */
		int part_number_;        /**< Part标识号码 */

		//PartEtag(const PartEtag&);
		//void operator=(const PartEtag&);

	public :
		/**
		 * PartEtag构造函数
		 * @param part_number [in] Part标识号码
		 * @param etag [in] Part的ETag值
		 */
		PartEtag(int part_number, const string &etag)
		{
			part_number_ = part_number;
			etag_ = etag;
		}
		
		/**
		 * 获得Part的ETag值
		 * @return Part的ETag值
		 * @retval const string 
		 */
		inline const string etag() const 
		{ return etag_; }

		/**
		 * 设置Part的ETag值
		 * @param pe [in] 标识一个PartEtag结构指针
		 * @param etag [in] Part的ETag值
		 * @retval void
		 */
		inline void set_etag(const string &etag)
		{ etag_ = etag; }

		/**
		 * 获得Part标识号码
		 * @return Part标识号码
		 * @retval int
		 */
		inline int part_number() const 
		{ return part_number_; }

		/**
		 * 设置Part标识号码
		 * @param part_number [in] Part标识号码
		 * @retval void
		 */
		inline void set_part_number(int part_number)
		{ part_number_ = part_number; }
};
}
/**@}*/
#endif
