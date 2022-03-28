#pragma once
#include <vector>
#include "Card.h"

using namespace std;

class Player
{
private:
	vector<Card> hand;
	bool cpu;

public:
	Player(bool);
	const vector<Card>& getHand() const;
	Card getHandIndex(int) const;
	void addToHand(Card);
	void removeFromHand(int);
	void clearHand();
	bool isCPU();
};

