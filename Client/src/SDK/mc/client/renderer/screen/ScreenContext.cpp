#include "ScreenContext.hpp"
#include "../../../../../Offsets/OffsetManager.hpp"

mce::Clock& ScreenContext::getClock() {
    return *hat::member_at<mce::Clock*>(this, 0xC0);
}

Tessellator& ScreenContext::getTessellator() {
    return *hat::member_at<Tessellator*>(this, GET_OFFSET("ScreenContext::tessellator"));
}

ShaderColor& ScreenContext::getCurrentShaderColor() {
    return *hat::member_at<ShaderColor*>(this, 0x30);
}