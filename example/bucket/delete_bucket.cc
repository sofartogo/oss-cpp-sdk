/*
 * =============================================================================
 *
 *       Filename:  delete_bucket.cc
 *
 *    Description:  delete_bucket example.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

/**
* 为用户删除一个bucket
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

	client.DeleteBucket(bucket_name, retcode);
	cout << "delete_bucket result:" << endl << endl;
	if(retcode == NO_CONTENT) {
		cout << "delete bucket successfully." << endl;
	} else {
		cout << Util::GetMessageFromRetcode(retcode) << endl;
	}

	return 0;
}

