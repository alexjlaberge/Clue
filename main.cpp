#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	vector<string> cards;
	cards = {"Scarlet", "Plum", "Mustard", "White", "Green", "Peacock",
			 "Rope", "Wrench", "Pistol", "Candlestick", "Pipe", "Dagger",
			 "Ballroom", "Kitchen", "DiningRoom", "BilliardRoom",
			 "Lounge", "Library", "Study", "Conservatory", "Hall"};

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
				cout << cards[i] << " ";
				c->push_back(cards[i]);
				cout << cards[j] << " ";
				c->push_back(cards[j]);
				cout << cards[k] << " ";
				c->push_back(cards[k]);
				combos.push_back(*c);
				cout << endl << flush;
			}
		}
	}	

	return 0;
}