#include "Shop.h"
#include <iostream>
using std::cout;

// -------------------------------------------------------c'tor
Shop::Shop() : manager(), name("~"), closedDay(Sunday), isOnline(0) {}; // default values

// input values if valid
Shop::Shop(const Manager& manager, const string& name, const Day& day, const bool& online) : manager(manager), name(name), closedDay(day), isOnline(online) {
	if (size(name) > MAX_NAME_LEN) // check length
	{
		cout << "Shop name length is too long\n";
		this->name = "~"; // if too long
	}
}

// -------------------------------------------------------getters
Manager Shop::getManager() const // get namager 
{
	return manager;
}

string Shop::getName() const // get name
{
	return name;
}

Day Shop::getClosedDay() const // get closed day
{
	return closedDay;
}

bool Shop::getIsOnline() const // get if online
{
	return isOnline;
}

// -------------------------------------------------------setters
void Shop::setManager(const Manager& manager) // set manager
{
	this->manager = manager;
}

void Shop::setName(const string& name) // set name 
{
	if (size(name) > MAX_NAME_LEN) // check length
	{
		cout << "Shop name length is too long\n"; 
		this->name = "~"; // if too long
	}
	else this->name = name;
}

void Shop::setClosedDay(const Day& day) // set closed day 
{
	closedDay = day;
}

void Shop::setIsOnline(const bool& state) // set is online
{
	isOnline = state;
}

// --------------------------------------------------------print
void Shop::print() const // prints the shops details
{
	string days[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" }; // array to print the enum days
	cout << "Printing shop:\n";
	manager.print(); // print namager 
	cout << "Name : " << name << "\n"; // print name
	cout << "Closed day : " << days[closedDay] << "\n"; // print closed day 
	cout << "Is Online : " << (isOnline ? "True" : "False") << "\n"; // print if online
}
