cmake_minimum_required(VERSION "3.27.0" FATAL_ERROR)


# DESCRIPTION:
# I am a very dumb student that simply wants to get passed my university stage of life.
# I found myself continously making projects on different platforms, IDE's, compilers, and environments and found myself screwing a lot with options and things I didn't understand well.
# As a result I put my big boy panths on and decided to create one Project template using CMake to resolve once and for all all of my needs. I understand that this is by no mean perfect nor acceptable.
# But, that is totally fine as all I want to achieve is something that does it all for me without me having to pull my hair out. So, here is a description of what I expect of this script/ project template being capable of doing
# and what things I have not figured out yet that I would highly appreciate if I can get some help with it. Any help, suggestions are highly appreciated as I have no clue what I am doing. If you find even the smallest incovinience or problem please let me know
# so that I can better myself and this script.


# [[ Project ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]

project("Application"
	
    VERSION 0.0.1

    DESCRIPTION "Application description"

    LANGUAGES CXX)

set(EXECUTABLE_NAME "${PROJECT_NAME}")



set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ Project ]]





# [[ Library options ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]

option(USE_LIB_DOXYGEN

    "Adds the library DOXYGEN to the project (Documentation library)"
    OFF)

option(USE_LIB_NLOHMANN_JSON

    "Adds the library nlohmann_json to the project (Jason interpreter library)"
    OFF)

option(USE_LIB_FMT

    "Adds the library fmt to the project (Formatting library)"
    OFF)

option(USE_LIB_SPDLOG

    "Adds the library spdlog to the project (Networking/HTPP library)"
    OFF)

option(USE_LIB_CXXOPTS

    "Adds the library cxxopts to the project (Command line Argument parser library)"
    OFF)

option(USE_LIB_GoogleTest

    "Adds the library Catch2 to the project (Unit testing library)"
    ON)

option(USE_LIB_WXWIDGETS
	
    "Adds the library spdlog to the project (Logging library)"
    OFF)
	
option(USE_LIB_BOOST
	
    "Adds the library Boost to the project (Utility library)"
    OFF)

option(USE_LIB_CURL

    "Adds the library Curl to the project (Networking/HTPP library)"
    OFF)

# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ Library options ]]





# [[ Clang-format ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]

find_program(CLANG_FORMAT_EXE
    NAMES "clang-format"
    DOC "Path to clang-format executable")

if(NOT CLANG_FORMAT_EXE)
    message(STATUS "Clang-Format not found.")
else()
    message(STATUS "Clang-Format found: ${CLANG_FORMAT_EXE}")
endif()


# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ Clang-format ]]





# [[ Resource system ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]

set(RESOURCE_TXT_FILES

    "file.txt")

set(RESOURCE_JSON_FILES

    "file.json")
	
set(RESOURCE_ICON_FILES

    "file.svg")

# Add more files as needed...

# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ Resource system ]]





# [[ Output Locations ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]

set(OUTPUT_DIRECTORY "")

set(CMAKE_BINARY_DIR "${CMAKE_SOURCE_DIR}/../build/bin")



if(CMAKE_SIZEOF_VOID_P EQUAL 8)

    set(OUTPUT_DIRECTORY

        "${CMAKE_BINARY_DIR}/${CMAKE_SYSTEM_NAME}/64-bit/")
endif()

if(CMAKE_SIZEOF_VOID_P EQUAL 4)

    set(OUTPUT_DIRECTORY

        "${CMAKE_BINARY_DIR}/${CMAKE_SYSTEM_NAME}/32-bit/")
endif()



set(CMAKE_RUNTIME_OUTPUT_DIRECTORY	# Defines executable path
	
    "${OUTPUT_DIRECTORY}/$<CONFIG>/executable")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY	# Defines shared lib path
	
    "${OUTPUT_DIRECTORY}/$<CONFIG>/executable")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY	# Defines static lib path
	
    "${OUTPUT_DIRECTORY}/$<CONFIG>/lib_static")

# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ Output Locations ]]





# [[ Executable Target ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]

add_executable(${EXECUTABLE_NAME})



set(HEADER_FILES

    "${CMAKE_CURRENT_SOURCE_DIR}/main.hpp")

set(SOURCE_FILES

    "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")

set_target_properties(${EXECUTABLE_NAME}

    PROPERTIES

    VERSION "${PROJECT_VERSION}")



target_sources(${EXECUTABLE_NAME}
	
    PUBLIC
    ${HEADER_FILES}

    PRIVATE
    ${SOURCE_FILES})



target_include_directories(${EXECUTABLE_NAME}

    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}")

# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ Executable Target ]]




# I keep hearing from different discussions on the internet that including the 
# "Compile options" and setting different compiler flags is a bad idea as CMake
# must only have enough insturctions to build the project and nothing more. These posts
# also say that things like this should be left to handle via a toolchain script.
# On the other hand, many developers actually believe it is good practice to specify these things 
# directly. I wanted to know what is your opinnion on this matter, should I keep this? Or do I just get rid of it?

# [[ Compile options ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]

# # Check if the compiler supports specific flags
# include(CheckCXXCompilerFlag)

# # Check for -Wall flag
# check_cxx_compiler_flag("-Wall" COMPILER_SUPPORTS_WALL)
# if(COMPILER_SUPPORTS_WALL)
#     add_compile_options(-Wall)
# endif()

# # Check for -Werror flag
# check_cxx_compiler_flag("-Werror" COMPILER_SUPPORTS_WERROR)
# if(COMPILER_SUPPORTS_WERROR)
#     add_compile_options(-Werror)
# endif()

# # Check for -Wno-error=maybe-uninitialized flag
# check_cxx_compiler_flag("-Wno-error=maybe-uninitialized" COMPILER_SUPPORTS_WNO_ERROR_MAYBE_UNINITIALIZED)
# if(COMPILER_SUPPORTS_WNO_ERROR_MAYBE_UNINITIALIZED)
#     add_compile_options(-Wno-error=maybe-uninitialized)
# endif()


# add_compile_options(
#        $<$<CONFIG:RELEASE>:-Ofast>
#        $<$<CONFIG:DEBUG>:-O0>
#        $<$<CONFIG:DEBUG>:-ggdb3>)

add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/Zc:wchar_t->")

# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ Compile options ]]





# [[ Compile Definitions ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]

if(CMAKE_SIZEOF_VOID_P EQUAL 8)

    target_compile_definitions(${EXECUTABLE_NAME}

        PUBLIC
        "TARGET_IS_64_BIT")
endif()

if(CMAKE_SIZEOF_VOID_P EQUAL 4)

    target_compile_definitions(${EXECUTABLE_NAME}

        PUBLIC
        "TARGET_IS_32_BIT")
endif()



target_compile_definitions(${EXECUTABLE_NAME}
	
    PUBLIC
	
    $<$<PLATFORM_ID:Linux>:TARGET_IS_LINUX>
    $<$<PLATFORM_ID:Darwin>:TARGET_IS_APPLE>
    $<$<PLATFORM_ID:Windows>:TARGET_IS_WINDOWS>)

target_compile_definitions(${EXECUTABLE_NAME}
	
    PUBLIC
	
    $<$<CONFIG:Debug>:DEBUG_MODE>
    $<$<CONFIG:Release>:RELEASE_MODE>
    $<$<CONFIG:RelWithDebInfo>:RELEASE_WITH_DEBUGINFO_MODE>
    $<$<CONFIG:MinSizeRel>:RELEASE_MINSIZE_MODE>)

# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ Compile Definitions ]]





# [[ External libraries ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]

set(EXTERNAL_LIBRARIES_TO_LINK)



include(FetchContent)



set(FETCHCONTENT_FULLY_DISCONNECTED OFF)    # Skips the DOWNLOAD and UPDATE steps
set(FETCHCONTENT_UPDATES_DISCONNECTED OFF)  # Skips the UPDATE step
set(FETCHCONTENT_QUIET ON)                  # Mute output logs



if(USE_LIB_DOXYGEN)

    find_package(Doxygen REQUIRED)

    set(DOXYGEN_GENERATE_HTML YES)
    set(DOXYGEN_HTML_OUTPUT "${CMAKE_BINARY_DIR}/doxygen") # See what is wrong with this.
    set(DOXYGEN_GENERATE_TREEVIEW YES)

    doxygen_add_docs(documentation

        "${PROJECT_SOURCE_DIR}"
        ALL # WHY DOES THIS OPTION FIX IT?
        COMMENT "Generating documentation")

endif()



if(USE_LIB_NLOHMANN_JSON)

    FetchContent_Declare(nlohmann_json

        GIT_REPOSITORY https://github.com/nlohmann/json
        GIT_TAG v3.11.2
        GIT_SHALLOW TRUE)

    FetchContent_MakeAvailable(nlohmann_json)

    list(APPEND

        EXTERNAL_LIBRARIES_TO_LINK

        nlohmann_json::nlohmann_json)

endif()



if(USE_LIB_FMT)

    FetchContent_Declare(fmt

        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG 9.1.0
        GIT_SHALLOW TRUE)

    FetchContent_MakeAvailable(fmt)

    list(APPEND

        EXTERNAL_LIBRARIES_TO_LINK

        fmt::fmt)

endif()



if(USE_LIB_SPDLOG)

    FetchContent_Declare(spdlog

        GIT_REPOSITORY https://github.com/gabime/spdlog
        GIT_TAG v1.11.0
        GIT_SHALLOW TRUE)

    FetchContent_MakeAvailable(spdlog)

    list(APPEND

        EXTERNAL_LIBRARIES_TO_LINK

        spdlog::spdlog)

endif()



if(USE_LIB_CXXOPTS)

    FetchContent_Declare(cxxopts

        GIT_REPOSITORY https://github.com/jarro2783/cxxopts
        GIT_TAG v3.0.0
        GIT_SHALLOW TRUE)

    FetchContent_MakeAvailable(cxxopts)

    list(APPEND

        EXTERNAL_LIBRARIES_TO_LINK

        cxxopts::cxxopts)

endif()



if(USE_LIB_GoogleTest)

    FetchContent_Declare(GoogleTest

        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG v1.14.0
        GIT_SHALLOW TRUE)

    FetchContent_MakeAvailable(GoogleTest)

    enable_testing()

    list(APPEND

        EXTERNAL_LIBRARIES_TO_LINK

        GTest::gtest_main
        GTest::gmock_main)

endif()



if(USE_LIB_WXWIDGETS)

    set(wxWidgets_USE_STATIC 1)
    set(wxBUILD_SHARED OFF)

    FetchContent_Declare(wxWidgets

       GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets.git
       GIT_TAG v3.2.1
       GIT_SHALLOW TRUE)

    FetchContent_MakeAvailable(wxWidgets)


    list(APPEND

        EXTERNAL_LIBRARIES_TO_LINK

        wx::base
        wx::core
        wx::adv
        wx::aui
        wx::propgrid
        wx::richtext
        wx::stc
        wx::html
        wx::media
        wx::net
        wx::webview
        wx::xml
        wx::qa
        wx::gl
        wx::ribbon
        wx::xrc)


    if(CMAKE_SIZEOF_VOID_P EQUAL 8)

        set_target_properties(${EXECUTABLE_NAME}

            PROPERTIES

            WIN64_EXECUTABLE TRUE)
    endif()

    if(CMAKE_SIZEOF_VOID_P EQUAL 4)

        set_target_properties(${EXECUTABLE_NAME}

            PROPERTIES

            WIN32_EXECUTABLE TRUE)
    endif()

endif()



if(USE_LIB_BOOST)

    FetchContent_Declare(Boost

        GIT_REPOSITORY https://github.com/boostorg/boost.git
        GIT_TAG boost-1.80.0
        GIT_SHALLOW TRUE)

    FetchContent_MakeAvailable(Boost)

    list(APPEND

        EXTERNAL_LIBRARIES_TO_LINK

        Boost::filesystem
        Boost::system
        Boost::regex
        Boost::date_time
        Boost::thread
        Boost::coroutine
        Boost::chrono
        Boost::atomic
        Boost::program_options
        Boost::unit_test_framework
        Boost::log
        Boost::serialization
        Boost::math
        Boost::random
        Boost::uuid
        Boost::signals2
        Boost::asio
        Boost::graph
        Boost::property_tree
        Boost::mpi)

endif()



if(USE_LIB_CURL)

    FetchContent_Declare(curl

        URL https://curl.se/download/curl-8.5.0.tar.gz
        DOWNLOAD_EXTRACT_TIMESTAMP true)

    FetchContent_MakeAvailable(curl)
	
	# A full list of options can be seen here:
	# https://github.com/curl/curl/blob/5ce164e0e9290c96eb7d502173426c0a135ec008/CMakeLists.txt#L84C1-L91C77
	
	set(BUILD_STATIC_LIBS ON)
	

    list(APPEND

        EXTERNAL_LIBRARIES_TO_LINK

        CURL::libcurl_static)

endif()

# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ External libraries ]]





# [[ Modules ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]

add_subdirectory(modules)



target_link_libraries(${EXECUTABLE_NAME}

    # Libraries
    PRIVATE
    ${EXTERNAL_LIBRARIES_TO_LINK}

    # Modules
    PRIVATE
    LIB_1)

# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ Modules ]]



# [[ Modules ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]


if(USE_LIB_GoogleTest)
    include(GoogleTest)
    add_subdirectory(unit_tests)
endif()

# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ Modules ]]




# [[ Custom targets ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]


# As expected, .clang-format will only be applied when you actuall press build. since
# it is a dpendencie that gets called only after building the target. I am still trying
# to find a way to make it complete on pressing save, but it seems to be tricky.
if(CLANG_FORMAT_EXE)
    file(GLOB_RECURSE ALL_FILES
        "${CMAKE_SOURCE_DIR}/*.cpp"
        "${CMAKE_SOURCE_DIR}/*.hpp"
        "${CMAKE_SOURCE_DIR}/*.h"
    )

    message(STATUS "Found source files: ${ALL_FILES}")

    add_custom_target(
        format
        COMMAND ${CLANG_FORMAT_EXE} -i -style=file ${ALL_FILES}
        COMMENT "Running clang-format on all source files"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}  # Set the working directory for the command
    )

    add_dependencies(${EXECUTABLE_NAME} format)
endif()


add_custom_target(CopyResourceFiles_TXT

    COMMENT "Copying resource files to output directory")

foreach(RESOURCE_FILE ${RESOURCE_TXT_FILES})
    message(STATUS "Copying ${RESOURCE_FILE} to output directory")

    add_custom_command(TARGET CopyResourceFiles_TXT POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/resources/txt/${RESOURCE_TXT_FILES}"
        "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources/txt/${RESOURCE_FILE}"
        COMMENT "Copying ${RESOURCE_FILE} to output directory")
endforeach()


add_custom_target(CopyResourceFiles_JSON

    COMMENT "Copying resource files to output directory")

foreach(RESOURCE_FILE ${RESOURCE_JSON_FILES})
    message(STATUS "Copying ${RESOURCE_FILE} to output directory")

    add_custom_command(TARGET CopyResourceFiles_JSON POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/resources/json/${RESOURCE_JSON_FILES}"
        "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources/json/${RESOURCE_FILE}"
        COMMENT "Copying ${RESOURCE_FILE} to output directory")
endforeach()


add_custom_target(CopyResourceFiles_ICON

    COMMENT "Copying resource files to output directory")

foreach(RESOURCE_FILE ${RESOURCE_ICON_FILES})
    message(STATUS "Copying ${RESOURCE_FILE} to output directory")

    add_custom_command(TARGET CopyResourceFiles_ICON POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/resources/icons/${RESOURCE_ICON_FILES}"
        "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources/icons/${RESOURCE_FILE}"
        COMMENT "Copying ${RESOURCE_FILE} to output directory")
endforeach()


add_dependencies(${EXECUTABLE_NAME} CopyResourceFiles_TXT)
add_dependencies(${EXECUTABLE_NAME} CopyResourceFiles_JSON)
add_dependencies(${EXECUTABLE_NAME} CopyResourceFiles_ICON)



# Copy DLL files to binary dir if we are dealing with windows. Unix platforms (mac, linux) use something called RPATH by default
if(WIN32)
    
	# This command will do fine as long as other projects/libs have set property to SHARED.
	# But, many of them have it set to UNKNOWN. So, what do we do if this command does not find all the dll's?
	add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different
		$<TARGET_RUNTIME_DLLS:${EXECUTABLE_NAME}>
		$<TARGET_FILE_DIR:${EXECUTABLE_NAME}>
		COMMAND_EXPAND_LISTS
		COMMENT "Copying DLLs to target directory")
endif()

# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ Custom targets ]]
