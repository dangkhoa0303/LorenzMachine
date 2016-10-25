#pragma once
#include "Wheel.h"
#include <iostream>
#include <vector>

using namespace std;

class WheelGroup
{
public:
	WheelGroup();
	~WheelGroup();

	void rotate();
	int getCurrentPins();
	void resetCurrentPins();
	void setWheelPins(vector<Wheel> allWheels, int type);

private:
	vector<Wheel> wheels;
};

