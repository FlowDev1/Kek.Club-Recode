#pragma once

namespace mce {
    class Color {
    public:
        float r;
        float g;
        float b;
        float a;

        [[nodiscard]] constexpr Color() : r(1), g(1), b(1), a(1) {}
        [[nodiscard]] constexpr Color(const float r, const float g, const float b, const float a = 1) : r(r), g(g), b(b), a(a) {}
        [[nodiscard]] constexpr Color(const int r, const int g, const int b, const int a = 255) {
            this->r = r / 255.f;
            this->g = g / 255.f;
            this->b = b / 255.f;
            this->a = a / 255.f;
        }
    };
}

struct QuadColorHolder {  // top left, top right, bottom left, bottom right
    mce::Color col1, col2, col3, col4;
};