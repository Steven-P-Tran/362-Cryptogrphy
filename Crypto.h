/*
Steven Tran
Eric Shulman
Crypto HW 1
IDE: Visual Studio 2019
*/

#pragma once

#include <iostream>;
#include <string>;

using namespace std;

class Crypto {
private:
	char InputDataBuffer[128];  // you process 16 characters at a time
	char CryptoKey[9];  // Using a user inputted 8-bit key
	char CryptoMatrix[128];
	char ClearMatrix[128];
	int KeyLength;
	short InputDataCount;
public:
	void setInputDataBuffer();
	void EncryptFunct();
	void DecryptFunct();
};