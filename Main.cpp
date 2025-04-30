#include "Stronghold.h"


class Peasants : public SocialClass {
public:
	Peasants(int population = 1000) : SocialClass("Peasants", population) {}
	void interact() override {
		cout << "The peasants are working the fields." << endl;
	}
};


class Nobles : public SocialClass {
public:
	Nobles(int population = 100) : SocialClass("Nobles", population) {}
	void interact() override {
		cout << "The nobles are discussing politics." << endl;
	}
};


void displayMenu() {
    cout << "\n===== Stronghold Management Menu =====\n";
    cout << "1. View Resources\n";
    cout << "2. View Population\n";
    cout << "3. View Military\n";
    cout << "4. View Economy\n";
    cout << "5. View Leadership\n";
    cout << "6. Simulate Turn\n";
    cout << "7. Update Resources\n";
    cout << "0. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    Kingdom* myKingdom = new Kingdom();

    if (!myKingdom->loadGame("game_save.txt")==-1) {
        cout << "No previous save found. Starting a new game.\n";
    }

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            myKingdom->displayResources();
            break;
        case 2:
            myKingdom->displayPopulation();
            break;
        case 3:
            myKingdom->displayMilitary();
            break;
        case 4:
            myKingdom->displayEconomy();
            break;
        case 5:
            myKingdom->displayLeadership();
            break;
        case 6:
            myKingdom->simulateTurn();
            break;
        case 7: {
            int food, wood, gold,stone;
            cout << "Enter new Food amount: "; cin >> food;
            cout << "Enter new Wood amount: "; cin >> wood;
            cout << "Enter new Stone amount: "; cin >> stone;
            cout << "Enter new Gold amount: "; cin >> gold;
            myKingdom->updateResources(food, wood,stone, gold);

            break;
        }
        case 0:
            cout << "Exiting game.\n";
            break;
        default:
            cout << "Invalid option. Try again.\n";
        }

        myKingdom->saveGame("game_save.txt");

    } while (choice != 0);

    delete myKingdom;
    return 0;
}