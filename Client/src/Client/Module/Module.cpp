#include "Module.h"

Module::Module(const entt::handle handle, const std::string& moduleName, const unsigned char key, const Category category, const std::string& description) : handle(handle), name(moduleName), key(key), category(category), description(description) {}

const std::string& Module::getModuleName() {
    return this->name;
}

const std::string& Module::getDescription() {
    return this->description;
}

void Module::onEnable() {}

void Module::onDisable() {}

unsigned char Module::getKey() const {
    return this->key;
}

void Module::setKey(const unsigned char keybind) {
    this->key = keybind;
}

void Module::setEnabled(const bool enabled) {
    this->enabled = enabled;

    if (enabled)
        this->onEnable();
    else
        this->onDisable();
}

void Module::toggle() {
    this->setEnabled(!this->enabled);
}

bool Module::isEnabled() const {
    return this->enabled;
}