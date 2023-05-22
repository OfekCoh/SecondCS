
#include "Branch.h"

// c'tor d'tor
Branch::Branch(const string& place) : catalog(), location(place), amount(0), oldest(0) {} // create the catalog array 

Branch:: ~Branch()
{
	for (int i = 0; i < amount; i++) delete catalog[i]; // free all the items  
}

// getters
string Branch::getLocation() const
{
	return location;
}

Item** Branch::getCatalog(int& num) 
{
	num = amount;
	return catalog;
}

int Branch::getAmount() const
{
	return amount;
}

int Branch::getOldest() const
{
	return oldest;
}

//setters
void Branch::setLocation(const string& place)
{
	location = place;
}

// methods
void Branch::addItem(Item* new_item)
{
	if (amount == BRANCH_SIZE) // store is full 
	{
		catalog[oldest++] = new_item; // replcae the oldest item
		if(oldest == BRANCH_SIZE) oldest = 0; // update oldest
	}
	else 
		catalog[amount++] = new_item; // add item and update amount
}