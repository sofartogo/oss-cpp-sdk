/*
 * =============================================================================
 *
 *       Filename:  get_object_to_buffer.cc
 *
 *    Description:  get_object_to_buffer example.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

/**
* 获取远程文件到内存
*/
#include <osscpp/client.h>
#include <iostream>
#include <fstream>
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
	const string key = "glib-2.32.4.tar.xz"; 
	string local_file = "local-file.tar.xz";
	void *buffer = NULL;
	unsigned int buffer_len = 0;

	std::ofstream ofs(local_file.c_str(), ofstream::binary);
	GetObjectRequest request(bucket_name, key);

	ObjectMetadata metadata = client.GetObject(request, &buffer, buffer_len, retcode);

	ofs.write(static_cast<char *>(buffer), buffer_len);
	ofs.close();

	if(retcode == 0) {
		cout << "get object successfully." << endl;
		cout << "Content-Length: " << metadata.content_length() << endl;
		cout << "Content-Md5: " << metadata.etag() << endl;
		cout << "Content-Type: " << metadata.content_type() << endl;
		cout << "Last-Modified: " << metadata.last_modified() << endl;
	} else {
		cout << "failed to get object" << endl;
		cout << Util::GetMessageFromRetcode(retcode) << endl;
	}

	return 0;
}

