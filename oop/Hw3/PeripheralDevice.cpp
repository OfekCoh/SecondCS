
#include "PeripheralDevice.h"

// c'tor d'tor
PeripheralDevice::PeripheralDevice(int price, string manufacturer, string color, bool wire): Item(price,manufacturer), color(color), isWireless(wire) {}

PeripheralDevice::~PeripheralDevice() {}

PeripheralDevice::PeripheralDevice(const PeripheralDevice& other) : Item(other), color(other.color), isWireless(other.isWireless) {}   // copy c'tor


// getters 
string PeripheralDevice::getColor() const
{
	return color;
}

bool PeripheralDevice::getIsWireless() const
{
	return isWireless;
}

// setters
void PeripheralDevice::setColor(const string& col)
{
	color = col;
}
void PeripheralDevice::setIsWireless(const bool& wire)
{
	isWireless = wire;
}

// conversion operator
PeripheralDevice::operator string() const
{
	string wire = (isWireless) ? "Wireless" : "Wired";
	return Item::operator string() + ", " + wire + ", " + color;  // prints "id #: manu, price$, if_wire, color"
}

// connect
void PeripheralDevice::connect(const Item& comp)
{
	cout << string(*this) << " is connecting to computer: " << string(comp) << "\n";
}