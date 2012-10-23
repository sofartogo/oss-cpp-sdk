/*
 * =============================================================================
 *
 *       Filename:  list_objects_with_bucket_name.cc
 *
 *    Description:  list_objects_with_bucket_name example.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

/**
* 返回请求者指定Bucket下的所有Object的列表
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
	int i;
	Client client(access_id, access_key, endpoint);
	const string bucket_name = "bucket_example";

	ObjectListing object_listing = client.ListObjects(bucket_name, retcode);
	cout << "list_objects_with_bucket_name result:" << endl << endl;
	if(retcode == 0) {
		cout << "list_objects_with_bucket_name successfully." << endl;
		cout << "bucket_name = " << object_listing.bucket_name() << endl
			<< "next_marker = " << object_listing.next_marker() << endl
			<< "prefix = " << object_listing.prefix() << endl
			<< "marker = " << object_listing.marker() << endl
			<< "max_keys = " << object_listing.max_keys() << endl
			<< "delimiter = " << object_listing.delimiter() << endl
			<< "is_truncated = " << object_listing.is_truncated() << endl; 
		for(i = 0; i < object_listing.summaries().size(); i++) {
			cout << "****************************************************************" << endl;
			cout << "object [" << i << "] : " << endl;
			cout << "type = " << (object_listing.summaries())[i].type() << endl 
				<< "etag = " << (object_listing.summaries())[i].etag() << endl
				<< "key = " << (object_listing.summaries())[i].key() << endl
				<< "last_modified = " << (object_listing.summaries())[i].last_modified() << endl
				<< "size = " << (object_listing.summaries())[i].size() << endl 
				<< "storage_class = " << (object_listing.summaries())[i].storage_class() << endl
				<< "id = " << (object_listing.summaries())[i].owner().id() << endl
				<< "display_name = " << (object_listing.summaries())[i].owner().display_name() << endl;
		}
	} else {
		cout << Util::GetMessageFromRetcode(retcode) << endl;
	}

	return 0;
}

