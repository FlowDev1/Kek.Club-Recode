#pragma once

#ifndef NDEBUG
#include <libhat/Signature.hpp>
#endif

#define clientMessage(x, ...) Logger::logToChat(std::string("{}[Recode]{} ") + xorstr(x), ColorFormat::AQUA, ColorFormat::RESET, __VA_ARGS__)
#define logF(x, ...) Logger::log(xorstr(x), __VA_ARGS__) // `F` for file (logging to file)

class Logger {
public:
    enum class Level {
        Info,
        Debug
    };
    static std::shared_ptr<spdlog::logger> logger;
    static std::vector<std::pair<std::string, Level>> logsToPrint;

    static void initializeLogger();

    static void clearLogs();

    template <typename... Args>
    static void log(const std::string& text, Args... args) {
        const std::string formatted = fmt::vformat(text, fmt::make_format_args(args...));
        logger->info(formatted);
        logsToPrint.emplace_back(formatted, Level::Debug);
    }

    template <typename... Args>
    static void logToChat(const std::string& text, Args... args) {
        const std::string formatted = fmt::vformat(text, fmt::make_format_args(args...));
        logsToPrint.emplace_back(formatted, Level::Info);
    }

#ifndef NDEBUG
    static std::string convertSigViewToString(const hat::signature_view sig) {
        std::ostringstream stream;

        for (const auto& element : sig) {
            if (element.has_value())
                stream << std::format("{:02X}", static_cast<uint8_t>(element.value())) << " ";
            else
                stream << "? ";
        }

        std::string str = stream.str();
        str = str.substr(0, str.size() - 1);

        return str;
    }
#endif
};