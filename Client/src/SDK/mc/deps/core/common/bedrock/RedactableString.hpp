#pragma once
#include <optional>
#include <string>

namespace Bedrock::Safety {
    class RedactableString {
    public:
        std::string unredactedString;
        std::optional<std::string> redactedString;
    };
}
