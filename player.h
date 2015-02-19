#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Player
{
public:
	Player(int numCards, string nameP);
	void generateHands(int numCards);
	void removeHands(string a, string b, string c);
	void updateProbabilities();
	double getProbability(string guess);
	string getName();
	int getNumCards();
	void printPossibilities();
	void setCardList(vector<string> cardList);

private:
	int cardNum;
	string name;
	vector<vector<string>> possibleHands;
	map<string, double> probabilities;
	vector<string> hand;
	vector<string> cards;
};