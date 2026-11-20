file(GLOB_RECURSE CLIENT_SOURCES CONFIGURE_DEPENDS "src/*.cpp" "src/*.h")

add_library(Client SHARED
	${CLIENT_SOURCES}
)

target_link_libraries(Client PRIVATE minhook libhat EnTT::EnTT magic_enum zasm spdlog::spdlog glm)

target_precompile_headers(Client PRIVATE "PCH.cpp")