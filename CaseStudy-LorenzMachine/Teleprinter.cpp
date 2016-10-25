#include "stdafx.h"
#include "Teleprinter.h"
#include <iostream>
#include <string>
#include <map>
#include <conio.h>

using namespace std;

Teleprinter::Teleprinter()
{
}


Teleprinter::~Teleprinter()
{
}

void Teleprinter::setMaps() {
	for (int i = 0; i < 32; i++) {
		charToBaudot.insert(pair<char, int>(character[i], baudot[i]));
		baudotToChar.insert(pair<int, char>(baudot[i], character[i]));
	}
}

int Teleprinter::getBaudotFromChar(char c) {
	return charToBaudot.at(c);
}

char Teleprinter::getCharFromBaudot(int baudot) {
	return baudotToChar.at(baudot);
}

string Teleprinter::decryptMessage(string enmessage) {
	string s;
	for (int i = 0; i < enmessage.length(); i++) {
		s += getCharFromBaudot(encryptor.encryptChar(getBaudotFromChar(enmessage.at(i))));
	}
	return s;
}

void Teleprinter::decrypt(string message) {
	setMaps();
	encryptor.setMachine();
	cout << "Decypted message: " + decryptMessage(message) << endl << endl;
}

void Teleprinter::encrypt() {
	setMaps();
	encryptor.setMachine();

	while (1) {
		int input = _getch();
		if (input == 13)
			break;
		char c = input;
		c = toupper(c); // convert to uppercase to make sure there is no crash when lowercase letter is input
		originalMessage += c;

		string s;
		s += c;
		cout << s; // print out what is typed

		// encrypt each character
		int enBaudot = encryptor.encryptChar(getBaudotFromChar(c));

		// get encrypted character
		char enChar = getCharFromBaudot(enBaudot);

		// form encrypted message
		encryptedMessage += enChar;
	}
	cout << endl << endl;
	cout << encryptedMessage << endl << endl;
}
