#include <iostream>
#include <windows.h>
#include <comdef.h>
#include <Mmsystem.h>
#include <stdio.h>
#include <conio.h>
#include <intrin.h>



bool path_pointer  []  = {false, false, false, false};

using namespace std;
void draw(HWND hwnd, HDC hdc);
void setConsoleSize();







class Mesh {
    public:
        int x, y;
        float size = 100;


        Mesh(int _x=0, int _y=0) {
            x = _x;
            y = _y;
        }
        
        void set_size(float _size) { size = _size; }

        void set_position(int _x, int _y) { x = _x; y = _y; }

        void set(int _x = NULL, int _y = NULL, float _size = NULL) {
            if (_x != NULL && _y != NULL) {
                set_position(_x, _y);
            }
            else if (_size != NULL) {
                set_size(_size);

            }
        }
        
        virtual void Render(HWND console) = 0;

};



class Player: public Mesh
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





void main()
{
    SetConsoleTitle(L"Simple Rectangle Drawing");
    HWND hwnd = GetConsoleWindow();
    HDC hdc = GetDC(hwnd);
    setConsoleSize(); // задание размеров консоли
    Sleep(100);
    int iKey = 1;
    rectangle.set(10, 10, 100);
    Sleep(10);
    ReleaseDC(hwnd, hdc); //освобождаем дескрипторы консоли
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






