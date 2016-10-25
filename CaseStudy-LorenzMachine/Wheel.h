#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Wheel
{
public:
	Wheel();
	~Wheel();

	void rotate();
	int getCurrentPin() { return pins.at(pinSetting); };
	void resetCurrentPin() { pinSetting = 0; };
	void setPins(int pin) { pins.push_back(pin); };
	void printPins();

private:
	vector<int> pins;
	int pinSetting = 0;
};

