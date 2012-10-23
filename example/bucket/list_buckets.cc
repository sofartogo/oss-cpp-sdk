/*
 * =============================================================================
 *
 *       Filename:  list_buckets.cc
 *
 *    Description:  list_buckets example.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

/**
* 返回请求者拥有的所有Bucket的列表
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

	int i;
	vector<Bucket> buckets;
	Owner owner;
	buckets = client.ListBuckets(retcode);
	cout << "list buckets result:" << endl << endl;
	if(retcode == 0) {
		cout << "list buckets successfully." << endl;
		if(buckets.size() != 0) {
			for(i = 0; i < buckets.size(); i++) {
				cout << "***********************************************************************" << endl;
				cout << "bucket [" << i << "] : " << endl;
				cout << "name = " << buckets[i].name() 
					<< "\tcreate_date = " << buckets[i].create_date() << endl;
				owner = buckets[i].owner();
				cout << "id = " << owner.id() <<
					"\tdisplay_name = " << owner.display_name() << endl;
			}
		} else {
			cout << "empty bucket list." << endl;
		}
	} else {
		cout << Util::GetMessageFromRetcode(retcode) << endl;
	}

	return 0;
}

