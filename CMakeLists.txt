cmake_minimum_required(VERSION 3.28)

set(projectName trainself)
set(appName trainself.exe)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(${projectName})

option(ENABLE_CONFIG_WINDOW "add configuration window in application" ON)

if(ENABLE_CONFIG_WINDOW)
	add_compile_definitions(CONFIG_WINDOW)
	message("configuration window: ENABLED")
else()
	message("configuration window: DISABLED")
endif()

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/extern/glfw/CMakeLists.txt")
    message(FATAL_ERROR
		"Submodules are not initialized. Run: git submodule update --init --recursive"
	)
endif()

add_subdirectory(external/glfw)
add_subdirectory(external/glad)
add_subdirectory(external/imgui)

set(SOURCES
	src/main.cpp
	src/core/AssetManager.cpp
	src/core/StateMachine.cpp
	src/states/MainState.cpp
	src/states/EditorState.cpp
)

add_executable(${appName} ${SOURCES})

if(
	(CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR
  	(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
)

target_compile_options(${appName} PRIVATE -Wall -g)

endif()

target_link_libraries(${appName}
	PRIVATE
		glfw
		glad
		imgui
)

target_include_directories(${appName}
   	PRIVATE
   		include
		include/states
		fonts
)

add_custom_command(TARGET ${appName} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_SOURCE_DIR}/fonts
	$<TARGET_FILE_DIR:${appName}>/fonts
	COMMENT "Copy fonts directory to build directory"
)
