#include "Card.h"
#include <string>

using namespace std;

Card::Card(int r, int s) {
	rank = r;
	suite = s;
}

const int& Card::getRank() const {
	return rank;
}

const int& Card::getSuite() const
{
	return suite;
}

string Card::str()
{
	return to_string(rank) + " of " + to_string(suite);
}
