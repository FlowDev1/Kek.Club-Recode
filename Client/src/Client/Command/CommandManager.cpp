#include "CommandManager.h"

#include "Commands/TestCommand.h"
#include "Commands/ToggleCommand.h"
#include "Commands/HelpCommand.h"

#include "../../Utils/Text.h"
#include "../Event/EventManager.h"

void CommandManager::initCommands() {
    logF("Initializing commands...");

    addCommand<TestCommand>();
    addCommand<ToggleCommand>();
    addCommand<HelpCommand>();

    eventMgr.subscribe<&CommandManager::onChatSendEvent>(this);

    this->initialized = true;
    logF("Initialized commands");
}

void CommandManager::disable() {
    registry.clear();

    eventMgr.unsubscribe<&CommandManager::onChatSendEvent>(this);

    this->initialized = false;
    logF("Disabled commands");
}

void CommandManager::switchLanguage() {
    disable();
    initCommands();
}

void CommandManager::onChatSendEvent(ChatSendEvent& event) {
    if (event.message[0] != prefix)
        return;

    const std::string commandWithoutPrefix = event.message.substr(1);
    auto args = Text::splitString(commandWithoutPrefix, ' ');

    if (args.empty())
        return;

    const std::string inputCommandName = Text::toLower(args[0]);

    for (auto&& command : getAllCommands()) {
        const std::string commandNameLower = Text::toLower(command->getCommandName());

        if (commandNameLower == inputCommandName) {
            args.erase(args.begin());
            try {
                CommandArguments commandArgs{args};
                handleExecuteResult(command->execute(commandArgs), *command);
            } catch (CommandException& ex) {
                handleCommandException(ex);
            }
            event.setCancelled(true);
            return;
        }

        const auto& aliases = command->aliases;
        for (const auto& alias : aliases) {
            const std::string aliasLower = Text::toLower(alias);

            if (aliasLower == inputCommandName) {
                args.erase(args.begin());
                try {
                    CommandArguments commandArgs{args};
                    handleExecuteResult(command->execute(commandArgs), *command);
                } catch (CommandException& ex) {
                    handleCommandException(ex);
                }
                event.setCancelled(true);
                return;
            }
        }
    }
    clientMessage("Unknown command '{}', use '{}help' to see all commands", inputCommandName, prefix);
}

void CommandManager::handleCommandException(const CommandException& ex) {
    // This will be further developed in the future
    logF("Exception occurred while executing command: {}", ex.what());
}

void CommandManager::handleExecuteResult(const Command::ExecuteResult result, Command& command) {
    switch (result) {
        case Command::ExecuteResult::Success:
            return;
        case Command::ExecuteResult::InputFailure:
            logF("Invalid input provided");
            break;
        case Command::ExecuteResult::ExecutionFailure:
            logF("Failed to execute command");
            return;
        case Command::ExecuteResult::InsufficientArguments:
            logF("Insufficient arguments provided");
            break;
        case Command::ExecuteResult::ExcessiveArguments:
            logF("Excessive arguments provided");
            break;
    }
    std::string usages;
    for (const auto& usage : command.getUsages())
        usages += "\n" + usage;
    clientMessage("Usages for '{}': {}", command.getCommandName(), usages);
}

CommandManager commandMgr;