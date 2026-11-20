#pragma once

#include "Event.hpp"

class CancellableEvent : public Event {
public:
    void setCancelled(bool cancelled);
    [[nodiscard]] bool isCancelled() const;

private:
    bool cancelled = false;
};