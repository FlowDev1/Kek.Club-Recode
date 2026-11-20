cmake_minimum_required (VERSION 3.24)

project ("Recode")

set(CMAKE_CXX_STANDARD 23)

add_compile_options(/GR-)

add_compile_definitions(_HAS_STATIC_RTTI=0)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:DLL>")

include(Includes/FetchLibraries.cmake)

set(CMAKE_COMPILE_WARNING_AS_ERROR ON)
add_subdirectory(Client)
