/*
 * =============================================================================
 *
 *       Filename:  oss_put_object_result.h
 *
 *    Description:  oss_put_object_result.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_PUT_OBJECT_RESULT_H
# error Never include <ossc/modules/oss_put_object_result.h> directly, use <ossc/client.h> instead.
#endif

#ifndef OSS_PUT_OBJECT_RESULT_H
#define OSS_PUT_OBJECT_RESULT_H

#include <string>

using namespace std;

namespace osscpp {

/**
 * @defgroup PutObjectResult PutObjectResult
 * @{
 */

/**
 * 上传object操作的返回结果
 */
class PutObjectResult {
	
	private :
		string etag_; /**< 新创建的OSSObject的ETag值*/

		//PutObjectResult(const PutObjectResult&);
		//void operator=(const PutObjectResult&);

	public :
		/**
		 * PutObjectResult 构造函数
		 */
		PutObjectResult()
		{}

		/**
		 * 获得新创建的OSSObject的ETag值
		 * @return 新创建的OSSObject的ETag值
		 * @retval const string 
		 */
		inline const string etag() const 
		{ return etag_; }

		/**
		 * 设置新创建的OSSObject的ETag值
		 * @param etag [in] 新创建的OSSObject的ETag值
		 * @retval void
		 */
		inline void set_etag(const string &etag)
		{ etag_ = etag; }
};
}
/**@}*/
#endif
