#include <iostream>



class SimpleClass {
private:
  int privateField1;
  double privateField2;

  // Дружній метод для іншого класу
  friend class FriendClass;

public:
  SimpleClass(int value1, double value2) : privateField1(value1), privateField2(value2) {}

  void printPrivateFields() {
    std::cout << "privateField1 = " << privateField1 << ", privateField2 = " << privateField2 << std::endl << std::endl;
  }
};

class FriendClass {
public:
  static void increasePrivateFields(SimpleClass& obj) {
    obj.privateField1 += 5; 
    obj.privateField2 += 5.0;
  }
};

int main() {
  SimpleClass obj(42, 3.14);
  obj.printPrivateFields(); 

  // Виклик дружнього методу для збільшення приватних полів на порядковий номер журналу
  FriendClass::increasePrivateFields(obj);

  obj.printPrivateFields(); 

  return 0;
}