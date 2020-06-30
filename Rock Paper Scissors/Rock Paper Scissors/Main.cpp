// This is a first attempt at a Rock Paper Scissors game
// This will also be the first project uploaded to Github
//
// Brandon Jett
// Start Date: 5/11/20

#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

//Function declarations
bool determineOpponent();
int getRPS(); 

int main()
{
	cout << "Welcome to Rock Paper Scissors" << endl << endl;
	//determineOpponent();
	
	//Get the Rock Paper Scissors of user 1 and cpu,
	//if playing vs another user get input of user 2
	//as well
	if (determineOpponent() == true) //User playing against CPU
	{
		cout << "User 1 ";
		int user_input = getRPS();

		//insert function call for CPU to determine its hand here
	}
	else
	{
		cout << "User 1 ";
		int user1_input = getRPS();

		cout << "User 2 ";
		int user2_input = getRPS();
	}
	

	system("pause");
	return 0;
	
}

//********************************************************
//This function will determine if the player wants to play
//against a computer (RNG) or play against another human
//
//Params: none
//return: bool
//********************************************************
bool determineOpponent()
{
	char userResponse = ' ';	//User response to determine if playing cpu
	bool playComputer;			//returned value, if true, CPU, else human

	//Prompt user to choose if they want to play human or CPU
	cout << "Do you want to play against a Computer? (Y/N): ";
	cin >> userResponse;
	cin.clear();
	cin.ignore(numeric_limits <streamsize> ::max(), '\n');	//not sure exactly as to how to use cin.ignore but this works
	userResponse = char(tolower(userResponse)); 

	//Check if the user entered a valid response
	if (userResponse != 'y'  && userResponse != 'n')
	{
		cout << "Response not valid, please enter only \"Y\" or \"N\"." << endl << endl << endl;
		determineOpponent();
	}
		
	//Determine if the user wants to play against another human or CPU
	if (userResponse == 'n')
	{
		playComputer = false;
		cout << "You have chosen to play against another human." << endl;
	}
	else
	{
		playComputer = true;
		cout << "You have chosen to play against the CPU." << endl;
	}
		
	return playComputer;
}

//********************************************************
//This function will determine from the user which hand 
//sign they want to use
//
//Params: none
//return: int
//********************************************************
int getRPS()
{
	int handsign = 1;

	//User chooses handsign
	cout << "Pick your move: " << endl << endl;
	cout << "Enter 1 for Rock '\n' Enter 2 for Scissors '\n' Enter 3 for Paper: ";
	cin >> handsign;
	cin.clear();
	cin.ignore(numeric_limits <streamsize> ::max(), '\n');
	
	//isdigit is always returning false, but somehow the code works so
	if (isalpha(handsign) || handsign < 1 || handsign > 3)
	{
		cout << "Invalid input: Please only enter 1, 2, or 3." << endl;
		getRPS();
	}
	else if (handsign == 1) //User chose Rock
	{
		cout << "User 1 selected Rock." << endl;
		return 1;
	}
	else if (handsign == 2) //User chose Scissors
	{
		cout << "User 1 selected Scissors." << endl;
		return 2;
	}
	else if (handsign == 3) //User chose Paper
	{
		cout << "User 1 selected Paper." << endl;
		return 3;
	}

	return handsign;
}