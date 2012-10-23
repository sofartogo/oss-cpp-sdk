/*
 * =============================================================================
 *
 *       Filename:  is_bucket_exist.cc
 *
 *    Description:  is_bucket_exist example.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

/**
* 判断一个bucket是否存在
*/
#define _OSS_CLIENT_H
#include <osscpp/modules/oss_client.h>
#undef _OSS_CLIENT_H
#include <iostream>
#include <string>

using namespace std;
using namespace osscpp;

static const string access_id  = "ACSfLOiddaOzejOP"; /**设置用户 Access ID */
static const string access_key = "MUltNpuYqE"; /** 设置用户的 Access Key */
static const string endpoint   = "storage.aliyun.com";    //设置 hostname

int main()
{
	bool result;
	Client client(access_id, access_key, endpoint);
	const string bucket_name = "bucket_example";       //设置bucket_name

	result = client.IsBucketExist(bucket_name);
	cout << "is_bucket_exist result:" << endl << endl;
	if(result == true) {
		cout << "bucket exist." << endl;
	} else {
		cout << "bucket not exist" << endl;
	}

	return 0;
}

