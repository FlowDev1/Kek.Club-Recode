#include "Logger.h"

#include "Files.h"

void Logger::initializeLogger() {
    logger = spdlog::basic_logger_mt("recode_logger", Files::getRecodeFolder() + "logs.txt");
    logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] %v");
    logger->flush_on(spdlog::level::info);
}

void Logger::clearLogs() {
    std::ofstream logfile(Files::getRecodeFolder() + "logs.txt", std::ios::trunc);
    ClientAssert(logfile.is_open(), "Error opening logs.txt for writing");
    logfile.close();
}

std::shared_ptr<spdlog::logger> Logger::logger = nullptr;
std::vector<std::pair<std::string, Logger::Level>> Logger::logsToPrint{};