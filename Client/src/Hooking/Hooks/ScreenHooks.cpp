#include "ScreenHooks.h"

#include "../../SDK/mc/client/gui/screens/ScreenView.h"
#include "../../SDK/mc/client/renderer/Mesh.h"
#include "../../SDK/mc/client/renderer/ViewRenderData.h"
#include "../../SDK/mc/client/renderer/NameTagRenderObject.h"
#include "../../SDK/mc/client/renderer/screen/UIRenderContext.h"
#include "../../SDK/mc/client/renderer/screen/MinecraftUIRenderContext.h"
#include "../../SDK/mc/client/gui/screens/models/ClientInstanceScreenModel.h"

#include "../HookManager.h"
#include "../../Renderer/Renderer.h"
#include "../../Signatures/SigManager.h"

#include "../../Client/Event/EventManager.h"
#include "../../Client/Event/Events/ChatSendEvent.h"
#include "../../Client/Event/Events/PreRenderEvent.h"
#include "../../Client/Event/Events/PostRenderEvent.h"

namespace {
    ClientInstanceScreenModel::ChatMessageRestrictions ClientInstanceScreenModel_sendChatMessage(ClientInstanceScreenModel* _this, const std::string& message) {
        static auto oFunc = HookManager::getReturn<&ClientInstanceScreenModel_sendChatMessage>();

        ChatSendEvent event(message);
        eventMgr.emit(event);
        if (event.isCancelled())
            return ClientInstanceScreenModel::Muted;

        return oFunc(_this, message);
    }

    void ScreenView_setupAndRender(ScreenView* _this, UIRenderContext& uiRenderContext) {
        static auto oFunc = HookManager::getReturn<&ScreenView_setupAndRender>();

        Renderer::update(_this, &uiRenderContext);

        PreRenderEvent preRenderEvent(_this, uiRenderContext);
        eventMgr.emit(preRenderEvent);

        oFunc(_this, uiRenderContext);

        PostRenderEvent postRenderEvent(_this, uiRenderContext);
        eventMgr.emit(postRenderEvent);
    }

    void BaseActorRenderer_renderText(ScreenContext& screenContext, const ViewRenderData& viewData, const NameTagRenderObject& tagData, Font& font, const mce::Mesh& a5) {
        static auto oFunc = HookManager::getReturn<&BaseActorRenderer_renderText>();

        oFunc(screenContext, viewData, tagData, font, a5);
    }
}

void ScreenHooks::addScreenHooks() {
    HookManager::addHook(GET_SIGNATURE("ClientInstanceScreenModel::sendChatMessage"), ClientInstanceScreenModel_sendChatMessage);
    HookManager::addHook(GET_SIGNATURE("ScreenView::setupAndRender"), ScreenView_setupAndRender);
    // HookManager::addHook(GET_SIGNATURE("BaseActorRenderer::renderText"), BaseActorRenderer_renderText);
}