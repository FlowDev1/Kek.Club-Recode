#pragma once

#include "CommandArguments.hpp"

#define AssertInsufficient(args, amount) if (args.hasOrLess(amount)) return ExecuteResult::InsufficientArguments
#define AssertExcessive(args, amount) if (args.hasOrMore(amount)) return ExecuteResult::ExcessiveArguments

class Command {
public:
    enum class ExecuteResult {
        Success,
        InputFailure,
        ExecutionFailure,

        InsufficientArguments,
        ExcessiveArguments
    };

    Command(entt::handle handle, const std::string& commandName, const std::string& description);

    virtual ~Command() = default;
    virtual std::span<const std::string> getUsages() = 0;
    virtual ExecuteResult execute(CommandArguments& args) = 0;

    const std::string& getCommandName();
    const std::string& getDescription();

    void addAlias(const std::string& alias);

    entt::handle handle;
    std::string name;
    std::string description;
    std::vector<std::string> aliases{};
};