#include "Stronghold.h"


void Leadership::setRulerName(const string& name) {
	this->rulerName = name;
}


void Leadership::setRulingStyle(const string& style) {
	this->rulingStyle = style;
}


void Leadership::electNewRuler(const string& newRuler, const string& newStyle) {
	this->rulerName = newRuler;
	this->rulingStyle = newStyle;
	cout << "A new ruler has been elected: " << newRuler << " (" << newStyle << ")" << endl;
}


void Leadership::coup() {
	cout << "A coup has occurred! The ruler has changed." << endl;
}


void Leadership::applyPolicy() {
	if (rulingStyle == "Benevolent") {
		cout << "The ruler has implemented a benevolent policy." << endl;
	}
	else if (rulingStyle == "Tyrannical") {
		cout << "The ruler has implemented a tyrannical policy." << endl;
	}
}


void Leadership::display() const {
	KingdomEntity::display();
	cout << "Ruler: " << rulerName << ", Ruling Style: " << rulingStyle << endl;
}