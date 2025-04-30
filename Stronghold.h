#ifndef STRONGHOLD_H
#define STRONGHOLD_H


#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>


using namespace std;


class KingdomEntity;
class SocialClass;
class Population;
class Military;
class Leadership;
class Economy;
class Bank;
class Resource;
class EventHandler;
class Kingdom;


// --- KingdomEntity ---
class KingdomEntity {
public:
	KingdomEntity(string name = "Unnamed") : name(name) {}
	virtual ~KingdomEntity() {}
	string getName() const { return name; }
	virtual void display() const;


protected:
	string name;
};


// --- Resource ---
class Resource : public KingdomEntity {
public:
	Resource(string name = "DefaultResource", int amount = 0) : KingdomEntity(name), amount(amount) {}
	int getAmount() const { return amount; }
	void setAmount(int amount);
	void setName(string Name);
	string getName();
	void gather(int amount);
	int consume(int amount); 
	void display() const override;

private:
	int amount;
};


// --- SocialClass ---
class SocialClass : public KingdomEntity {
public:
	SocialClass(string name = "DefaultClass", int population = 0) : KingdomEntity(name), population(population) {}
	int getPopulation() const { return population; }
	void setPopulation(int population);
	virtual void interact() = 0; 
	void display() const override;


protected:
	int population;
};


// --- Population ---
class Population : public KingdomEntity {
public:
	Population(int total_population = 1000) : KingdomEntity("Population"), total_population(total_population) {}
	int getTotalPopulation() const { return total_population; }
	void grow(int amount);
	int shrink(int amount);  
	void affectByFood(int foodSupply);
	void revolt();
	void display() const override;
	void setTotalPopulation(int population);

private:
	int total_population;
};


// --- Military ---
class Military : public KingdomEntity {
public:
	Military(int size = 100, int morale = 100, int foodConsumption = 10, int weaponConsumption = 5)
		: KingdomEntity("Military"), size(size), morale(morale), foodConsumption(foodConsumption),
		weaponConsumption(weaponConsumption) {}
	int getSize() const { return size; }
	void setSize(int size);
	int getMorale() const { return morale; }
	void setMorale(int morale);
	void train();
	void battle(int enemyStrength);
	int getFoodConsumption() const { return foodConsumption; }
	int getWeaponConsumption() const { return weaponConsumption; }
	void display() const override;


private:
	int size;
	int morale;
	int foodConsumption;
	int weaponConsumption;
};


// --- Leadership ---
class Leadership : public KingdomEntity {
public:
	Leadership(string rulerName = "King Arthur", string rulingStyle = "Benevolent")
		: KingdomEntity("Leadership"), rulerName(rulerName), rulingStyle(rulingStyle) {}
	string getRulerName() const { return rulerName; }
	void setRulerName(const string& name);
	string getRulingStyle() const { return rulingStyle; }
	void setRulingStyle(const string& style);
	void electNewRuler(const string& newRuler, const string& newStyle);
	void coup();
	void applyPolicy();
	void display() const override;


private:
	string rulerName;
	string rulingStyle;
};


// --- Economy ---
class Economy : public KingdomEntity {
public:
	Economy(int treasury = 10000, double taxRate = 0.2, double inflationRate = 0.0)
		: KingdomEntity("Economy"), treasury(treasury), taxRate(taxRate), inflationRate(inflationRate) {}
	int getTreasury() const { return treasury; }
	void setTreasury(int treasury);
	double getTaxRate() const { return taxRate; }
	void setTaxRate(double taxRate);
	double getInflationRate() const { return inflationRate; }
	void setInflationRate(double inflationRate);
	void tax(const Population& population);
	void inflate();
	void warEffects(bool atWar);
	void display() const override;


private:
	int treasury;
	double taxRate;
	double inflationRate;
};


// --- Bank ---
class Bank : public KingdomEntity {
public:
	Bank(int balance = 100000, double interestRate = 0.05)
		: KingdomEntity("Bank"), balance(balance), interestRate(interestRate) {}
	int getBalance() const { return balance; }
	void setBalance(int balance);
	double getInterestRate() const { return interestRate; }
	void setInterestRate(double interestRate);
	int loan(int amount);  
	void collectInterest();
	void audit();
	void display() const override;


private:
	int balance;
	double interestRate;
};


// --- EventHandler ---
class EventHandler : public KingdomEntity {
public:
	EventHandler() : KingdomEntity("EventHandler") {}
	void handleEvent(Kingdom& kingdom);
	void famine(Kingdom& kingdom);
	void war(Kingdom& kingdom);
	void drought(Kingdom& kingdom);
	void plague(Kingdom& kingdom);
	void display() const override;
};

class Kingdom {
public:
	Kingdom();
	~Kingdom();
	int simulateTurn(); 
	/*void displayStatus() const;*/
	int saveGame(const string& filename) const; 
	int loadGame(const string& filename);  
	void updateResources(int food, int wood, int stone,int gold);
	void displayResources()const;
	void displayPopulation()const;
	void displayMilitary()const;
	void displayEconomy()const;
	void displayLeadership()const;
	void displayBank()const;

	Population* getPopulation() { return population; }
	Military* getMilitary() { return military; }
	Leadership* getLeadership() { return leadership; }
	Economy* getEconomy() { return economy; }
	Bank* getBank() { return bank; }
	EventHandler* getEventHandler() { return eventHandler; }
	Resource* getResources() { return resources; }
	SocialClass** getSocialClasses() { return socialClasses; }


private:
	Population* population;
	Military* military;
	Leadership* leadership;
	Economy* economy;
	Bank* bank;
	EventHandler* eventHandler;
	Resource* resources;
	SocialClass** socialClasses;
	int numResources;
	int numSocialClasses;


	static const int MAX_RESOURCES = 10;
	static const int MAX_SOCIAL_CLASSES = 5;
};


#endif