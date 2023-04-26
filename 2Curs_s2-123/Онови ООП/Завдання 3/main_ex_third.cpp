#include <iostream>

#include <iostream>
 
class Values; // попереднє оголошення класу Values
 
class Display
{
private:
	bool m_displayIntFirst;
 
public:
	Display() {}
	
	void displayItem(Values &value); // вищенаведене попереднє оголошення необхідне для цього рядка
};

class Values
{
private:
	int m_intValue;
public:
	Values(int intValue)
	{
		m_intValue = intValue;
	}
 
	// Робимо метод Display::displayItem() другом класу Values
	friend void Display::displayItem(Values& value); // помилка: Values не бачить повного визначення класу Display
};


void Display::displayItem(Values &value)
{
	std::cout << value.m_intValue << " into >> " <<  value.m_intValue + 5 << '\n';
    value.m_intValue += 5;
}

int main()
{
    Values value(7);
    Display display;
    display.displayItem(value);
    display.displayItem(value);
    display.displayItem(value);
    display.displayItem(value);
    display.displayItem(value);
    display.displayItem(value);
}