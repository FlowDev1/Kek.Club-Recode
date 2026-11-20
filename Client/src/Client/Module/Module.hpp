#pragma once

#include "Settings/Setting.hpp"

enum class Category {
    COMBAT,
    VISUAL,
    MOVEMENT,
    PLAYER,
    WORLD,
    CLIENT,
    HUD
};

class Module {
public:
    Module(entt::handle handle, const std::string& moduleName, unsigned char key, Category category, const std::string& description);

    virtual ~Module() = default;

    virtual void onEnable();
    virtual void onDisable();
    virtual const std::string& getModuleName();
    virtual const std::string& getDescription();
    
    [[nodiscard]] unsigned char getKey() const;
    void setKey(unsigned char keybind);
    void setEnabled(bool enabled);
    void toggle();
    [[nodiscard]] bool isEnabled() const;

    entt::handle handle;
    std::vector<SettingVariant> settings;

    template <typename T>
    void addSetting(const std::string& name, T& value, T minValue, T maxValue, const std::string& description) {
        settings.emplace_back(Setting<T>{name, value, minValue, maxValue, description});
    }

    template <typename T>
    std::enable_if_t<std::is_same_v<T, bool>, void>
    addSetting(const std::string& name, T& option, const std::string& description) {
        settings.emplace_back(Setting<bool>{name, option, false, true, description});
    }

    template <typename T>
    std::enable_if_t<std::is_enum_v<T>, void>
    addSetting(const std::string& name, T& value, const std::string& description) {
        settings.emplace_back(EnumSetting{name, value, description});
    }

private:
    std::string name;
    unsigned char key = 0;
    Category category{};
    std::string description;
    bool enabled = false;
};