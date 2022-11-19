#include <iostream>
#include <windows.h>
#include <comdef.h>
#include <Mmsystem.h>
#include <stdio.h>
#include <conio.h>
#include <intrin.h>
#include <thread>
#include <math.h>



int MAX_Y = 1000;
int MAX_X = 800;
float speed = 3.0f;

POINT cursor;

// top right bottom left

bool path_pointer  []  = {false, true, false, false};

using namespace std;
void draw(HWND hwnd, HDC hdc);
void setConsoleSize();

HWND hwnd;
HDC hdc;

bool EXIT_STATUS = false;
bool HOOK_STATUS = false;


class Point{
public:
    float x,y;
    Point(float _x, float _y) {x = _x; y = _y;}
};


class Mesh {
    public:
        double x, y;
        double size = 100;


        Mesh(double _x=0, double _y=0) {
            x = _x;
            y = _y;
        }
        
        void set_size(double _size) { size = _size; }

        void set_position(double _x, double _y) {
            if (_x <= MAX_X) {
                x = _x;
            }
            if (_y <= MAX_Y) {
                y = _y;
            }
        }

        void set(double _x = NULL, double _y = NULL, double _size = NULL) {
            if (_x != NULL && _y != NULL) {
                set_position(_x, _y);
            }
            else if (_size != NULL) {
                set_size(_size);

            }
        }
        
        virtual void Render(HWND console) = 0;

};

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


class Player : public Mesh
{

public:
    Player() {
    }

    void Render(HWND console) {
        Rectangle(GetDC(console), x, y, x + size, y + size);
    }


private:





};

//Mesh rectangle = Mesh(10, 10);

Player rectangle = Player();







void main(){
    SetConsoleTitle(L"Simple Rectangle Drawing");
    hwnd = GetConsoleWindow();
    hdc = GetDC(hwnd);
    SetWindowPos(hwnd, 0, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

    //setConsoleSize(); // задание размеров консоли
    Sleep(100);

    rectangle.set(100, 100, 100);

    ReleaseDC(hwnd, hdc);



    while (!EXIT_STATUS) {
        draw(hwnd, hdc);
        ClearScreen();
        if (path_pointer[1]) {
            rectangle.set_position(rectangle.x + speed, rectangle.y);
        }
        else if (path_pointer[0]) {
            rectangle.set_position(rectangle.x, rectangle.y- speed);

        }
        Sleep(2);
    
    }


//освобождаем дескрипторы консоли
}

// Функция рисования. Помещайте сюда всю графику
void draw(HWND hwnd, HDC hdc)
{
    rectangle.Render(hwnd);


}
void setConsoleSize() // Задание размеров окна консоли
{
    const int colConsole = 400;
    const int rowConsole = 600;
    HANDLE hNdl = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT windowSize = { 0,0,colConsole - 1,rowConsole - 1 };
    SetConsoleWindowInfo(hNdl, TRUE, &windowSize);
    COORD bufferSize = { colConsole, rowConsole }; // размеры буфера
    SetConsoleScreenBufferSize(hNdl, bufferSize);
}






