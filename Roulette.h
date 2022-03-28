#pragma once
#include <vector>
#include <string>

using namespace std;

void makeBoard(vector<string>&);
void playerBets(vector<vector<string>>&, int);
string returnRandom(vector<string>&);
void checkBets(vector<vector<string>>&, string);
void roulette();