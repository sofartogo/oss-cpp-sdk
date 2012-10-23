/*
 * =============================================================================
 *
 *       Filename:  oss_multipart_object_group.h
 *
 *    Description:  oss multipart_object_group
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#ifndef _OSS_MULTIPART_OBJECT_GROUP_H
# error Never include <ossc/modules/oss_multipart_object_group.h> directly, use <ossc/client.h> instead.
#endif

#ifndef OSS_MULTIPART_OBJECT_GROUP_H
#define OSS_MULTIPART_OBJECT_GROUP_H

#include <string>

using namespace std;

namespace osscpp {

/**
 * @defgroup MultipartObjectGroup MultipartObjectGroup
 * @{
 */

/**
 * object group中每个object的信息
 */
class MultipartObjectGroup {
	
	private :
		string etag_;              /**< Object的etag */
		string part_name_;         /**< Object的name */
		int part_number_;         /**< Object的number */
		size_t part_size_;        /**< Object的size */

		//MultipartObjectGroup(const MultipartObjectGroup&);
		//void operator=(const MultipartObjectGroup&);

	public :
		/**
		 * MultipartObjectGroup构造函数
		 */
		MultipartObjectGroup()
		{
			part_number_ = 0;
			part_size_ = 0;
		}
		
		/**
		 * 获得Object的etag
		 * @return Object的etag
		 * @retval const string 
		 */
		inline const string etag() const 
		{ return etag_; }

		/**
		 * 设置Object的etag
		 * @param etag [in] Object的etag
		 * @retval void
		 */
		inline void set_etag(const string &etag)
		{ etag_ = etag; }

		/**
		 * 获得Object的name
		 * @return Object的name
		 * @retval const string 
		 */
		inline const string part_name() const 
		{ return part_name_; }

		/**
		 * 设置Object的name
		 * @param part_name [in] Object的name
		 * @retval void
		 */
		inline void set_part_name(const string &part_name)
		{ part_name_ = part_name; }

		/**
		 * 获得Object的number
		 * @return Object的number
		 * @retval int
		 */
		inline int part_number() const 
		{ return part_number_; }

		/**
		 * 设置Object的number
		 * @param part_number [in] Object的number
		 * @retval void
		 */
		inline void set_part_number(int part_number)
		{ part_number_ = part_number; }

		/**
		 * 获得Object的size
		 * @return Object的size
		 * @retval size_t
		 */
		inline size_t part_size() const 
		{ return part_size_; }

		/**
		 * 设置Object的size
		 * @param part_size [in] Object的size
		 * @retval void
		 */
		inline void set_part_size(size_t part_size)
		{ part_size_ = part_size; }

};
}
/**@}*/
#endif // OSS_MULTIPART_OBJECT_GROUP_H

