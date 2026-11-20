#include "TestCommand.h"

TestCommand::TestCommand(const entt::handle handle) : Command(handle, "command.testcommand.name", "command.testcommand.description") {
    addAlias("command.testcommand.alias.t");
}

std::span<const std::string> TestCommand::getUsages() {
    static const auto usages = std::to_array<std::string>({""});
    return {usages};
}

TestCommand::ExecuteResult TestCommand::execute(CommandArguments& args) {
    return ExecuteResult::Success;
}