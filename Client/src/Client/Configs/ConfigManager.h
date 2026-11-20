#pragma once

class ConfigManager {
public:
    static void initConfigManager();

    static std::string currentConfig;

    static std::string getPath();

    static void saveConfig(const std::string& name);
    static void updateConfigFile(const json& config, const std::string& name);
    static bool loadConfig(const std::string& name);
};