#include "CancellableEvent.hpp"

void CancellableEvent::setCancelled(const bool cancelled) {
    this->cancelled = cancelled;
}

bool CancellableEvent::isCancelled() const {
    return this->cancelled;
}