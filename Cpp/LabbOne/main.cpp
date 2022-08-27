#include "sqlite3.h"
#include <iostream>
#include <string>
#include <list>


using namespace std;

 
const char* SQL = "CREATE TABLE IF NOT EXISTS persons (\'id\' INTEGER NOT NULL,\'name\' TEXT,\'password\' TEXT, PRIMARY KEY(\'id\' AUTOINCREMENT))";


class Person  
{
   public:
      Person (string Login, string Password){
         loggin = Login;
         password = Password;
      };      
      string loggin;
      string password;
      void SetLogin(string Login){
         loggin = Login;

      }
      void SetPassword(string Password){
         password = Password;

      }
};


static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}




class DataBase{
   public:

      DataBase(){
         Person tmp1 = Person("admin","admin");
         Person tmp2 = Person("user1","pass");

         persons.push_back(tmp1);
         persons.push_back(tmp2);
      }

      pair<bool,bool> FindPerson(Person entered_person){
         string log = entered_person.loggin;
         string pas = entered_person.password;
         bool is_loggins;
         bool is_password;
         // getting data -------------

         //---------------------------

         for (auto i = persons.begin(); i != persons.end(); i++){
            is_loggins = isTrueLogin(log,*i);
            if (is_loggins){
               // cout << is_loggins << " " << is_password << endl;
               is_password = isTruePassword(pas,*i);
               if (is_password) {
                  return pair<bool,bool>(true,true);

               }else {
                  return pair<bool,bool>(true,false);
               }
            } else {
               return pair<bool,bool>(false,false);
            }
         }
         return pair<bool,bool>(is_loggins,is_password);
      }

      void AddPerson(Person inf){
         persons.push_back(inf);
      } 

   private:
      list<Person> persons;

      bool isTrueLogin(string login, Person curent_person){
         if(login==curent_person.loggin){
            return true;
         } else {
            return false;
         }
      }

      bool isTruePassword(string pasword, Person curent_person){
         if (pasword==curent_person.password){
            return true;
         } else {
            return false;
         }
      }
};


class InputModel {
   public:
      void StartSesion(){
         CurentLogin=GetLogin();
         CurentPassword=GetPassword();
         number_of_try++;
      }
      void LoggedUser(){
         cout << CurentLogin << endl;
         cout << CurentPassword << endl;
      }
      int GetAttemptCount(){
         return number_of_try;
      }
      Person GetPerson(){
         return Person(CurentLogin,CurentLogin);
      }


   private:
      string CurentLogin;
      string CurentPassword;
      int number_of_try;
      // funcks()
      string GetPassword();
      string GetLogin();
};


string InputModel::GetPassword(){
   string pas;
   cout << "[    enter    ] Password: ";
   cin >> pas;
   return pas;
}

string InputModel::GetLogin(){
   string log;
   cout << "[    enter    ] Login: ";
   cin >> log;
   return log;
}


class Identifier {
   pair<bool,bool> result;
   Person hash_person = Person("","");


   public:
      int log_errors = 0;
      int pas_errors = 0;
      bool Identifie(Person inputed_person){
         result = data.FindPerson(inputed_person);
         if (isFirstRun) {
            hash_person = inputed_person;
            isFirstRun = false;
            if (result.first == true){
               if (result.second == true){
                  status=true;

               } else {
                  cout << "[ input fatal ] wrong login!" << endl;
                  pas_errors++;
               }

            } else {
               cout << "[ input fatal ] wrong password!\n" << endl;
               log_errors++;
            }
         } else {
            if (result.first == true && hash_person.loggin == inputed_person.loggin){
               if (result.second == true){
                  status=true;
               } else {
                  cout << "[ input fatal ] wrong password!\n" << endl;
                  pas_errors++;
               }

            } else {
               cout << "[ input fatal ] wrong login!\n" << endl;
               if (hash_person.loggin == inputed_person.loggin){
                  log_errors++;
               }
            }
            hash_person = inputed_person;
         }

         return status;

      }

      bool GetStatus(){
         return status;
      }


   private:
      DataBase data = DataBase();
      bool status = false;
      bool isFirstRun = false;
};


int main(void) {
   string stop;
   InputModel sesion;
   Identifier process;

   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;

   if (sqlite3_open("test.db",&db)){
      cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
   } else {
      cout << "Opened database successfully " << endl;
   }

   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   sqlite3_close(db);

   // if ( rc != SQLITE_OK ){
   //    cout << "SQL error: " << zErrMsg << endl;
   // } else {
   //    cout << "Table created successfully\n" << endl;
   // }




   do {
      sesion.StartSesion();
   } while ( !process.Identifie(sesion.GetPerson()) && sesion.GetAttemptCount() < 3);
   
   if (!process.GetStatus()){
      if (process.log_errors == 3 && process.pas_errors != 3){
         cout << "[     log     ] End session" << endl;

      } else if (process.pas_errors == 3 && process.log_errors){
         cout << "[     log     ] Unauthorized access attempt" << endl;

      } else {


      }
   }



   cout << "Enter any button ... ";
   cin >> stop;
   return 0;
}


   // sqlite3 *db;asf
   // char *zErrMsg = 0;
   // int rc;aas

   // rc = sqlite3_open("test.db", &db);

   // if( rc ) {
   //    std::cout << "Can't open database: \n";
   //    return(0);
   // } else {
   //    std::cout << "Opened database successfully: \n";

   // }
   // sqlite3_close(db);
