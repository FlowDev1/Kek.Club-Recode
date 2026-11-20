#pragma once

#include "../Event.hpp"
#include "../../../SDK/mc/client/gui/screens/ScreenView.hpp"
#include "../../../SDK/mc/client/renderer/screen/UIRenderContext.hpp"

class PostRenderEvent : public Event {
public:
    PostRenderEvent(ScreenView* screenView, UIRenderContext& uiRenderContext) : screenView(screenView), uiRenderContext(uiRenderContext) {}

    ScreenView* screenView;
    UIRenderContext& uiRenderContext;
};