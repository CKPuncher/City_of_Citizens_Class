#ifndef CITY_H_
#define CITY_H_

#include<vector>
#include<string>
using namespace std;

class City
{
private:
	string _name;
	vector<Citizen*> citizenList;

public:
	// Constructor
	// (Reads population from a file if already exists)
	City(string cityName);

	// Destructor
	// (Writes population to file)
	~City();

	// GETTERS AND SETTERS

	string getCityName() const;

	int populationSize() const;

	// Returns pointer to a citizen using index of vector
	Citizen* getCitizenAtIndex(int index) const;

	void addCitizen(Citizen* citizen);

	// Returns citizen found via their id
	Citizen* getCitizenWithId(int id) const;

	/* Finds all citizens with certain favorite color and adds
	them to a vector. Returns the vector. */
	vector<Citizen*> getCitizensForFavoriteColor(string color) const;
};

#endif