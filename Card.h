#pragma once

#include <string>

using namespace std;

class Card
{
private:
	int suite;
	int rank;

public:
	Card(int, int);
	const int& getRank() const;
	const int& getSuite() const;
	string str();
};

