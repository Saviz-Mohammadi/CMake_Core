cmake_minimum_required(VERSION "3.27.0" FATAL_ERROR)


project("Application"
	
	VERSION 0.0.1
	
	DESCRIPTION "Application description"
	
	LANGUAGES CXX)


set(EXECUTABLE_NAME
	
	"${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD
	
	17)
	
set(CMAKE_CXX_STANDARD_REQUIRED
	
	ON)
	
set(CMAKE_CXX_EXTENSIONS
	
	OFF)




# [[ Library options ]]
# [[ ----------------------------------------------------------------------- ]]

option(USE_LIB_SFML
	
	"Adds the library SFML to the project"
	OFF)
	
option(USE_LIB_WXWIDGETS
	
	"Adds the library wxWidgets to the project"
	OFF)
	
option(USE_LIB_BOOST
	
	"Adds the library Boost to the project"
	OFF)

# [[ ----------------------------------------------------------------------- ]]
# [[ Library options ]]




# [[ Output Locations ]]
# [[ ----------------------------------------------------------------------- ]]

set(OUTPUT_DIRECTORY
	
	"")


set(CMAKE_BINARY_DIR
	
	"${CMAKE_SOURCE_DIR}/../build/bin")


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
# [[ Output Locations ]]




# [[ Executable Target ]]
# [[ ----------------------------------------------------------------------- ]]

add_executable(${EXECUTABLE_NAME})


set_target_properties(${EXECUTABLE_NAME}
	
	PROPERTIES
	
	VERSION "${PROJECT_VERSION}")


target_sources(${EXECUTABLE_NAME}
	
	PRIVATE
	
	"${CMAKE_CURRENT_LIST_DIR}/main.cpp")

# [[ ----------------------------------------------------------------------- ]]
# [[ Executable Target ]]




# [[ Compile Definitions ]]
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


target_compile_definitions(

	${EXECUTABLE_NAME}
	
    PUBLIC
	
	$<$<PLATFORM_ID:Linux>:TARGET_IS_LINUX>
	$<$<PLATFORM_ID:Darwin>:TARGET_IS_APPLE>
	$<$<PLATFORM_ID:Windows>:TARGET_IS_WINDOWS>)


target_compile_definitions(

	${EXECUTABLE_NAME}
	
    PUBLIC
	
	$<$<CONFIG:Debug>:DEBUG_MODE>
	$<$<CONFIG:Release>:RELEASE_MODE>
	$<$<CONFIG:RelWithDebInfo>:RELEASE_WITH_DEBUGINFO_MODE>
	$<$<CONFIG:MinSizeRel>:RELEASE_MINSIZE_MODE>)

# [[ ----------------------------------------------------------------------- ]]
# [[ Compile Definitions ]]




# [[ Modules ]]
# [[ ----------------------------------------------------------------------- ]]

add_subdirectory(modules)

target_link_libraries(${EXECUTABLE_NAME}
    
	PUBLIC
	
	LIB_1)

# [[ ----------------------------------------------------------------------- ]]
# [[ Modules ]]




# [[ 3rd Party Libs ]]
# [[ ----------------------------------------------------------------------- ]]

if(USE_LIB_SFML)
	
	list(APPEND
	
		CMAKE_PREFIX_PATH
		
		"${CMAKE_SOURCE_DIR}/lib/SFML")

	set(SFML_STATIC_LIBRARIES
	
		TRUE)

	find_package(SFML
		
		2.6.0
		
		REQUIRED COMPONENTS
		
		audio
		network
		graphics
		window
		system
		main
		
		NO_MODULE)

	target_link_libraries(${EXECUTABLE_NAME}
		
		PUBLIC
		
		sfml-audio
		sfml-network
		sfml-graphics
		sfml-window
		sfml-system
		sfml-main)
	
	set_target_properties(${EXECUTABLE_NAME}
		
		PROPERTIES
		
		WIN32_EXECUTABLE TRUE)
endif()


if(USE_LIB_WXWIDGETS)

	set(wxWidgets_ROOT_DIR
		
		"${CMAKE_SOURCE_DIR}/lib/wxWidgets")

	set(wxWidgets_EXCLUDE_COMMON_LIBRARIES
	
		TRUE)

	find_package(wxWidgets
		
		REQUIRED
		
		gl
		core
		base)

	include(${wxWidgets_USE_FILE})

	target_link_libraries(${EXECUTABLE_NAME}
		
		${wxWidgets_LIBRARIES})

	set_target_properties(${EXECUTABLE_NAME}
		
		PROPERTIES
		
		WIN32_EXECUTABLE TRUE)
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
	
	find_package(Boost
		
		1.66.0
		
		COMPONENTS
		
		date_time
		filesystem
		system)
	
	if(Boost_FOUND)
	
		include_directories(${Boost_INCLUDE_DIRS})
		
		target_link_libraries(${EXECUTABLE_NAME}
			
			${Boost_LIBRARIES})
	endif()

endif()

# [[ ----------------------------------------------------------------------- ]]
# [[ 3rd Party Libs ]]




# [[ Logging ]]
# [[ ----------------------------------------------------------------------- ]]

message("\n")
message("[[ ---------------------- Configuration ------------------------- ]]")
message("\n")


message(STATUS

	"Provided name for Project:\t\t\t ${PROJECT_NAME}")
	
message(STATUS
	
	"Provided name for Executable:\t\t ${EXECUTABLE_NAME}")


message("")


cmake_host_system_information(RESULT HOST_NAME
	
	QUERY OS_NAME)

cmake_host_system_information(RESULT HOST_IS_64BIT
	
	QUERY IS_64BIT)


message(STATUS

	"Host operating system name is:\t\t ${HOST_NAME}")


if(HOST_IS_64BIT EQUAL 1)

	message(STATUS

		"Host operating system platform is:\t\t 64-bit")
else()

	message(STATUS

		"Host operating system architecture is:\t\t 32-bit")
endif()


message("")


message(STATUS

	"Target operating system name is:\t\t ${CMAKE_SYSTEM_NAME}")


if(CMAKE_SIZEOF_VOID_P EQUAL 8) # 64-bit systems

	message(STATUS
		
		"Target operating system platform is:\t\t 64-bit")
endif()


if(CMAKE_SIZEOF_VOID_P EQUAL 4) # 32-bit systems

	message(STATUS
		
		"Target operating system platform is:\t\t 32-bit")	
endif()


message("")


get_property(IS_MULTI_CONFIG GLOBAL

	PROPERTY
	
	GENERATOR_IS_MULTI_CONFIG)


if(IS_MULTI_CONFIG)

	message(STATUS
		
		"THE BUILD_TYPE:\t\t\t\t Generator is multi-config.")
else()

	message(STATUS
		
		"The BUILD_TYPE:\t\t\t ${CMAKE_BUILD_TYPE}")
endif()


message("")


message(STATUS
	
	"The SOURCE_DIR folder path is:\t\t ${CMAKE_SOURCE_DIR}")

message(STATUS
	
	"The BINARY_DIR folder path is:\t\t ${CMAKE_BINARY_DIR}")


message("\n")
message("[[ ---------------------- Configuration ------------------------- ]]")
message("\n")

# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ Logging ]]