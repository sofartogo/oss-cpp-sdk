/*
 * =============================================================================
 *
 *       Filename:  oss_copy_object_result.h
 *
 *    Description:  oss_copy_object_result.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_COPY_OBJECT_RESULT_H
# error Never include <modules/oss_copy_object_result.h> directly, use <ossc/client.h> instead.
#endif

#ifndef OSS_COPY_OBJECT_RESULT_H
#define OSS_COPY_OBJECT_RESULT_H

#include <string>

using namespace std;

namespace osscpp {
/**
 * @defgroup CopyObjectResult CopyObjectResult
 * @{
 */

/**
 * 拷贝一个在OSS上已经存在的Object成另外一个Object的请求结果
 */
class CopyObjectResult {

	private :
		string etag_;       /**< 新Object的ETag值 */
		string last_modified_;   /**< 新Object的最后修改时间 */
		
		//CopyObjectResult(const CopyObjectResult&);
		//void operator=(const CopyObjectResult&);

	public :
		/**
		 * CopyObjectResult 构造函数
		 */
		CopyObjectResult(void)
		{}

		/**
		 * 获得新Object的ETag值
		 * @return 新Object的ETag值
		 * @retval const string 
		 */
		inline const string  etag() const 
		{ return etag_; }

		/**
		 * 设置新Object的ETag值
		 * @param etag [in] 新Object的ETag值
		 * @retval void
		 */
		inline void set_etag(const string &etag)
		{ etag_ = etag; }

		/**
		 * 获得新Object的最后修改时间
		 * @return 新Object的最后修改时间
		 * @retval const string 
		 */
		inline const string last_modified() const 
		{ return last_modified_; }

		/**
		 * 设置新Object的最后修改时间
		 * @param last_modified [in] 新Object的最后修改时间
		 * @retval void
		 */
		inline void set_last_modified(const string &last_modified)
		{ last_modified_ = last_modified; }

};
}

/**@}*/
#endif
