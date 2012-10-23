INCLUDE_DIRECTORIES(
	${OSSCPP_BINARY_DIR}
	${OSSCPP_SOURCE_DIR}/include/
	${OSSCPP_SOURCE_DIR}/include/osscpp/util
	${OSSCPP_SOURCE_DIR}/include/osscpp/modules/
	${OSSCPP_SOURCE_DIR}/src/lib/
	${OSSCPP_SOURCE_DIR}/src/
	)

ADD_EXECUTABLE(abort_multipart_upload abort_multipart_upload.cc)
TARGET_LINK_LIBRARIES(abort_multipart_upload osscppcore_static curl)
#
ADD_EXECUTABLE(complete_multipart_upload complete_multipart_upload.cc)
TARGET_LINK_LIBRARIES(complete_multipart_upload osscppcore_static curl)
#
ADD_EXECUTABLE(initiate_multipart_upload initiate_multipart_upload.cc)
TARGET_LINK_LIBRARIES(initiate_multipart_upload osscppcore_static curl)
#
ADD_EXECUTABLE(list_multipart_upload list_multipart_upload.cc)
TARGET_LINK_LIBRARIES(list_multipart_upload osscppcore_static curl)
#
ADD_EXECUTABLE(list_parts list_parts.cc)
TARGET_LINK_LIBRARIES(list_parts osscppcore_static curl)
#
ADD_EXECUTABLE(upload_part upload_part.cc)
TARGET_LINK_LIBRARIES(upload_part osscppcore_static curl)
