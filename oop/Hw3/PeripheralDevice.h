
#pragma once
#include "Item.h"



class PeripheralDevice : public Item
{
private:
	string color;
	bool isWireless;

public:
	// c'tor d'tor
	PeripheralDevice(int price = 0, string manufacturer = "~", string color = "black", bool wire = false);
	virtual ~PeripheralDevice();
	PeripheralDevice(const PeripheralDevice& other); // copy c'tor

	// getters 
	string getColor() const;
	bool getIsWireless() const;

	// setters
	void setColor(const string& col);
	void setIsWireless(const bool& wire);

	// conversion operator
	virtual operator string() const=0; //pure virtual

	// connect
	virtual void connect(const Item& comp);
};

