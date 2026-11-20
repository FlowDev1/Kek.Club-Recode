#include "Internationalization.h"

#include "../Files.h"
#include "../Text.h"

std::string Internationalization::directory{};
std::unordered_map<Internationalization::Translation, nlohmann::json> Internationalization::translationFiles{};

void Internationalization::setup() {
    directory = Files::getRecodeFolder() + "Languages\\";
    std::ifstream file;
    switch (currentTranslation) {
        case English:
            file = std::ifstream(directory + enLangFile);
        break;
        case French:
            file = std::ifstream(directory + frLangFile);
        break;
        case German:
            file = std::ifstream(directory + deLangFile);
        break;
    }
    ClientAssert(file.is_open(), "The translation file did not succesfully open!");
    json lang;
    file >> lang;
    translationFiles.emplace(currentTranslation, lang);
}

std::string Internationalization::lookupTranslation(const std::string_view lookupStr) {
    const auto sections = Text::splitString(lookupStr, '.');
    json root = translationFiles[currentTranslation];

    for (const auto& part : sections) {
        ClientAssert(root.contains(part), "The translation file does not contain required information!");
        root = root[part];
        if (root.is_null())
            throw std::runtime_error("Root is null");
    }

    return root.get<std::string>();
}

bool Internationalization::switchLanguage(Translation newLang) {
    return true;
}