#include "Stronghold.h"


void Resource::setAmount(int amount) {
	if (amount >= 0) {
		this->amount = amount;
	}
}


void Resource::gather(int amount) {
	if (amount > 0) {
		this->amount += amount;
	}
}


int Resource::consume(int amount) {
	if (amount > 0 && amount <= amount) {
		this->amount -= amount;
		return 0;
	}

}



void Resource::display() const {
	KingdomEntity::display();
	cout << "Amount: " << amount << endl;
}
string Resource::getName()
{
	return this->name;
}
void Resource::setName(string Name)
{
	this->name = Name;
}