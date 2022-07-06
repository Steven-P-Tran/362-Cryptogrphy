// CryptoHW1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Crypto.h"

void setInputDataBuffer();
void EncryptFunct();
void DecryptFunct();

int main() {

	Crypto object;
	
	object.setInputDataBuffer();
	object.EncryptFunct();
	object.DecryptFunct();
	
	return 0;
}

void Crypto::setInputDataBuffer() {


	for (int i = 9; i < 129; i++)
	{
		CryptoMatrix[i] = '/0';
		InputDataBuffer[i] = '0';
	}

	cout << "Please enter a string (must be 128 characters)" << endl;
	cin.getline(InputDataBuffer, 128);
	InputDataCount = cin.gcount();

	cout << "Total Characters entered: " << InputDataCount << endl;

	while (KeyLength != 9)
	{
		cout << "Please enter encyption key (must be 8  characters)" << endl;
		cin.getline(CryptoKey, 9);
		KeyLength = cin.gcount();
	}
}

void Crypto::EncryptFunct() {

	int ed = 0;

	for (int x = 0; x < InputDataCount; x++)
	{
		if (ed == 8) {
			ed = 8;
		}
		CryptoMatrix[x] = InputDataBuffer[x] ^ CryptoKey[ed];
		ed++;
	}

	cout << InputDataBuffer << endl;
	cout << "Displaying crypto mattrix" << endl;

	for (int i = 0; i < InputDataCount; i++)
	{
		cout << CryptoMatrix[i];
	}
	cout << '/n';
}

void Crypto::DecryptFunct() {

	int decnum = 0;

	for (int i = 0; i < InputDataCount; i++)
	{
		if (decnum == 8) {
			decnum = 0;
		}
		ClearMatrix[i] = CryptoMatrix[i] ^ CryptoKey[decnum];
		decnum++;
	}

	for (int x = 0; x < InputDataCount; x++)
	{
		cout << ClearMatrix[x];
	}
	cout << '/n';
}