#include "BlackJack.h"

#include <vector>
#include <iostream>

#include "Card.h"
#include "Deck.h"
#include "Player.h"

using namespace std;
using Hand = vector<Card>;
using Players = vector<Player>;

int sumOfCards(Hand hand) {
	int sum = 0;
	int aces = 0;
	for (auto element : hand) {
		if (element.getRank() > 10) {
			sum += 10;
		}
		else if (element.getRank() == 1 && sum + 11 <= 21) {
			aces++;
			sum += 11;
		}
		else {
			sum += element.getRank();
		}
	}
	while (sum > 21 && aces > 0) {
		sum -= 10;
	}
	return sum;
}

void makePlayers(int reg, int cpu, Players & players) {
	for (int i = 0; i < reg; i++) {
		Player player(false);
		players.push_back(player);
	}

	for (int i = 0; i < cpu; i++) {
		Player player(true);
		players.push_back(player);
	}
}

int playerDecisions(Player & player, Deck & deck) {
	cout << "current hand: ";
	cout << "[";
	auto hand = player.getHand();
	for (int i = 0; i < hand.size(); i++) {
		cout << player.getHandIndex(i).str();
		if (i != hand.size() - 1) {
			cout << ", ";
		}
	}
	cout << "]" << endl;
	string choice;
	cout << "options: fold(f) hit(h)" << endl;
	cout << "choice: ";
	cin >> choice;
	if (choice == "f") return 1;
	else {
		player.addToHand(deck.deal());
		return 0;
	}


}
int cpuChoices(Player & player, Deck & deck) {
	if(sumOfCards(player.getHand()) < 16 ){
		player.addToHand(deck.deal());
		return 0;
	}
	return 1;
}

void blackJack() {
	vector<Player> players;
	int numPlayers;
	int numCPU;
	Deck deck;
	deck.shoufle();
	cout << "Welcome to Blackjack! Here you can play against CPU's and friends locally" << endl;
	cout << "How many controlled players do you want: ";
	cin >> numPlayers;
	cout << "How many CPU's do you want: ";
	cin >> numCPU;
	cout << endl;
	makePlayers(numPlayers, numCPU, players);
	for (int i = 0; i < players.size(); i++) {
		players[i].addToHand(deck.deal());
	}
	// get the cpu's done first
	int cpuStop = 0;
	while (cpuStop != numCPU) {
		cpuStop = 0;
		for (int j = numCPU - 1; j < players.size(); j++) {
			cpuStop += cpuChoices(players[j], deck);
		}
	}
	int stop = 0;
	while (stop != numPlayers) {
		stop = 0;
		for (int i = 0; i < players.size(); i++) {
			auto & player = players[i];
			//cout << "Player hand size: " << player.getHand().size() << endl;
			if (sumOfCards(player.getHand()) <= 21 && !player.isCPU()) {
				cout << "Player " << i + 1 << "'s turn." << endl;
				cout << "Current sum: " << sumOfCards(player.getHand()) << endl;
				stop += playerDecisions(player, deck);
				cout << "New hand: ";
				cout << "[";
				auto hand = player.getHand();
				for (int i = 0; i < hand.size(); i++) {
					cout << player.getHandIndex(i).str();
					if (i != hand.size() - 1) {
						cout << ", ";
					}
				}
				cout << "]" << endl;
				cout << "New sum: " << sumOfCards(player.getHand()) << endl;
				
			}
			else if(!player.isCPU()) {
				cout << "player " << i + 1 << " has exceded 21. Hence he is out" << endl;
				stop += 1;
			}
			cout << endl;
			
		}
	}
	for (int i = 0; i < players.size(); i++) {
		cout << "Player " << i + 1 << "'s sum: " << sumOfCards(players[i].getHand()) << endl;
	}
	// make a winners thing
	vector<vector<int>> winner;
	int max = 0;
	for (int i = 0; i < players.size(); i++) {
		int sum = sumOfCards(players[i].getHand());
		if (sum <= 21 && sum > max) {
			winner.clear();
			max = sum;
			vector<int> x{ sum, i };
			winner.push_back(x);
		}
		else if (sum <= 21 && sum == max) {
			vector<int> x{ sum, i };
			winner.push_back(x);
		}
	}
	if (winner.size() > 1) {
		cout << "The winners are players: ";
	}
	else {
		cout << "The winner is player: ";
	}
	for (auto element : winner) {
		cout << element[1] + 1 << " ";
	}

}
