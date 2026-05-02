cmake_minimum_required(VERSION 3.15)

set(projectName trainself)
set(appName trainself)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(${projectName})

option(ENABLE_CONFIG_WINDOW "add configuration window in application" ON)
option(ENABLE_TESTS "build tests" ON)


if(ENABLE_CONFIG_WINDOW)
	add_compile_definitions(CONFIG_WINDOW)
	message("configuration window: ENABLED")
else()
	message("configuration window: DISABLED")
endif()

if(ENABLE_TESTS)
	add_compile_definitions(DEBUG_TESTS)
	message("build tests: ENABLED")
else()
	message("build tests: DISABLED")
endif()


if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
    message(FATAL_ERROR
		"Submodules are not initialized. Run: git submodule update --init --recursive"
	)
endif()


add_subdirectory(external/glfw)
add_subdirectory(external/glad)
add_subdirectory(external/imgui)


set(SOURCES
	src/loadSourceManager.cpp
	src/core/AssetManager.cpp
	src/core/ProductUI.cpp
	src/core/StateMachine.cpp
	src/states/MainState.cpp
	src/states/EditorState.cpp
)

add_executable(${appName} ${SOURCES} src/main.cpp)

set(EXTERN_LIBS
	glfw
	glad
	imgui
)


target_link_libraries(${appName} PRIVATE ${EXTERN_LIBS})

target_include_directories(${appName}
   	PRIVATE
   		include
		fonts
)

if(
	(CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR
  	(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
)

target_compile_options(${appName} PRIVATE -Wall -g)

endif()


if(ENABLE_TESTS)
	add_subdirectory(external/googletest)

	add_library(srcLib STATIC ${SOURCES})

	target_include_directories(srcLib
		PUBLIC
			${CMAKE_SOURCE_DIR}/include
		PRIVATE
			${CMAKE_SOURCE_DIR}/src
	)

	target_link_libraries(srcLib PUBLIC	${EXTERN_LIBS})

	enable_testing()
	add_subdirectory(tests)
endif()


add_custom_command(TARGET ${appName} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_SOURCE_DIR}/fonts
	$<TARGET_FILE_DIR:${appName}>/fonts
	COMMENT "Copy fonts directory to build directory"
)
