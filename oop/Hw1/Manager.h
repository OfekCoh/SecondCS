#pragma once
#include <string>
using std::string;
#define MAX_NAME_LEN 10


class Manager
{
private:
	int id;
	string firstName;
	string lastName;
	int birthYear;

public:
	// c'tor
	Manager(); // default values
	Manager(const int& id, const string& name, const string& name2, const int& year); // input values

	// getters
	int getId() const; // get id
	string getFirstName() const; // get first name
	string getLastName() const; // get last name
	int getBirthYear() const; // get birth year

	// setters
	void setId(const int& id_num); // set id
	void setFirstName(const string& name); // set first name if not too long
	void setLastName(const string& name); // set last name if not too long
	void setBirthYear(const int& year); // set birth year

	// print
	void print() const; // prints the managers details
};