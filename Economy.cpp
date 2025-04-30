#include "Stronghold.h"


void Economy::setTreasury(int treasury) {
	if (treasury >= 0) {
		this->treasury = treasury;
	}

}


void Economy::setTaxRate(double taxRate) {
	if (taxRate >= 0 && taxRate <= 1) {
		this->taxRate = taxRate;
	}

}


void Economy::setInflationRate(double inflationRate) {
	if (inflationRate >= 0) {
		this->inflationRate = inflationRate;
	}

}


void Economy::tax(const Population& population) {
	int collectedTax = static_cast<int>(population.getTotalPopulation() * 10 * taxRate); 
	if (collectedTax > 0) {
		this->treasury += collectedTax;
	}
	cout << "Tax collected: " << collectedTax << endl;
}


void Economy::inflate() {
	if (inflationRate > 0) {
		this->treasury *= (1 - inflationRate);
	}
	cout << "Inflation has affected the economy." << endl;
}


void Economy::warEffects(bool atWar) {
	if (atWar) {
		this->treasury /= 2;
		this->inflationRate += 0.1;
		cout << "The war is draining the economy." << endl;
	}
}


void Economy::display() const {
	KingdomEntity::display();
	cout << "Treasury: " << treasury << ", Tax Rate: " << taxRate << ", Inflation Rate: " << inflationRate
		<< endl;
}