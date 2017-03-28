
#include "stdafx.h"
#include "ttmath.h"
#include <iostream>
#include <fstream> 
#include <time.h>



using namespace std;
typedef ttmath::Big<1, 2> MyBig;

/*struct UserInfo {
	string Name;
	int Password;
	string PasswordHint;
};*/

void primeNumberGenerator()
{
	int randomNumber = 0;
	int randomNumber2 = 0;

	typedef ttmath::Big<1, 2> MyBig;

	MyBig a, b, c, d, e , tempary, tempary2, tempary3;

	//a = randomNumber; 
	//b = randomNumber2;
	srand(time(NULL));
	randomNumber = rand() % 100 + 50;
	randomNumber2 = rand() % 100 + 50;
	
	bool isPrime = false;

	while (isPrime == false)
	{
		//randomNumber = rand() % 10;
		//randomNumber2 = rand() % 10;
		
		a = randomNumber;
		b = randomNumber2;
		randomNumber++;
		//randomNumber2++;
		e = a + b;
		c = 2;

		cout << "Prime number generation" << endl;

		cout << "random number 1 " << randomNumber << endl;
		cout << "random number 2 " << randomNumber2 << endl;

		while (c < 25)
		{
			//d = Mod(e, c);  //PROBLEM WITH THE MOD FUNCTION USE THE ONE THAT YOU HAVE MADE

			//Mod function

			tempary2 = 0;
			tempary3 = e;

			
				while (tempary3 > tempary2)
				{
					tempary = tempary3;
					tempary3 = tempary3 - c;
					//cout << "moding" << endl;

				}

				d = tempary;

			cout << "mod two numbers is " << d << endl;

			if (d == 0)
			{
				isPrime = false;
				c = 26;
				
			}
			
			if (d >= 1)
			{
				isPrime = true;
				
			}

			c++;

		}

		
	}
	
	/*cout << "Prime number generation" << endl;

	cout << "random number 1 " << randomNumber << endl;
	cout << "random number 2 " << randomNumber2 << endl;*/

	cout << "this number is a prime number " << randomNumber + randomNumber2 << endl;
	
}

/*
void KeyGeneration()
{
	MyBig a, b, c, D, PublicKey, PublicExponent, PrivateKey, PartKey, message, HiddenMessage, decryptedMessage;

	a = "53";
	b = "59";
	c = "2";
	D = 1;
	PublicKey = a*b;
	PartKey = (a-1) * (b-1);
	PublicExponent = "3";
	PrivateKey = ((c*PublicKey) + D) / PublicExponent;

	cout << "the private key is " << PrivateKey << endl;
	cout << "The publc key is " << PublicKey << endl;

	message = "89";

	HiddenMessage = Mod((message^c), PublicKey);

	// decryption
	
	




}*/


string PasswordChecker() {

	ifstream inFile("User.txt");

	if (!inFile)
	{
		cout << "ERROR program failed to open a file for password checking" << endl;
	}

	string Name;
	int Password;
	string PasswordHint;
	string UserInput = "a";

	inFile >> Name >> Password >> PasswordHint;

	

	

	cout << "Please type in the password" << endl;
	cin >> UserInput;

	int UIHashed = hash<string>()(UserInput);

	while (UIHashed != Password)
	{
		cout << "Hint: " << PasswordHint << endl;
		cout << "Please type in the password" << endl;
		cin >> UserInput;
		UIHashed = hash<string>()(UserInput);
	}
	

		return Name;

}


void Setup()
{
	ifstream inFile("User.txt");
	string UserName = "";

	if (!inFile)
	{
		//start setup
		
		string UserPassword = "";
		string PasswordHint = "";
		bool inputCorrect = false;

	while (inputCorrect == false) {
			char UserAnswer;
			cout << "DON'T USE SPACES WHEN YOU TYPE" << endl;
			cout << "Type in your name." << endl;
			cin >> UserName;
			cout << endl << "Type in your password." << endl;
			cin >> UserPassword;
			cout << endl << "Type in your password hint." << endl;
			cin >> PasswordHint;
			cout << "Your user name is " << UserName << endl;
			cout << "Your password is " << UserPassword << endl;
			cout << "Your password hint is " << PasswordHint << endl;
			cout << "Is everything correct?" << endl;
			cout << "Y for yes or N for no" << endl;
			
			cin >> UserAnswer;

			if (UserAnswer == 'y' || UserAnswer == 'Y')
			{
				inputCorrect = true;
			}
	}

	int HashedPassword = hash<string>()(UserPassword);

	ofstream UserFile("User.txt");
	UserFile << UserName << " " << HashedPassword << " " << PasswordHint;

	}



//inFile >> UserInfo.Name >> UserInfo.Password >> UserInfo.PasswordHint;

//return UserName;
}