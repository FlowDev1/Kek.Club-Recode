#pragma once

class Text {
public:
    static std::string toHexAddress(const auto* ptr) {
        return fmt::format("0x{:X}", reinterpret_cast<uintptr_t>(ptr));
    }

    static std::vector<std::string> splitString(const std::string_view& str, char delimiter) {
        return str
            | std::views::split(delimiter)
            | std::views::transform([](auto&& token) { return std::string{token.begin(), token.end()}; })
            | std::ranges::to<std::vector>();
    }

    static std::string toLower(const std::string_view str) {
        return std::views::transform(str, tolower) | std::ranges::to<std::string>();
    }
};