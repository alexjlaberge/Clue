#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

vector<string> cards;

class Player
{
public:
	int cardNum;
	string name;
	vector<vector<string>> possibleHands;
	map<string, double> probabilities;
	vector<string> hand;

	Player(int numCards, string nameP)
	{
		name = nameP;
		cardNum = numCards;
	}

	void generateHands(int numCards, int i, vector<string> hand)
	{
		
	}

	void removeHands(string a, string b, string c)
	{

	}

	void updateProbabilities()
	{
		int count;
		vector<string> c;
		for(int i = 0; i < cards.size(); i++)
		{
			count = 0;
			for(int j = 0; j < possibleHands.size(); j++)
			{
				c = possibleHands[j];
				if(find(c.begin(), c.end(), cards[i]) != c.end())
				{
					count++;
				}
			}
			probabilities[cards[i]] = (double)count / possibleHands.size();
		}
	}

	double getProbability(string guess)
	{
		return probabilities[guess];
	}
};

int main()
{
	//Guaranteed cards
	cards = {"Rope", "Wrench", "Pistol", "Candlestick", "Pipe", "Dagger",
			 "Ballroom", "Kitchen", "DiningRoom", "BilliardRoom",
			 "Lounge", "Library", "Study", "Conservatory", "Hall"};

	//Adding players
	string players;
	int numPlayers;
	cout << "Which characters are playing?\n";
	cin >> players;
	numPlayers = players.size();
	vector<Player*> myPlayers;
	string name;
	string numCards;
	for(int i = 0; i < players.size(); i++)
	{
		if(players[i] == 'R')
		{
			cout << "Scarlets Name: ";
			cin >> name;
			cout << "Scarlets # of Cards: ";
			cin >> numCards;
			myPlayers.push_back(new Player(atoi(numCards.c_str()), name));
			cards.push_back("Scarlet");
		}
		else if(players[i] == 'Y')
		{
			cout << "Mustards Name: ";
			cin >> name;
			cout << "Mustards # of Cards: ";
			cin >> numCards;
			myPlayers.push_back(new Player(atoi(numCards.c_str()), name));
			cards.push_back("Mustard");
		}
		else if(players[i] == 'W')
		{
			cout << "Whites Name: ";
			cin >> name;
			cout << "Whites # of Cards: ";
			cin >> numCards;
			myPlayers.push_back(new Player(atoi(numCards.c_str()), name));
			cards.push_back("White");
		}
		else if(players[i] == 'G')
		{
			cout << "Greens Name: ";
			cin >> name;
			cout << "Greens # of Cards: ";
			cin >> numCards;
			myPlayers.push_back(new Player(atoi(numCards.c_str()), name));
			cards.push_back("Green");
		}
		else if(players[i] == 'B')
		{
			cout << "Peacocks Name: ";
			cin >> name;
			cout << "Peacocks # of Cards: ";
			cin >> numCards;
			myPlayers.push_back(new Player(atoi(numCards.c_str()), name));
			cards.push_back("Peacock");
		}
		else if(players[i] == 'P')
		{
			cout << "Plums Name: ";
			cin >> name;
			cout << "Plums # of Cards: ";
			cin >> numCards;
			myPlayers.push_back(new Player(atoi(numCards.c_str()), name));
			cards.push_back("Plum");	
		}
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