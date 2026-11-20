#include "Files.h"

std::string Files::roamingState{};
std::string Files::recodeFolder{};
std::string Files::assetsFolder{};

void Files::init() {
    setupFolders();
    createRecodeFolder();
    createFolder(recodeFolder + "Assets");
}

void Files::setupFolders() { // May only be called from the main thread
    const auto roamingFolder = Storage::ApplicationData::Current().RoamingFolder();
    roamingState = to_string(roamingFolder.Path());
    recodeFolder = roamingState + "\\Recode\\";
    assetsFolder = recodeFolder + "Assets\\";
}

const std::string& Files::getRoamingState() {
    return roamingState;
}

const std::string& Files::getRecodeFolder() {
    return recodeFolder;
}

const std::string& Files::getAssetsFolder() {
    return assetsFolder;
}

bool Files::doesPathExist(const std::string& path, const bool isDirectory) {
    if (!std::filesystem::exists(path)) return false;

    if (isDirectory)
        return std::filesystem::is_directory(path);
    return std::filesystem::is_regular_file(path);
}

bool Files::createFolder(const std::string& path) {
    if (doesPathExist(path, true)) return true;

    return std::filesystem::create_directory(path);
}

bool Files::createRecodeFolder() {
    return createFolder(getRecodeFolder());
}