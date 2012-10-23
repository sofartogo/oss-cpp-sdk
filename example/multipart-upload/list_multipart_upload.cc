/*
 * =============================================================================
 *
 *       Filename:  list_multipart_upload.cc
 *
 *    Description:  list_multipart_upload example
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


	ListMultipartUploadsRequest request(bucket_name);
	MultipartUploadListing listing = client.ListMultipartUploads(request, retcode);
	if(retcode == 0) {
		cout << "ListMultipartUploads execute successfully." << endl;
		vector<MultipartUpload> multipart_upload = listing.multipart_uploads();
		vector<MultipartUpload>::iterator iter;
		for (iter = multipart_upload.begin(); iter != multipart_upload.end(); iter++) {
			cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			cout << "Initiated: " << (*iter).initiated() << endl;
			cout << "Storage Class: " << (*iter).storage_class() << endl;
			cout << "Upload ID: " << (*iter).upload_id() << endl;
			cout << "Key: " << (*iter).key() << endl;
		}
	} else {
		cout << "failed!" << endl;
		cout << Util::GetMessageFromRetcode(retcode) << endl;
	}

	return 0;
}


