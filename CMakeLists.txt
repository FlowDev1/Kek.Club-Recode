cmake_minimum_required (VERSION 3.24)

project ("Recode")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

add_compile_options(/GR-)

add_compile_definitions(_HAS_STATIC_RTTI=0)

include(Includes/FetchLibraries.cmake)

add_subdirectory(Client)

set_property(
	TARGET Client libhat minhook zasm spdlog glm
	PROPERTY MSVC_RUNTIME_LIBRARY
	# Use /MD (dynamic linking) in debug mode and /MT (static linking) in release
	$<$<CONFIG:Debug>:MultiThreadedDLL>$<$<CONFIG:Release>:MultiThreaded>
)