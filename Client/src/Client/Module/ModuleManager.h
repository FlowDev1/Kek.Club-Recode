#pragma once

#include "../Event/Events/ConfigSaveEvent.h"
#include "../Event/Events/ConfigLoadEvent.h"
#include "Components/SuffixComponent.h"
#include "Components/ModuleTypeComponent.h"
#include "Components/ModuleOwnerComponent.h"

class ModuleManager {
public:
    template <typename T>
    void addModule() {
        const auto entity = registry.create();
        entt::handle handle(registry, entity);
        registry.emplace<ModuleOwnerComponent>(entity, std::make_unique<T>(handle));
        registry.emplace<ModuleTypeComponent<T>>(entity);
        registry.emplace<SuffixComponent>(entity);
    }

    auto getAllModules() {
        return registry.view<ModuleOwnerComponent>().each() | std::views::transform([](auto&& tuple) {
            return std::get<1>(tuple).module.get();
        });
    }

    template <typename T>
    T& getModule() { // Best senario is we don't use this function at all
        for (auto&& [_, moduleOwner] : registry.view<ModuleOwnerComponent, ModuleTypeComponent<T>>().each())
            return *static_cast<T*>(moduleOwner.module.get());
        throw std::runtime_error("Module not found");
    }
    
    void initModules();
    void disable();
    void switchLanguage();

    void onConfigSaveEvent(const ConfigSaveEvent& event);
    void onConfigLoadEvent(const ConfigLoadEvent& event);

private:
    bool initialized = false;
    entt::registry registry{};
};

extern ModuleManager moduleMgr;