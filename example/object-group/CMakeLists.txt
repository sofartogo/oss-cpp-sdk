INCLUDE_DIRECTORIES(
	${OSSCPP_BINARY_DIR}
	${OSSCPP_SOURCE_DIR}/include/
	${OSSCPP_SOURCE_DIR}/include/osscpp/util
	${OSSCPP_SOURCE_DIR}/include/osscpp/modules/
	${OSSCPP_SOURCE_DIR}/src/lib/
	${OSSCPP_SOURCE_DIR}/src/
	)

ADD_EXECUTABLE(post_object_group post_object_group.cc)
TARGET_LINK_LIBRARIES(post_object_group osscppcore_static curl)

ADD_EXECUTABLE(get_object_group_to_buffer get_object_group_to_buffer.cc)
TARGET_LINK_LIBRARIES(get_object_group_to_buffer osscppcore_static curl)

ADD_EXECUTABLE(get_object_group_to_file get_object_group_to_file.cc)
TARGET_LINK_LIBRARIES(get_object_group_to_file osscppcore_static curl)

ADD_EXECUTABLE(get_object_group_index get_object_group_index.cc)
TARGET_LINK_LIBRARIES(get_object_group_index osscppcore_static curl)

ADD_EXECUTABLE(head_object_group head_object_group.cc)
TARGET_LINK_LIBRARIES(head_object_group osscppcore_static curl)

ADD_EXECUTABLE(delete_object_group delete_object_group.cc)
TARGET_LINK_LIBRARIES(delete_object_group osscppcore_static curl)

