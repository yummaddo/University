#include <windows.h>
#include <iostream>
#include <cmath>
#include <time.h>
#include <thread>


int delta_y_to_X_AXIS = 300;
int delta_x_to_Y_AXIS = 600;
int Step_int_gerc = 54;
int Step_int_numbers = 25;


void Draw_the_Coord(HWND hWnd, int _axis_y = 25, int _axis_x = 1000, int R=0) {
    HPEN hPen;
    HDC hDC = GetDC(hWnd);
    float Axis_y = (float)_axis_y;
    float Axis_x = (float)_axis_x/10;
    R = rand() % 2;
    printf("R = %d :: Частота = 54.5гц :: ромірність Y : %f  розмірність X : %f МГЦ", R, (float)Axis_y, (float)(Axis_x * 10) / 1000);
    hPen = CreatePen(PS_SOLID, 1, RGB(200, 0, 37));
    SelectObject(hDC, hPen);
    // x axis
    POINT x_ptsEnd = { 2000, delta_y_to_X_AXIS };
    MoveToEx(hDC, 0, delta_y_to_X_AXIS, (LPPOINT)NULL);
    LineTo(hDC, x_ptsEnd.x, x_ptsEnd.y);
    // y axis
    hPen = CreatePen(PS_SOLID, 1, RGB(200, 95, 25));
    SelectObject(hDC, hPen);
    POINT y_ptsEnd = { delta_x_to_Y_AXIS, 2000 };
    MoveToEx(hDC, delta_x_to_Y_AXIS, 0, (LPPOINT)NULL);
    LineTo(hDC, y_ptsEnd.x, y_ptsEnd.y);
    hPen = CreatePen(PS_SOLID, 1, RGB(177, 172, 200));
    SelectObject(hDC, hPen);
    for (float i = 0; i < 2000; i += Axis_x) {
        MoveToEx(hDC, i, delta_y_to_X_AXIS - 5, (LPPOINT)NULL);
        LineTo(hDC, i, delta_y_to_X_AXIS) + 5;
    }
    for (float i = 0; i < 2000; i += Axis_y) {
        MoveToEx(hDC, delta_x_to_Y_AXIS - 5, i, (LPPOINT)NULL);
        LineTo(hDC, delta_x_to_Y_AXIS + 5, i);
    }

}


void Draw_the_ATL(HWND hWnd, int _axis_y = 25, int _axis_x = 1000, int R = 0) {
    PAINTSTRUCT ps;
    POINT op;
    HDC hDC = GetDC(hWnd);
    HPEN hPen;
    float Axis_y = (float)_axis_y;
    float Axis_x = (float)_axis_x;
    float y;
    float x = (-delta_x_to_Y_AXIS) * (Axis_x / 1000);;

    hPen = CreatePen(PS_SOLID, 1, RGB(0, 200, 183));
    SelectObject(hDC, hPen);
    srand(time(NULL));
    y = 50 * (cos(x / 10) + R * cos(x / 5)) + 150;
    MoveToEx(hDC, 0, delta_x_to_Y_AXIS + y, &op);

    float delat_y = (float)Step_int_numbers / (float)Axis_y;
    for (float i = -delta_x_to_Y_AXIS; i < 1000; i += 1)
    {
        x = i * (Axis_x / 1000);
        y = 50 * (cos(x / 10) + R * cos(x / 5)) + 150;
        y = y * delat_y; // підганяємо лінію до потрібного значення в залежності від розмірності
        LineTo(hDC, delta_x_to_Y_AXIS + i, delta_y_to_X_AXIS + y);
        MoveToEx(hDC, delta_x_to_Y_AXIS + i, delta_y_to_X_AXIS + y, &op);
        
        Sleep(5);
    }

    ReleaseDC(hWnd, hDC);
}


void ClearScreen()
{
    HANDLE                     hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD                      count;
    DWORD                      cellCount;
    COORD                      homeCoords = { 0, 0 };

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE) return;

    /* Get the number of cells in the current buffer */
    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    /* Fill the entire buffer with spaces */
    if (!FillConsoleOutputCharacter(
        hStdOut,
        (TCHAR)' ',
        cellCount,
        homeCoords,
        &count
    )) return;

    /* Fill the entire buffer with the current colors and attributes */
    if (!FillConsoleOutputAttribute(
        hStdOut,
        csbi.wAttributes,
        cellCount,
        homeCoords,
        &count
    )) return;

    /* Move the cursor home */
    SetConsoleCursorPosition(hStdOut, homeCoords);
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    HWND hWnd = GetConsoleWindow();
    HWND hwnd;
    TCHAR Title[1024];
    GetConsoleTitle(Title, 1024); // Узнаем имя окна
    hwnd = FindWindow(NULL, Title); // Узнаем hwnd окна
    MoveWindow(hwnd, 0, 0, 1800, 1000, TRUE);

    system("color 0A");
    int x, y, R;
    R = rand() % 2;
    Draw_the_Coord(hWnd, 25, 1000); 
    printf("  Введіть розмірність Y, X гц =");
    std::cin >> y;
    std::cin >> x;
    ClearScreen();
    Draw_the_Coord(hWnd, 25, 1000);
    Draw_the_ATL(hWnd, y, x, R);
    while (true) {

    }
    return 1;

}