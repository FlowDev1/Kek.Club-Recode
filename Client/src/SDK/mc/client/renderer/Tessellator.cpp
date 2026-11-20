#include "Tessellator.h"

#include "../../../../Signatures/SigManager.h"

void Tessellator::begin(const mce::PrimitiveMode mode, const int maxVertices) {
    static auto begin = Memory::getFunction<&Tessellator::begin>(GET_SIGNATURE("Tessellator::begin"));
    (this->*begin)(mode, maxVertices);
}

void Tessellator::vertex(const float x, const float y, const float z) {
    static auto vertex = Memory::getFunction<&Tessellator::vertex>(GET_SIGNATURE("Tessellator::vertex"));
    (this->*vertex)(x, y, z);
}

void Tessellator::vertexUVV(const Vec2& pos, const Vec2& uv) {
    vertexUV(pos.x, pos.y, 0.f, uv.x, uv.y);
}

void Tessellator::vertexUV(const float x, const float y, const float z, const float u, const float v) {
    static auto vertexUV = Memory::getFunction<&Tessellator::vertexUV>(GET_SIGNATURE("Tessellator::vertexUV"));
    (this->*vertexUV)(x, y, z, u, v);
}

void Tessellator::color(const float r, const float g, const float b, const float a) {
    static auto color = Memory::getFunction<&Tessellator::color>(GET_SIGNATURE("Tessellator::colorF"));
    (this->*color)(r, g, b, a);
}

void Tessellator::colorC(const mce::Color& color) {
    static auto colorC = Memory::getFunction<&Tessellator::colorC>(GET_SIGNATURE("Tessellator::colorC"));
    (this->*colorC)(color);
}

void Tessellator::simpleQuad(const Vec2& pos, const Vec2& size, const bool flipHorizontal, const bool flipVertical) {
    static Vec2 empty{0, 0};
    simpleQuad(pos, size, empty, Vec2(1, 1), flipHorizontal, flipVertical);
}

void Tessellator::simpleQuad(const Vec2& pos, const Vec2& size, Vec2& uvPos, const Vec2& uvSize, const bool flipHorizontal, const bool flipVertical) {
    Vec2 uvLow = uvPos, uvHigh = uvPos + uvSize;

    if (flipHorizontal) {
        const float lowX = uvLow.x;
        uvLow.x = uvHigh.x;
        uvHigh.x = lowX;
    }

    if (flipVertical) {
        const float lowY = uvLow.y;
        uvLow.y = uvHigh.y;
        uvHigh.y = lowY;
    }

    vertexUV(pos.x, pos.y, 0, uvLow.x, uvLow.y);
    vertexUV(pos.x, pos.y + size.y, 0, uvLow.x, uvHigh.y);
    vertexUV(pos.x + size.x, pos.y, 0, uvHigh.x, uvLow.y);

    vertexUV(pos.x + size.x, pos.y + size.y, 0, uvHigh.x, uvHigh.y);
    vertexUV(pos.x + size.x, pos.y, 0, uvHigh.x, uvLow.y);
    vertexUV(pos.x, pos.y + size.y, 0, uvLow.x, uvHigh.y);
}