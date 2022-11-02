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
            std::cout << "Клавіша 9 заблокована" << std::endl;
        }
        else {
            std::cout << "Клавіша 9 розблокована" << std::endl;
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

        case VK_F9:
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


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    MEMORYSTATUS statex;

    GlobalMemoryStatus(&statex);

    std::cout << "Завдання 1 ";
    std::cout << "\n\nВідеокарта                             =: " << getGpuName() << std::endl;
    std::cout << "Процессор                              =: " << getCpuName() << std::endl;
    std::cout << "Кількість ядер процессора              =: " << getCpuCoreCount() << std::endl;
    printf("\nІнформація про стан фізичної та віртуальної памяті\n\n");
    printf("Використовувана фізична пам'ять        =: %ld (procents)\n", statex.dwMemoryLoad);
    printf("Розмір структури                       =: %ld (procents)\n", statex.dwLength);
    printf("Обсяг фактичної фізичної пам'яті       =: %*ld MB\n", WIDTH, statex.dwTotalPhys / 1048576);
    printf("Розмір вільної фізичної пам’яті        =: %*ld MB\n", WIDTH, statex.dwAvailPhys / 1048576);
    printf("Розмір файлу підкачки                  =: %*ld MB\n", WIDTH, statex.dwTotalPageFile / 1048576);
    printf("Вільний розмір файлу підкачки          =: %*ld MB\n", WIDTH, statex.dwAvailPageFile / 1048576);
    printf("Користувацькі байти адресного простору =: % *ld ГB\n", WIDTH, statex.dwTotalVirtual / 1048576 / 1024);
    printf("Вільні байти користувача               =: %*ld ГB\n", WIDTH, statex.dwAvailVirtual / 1048576 / 1024);

    DWORD d = GetLogicalDrives();
    std::cout << "\nІснуючі томи жорстких дисків \n\n";
    int i, index = 0;
    char drive[] = "A:\\";
    for (i = 0; i < 26; i++) {
        if (d & (1 << i)) {
            drive[0] = 'A' + i;
            std::cout << drive << " ";
        }
    }
    std::cout << "\n\n";



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
