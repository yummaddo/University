#include "sqlite3.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;


int SQLITE_RUN_SIZE = -1;

static int Callback(void *data, int argc, char **argv, char **azColName) {
   return 0;
};

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


class DataBase{
   public:

      DataBase(){
         //admin infor
         Person tmp1 = Person("Administrator","12345678");


         persons.push_back(tmp1);

      }

      void print_data(){
         int index = 0;
         for (auto i = persons.begin(); i != persons.end(); i++){
            print_person(*i,index);
            index++;
         }
      }

      pair<bool,bool> FindPerson(Person entered_person){
         // print_data();
         string log = entered_person.loggin;
         string pas = entered_person.password;
         bool is_loggins;
         bool is_password;
         // getting data -------------

         //---------------------------
         pair<bool,bool> res = pair<bool,bool>(false,false);

         for (auto i = persons.begin(); i != persons.end(); i++){
            is_loggins = isTrueLogin(log,*i);
            is_password = isTruePassword(pas,*i);
            
            if (is_loggins){
               // cout << is_loggins << " " << is_password << endl;
               if (is_password) {
                  return  pair<bool,bool>(true,true);

               }else {
                  res =  pair<bool,bool>(true,false);
               }
            } else {
               if (!res.first){
                  res =  pair<bool,bool>(false,false);
               }
            }
         }
         return res;
      }

      void AddPerson(Person inf){
         persons.push_back(inf);
      } 

      Person SetByIndex(int index, string element, string prefix){
         int iter = 0;

         for (auto i = persons.begin(); i != persons.end(); i++){
            if (iter==index){
               Person temp = *i;
               if (prefix == "name"){
                  temp.SetLogin(element);
                  *i = temp;
                  
               } else if (prefix == "pass"){
                  temp.SetPassword(element);
                  *i = temp;

               }
               return *i;
            } //first item we ignored becose this is admin
            i++;iter++;
         }
         return Person("Nool","Nool");
      }

   private:
      list<Person> persons;

      void print_person(Person inf, int index){
         if (inf.loggin != "Administrator"){
            cout << "[" << index << "] " << inf.loggin << " " << inf.password << endl;
         }
      }

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


static int UpdateCallback(void *data, int argc, char **argv, char **azColName){
   return 0;
}


class InputModel {
   public:
      int isLogin = -1;
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
         return Person(CurentLogin,CurentPassword);
      }

      void EnteredAccount(){
         cout << "[     log     ] Enter into acaunt" << endl;
      }

      bool StartMenu(sqlite3 *db){
         string ansv;
         cout << "[     log     ] Welcome in main menu" << endl;
         cout << "[     log     ] You can execute several commands  by entering thair name or number" << endl;
         cout << "[     log     ] ----  suggested list ----" << endl;
         cout << "[     log     ] 1-register  :: create a new account " << endl;
         cout << "[     log     ] 2-login     :: login a new accout " << endl;
         cout << "[     log     ] 3-exit      :: login a new accout " << endl;
         do{
            cout << "[    enter    ] command name or index: ";
            cin >> ansv;
            if (ansv == string("register") || ansv == string("1")){
               Register(db);
               isLogin=2;
               break;
            } else if (ansv == string("login") || ansv == string("2")){
               isLogin=1;
               break;
            } else if (ansv == string("exit") || ansv == string("3")){
               break;
            } else {
               cout << "[     log     ] Coomand not found " << endl;
            }
         } while (ansv != string("exit") || ansv != string("3"));
         return isLogin;
      } 

   private:
      string CurentLogin;
      string CurentPassword;
      int number_of_try;
      // funcks()
      string GetPassword();
      string GetLogin();
      void Register(sqlite3 *db){
         char *zErrMsg = 0;
         const char* data = "";
         int rc;
         string new_login = GetLogin();
         string new_password = GetPassword();
         string SQL_REGISTER = string("INSERT INTO \'persons\'(\'name\',\'password\') VALUES (\'") + new_login +string("\',\'") + new_password +string("\')");
         rc = sqlite3_exec(db, SQL_REGISTER.c_str(), Callback, (void*)data, &zErrMsg);
         if ( rc != SQLITE_OK ){
            cout << "{sqlite3 log} SQL error: " << zErrMsg << endl;
         } else {
            cout << "{sqlite3 log} New person acount has created successfully" << endl;
         }
      }
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
                  status = true;

               } else {
                  cout << "[ input fatal ] wrong login!" << endl;
                  pas_errors++;
               }

            } else {
               cout << "[ input fatal ] wrong password!\n" << endl;
               log_errors++;
            }
         } else {
            if (result.first == true){
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

      void AddPersonInHash(Person inf){
         data.AddPerson(inf);
      }

      bool GetStatus(){
         return status;
      }

      void VievDataInformation(){
         data.print_data();
      }

      Person SetByIndex(int index,string element, string prefix){
         return data.SetByIndex(index,element,prefix);
      }

   private:
      DataBase data = DataBase();
      bool status = false;
      bool isFirstRun = false;
};


 // global visible
InputModel sesion;
Identifier process;

class AdminSesion{
   char *zErrMsg = 0;
   int rc;
   char *sql;
   const char* data = "";
   public:
      AdminSesion(sqlite3 *db){
         string com;
         cout << "[     log     ] Welcome in administrator panel" << endl;
         cout << "[     log     ] You can execute several commands  by entering thair name or number" << endl;
         cout << "[     log     ] ----  suggested list ----" << endl;
         cout << "[     log     ] 1 - print_all             :: viev information about all person in data base " << endl;
         cout << "[     log     ] 2 - set_name_by_index     :: seted name of person by index " << endl;
         cout << "[     log     ] 3 - set_password_by_index :: seted password of person by index " << endl;
         cout << "[     log     ] 4 - exit                  :: exit program " << endl;
         
         
         do{

            cout << "[    enter    ] command name or index: ";

            cin >> com;
            if (com == "1" || com == "print_all"){
               process.VievDataInformation();
            } else if (com == "2" || com == "set_name_by_index") {
                int index;
                cout << "[    enter    ] index: ";
                cin >> index;
                set_name_by_index(index,db);            

            } else if (com == "3" || com == "set_password_by_index"){
                int index;
                cout << "[    enter    ] index: ";
                cin >> index;
                set_password_by_index(index,db);  

            } else if (com == "4" || com == "exit"){
               break;
            } else {
               cout << "[     log     ] Coomand not found " << endl;
            }
         }
         while (com != "exit");
      }
   private:
      Person SetByIndex(int index,string element, string prefix){
         return process.SetByIndex(index,element,prefix);
      }

      void set_data_base_information(Person inf, string prefix,int index, sqlite3 *db){
         
         string name_sql = string("UPDATE persons SET name=\'") + inf.loggin + string("\' WHERE id=\'") + to_string(index-1) + string("\';");
         string password_sql = string("UPDATE persons SET password=\'") + inf.password + string("\' WHERE id=\'") + to_string(index-1) + string("\';");
         if (prefix == "name"){
            cout << "[     log     ]  " << name_sql << endl;
            cout << "[     log     ]  " << inf.loggin << " " << inf.password << endl;
            rc = sqlite3_exec(db,name_sql.c_str(),UpdateCallback,0,&zErrMsg);
         } else if (prefix == "pass"){
            cout << "[     log     ] " << password_sql << endl;
            cout << "[     log     ]  " << inf.loggin << " " << inf.password << endl;
            rc = sqlite3_exec(db,password_sql.c_str(),UpdateCallback,0,&zErrMsg);
         }
         if ( rc != SQLITE_OK ){
            cout << "{sqlite3 log} SQL error: " << zErrMsg << endl;
         } else {
            cout << "{sqlite3 log} Update successfully" << endl;
         }
      }

      void set_name_by_index(int index, sqlite3 *db){
         string new_name;
         cout << "[    enter    ] new login: ";
         cin >> new_name;
         Person person_inf = SetByIndex(index,new_name,"name");
         set_data_base_information(person_inf, "name", index, db);
      }

      void set_password_by_index(int index,sqlite3 *db){
         string new_password;
         cout << "[    enter    ] new password: ";
         cin >> new_password;
         Person person_inf = SetByIndex(index,new_password,"pass"); 
         set_data_base_information(person_inf, "pass", index, db);
      }
};

static int AddInHash(void *data, int argc, char **argv, char **azColName) {
   string name,password;
   for (int i =0; i < argc;i+=3){
      if (argv) {
         name = (string)argv[i+1];
         password = (string)argv[i+2];
         process.AddPersonInHash(Person(name,password));     
      }
   }
   return 0;
};

static int SizeCallback(void *data, int argc, char **argv, char **azColName) {
   if (string(argv[0]) == string("0")){
      SQLITE_RUN_SIZE = 1;
   } else {
      SQLITE_RUN_SIZE = 0;
   }
   return 0;
};


int main(void) {
   int try_numbers = 0;
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;
   const char* data = "";
   const char* SQL_SELECT = "SELECT * FROM persons";
   const char* SQL_COUNT = "SELECT COUNT(*) FROM persons";
   const char* SQL_INSERT = "INSERT INTO \'persons\'(\'name\',\'password\') VALUES (\'def1\',\'pass\'),(\'def2\',\'pass\')";
   const char* SQL = "CREATE TABLE IF NOT EXISTS persons (\'id\' INTEGER NOT NULL,\'name\' TEXT,\'password\' TEXT, PRIMARY KEY(\'id\' AUTOINCREMENT))";

   // connection to db and get ( 1-has connected 2-table created or exist 3-information that will be add in hash )
   
   // first step
   if (sqlite3_open("test.db",&db)){
      cout << "{sqlite3 log} Can't open database: " << sqlite3_errmsg(db) << endl;
   } else {
      cout << "{sqlite3 log} Opened database successfully " << endl;
   }
   // second 
   rc = sqlite3_exec(db, SQL,Callback, 0, &zErrMsg);
   if ( rc != SQLITE_OK ){
      cout << "{sqlite3 log} SQL error: " << zErrMsg << endl;
   } else {
      cout << "{sqlite3 log} Table created or connected successfully" << endl;
   }


   rc = sqlite3_exec(db, SQL_COUNT, SizeCallback, (void*)data, &zErrMsg);
   if ( rc != SQLITE_OK ){
      cout << "{sqlite3 log} SQL error: " << zErrMsg << endl;
   }

   if (SQLITE_RUN_SIZE == 1 && rc == SQLITE_OK){
      rc = sqlite3_exec(db, SQL_INSERT, Callback, (void*)data, &zErrMsg);
      if ( rc != SQLITE_OK ){
         cout << "{sqlite3 log} SQL error: " << zErrMsg << endl;
      } else {
         cout << "{sqlite3 log} Defult users load successfully" << endl;
      }
   }



   // thid 
   rc = sqlite3_exec(db,SQL_SELECT, AddInHash, (void*)data,&zErrMsg);
   if ( rc != SQLITE_OK ){
      cout << "{sqlite3 log} SQL error: " << zErrMsg << endl;
   } else {
      cout << "{sqlite3 log} Inforamation load successfully" << endl;
   }


   int result = sesion.StartMenu(db);

   if (result == 1){
      do {
         sesion.StartSesion();
         try_numbers++;
      } while ( !process.Identifie(sesion.GetPerson()) && try_numbers < 3 );
      
      if (!process.GetStatus()){
         if (process.log_errors == 3 && process.pas_errors != 3){
            cout << "[     log     ] End session" << endl;

         } else if (process.pas_errors == 3 && process.log_errors){
            cout << "[     log     ] Unauthorized access attempt" << endl;

         }
      } else {
         if (sesion.GetPerson().loggin == "Administrator"){
            AdminSesion sub_process = AdminSesion(db);
         } else {
            sesion.EnteredAccount();
         }
      }
   } else {
      sesion.EnteredAccount();
   }



   // closed connection with db
   sqlite3_close(db);
   return 0;
}
