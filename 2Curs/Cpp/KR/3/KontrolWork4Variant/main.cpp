#include "sqlite3.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <math.h>
#include <malloc.h>

//
//    const elements
//

// parameter of the list commands
const char MainMenu[3][1][30] = {
    {"Key Combinations"},
    {"Information by the date"},
    {"Exit"}
};


// colors typing
#define RESET   "\033[1;32m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define DBLUE   "\033[1;36m"
#define BLACK   "\033[1;30m"
#define WHITE   "\033[1;37m"
#define PURPLE  "\033[1;35m"
#define BROWN   "\033[0;33m"



//-------------------------------------------------------------------------------------------------
//
// .h

void LEFT_RIGHT_BORGER(HANDLE console, int col);
void MAINMENU(HANDLE console);

void set_cursore_pos(HANDLE console, int x, int y);
void cls(HANDLE hConsole);
void setConsoleSize(int x, int y);

int GetMainCommand(HANDLE console);

//
//-------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------
//
//                                        INTERFAISE DRAW
//
//-------------------------------------------------------------------------------------------------


//start area # MAIN MENU 

void LEFT_RIGHT_BORGER(HANDLE console, int col){
    set_cursore_pos(console,0,col);
    printf("|");
    set_cursore_pos(console,105,col);
    printf("|");
}

void DRAW_THE_INPUT_MESSAGE(HANDLE console){
    set_cursore_pos(console,40,3);
    printf("%sthe program can record key combinations in the %s",PURPLE,RESET);
    set_cursore_pos(console,40,4);
    printf("%sbackground and write them to the database registry %s",PURPLE,RESET);
    set_cursore_pos(console,40,5);
    printf("%swriting occurs for combinations that are in the%s",PURPLE,RESET);
    set_cursore_pos(console,40,6);
    printf("%sthe registry can be expanded by adding a combination%s",PURPLE,RESET);
    set_cursore_pos(console,40,7);
    printf("%sin the program%s",PURPLE,RESET);
} 

void DRAW_THE_INPUT_CURSORE(HANDLE console){
    set_cursore_pos(console,10,10);
    printf("%sTo execute the command, enter its index in the list%s",WHITE,RESET);
    set_cursore_pos(console,10,11);
    printf("%sSelect a command to execute >>: %s",WHITE,RESET);
}


void DRAW_THE_COMMAND_LIST(HANDLE console){
    set_cursore_pos(console,3,3);
    printf("%sCOMMANDS%s",RED,RESET);
    set_cursore_pos(console,3,4);
    for (int i = 0; i < 3; i++){
        set_cursore_pos(console,3,4+i);
        printf("%s[%d] %s %s",WHITE, i ,MainMenu[i][0] , RESET);
    }
}



void MAINMENU(HANDLE console){
    set_cursore_pos(console,0,1);
    printf("/--------------------------------------------------------------------------------------------------------\\");
    for (int i = 2; i < 27; i++ ){
        LEFT_RIGHT_BORGER(console, i);
    }
    set_cursore_pos(console,0,27);

    printf("\\--------------------------------------------------------------------------------------------------------/");
    DRAW_THE_COMMAND_LIST(console);
    DRAW_THE_INPUT_MESSAGE(console);
    DRAW_THE_INPUT_CURSORE(console);
}

// end area # MAIN MENU 







//-------------------------------------------------------------------------------------------------
//
//                                        UTILS
//
//-------------------------------------------------------------------------------------------------

void set_cursore_pos(HANDLE hStdOut, int x, int y){
    COORD set = {(short)x,(short)y};
    SetConsoleCursorPosition(hStdOut, set);
}


void cls(HANDLE hConsole)
{
    COORD coordScreen = {0,0}; // начальное положение курсора
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;
    DWORD cCharsWritten;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y; // количество
    // символьных ячеек в буфере консоли
    FillConsoleOutputCharacter(hConsole,(TCHAR)' ',dwConSize, coordScreen, &cCharsWritten);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes,dwConSize, coordScreen, &cCharsWritten);
    SetConsoleCursorPosition(hConsole, coordScreen);
}

void setConsoleSize(int x = 400, int y = 600) // Задание размеров окна консоли row = 106 col = 29
{
    HWND hWnd = GetConsoleWindow();
    HWND hwnd;
    TCHAR Title[1024];
    GetConsoleTitle(Title, 1024); // Узнаем имя окна
    hwnd = FindWindow(NULL, Title); // Узнаем hwnd окна
    MoveWindow(hwnd, 0, 0, 800, 500, TRUE);
    system("color 0A");
}


//-------------------------------------------------------------------------------------------------
//
//                                     COMANDS ZONE
//
//-------------------------------------------------------------------------------------------------





int GetMainCommand(HANDLE console){
    cls(console);
    MAINMENU(console);

    int answer;
    printf("%s",RED);
    scanf("%d", &answer);
    printf("%s",RESET);
    return answer;

}






int main(void) {
    setConsoleSize();
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    
    int link = GetMainCommand(console);


    system("pause");
}