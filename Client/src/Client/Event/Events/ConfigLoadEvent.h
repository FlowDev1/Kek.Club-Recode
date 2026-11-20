#pragma once

#include "../Event.h"

class ConfigLoadEvent : public Event {
public:
    ConfigLoadEvent(json& config, const std::string& name) : config(config), configName(name) {}

    json& config;
    std::string configName{};
};