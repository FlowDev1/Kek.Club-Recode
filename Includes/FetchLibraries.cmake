include(FetchContent)

FetchContent_Declare(
        minhook
        GIT_REPOSITORY https://github.com/TsudaKageyu/minhook.git
        GIT_TAG c1a7c3843bd1a5fe3eb779b64c0d823bca3dc339
)

FetchContent_Declare(
        libhat
        GIT_REPOSITORY https://github.com/BasedInc/libhat.git
        GIT_TAG d6297514b05fd238f5b46d003325f108c22741e3
)

FetchContent_Declare(
        entt
        GIT_REPOSITORY https://github.com/Borion-Updated/entt.git # Using specialized fork because of entt::type_info normally leaking names
        GIT_TAG 36d0212ba103d0d8da6ca4a589ae2de773647f34
)

FetchContent_Declare(
        magic_enum
        GIT_REPOSITORY https://github.com/Neargye/magic_enum.git
        GIT_TAG 1a1824df7ac798177a521eed952720681b0bf482
)

FetchContent_Declare(
        zasm
        GIT_REPOSITORY https://github.com/zyantific/zasm.git
        GIT_TAG b14c1b36c9bb453d8eb3a5b2cc180233f0e54a7a
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

FetchContent_MakeAvailable(
        minhook
        libhat
        entt
        magic_enum
        zasm
        spdlog
        glm
)