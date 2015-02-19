#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <map>
#include <algorithm>
#include "player.h"

using namespace std;

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

	//Setup players
	for(int i = 0; i < myPlayers.size(); i++)
	{
		myPlayers[i]->setCardList(cards);
		myPlayers[i]->generateHands(myPlayers[i]->getNumCards());
	}
	myPlayers[0]->updateProbabilities();
	cout << myPlayers[0]->getProbability("Scarlet");

	return 0;

	//Main logic loop
	bool won = false;
	string guess;
	string check;
	string answer;
	string guessP;
	string guessW;
	string guessL;
	while(!won)
	{
		//Formulate Guess
		guessP = "Scarlet";
		guessW = "Gun";
		guessL = "Lounge";

		//Output
		cout << guess << endl;
		for(int i = 0; i < myPlayers.size(); i++)
		{
			cout << "Did " << myPlayers[i]->getName() << " say no? ";
			cin >> answer;
			if(answer == "y")
			{
				//GuessLogic
			}
			else
				myPlayers[i]->removeHands(guessP, guessW, guessL);
		}
		cout << "Did you win?";
		cin >> check;
		if(check == "y")
			won = true;
	}	

	return 0;
}