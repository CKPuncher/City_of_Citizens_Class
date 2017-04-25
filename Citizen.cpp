#include<string>
using namespace std;

#include "Citizen.h"

// CONSTRUCTOR
Citizen::Citizen(int id, string firstName, string lastName, string color)
{
	_id = id;
	_firstName = firstName;
	_lastName = lastName;
	_color = color;
}

// CONSTRUCTOR FROM A POINTER
Citizen::Citizen(Citizen* citizen)
{
	if (citizen != NULL)
	{
		_id = citizen->getId();
		_firstName = citizen->getFirstName();
		_lastName = citizen->getLastName();
		_color = citizen->getFavoriteColor();
	} 
}

// (DOESN'T NEED DESTRUCTOR... GETS DESTROYED BY CLASS THAT USES IT (CITY.H))

// GETTERS (and setter)

string Citizen::getFirstName() const
{
	return _firstName;
}

string Citizen::getLastName() const
{
	return _lastName;
}

int Citizen::getId() const
{
	return _id;
}

string Citizen::getFavoriteColor() const
{
	return _color;
}

void Citizen::setFavoriteColor(string color)
{
	_color = color;
}