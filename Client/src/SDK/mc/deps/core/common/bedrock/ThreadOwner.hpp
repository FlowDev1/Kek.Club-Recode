#pragma once

#include <cstdint>
#include <thread>

#include "ThreadOwnerBehavior.hpp"

namespace Bedrock::Application {
    template <typename T0, ThreadOwnerBehavior WrongThreadBehavior = ThreadOwnerBehavior::Assert>
    class ThreadOwner {
    public:
        T0 object;
        bool threadIdInitialized{};
        std::thread::id threadId;
        uint32_t threadCheckIndex{};
    };
}
