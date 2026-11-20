#pragma once

#include "../Module.h"
#include "../../Event/Events/KeyEvent.h"
#include "../../Event/Events/PreRenderEvent.h"
#include "../../Event/Events/PostRenderEvent.h"

class TestModule final : public Module {
public:
    enum class TestEnum : int {
        Option1 = 0,
        Option2 = 1,
        Option3 = 2
    };

    explicit TestModule(entt::handle handle);
    ~TestModule() override = default;

    int intVal = 2;
    bool boolVal = false;
    float floatVal = 1.52f;
    TestEnum enumVal = TestEnum::Option1;

    void onEnable() override;
    void onPreRender(PreRenderEvent& event);
    void onPostRender(PostRenderEvent& event);
    void onKeyUpdate(KeyEvent& event);
    void onDisable() override;
};