file(GLOB_RECURSE CLIENT_SOURCES CONFIGURE_DEPENDS "src/*.cpp" "src/*.hpp")

add_library(Client SHARED
	${CLIENT_SOURCES}
)

target_link_libraries(Client PRIVATE safetyhook libhat EnTT::EnTT magic_enum spdlog::spdlog glm WindowsApp.lib urlmon.lib)

target_precompile_headers(Client PRIVATE "PCH.cpp")

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(Client PRIVATE -Wno-error=pch-date-time -Wno-unused-private-field)
endif()
