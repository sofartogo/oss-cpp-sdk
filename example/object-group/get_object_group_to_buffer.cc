/*
 * =============================================================================
 *
 *       Filename:  get_object_group_to_buffer.cc
 *
 *    Description:  get_object_group_to_buffer example.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

/**
* 读取用户指定的Object group到buffer 
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
	string buffer;

	Client client(access_id, access_key, endpoint);
	GetObjectGroupRequest request(bucket_name, key);
	ObjectMetadata result = client.GetObjectGroupToBuffer(request, buffer, retcode);

	cout << "get_obejct_group_to_buffer result:" << endl << endl;
	if(retcode == OK) {
		cout << "get_object_group_to_buffer successfully." << endl;
		cout << "etag = " << result.etag() << endl 
			<< "last_modified = " << result.last_modified() << endl
			<< "content_type = " << result.content_type() << endl
			<< "content_length = " << result.content_length() << endl; 
		cout << "buffer = " << endl << buffer << endl;
	} else {
		cout << Util::GetMessageFromRetcode(retcode) << endl;
	}

	return 0;
}


