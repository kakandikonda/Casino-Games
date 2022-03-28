#pragma once
#include <vector>
#include <string>
#include "Card.h"

using namespace std;


class Deck
{
private:
	vector<Card> deck;
public:
	Deck();
	void shoufle();
	void print();
	Card deal();
	int size();


};

