#pragma once

class Hook {
public:
    using Function = void*;

    enum class Type {
        Global,
        Modular
    };

    bool isEnabled = false;
    Type type = Type::Global;
    Function targetFunction = nullptr;
    Function callbackFunction = nullptr;
    Function trampolineFunction = nullptr;

    Hook(uintptr_t targetFunction, Function callbackFunction, Type type = Type::Global);
    ~Hook();

    void enableHook();
    void disableHook();
    void enableHookQueued();
    void disableHookQueued();
};