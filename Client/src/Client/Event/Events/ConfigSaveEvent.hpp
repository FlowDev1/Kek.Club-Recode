#pragma once

#include "../Event.hpp"

class ConfigSaveEvent : public Event {
public:
    ConfigSaveEvent(json& config, const std::string& name) : config(config), configName(name) {}

    json& config;
    std::string configName{};
};