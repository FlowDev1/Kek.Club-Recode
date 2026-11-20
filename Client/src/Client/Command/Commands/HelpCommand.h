#pragma once

#include "../Command.h"

class HelpCommand : public Command {
public:
    explicit HelpCommand(entt::handle handle);
    ~HelpCommand() override = default;

    std::span<const std::string> getUsages() override;
    ExecuteResult execute(CommandArguments& args) override;
};