#pragma once

#include <system_error>

namespace Bedrock::Detail {
    template <typename T>
    struct ErrorInfoBuilder {
        T type;
        bool hasValue = true;
    };

    ErrorInfoBuilder<std::error_code> createError(std::errc code);
}
