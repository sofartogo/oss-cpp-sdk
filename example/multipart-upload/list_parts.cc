/*
 * =============================================================================
 *
 *       Filename:  list_parts.cc
 *
 *    Description:  list_parts example
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
	const string upload_id = "0004CB9D8ADBD007E25D68FA4AEEBDF1";
	


	ListPartsRequest request(bucket_name, key, upload_id);
	PartListing listing = client.ListParts(request, retcode);
	if(retcode == 0) {
		cout << "ListParts execute successfully." << endl;
		cout << "Bucket Name: " << listing.bucket_name() << endl;
		cout << "Upload ID " << listing.upload_id() << endl;
		cout << "Storage Class: " << listing.storage_class() << endl;

		vector<PartSummary> parts = listing.parts();
		vector<PartSummary>::iterator iter;
		for (iter = parts.begin(); iter != parts.end(); iter++) {
			cout << "Etag: " << (*iter).etag() << endl;
			cout << "Last Modified: " << (*iter).last_modified() << endl;
			cout << "Part Number: " << (*iter).part_number() << endl;
			cout << "Size: " << (*iter).size() << endl;

		}
	} else {
		cout << "failed!" << endl;
		cout << Util::GetMessageFromRetcode(retcode) << endl;
	}

	return 0;
}

