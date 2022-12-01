#include <iostream>
#include <windows.h>
#include <intrin.h>
#include <comdef.h>
#include <Mmsystem.h>
#include <stdio.h>
#include <conio.h>
#define WIDTH 7
#define _WIN32_WINNT 0x050


const std::string sound = "WindowsExclamation.wav";

bool shiftPressed = false;
bool altPressed = false;
bool f9Pressed = false;

bool keyLocked = false;

void UpdateLock() {

    if (shiftPressed && altPressed && f9Pressed) {
        keyLocked = !keyLocked;

        shiftPressed = false;
        altPressed = false;
        f9Pressed = false;

        if (keyLocked) {
            std::cout << "Key 9 is locked" << std::endl;
        }
        else {
            std::cout << "Key 9 is unlocked" << std::endl;
        }
    }
}

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {

    if (nCode == HC_ACTION) {
        KBDLLHOOKSTRUCT* details = (KBDLLHOOKSTRUCT*)lParam;

        switch (details->vkCode) {
        case VK_RMENU:

            altPressed = true;
            break;

        case VK_RSHIFT:
            if (!shiftPressed) {
                shiftPressed = true;
            }
            break;

        case VK_F10:
            if (shiftPressed && !f9Pressed) {
                f9Pressed = true;
            }
            break;
        }


        UpdateLock();
        if (wParam == WM_KEYDOWN) {
            if (details->vkCode == 0x39) {
                if (keyLocked) {
                    return 1;
                }
            }
        }
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}



int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    HHOOK hook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, 0, 0);
    MSG msg;
    while (GetMessage(&msg, NULL, NULL, NULL) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    UnhookWindowsHookEx(hook);
    return 1;
}


