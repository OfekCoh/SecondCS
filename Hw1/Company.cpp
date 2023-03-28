#include "Company.h"
#include <iostream>
using std::cout;

// -------------------------------------------------------c'tor 
Company::Company() : name("~"), shops(), shopsNumber(0) {}; // default values 

// input values if valid
Company::Company(const string& name) : name(name), shops(), shopsNumber(0) {
	if (size(name) > MAX_NAME_LEN) // check name length
	{
		cout << "Company name length is too long\n";
		this->name = "~"; // too long- default value
	}
}

// -------------------------------------------------------getters
string Company::getName() const // get name 
{
	return name;
}

const Shop* Company::getShops() const // get pointer to shops array 
{
	return shops;
}

int Company::getShopsNumeber() const // get shops number
{
	return shopsNumber;
}

// -------------------------------------------------------setters
void Company::setName(const string& name) // set name if not too long 
{
	if (size(name) > MAX_NAME_LEN) // check name length 
	{
		cout << "Company name length is too long\n";
		this->name = "~"; // too long- default value 
	}
	else this->name = name; // length is ok
}

// --------------------------------------------------------add shop
void Company::addShop(const Shop& shop) // add shop
{
	if (shopsNumber >= MAX_SHOPS_NUMBER) // check if theres space for more shops
	{
		cout << "There is no place for new shops!\n"; // if company is full cant add a shop
	}
	else // there is space 
	{
		shops[shopsNumber++] = shop;
	}
}


// --------------------------------------------------------- help funcs

//sort function that takes a parameter to sort by name or by day
void Company::sortShops(Shop* shops, const int size, const string sortBy)
{
	Shop temp; // for swapping
	int i, j;

	for (i = 0; i < size - 1; i++) // bubble sort the array 
	{
		for (j = i + 1; j < size; j++)
		{
			if (sortBy == "name" && shops[i].getName() > shops[j].getName()) // If sorting by lexicographic order of names
			{
				temp = shops[i]; // swap 
				shops[i] = shops[j];
				shops[j] = temp;
			}
			else if (sortBy == "day" && shops[i].getClosedDay() > shops[j].getClosedDay()) // If sorting by day
			{
				temp = shops[i]; // swap
				shops[i] = shops[j];
				shops[j] = temp;
			}
		}
	}
}

void Company::printTheArray() const // help func that prints the array
{
	int i;
	for (i = 0; i < this->shopsNumber; i++)  // print the sorted shops array
	{
		cout << "Shop #" << i + 1 << " :\n";
		this->shops[i].print();
		cout << "\n";
	}
}

// ---------------------------------------------------------print
void Company::printShopsByDay() // print shops by closed day order
{
	if (!shopsNumber) cout << "There are no shops in this company.\n"; // no shops
	else if (shopsNumber == 1) // only one shop
	{
		cout << "There is 1 shop in this company. The shops details are : \n";
		printTheArray(shops, 1); //print the shop
	}
	else // several shops  
	{
		cout << "There are " << shopsNumber << " shops in this company. The shops details are :\n";
		sortShops(shops, shopsNumber, "day"); // help fucn that sorts and prints the shops
		printTheArray(shops, shopsNumber); // help func that prints the array
	}
}

void Company::printShopsByName() // print shops by lexicographic order of names 
{
	if (!shopsNumber) cout << "There are no shops in this company.\n"; // no shops
	else if (shopsNumber == 1) // only one shop
	{
		cout << "There is 1 shop in this company. The shops details are : \n";
		printTheArray(shops, 1); //print the shop
	}
	else // several shops  
	{
		cout << "There are " << shopsNumber << " shops in this company. The shops details are :\n";
		sortShops(shops, shopsNumber, "name"); // help fucn that sorts and prints the shops
		printTheArray(shops, shopsNumber); // help func that prints the array
	}
}
