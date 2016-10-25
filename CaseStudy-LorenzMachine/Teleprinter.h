#pragma once
#include "LorenzMachine.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Teleprinter
{
public:
	Teleprinter();
	~Teleprinter();

	int getBaudotFromChar(char c);
	char getCharFromBaudot(int b);
	string decryptMessage(string message);

	void setMaps();
	void encrypt();
	void decrypt(string message);

private:
	char character[32] = {'*', ' ', 'Q', 'W', 'E', 'R', 'T', 'Y', 
	'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 
	'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '-', '!', '.'};

	int baudot[32] = {0, 4, 23, 19, 1, 10, 16, 21, 7, 6, 24, 22,
	3, 5, 9, 13, 26, 20, 11, 15, 18, 17, 29, 14, 30, 25, 12, 28, 8,
	2, 27, 31};

	map<char, int> charToBaudot;
	map<int, char> baudotToChar;
	LorenzMachine encryptor;
	string originalMessage;
	string encryptedMessage;
};

