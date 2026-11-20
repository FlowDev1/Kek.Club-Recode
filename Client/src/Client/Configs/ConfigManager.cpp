#include "ConfigManager.h"

#include "../../Utils/Files.h"
#include "../Event/EventManager.h"
#include "../Event/Events/ConfigLoadEvent.h"
#include "../Event/Events/ConfigSaveEvent.h"

void ConfigManager::initConfigManager() {
    logF("Initializing configs...");
    Files::createFolder(getPath());
    if (!loadConfig(currentConfig))
        saveConfig(currentConfig);
    logF("Initialized configs");
}

std::string ConfigManager::currentConfig = "default";

std::string ConfigManager::getPath() {
    return Files::getRecodeFolder() + "Configs\\";
}

void ConfigManager::saveConfig(const std::string& name) {
    json config;
    ConfigSaveEvent event(config, name);
    eventMgr.emit(event);
}

void ConfigManager::updateConfigFile(const json& config, const std::string& name) {
    const std::string configStr = config.dump(4);
    const std::string path = getPath() + name + ".conf";
    std::ofstream file(path);
    if (file.is_open()) {
        file << configStr;
        file.close();
    }
}

bool ConfigManager::loadConfig(const std::string& name) {
    const std::string path = getPath() + name + ".conf";
    std::ifstream file(path);
    json config;

    if (file.is_open()) {
        try {
            file >> config;
            file.close();
        } catch (json::parse_error&) {
            file.close();
            return false;
        }
    } else
        return false;

    ConfigLoadEvent event(config, name);
    eventMgr.emit(event);

    currentConfig = name;
    return true;
}