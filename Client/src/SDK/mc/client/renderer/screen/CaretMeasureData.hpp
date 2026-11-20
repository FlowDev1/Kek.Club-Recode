#pragma once

struct CaretMeasureData {
    const int32_t position;
    const bool shouldRender;

    CaretMeasureData() : position(-1), shouldRender(false) {}
    CaretMeasureData(const int32_t position, const bool shouldRender) : position(position), shouldRender(shouldRender) {}
};