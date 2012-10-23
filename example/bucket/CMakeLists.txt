INCLUDE_DIRECTORIES(
	${OSSCPP_BINARY_DIR}
	${OSSCPP_SOURCE_DIR}/include/
	${OSSCPP_SOURCE_DIR}/include/osscpp/util
	${OSSCPP_SOURCE_DIR}/include/osscpp/modules/
	${OSSCPP_SOURCE_DIR}/src/lib/
	${OSSCPP_SOURCE_DIR}/src/
	)

ADD_EXECUTABLE(create_bucket create_bucket.cc)
TARGET_LINK_LIBRARIES(create_bucket osscppcore_static curl)

ADD_EXECUTABLE(list_buckets list_buckets.cc)
TARGET_LINK_LIBRARIES(list_buckets osscppcore_static curl)

ADD_EXECUTABLE(set_bucket_acl set_bucket_acl.cc)
TARGET_LINK_LIBRARIES(set_bucket_acl osscppcore_static curl)

ADD_EXECUTABLE(get_bucket_acl get_bucket_acl.cc)
TARGET_LINK_LIBRARIES(get_bucket_acl osscppcore_static curl)

ADD_EXECUTABLE(list_objects_with_bucket_name list_objects_with_bucket_name.cc)
TARGET_LINK_LIBRARIES(list_objects_with_bucket_name osscppcore_static curl)

ADD_EXECUTABLE(list_objects_with_prefix list_objects_with_prefix.cc)
TARGET_LINK_LIBRARIES(list_objects_with_prefix osscppcore_static curl)

ADD_EXECUTABLE(list_objects_with_request list_objects_with_request.cc)
TARGET_LINK_LIBRARIES(list_objects_with_request osscppcore_static curl)

ADD_EXECUTABLE(is_bucket_exist is_bucket_exist.cc)
TARGET_LINK_LIBRARIES(is_bucket_exist osscppcore_static curl)

ADD_EXECUTABLE(delete_bucket delete_bucket.cc)
TARGET_LINK_LIBRARIES(delete_bucket osscppcore_static curl)


