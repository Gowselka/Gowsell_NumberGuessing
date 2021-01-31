/*
Author: Kevin Gowsell

Course: CIS 2207 N01 Data Structures and Algorithms

Date Begun: 1/21/2021

Problem Description: Design and implement an ADT for a one-person guessing game that chooses n random integers in the range of 1 to m and asks the user to guess them.
						The same integer might be chosen more than once.
*/
#pragma once
#include <vector>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <iostream>   
#include "Game.h"
using namespace std;



vector<int> Game::RandomInt(int numInts, int maxRange) {
	
	vector<int> GeneratedIntegers;

	srand(time(0));								//Use current time as seed for
	for (int i = 0; i < numInts; i++) {			//loops as many times as number of integers from driver.cpp
		int Random = (rand() % maxRange);		//generated random integer and assigns it to Random
		GeneratedIntegers.push_back(Random);	//Pushes the integer to the end of the vector
	}
	
	return GeneratedIntegers;					//return a vector of randomly generated integers

}

void Game::GuessTheIntegers (vector<int>random, int numInts, int rangeMax) {
	bool guessIsCorrect = false;
	int enteredInts;
	vector<int>guesses;
	int correctGuesses = 0;
	vector<int>::iterator it;
	string input;
	int foundkey = 0;
	vector<int>temporary;

	while (guessIsCorrect == false) {
		//pull guesses from cin
		correctGuesses = 0;
		cout << "Enter your guesses for the " << numInts << " integers in the range from 1 to " << rangeMax << "that you selected: " << endl;
		for (int a = 0; a < numInts; a++) {
			cout << (a + 1) << " guess: ";
			cin >> enteredInts;
			guesses.push_back(enteredInts);
		}

		/*for (int i = 0; i < guesses.size(); i++)
		{
			cout << guesses[i] << endl;
		}
		cout << guesses.size() << endl;*/


		//check vectors against each other

		for (int o = 0; o < random.size(); o++) {
			temporary.push_back(random[o]);
		}

		//check vectors against each other

		for (int i = 0; i < guesses.size(); i++) {
			int key = guesses[i];						//assign the guesses to a key in a loop
			for (int e = 0; e < temporary.size(); e++) {
				int randomkey = temporary[e];				//search for that guess in random vector
				if (key == randomkey) {
					temporary.erase(temporary.begin() + e);

					correctGuesses++;
				}
				else {
					continue;
				}
			}
		}
		for (int u = 0; u < temporary.size(); u++) {
			temporary.erase(temporary.begin(), temporary.end());
		}
		for (int u = 0; u < guesses.size(); u++) {
			guesses.erase(guesses.begin(), guesses.end());
		}

		if (correctGuesses == random.size()) {
			cout << "All your answers are correct! Congratulations!" << endl;
			guessIsCorrect = true;
		}
		else {
			cout << correctGuesses << " of your guesses are correct" << endl;
		}


	}

}





