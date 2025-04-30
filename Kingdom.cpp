#include "Stronghold.h"


Kingdom::Kingdom() :
	population(new Population()),
	military(new Military()),
	leadership(new Leadership()),
	economy(new Economy()),
	bank(new Bank()),
	eventHandler(new EventHandler()),
	resources(new Resource[MAX_RESOURCES]),
	socialClasses(new SocialClass* [MAX_SOCIAL_CLASSES]),
	numResources(4),
	numSocialClasses(0) {
	resources[0] = Resource("Food", 5000);
	resources[1] = Resource("Wood", 2000);
	resources[2] = Resource("Stone", 1000);
	resources[3] = Resource("Gold", 500);
}

Kingdom::~Kingdom() {
	delete population;
	delete military;
	delete leadership;
	delete economy;
	delete bank;
	delete eventHandler;
	delete[] resources;


	for (int i = 0; i < numSocialClasses; ++i) {
		delete socialClasses[i];
	}
	delete[] socialClasses;
}

void Kingdom::updateResources(int food, int wood, int stone,int gold)
{
	resources[0].setAmount(food);
	resources[1].setAmount(wood);
	resources[2].setAmount(stone);
	resources[3].setAmount(gold);
}
int Kingdom::simulateTurn() {
	economy->tax(*population);
	bank->collectInterest();
	population->affectByFood(resources[0].getAmount()); 
	military->train();
	eventHandler->handleEvent(*this);
	return 0;
}


void Kingdom::displayPopulation() const {
	cout << "--- Population Status ---" << endl;
	population->display();
	cout << "----------------------" << endl;
}
void Kingdom::displayResources() const {
	cout << "--- Resources Status ---" << endl;
	for (int i = 0; i < numResources; ++i) {
		resources[i].display();
	}
	cout << "----------------------" << endl;
}
void Kingdom::displayBank() const {
	cout << "--- Bank Status ---" << endl;
	bank->display();
	cout << "----------------------" << endl;
}
void Kingdom::displayMilitary() const {
	cout << "--- Military Status ---" << endl;
	military->display();
	cout << "----------------------" << endl;
}
void Kingdom::displayLeadership() const {
	cout << "--- Leadership Status ---" << endl;
	leadership->display();
	cout << "----------------------" << endl;
}
void Kingdom::displayEconomy() const {
	cout << "--- Economy Status ---" << endl;
	economy->display();
	cout << "----------------------" << endl;
}
int Kingdom::saveGame(const string& filename) const {
	ofstream file(filename);
	if (!file.is_open()) {
		cerr << "Error: Could not open save file." << endl;
		return -1;
	}


	file << population->getTotalPopulation() << " "
		<< military->getSize() << " " << military->getMorale() << " "
		<< leadership->getRulerName() << endl;
	file << " " << leadership->getRulingStyle() << endl;
		file<< economy->getTreasury() << " " << economy->getTaxRate() << " " << economy->getInflationRate() << " "
		<< bank->getBalance() << " " << bank->getInterestRate() << endl;


	for (int i = 0; i < numResources; ++i) {
		file << resources[i].getName() << " " << resources[i].getAmount() << endl;
	}


	file.close();
	cout << "Game saved to " << filename << endl;
	return 0;
}


int Kingdom::loadGame(const string& filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		cerr << "Error: Could not open save file." << endl;
		return -1;
	}


	int newPopulation, militarySize, militaryMorale, treasury, bankBalance;
	double taxRate, inflationRate, bankInterestRate;
	string rulerName, rulingStyle;


	file >> newPopulation >> militarySize >> militaryMorale;
	getline(file, rulerName);
	getline(file, rulingStyle);
	file>> treasury >> taxRate >> inflationRate>> bankBalance >> bankInterestRate;

	population->setTotalPopulation(newPopulation);
	military->setSize(militarySize);
	military->setMorale(militaryMorale);
	leadership->setRulerName(rulerName);
	leadership->setRulingStyle(rulingStyle);
	economy->setTreasury(treasury);
	economy->setTaxRate(taxRate);
	economy->setInflationRate(inflationRate);
	bank->setBalance(bankBalance);
	bank->setInterestRate(bankInterestRate);


	for (int i = 0; i < numResources; ++i) {
		string name;
		int amount;
		file >> name >> amount;
		resources[i].setAmount(amount);
		resources[i].setName(name);
	}


	file.close();
	cout << "Game loaded from " << filename << endl;
	return 0;
}
