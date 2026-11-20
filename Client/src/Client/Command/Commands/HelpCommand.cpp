#include "HelpCommand.hpp"

HelpCommand::HelpCommand(const entt::handle handle) : Command(handle, "Help", "Helps with the usage of commands and modules") {}

std::span<const std::string> HelpCommand::getUsages() {
    static const auto usages = std::to_array<std::string>({""});
    return {usages};
}

Command::ExecuteResult HelpCommand::execute(CommandArguments& args) {
    return ExecuteResult::Success;
}