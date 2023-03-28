#include <iostream>

class Complex {
private:
    double real;
    double imag;
public:
    // Конструктор за замовчуванням
    Complex() {
        real = 0.0;
        imag = 0.0;
    }

    // Конструктор з параметрами
    Complex(double r, double i) {
        real = r;
        imag = i;
    }

    // Конструктор копії
    Complex(const Complex& c) {
        real = c.real;
        imag = c.imag;
    }

    // Перевантаження оператора додавання
    Complex operator + (const Complex& c) {
        Complex result;
        result.real = real + c.real;
        result.imag = imag + c.imag;
        return result;
    }

    // Перевантаження оператора множення
    Complex operator * (const Complex& c) {
        Complex result;
        result.real = real * c.real - imag * c.imag;
        result.imag = imag * c.real + real * c.imag;
        return result;
    }

    // Перевантаження оператора віднімання
    Complex operator - (const Complex& c) {
        Complex result;
        result.real = real - c.real;
        result.imag = imag - c.imag;
        return result;
    }

    // Перевантаження оператора ділення
    Complex operator / (const Complex& c) {
        Complex result;
        double denominator = c.real * c.real + c.imag * c.imag;
        result.real = (real * c.real + imag * c.imag) / denominator;
        result.imag = (imag * c.real - real * c.imag) / denominator;
        return result;
    }

    // Перевантаження оператора присвоєння
    Complex& operator = (const Complex& c) {
        real = c.real;
        imag = c.imag;
        return *this;
    }

    // Перевантаження оператора порівняння
    bool operator == (const Complex& c) {
        return (real == c.real && imag == c.imag);
    }

    // Метод для отримання реальної частини комплексного числа
    double getReal() {
        return real;
    }

    // Метод для отримання уявної частини комплексного числа
    double getImag() {
        return imag;
    }

    // Метод для встановлення значення реальної частини комплексного числа
    void setReal(double r) {
        real = r;
    }

    // Метод для встановлення значення уявної частини комплексного числа
    void setImag(double i) {
        imag = i;
    }

    // Метод для виведення комплексного числа на екран
    void print() {
        if (imag >= 0){
            std::cout << real << " + " << imag << "i" << std::endl;
        } else {
            std::cout << real << " - " << imag * -1.0f << "i" << std::endl;
        }
    }

};

int main() {

    Complex first(1,2), second(1,2), third(4,5), fourth, fifth;
    
    fourth = third - second;
    fourth.print();
    bool res = first == second;
    std::cout << "first == second = " << res << std::endl;
    res = first == third;
    std::cout << "first == third = " << res << std::endl;

    fifth = third / first;
    fifth.print();
    
    fifth = third + third;
    fifth.print();

    first = fifth / second;
    first.print();

}
