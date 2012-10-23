/*
 * =============================================================================
 *
 *       Filename:  post_object_group.cc
 *
 *    Description:  post_object_group example.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

/**
* Post Object Group 操作将根据用户提供的 Object 信息,在 OSS 服务器端创建出一个新的 Object Group。
* 用户需要将创建该 Object Group 所需的 Object Name, E-tag 以及标识该 Object 在整个 Group 中相对位置的 Part ID
* 按照规定的 XML 格式发给 OSS, Object 的 E-tag 值可以通过list_object功能获得。
*/
#include <osscpp/client.h>
#include <iostream>
#include <string>

using namespace std;
using namespace osscpp;

static const string access_id  = "ACSfLOiddaOzejOP"; /**设置用户 Access ID */
static const string access_key = "MUltNpuYqE"; /** 设置用户的 Access Key */
static const string endpoint   = "storage.aliyun.com";    //设置 hostname

/* *设置要组合的Objects的etag值 */
static const char *etags[] = {
	"6F395BF16882D154CCB448806EA8C47D",
	"321F048D6C898398F3168545F6CE8551",
	"249697174471EEE73202E9214B037E08",
	"B78E7B470FA41AA5478CFB0EDFF7B2E6",
	"E0CA28D194BC790EF3C6236231D033A7"
};

/* *设置要组合的Objects的name */
static const char *partname[] = {
	"a.txt",
	"b.txt",
	"c.txt",
	"d.txt",
	"e.txt"
};

int main()
{
	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果;

	Client client(access_id, access_key, endpoint);
	const string bucket_name = "bucket_example";       //设置bucket_name
	const string key = "a_group_file.dat";             //设置object group的名称
	int i;
	int n = sizeof(partname)/sizeof(char *);
	/* *构造各个Object的etag，name，ID到part_item */
	vector<ObjectGroupItem> part_item;
	for (i = 0; i < n; i++) {
		string etag = etags[i];
		string name = partname[i];
		int number = i + 1;
		ObjectGroupItem item(etag, name, number);
		part_item.push_back(item);
	}
	PostObjectGroupRequest request(bucket_name, key, part_item);
	PostObjectGroupResult result = client.PostObjectGroup(request, retcode);

	cout << "post_obejct_group result:" << endl << endl;
	if(retcode == OK) {
		cout << "post_object_group successfully." << endl;
		cout << "bucket_name = " << result.bucket_name() << endl << "key = " << result.key() << endl << "etag = " << result.etag() << endl << "size = " << result.size() << endl; 
	} else {
		cout << Util::GetMessageFromRetcode(retcode) << endl;
	}

	return 0;
}


