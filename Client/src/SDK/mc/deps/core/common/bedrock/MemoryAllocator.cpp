#include "MemoryAllocator.hpp"

namespace Bedrock::Memory {
    void* MemoryAllocator::alignedAlloc(uint64_t size, uint64_t alignment) {
        if (!alignment || (alignment & (alignment - 1))) return nullptr;
        alignment = std::max(alignment, static_cast<uint64_t>(sizeof(void*)));

        if (size == 0)
            size = 1;

        const auto maximum = std::numeric_limits<size_t>::max();
        if (alignment - 1 > maximum - sizeof(void*) ||
            size > maximum - sizeof(void*) - (alignment - 1)) return nullptr;
        auto* allocation = malloc(static_cast<size_t>(size + sizeof(void*) + alignment - 1));
        if (!allocation) return nullptr;
        const auto address = (reinterpret_cast<uintptr_t>(allocation) + sizeof(void*) + alignment - 1) & ~(alignment - 1);
        auto* result = reinterpret_cast<void*>(address);
        reinterpret_cast<void**>(result)[-1] = allocation;
        return result;
    }

    void MemoryAllocator::alignedRelease(void* ptr) {
        if (ptr != nullptr)
            free(reinterpret_cast<void**>(ptr)[-1]);
    }
}
