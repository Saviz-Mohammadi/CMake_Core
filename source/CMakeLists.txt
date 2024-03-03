cmake_minimum_required(VERSION "3.27.0" FATAL_ERROR)





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

option(USE_LIB_CATCH2

    "Adds the library Catch2 to the project (Unit testing library)"
    OFF)

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





# [[ Resource files for copying ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]

set(RESOURCE_FILES

    "file.txt")

# Add more files as needed (Image files, Text files, etc...)

# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ Resource files for copying ]]





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



if(USE_LIB_WXWIDGETS)

    list(APPEND SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/resources/wx.rc")

endif()



target_sources(${EXECUTABLE_NAME}
	
    PUBLIC
    ${HEADER_FILES}

    PRIVATE
    ${SOURCE_FILES}
    )



target_include_directories(${EXECUTABLE_NAME}

    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}")

# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ Executable Target ]]





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



if(USE_LIB_CATCH2)

    FetchContent_Declare(Catch2

        GIT_REPOSITORY https://github.com/catchorg/Catch2
        GIT_TAG v2.13.9
        GIT_SHALLOW TRUE)

    FetchContent_MakeAvailable(Catch2)

    list(APPEND

        EXTERNAL_LIBRARIES_TO_LINK

        cxxopts::cxxopts)

endif()



if(USE_LIB_WXWIDGETS)

    set(wxWidgets_USE_STATIC 1)
    set(wxBUILD_SHARED OFF)

    FetchContent_Declare(wxWidgets

       GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets.git
       GIT_TAG v3.2.1
    )

    FetchContent_GetProperties(wxwidgets)



    if(NOT wxwidgets_POPULATED)
       FetchContent_Populate(wxwidgets)
       add_subdirectory(${wxwidgets_SOURCE_DIR} "C:/Users/Saviz/Desktop/CMake_Core/build/bin/_deps/wxwidgets-build")
    endif()


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
        wx::charts
        wx::grid
        wx::printout
        wx::svg
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

endif()



if(USE_LIB_CURL)

    FetchContent_Declare(curl

        GIT_REPOSITORY https://github.com/curl/curl
        GIT_TAG curl-8_6_0
        GIT_SHALLOW TRUE)

    FetchContent_MakeAvailable(curl)

    list(APPEND

        EXTERNAL_LIBRARIES_TO_LINK

        CURL::curl
        CURL::libcurl)

endif()

# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ External libraries ]]





# [[ Modules ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]

add_subdirectory(modules)



target_link_libraries(${EXECUTABLE_NAME}

    PRIVATE
    ${EXTERNAL_LIBRARIES_TO_LINK}

    PRIVATE
    LIB_1)

# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ Modules ]]





# [[ Custom targets ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]

add_custom_target(CopyResourceFiles

    COMMENT "Copying resource files to output directory")

# Loop over the list of resource files and add copy commands for each file
foreach(RESOURCE_FILES ${RESOURCE_FILESS})

    add_custom_command(TARGET CopyResourceFiles POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/resources/${RESOURCE_FILES}"
        "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources/${RESOURCE_FILES}"
        COMMENT "Copying ${RESOURCE_FILES} to output directory")

endforeach()

add_dependencies(${EXECUTABLE_NAME} CopyResourceFiles)



add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_RUNTIME_DLLS:${EXECUTABLE_NAME}>
        $<TARGET_FILE_DIR:${EXECUTABLE_NAME}>
    COMMENT "Copying DLLs to target directory")



if(USE_LIB_CURL)

    add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CURL_LIBRARY_DIR}/curl-ca-bundle.crt"
        $<TARGET_FILE_DIR:${EXECUTABLE_NAME}>
        COMMENT "Copying curl-ca-bundle.crt to target directory")

endif()

# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ Custom targets ]]
