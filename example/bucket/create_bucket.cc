/*
 * =============================================================================
 *
 *       Filename:  create_bucket.cc
 *
 *    Description:  create_bucket example.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

/**
* 为用户创建一个bucket
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

	client.CreateBucket(bucket_name, retcode);
	if(retcode == 0) {
		cout << "create bucket successfully." << endl;
	} else {
		cout << Util::GetMessageFromRetcode(retcode) << endl;
	}

	return 0;
}

