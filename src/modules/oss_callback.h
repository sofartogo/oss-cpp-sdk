/*
 * =============================================================================
 *
 *       Filename:  oss_callback.h
 *
 *    Description:  curl callback routines.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#ifndef OSS_CALLBACK_H
#define OSS_CALLBACK_H
namespace osscpp {

class Callback {

	public:
		static unsigned int GeneralOperationSendCallback(
				void *ptr, unsigned int size,
				unsigned int nmemb, void *stream);

		static unsigned int GeneralOperationSendCallback2nd(
				void *ptr, unsigned int size,
				unsigned int nmemb, void *stream);

		static unsigned int GeneralOperationRecvCallback(
				void *ptr, unsigned int size,
				unsigned int nmemb, void *stream);
		
		static unsigned int GeneralOperationRecvCallback2nd(
				void *ptr, unsigned int size,
				unsigned int nmemb, void *stream);

		static unsigned int GeneralOperationHeaderCallback(
				void *ptr, unsigned int size,
				unsigned int nmemb, void *stream);

		static unsigned int GeneralOperationHeaderCallback2nd(
				void *ptr, unsigned int size,
				unsigned int nmemb, void *stream);
};

}

#endif // OSS_CALLBACK_H
