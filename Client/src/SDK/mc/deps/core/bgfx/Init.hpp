#pragma once

#include <cstdint>

#include "RendererType.hpp"
#include "Resolution.hpp"

namespace bgfx {
    struct Init {
        struct Limits {
            uint16_t maxEncoders;
            uint32_t transientVbSize;
            uint32_t transientIbSize;
            uint8_t maxRendererWorkers;
        };

        RendererType::Enum type;
        uint16_t vendorId;
        uint16_t deviceId;
        uint8_t debug;
        bool profile;
        Resolution resolution;
        Limits limits;
        void* callback;
        void* allocator;
        void* testingCallback;
    };
}
