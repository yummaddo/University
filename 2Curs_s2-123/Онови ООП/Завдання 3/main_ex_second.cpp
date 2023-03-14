#include <iostream>

class Behavior {
public:
    virtual ~Behavior() {}
    virtual void displayInfo() = 0;
    virtual int Speed() = 0;
private:
    int speed;
};

class Plane : public Behavior {
protected: 
    int speed;
private:
    int payloadCapacity;
public:
    Plane(int _speed, int _payloadCapacity) : speed(_speed), payloadCapacity(_payloadCapacity) {}
    void displayInfo() override {
        std::cout << "This is a plane. Speed: " << speed << ", Payload Capacity: " << payloadCapacity << std::endl;
    }
    int Speed(){ return speed;}
    friend class SpeedCompare;
    friend class CapacityCompare;
};

class Helicopter : public Behavior {
private:
    int speed;
    int payloadCapacity;
public:
    Helicopter(int _speed, int _payloadCapacity) : speed(_speed), payloadCapacity(_payloadCapacity) {}
    void displayInfo() override {
        std::cout << "This is a helicopter. Speed: " << speed << ", Payload Capacity: " << payloadCapacity << std::endl;
    }
    int Speed(){ return speed;}
    friend class SpeedCompare;
    friend class CapacityCompare;

};

class SpeedCompare {
public:
    static void compare(Behavior &obj1, Behavior &obj2) {
        if (obj1.Speed() > obj2.Speed()) {
            std::cout << "The " << typeid(obj1).name() << " is faster." << std::endl;
        }
        else if (obj1.Speed() < obj2.Speed()) {
            std::cout << "The " << typeid(obj2).name() << " is faster." << std::endl;
        }
        else {
            std::cout << "The " << typeid(obj1).name() << " and " << typeid(obj2).name() << " have the same speed." << std::endl;
        }
    }
};

class CapacityCompare {
public:
    static void compare(Behavior &obj1, Behavior &obj2) {
        if (obj1.Speed() > obj2.Speed()) {
            std::cout << "The " << typeid(obj1).name() << " is Capacity." << std::endl;
        }
        else if (obj1.Speed() < obj2.Speed()) {
            std::cout << "The " << typeid(obj2).name() << " is Capacity." << std::endl;
        }
        else {
            std::cout << "The " << typeid(obj1).name() << " and " << typeid(obj2).name() << " have the same Capacity." << std::endl;
        }
    }
};

int main() {
    SpeedCompare compere_system;
    CapacityCompare capasity_system;

    Helicopter h1(50,500);
    Plane p1(100,800);
    
    compere_system.compare(h1,p1);
    capasity_system.compare(h1,p1);
}
