#include <iostream>


class  MagicCall
{
private:
    /* data */
    int cout_of_execute = 0;

public:
     MagicCall(/* args */){}
    ~ MagicCall(){};

    void printString(char* str) {
        std::cout << str << std::endl;
        cout_of_execute++;
        
    }


    void printString(char* str, int count) {
        if (count == 0){
            for (int iter = 0; iter < cout_of_execute; iter++ ){
                std::cout << str << std::endl;
            }
        } else{
            for (int iter = 0; iter < count; iter++ ){
                std::cout << str << std::endl;
            }
        }
        cout_of_execute++;
    }

};

int main(){
    MagicCall caller;

    char PutString1 [] = "Im called one";
    char PutString2 [] = "Im called two";
    char PutString3 [] = "Im called three";
    char PutString4 [] = "Im called four";
    char PutString5 [] = "Im called five";
    char PutString6 [] = "Im called six";

    caller.printString(PutString1);
    
    caller.printString(PutString2,4);
    
    caller.printString(PutString3);
    
    caller.printString(PutString4,0);
    
    caller.printString(PutString5);

    caller.printString(PutString6,0);

}

