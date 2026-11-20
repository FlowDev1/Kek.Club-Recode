#pragma once

#include "Event.h"

class CancellableEvent : public Event {
public:
    void setCancelled(bool cancelled);
    [[nodiscard]] bool isCancelled() const;

private:
    bool cancelled = false;
};