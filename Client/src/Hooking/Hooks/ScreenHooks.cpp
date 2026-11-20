#include "ScreenHooks.hpp"

#include "../../SDK/mc/client/gui/screens/ScreenView.hpp"
#include "../../SDK/mc/client/renderer/Mesh.hpp"
#include "../../SDK/mc/client/renderer/ViewRenderData.hpp"
#include "../../SDK/mc/client/renderer/NameTagRenderObject.hpp"
#include "../../SDK/mc/client/renderer/screen/UIRenderContext.hpp"
#include "../../SDK/mc/client/renderer/screen/MinecraftUIRenderContext.hpp"
#include "../../SDK/mc/client/gui/screens/models/ClientInstanceScreenModel.hpp"

#include "../HookManager.hpp"
#include "../../Renderer/Renderer.hpp"
#include "../../Signatures/SigManager.hpp"

#include "../../Client/Event/EventManager.hpp"
#include "../../Client/Event/Events/ChatSendEvent.hpp"
#include "../../Client/Event/Events/PreRenderEvent.hpp"
#include "../../Client/Event/Events/PostRenderEvent.hpp"

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