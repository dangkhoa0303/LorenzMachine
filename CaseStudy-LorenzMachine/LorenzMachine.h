#ifndef LORENZMACHINE_H
#define LORENZMACHINE_H

#include "Wheel.h"
#include "WheelGroup.h"

// This class models the main encyption device within the Lorenz SZ40 Machine
class LorenzMachine
{
private:
	Wheel m37; // the m37 motor wheel
	Wheel m61; // the m61 motor wheel
	WheelGroup psi; // the psi group of wheels
	WheelGroup chi; // the chi group of wheels

	// apply the wheel rotation algorithm to generate a pseudo random sequence
	void rotateWheels();

	// generate an encryption key using the psi and chi wheels
	int makeKey();

	// settings of all wheels
	vector<Wheel> wheels;

public:
	// constructors
	LorenzMachine() {}; // default constructor
	//LorenzMachine(WheelGroup chi, WheelGroup psi, Wheel m37, Wheel m61);

	// encrypt a given baudot-encoded character
	int encryptChar(int baudotChar);

	void setAllWheelsPins();
	void setWheels();
	void setMachine();
	void resetMachine();
};

#endif