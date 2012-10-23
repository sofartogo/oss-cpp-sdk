/*
 * =============================================================================
 *
 *       Filename:  get_bucket_acl.cc
 *
 *    Description:  get_bucket_acl example.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

/**
* 获得指定bucket的访问权限
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
	//const char *retinfo;            //保存通过retcode获得的错误信息

	Client client(access_id, access_key, endpoint);
	const string bucket_name = "bucket_example";    //设置bucket_name

	AccessControlList acl;
	acl = client.GetBucketAcl(bucket_name, retcode);
	Owner owner;
	cout << "get_bucket_acl result:" << endl << endl;
	if(retcode == 0) {
		cout << "get_bucket_acl successfully." << endl;
		owner = acl.owner();
		cout << "grant = " << acl.grant() << endl 
			<< "id = " << owner.id() << endl
			<< "display_name = " << owner.display_name() << endl;
	} else {
		cout << Util::GetMessageFromRetcode(retcode) << endl;
	}
	return 0;
}

