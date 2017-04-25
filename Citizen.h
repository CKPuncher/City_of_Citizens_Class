#ifndef CITIZEN_H_
#define CITIZEN_H_

#include<string>
using namespace std;

class Citizen
{
private:
	int _id;
	string _firstName;
	string _lastName;
	string _color;

public:
	// Constructor
	// Once created, can only change favorite color
	Citizen(int id, string firstName, string lastName, string color);

	/* Creates new citizen with data copied
	from passed-in pointer to a citizen */
	Citizen(Citizen* citizen);

	// GETTERS (and setter)

	string getFirstName() const;

	string getLastName() const;

	int getId() const;

	string getFavoriteColor() const;

	void setFavoriteColor(string color);
};

#endif
