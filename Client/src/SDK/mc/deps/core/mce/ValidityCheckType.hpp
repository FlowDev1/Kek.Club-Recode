#pragma once

#include <cstdint>

namespace mce {
    enum class ValidityCheckType : uint8_t {
        Increment,
        Immutable
    };
}
