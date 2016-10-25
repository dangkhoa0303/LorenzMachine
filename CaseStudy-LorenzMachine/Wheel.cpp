#include "stdafx.h"
#include "Wheel.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Wheel::Wheel()
{
}


Wheel::~Wheel()
{
}

void Wheel::printPins() {
	for (int i = 0; i < pins.size(); i++) {
		cout << to_string(pins.at(i));
	}
	cout << endl;
}

void Wheel::rotate() {
	if (pinSetting < pins.size()-1) {
		pinSetting++;
	}
	else {
		pinSetting = 0;
	}
}
