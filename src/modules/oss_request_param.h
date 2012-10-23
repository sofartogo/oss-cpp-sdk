/*
 * =============================================================================
 *
 *       Filename:  oss_request_param.h
 *
 *    Description:  oss request parameter utility.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#ifndef OSS_REQUEST_PARAM_H
#define OSS_REQUEST_PARAM_H

#include <stdio.h>
#include <stdlib.h>

namespace osscpp {

struct ParamBuffer {
	char *ptr; //< 缓冲区首指针 /
	unsigned int left; //< 缓冲区剩余大小 /
	unsigned int allocated; //< 缓冲区总大小 /
	unsigned short code; //< 返回码 /
};

class Request {
public:
	Request();
	Request(unsigned int snd_buffer_size,
			unsigned int rcv_buffer_size,
			unsigned int hdr_buffer_size);

	inline ParamBuffer * send_buffer() const
	{ return send_buffer_;}

	inline void set_send_buffer(ParamBuffer *send_buffer)
	{
		if (send_buffer_ != NULL) {
			if (send_buffer_->ptr != NULL) {
				free(send_buffer_->ptr);
				send_buffer_->ptr = NULL;
			}
			delete send_buffer_;
		}
		send_buffer_ = send_buffer;
	}

	inline ParamBuffer * recv_buffer() const
	{return recv_buffer_;}

	inline void set_recv_buffer(ParamBuffer *recv_buffer)
	{ recv_buffer_ = recv_buffer;}

	inline ParamBuffer * header_buffer() const
	{ return header_buffer_;}

	inline void set_header_buffer(ParamBuffer *header_buffer)
	{ header_buffer_ = header_buffer;}

	~Request();

private:
	ParamBuffer *send_buffer_; //< 发送缓冲区 /
	ParamBuffer *recv_buffer_; //< 接收缓冲区 /
	ParamBuffer *header_buffer_; //< 头部缓冲区 /
	
private:
	Request(const Request&);
	void operator=(const Request&);
};

} 

#endif // OSS_REQUEST_PARAM_H
