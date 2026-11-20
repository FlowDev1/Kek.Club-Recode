#pragma once

class Files {
    static std::string roamingState;
    static std::string recodeFolder;
    static std::string assetsFolder;

public:
    static void init();

    static void setupFolders();

    static const std::string& getRoamingState();
    static const std::string& getRecodeFolder();
    static const std::string& getAssetsFolder();

    static bool doesPathExist(const std::string& path, bool isDirectory);

    static bool createFolder(const std::string& path);

    static bool createRecodeFolder();
};