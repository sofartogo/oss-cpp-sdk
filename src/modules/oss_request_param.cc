/*
 * =============================================================================
 *
 *       Filename:  oss_request_param.cc
 *
 *    Description:  oss request parameter utility.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

#include "oss_request_param.h"

#define _OSS_CLIENT_H
#include <osscpp/modules/oss_client.h>
#undef _OSS_CLIENT_H

namespace osscpp {

Request::Request()
{
	send_buffer_ = (ParamBuffer *) malloc(sizeof(ParamBuffer));
	if (send_buffer_ == NULL) exit(-1);
	memset(send_buffer_, 0, sizeof(ParamBuffer));
	send_buffer_->ptr = new char[MAX_SEND_BUFFER_SIZE];
	memset(send_buffer_->ptr, 0, MAX_SEND_BUFFER_SIZE);
	send_buffer_->left = MAX_SEND_BUFFER_SIZE;
	send_buffer_->allocated = MAX_SEND_BUFFER_SIZE;
	send_buffer_->code = -1;

	recv_buffer_ = (ParamBuffer *) malloc(sizeof(ParamBuffer));
	if (recv_buffer_ == NULL) exit(-1);
	memset(recv_buffer_, 0, sizeof(ParamBuffer));
	recv_buffer_->ptr = new char[MAX_RECV_BUFFER_SIZE];
	memset(recv_buffer_->ptr, 0, MAX_RECV_BUFFER_SIZE);
	recv_buffer_->left = MAX_RECV_BUFFER_SIZE;
	recv_buffer_->allocated = MAX_RECV_BUFFER_SIZE;
	recv_buffer_->code = -1;

	header_buffer_ = (ParamBuffer *) malloc(sizeof(ParamBuffer));
	if (header_buffer_ == NULL) exit(-1);
	memset(header_buffer_, 0, sizeof(ParamBuffer));
	header_buffer_->ptr = new char[MAX_HEADER_BUFFER_SIZE];
	memset(header_buffer_->ptr, 0, MAX_HEADER_BUFFER_SIZE);
	header_buffer_->left = MAX_HEADER_BUFFER_SIZE;
	header_buffer_->allocated = MAX_HEADER_BUFFER_SIZE;
	header_buffer_->code = -1;

}

Request::Request(
		unsigned int snd_buffer_size = MAX_SEND_BUFFER_SIZE,
		unsigned int rcv_buffer_size = MAX_RECV_BUFFER_SIZE,
		unsigned int hdr_buffer_size = MAX_HEADER_BUFFER_SIZE)
{

	if (snd_buffer_size > 0) {
		send_buffer_ = (ParamBuffer *) malloc(sizeof(ParamBuffer));
		if (send_buffer_ == NULL) exit(-1);
		memset(send_buffer_, 0, sizeof(ParamBuffer));
		send_buffer_->ptr = new char[snd_buffer_size];
		memset(send_buffer_->ptr, 0, snd_buffer_size);
		send_buffer_->left = snd_buffer_size;
		send_buffer_->allocated = snd_buffer_size;
		send_buffer_->code = -1;
	} else {
		send_buffer_ = (ParamBuffer *) malloc(sizeof(ParamBuffer));
		if (send_buffer_ == NULL) exit(-1);
		memset(send_buffer_, 0, sizeof(ParamBuffer));
		send_buffer_->ptr = NULL;
		send_buffer_->left = 0;
		send_buffer_->allocated = 0;
		send_buffer_->code = -1;
	}

	if (rcv_buffer_size > 0) {
		recv_buffer_ = (ParamBuffer *) malloc(sizeof(ParamBuffer));
		if (recv_buffer_ == NULL) exit(-1);
		memset(recv_buffer_, 0, sizeof(ParamBuffer));
		recv_buffer_->ptr = new char[rcv_buffer_size];
		memset(recv_buffer_->ptr, 0, rcv_buffer_size);
		recv_buffer_->left = rcv_buffer_size;
		recv_buffer_->allocated = rcv_buffer_size;
		recv_buffer_->code = -1;
	} else {
		recv_buffer_ = (ParamBuffer *) malloc(sizeof(ParamBuffer));
		if (recv_buffer_ == NULL) exit(-1);
		memset(recv_buffer_, 0, sizeof(ParamBuffer));
		recv_buffer_->ptr = NULL;
		recv_buffer_->left = 0;
		recv_buffer_->allocated = 0;
		recv_buffer_->code = -1;
	}

	header_buffer_ = (ParamBuffer *) malloc(sizeof(ParamBuffer));
	if (header_buffer_ == NULL) exit(-1);
	memset(header_buffer_, 0, sizeof(ParamBuffer));
	header_buffer_->ptr = new char[hdr_buffer_size];
	memset(header_buffer_->ptr, 0, hdr_buffer_size);
	header_buffer_->left = hdr_buffer_size;
	header_buffer_->allocated = hdr_buffer_size;
	header_buffer_->code = -1;
}

Request::~Request()
{
	if (send_buffer_ != NULL) {
		if (send_buffer_->ptr != NULL) {
			delete send_buffer_->ptr;
			send_buffer_->ptr = NULL;
		}
		free(send_buffer_);
		send_buffer_ = NULL;
	}

	if (recv_buffer_!= NULL) {
		if (recv_buffer_->ptr != NULL) {
			delete recv_buffer_->ptr;
			recv_buffer_->ptr = NULL;
		}
		free(recv_buffer_);
		recv_buffer_= NULL;
	}

	if (header_buffer_!= NULL) {
		if (header_buffer_->ptr != NULL) {
			delete header_buffer_->ptr;
			header_buffer_->ptr = NULL;
		}
		free(header_buffer_);
		header_buffer_ = NULL;
	}
}

}
