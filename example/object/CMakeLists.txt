INCLUDE_DIRECTORIES(
	${OSSCPP_BINARY_DIR}
	${OSSCPP_SOURCE_DIR}/include/
	${OSSCPP_SOURCE_DIR}/include/osscpp/util
	${OSSCPP_SOURCE_DIR}/include/osscpp/modules/
	${OSSCPP_SOURCE_DIR}/src/lib/
	${OSSCPP_SOURCE_DIR}/src/
	)

ADD_EXECUTABLE(copy_object copy_object.cc)
TARGET_LINK_LIBRARIES(copy_object osscppcore_static curl)

ADD_EXECUTABLE(copy_object_ext copy_object_ext.cc)
TARGET_LINK_LIBRARIES(copy_object_ext osscppcore_static curl)

ADD_EXECUTABLE(get_object_to_file get_object_to_file.cc)
TARGET_LINK_LIBRARIES(get_object_to_file osscppcore_static curl)

ADD_EXECUTABLE(get_object_metadata get_object_metadata.cc)
TARGET_LINK_LIBRARIES(get_object_metadata osscppcore_static curl)

ADD_EXECUTABLE(get_object_to_buffer get_object_to_buffer.cc)
TARGET_LINK_LIBRARIES(get_object_to_buffer osscppcore_static curl)

ADD_EXECUTABLE(delete_object delete_object.cc)
TARGET_LINK_LIBRARIES(delete_object osscppcore_static curl)

ADD_EXECUTABLE(delete_multiple_object delete_multiple_object.cc)
TARGET_LINK_LIBRARIES(delete_multiple_object osscppcore_static curl)

ADD_EXECUTABLE(put_object_from_buffer put_object_from_buffer.cc)
TARGET_LINK_LIBRARIES(put_object_from_buffer osscppcore_static curl)

ADD_EXECUTABLE(put_object_from_file put_object_from_file.cc)
TARGET_LINK_LIBRARIES(put_object_from_file osscppcore_static curl)

