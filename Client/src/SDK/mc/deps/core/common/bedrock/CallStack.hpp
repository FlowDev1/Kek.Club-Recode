#pragma once

#include <cstdint>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

#include "LogLevel.hpp"
#include "LogAreaID.hpp"

namespace Bedrock {
    struct CallStack {
        struct Frame {
            uint64_t filenameHash;
            std::string_view filename;
            uint32_t line;
        };

        struct Context {
            std::string value;
            std::optional<LogLevel> logLevel;
            std::optional<LogAreaID> logArea;
        };

        struct FrameWithContext {
            Frame frame;
            std::optional<Context> context;
        };

        std::vector<FrameWithContext> frames;
    };

    namespace Detail {
        CallStack::Context createContext(const std::string& value);
    }
}
