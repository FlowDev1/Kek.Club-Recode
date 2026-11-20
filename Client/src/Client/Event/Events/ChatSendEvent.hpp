#pragma once

#include "../CancellableEvent.hpp"

class ChatSendEvent : public CancellableEvent {
public:
    ChatSendEvent(const std::string& name) : message(name) {}

    std::string message;
};