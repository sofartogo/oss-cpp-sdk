/*
 * =============================================================================
 *
 *       Filename:  delete_object_group.cc
 *
 *    Description:  delete_object_group example.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

/**
* Delete Object Group 删除用户指定的 Object Group 信息
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

	Client client(access_id, access_key, endpoint);
	const string bucket_name = "bucket_example";       //设置bucket_name
	const string key = "a_group_file.dat";             //设置object group的名称

	client.DeleteObjectGroup(bucket_name, key, retcode);

	cout << "delete_obejct_group result:" << endl << endl;
	if(retcode == NO_CONTENT) {
		cout << "delete_object_group successfully." << endl;
	} else {
		cout << Util::GetMessageFromRetcode(retcode) << endl;
	}

	return 0;
}


