#include <iostream>

class Build {
    private:
        std::string addres = "delault addres";
        std::string name = "title";
        
    public:
        Build ( std::string arg1,std::string arg2 ) {
            addres = arg1;
            name = arg2;
        }

        void Viev() {
            std::cout << "Build with name : " << name << " addres : " << addres << std::endl; 
        }
};

int main() {
    Build NewBuild("new_name", "new title");
    NewBuild.Viev();
    return 1;
}