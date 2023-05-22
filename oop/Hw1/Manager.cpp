#include "Manager.h"
#include <iostream>
using std::cout;

// -------------------------------------------------------c'tor
Manager::Manager() : id(0), firstName("~"), lastName("~"), birthYear(0) {}; // default values

// sets input values if valid
Manager::Manager(const int& id, const string& name, const string& name2, const int& year) : id(id), firstName(name), lastName(name2), birthYear(year) {
	if (size(name) > MAX_NAME_LEN) // check first name length
	{
		cout << "Manager first name length is too long\n"; 
		firstName = "~"; // if too long
	}
	if (size(name2) > MAX_NAME_LEN) // check last name length
	{
		cout << "Manager last name length is too long\n";
		lastName = "~"; // if too long
	}
}

// -------------------------------------------------------getters
int Manager::getId() const // get id
{
	return id;
}

string Manager::getFirstName() const // get first name
{
	return firstName;
}

string Manager::getLastName() const // get last name
{
	return lastName;
}

int Manager::getBirthYear() const // get birth year
{
	return birthYear;
}

// -------------------------------------------------------setters
void Manager::setId(const int& id_num) // set id
{
	id = id_num;
}

void Manager::setFirstName(const string& name) // set first name if not too long
{
	if (size(name) > MAX_NAME_LEN) // check input length
	{
		cout << "Manager first name length is too long\n";
		firstName = "~"; // if too long
	}
	else firstName = name;
}

void Manager::setLastName(const string& name) // set last name if not too long
{
	if (size(name) > MAX_NAME_LEN) // check input length
	{
		cout << "Manager last name length is too long\n";
		lastName = "~"; // if too long
	}
	else lastName = name;
}

void Manager::setBirthYear(const int& year) // set birth year
{
	birthYear = year;
}

// -----------------------------------------------------print
void Manager::print() const // prints the managers details,
{
	cout << "Printing manager:\n";
	cout << "Id : " << id << "\n"; // print id
	cout << "First name : " << firstName << "\n"; // print first name
	cout << "Last name : " << lastName << "\n"; // print last name
	cout << "Birth year : " << birthYear << "\n"; // print birth year
}
