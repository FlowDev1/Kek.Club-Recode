#pragma once

#include "../../deps/core/mce/Color.hpp"
#include "../../deps/core/mce/PrimitiveMode.hpp"
#include "../../../../Utils/Math/Vectors.hpp"

class Tessellator {
public:
    void begin(mce::PrimitiveMode mode = mce::PrimitiveMode::TriangleList, int maxVertices = 0);
    void vertex(float x, float y, float z);
    void vertexUVV(const Vec2& pos, const Vec2& uv);
    void vertexUV(float x, float y, float z, float u, float v);
    void color(float r, float g, float b, float a);
    void colorC(const mce::Color& color);
    void simpleQuad(const Vec2& pos, const Vec2& size, bool flipHorizontal = false, bool flipVertical = false);
    void simpleQuad(const Vec2& pos, const Vec2& size, Vec2& uvPos, const Vec2& uvSize, bool flipHorizontal = false, bool flipVertical = false);
};