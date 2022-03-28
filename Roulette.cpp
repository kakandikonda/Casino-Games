#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "Roulette.h"

using namespace std;


void makeBoard(vector<string>& board) {
	board.push_back("0");
	for (int i = 1; i <= 10; i++) {
		if (i % 2 == 0) {
			string tile = to_string(i) + "B";
			board.push_back(tile);
		}
		else {
			string tile = to_string(i) + "R";
			board.push_back(tile);
		}
	}
	for (int i = 11; i <= 18; i++) {
		if (i % 2 == 0) {
			string tile = to_string(i) + "R";
			board.push_back(tile);
		}
		else {
			string tile = to_string(i) + "B";
			board.push_back(tile);
		}
	}
	for (int i = 19; i <= 28; i++) {
		if (i % 2 == 0) {
			string tile = to_string(i) + "B";
			board.push_back(tile);
		}
		else {
			string tile = to_string(i) + "R";
			board.push_back(tile);
		}
	}
	for (int i = 29; i <= 36; i++) {
		if (i % 2 == 0) {
			string tile = to_string(i) + "R";
			board.push_back(tile);
		}
		else {
			string tile = to_string(i) + "B";
			board.push_back(tile);
		}
	}
	board.push_back("00");
}

void playerBets(vector<vector<string>>& players, int p) {	
	for (int i = 0; i < p; i++) {
		vector<string> bets;
		while (true) {
			string bet;
			cout << "Player " << i + 1 << ": What would you like to bet on (f to stop)? ";
			cin >> bet;
			if (bet == "f") {
				break;
			}
			else {
				bets.push_back(bet);
			}			
		}
		players.push_back(bets);
	}
}

void checkBets(vector<vector<string>>& players, string tile) {
	stringstream ss;
	string color;
	string numStr = tile.substr(0, tile.size() - 1);
	int num = stoi(numStr);
	int n = 1;
	if (tile != "0" || tile != "00") {
		if (tile[tile.size() - 1] == 'B') {
			color = "black";
		}
		else {
			color = "red";
		}
		for (auto bets : players) {
			for (auto bet : bets) {
				if (bet == color || bet == numStr) {
					cout << "Player " << n << " is a winner. ";
				}
				else if (num % 2 == 0 && bet == "even") {
					cout << "Player " << n << " is a winner. ";
				}
				else if (num % 2 == 1 && bet == "odd") {
					cout << "Player " << n << " is a winner. ";
				}
				else if(bet.find('-') != string::npos) {
					int lower;
					int upper;
					string word;
					for (int i = 0; i < bet.size(); i++) {
						if (bet[i] != '-') {
							word += bet[i];
						}
						else {
							lower = stoi(word);
							word.clear();
						}
					}
					upper = stoi(word);
					if (lower < num && num < upper) {
						cout << "Player " << n << " is a winner. ";
					}
				}
			}
			n++;
		}
	}
	else {
		cout << "Casino wins and all players lose. Better luck next time!" << endl;
	}
	
}

string returnRandom(vector<string>& board) {

	/* initialize random seed: */
	srand(time(0));

	/* generate secret number between 1 and 10: */
	int range = board.size() - 1;
	int rnum = rand() % range;
	return board[rnum];
	

}

void roulette() {
	vector<string> board;
	makeBoard(board);
	int p;
	cout << "How many players to you want? ";
	cin >> p;
	vector<vector<string>> playersBets;
	string landed = returnRandom(board);
	//cout << landed << endl;
	playerBets(playersBets, p);
	cout << "And the ball laneded on: " << landed << endl;
	cout << "Therefore: " << endl;
	checkBets(playersBets, landed);
	cout << endl;
	cout << endl;
	

}
