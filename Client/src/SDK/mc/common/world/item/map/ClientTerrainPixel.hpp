#pragma once

#include <cstdint>

struct ClientTerrainPixel {
    uint32_t pixel;
    bool assignedToMap;
    bool sentToServer;
};
