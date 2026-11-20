#pragma once

#include "../Command.hpp"

class TestCommand final : public Command {
public:
    explicit TestCommand(entt::handle handle);
    ~TestCommand() override = default;

    std::span<const std::string> getUsages() override;
    ExecuteResult execute(CommandArguments& args) override;
};