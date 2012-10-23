/*
 * =============================================================================
 *
 *       Filename:  upload_part.cc
 *
 *    Description:  upload_part example
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

	/* TODO: 设置upload id，此upload id由initiate multipart upload 操作返回 */
	const string upload_id = "0004CB9D8ADBD007E25D68FA4AEEBDF1";

	FILE *fp= fopen("mysql-5.1.52.tar.gz", "r"); /* 需要通过multipart upload上传的文件 */
	if (fp == NULL) {
		fprintf(stderr, "error in opening file...\nplease check again before upload part !\n");
		return -1;
	}
	unsigned int file_len = Util::GetFileSize(fp); /* 获取文件大小 */
	
	char *buffer = (char *)malloc(sizeof(char) * file_len + 1);
	memset(buffer, '\0', file_len + 1);
	unsigned int file_sz = fread(buffer, 1, file_len, fp);
	if (file_sz < file_len) {fprintf(stderr, "fread error.\n"); return -1;}
	const int single_request_len = 8 * 1024 * 1024; /* 每个Part的大小 */
	int requests_num = file_len / single_request_len; /* 需要多少次上传 */
	int current_part_number = 0; /* 当前上传的 Part Number */

	UploadPartRequest request;
	request.set_bucket_name(bucket_name);
	request.set_key(key);
	request.set_upload_id(upload_id);

	for (current_part_number = 0; current_part_number < requests_num + 1; current_part_number++) {
		/* 除了最后一块的其他块，最小为 5MB，此处设置单个Part为single_request_len = 8MB */
		if (current_part_number < requests_num) { 
			request.set_part_number(current_part_number + 1);
			void *input_stream = buffer + current_part_number * single_request_len;
			request.set_input_stream(input_stream);
			request.set_part_size(single_request_len);

			/* 上传Part */
			UploadPartResult result  = client.UploadPart(request, retcode);

			if (retcode == OK) { /* 打印返回信息，包括 Part Number 和 ETag 值 */
				cout << "PartNumber: " << result.part_number() << "," << "ETag: " << result.etag() << endl;
			} else { /* 打印出错信息 */
				cout << Util::GetMessageFromRetcode(retcode) << endl;
			}
		} else { /* 最后一块，可以小于5MB */
			request.set_part_number(current_part_number + 1);
			void *input_stream = buffer + current_part_number *single_request_len ;
			request.set_input_stream(input_stream);
			request.set_part_size(file_len - single_request_len * current_part_number);

			/* 上传Part */
			UploadPartResult result  = client.UploadPart(request, retcode);

			if (retcode == OK) { /* 打印返回信息，包括 Part Number 和 ETag 值 */
				cout << "PartNumber: " << result.part_number() << "," << "ETag: " << result.etag() << endl;
			} else { /* 打印出错信息 */
				cout << Util::GetMessageFromRetcode(retcode) << endl;
			}
		}
	}

	free(buffer);
	fclose(fp);

	return 0;

}

