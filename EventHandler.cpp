#include "Stronghold.h"


void EventHandler::handleEvent(Kingdom& kingdom) {
	int eventType = rand() % 4;
	switch (eventType) {
	case 0:
		famine(kingdom);
		break;
	case 1:
		war(kingdom);
		break;
	case 2:
		drought(kingdom);
		break;
	case 3:
		plague(kingdom);
		break;
	}
}


void EventHandler::famine(Kingdom& kingdom) {
	cout << "A famine has struck the kingdom!" << endl;
	int foodLoss = kingdom.getPopulation()->getTotalPopulation() / 4;
	if (kingdom.getResources()[0].consume(foodLoss) == -1) { 
		cout << "The famine has devastated the kingdom!" << endl;
		kingdom.getPopulation()->shrink(kingdom.getPopulation()->getTotalPopulation() / 2);
	}
	else {
		cout << foodLoss << " food consumed" << endl;
	}


}


void EventHandler::war(Kingdom& kingdom) {
	cout << "War has broken out!" << endl;
	int enemyStrength = rand() % kingdom.getMilitary()->getSize();
	kingdom.getMilitary()->battle(enemyStrength);
	kingdom.getEconomy()->warEffects(true);
}


void EventHandler::drought(Kingdom& kingdom) {
	cout << "A drought has devastated the land!" << endl;
	kingdom.getResources()[0].consume(kingdom.getResources()[0].getAmount() / 2); 
}


void EventHandler::plague(Kingdom& kingdom) {
	cout << "A plague is spreading through the kingdom!" << endl;
	kingdom.getPopulation()->shrink(kingdom.getPopulation()->getTotalPopulation() / 3);
}


void EventHandler::display() const {
	KingdomEntity::display();
	cout << "Handling Events" << endl;
}