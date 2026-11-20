#pragma once

template <typename T>
struct Setting {
    std::string name{};
    T& value;
    T minValue;
    T maxValue;
    std::string description{};

    Setting(const std::string& name, T& value, T minValue, T maxValue, const std::string& description) : name(name), value(value), minValue(minValue), maxValue(maxValue), description(description) {}
};

struct EnumSetting {
    std::map<int, std::string> options{};
    std::string name{};
    std::string description{};
    int& value;

    template <typename T>
    EnumSetting(const std::string& name, T& value, const std::string& description) : name(name), description(description), value(reinterpret_cast<int&>(value)) {
        for (auto& map : magic_enum::enum_entries<T>())
            options[static_cast<int>(map.first)] = std::string(map.second);
    }

    const std::string& getValueAsString() {
        return options[value];
    }

    template <typename T>
    T getCurrentValue() {
        return static_cast<T>(value);
    }

    template <typename T>
    void setCurrentValue(T value) {
        this->value = static_cast<int>(value);
    }
};

using SettingVariant = std::variant<Setting<int>, Setting<float>, Setting<bool>, EnumSetting>;