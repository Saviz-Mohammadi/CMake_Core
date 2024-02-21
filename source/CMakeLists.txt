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

# You need to make sure that the corresponding libraries are downloaded
# and placed into their corresponding folder before trying to enable
# these options. Also make sure that your CMakeCache is reset.
	
option(USE_LIB_WXWIDGETS
	
    "Adds the library wxWidgets to the project"
    OFF)
	
option(USE_LIB_BOOST
	
    "Adds the library Boost to the project"
    OFF)

option(USE_LIB_CURL

    "Adds the library Curl to the project"
    OFF)

# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ Library options ]]





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

    "${CMAKE_CURRENT_LIST_DIR}/main.hpp")

set(SOURCE_FILES

    "${CMAKE_CURRENT_LIST_DIR}/main.cpp")



set_target_properties(${EXECUTABLE_NAME}
	
    PROPERTIES

    VERSION "${PROJECT_VERSION}")



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

set(EXTERNAL_EXTERNAL_LIBRARIES_TO_LINK)



if(USE_LIB_WXWIDGETS)

    set(wxWidgets_ROOT_DIR

        "${CMAKE_SOURCE_DIR}/lib/wxWidgets")

    set(wxWidgets_LIB_DIR

        "${CMAKE_SOURCE_DIR}/lib/wxWidgets/lib/..._dll/")

    set(wxWidgets_INCLUDE_DIRS

        "${CMAKE_SOURCE_DIR}/lib/wxWidgets/include")



    set(wxWidgets_USE_STATIC ON)
    set(wxWidgets_EXCLUDE_COMMON_LIBRARIES TRUE)
    set(wxWidgets_USE_UNICODE ON)



    find_package(wxWidgets REQUIRED gl core base)

    include(${wxWidgets_USE_FILE})

    list(APPEND EXTERNAL_LIBRARIES_TO_LINK ${wxWidgets_LIBRARIES})



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

	list(APPEND
	
            CMAKE_PREFIX_PATH

            "${CMAKE_SOURCE_DIR}/lib/Boost")



	set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
	set(Boost_USE_DEBUG_LIBS        OFF)  # ignore debug libs and
	set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
	set(Boost_USE_MULTITHREADED      ON)
	set(Boost_USE_STATIC_RUNTIME    OFF)
	


        find_package(Boost 1.66.0 COMPONENTS date_time filesystem system)
	
        include_directories(${Boost_INCLUDE_DIRS})

        list(APPEND EXTERNAL_LIBRARIES_TO_LINK ${Boost_LIBRARIES})

endif()



if(USE_LIB_CURL)

    list(APPEND

        CMAKE_PREFIX_PATH

        "${CMAKE_SOURCE_DIR}/lib/Curl")

    find_package(CURL REQUIRED)

    include_directories(${CURL_INCLUDE_DIRS})

    list(APPEND EXTERNAL_LIBRARIES_TO_LINK ${CURL_LIBRARIES})

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
