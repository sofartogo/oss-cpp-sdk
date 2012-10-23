/*
 * =============================================================================
 *
 *       Filename:  get_object_metadata.cc
 *
 *    Description:  get_object_metadata example.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

/**
* 返回OSSObject的元数据
*/
#include <osscpp/client.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
using namespace osscpp;

static const string access_id  = "ACSGmv8fkV1TDO9L"; /**设置用户 Access ID */
static const string access_key = "BedoWbsJe2"; /** 设置用户的 Access Key */
static const string endpoint   = "storage.aliyun.com";    //设置 hostname

int main()
{
	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果;

	Client client(access_id, access_key, endpoint);
	const string bucket_name = "bucketname001";       //设置bucket_name
	const string key = "glib-2.32.4.tar.xz"; 
	ObjectMetadata metadata = client.GetObjectMetadata(bucket_name, key, retcode);

	if(retcode == 0) {
		cout << "get object successfully." << endl;
		cout << "Content-Length: " << metadata.content_length() << endl;
		cout << "Content-Md5: " << metadata.etag() << endl;
		cout << "Content-Type: " << metadata.content_type() << endl;
		cout << "Last-Modified: " << metadata.last_modified() << endl;
	} else {
		cout << "failed to get object" << endl;
		cout << Util::GetMessageFromRetcode(retcode) << endl;
	}

	return 0;
}

