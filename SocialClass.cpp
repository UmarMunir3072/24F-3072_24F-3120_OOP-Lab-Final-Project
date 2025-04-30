#include "Stronghold.h"


void SocialClass::setPopulation(int population) {
	if (population >= 0) {
		this->population = population;
	}
	else {
		cout << "Error: Population cannot be negative." << endl;
	}
}


void SocialClass::display() const {
	KingdomEntity::display();
	cout << "Population: " << population << endl;
}