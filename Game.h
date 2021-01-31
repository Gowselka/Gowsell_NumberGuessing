/*
Author: Kevin Gowsell

Course: CIS 2207 N01 Data Structures and Algorithms

Date Begun: 1/21/2021

Problem Description: Design and implement an ADT for a one-person guessing game that chooses n random integers in the range of 1 to m and asks the user to guess them.  
						The same integer might be chosen more than once.  
*/

#ifndef GAME_H
#define GAME_H
#include <vector>
using namespace std;

//encapsulation example
class GetGameInputs {
private:
	int numberofInts;
	int range;
public:
	void setNOI(int a) {
		numberofInts = a;
	}
	void setRange(int b) {
		range = b;
	}
	int returnNOI() {
		return numberofInts;
	}
	int returnRange() {
		return range;
	}
	void Display() {
		cout << " Game Inputs are set to: " << numberofInts << " for number of integers to guess in a range of 1 to " << range << endl;
	}
};
class Game {
public:
	vector<int> RandomInt(int numInts, int maxRange);
	void GuessTheIntegers(vector<int>random, int numInts, int rangeMax);
};





#endif





