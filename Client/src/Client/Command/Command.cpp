#include "Command.h"

Command::Command(const entt::handle handle, const std::string& commandName, const std::string& description) : handle(handle), name(commandName), description(description) {}

const std::string& Command::getCommandName() {
    return name;
}

const std::string& Command::getDescription() {
    return description;
}

void Command::addAlias(const std::string& alias) {
    aliases.push_back(alias);
}