/*
 * =============================================================================
 *
 *       Filename:  oss_callback.cc
 *
 *    Description:  curl callback routines.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#include <stdio.h>
#include <string.h>

#include "oss_callback.h"
#include "oss_request_param.h"

namespace osscpp {

unsigned int
Callback::GeneralOperationSendCallback(
		void *ptr, unsigned int size, 
		unsigned int nmemb, void *stream)
{
	ParamBuffer *send_buffer = (ParamBuffer *)stream;
	unsigned int bytes_per_send = size * nmemb; 

	if(bytes_per_send < 1)
		return 0;
	if(send_buffer->left > 0) {
		if (send_buffer->left > bytes_per_send) {
			memcpy((void *)ptr,
					(const void *)(send_buffer->ptr), bytes_per_send);
			send_buffer->ptr += bytes_per_send; /* advance pointer */
			send_buffer->left -= bytes_per_send; /* less data left */
			return bytes_per_send;
		} else {
			memcpy((void *)ptr,
					(const void *)(send_buffer->ptr), send_buffer->left);
			unsigned int last_sent_bytes = send_buffer->left;
			send_buffer->left -= bytes_per_send; /* less data left */
			return last_sent_bytes;
		}
	} else return 0;
}

unsigned int
Callback::GeneralOperationSendCallback2nd(
		void *ptr, unsigned int size, 
		unsigned int nmemb, void *stream)
{
	ParamBuffer *send_buffer = (ParamBuffer *)stream;
	unsigned int bytes_per_send = size * nmemb; 

	if(bytes_per_send < 1)
		return 0;
	if(static_cast<int>(send_buffer->left) > 0) {
		if (send_buffer->left > bytes_per_send) {
			memcpy((void *)ptr,
					(const void *)(send_buffer->ptr +
						send_buffer->allocated - send_buffer->left), bytes_per_send);
			send_buffer->left -= bytes_per_send; /* less data left */
			return bytes_per_send;
		} else {
			memcpy((void *)ptr,
					(const void *)(send_buffer->ptr +
						send_buffer->allocated - send_buffer->left), send_buffer->left);
			unsigned int last_sent_bytes = send_buffer->left;
			send_buffer->left -= bytes_per_send; /* less data left */
			return last_sent_bytes;
		}
	} else return 0;
}

unsigned int
Callback::GeneralOperationRecvCallback(
		void *ptr, unsigned int size,
		unsigned int nmemb, void *stream)
{
	ParamBuffer *recv_buffer = (ParamBuffer *)stream;
	unsigned int bytes_per_recv = size * nmemb;
	if (recv_buffer->left > 0) {
		unsigned int offset = recv_buffer->allocated - recv_buffer->left;
		if (recv_buffer->left > bytes_per_recv) {
			strncpy(recv_buffer->ptr + offset, (const char *)ptr, size * nmemb);
			recv_buffer->left -= bytes_per_recv;
			return bytes_per_recv;
		} else {
			strncpy(recv_buffer->ptr + offset, (const char *)ptr, recv_buffer->left);
			unsigned int last_recv_bytes = recv_buffer->left;
			recv_buffer->left -= bytes_per_recv;
			return last_recv_bytes;
		}
	} else {
		fprintf(stderr, "%s\n", "Receive buffer overflow!");
		return 0;
	}
}

unsigned int
Callback::GeneralOperationRecvCallback2nd(
		void *ptr, unsigned int size,
		unsigned int nmemb, void *stream)
{

  unsigned int recv_size = size * nmemb;
  ParamBuffer *recv_buffer = (ParamBuffer *)stream;
 
  recv_buffer->ptr = (char *)realloc(recv_buffer->ptr, recv_buffer->allocated + recv_size + 1);
  if (recv_buffer->ptr == NULL) {
    /* out of memory! */ 
    exit(EXIT_FAILURE);
  }
  memcpy(&(recv_buffer->ptr[recv_buffer->allocated]), ptr, recv_size);
  recv_buffer->allocated += recv_size;
  recv_buffer->ptr[recv_buffer->allocated] = 0;
  return recv_size;
}


unsigned int
Callback::GeneralOperationHeaderCallback(
		void *ptr, unsigned int size,
		unsigned int nmemb, void *stream)
{
	ParamBuffer *header_buffer = (ParamBuffer *)stream;
	char etag[48] = {0};
	int rcode = 0;
	int retag = 0;
	unsigned int code = 0;

	rcode = sscanf((const char *)ptr, "HTTP/1.1 %u\n", &code);
	if (rcode != 0) {
		header_buffer->code= code;
	}

	retag = sscanf((const char *)ptr, "ETag: %s", etag);
	if (retag != 0) {
		memset(header_buffer->ptr, 0, header_buffer->allocated);
		strncpy(header_buffer->ptr, etag, 48);
	}

	return size * nmemb;
}

unsigned int
Callback::GeneralOperationHeaderCallback2nd(
		void *ptr, unsigned int size,
		unsigned int nmemb, void *stream)
{
	ParamBuffer *header_buffer = (ParamBuffer *)stream;
	char etag[48] = {0};
	char type[64] = {0};
	char length[16] = {0};
	char week[5] = {0};
	char day[3] = {0};
	char mon[4] = {0};
	char year[5] = {0};
	char time[9] = {0};
	char gmt[4] = {0};
	int rcode = 0;
	int retag = 0;
	int rtype = 0;
	int rlength = 0;
	int rlastmodified = 0;
	unsigned int code = 0;

	rcode = sscanf(static_cast<const char *>(ptr), "HTTP/1.1 %u\n", &code);
	if (rcode != 0) {
		header_buffer->code= code;
	}

	retag = sscanf(static_cast<const char *>(ptr), "ETag: %s", etag);
	if (retag != 0) {
		unsigned int offset = header_buffer->allocated - header_buffer->left;
		retag = sprintf(header_buffer->ptr + offset, "Content-Md5#%s#", etag);
		header_buffer->left -= retag;
	}
	
	rtype = sscanf(static_cast<const char *>(ptr), "Content-Type: %s", type);
	if (rtype != 0) {
		unsigned int offset = header_buffer->allocated - header_buffer->left;
		rtype = sprintf(header_buffer->ptr + offset, "Content-Type#%s#", type);
		header_buffer->left -= rtype;
	}
	
	rlength = sscanf(static_cast<const char *>(ptr), "Content-Length: %s", length);
	if (rlength != 0) {
		unsigned int offset = header_buffer->allocated - header_buffer->left;
		rlength = sprintf(header_buffer->ptr + offset, "Content-Length#%s#", length);
		header_buffer->left -= rlength;
	}

	rlastmodified = sscanf(static_cast<const char *>(ptr),
			"Last-Modified: %s %s %s %s %s %s", week, day, mon, year, time, gmt);
	if (rlastmodified != 0) {
		unsigned int offset = header_buffer->allocated - header_buffer->left;
		rlastmodified = sprintf(header_buffer->ptr + offset, "Last-Modified#%s %s %s %s %s %s#", week,
				day, mon, year, time, gmt);
		header_buffer->left -= rlastmodified;
	}
	return size * nmemb;
}

}
