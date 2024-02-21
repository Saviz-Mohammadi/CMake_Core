set(LIBRARY_NAME "LIB_1")



set(HEADER_FILES

    "${CMAKE_CURRENT_SOURCE_DIR}/include/file.hpp")
	
set(SOURCE_FILES

    "${CMAKE_CURRENT_SOURCE_DIR}/src/file.cpp")



add_library(${LIBRARY_NAME} STATIC)

target_sources(${LIBRARY_NAME}

    PUBLIC
    ${HEADER_FILES}

    PRIVATE
    ${SOURCE_FILES})

target_include_directories(${LIBRARY_NAME}
	
    PUBLIC

    "${CMAKE_CURRENT_SOURCE_DIR}/include")



set(LIBRARIES_TO_LINK)

if(Boost_FOUND)
    list(APPEND LIBRARIES_TO_LINK ${Boost_LIBRARIES})
endif()

if(wxWidgets_FOUND)
    list(APPEND LIBRARIES_TO_LINK ${wxWidgets_LIBRARIES})
endif()

if(CURL_FOUND)
    list(APPEND LIBRARIES_TO_LINK ${CURL_LIBRARIES})
endif()



target_link_libraries(${LIBRARY_NAME}

    PRIVATE
    ${LIBRARIES_TO_LINK})
