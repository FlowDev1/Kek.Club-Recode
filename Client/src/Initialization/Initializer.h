#pragma once

class Initializer {
public:
    static DWORD WINAPI ejectThread(LPVOID);
    static void initializeClient(HMODULE hinstDLL);
    static void ejectClient();

    static inline HMODULE hinstDLL = nullptr;
    static inline bool eject = false;
    static inline bool isRunning = true;
};