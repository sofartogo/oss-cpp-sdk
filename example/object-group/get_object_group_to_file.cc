/*
 * =============================================================================
 *
 *       Filename:  get_object_group_to_file.cc
 *
 *    Description:  get_object_group_to_file example.
 *
 *        Created:  09/21/2012 03:55:34 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

/**
* 读取用户指定的Object group到本地文件 
*/
#include <osscpp/client.h>
#include <iostream>
#include <string>

using namespace std;
using namespace osscpp;

static const string access_id  = "ACSfLOiddaOzejOP"; /**设置用户 Access ID */
static const string access_key = "MUltNpuYqE"; /** 设置用户的 Access Key */
static const string endpoint   = "storage.aliyun.com";    //设置 hostname

int main()
{
	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果;

	const string bucket_name = "bucket_example";       //设置bucket_name
	const string key = "a_group_file.dat";             //设置object group的名称
	const string file_name = "get_object_group";

	Client client(access_id, access_key, endpoint);
	GetObjectGroupRequest request(bucket_name, key);
	ObjectMetadata result = client.GetObjectGroupToFile(request, file_name, retcode);

	cout << "get_obejct_group_to_buffer result:" << endl << endl;
	if(retcode == OK) {
		cout << "get_object_group_to_buffer successfully." << endl;
		cout << "etag = " << result.etag() << endl 
			<< "last_modified = " << result.last_modified() << endl
			<< "content_type = " << result.content_type() << endl
			<< "content_length = " << result.content_length() << endl; 
	} else {
		cout << Util::GetMessageFromRetcode(retcode) << endl;
	}

	return 0;
}


