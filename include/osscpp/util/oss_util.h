/*
 * =============================================================================
 *
 *       Filename:  oss_time.h
 *
 *    Description:  oss time utility.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#ifndef oss_time_h
#define oss_time_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <string>


#define _OSS_CONSTANTS_H
#include <osscpp/oss_constants.h>
#undef _OSS_CONSTANTS_H
using namespace std;

namespace osscpp {

class Util {

	public :
		/**
		 * 获取ANSI C格式时间
		 */
		 static const string GetAscTime()
		 {
			time_t now;
			struct tm *gmt;
			time(&now);
			gmt = gmtime(&now);
			return asctime(gmt);
		 }

		/**
		 * 获取符合 HTTP/1.1 格式时间
		 */
		static const string GetGmtTime()
		{
			time_t now;
			struct tm *gmt;
			char *time_val;
			time(&now);
			gmt = gmtime(&now);
			time_val = (char *)malloc(sizeof(char) * 65);
			memset(time_val, '\0', 65);
			strftime(time_val, 64, "%a, %d %b %Y %H:%M:%S GMT", gmt);
			string gmt_time = time_val;
			free(time_val);
			return gmt_time;
		}
		
		static char *ComputeMD5Digest(const void *ptr, unsigned int len);
		static long GetFileSize(FILE *fp);
		static const string GenerateAuthentication(const string &access_key,
				const string &method,
				map<string, string> &default_headers,
				map<string, string> &user_headers,
				const string &resource);
		
		static OSS_ERROR_CODE GetRetcodeFromResponse(const char *response);
		static const char *GetMessageFromRetcode(OSS_ERROR_CODE retcode);

	private:
		static OSS_ERROR_CODE GetRetcodeFromRetinfo(const char *retinfo);
};
}
#endif
