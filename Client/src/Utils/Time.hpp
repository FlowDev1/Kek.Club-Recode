#pragma once

class Time {
public:
    static std::chrono::milliseconds getCurrentTime() {
        const auto now = std::chrono::system_clock::now().time_since_epoch();
        return std::chrono::duration_cast<std::chrono::milliseconds>(now);
    }

    static void wait(const int seconds) {
        std::this_thread::sleep_for(std::chrono::seconds(seconds));
    }

    static std::string getTimestamp() {
        const auto now = std::chrono::system_clock::now();
        const auto in_time_t = std::chrono::system_clock::to_time_t(now);
        const auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;

        std::tm tm{};
        localtime_s(&tm, &in_time_t);

        return std::format("[{:02}:{:02}.{:03}]", tm.tm_min, tm.tm_sec, ms.count());
    }
};