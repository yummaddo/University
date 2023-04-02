#include <iostream>

class Behavior {
public:
    virtual ~Behavior() {}

    virtual void displayInfo() = 0;

    friend void SpeedCompare(Behavior &obj1, Behavior &obj2);
    friend void CapacityCompare(Behavior &obj1, Behavior &obj2);

private:
    int speed;

};

class Plane : public Behavior {
protected: 
private:
    int speed;
    int payloadCapacity;
public:
    Plane(int _speed, int _payloadCapacity) : speed(_speed), payloadCapacity(_payloadCapacity) {}
    void displayInfo() override {
        std::cout << "This is a plane. Speed: " << speed << ", Payload Capacity: " << payloadCapacity << std::endl;
    }

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


};


void SpeedCompare(Behavior &obj1, Behavior &obj2) {
    if (obj1.speed > obj2.speed) {
        std::cout << "The " << typeid(obj1).name() << " is faster." << std::endl;
    }
    else if (obj1.speed < obj2.speed) {
        std::cout << "The " << typeid(obj2).name() << " is faster." << std::endl;
    }
    else {
        std::cout << "The " << typeid(obj1).name() << " and " << typeid(obj2).name() << " have the same speed." << std::endl;
    }
}
void CapacityCompare(Behavior &obj1, Behavior &obj2) {
    if (obj1.speed > obj2.speed) {
        std::cout << "The " << typeid(obj1).name() << " is Capacity." << std::endl;
    }
    else if (obj1.speed < obj2.speed) {
        std::cout << "The " << typeid(obj2).name() << " is Capacity." << std::endl;
    }
    else {
        std::cout << "The " << typeid(obj1).name() << " and " << typeid(obj2).name() << " have the same Capacity." << std::endl;
    }
}

int main() {

    Helicopter h1(50,500);
    Plane p1(100,800);
    
    SpeedCompare(h1,p1);
    CapacityCompare(h1,p1);
}
