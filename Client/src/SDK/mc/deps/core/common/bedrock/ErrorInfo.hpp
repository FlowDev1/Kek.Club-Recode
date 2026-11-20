#pragma once

#include <vector>
#include <system_error>

#include "CallStack.hpp"

namespace Bedrock {
    template <typename E = std::error_code>
    struct ErrorInfo {
        ErrorInfo() = default;

        [[nodiscard]] constexpr E& code() { return error; }
        [[nodiscard]] constexpr const E& code() const { return error; }

        E error;
        CallStack callStack;
        std::vector<ErrorInfo> stackErrors;
    };
}
