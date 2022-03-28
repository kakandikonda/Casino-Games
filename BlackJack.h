#pragma once
#include <vector>

#include "Card.h"
#include "Deck.h"
#include "Player.h"

using namespace std;
using Hand = vector<Card>;
using Players = vector<Player>;

int sumOfCards(Hand);
void makePlayers(int, int, Players &);
int playerDecisions(Player &, Deck &);
int cpuChoices(Player &, Deck &);
void blackJack();
