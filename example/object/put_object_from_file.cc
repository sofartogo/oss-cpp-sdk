/*
 * =============================================================================
 *
 *       Filename:  put_object_from_file.cc
 *
 *    Description:  put_object_from_file example.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#include <osscpp/client.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
using namespace osscpp;

static const string access_id  = "ACSGmv8fkV1TDO9L"; /**设置用户 Access ID */
static const string access_key = "BedoWbsJe2"; /** 设置用户的 Access Key */
static const string endpoint   = "storage.aliyun.com";    //设置 hostname

long
_GetFileSize(FILE *fp)
{
    long int save_pos;
    long size_of_file;
    /* Save the current position. */
    save_pos = ftell(fp);
    /* Jump to the end of the file. */
    fseek(fp, 0L, SEEK_END);
    /* Get the end position. */
    size_of_file = ftell(fp);
    /* Jump back to the original position. */
    fseek(fp, save_pos, SEEK_SET);
    return size_of_file;
}
/* 将文件上传至云服务器中 */
int main()
{

	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果;

	Client client(access_id, access_key, endpoint);

	const string bucket_name = "bucketname001";       //设置bucket_name
	const string key         = "put-ojbect.data";      //设置上传key
	const string local_file  = "proactor.pdf";         //设置需要上传的文件
	unsigned int retsize = 0; // 读取文件时的返回值

	FILE *fp = fopen(local_file.c_str(), "r");
	if (fp == NULL) {
		return -1;
	}
	long file_len = _GetFileSize(fp);
	stringstream ss;
	ss << file_len;

#if 1
	/* 初始化元信息，并设置相关属性 */
	ObjectMetadata metadata;
	metadata.set_content_length(ss.str()); /** 该参数必须设置 */
	metadata.set_content_type("application/octet-stream");
	metadata.set_cache_control("no-cache");
	metadata.set_content_encoding("utf-8");
	metadata.set_content_disposition("attachment;");
	metadata.set_expiration_time("Thu, 13 Sep 2012 21:08:42 GMT");
#endif
	/* 将文件上传至云服务器中 */
	PutObjectResult result = client.PutObjectFromFile(
			bucket_name, key, local_file, metadata, retcode);
	if(retcode == 0) {
		cout << "put object successfully." << endl;
		cout << "ETag: " << result.etag() << endl;
	} else {
		cout << "failed to put object" << endl;
		cout << Util::GetMessageFromRetcode(retcode) << endl;
	}
	fclose(fp);
}
