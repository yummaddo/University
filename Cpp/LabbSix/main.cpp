#include <iostream>
#include <windows.h>
#include <intrin.h>
#include <comdef.h>
#include <Mmsystem.h>
#include <stdio.h>
#include <conio.h>

#define DIV 1024
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
        if (keyLocked) {
            PlaySoundA(sound.c_str(), NULL, SND_FILENAME | SND_ASYNC);
            std::cout << "Клавіша 9 заблокована" << std::endl;
        }
        else {
            PlaySoundA(sound.c_str(), NULL, SND_FILENAME | SND_ASYNC);
            std::cout << "Клавіша 9 розблокована" << std::endl;
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
            case VK_RSHIFT:
                if (!shiftPressed) {
                    shiftPressed = true;
                }
                break;
            case VK_RMENU:
                if (!altPressed && shiftPressed) {
                    altPressed = true;
                }
                break;
            case VK_F9:
                if (!f9Pressed && altPressed && shiftPressed) {
                    f9Pressed = true;
                }
                break;
            }
            break;
        case WM_KEYUP:
        case WM_SYSKEYUP:
            switch (details->vkCode) {
            case VK_RSHIFT:
                shiftPressed = false;
                break;
            case VK_RMENU:
                altPressed = false;
                break;
            case VK_F9:
                f9Pressed = false;
                break;
            }
            break;
        }
        UpdateLock();
        if (wParam == WM_KEYDOWN) {
            if (details->vkCode == 0x37) {
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
    _bstr_t b2(dd.DeviceString);
    const char* c2 = b2;
    return std::string(c2);
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




    std::cout << "Завдання 1 ";
    std::cout << "\n\nВідеокарта                    =: " << getGpuName() << std::endl;
    std::cout << "Процессор                     =: " << getCpuName() << std::endl;
    std::cout << "Кількість ядер процессора     =: " << getCpuCoreCount() << std::endl;
    std::cout << "Кількість оперативної пам'яті =: " << getTotalRam() << " MB" << std::endl;
    DWORD d = GetLogicalDrives();
    std::cout << "Існуючі томи жорстких дисків ";
    int i, index = 0;
    char drive[] = "A:\\";
    for (i = 0; i < 26; i++) {
        if (d & (1 << i)) {
            drive[0] = 'A' + i;
            std::cout << "\n";
            std::cout << ++index << "  " << drive << " ";
        }
    }
    //MEMORYSTATUS statex;

    //GlobalMemoryStatus(&statex);

    //printf("%ld percent of memory in use   \n", statex.dwMemoryLoad);
    //printf("%ld sizeof  bytes\n", statex.dwLength);
    //printf("%*ld  %s bytes of physical memory \n", WIDTH, statex.dwTotalPhys / DIV);
    //printf("%*ld  %s free physical memory bytes\n", WIDTH, statex.dwAvailPhys / DIV);
    //printf("%*ld  %s bytes of paging file \n", WIDTH, statex.dwTotalPageFile / DIV);
    //printf("%*ld  %s free bytes of paging file  \n", WIDTH, statex.dwAvailPageFile / DIV);
    //printf("%*ld  %s user bytes of address space \n", WIDTH, statex.dwTotalVirtual / DIV);
    //printf("%*ld  %s free user bytes \n", WIDTH, statex.dwAvailVirtual / DIV);


    //_getch();


    std::cout << "Завдання 2 \n\n";

    HHOOK hook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, 0, 0);
    MSG msg;
    while (GetMessage(&msg, NULL, NULL, NULL) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    UnhookWindowsHookEx(hook);
    return 1;
}



