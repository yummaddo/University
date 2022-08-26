//#include "sqlite3.h"
#include <iostream>
#include <string>

using namespace std;

#define NumberOfPerson 2; 

class Person  
{
   public:
      Person (string Login, string Password){
         login = Login;
         password = Password;
      };      
      string login;
      string password;
      void SetLogin(string Login){

      }
};





class Identifier {
   public:
      
      Identifier(){
            
      }


   private:
      bool isFirstRun = false;


};


class InputModel {
   public:
      void StartSesion(){
         CurentLogin=GetLogin();
         CurentPassword=GetPassword();
      }
      void LoggedUser(){
         cout << CurentLogin << endl;
         cout << CurentPassword << endl;
      }
      int GetAttemptCount(){
         return number_of_try;
      }


   private:
      string CurentLogin;
      string CurentPassword;
      int number_of_try;
      string GetPassword();
      string GetLogin();
};


string InputModel::GetPassword(){
   string pas;
   cout << "Password: ";
   cin >> pas;
   return pas;
}

string InputModel::GetLogin(){
   string log;
   cout << "Login: ";
   cin >> log;
   return log;
}



int main(int argc, char* argv[]) {
   // sqlite3 *db;
   // char *zErrMsg = 0;
   // int rc;

   // rc = sqlite3_open("test.db", &db);

   // if( rc ) {
   //    std::cout << "Can't open database: \n";
   //    return(0);
   // } else {
   //    std::cout << "Opened database successfully: \n";

   // }
   // sqlite3_close(db);
   InputModel first_sesion;
   first_sesion.StartSesion();
   first_sesion.LoggedUser();
}



