#pragma once

#include "Components/CommandTypeComponent.hpp"
#include "Components/CommandOwnerComponent.hpp"

#include "../Event/Events/ChatSendEvent.hpp"

class CommandManager {
    entt::registry registry{};
public:
    template <typename T>
    void addCommand() {
        const auto entity = registry.create();
        entt::handle handle(registry, entity);
        registry.emplace<CommandOwnerComponent>(entity, std::make_unique<T>(handle));
        registry.emplace<CommandTypeComponent<T>>(entity);
    }

    auto getAllCommands() {
        return registry.view<CommandOwnerComponent>().each() | std::views::transform([](auto&& tuple) {
            return std::get<1>(tuple).command.get();
        });
    }

    void initCommands();
    void disable();
    void switchLanguage();

    void onChatSendEvent(ChatSendEvent& event);

    static void handleCommandException(const CommandException& ex);
    static void handleExecuteResult(Command::ExecuteResult result, Command& command);

    bool initialized = false;
    char prefix = '.';
};

extern CommandManager commandMgr;