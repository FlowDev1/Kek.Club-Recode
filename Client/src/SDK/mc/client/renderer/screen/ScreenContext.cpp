#include "ScreenContext.h"

mce::Clock& ScreenContext::getClock() {
    return *hat::member_at<mce::Clock*>(this, 0xC0);
}

Tessellator& ScreenContext::getTessellator() {
    return *hat::member_at<Tessellator*>(this, 0xC8);
}

ShaderColor& ScreenContext::getCurrentShaderColor() {
    return *hat::member_at<ShaderColor*>(this, 0x30);
}