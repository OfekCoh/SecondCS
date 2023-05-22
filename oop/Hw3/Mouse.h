
#pragma once
#include "PeripheralDevice.h"

class Mouse : public PeripheralDevice
{
private:
	int dpi;

public:
	//c'tor d'tor
	Mouse(int price = 0, string manufacturer = "~", string color = "black", bool wire = false, int num = 0);
	~Mouse();
	Mouse(const Mouse& other); // copy c'tor

	//getter
	int getDpi() const;

	//setter
	void setDpi(const int& num);

	// operator string()
	operator string() const;

	// connect
	void connect(const Item& comp);
};
