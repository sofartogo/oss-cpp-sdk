/*
 * =============================================================================
 *
 *       Filename:  complete_multipart_upload.cc
 *
 *    Description:  complete_multipart_upload example
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

const char *etags[] = {
	"5EAE389C2B7DB4D7CBF36B6F125272F6",
	"F8EC926E209252B72CFBB775A9360E8D"
};

int main()
{

	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果;

	Client client(access_id, access_key, endpoint);
	const string bucket_name = "bucketname001";       //设置bucket_name
	const string key = "accumulo-1.4.0-src.tar.gz"; 

	/* TODO: 设置upload id，此upload id由initiate multipart upload 操作返回 */
	const string upload_id = "0004CB9D8ADBD007E25D68FA4AEEBDF1";

	vector<PartEtag> vparts;
	for (int i = 0; i < sizeof(etags) / sizeof(char *); i++) {
		PartEtag part(i + 1, etags[i]);
		vparts.push_back(part);
	}
	CompleteMultipartUploadRequest request(bucket_name, key, upload_id, vparts);
	CompleteMultipartUploadResult result = client.CompleteMultipartUpload(request, retcode);

	if(retcode == 0) {
		cout << "CompleteMultipartUpload execute successfully." << endl;
		cout << "ETag: " << result.etag() << endl;
	} else {
		cout << "failed!" << endl;
		cout << Util::GetMessageFromRetcode(retcode) << endl;
	}

	return 0;

}
