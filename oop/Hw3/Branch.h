
#pragma once
#include <iostream>
#include "Item.h"
using std::string;
#define BRANCH_SIZE 10

class Branch
{
private:
	Item* catalog[BRANCH_SIZE];
	string location;
	int amount; // how many items are in the catalog
	int oldest; // index for the oldest item
public:
	// c'tor d'tor
	Branch(const string& place= "~");
	~Branch();
	
	// getters
	string getLocation() const; 
	Item** getCatalog(int& num); // Omer said its fine without const at the end 
	int getAmount() const;
	int getOldest() const;

	//setters
	void setLocation(const string& place);

	// methods
	void addItem(Item* new_item);
};
