#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#include "Deck.h"

using namespace std;

Deck::Deck() {
	
	// i = suite, j = rank
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 13; j++) {
			deck.push_back(Card(j, i));
		}
	}
	
}

void Deck::shoufle() {
	random_device rd;
	auto rng = default_random_engine{ rd() };
	shuffle(deck.begin(), deck.end(), rng);
}

void Deck::print() {
	for (auto card : deck) {
		cout << card.getSuite() << " " << card.getRank() << endl;
	}
}

Card Deck::deal()
{
	Card topCard = deck[0];
	deck.erase(deck.begin());
	return topCard;
}

int Deck::size()
{
	return deck.size();
}
