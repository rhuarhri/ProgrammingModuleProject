// C++Project.cpp : Defines the entry point for the console application.
//

/*Plan for the project

Step 1 the program should gather all of the neccessary data from files

step 2 the program should then prompt the user for the password

step 3 the program should then create a verity of options including 

reset program (where the program will generate two new prime number and 
create a new encryption key)

Encrypt a file (where the program will collect the content off a file 
then it will convert it into ascii code and then change add the encryption key to it)
During this part the the user will be prompted to add input

Dectypt a file (where the program will use the prime numbers to find and remove the 
encryption key from the file to leave the ascii code which can be converted into text)

Exit function 

idea try and find a way to split the numbers into 64bit chunks

888888888888888888888888888888888888888

go to session 8 
within session 8 it documnets how to input content in a file into an arry regardless of what size the array is.
this could be used in the ecryption software by allowing the program to split the words up which can then be changed
into ascii code of use


PROBLEM CAN MODULUS WORK ON THIS PROGRAM BECAUSE DOESN'T A DEFFINITION OF MODULUS NEED TO BE IN THE 
LIBRARY FOLDER TO WORK.


*/


#include "stdafx.h"
#include "ttmath.h"
#include <iostream>

#include "Functions.h"

using namespace std;

typedef ttmath::Big<1, 2> MyBig;





void SimpleCalculating(const MyBig & a, const MyBig & b, const MyBig & c, const MyBig & D)
{
	std::cout << "Simple calculating" << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "b = " << c << std::endl;
	std::cout << "a + b = " << a + b + c<< std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "a * b = " << a*b << std::endl;
	std::cout << "a / b = " << a / b << std::endl;

	//D = a^c;

	cout << "Mod A and B " << Mod(D, b)<<endl; 

	
}



/*int convertToASCII(char letter)
{



	int ascii = int(letter);
	//char letters = ascii;
	/*cout << letters << endl;
	cout << ascii << endl;

	return ascii;


}

//Converting to ascii code
void convertToASCII(string letter)
{
	for (int i = 0; i < letter.length(); i++)
	{
		char x = letter.at(i);
		int ascii = int(x);
		char letters = ascii;
		cout << letters << endl;
		cout << ascii << endl;
		
	}
}*/

int Menu()
{
	int UsersChoice = 0;
	string FileName = "";
	
	while (UsersChoice > 4 || UsersChoice < 1) {
		cout << "Which of the following would you like to do?" << endl;
		cout << "Press 1: Encrypt a text file." << endl;
		cout << "Press 2: To input text for Encryption." << endl;
		cout << "Press 3: To Decrypt a text file." << endl;
		cout << "Press 4: To exit the program." << endl;

		

		cin >> UsersChoice;
		/*cin.clear();

		if (cin.fail())
		{
			cin.clear();
			cin >> UsersChoice;
		}*/

	}

	if (UsersChoice == 1)
	{
		//start encryption function
		FileName = "";
		FileInput(FileName);
		Encryption();
	}
	else if (UsersChoice == 2)
	{
		//get user input and put into file
		//start encryption function 
		FileName = UserTextEncryption();
		FileInput(FileName);
		Encryption();
	}
	else if (UsersChoice == 3)
	{
		//start decryption function
	}
	
	else
	{
		char exit = 'a';
		cout << "Press anything to exit." << endl;
		cin >> exit;
		
	}

	return UsersChoice;
}



int main()
{
	string UserName = "";

	primeNumberGenerator();

	Setup();
	
	UserName = PasswordChecker();

	cout << "Welcome " << UserName << endl;

	MyBig a, b, c,D, f, e, g, h;

	
	//a = "123456.543456";
	//b = 98767878.124322;

	/*string Test = "password";*/

	a = 1394; //3;
	b = 3127; //2;
	c = 2011; //3;
	D = a^c;
	f = 0;
	e = 1;
	g = a;
	h = 5;

	//cout <<"factorisation "<< Factorial(h)<<endl;

	//this code calculates A to the power of B
	while (f < (c-1))
	{
		g = g*a;
		f = f + e;
	}

	/***********
	PROBLEM WITH THE MOD FUNCTION

	How to solve the problem of a mod b
	
	tempary = 0; // this is used to store the previsious value
	a = 1050
	b = 52
	
	while ( a > 0)
	{
	tempary = a;
	a - b = a;
	
	}

	when a is less than 0 then tampary is equal to the mod value 
	however for every large numbers this could take a long time.

	another solution

	a/b = tempary  
	tempary + b = tempary 
	tempary - a = temapary

	example 50 mod 7 
	50 / 7 = 7
	7 + 7 = 49
	50 - 49= 1
	this is quicker than the above example but only works for interages

	*/
	cout << "A to the power of c = " << g << endl;
	f = Mod(g, b);
	cout << "Mod A and B " << f << endl;

	SimpleCalculating(a, b, c, g);

	

	/*int Acsii = hash<string>()(Test);

	//cout << "Hashed password is "<< Acsii << endl;


	string plainText;
	cout << "Enter text to convert to ASCII: ";
	
	getline(cin, plainText);

	//string result = "";
	string addToString = "";
	
	for (int i = 0; i < plainText.length(); i++)
	{
		int getcode = convertToASCII(plainText.at(i));
		cout << getcode << endl;
		//addToString = "" + getcode;
		//result.append(addToString);
			
			//= result + code;
	}



	
	//cout << result << endl;*/
	
	int choice = 0;
	
	while (choice < 4) {

		choice = Menu();
	}

	/*char exit = 'a';
	cout << "End of the program." << endl;
	cin >> exit;*/
	

	return 0;
}

