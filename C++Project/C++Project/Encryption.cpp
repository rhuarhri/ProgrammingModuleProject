#include "stdafx.h"
#include "ttmath.h"
#include <iostream>
#include <fstream> 
using namespace std;



struct WordInFile {
	string CurrentWord;
};

//Converting to ascii code
void convertToASCII(WordInFile List[], int NumOfWords, string FileName)
{
	ifstream inFile(FileName);
	
	for (int i = 0; i<NumOfWords; i++)
	{
		inFile >> List[i].CurrentWord;
	}

	inFile.close();

	ofstream EncryptionFile("EncryptedFile.txt");

	for (int PlaceInFile = 0; PlaceInFile < NumOfWords; PlaceInFile++) {

		for (int i = 0; i < List[PlaceInFile].CurrentWord.length(); i++)
		{
			char letter = List[PlaceInFile].CurrentWord.at(i);
			int ascii = int(letter);
			//char letters = ascii;
			/*cout << letters << endl;
			cout << ascii << endl;*/

			//return ascii;

			EncryptionFile << ascii << endl;

			
		}
	}

	EncryptionFile.close();
}


void Encryption()
{
	/*the way that the encryption is going to work is that it will encrypt the message letter by letter
	then it will add the location number of the array for example if a is encrypted to 1000 and is in the 
	second location of the array then it will become 1002 and if there is an a in the third posistion
	it will be 1003*/
	/*int NumCars = FindNumCars("car.txt");
	Car* StockList = new Car[NumCars];*/

	//Encryption key generation should not be in this function
	

	ifstream infile("EncryptedFile.txt");
	//int codedLetter = 0;
	string codedLetter = "";
	while (!infile.eof())
	{

		getline(infile, codedLetter);
		

	}
	
	
	cout << "Encryption" << endl;

}


//This function take in a file that the user wants to be encrypted and then converts it into ascii code ready for encryption
void FileInput(string FileName)
{
	
	if (FileName == "")//This is if the user wants to encrypt a file
	{

		//string FileName = "";
		cout << "Type in the name of the .TXT file you want to encrypt." << endl;
		cin >> FileName;
		ifstream inFile(FileName);
		while (!inFile)
		{
			cout << "This file does not exist." << endl;
			cout << "Try using a different .TXT file." << endl;
			cout << "Type in the name of the .TXT file you want to encrypt." << endl;
			cin >> FileName;
		}

	}

	
	//string FileName = "";
	ifstream inFile(FileName);
	if (!inFile)
	{
		cout << "Error no file found!" << endl;
		
	}

	int NumOfWords = 0;
	string tempLine;
	while (!inFile.eof())
	{
		getline(inFile, tempLine);
		NumOfWords++;

		if (tempLine == "")
		{
			NumOfWords--;
		}
	}

	WordInFile* CurrentFile = new WordInFile[NumOfWords];

	inFile.close();

	convertToASCII(CurrentFile, NumOfWords, FileName);

	
}

string UserTextEncryption()
{
	cout << "Type in a phrase which you would like to encrypt" << endl;
	string FileName = "UserInput.txt";
	string UserPhase = "";
	cin >> UserPhase;
	ofstream UserInputFile(FileName);
	UserInputFile << UserPhase;
	UserInputFile.close();
	return FileName;
}

/*int FindNumCars(string CarFileName)
{
	// read the file, counting lines, until end of file reached
	ifstream inFile(CarFileName); // declare an OBJECT for handling file input and associate it with the cars.txt file
	if (!inFile)
	{
		return -1; //no file found - return -1
	}
	int counter = 0;
	string tempLine; //to hold lines read
	while (!inFile.eof())
	{
		getline(inFile, tempLine);	// this reads whole line into tempLine since we are not bothered about what is in it yet
		counter++;
	}
	// may need to check last line in case it contains nothing but eof

	if (tempLine == "")
	{
		counter--;
	}

	return counter; // count of lines is number of cars
}


int LoadCars(Car List[], int NumCars, string CarFileName)
{
	// read cars from file specified as parameter
	ifstream inFile(CarFileName); // declare an OBJECT for handling file input and associate it with the cars.txt file
	if (!inFile)
	{
		cout << "Oh dear, your file is not here" << endl;
		return 1; //an error - return a value to indicate this
	}
	// read Cars from the file up to number specified into array provided
	for (int i = 0; i<NumCars; i++)
	{
		inFile >> List[i].ModelName >> List[i].Registration >> List[i].EngineSize >> List[i].Price;
	}
	inFile.close();
	return 0;
}*/

