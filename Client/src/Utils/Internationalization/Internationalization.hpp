#pragma once

class Internationalization {
public:
    enum Translation {
        English,
        French,
        German
    };

    static void setup();
    static std::string lookupTranslation(std::string_view lookupStr);
    static bool switchLanguage(Translation newLang);

    static std::string directory;
    static inline Translation currentTranslation = English;
    static std::unordered_map<Translation, nlohmann::json> translationFiles;

    static inline std::string enLangFile = "en_lang.json";
    static inline std::string frLangFile = "fr_lang.json";
    static inline std::string deLangFile = "de_lang.json";
};

inline auto operator"" _i18n(const char* lookupStr, size_t) {
    return Internationalization::lookupTranslation(lookupStr);
}

inline auto operator"" _contain(const char* str, size_t) {
    return '<' + str + '>';
}