#pragma once

#include <cstddef>
#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <limits>

namespace Bedrock::Memory {
    class MemoryAllocator {
    public:
        static void* alignedAlloc(uint64_t size, uint64_t alignment);

        static void alignedRelease(void* ptr);
    };
}
