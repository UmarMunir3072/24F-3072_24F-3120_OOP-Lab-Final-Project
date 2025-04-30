#include "Stronghold.h"


void Population::grow(int amount) {
	if (amount > 0) {
		total_population += amount;
	}
}


int Population::shrink(int amount) {
	if (amount > 0 && amount <= total_population) {
		total_population -= amount;
		return 0;  
	}
	else {
		cout << "Error: Cannot shrink population by that amount." << endl;
		return -1;
	}
}


void Population::affectByFood(int foodSupply) {
	if (foodSupply > total_population) {
		grow(foodSupply / 10);
	}
	else if (foodSupply < total_population / 2) {
		shrink(total_population / 20);
	}
}


void Population::revolt() {
	cout << "The population is in revolt!" << endl;
}


void Population::display() const {
	KingdomEntity::display();
	cout << "Total Population: " << total_population << endl;
}
void Population::setTotalPopulation(int population)
{
	total_population = population;
}