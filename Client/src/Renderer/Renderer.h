#pragma once

#include "../SDK/mc/client/gui/gui/Font.h"
#include "../SDK/mc/client/gui/screens/ScreenView.h"
#include "../SDK/mc/client/renderer/MaterialPtr.h"
#include "../SDK/mc/client/renderer/screen/UIRenderContext.h"
#include "../SDK/mc/deps/core/mce/ClientTexture.h"
#include "../SDK/mc/deps/core/mce/Color.h"
#include "../SDK/mc/deps/core/mce/PrimitiveMode.h"
#include "../SDK/mc/deps/core/mce/TexturePtr.h"
#include "../Utils/Math/Vectors.h"

class Renderer {
public:
    static void update(ScreenView* screenView, UIRenderContext* uiRenderContext);

    static void setColor(const mce::Color& color = mce::Color());

    static mce::MaterialPtr* getUIFillColorMaterial();
    static mce::MaterialPtr* getUITexturedMaterial();
    static mce::TexturePtr getTexture(const std::string& textureName, bool external = false);

    static void drawText(Fonts font, const Vec2& pos, const std::string& text, const mce::Color& color = mce::Color(), float size = 1, float alpha = 1, bool shadow = false);
    static void flushText();

    static void begin(mce::PrimitiveMode mode = mce::PrimitiveMode::TriangleList);
    static void render(const mce::MaterialPtr* material = getUIFillColorMaterial());
    static void render(const std::string& path, const mce::MaterialPtr* material = getUITexturedMaterial(), bool external = true);
    static void render(const mce::ClientTexture& texture, const mce::MaterialPtr* material = getUITexturedMaterial());

    static void drawImage(const std::string& path, const Vec2& pos, const Vec2& size, const mce::Color& color = mce::Color(), bool external = true);
    static void drawImage(const std::string& path, const Vec2& pos, const Vec2& size, Vec2& uvPos, const Vec2& uvSize, const mce::Color& color = mce::Color(), bool external = true);
    static void drawImageEx(const std::string& path, const QuadVertexHolder& pos, const QuadColorHolder& colors = QuadColorHolder(), bool external = true);

    static void drawTriangle(const Vec2& pos1, const Vec2& pos2, const Vec2& pos3, const mce::Color& color = mce::Color());
    static void drawRect(const Vec2& pos, const Vec2& size, float lineSize, const mce::Color& color = mce::Color());
    static void fillRect(const Vec2& pos, const Vec2& size, const mce::Color& color = mce::Color());
    static void drawRoundedRect(const Vec2& pos, const Vec2& size, float stepSize, const mce::Color& color = mce::Color(), uint16_t flags = 0xF, float radius = 4.2f);

    static void addImage(const Vec2& pos, const Vec2& size, const mce::Color& color = mce::Color());
    static void addImage(const Vec2& pos, const Vec2& size, Vec2& uvPos, const Vec2& uvSize, const mce::Color& color = mce::Color());
    static void addImageEx(const QuadVertexHolder& pos, const QuadColorHolder& colors = QuadColorHolder());

    static void addTriangle(const Vec2& pos1, const Vec2& pos2, const Vec2& pos3, const mce::Color& color = mce::Color());
    static void addRect(const Vec2& pos, const Vec2& size, float lineSize, const mce::Color& color = mce::Color());
    static void addFilledRect(const Vec2& pos, const Vec2& size, const mce::Color& color = mce::Color());
    static void addRoundedRect(const Vec2& pos, const Vec2& size, float stepSize, const mce::Color& color = mce::Color(), uint16_t flags = 0xF, float radius = 4.2f);
};