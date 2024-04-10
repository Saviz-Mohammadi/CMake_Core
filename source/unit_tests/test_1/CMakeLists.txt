set(TEST_NAME "TEST_1")



set(HEADER_FILES

    "${CMAKE_CURRENT_SOURCE_DIR}/include/file.hpp")
	
set(SOURCE_FILES

    "${CMAKE_CURRENT_SOURCE_DIR}/src/file.cpp")



add_executable(${TEST_NAME})

# The reason why we have header filse in both below commands be private is because tests usually contain well... tests! So i don't see the point of exposing header files to the rest of the project that are just meant to solely test for stuff...



target_sources(${TEST_NAME}

    PRIVATE
    ${HEADER_FILES}

    PRIVATE
    ${SOURCE_FILES})

target_include_directories(${TEST_NAME}
	
    PRIVATE

    "${CMAKE_CURRENT_SOURCE_DIR}/include")



target_link_libraries(${TEST_NAME}

    PRIVATE
    ${EXTERNAL_LIBRARIES_TO_LINK})


gtest_discover_tests(${TEST_NAME})