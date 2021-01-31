/*
Author: Kevin Gowsell

Course: CIS 2207 N01 Data Structures and Algorithms

Date Begun: 1/21/2021

Problem Description:    Design and implement an ADT for a one-person guessing game that chooses n random integers 
						in the range of 1 to m and asks the user to guess them.
						The same integer might be chosen more than once.
*/

#include <iostream>   
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include "Game.h"
using namespace std;


int main() {

	bool PlayAgain = true;
	int intNum = 0;
	int maxRange = 0;
	vector<int> randGuess;
	string playAgainstring = "N";

	// Introduction
	cout << "Welcome to Gowsell's Guessing Game" << endl;
	cout << endl;
	cout << "In this game you will be asked to enter how many numbers you'd like to guess" << endl;
	cout << "Then you will be asked in what range these number will fall" << endl;
	cout << "The game will continue until you guess correctly or give up! " << endl;
	cout << "Have fun!" << endl; 
	cout << endl;

	//Main loop
	while (PlayAgain == true) {
		bool validIntNum = false;
		bool validRange = false;
		GetGameInputs gGI;
		Game game;

		//Get the number of ints to guess
		while (validIntNum == false) {
			cout << "Enter the Number of Integers to guess" << endl;;
			cin >> intNum;
			gGI.setNOI(intNum);
			if (cin.fail()) {
				cout << "Please enter a valid Integer" << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else {
				validIntNum = true;
			}
		}

		
		//Get the Range of those ints
		while (validRange == false) {
			cout << "Enter the Range of the Integers 1 to: ";
			cin >> maxRange;
			gGI.setRange(maxRange);
			if (cin.fail()) {
				cout << "Please enter a valid Integer" << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else {
				validRange = true;
				cin.clear();
			}
			
		}

		//call to game cpp to generate random integers based on given
		//randGuess = RandomInt(gGI.returnNOI(), gGI.returnRange());
		randGuess = game.RandomInt(intNum, maxRange);
		
		//prints the contents of vector after call for verification
		for (int i = 0; i < randGuess.size(); i++) {
			cout << (randGuess[i]) << endl;						
		}

		//GuessTheIntegers(randGuess, gGI.returnNOI(), gGI.returnRange());
		game.GuessTheIntegers(randGuess, intNum, maxRange);
		
		//Play again inquiry
		while(PlayAgain == true) {
			cout << "Play again? (Y/N):";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> playAgainstring;
			if (cin.fail()) {
				cout << "Please enter a valid string" << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			if (playAgainstring == "N" || playAgainstring == "Y" || playAgainstring == "n" || playAgainstring == "y") {
				if (playAgainstring == "N" || playAgainstring == "n") {
					PlayAgain = false;
					terminate;
				}
				else {
					cout << endl;
					cout << endl;
					break;
				}
			}
			else {
				continue;
			}
		}
	}

	return 0;                        // Terminate main()
}








