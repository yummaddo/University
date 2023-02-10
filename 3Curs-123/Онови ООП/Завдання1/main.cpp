#include <iostream>

class Build {
    private:
        std::string addres = "delault addres";
        std::string name = "title";
        
    public:
        Build ( std::string _addres,std::string _name ) {
            addres = _addres;
            name = _name;
        }
        Build ( std::string _addres ) {
            addres = _addres;
        }
        Build () {
        }
        void Viev() {
            std::cout << "Build with name : " << name << "|| addres : " << addres << std::endl; 
        }
};

class StrangeTime
{
    private:
        std::string __type = "hour";
        int hour = 0;
        int minutes = 0;
        int seconds = 0;

        int ConvertMinutes(){
            if ( __type == "hour" ) {
                minutes = hour * 60;
            } else if ( __type == "seconds" ) {
                minutes = seconds / 60;
            }
            return minutes;
        }

    public:
        int GetMinutes() {
            return minutes;
        }
        StrangeTime(int _time_type, std::string _type) {
            if ( _type == "hour" ) {
                hour = _time_type;
                __type = _type;
            } else if ( _type == "seconds" ) {
                seconds = _time_type;
                __type = _type;
            } else {
                hour = _time_type;
            }
            minutes = ConvertMinutes();
        }
        void SetSeconds(int _time_type) {
            seconds = _time_type;
            __type = "seconds";
            minutes = ConvertMinutes();
        }
        void SetHour(int _time_type) {
            hour = _time_type;
            __type = "hour";
            minutes = ConvertMinutes();
        }
};


int main() {
    Build NewBuild("new_name", "new title");
    NewBuild.Viev();

    StrangeTime NewTimer(360, "seconds");
    std::cout << "RESULT of time " << NewTimer.GetMinutes() << " minutes" << std::endl;
    NewTimer.SetHour(4);
    std::cout << "RESULT of time " << NewTimer.GetMinutes() << " minutes" << std::endl;

    return 1;
}