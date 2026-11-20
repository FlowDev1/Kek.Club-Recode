#pragma once

class Event {};

template<std::derived_from<Event> T>
struct EventWrapper {
    EventWrapper(T& impl) : impl(&impl) {}

    T& operator*() const {
        return *this->impl;
    }
private:
    T* impl;
};