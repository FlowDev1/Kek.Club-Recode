#include "ErrorInfoBuilder.hpp"

namespace Bedrock::Detail {
    ErrorInfoBuilder<std::error_code> createError(std::errc code) {
        ErrorInfoBuilder<std::error_code> builder;

        builder.type = std::error_code(static_cast<int>(code), std::generic_category());

        return builder;
    }
}
