#pragma once

#include "../Event.h"
#include "../../../SDK/mc/client/gui/screens/ScreenView.h"
#include "../../../SDK/mc/client/renderer/screen/UIRenderContext.h"

class PostRenderEvent : public Event {
public:
    PostRenderEvent(ScreenView* screenView, UIRenderContext& uiRenderContext) : screenView(screenView), uiRenderContext(uiRenderContext) {}

    ScreenView* screenView;
    UIRenderContext& uiRenderContext;
};