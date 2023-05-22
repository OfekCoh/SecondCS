
#pragma once
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::to_string;

class Item
{
private:
	int price;
	string manufacturer;
	const int id;  
	static int next_id; // the last id given+1 

public:
	// c'tor d'tor
	Item(int price=0, string manufacturer ="~"); 
	virtual ~Item(); 
	Item(const Item& other); // copy c'tor 

	//getters
	int getPrice() const;
	string getManufacturer() const;
	int getId() const;

	// setters
	void setPrice(const int& num);
	void setManufacturer(const string& name);

	// conversion operator
	virtual operator string() const=0; // pure virtual to make the class ABC 
};