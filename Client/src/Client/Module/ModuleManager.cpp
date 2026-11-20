#include "ModuleManager.hpp"

#include "../Event/EventManager.hpp"
#include "../Configs/ConfigManager.hpp"
#include "Modules/TestModule.hpp"

void ModuleManager::initModules() {
    logF("Initializing modules...");

    addModule<TestModule>();

    eventMgr.subscribe<&ModuleManager::onConfigSaveEvent>(this);
    eventMgr.subscribe<&ModuleManager::onConfigLoadEvent>(this);

    this->initialized = true;
    logF("Initialized modules");
}

void ModuleManager::disable() {
    eventMgr.unsubscribe<&ModuleManager::onConfigSaveEvent>(this);
    eventMgr.unsubscribe<&ModuleManager::onConfigLoadEvent>(this);

    for (auto* module : getAllModules()) {
        if (module->isEnabled())
            module->setEnabled(false);
    }

    registry.clear();

    this->initialized = false;

    logF("Disabled modules");
}

void ModuleManager::switchLanguage() {
    disable();
    initModules();
}

void ModuleManager::onConfigSaveEvent(const ConfigSaveEvent& event) {
    auto config = event.config;

    json modulesJson;

    for (auto* const module : getAllModules()) {
        // TODO: Move config saving to a virtual in Module
        json moduleJson;

        for (auto& setting : module->settings) {
            std::visit([&](auto&& arg) { moduleJson[arg.name] = arg.value; }, setting);
        }

        moduleJson["enabled"] = module->isEnabled();
        moduleJson["keybind"] = module->getKey();

        modulesJson[module->getModuleName()] = moduleJson;
    }

    config["Modules"] = modulesJson;

    ConfigManager::updateConfigFile(config, event.configName);
}

void ModuleManager::onConfigLoadEvent(const ConfigLoadEvent& event) {
    auto config = event.config;

    if (config.contains("Modules")) {
        auto modulesJson = config["Modules"];

        for (auto* const module : getAllModules()) {
            // TODO: Move config loading to a virtual in Module
            if (modulesJson.contains(module->getModuleName())) {
                auto moduleJson = modulesJson[module->getModuleName()];

                if (moduleJson.contains("enabled"))
                    module->setEnabled(moduleJson["enabled"]);

                if (moduleJson.contains("keybind"))
                    module->setKey(moduleJson["keybind"]);

                for (auto& setting : module->settings) {
                    std::visit([&](auto&& arg) {
                        if (moduleJson.contains(arg.name))
                            arg.value = moduleJson[arg.name];
                    }, setting);
                }
            }
        }
    }
}

ModuleManager moduleMgr;