/*
 * =============================================================================
 *
 *       Filename:  generate_presigned_url_with_method.cc
 *
 *    Description:  generate_presigned_url_with_method example.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

/**
* 生成一个用指定 HTTP 方法访问 OSSObject 的 URL
*/
#include <osscpp/client.h>

#include <time.h>
#include <iostream>
#include <string>

using namespace std;
using namespace osscpp;

static const string access_id = "ACSfLOiddaOzejOP";   //设置用户帐号
static const string access_key = "MUltNpuYqE";  //设置用户密码
static const string endpoint = "storage.aliyun.com";    //设置hostname

int main()
{

	Client client(access_id, access_key, endpoint);
	const string bucket_name = "bucket_example";       //设置bucket_name
	const string key = "b.txt";

	time_t t = time(NULL); 
	t += 60;
	char  expiration[20];
	sprintf(expiration, "%ld", t);
	
	const string  url = client.GeneratePresignedUrl(bucket_name, key, expiration, "GET");
	cout << "url = " << url << endl;
	return 0;
}

