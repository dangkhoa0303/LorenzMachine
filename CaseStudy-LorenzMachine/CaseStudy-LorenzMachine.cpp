// CaseStudy-LorenzMachine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WheelGroup.h"
#include "LorenzMachine.h"
#include "Teleprinter.h"
#include "Wheel.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	// decrypt message
	Teleprinter de;
	de.decrypt("DIDWV-UPO*- XZB");

	// encrypt message
	Teleprinter en;
	en.encrypt();
    return 0;
}

