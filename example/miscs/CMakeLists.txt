INCLUDE_DIRECTORIES(
	${OSSCPP_BINARY_DIR}
	${OSSCPP_SOURCE_DIR}/include/
	${OSSCPP_SOURCE_DIR}/include/osscpp/util
	${OSSCPP_SOURCE_DIR}/include/osscpp/modules/
	${OSSCPP_SOURCE_DIR}/src/util/
	${OSSCPP_SOURCE_DIR}/src/lib/
	${OSSCPP_SOURCE_DIR}/src/
	)

ADD_EXECUTABLE(generate_presigned_url_with_expiration generate_presigned_url_with_expiration.cc)
TARGET_LINK_LIBRARIES(generate_presigned_url_with_expiration osscppcore_static curl)

ADD_EXECUTABLE(generate_presigned_url_with_method generate_presigned_url_with_method.cc)
TARGET_LINK_LIBRARIES(generate_presigned_url_with_method osscppcore_static curl)

