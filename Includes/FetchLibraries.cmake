include(FetchContent)

FetchContent_Declare(
        safetyhook
        GIT_REPOSITORY https://github.com/cursey/safetyhook.git
        GIT_TAG c3f3f306a0f12d1811c0b713ad2ed2a8ddc6cf55
)

FetchContent_Declare(
        libhat
        GIT_REPOSITORY https://github.com/BasedInc/libhat.git
        GIT_TAG d6297514b05fd238f5b46d003325f108c22741e3
)

FetchContent_Declare(
        entt
        GIT_REPOSITORY https://github.com/skypjack/entt.git
        GIT_TAG fe8d7d78c4823e8a66a050bf86f5c6318cf76ce7
)

FetchContent_Declare(
        magic_enum
        GIT_REPOSITORY https://github.com/Neargye/magic_enum.git
        GIT_TAG 1a1824df7ac798177a521eed952720681b0bf482
)

FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG 24dde318fe034f0c7e809daa5a6e81dc85e1155a
)

FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG 33b4a621a697a305bc3a7610d290677b96beb181
)

set(SPDLOG_USE_STD_FORMAT ON CACHE BOOL "Use the C++ standard formatter" FORCE)

FetchContent_MakeAvailable(
        safetyhook
        libhat
        entt
        magic_enum
        spdlog
        glm
)