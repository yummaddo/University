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

// data base elements 
sqlite3 *db;
int try_numbers = 0;
char *zErrMsg = 0;
int rc;
char *sql;
const char* data = "";


// information from data base 
struct CombinesLog{
    char combine[50];
    char date[50];
};

char **Combines;
int Combines_size = 0;
CombinesLog *Log;
int Log_size = 0;

// parameter of the list commands
const char MainMenu[3][1][30] = {
    {"Key Combinations"},
    {"Information by the date"},
    {"Exit"}
};
const char RegisterMenu[4][1][30] = {
    {"Add key combination"},
    {"Delete key combination"},
    {"View all"},
    {"Exit"}
};
const char InformationMenu[3][1][35] = {
    {"Viev all"},
    {"Viev by index int register data"},
    {"Exit"}
};


// exit point
int EXIT_STATUS = 0;
int EXIT_REGISTER_STATUS = 0;
int EXIT_INFORMATION_STATUS = 0;
int EXIT_ADD_COMBINATION_STATUS = 0;

// point of error massage
int MAIN_MENU_STATUS = -1;
int REGISTER_MENU_STATUS = -1;
int INFORMATION_MENU_STATUS = -1;
int ADD_COMBINATION_MENU_STATUS = -1;

// add string 
char execute_add_string[50]; 
char splited_execute_add_string[6][10];
int  splited_execute_add_number = 0;
// 
char _CTRL_left[] = "lctr";
char _CTRL_right[] = "rctr"; 
char _CTRL[] = "ctr"; 
char _ALT_left[] = "lalt";
char _ALT_right[] = "ralt";
char _ALT[] = "alt";
char _SHIFT_left[] = "lshift";
char _SHIFT_right[] = "rshift";
char _SHIFT[] = "shift";
char _ESC[] = "esc";
char _F1[] = "f1";
char _F2[] = "f2";
char _F3[] = "f3";
char _F4[] = "f4";
char _F5[] = "f5";
char _F6[] = "f6";
char _F7[] = "f7";
char _F8[] = "f8";
char _F9[] = "f9";
char _F10[] = "f10";
char _F11[] = "f11";
char _F12[] = "f12";

char *keys_combine[] = {
    _CTRL_left,
    _CTRL_right,
    _CTRL,
    _ALT_left,
    _ALT_right,
    _ALT,
    _SHIFT_left,
    _SHIFT_right,
    _SHIFT,
    _ESC,
    _F1,
    _F2,
    _F3,
    _F4,
    _F5,
    _F6,
    _F7,
    _F8,
    _F9,
    _F10,
    _F11,
    _F12
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
//-------
void LEFT_RIGHT_BORGER(HANDLE console, int col);
void DRAW_THE_INPUT_CURSORE(HANDLE console);
void DRAW_THE_INPUT_MESSAGE(HANDLE console);
void DRAW_THE_COMMAND_LIST(HANDLE console);
void DRAW_THE_ERROR(HANDLE console);
void MAINMENU(HANDLE console,int INPUT_ERROR );
//-------
void set_cursore_pos(HANDLE console, int x, int y);
void cls(HANDLE hConsole);
void setConsoleSize(int x, int y);
void splite_the_execute_str();
//-------
int GetMainCommand();
void Sesion();
//-------
void RegisterSesionProces();
void RegisterSesion();
//-------
void REGISTER_DRAW_THE_COMMAND_LIST(HANDLE console);
void REGISTER_MENU(HANDLE console, int INPUT_ERROR);
//-------
void ADD_MSG(HANDLE console);
void ADD_ELEMENT_RENDER(HANDLE console);
void ADD_MSG_ADDED_COMBINATION(HANDLE console);
//-------
void DELETE_MSG(HANDLE console);
void DELETE_ELEMENT_RENDER(HANDLE console);

//-------
void VIEV_MSG(HANDLE console);
void VIEV_ELEMENT_RENDER(HANDLE console);
void VIEV_REGISTER_DATA(HANDLE console);
//-------
void InformationSesionProces();
void InformationSesion();
//-------
void INFORAMTION_DRAW_THE_COMMAND_LIST(HANDLE console);
void VIEV_ALL_ELEMENT_INFORMATION_RENDER(HANDLE console);
void VIEV_BY_INDEX_ELEMENT_INFORMATION_RENDER(HANDLE console);
void VIEV_COME_BACK_MSG(HANDLE console);
void VIEV_GET_INDEX_MSG(HANDLE console);
//-------
void render_add_proces(HANDLE console);
void render_viev_by_index_proces(HANDLE console);
void render_viev_all_proces(HANDLE console);
// data base 
void create_table_if_not_exists();
void get_log_information();
void get_combines_information();
static int AddLogInHash(void *data, int argc, char **argv, char **azColName);
static int AddCombinesInHash(void *data, int argc, char **argv, char **azColName);
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

void DRAW_THE_ERROR(HANDLE console){
    set_cursore_pos(console,15,9);
    printf("COMAND DONST FOUND");
}

void MAINMENU(HANDLE console, int INPUT_ERROR){

    set_cursore_pos(console,0,1);
    printf("/-MAIN-MENU-----------------------------------------------------------------------------------------------\\");
    for (int i = 2; i < 27; i++ ){
        LEFT_RIGHT_BORGER(console, i);
    }
    set_cursore_pos(console,0,27);

    printf("\\--------------------------------------------------------------------------------------------------------/");
    if (INPUT_ERROR == 1){
        DRAW_THE_ERROR(console);
    }
    DRAW_THE_COMMAND_LIST(console);
    DRAW_THE_INPUT_MESSAGE(console);
    DRAW_THE_INPUT_CURSORE(console);
}
// end area # MAIN MENU 
//-------------------------------------------------------------------------------------------------
// start area # REGISTER MENU 
void REGISTER_MENU(HANDLE console, int INPUT_ERROR){
    set_cursore_pos(console,0,1);
    printf("/--------------------------------------------------------------------------------------------------------\\");

    for (int i = 2; i < 27; i++ ){
        LEFT_RIGHT_BORGER(console, i);
    }
    set_cursore_pos(console,0,27);
    printf("\\-REGISTER-MENU------------------------------------------------------------------------------------------/");
    if (INPUT_ERROR == 1){
        DRAW_THE_ERROR(console);
    }
    REGISTER_DRAW_THE_COMMAND_LIST(console);
    DRAW_THE_INPUT_CURSORE(console);
}

void REGISTER_DRAW_THE_COMMAND_LIST(HANDLE console){
    set_cursore_pos(console,3,3);
    printf("%sCOMMANDS%s",RED,RESET);
    set_cursore_pos(console,3,4);
    for (int i = 0; i < 4; i++){
        set_cursore_pos(console,3,4+i);
        printf("%s[%d] %s %s",WHITE, i ,RegisterMenu[i][0] , RESET);
    }
}
// end area # REGISTER MENU 
//-------------------------------------------------------------------------------------------------

void INFORMATION_MENU(HANDLE console, int INPUT_ERROR){
    set_cursore_pos(console,0,1);
    printf("/--------------------------------------------------------------------------------------------------------\\");

    for (int i = 2; i < 27; i++ ){
        LEFT_RIGHT_BORGER(console, i);
    }
    set_cursore_pos(console,0,27);
    printf("\\-INFORMATION-MENU---------------------------------------------------------------------------------------/");
    if (INPUT_ERROR == 1){
        DRAW_THE_ERROR(console);
    }
    INFORAMTION_DRAW_THE_COMMAND_LIST(console);
    DRAW_THE_INPUT_CURSORE(console);
}

void INFORAMTION_DRAW_THE_COMMAND_LIST(HANDLE console){
    set_cursore_pos(console,3,3);
    printf("%sCOMMANDS%s",RED,RESET);
    set_cursore_pos(console,3,4);
    for (int i = 0; i < 3; i++){
        set_cursore_pos(console,3,4+i);
        printf("%s[%d] %s %s",WHITE, i ,InformationMenu[i][0] , RESET);
    }
}
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

void splite_the_execute_str(){ // func splited the string
    // get the "ctrl-shift-f9" transform into --> {"ctrl" , "shift" , "f9"}
    int index = 0;
    int str_index = 0;
    int curent_str_index = 0;
    while (execute_add_string[index] != '\0')
    {
        if (execute_add_string[index] != '-') {
            splited_execute_add_string[curent_str_index][str_index] = execute_add_string[index];
            str_index++;index++;
        } else {
            splited_execute_add_string[curent_str_index][str_index+1] = '\0';
            str_index = 0;curent_str_index++;index++;
        }
    }
    splited_execute_add_number = curent_str_index+1;
}
//-------------------------------------------------------------------------------------------------
//
//                                     REGISTER SESION
//
//-------------------------------------------------------------------------------------------------

void RegisterSesion(){
    while (!EXIT_REGISTER_STATUS)
    {
        RegisterSesionProces();
    }
}

void RegisterSesionProces(){
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    cls(console);

     if (REGISTER_MENU_STATUS == -1){
        REGISTER_MENU(console,REGISTER_MENU_STATUS);

    } else if (REGISTER_MENU_STATUS == 0) {
        REGISTER_MENU(console,1);

    }

    int answer = GetMainCommand();

    if (answer == 0 ){ // add
        REGISTER_MENU_STATUS = -1;
        while (!EXIT_ADD_COMBINATION_STATUS)
        {
            render_add_proces(console);
        }
        
        
    } else if (answer == 1) { // delete
        REGISTER_MENU_STATUS = -1;
        DELETE_ELEMENT_RENDER(console);


    } else if (answer == 2) { // viev
        REGISTER_MENU_STATUS = -1;
        VIEV_ELEMENT_RENDER(console);
    
    } else if (answer == 3) { // exit
        EXIT_REGISTER_STATUS = 1;
        REGISTER_MENU_STATUS = -1;

    } else {
        REGISTER_MENU_STATUS = 0;
    }
}





// ADD
void ADD_MSG(HANDLE console){
    set_cursore_pos(console, 4,4);
    printf("%sPress the command like ( lctr-ralt-f9 )(inpute 0 to come back)%s",WHITE, RESET);
    set_cursore_pos(console, 4,5);
}

void ADD_ELEMENT_RENDER(HANDLE console) {
    cls(console);
    set_cursore_pos(console, 0,1);
    printf("/--------------------------------------------------------------------------------------------------------\\");
    for (int i = 2; i < 27; i++ ){
        LEFT_RIGHT_BORGER(console, i);
    }
    printf("\\-REGISTER-MENU-ADD-------------------------------------------------------------------------------------/");

    ADD_MSG(console);
}

void ADD_MSG_ADDED_COMBINATION(HANDLE console){
    set_cursore_pos(console,4,7);
    printf("%s[asf]",execute_add_string);
    for (int i = 0; i < splited_execute_add_number; i++){
        set_cursore_pos(console,4,8+i);
        printf("1-%s",splited_execute_add_string[i]);
    }

}

void render_add_proces(HANDLE console){
    ADD_ELEMENT_RENDER(console);
    scanf("%s",&execute_add_string);  // get msg for execute into db
    set_cursore_pos(console, 4,6);

    if (ADD_COMBINATION_MENU_STATUS == 1){
        ADD_MSG_ADDED_COMBINATION(console);
    }
    if (execute_add_string[0] != '0'){
        ADD_COMBINATION_MENU_STATUS = 1;
        splite_the_execute_str();
    } else {
        ADD_COMBINATION_MENU_STATUS = -1;
        EXIT_ADD_COMBINATION_STATUS = 1;
    }


}
// DELETE
void DELETE_MSG(HANDLE console){
    set_cursore_pos(console, 4,4);
    printf("%sInput index of key combination %s",WHITE, RESET);
    set_cursore_pos(console, 4,5);
}

void DELETE_ELEMENT_RENDER(HANDLE console) {
    cls(console);
    printf("/--------------------------------------------------------------------------------------------------------\\");
    set_cursore_pos(console, 0,1);
    for (int i = 2; i < 27; i++ ){
        LEFT_RIGHT_BORGER(console, i);
    }
    printf("\\-REGISTER-MENU-DELETE-----------------------------------------------------------------------------------/");
    DELETE_MSG(console);
}
// VIEV
void VIEV_MSG(HANDLE console){
    set_cursore_pos(console, 4,4);
    printf("%s Inpute any string to come back into register menu%s",WHITE, RESET);
    set_cursore_pos(console, 4,5);
}

void VIEV_ELEMENT_RENDER(HANDLE console){
    cls(console);
    set_cursore_pos(console, 0,1);
    printf("/--------------------------------------------------------------------------------------------------------\\");
    for (int i = 2; i < 27; i++ ){
        LEFT_RIGHT_BORGER(console, i);
    }
    printf("\\-REGISTER-MENU-VIEV-------------------------------------------------------------------------------------/");
    VIEV_MSG(console);
}

void VIEV_REGISTER_DATA(HANDLE console){
    set_cursore_pos(console, 4,6);
    printf("COMBINATIONS");
}

//-------------------------------------------------------------------------------------------------
//
//                                     INFORMATION SESION
//
//-------------------------------------------------------------------------------------------------

void InformationSesion(){
    while (!EXIT_INFORMATION_STATUS )
    {
        InformationSesionProces();
    }
}

void InformationSesionProces(){

    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    cls(console);

     if (INFORMATION_MENU_STATUS == -1){
        INFORMATION_MENU(console,INFORMATION_MENU_STATUS);

    } else if (INFORMATION_MENU_STATUS == 0) { // if command doesnt found
        INFORMATION_MENU(console,1);

    }
    int answer = GetMainCommand();

    if (answer == 0 ){ // viev all
        INFORMATION_MENU_STATUS = -1;
        render_viev_all_proces(console);
        
    } else if (answer == 1) { // viev by index
        INFORMATION_MENU_STATUS = -1;
        render_viev_by_index_proces(console);
    
    } else if (answer == 2) { // exit
        EXIT_INFORMATION_STATUS = 1;
        INFORMATION_MENU_STATUS = -1;

    } else {
        INFORMATION_MENU_STATUS = 0;
    }
}

void VIEV_COME_BACK_MSG(HANDLE console){
    set_cursore_pos(console, 4,4);
    printf("%s Inpute any string to come back into information menu%s",WHITE, RESET);
    set_cursore_pos(console, 4,5);
}

void VIEV_ALL_ELEMENT_INFORMATION_RENDER(HANDLE console){
    cls(console);
    set_cursore_pos(console,0,1);
    printf("/--------------------------------------------------------------------------------------------------------\\");
    set_cursore_pos(console, 0,1);
    for (int i = 2; i < 27; i++ ){
        LEFT_RIGHT_BORGER(console, i);
    }
    set_cursore_pos(console, 4,3);
    VIEV_COME_BACK_MSG(console);
    printf("                                  DATA COMBINATION");
}



void render_viev_all_proces(HANDLE console){
    VIEV_ALL_ELEMENT_INFORMATION_RENDER(console);
    for (int i = 0; i < Log_size; i++){
        set_cursore_pos(console, 8,6+i);
        printf("%s[INDEX]%d [DATE]%s [COMBINE]%s %s",RED,i,Log[i].date,Log[i].combine,RESET);   
    }
    VIEV_COME_BACK_MSG(console);
    int answer = GetMainCommand();
}

void VIEV_GET_INDEX_MSG(HANDLE console){
    set_cursore_pos(console, 4,4);
    printf("%s Inpute the index %s",WHITE, RESET);
    set_cursore_pos(console, 4,5);
}

void VIEV_BY_INDEX_ELEMENT_INFORMATION_RENDER(HANDLE console){
    cls(console);
    set_cursore_pos(console,0,1);
    printf("/--------------------------------------------------------------------------------------------------------\\");
    set_cursore_pos(console, 0,1);
    for (int i = 2; i < 27; i++ ){
        LEFT_RIGHT_BORGER(console, i);
    }
    set_cursore_pos(console, 4,3);
    VIEV_GET_INDEX_MSG(console);
}

void render_viev_by_index_proces(HANDLE console){

    VIEV_BY_INDEX_ELEMENT_INFORMATION_RENDER(console);
    int answer = GetMainCommand();
    set_cursore_pos(console, 8,6);
    if (answer >= 0 && answer < Log_size){
        printf("%s[INDEX]%d [DATE]%s [COMBINE]%s %s",RED,answer,Log[answer].date,Log[answer].combine,RESET);   
    }
    VIEV_COME_BACK_MSG(console);
    set_cursore_pos(console, 4,4);
    set_cursore_pos(console, 4,20);
    set_cursore_pos(console, 4,5);
    answer = GetMainCommand();
}



//-------------------------------------------------------------------------------------------------
//
//                                     COMANDS ZONE
//
//-------------------------------------------------------------------------------------------------
int GetMainCommand(){
    int answer;
    printf("%s",RED);
    scanf("%d", &answer);
    printf("%s",RESET);
    return answer;
}

void Sesion(){
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    cls(console);

    if (MAIN_MENU_STATUS == -1){
        MAINMENU(console,0);
    } else if (MAIN_MENU_STATUS == 0) {
        MAINMENU(console,1); 
    }

    int answer = GetMainCommand();

    if (answer == 0 ){ // combination register
        MAIN_MENU_STATUS = -1;
        EXIT_REGISTER_STATUS = 0;
        RegisterSesion();

    } else if ( answer == 1) { // information
        MAIN_MENU_STATUS = -1;
        EXIT_INFORMATION_STATUS = 0;
        InformationSesion();

    } else if ( answer == 2) { // exit
        MAIN_MENU_STATUS = -1;
        EXIT_STATUS = 1;


    } else {
        MAIN_MENU_STATUS = 0;

    }

}



int main(void) {
    setConsoleSize();
    if (sqlite3_open("data.db",&db)){};

    create_table_if_not_exists();
    get_combines_information();
    get_log_information();

    while (!EXIT_STATUS){   
        Sesion();
    }
    scanf("%f");
    system("pause");
}

static int create_combines_table(void *data, int argc, char **argv, char **azColName) {
   return 0;
};
static int UpdateCallback(void *data, int argc, char **argv, char **azColName){
   return 0;
}

void create_table_if_not_exists(){
    rc = sqlite3_exec(
        db,
        "CREATE TABLE IF NOT EXISTS combines (\'id\' INTEGER NOT NULL,\'combine\' TEXT, PRIMARY KEY(\'id\' AUTOINCREMENT))",
        create_combines_table,
        0,
        &zErrMsg
    );
    rc = sqlite3_exec(
        db,
        "CREATE TABLE IF NOT EXISTS infor (\'id\' INTEGER NOT NULL,\'date\' TEXT,\'combine\' TEXT, PRIMARY KEY(\'id\' AUTOINCREMENT))",
        create_combines_table,
        0,
        &zErrMsg
    );

}   

static int AddCombinesInHash(void *data, int argc, char **argv, char **azColName) {
    if (Combines_size == 0){
        Combines = (char **)malloc(sizeof(char*)*(Combines_size+1));
        Combines[0] = (char *)malloc(sizeof(char)*50);
        strcpy(Combines[Combines_size], argv[1]);

    } else {
        Combines = (char **)realloc(Combines, sizeof(char*)*(Combines_size+1));
        Combines[Combines_size] = (char *)malloc(sizeof(char)*50);
        strcpy(Combines[Combines_size], argv[1]);

    }
    Combines_size++;
    return 0;
}

static int AddLogInHash(void *data, int argc, char **argv, char **azColName) {
    if (Log_size == 0){
        Log = (CombinesLog *)malloc(sizeof(CombinesLog));
    } else {
        Log = (CombinesLog *)realloc(Log, sizeof(CombinesLog)*(Log_size+1));
    }

    for (int i =0; i < argc;i+=3){
        if (argv) {
            CombinesLog temp;
            strcpy(temp.date,argv[1]);
            strcpy(temp.combine,argv[2]);
            Log[Log_size] = temp;
        }
    }
    Log_size++;
    
    return 0;
}


void get_combines_information() {
    const char * get = "SELECT * FROM combines";
    rc = sqlite3_exec(db,get, AddCombinesInHash, (void*)data,&zErrMsg);
}


void get_log_information() {
    const char * get = "SELECT * FROM infor";
    rc = sqlite3_exec(db,get, AddLogInHash, (void*)data,&zErrMsg);
}

