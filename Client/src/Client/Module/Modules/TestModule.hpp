#pragma once

#include "../Module.hpp"
#include "../../Event/Events/KeyEvent.hpp"
#include "../../Event/Events/PreRenderEvent.hpp"
#include "../../Event/Events/PostRenderEvent.hpp"

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