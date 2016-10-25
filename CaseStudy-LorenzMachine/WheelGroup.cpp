#include "stdafx.h"
#include "WheelGroup.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::vector;
using namespace std;

WheelGroup::WheelGroup()
{
}


WheelGroup::~WheelGroup()
{
}

void WheelGroup::rotate() {
	for (int i = 0; i < wheels.size(); i++) {
		(wheels.at(i)).rotate();
	}
}

void WheelGroup::resetCurrentPins() {
	for (int i = 0; i < wheels.size(); i++) {
		(wheels.at(i)).resetCurrentPin();
	}
}

int WheelGroup::getCurrentPins() {
	int sum = 0;
	for (int i = 0; i < wheels.size(); i++) {
		sum += ((wheels.at(i)).getCurrentPin())*pow(2, (wheels.size()-i-1)*1.0);
	}
	return sum;
}

void WheelGroup::setWheelPins(vector<Wheel> allWheels, int type) {
	int start = 0, end = 0;
	if (type == 0) { // psi
		start = 0;
		end = 4;
	}
	else { // chi
		start = 7;
		end = 11;
	}
	for (int i = start; i <= end; i++) {
		wheels.push_back(allWheels.at(i));
	}
}