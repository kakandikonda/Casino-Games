#include "Player.h"

Player::Player(bool c){
	cpu = c;
}

const vector<Card>& Player::getHand() const {
	return hand;
}

Card Player::getHandIndex(int index) const {
	return hand[index];
}

void Player::addToHand(Card card) {
	hand.push_back(card);
}

void Player::removeFromHand(int index) {
	hand.erase(hand.begin() + index);
}

void Player::clearHand() {
	hand.clear();
}

bool Player::isCPU()
{
	return cpu;
}
