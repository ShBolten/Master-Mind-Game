//============================================================================
// Name        : MasterMind.cpp
// Author      : Shaun Bolten
// Version     : C++
// Copyright   :
// Description : This is a project consisting of the game Mater-Mind. It is a
//				 guessing game that is based upon a secret code, and the user
//				 entering that secret code, or attempting to. Along with this
//				 there are hints given to the user; black pins for a correct
//				 color in a correct position (numbers in the instance of my
//				 algorithm), and white pins for the number of correct colors
//				 in the wrong position. The game can be played multiple times.
//============================================================================

#include <iostream>
#include <random>
#include <cstdlib>
#include <string>

using namespace std;
void playGame();
void gamePlay();

int main()
{
	char userGame;
	cout << "Does the user want to play Master-Mind? Enter Y or N: " << endl;
	cin >> userGame;
	while (userGame == 'Y' || userGame == 'y') { //This while loop will continue until the user does not want to play.
		playGame();
		gamePlay();
		cout << "Does the user want to play Master-Mind? Enter Y or N: " << endl;
		cin >> userGame;
	}
	cout << "MasterMind has been exited." << endl;
	return (0);
} //End of Main method.

void playGame() //This method will contain the game instructions.
{
	cout << "The objective of this game is for the user to correctly guess a 'secret code'." << endl;
	cout << "The secret code can consist of eight to four colors in length." << endl;
	cout << "These colors will be set to numbers for simplicity: Green - 1, Red - 2, Blue - 3," << endl;
	cout << "Purple - 4, Brown - 5, Yellow - 6, Orange - 7, Grey - 8, there can be repeats!" << endl;
	cout << "There are also hints given after each turn, Black being in the correct color in the" << endl;
	cout << "correct position, and White being a correct color in an incorrect position." << endl;
	return;
} //End pf playGame method.

void gamePlay() //This method will contain the bulk of the game, or game-play.
{
	int pins, blackPins = 0, whitePins = 0, colors, guesses, count = 0, attempts = 0;
	string secret, user;
	cout << "Please enter the number of pins that will be used(1 - 7): " << endl;
	cin >> pins;
	cout << "Please enter the number of colors to be used(1 - 8): " << endl;
	cin >> colors;
	cout << "Please enter the number of guesses you will be allowing yourself: " << endl;
	cin >> guesses;
	random_device myEngine;
	uniform_int_distribution<int> randomInt(0, colors);
	while(count < pins) {
		secret += to_string(randomInt(myEngine)); //Adding each random number to make secret string.
		count++;
	}
	cout << secret << endl;
	cout << "Secret Code Generated! Beginning game now..." << endl;
	while(attempts <= guesses) { //Beginning the while loop that contains the game.
			cout << "Enter your guess (in one line): " << endl;
			cin >> user;
			while (user.length() != secret.length()) { //While the input is not valid.
				cout << "Please enter a valid input." << endl;
				cin >> user;
			}
			for (int i = 0; i < user.length(); i++) { //Iterate through the user's input.
				if (user == secret) { //Check if user guessed correctly.
					cout << "USER GUESSED THE SECRET COLORS CORRECTLY!" << endl;
					attempts = guesses;
					break; //End loop and function if guess is correctly guessed.
				}
				else if (user[i] == secret[i]) { //Check if need to add black pin (if user guessed a correct number in the correct place).
					blackPins += 1;
					cout << "BLACK PIN ADDED" << endl;
					cout << blackPins << endl;
					continue;
				}
				else if (secret.find(user[i])) { //Check if need to add white pin (if user guessed a correct number in the wrong place)
					if (secret.find(user[i]) > 0 && secret.find(user[i]) < 2) {
						whitePins += 1;
						cout << "WHITE PIN ADDED" << endl;
						cout << whitePins << endl;
						continue;
					}
				}
			}
			attempts+=1; //Reset the loop and add to the attempts.
			}
	cout << "The secret code generated was: " << user << endl;
} //End of gamePlay method.

//green = 1, red = 2, blue = 3, purple = 4, brown = 5, yellow = 6, orange = 7, grey = 8
