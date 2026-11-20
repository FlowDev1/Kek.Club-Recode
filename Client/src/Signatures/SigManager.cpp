#include "SigManager.h"

void SigManager::scanAllSignatures() {
    std::vector<std::future<void>> futures;

    futures.reserve(signatures.size());
    for (auto& sig : std::views::values(signatures)) {
        futures.push_back(std::async(std::launch::async, [&sig] {
            sig.address = Memory::findSig(sig.signature);
            sig.scanned = true;
        }));
    }

    for (auto& future : futures)
        future.get();
}

void SigManager::addAllSignatures() {
    // Hooks
    ADD_SIGNATURE("Keyboard::feed", "48 83 EC ? ? ? C1 4C 8D 05");
    ADD_SIGNATURE("MouseDevice::feed", "E8 ? ? ? ? 40 88 6C 1F");
    ADD_SIGNATURE("ClientInstanceScreenModel::sendChatMessage", "48 89 5C 24 ? 48 89 74 24 ? 55 57 41 55 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 4C 8B EA 48 8B F9");
    ADD_SIGNATURE("ScreenView::setupAndRender", "48 8B C4 48 89 58 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 0F 29 70 ? 0F 29 78 ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 4C 8B E2 48 89 55 ? 4C 8B F9");
    ADD_SIGNATURE("Minecraft::tick", "E8 ? ? ? ? 4D 8B BD ? ? ? ? 4D 85 FF 0F 84 ? ? ? ? 49 8B 07");
    ADD_SIGNATURE("BaseActorRenderer::renderText", "48 8B C4 48 89 58 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 0F 29 70 ? 0F 29 78 ? 44 0F 29 40 ? 44 0F 29 48 ? 44 0F 29 90 ? ? ? ? 44 0F 29 98 ? ? ? ? 44 0F 29 A0 ? ? ? ? 44 0F 29 A8 ? ? ? ? 44 0F 29 B0 ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 4D 8B F1 4D 8B F8");
    ADD_SIGNATURE("ClientInstance::update", "48 89 5C 24 ? 55 56 57 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 48 8B D9 88 55 ? 45 33 FF 44 89 7C 24 ? 48 8B 01 48 8B 40 ? FF 15 ? ? ? ? 4C 8B F0 8B BB ? ? ? ? 33 D2");
    // Other
    ADD_SIGNATURE("MainView::mInstance", "48 89 3D ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? 48 8B D8 48 89 44 24 ? 48 85 C0 74");
    ADD_SIGNATURE("Mouse::_instance", "48 8D 0D ? ? ? ? E8 ? ? ? ? 40 B7 ? 48 85 DB");
    // Functions
    ADD_SIGNATURE("Font::getTextHeight", "E8 ? ? ? ? 66 44 0F 6E D8");

    ADD_SIGNATURE("mce::RenderMaterialGroup::common", "48 8B 05 ? ? ? ? 48 8D 0D ? ? ? ? 48 8B 40 ? FF 15 ? ? ? ? 48 8B D8");

    ADD_SIGNATURE("Tessellator::begin", "40 53 55 48 83 EC ? 80 B9 ? ? ? ? ? 44 0F B6 D2");
    ADD_SIGNATURE("Tessellator::vertex", "40 57 48 81 EC ? ? ? ? 0F 29 7C ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 44 24 ? 8B 81");
    ADD_SIGNATURE("Tessellator::vertexUV", "48 83 EC ? 80 B9 ? ? ? ? ? 0F 57 E4");
    ADD_SIGNATURE("Tessellator::colorF", "80 B9 ? ? ? ? ? 4C 8B C1 75 ? F3 0F 10 25");
    ADD_SIGNATURE("Tessellator::colorC", "80 B9 ? ? ? ? ? 4C 8B D2 4C 8B C1");

    ADD_SIGNATURE("MeshHelpers::renderMeshImmediately1", "40 53 55 56 57 41 56 48 81 EC ? ? ? ? 49 8B F1 4D 8B F0 48 8B FA 48 8B E9 80 BA ? ? ? ? ? 0F 85 ? ? ? ? 48 8D 05 ? ? ? ? 48 89 44 24 ? 48 C7 44 24 ? ? ? ? ? 0F 28 44 24 ? 66 0F 7F 44 24 ? C7 44 24 ? ? ? ? ? 4C 8D 4C 24 ? 41 B8 ? ? ? ? 48 8D 94 24 ? ? ? ? 48 8B CF E8 ? ? ? ? 48 8B D8 C6 84 24 ? ? ? ? ? 33 D2");
    ADD_SIGNATURE("MeshHelpers::renderMeshImmediately2", "40 55 53 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 49 8B F9 4D 8B F8");

    ADD_SIGNATURE("GuiData::displayClientMessage", "40 55 53 56 57 41 56 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 41 0F B6 F9 49 8B D8");

    ADD_SIGNATURE("mce::MathUtility::getRotationFromNegZToVector", "48 8B C4 48 81 EC ? ? ? ? F3 0f 10 ? F3 0F 10");

    ADD_SIGNATURE("MinecraftPackets::createPacket", "E8 ? ? ? ? 90 48 83 BD ? ? ? ? ? 0F 84 ? ? ? ? FF 15");
}

SigManager sigMgr;