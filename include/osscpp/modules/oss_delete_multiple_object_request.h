/*
 * =============================================================================
 *
 *       Filename:  oss_delete_multiple_object.h
 *
 *    Description:  oss_delete_multiple_object.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_DELETE_MULTIPLE_OBJECT_REQUEST_H
# error Never include <ossc/modules/oss_delete_multiple_object.h> directly, use <ossc/client.h> instead.
#endif

#ifndef OSS_DELETE_MULTIPLE_OBJECT_REQUEST_H
#define OSS_DELETE_MULTIPLE_OBJECT_REQUEST_H 

#include <string>
#include <vector>

using namespace std;

namespace osscpp {

/**
 * @defgroup DeleteMultipleObjectRequest DeleteMultipleObjectRequest
 * @{
 */

/**
 * 删除指定Bucket的多个Object
 */
class DeleteMultipleObjectRequest{

	private :
		string bucket_name_;   /**< Bucket名称 */
		vector<string> keys_;         /**< 多个Object的名称 */
		bool mode_;           /**< 设置为 true 表示 quiet 模式，false 标识 verbose 模式 */

		DeleteMultipleObjectRequest(const DeleteMultipleObjectRequest&);
		void operator=(const DeleteMultipleObjectRequest&);

	public :
		/**
		 * DeleteMultipartObjectRequest 构造函数
		 * @param bucket_name [in] Bucket名称
		 * @param keys [in] 多个Object的名称
		 * @param mode [in] 模式
		 */
		DeleteMultipleObjectRequest(
				const string &bucket_name,
				vector<string> &keys,
				bool mode)
		{
			bucket_name_ = bucket_name;
			keys_ = keys;
			mode_ = mode;
		}
		
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
		 * 获得多个Object的名称
		 * @return 多个Object的名称
		 * @retval const string *
		 */
		vector<string> keys() const
		{ return keys_; }

		/**
		 * 设置多个Object的名称
		 * @retval void
		 */
		inline void set_keys(vector<string> &keys)
		{ keys_ = keys; }

		/**
		 * 获得模式
		 * @return 模式
		 * @retval bool
		 */
		inline bool  mode() const 
		{ return mode_; }

		/**
		 * 设置模式
		 * @param mode [in] 模式
		 * @retval void
		 */
		inline void set_mode(bool mode)
		{ mode_ = mode; }
};
}
/**@}*/
#endif
