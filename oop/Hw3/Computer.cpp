
#include "Computer.h"

// c'tor d'tor
Computer::Computer(int price, string manufacturer, string cpu, bool laptop): Item(price,manufacturer), cpu(cpu), isALaptop(laptop) {}

Computer::~Computer() {}

// getters 
string Computer::getCpu() const
{
	return cpu;
}
bool Computer::getIsALaptop() const
{
	return isALaptop;
}


// setters
void Computer::setCpu(const string& name)
{
	cpu = name;
}

void Computer::setIsALaptop(const bool& laptop)
{
	isALaptop = laptop;
}


// conversion operator
Computer::operator string() const
{
	string lap = (isALaptop) ? "Laptop" : "Desktop";
	return Item::operator string() + ", " + lap + ", " + cpu + "\n";  // prints "id #: manu, price$, if_laptop, cpu"
}