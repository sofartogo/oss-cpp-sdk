/*
 * =============================================================================
 *
 *       Filename:  set_bucket_acl.cc
 *
 *    Description:  set_bucket_acl example.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

/**
* 设置指定bucket的访问权限
* 暂时服务器那边的private和public-read-write是一样的
*/

#include <osscpp/client.h>
#include <iostream>
#include <string>

using namespace std;
using namespace osscpp;

static const string access_id = "ACSfLOiddaOzejOP";   //设置用户帐号
static const string access_key = "MUltNpuYqE";  //设置用户密码
static const string endpoint = "storage.aliyun.com";    //设置hostname

int main()
{
	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果
	const string retinfo;            //保存通过retcode获得的错误信息

	Client client(access_id, access_key, endpoint);
	const string bucket_name = "bucket_example";    //设置bucket_name

	const string acl = "private";            //设置bucket的访问权限（private，public-read，public-read-write中的一个）
	client.SetBucketAcl(bucket_name, acl, retcode);
	printf("set_bucket_acl result:\n\n");
	if(retcode == 0) {
		cout << "set bucket acl successfully." << endl;
	} else {
		cout << Util::GetMessageFromRetcode(retcode) << endl;
	}

	return 0;
}

