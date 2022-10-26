#include <iostream>
#include "stdio.h"
#include <windows.h>
#include <intrin.h>
#include <comdef.h>
#include <Mmsystem.h>

#pragma comment(lib, "winmm.lib")


const std::string sound = "WindowsExclamation.wav";


bool shiftPressed = false;
bool altPressed = false;
bool f5Pressed = false;

bool keyLocked = false;



void UpdateLock() {
    if (shiftPressed && altPressed && f5Pressed) {
        keyLocked = !keyLocked;
        if (keyLocked) {
            std::cout << "Клавіша 4 заблокована" << std::endl;
        }
        else {
            std::cout << "Клавіша 4 розблокована" << std::endl;
        }
    }
}

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        KBDLLHOOKSTRUCT* details = (KBDLLHOOKSTRUCT*)lParam;
        switch (wParam) {
        case WM_KEYDOWN:
        case WM_SYSKEYDOWN:
            switch (details->vkCode) {
            case VK_LSHIFT:
                if (!shiftPressed) {
                    shiftPressed = true;
                }
                break;
            case VK_LMENU:
                if (!altPressed && shiftPressed) {
                    altPressed = true;
                }
                break;
            case VK_F5:
                if (!f5Pressed && altPressed && shiftPressed) {
                    f5Pressed = true;
                }
                break;
            } break;
        case WM_KEYUP:
        case WM_SYSKEYUP:
            switch (details->vkCode) {
            case VK_LSHIFT:
                shiftPressed = false;
                break;
            case VK_LMENU:
                altPressed = false;
                break;
            case VK_F5:
                f5Pressed = false;
                break;
            } break;
        }
        UpdateLock();
        if (wParam == WM_KEYDOWN) {
            if (details->vkCode == 0x34) {
                if (keyLocked) {
                    return 1;
                }
            }
        }
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}


std::string getGpuName() {
    DISPLAY_DEVICE dd = { sizeof(dd), 0 };
    EnumDisplayDevices(NULL, 0, &dd, EDD_GET_DEVICE_INTERFACE_NAME);

    return dd.DeviceString;
}

std::string getCpuName() {
    int cpuInfo[4] = { -1 };
    unsigned nExIds, i = 0;
    char cpuName[0x40];
    __cpuid(cpuInfo, 0x80000000);
    nExIds = cpuInfo[0];
    for (i = 0x80000000; i <= nExIds; ++i)
    {
        __cpuid(cpuInfo, i);
        if (i == 0x80000002)
            memcpy(cpuName, cpuInfo, sizeof(cpuInfo));
        else if (i == 0x80000003)
            memcpy(cpuName + 16, cpuInfo, sizeof(cpuInfo));
        else if (i == 0x80000004)
            memcpy(cpuName + 32, cpuInfo, sizeof(cpuInfo));
    }
    return cpuName;
}

short getCpuCoreCount() {
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    return sysInfo.dwNumberOfProcessors;
}

float getTotalRam() {
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);
    GlobalMemoryStatusEx(&statex);
    return statex.ullTotalPhys / 1048576;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    std::cout << "Lab6 заваднняNo1 ";
    std::cout << "\n\nВідеокарта: " << getGpuName() << std::endl;
    std::cout << "\nПроцессор: " << getCpuName() << std::endl;
    std::cout << "\nКількість ядер процессора: " << getCpuCoreCount() << std::endl;
    std::cout << "\nКількість оперативної пам'яті: " << getTotalRam() << " MB" << std::endl;
    DWORD d = GetLogicalDrives();
    std::cout << "\nІснуючі томи жорстких дисків ";
    int i, index = 0;
    char drive[] = "A:\\";
    for (i = 0; i < 26; i++) {
        if (d & (1 << i)) {
            drive[0] = 'A' + i;
            std::cout << "\n";
            std::cout << "[" << ++index << "]  " << drive << " ";
        }
    }
    std::cout << "\n\n";

    std::cout << "Lab6 заваднняNo2 \n\n";
    HHOOK hook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, 0, 0);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    UnhookWindowsHookEx(hook);


}
