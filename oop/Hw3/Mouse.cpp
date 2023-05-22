
#include "Mouse.h"

//c'tor d'tor
Mouse::Mouse(int price, string manufacturer, string color, bool wire, int dpi) : PeripheralDevice(price, manufacturer, color, wire), dpi(dpi) {}

Mouse::~Mouse() {}

Mouse::Mouse(const Mouse& other) : PeripheralDevice(other), dpi(other.dpi) {} // copy c'tor


//getter
int Mouse::getDpi() const
{
	return dpi;
}


//setter
void Mouse::setDpi(const int& num)
{
	dpi = num;
}

// operator string()
Mouse::operator string() const
{
	return PeripheralDevice::operator string() + ", Mouse with dpi : " + to_string(dpi);
}

//connect
void Mouse::connect(const Item& comp)
{
	cout << "Connecting a mouse \n";
	PeripheralDevice::connect(comp);
}