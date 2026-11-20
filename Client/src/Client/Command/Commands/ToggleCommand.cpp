#include "ToggleCommand.h"

#include "../../../Utils/Text.h"
#include "../../Module/ModuleManager.h"

ToggleCommand::ToggleCommand(const entt::handle handle) : Command(handle, "command.togglecommand.name"_i18n, "command.togglecommand.description"_i18n) {
    addAlias("command.togglecommand.alias.enable"_i18n);
    addAlias("command.togglecommand.alias.disable"_i18n);
}

std::span<const std::string> ToggleCommand::getUsages() {
    static const auto usages = std::to_array<std::string>({"command.togglecommand.usage.module_name"_i18n, "command.togglecommand.usage.list"_i18n});
    return {usages};
}

Command::ExecuteResult ToggleCommand::execute(CommandArguments& args) {
    AssertInsufficient(args, 0);
    AssertExcessive(args, 2);

    if (args[0] == "command.togglecommand.usage.list"_i18n) {
        std::string msg;
        for (const auto module : moduleMgr.getAllModules())
            msg += module->getModuleName() + "\n";
        clientMessage("Modules:\n{}", msg);
        return ExecuteResult::Success;
    }
    for (const auto module : moduleMgr.getAllModules()) {
        const std::string nameLower = Text::toLower(module->getModuleName());
        const std::string inputLower = Text::toLower(args.args[0]);
        if (nameLower == inputLower) {
            module->toggle();
            clientMessage("Toggled module {}", module->getModuleName());
            return ExecuteResult::Success;
        }
    }

    clientMessage("Module name not found, use 'list' to see all modules");

    return ExecuteResult::InputFailure;
}