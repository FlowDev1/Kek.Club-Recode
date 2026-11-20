#include "Initializer.h"

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID) {
    if (fdwReason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hinstDLL);
        ApplicationModel::Core::CoreApplication::MainView().CoreWindow().Dispatcher().RunAsync(
            UI::Core::CoreDispatcherPriority::Normal,
            [=] {
                Initializer::initializeClient(hinstDLL);
            }
        );
    }
    return TRUE;
}