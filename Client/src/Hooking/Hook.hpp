#pragma once

#include <safetyhook/inline_hook.hpp>

class Hook {
public:
    using Function = void*;

    enum class Type {
        Global,
        Modular
    };

    safetyhook::InlineHook handle;
    Type type = Type::Global;
    Function callbackFunction = nullptr;

    Hook(uintptr_t targetFunction, Function callbackFunction, Type type = Type::Global);

    void enableHook();
    void disableHook();
};