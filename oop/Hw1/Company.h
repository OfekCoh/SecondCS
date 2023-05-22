#pragma once
#include "Shop.h"
#define MAX_SHOPS_NUMBER 10

class Company
{
private:
	string name;
	Shop shops[MAX_SHOPS_NUMBER];
	int shopsNumber;

	//help function
	void sortShops(Shop* shops,const string& sortBy); // sorts the shops by either name or closed day 
	void printTheArray(const string& sortBy); // sorts the array then prints the shops

public:
	// c'tor 
	Company(); // default values 
	Company(const string& name); // input values

	// getters                              
	string getName() const; // get name
	const Shop* getShops() const; // get pointer to shops array 
	int getShopsNumber() const; // get number of shops

	// setters
	void setName(const string& name); // set name

	//else
	void addShop(const Shop& shop); // add shop
	void printShopsByName(); // print shops by lexicographic order of names 
	void printShopsByDay(); // print shops by closed day order
};
