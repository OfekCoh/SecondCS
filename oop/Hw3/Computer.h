
#pragma once
#include "Item.h"

class Computer : public Item
{
private:
	string cpu;
	bool isALaptop;

public:
	// c'tor d'tor
	Computer(int price = 0, string manufacturer = "~", string cpu = "~", bool laptop = false);
	~Computer();

	// getters 
	string getCpu() const;
	bool getIsALaptop() const;

	// setters
	void setCpu(const string& name);
	void setIsALaptop(const bool& laptop);

	// conversion operator
	operator string() const;
};
