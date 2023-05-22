#pragma once
#include "Manager.h"

enum Day { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

class Shop
{
private:
	Manager manager;
	string name;
	Day closedDay;
	bool isOnline;

public:
	// c'tor
	Shop(); // default values
	Shop(const Manager& manager, const string& name, const Day& day, const bool& online); // input values

	//getters 
	Manager getManager() const; // get manager
	string getName() const; // get name
	Day getClosedDay() const; // get closed day
	bool getIsOnline() const; // get if online

	//setters 
	void setManager(const Manager& manager); // set namager
	void setName(const string& name); // set name
	void setClosedDay(const Day& day); // set closed day
	void setIsOnline(const bool& state); // set if online

	//print 
	void print() const; // prints the shops details
};