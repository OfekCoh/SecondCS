
#pragma once
#include "PeripheralDevice.h"

class Keyboard : public PeripheralDevice
{
private:
	int numberOfKeys;

public:
	//c'tor d'tor
	Keyboard(int price = 0, string manufacturer = "~", string color = "black", bool wire = false, int num=0);
	~Keyboard();
	Keyboard(const Keyboard& other); // copy c'tor

	//getter
	int getNumberOfKeys() const;

	//setter
	void setNumberOfKeys(const int& num);

	// operator string()
	operator string() const;

	//connect
	void connect(const Item& comp);
};
