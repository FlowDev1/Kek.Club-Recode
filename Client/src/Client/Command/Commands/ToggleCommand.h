#pragma once

#include "../Command.h"

class ToggleCommand final : public Command {
public:
    explicit ToggleCommand(entt::handle handle);
    ~ToggleCommand() override = default;

    std::span<const std::string> getUsages() override;
    ExecuteResult execute(CommandArguments& args) override;
};