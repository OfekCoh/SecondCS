
#include "Item.h"

int Item::next_id = 1; // initialize static member with 1

// c'tor d'tor 
Item::Item(int price, string manufacturer) : price(price), manufacturer(manufacturer), id(next_id) 
{
	next_id += 1; // update the next id
}

Item::~Item() { cout << "Throwing away an item\n"; }

Item::Item(const Item& other): price(other.price), manufacturer(other.manufacturer), id(next_id) // copy c'tor
{
	next_id += 1; // update the next id
}


//getters
int Item::getPrice() const
{
	return price;
}

string Item::getManufacturer() const
{
	return manufacturer;
}

int Item::getId() const
{
	return id;
}


// setters
void Item::setPrice(const int& num)
{
	price = num;
}

void Item::setManufacturer(const string& name)
{
	manufacturer = name;
}


// conversion operator
Item::operator string() const   // for string(Item)
{
	return "id " + to_string(id) + ": " + manufacturer + " " + to_string(price) + "$"; // return the wanted string
}
