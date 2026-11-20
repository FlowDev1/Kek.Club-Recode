#pragma once

#include "Event.hpp"
#include "../../Utils/Details.hpp"

class EventManager {
public:
    template <typename Event>
    void emit(Event& event) {
        dispatcher.trigger<EventWrapper<Event>>(event);
    }

    template <auto Candidate, typename Listener>
    void subscribe(Listener* listener) {
        using EventType = std::decay_t<details::member_function_arg_t<decltype(Candidate)>>;
        dispatcher.sink<EventWrapper<EventType>>().template connect<&unwrap_and_invoke<EventType, Listener, Candidate>>(*listener);
    }

    template <auto Candidate, typename Listener>
    void unsubscribe(Listener* listener) {
        using EventType = std::decay_t<details::member_function_arg_t<decltype(Candidate)>>;
        dispatcher.sink<EventWrapper<EventType>>().template disconnect<&unwrap_and_invoke<EventType, Listener, Candidate>>(*listener);
    }

private:
    template <typename Event, typename Listener, auto Candidate>
    static void unwrap_and_invoke(Listener& listenerObj, EventWrapper<Event> wrapper) {
        std::invoke(Candidate, listenerObj, *wrapper);
    }

    entt::dispatcher dispatcher{};
};

extern EventManager eventMgr;