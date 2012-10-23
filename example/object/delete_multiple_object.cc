/*
 * =============================================================================
 *
 *       Filename:  delete_multiple_object.cc
 *
 *    Description:  delete_multiple_object example.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

/**
* 删除多个object
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
	const string bucket_name = "bucketexample";       //设置bucket_name

	vector<string> keys;
	keys.push_back("multipart-upload.data");
	keys.push_back("put-object.data");
	bool mode = true;
	DeleteMultipleObjectRequest request(bucket_name, keys, mode);

	client.DeleteMultipleObject(request, retcode);
	if(retcode == 0) {
		cout << "delete multiple object successfully." << endl;
	} else {
		cout << "failed to delete multiple object" << endl;
		cout << Util::GetMessageFromRetcode(retcode) << endl;
	}

	return 0;
}

