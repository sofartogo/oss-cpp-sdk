/*
 * =============================================================================
 *
 *       Filename:  oss_PartSummary.h
 *
 *    Description:  oss_PartSummary.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_PART_SUMMARY_H
# error Never include <ossc/modules/oss_PartSummary.h> directly, use <ossc/client.h> instead.
#endif

#ifndef OSS_PART_SUMMARY_H
#define OSS_PART_SUMMARY_H

#include <string>

using namespace std;

namespace osscpp {

/**
 * @defgroup PartSummary PartSummary
 * @{
 */

/**
 * 包含通过Multipart上传模式上传的Part的摘要信息
 */
class PartSummary {

	private :
		string etag_;                   /**< Part的etag值 */
		string last_modified_;          /**< Part上次修改的时间 */
		int part_number_;              /**< Part的序号number */
		long size_;                    /**< Part的大小 */

		//PartSummary(const PartSummary&);
		//void operator=(const PartSummary&);
		
	public :
		/**
		 * PartSummary构造函数
		 */
		PartSummary(void)
		{
			part_number_ = 0;
			size_ = 0;
		}

		/**
		 * 获得Part的etag值
		 * @return Part的etag值
		 * @retval const string 
		 */
		inline const string etag() const
		{ return etag_; }

		/**
		 * 设置Part的etag值
		 * @param etag [in] Part的etag值
		 * @retval void
		 */
		inline void set_etag(const string &etag)
		{ etag_ = etag; }

		/**
		 * 获得Part上次修改的时间
		 * @return Part上次修改的时间
		 * @retval const string 
		 */
		inline const string last_modified() const 
		{ return last_modified_; }

		/**
		 * 设置Part上次修改的时间
		 * @param lastmodified [in] Part上次修改的时间
		 * @retval void
		 */
		inline void set_last_modified(const string &last_modified)
		{ last_modified_ = last_modified; }

		/**
		 * 获得Part的序号number
		 * @return Part的序号number
		 * @retval int
		 */
		inline int part_number() const 
		{ return part_number_; }

		/**
		 * 设置Part的序号number
		 * @param part_number [in] Part的序号number
		 * @retval void
		 */
		inline void set_part_number(int part_number)
		{ part_number_ = part_number; }

		/**
		 * 获得Part的大小
		 * @return Part的大小
		 * @retval long
		 */
		inline long size() const 
		{ return size_; }

		/**
		 * 设置Part的大小
		 * @param size [in] Part的大小
		 * @retval void
		 */
		inline void set_size(long size)
		{ size_ = size; }
};
}

/**@}*/
#endif
