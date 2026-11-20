#pragma once

#include "../Event.h"
#include "../../../SDK/mc/client/gui/screens/ScreenView.h"
#include "../../../SDK/mc/client/renderer/screen/UIRenderContext.h"

class PreRenderEvent : public Event {
public:
    PreRenderEvent(ScreenView* screenView, UIRenderContext& uiRenderContext) : screenView(screenView), uiRenderContext(uiRenderContext) {}

    ScreenView* screenView;
    UIRenderContext& uiRenderContext;
};