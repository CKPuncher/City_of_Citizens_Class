#include<string>
#include<vector>
#include<fstream>
#include<iostream>
using namespace std;

#include "Citizen.h"
#include "City.h"

// CONSTRUCTOR
City::City(string cityName)
{
	_name = cityName;

	fstream readInStream(_name, ios::in); // Open a text file (create it if it doesn't exist)
	if (readInStream.is_open())
	{
		int id;
		string firstName, lastName, color;

		while (readInStream >> id >> firstName >> lastName >> color) // Read in the four elements each time
		{
			// Put those elements into a new (dynamically allocated) citizen
			Citizen* c = new Citizen(id, firstName, lastName, color);

			// Add that citizen to the vector of citizens in this city
			citizenList.push_back(c);
		}
	}
}

// DESTRUCTOR
City::~City()
{
	fstream saveRecordsStream(_name, ios::out); // Output the citizens and their info (create file if nonexistent)
	if (saveRecordsStream.is_open())
	{
		for (int i = 0; i < citizenList.size(); i++)
		{
			saveRecordsStream << citizenList[i]->getId() << " "
				<< citizenList[i]->getFirstName() << " "
				<< citizenList[i]->getLastName() << " "
				<< citizenList[i]->getFavoriteColor() << endl;
			
			delete citizenList[i]; // Delete the citizen after saving it to the record file
		}
	}

	else
	{
		for (int i = 0; i < citizenList.size(); i++)
		{
			delete citizenList[i];
		}
	}
}

// GETTERS AND SETTERS

string City::getCityName() const
{
	return _name;
}

int City::populationSize() const
{
	return citizenList.size();
}

// Returns pointer to a citizen using index of vector
Citizen* City::getCitizenAtIndex(int index) const
{
	if (index >= 0 && index < citizenList.size())
	{
		return citizenList[index];
	}

	return NULL;
}

void City::addCitizen(Citizen* citizen)
{
	Citizen* c = new Citizen(citizen);
	citizenList.push_back(c);
}

// Returns citizen found via their id
Citizen* City::getCitizenWithId(int id) const
{
	for (int i = 0; i < citizenList.size(); i++)
	{
		if (citizenList[i]->getId() == id)
			return citizenList[i];
	}

	return NULL;
}

/* Finds all citizens with certain favorite color and adds
them to a vector. Returns this vector. */
vector<Citizen*> City::getCitizensForFavoriteColor(string color) const
{
	vector<Citizen*> favoriteColorList;

	for (int i = 0; i < citizenList.size(); i++)
	{
		if (citizenList[i]->getFavoriteColor() == color)
			favoriteColorList.push_back(citizenList[i]);
	}

	return favoriteColorList;
}