cmake_minimum_required(VERSION 3.28)

set(projectName trainself)
set(appName hello)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(${projectName})

add_subdirectory(external/glfw)
add_subdirectory(external/glad)
add_subdirectory(external/imgui)

set(SOURCES
	src/main.cpp
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
)
