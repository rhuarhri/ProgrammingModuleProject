
#include "stdafx.h"
#include <iostream>
#include <fstream> 
using namespace std;

/*struct UserInfo {
	string Name;
	string Password;
	string PasswordHint;
};*/


//string Hint = "The password is password";

/*bool PasswordChecker(){

	
	
	string UserInput = "a";

	cout << "Please type in the password" << endl;
	cin >> UserInput;

	int UIHashed = hash<string>()(UserInput);

	while (UIHashed != HashedPassword)
	{
		cout << "Hint: " << Hint << endl;
		cout << "Please type in the password" << endl;
		//cin >> UserInput;
		UIHashed = hash<string>()(UserInput);
	}
	

	return true;

}

//Setup function 

/*string Setup()
{
	ifstream inFile("User.txt");
	
	if (!inFile)
	{
		//start setup
		string UserName = "";
		string UserPassword = "";
		string PasswordHint = "";
		bool inputCorrect = false;
		
		while (inputCorrect == false) {
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
			char UserAnswer = 'a';
			cin >> UserAnswer;
			
			if (UserAnswer == 'y' || UserAnswer == 'Y')
			{
				inputCorrect = true;
			}
		}

		int HashedPassword = hash<string>()(UserPassword);
		
		ofstream UserFile("User.txt");
		UserFile << UserName " " << HashedPassword << " " << PasswordHint; 
		
	}

	

	inFile >> UserInfo.Name >> UserInfo.Password >> UserInfo.PasswordHint;

	return UserInfo.Name;
}*/