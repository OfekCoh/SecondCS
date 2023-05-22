
#include "Keyboard.h"

//c'tor d'tor
Keyboard::Keyboard(int price, string manufacturer, string color, bool wire, int num) : PeripheralDevice(price,manufacturer,color,wire), numberOfKeys(num) {}

Keyboard::~Keyboard() {}

Keyboard::Keyboard(const Keyboard& other) : PeripheralDevice(other), numberOfKeys(other.numberOfKeys) {} // copy c'tor


//getter
int Keyboard::getNumberOfKeys() const
{
	return numberOfKeys;
}


//setter
void Keyboard::setNumberOfKeys(const int& num)
{
	numberOfKeys = num;
}

// operator string()
Keyboard::operator string() const
{
	return PeripheralDevice::operator string() + ", Keyboard with " + to_string(numberOfKeys) + " keys";
}

//connect
void Keyboard::connect(const Item& comp)
{
	cout << "Connecting a keyboard \n"; 
	PeripheralDevice::connect(comp);
}