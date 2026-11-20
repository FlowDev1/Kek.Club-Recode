#pragma once

using namespace winrt::Windows::Data::Xml::Dom;
using namespace winrt::Windows::UI::Notifications;

#define ClientAssert(condition, message)                                                        \
    do {                                                                                        \
        if (!(condition)) {                                                                     \
            logF("Assertion failed at {}:{} - {}", __FILE__, __LINE__, xorstr(message)); \
            assert((condition) && "Assertion failed");                                          \
        }                                                                                       \
    } while (0)

namespace Utils {
    static void displayToastNotification(const std::string& title, const std::string& text, const int duration) {
        const XmlDocument toastXml{ToastNotificationManager::GetTemplateContent(ToastTemplateType::ToastText02)};
        const XmlNodeList textNodes{toastXml.GetElementsByTagName(L"text")};
        textNodes.Item(0).InnerText(winrt::to_hstring(title));
        textNodes.Item(1).InnerText(winrt::to_hstring(text));

        const ToastNotification toastNotification{toastXml};
        const auto now = winrt::clock::now();
        const auto expiration = now + std::chrono::seconds(duration);
        toastNotification.ExpirationTime(expiration);

        ToastNotificationManager::CreateToastNotifier().Show(toastNotification);
    }
}