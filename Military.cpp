#include "Stronghold.h"


void Military::setSize(int size) {
	if (size >= 0) {
		this->size = size;
	}
	else {
		cout << "Error: Military size cannot be negative." << endl;
	}
}


void Military::setMorale(int morale) {
	if (morale >= 0) {
		this->morale = morale;
	}
	else {
		cout << "Error: Military morale cannot be negative." << endl;
	}
}


void Military::train() {
	this->size += 10;
	this->morale += 5;
	this->foodConsumption += 2;
	this->weaponConsumption += 1;
	cout << "Military trained. Size and morale increased." << endl;
}


void Military::battle(int enemyStrength) {
	if (enemyStrength > size) {
		this->size /= 2;
		this->morale -= 20;
		cout << "Lost the battle. Military size and morale decreased." << endl;
	}
	else {
		this->size += enemyStrength / 4;
		this->morale += 10;
		cout << "Won the battle. Military size and morale increased." << endl;
	}
}


void Military::display() const {
	KingdomEntity::display();
	cout << "Size: " << size << ", Morale: " << morale
		<< ", Food Consumption: " << foodConsumption << ", Weapon Consumption: " << weaponConsumption
		<< endl;
}