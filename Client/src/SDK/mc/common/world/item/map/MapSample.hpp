#pragma once

#include <cstdint>
#include "../../../../deps/core/mce/Color.hpp"

class Block;

struct MapSample {
    mce::Color color;
    Block* block;
    int16_t height;
};
