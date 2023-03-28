#include <iostream>




class Time {
    public:
        Time (int _seconds){
            seconds = _seconds;
            hours   = _seconds / 3600;
            minutes = _seconds / 60;
            seconds = _seconds % 60;
        }

        Time (int _seconds, int _minutes){
            seconds =  _seconds % 60;
            minutes = (_minutes + _seconds / 60) % 60;
            hours   = _seconds / 3600 + _minutes / 60;
        }        
        
        Time (int _seconds, int _minutes, int _hours){
            seconds =  _seconds % 60;
            minutes = (_minutes + _seconds / 60) % 60;
            hours = _hours + _minutes / 60;
        }

    void GetTime(){
        std::cout << "Time: s:m:h format = ";
        std::cout << seconds;
        std::cout << ":";
        std::cout << minutes;
        std::cout << ":";
        std::cout << hours;
        std::cout << std::endl;
        std::cout << std::endl;
    }


    private:
        int seconds,minutes,hours;
};

int main(){
    Time first(200);
    first.GetTime();

    Time second(80, 80);
    second.GetTime();

    Time third(80, 80, 80);
    third.GetTime();

}