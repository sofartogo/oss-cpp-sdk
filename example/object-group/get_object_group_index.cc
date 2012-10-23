/*
 * =============================================================================
 *
 *       Filename:  get_object_group_index.cc
 *
 *    Description:  get_object_group_index example.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

/**
* 返回 Object Group 中的 Object List 信息
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
	int i;

	Client client(access_id, access_key, endpoint);
	GetObjectGroupIndexResult result = client.GetObjectGroupIndex(bucket_name, key, retcode);

	cout << "get_obejct_group_index result:" << endl << endl; 
	if(retcode == OK) {
		cout << "get_object_group_index successfully." << endl;
		cout << "bucket_name = " << result.bucket_name() << endl << "key = " << result.key() << endl << "etag = " << result.etag() << endl << "file_length = " << result.file_length() << endl; 
		printf("============================================\n");
		for(i = 0; i < result.group().size(); i++) {
			cout << "part [" << i << "] :" << endl;
			cout << "etag = " << (result.group())[i].etag() << endl << "part_name = " << (result.group())[i].part_name() << endl << "part_number = " << (result.group())[i].part_number() << endl << "part_size = " << (result.group())[i].part_size() << endl;
			printf("*****************************************\n");
		}
	} else {
		cout << Util::GetMessageFromRetcode(retcode) << endl;
	}

	 return 0;
}


