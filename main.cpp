#include <iostream>
#include <string>

//games
#include "BlackJack.h"
#include "Roulette.h"

using namespace std;

int main() {
	cout << "Welcome to the casino! We have a variety of games to play. We have: " << endl;
	cout << "No gambling has been implemented yet" << endl;
	cout << "1) Blackjack" << endl;
	cout << "2) Roulette" << endl;
	cout << "3) Slot Mechine (in development)" << endl;
	cout << "q to quit" << endl;
	cout << "What would u like to play? ";
	string option;
	cin >> option;

	while (option != "q") {
		if (option == "1") {
			cout << endl;
			blackJack();
		}
		else if (option == "2") {
			roulette();
		}
		else if (option == "3") {
			cout << "the game is still in development and will be released soon. Sorry for your inconvenience" << endl;
		}
		else {
			cout << "Please enter a valid option" << endl;			
		}
		cout << "What would u like to play? ";
		cin >> option;
	}
	
}