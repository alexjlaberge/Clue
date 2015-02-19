#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

class Player
{
public:
	int cardNum;
	string name;
	Player(int numCards, string nameP)
	{
		name = nameP;
		cardNum = numCards;
		generateHands(cardNum);
	}
	void generateHands(int cardNum)
	{

	}
	void updateProbabilities()
	{

	}
};

int main()
{
	//Guaranteed cards
	vector<string> cards;
	cards = {"Rope", "Wrench", "Pistol", "Candlestick", "Pipe", "Dagger",
			 "Ballroom", "Kitchen", "DiningRoom", "BilliardRoom",
			 "Lounge", "Library", "Study", "Conservatory", "Hall"};

	//Adding players
	string players;
	int numPlayers;
	cout << "Which characters are playing?\n";
	cin >> players;
	numPlayers = players.size();
	for(int i = 0; i < players.size(); i++)
	{
		if(players[i] == 'R')
			cards.push_back("Scarlet");
		else if(players[i] == 'Y')
			cards.push_back("Mustard");
		else if(players[i] == 'W')
			cards.push_back("White");
		else if(players[i] == 'G')
			cards.push_back("Green");
		else if(players[i] == 'B')
			cards.push_back("Peacock");
		else if(players[i] == 'P')
			cards.push_back("Plum");	
	}

	//Combination Generator
	vector<vector<string>> combos;
	vector<string> *c;
	for(int i = 0; i < 21; i++)
	{
		for(int j = i+1; j < 21; j++)
		{
			for(int k = j + 1; k < 21; k++)
			{
				c = new vector<string>;
				c->push_back(cards[i]);
				c->push_back(cards[j]);
				c->push_back(cards[k]);
				combos.push_back(*c);
			}
		}
	}
	cout << combos.size() << endl;

	//Main logic loop
	bool won = false;
	string guess;
	string check;
	while(!won)
	{


		//Output
		cout << guess << endl;
		cout << "Did you win?";
		cin >> check;
		if(check == "y")
			won = true;
	}	

	return 0;
}