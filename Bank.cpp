#include "Stronghold.h"


void Bank::setBalance(int balance) {
	if (balance >= 0) {
		this->balance = balance;
	}

}


void Bank::setInterestRate(double interestRate) {
	if (interestRate >= 0) {
		this->interestRate = interestRate;
	}

}


int Bank::loan(int amount) {
	if (amount > 0 && amount <= balance) {
		this->balance -= amount;
		cout << "Loan issued: " << amount << endl;
		return 0; 
	}

}


void Bank::collectInterest() {
	int interest = static_cast<int>(balance * interestRate);
	if (interest > 0) {
		this->balance += interest;
	}
	cout << "Interest collected: " << interest << endl;
}


void Bank::audit() {
	if (balance < 0) {
		cout << "Warning: Financial irregularities detected!" << endl;
	}
	else {
		cout << "Audit: No irregularities found." << endl;
	}
}


void Bank::display() const {
	KingdomEntity::display();
	cout << "Balance: " << this->balance << ", Interest Rate: " << interestRate << endl;
}