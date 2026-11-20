#pragma once

struct ArgumentParser {
    enum ParseError {
        Other,
        InvalidArgument,
        ResultOutOfRange
    };

    template <typename T> requires std::is_arithmetic_v<T> // Thanks to Brady for GREATLY *inspiring* this code
    static std::expected<T, ParseError> parse(const std::string& argument) {
        T out{};
        auto [ptr, ec] = std::from_chars(argument.data(), argument.data() + argument.size(), out);
        if (ec != std::errc()) {
            switch (ec) {
                case std::errc::invalid_argument:
                    return std::unexpected(InvalidArgument);
                case std::errc::result_out_of_range:
                    return std::unexpected(ResultOutOfRange);
                default:
                    return std::unexpected(Other);
            }
        }
        return out;
    }
};