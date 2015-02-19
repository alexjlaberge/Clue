#include "player.h"

Player::Player(int numCards, string nameP)
{
	name = nameP;
	cardNum = numCards;
}

void Player::setCardList(vector<string> cardList)
{
	cards = cardList;
}

void Player::generateHands(int numCards)
{
	vector<string> *c;	
	if(numCards == 3)
	{
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
					possibleHands.push_back(*c);
				}
			}
		}
	}
	else if(numCards == 4)
	{
		for(int i = 0; i < 21; i++)
		{
			for(int j = i+1; j < 21; j++)
			{
				for(int k = j + 1; k < 21; k++)
				{
					for(int m = k + 1; m < 21; m++)
					{
						c = new vector<string>;
						c->push_back(cards[i]);
						c->push_back(cards[j]);
						c->push_back(cards[k]);
						c->push_back(cards[m]);
						possibleHands.push_back(*c);
					}
				}
			}
		}
	}
}

void Player::removeHands(string a, string b, string c)
{
	vector<string> d;
	for(int i = 0; i < possibleHands.size(); i++)
	{
		d = possibleHands[i];
		if(find(d.begin(), d.end(), a) != d.end())
		{
			possibleHands.erase(possibleHands.begin() + i);
		}
		else if(find(d.begin(), d.end(), b) != d.end())
		{
			possibleHands.erase(possibleHands.begin() + i);
		}
		else if(find(d.begin(), d.end(), c) != d.end())
		{
			possibleHands.erase(possibleHands.begin() + i);
		}
	}
}

void Player::updateProbabilities()
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

double Player::getProbability(string guess)
{
	return probabilities[guess];
}

string Player::getName()
{
	return name;
}

int Player::getNumCards()
{
	return cardNum;
}

void Player::printPossibilities()
{
	vector<string> c;
	for(int i = 0; i < possibleHands.size(); i++)
	{
		c = possibleHands[i];
		for(int j = 0; j < cardNum; j++)
		{
			cout << c[j] << " ";
		}
		cout << endl;
	}
}