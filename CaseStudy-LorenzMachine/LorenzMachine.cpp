#include "stdafx.h"
#include "LorenzMachine.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void LorenzMachine::rotateWheels() {
	chi.rotate();
	if (m37.getCurrentPin() == 1) {
		psi.rotate();
	}
	if (m61.getCurrentPin() == 1) {
		m37.rotate();
	}
	m61.rotate();
}

void LorenzMachine::setWheels() {
	m37 = wheels.at(5);
	m61 = wheels.at(6);
	chi.setWheelPins(wheels, 1);
	psi.setWheelPins(wheels, 0);
}

int LorenzMachine::makeKey() {
	return chi.getCurrentPins() ^ psi.getCurrentPins();
}

int LorenzMachine::encryptChar(int baudotChar) {
	int enChar = baudotChar ^ makeKey();
	rotateWheels();
	return enChar;
}

void LorenzMachine::setMachine() {
	setAllWheelsPins();
	setWheels();
}

void LorenzMachine::resetMachine() {
	m37.resetCurrentPin();
	m61.resetCurrentPin();
	psi.resetCurrentPins();
	chi.resetCurrentPins();
}

void LorenzMachine::setAllWheelsPins() {
	ifstream mFile;
	mFile.open("pinsettings.dat");
	char c;
	int count = 0, i = 0;
	Wheel *wheel = new Wheel();

	int numberOfPins[] = { 43, 47, 51, 53, 59, 37, 61, 41, 31, 29, 26, 23 };

	if (mFile.is_open()) {
		while (!mFile.eof()) {
			mFile >> c;
			int pin = c - '0';
			(*wheel).setPins(pin);
			count++;
			if (count == numberOfPins[i]) {
				count = 0;
				wheels.push_back(*wheel);
				wheel = new Wheel();
				i++;
			}
		}
	}
	mFile.close();
}