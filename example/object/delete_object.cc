/*
 * =============================================================================
 *
 *       Filename: delete_object.cc
 *
 *    Description:  delete object example.
 *
 *        Created:  09/21/2012 09:21:49 AM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */


#include <osscpp/client.h>
#include <iostream>
#include <string>

using namespace std;
using namespace osscpp;

static const string access_id  = "ACSGmv8fkV1TDO9L"; /**设置用户 Access ID */
static const string access_key = "BedoWbsJe2"; /** 设置用户的 Access Key */
static const string endpoint   = "storage.aliyun.com";    //设置 hostname

int main()
{
	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果;

	Client client(access_id, access_key, endpoint);
	const string bucket_name = "bucketname001";       //设置bucket_name
	const string key = "accumulo-1.4.0-src.tar.gz"; 

	client.DeleteObject(bucket_name, key, retcode);
	if(retcode == 0) {
		cout << "delete object successfully." << endl;
	} else {
		cout << "failed to delete object" << endl;
		cout << Util::GetMessageFromRetcode(retcode) << endl;
	}

	return 0;
}

