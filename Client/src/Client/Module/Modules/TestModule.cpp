#include "TestModule.hpp"

#include "../../Event/EventManager.hpp"
#include "../../../Renderer/Renderer.hpp"

TestModule::TestModule(const entt::handle handle) : Module(handle, "module.testmodule.name"_i18n, 0, Category::CLIENT, "module.testmodule.description"_i18n) {
    addSetting<int>("module.testmodule.int_test.name"_i18n, intVal, 1, 10, "module.testmodule.int_test.description"_i18n);
    addSetting<bool>("module.testmodule.bool_test.name"_i18n, boolVal, "module.testmodule.bool_test.description"_i18n);
    addSetting<float>("module.testmodule.float_test.name"_i18n, floatVal, 1.0f, 10.0f, "module.testmodule.float_test.description"_i18n);
    addSetting<TestEnum>("module.testmodule.enum_test.name"_i18n, enumVal, "module.testmodule.enum_test.description"_i18n);
}

void TestModule::onEnable() {
    eventMgr.subscribe<&TestModule::onKeyUpdate>(this);
    eventMgr.subscribe<&TestModule::onPreRender>(this);
    eventMgr.subscribe<&TestModule::onPostRender>(this);
}

void TestModule::onPreRender(PreRenderEvent& event) {
}

void TestModule::onPostRender(PostRenderEvent& event) {
    Renderer::setColor();

    const mce::TexturePtr& texture = Renderer::getTexture("dog.tga", true);

    Renderer::begin();

    Renderer::addImage({25.f, 25.f}, {50.f, 50.f});

    QuadVertexHolder pos;
    QuadColorHolder colors;

    pos.pos1 = {80.f, 25.f};
    pos.uv1 = {0.f, 0.f};
    colors.col1 = {1.f, 0.f, 0.f, 1.f};

    pos.pos2 = {130.f, 25.f};
    pos.uv2 = {1.f, 0.f};
    colors.col2 = {0.f, 0.f, 1.f, 1.f};

    pos.pos3 = {90.f, 75.f};
    pos.uv3 = {0.f, 1.f};
    colors.col3 = {0.f, 1.f, 0.f, 1.f};

    pos.pos4 = {140.f, 75.f};
    pos.uv4 = {1.f, 1.f};
    colors.col4 = {1.f, 1.f, 1.f, 1.f};

    Renderer::addImageEx(pos, colors);

    Renderer::render(texture.clientTexture->clientTexture);

    Renderer::begin();

    Renderer::addRect({25.f, 80.f}, {50.f, 50.f}, 4.f);
    Renderer::addFilledRect({80.f, 80.f}, {50.f, 50.f});
    Renderer::addRoundedRect({25.f, 135.f}, {50.f, 50.f}, 10.f);
    Renderer::addRoundedRect({80.f, 135.f}, {50.f, 50.f}, 1.f, mce::Color(1.f, 1.f, 1.f, 0.5f), 0b11001, 8.4f);

    Renderer::render();

    Renderer::drawText(Fonts::SmoothFontLatin, {25.f, 190.f}, "Hello, world!", mce::Color(1.f, 1.f, 1.f, 1.f), 1.f);
    Renderer::flushText();
}

void TestModule::onKeyUpdate(KeyEvent& event) {}

void TestModule::onDisable() {
    eventMgr.unsubscribe<&TestModule::onKeyUpdate>(this);
    eventMgr.unsubscribe<&TestModule::onPreRender>(this);
    eventMgr.unsubscribe<&TestModule::onPostRender>(this);
}