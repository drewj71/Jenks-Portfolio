#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "Card.h"
#include "Player.h"

class Dealer
{
public:
	std::vector<Card> dealerHand;
	std::vector<Card> shoe;
	bool dealNoBlackjack = true;
	bool playerHasntWon = true;
	bool dealHasntWon = true;
	bool NoDrawGame = true;

	void DealerAutoPlay() {
		if ((dealerHand.at(0).value + dealerHand.at(1).value) <= 16)
		{
			DealerHit();
			dHandValue = (dealerHand.at(0).value + dealerHand.at(1).value + dealerHand.at(2).value);
			std::cout << "Dealer Hand is now --\t" << dHandValue << std::endl;
			if (dHandValue > 21)
			{
				std::cout << "\t--DEALER HAS BUSTED--\t\n";
				playerHasntWon = false;
				return;
			}
			else if (dHandValue == 21)
			{
				std::cout << "\t--DEALER HAS BLACKJACK--\t\n";
				dealHasntWon = false;
				return;
			}
			else if (dHandValue < 21)
			{
				if (dHandValue <= 16)
				{
					DealerHit();
					dHandValue = (dealerHand.at(0).value + dealerHand.at(1).value + dealerHand.at(2).value + dealerHand.at(3).value);
					std::cout << "Dealer Hand is now --\t" << dHandValue << std::endl;
					if (dHandValue > 21)
					{
						std::cout << "\t--DEALER HAS BUSTED--\t\n";
						playerHasntWon = false;
						return;
					}
					else if (dHandValue == 21)
					{
						std::cout << "\t--DEALER HAS BLACKJACK--\t\n";
						dealHasntWon = false;
						return;
					}
					else
					{
						std::cout << "Dealer Hand is now --\t" << dHandValue << std::endl;
						if (pHandValue == dHandValue)
						{
							std::cout << '\n' << "--ITS A DRAW, PUSH!--\n";
							NoDrawGame = false;
						}
						else if (pHandValue > dHandValue && pHandValue <= 21)
						{
							std::cout << '\n' << "--PLAYER HAS WON--\n";
							playerHasntWon = false;
						}
						else if (dHandValue > pHandValue && dHandValue <= 21)
						{
							std::cout << '\n' << "--DEALER HAS WON--\n";
							playerHasntWon = false;
						}
						return;
					}
				}
			}
		}
		else if ((dealerHand.at(0).value + dealerHand.at(1).value) == 21)
		{
			std::cout << "\t--DEALER HAS BLACKJACK--\t\n";
			dealHasntWon = false;
			return;
		}
		else if ((dealerHand.at(0).value + dealerHand.at(1).value) < 21)
		{
			dHandValue = (dealerHand.at(0).value + dealerHand.at(1).value);
			DealerStand();
			if (pHandValue == dHandValue)
			{
				std::cout << '\n' << "--ITS A DRAW, PUSH!--\n";
				NoDrawGame = false;
			}
			else if (pHandValue > dHandValue && pHandValue <= 21)
			{
				std::cout << '\n' << "--PLAYER HAS WON--\n";
				playerHasntWon = false;
			}
			else if (dHandValue > pHandValue && dHandValue <= 21)
			{
				std::cout << '\n' << "--DEALER HAS WON--\n";
				dealHasntWon = false;
			}
			return;
		}
	}

	void DealerHit() {
		dealerHand.push_back(shoe.back());
		shoe.pop_back();
		std::cout << std::endl;
		std::cout << "\t--DEALER HITS--\t" << std::endl;
	}

	void DealerStand() {
		std::cout << "\t--DEALER STANDS--\t" << std::endl;
		std::cout << "DEALER Hand is now --\t" << dHandValue << std::endl;
	}

	void DealerAceConversion() {
		if (dealerHand.at(0).value == (int)Value::ACE)
		{
			if (11 + dealerHand.at(1).value <= 21)
			{
				dealerHand.at(0).value = 11;
			}
			else
			{
				return;
			}
		}
		else if (dealerHand.at(1).value == (int)Value::ACE)
		{
			if (dealerHand.at(0).value + 11 <= 21)
			{
				dealerHand.at(1).value = 11;
			}
			else
			{
				return;
			}
		}
		else
		{
			if (dealerHand.at(0).value == (int)Value::ACE && dealerHand.at(1).value == (int)Value::ACE)
			{
				dealerHand.at(0).value = 11;
				dealerHand.at(1).value = 1;
			}
		}
	}

	void DealCards(Player& p) {
		for (int i = 0; i < 2; i++)
		{
			p.playerHand.push_back(shoe.back());
			shoe.pop_back();
			dealerHand.push_back(shoe.back());
			shoe.pop_back();
		}
	}

	void SetupCardDeck() {
		for (int col = (int)Suit::HEARTS; col <= (int)Suit::CLUBS; col++)
		{
			for (int row = (int)Value::ACE; row <= (int)Value::KING; row++)
			{
				Card c;
				c.suits = (Suit)col;
				c.values = (Value)row;
				if (c.values == Value::JACK)
				{
					c.value = 10;
				}
				else if (c.values == Value::QUEEN)
				{
					c.value = 10;
				}
				else if (c.values == Value::KING)
				{
					c.value = 10;
				}
				else
				{
					c.value = (int)c.values;
				}
				int i = ((13 * col) + row - 1);
				deck.push_back(c);
			}
		}
	}

	void PrintDeck() {
		for (int col = (int)Suit::HEARTS; col <= (int)Suit::CLUBS; col++)
		{
			for (int row = (int)Value::ACE; row <= (int)Value::KING; row++)
			{
				int i = ((13 * col) + row - 1);
				deck[i].PrintCard();
			}
			std::cout << std::endl;
		}
	}

	void SetupCardShoe() {
		for (int i = 0; i < 312; i++)
		{
			if (i < 52)
			{
				shoe.push_back(deck[i]);
			}
			else if (103 > i)
			{
				shoe.push_back(deck[i - 51]);
			}
			else if (155 > i)
			{
				shoe.push_back(deck[i - 103]);
			}
			else if (207 > i)
			{
				shoe.push_back(deck[i - 155]);
			}
			else if (259 > i)
			{
				shoe.push_back(deck[i - 207]);
			}
			else if (311 > i)
			{
				shoe.push_back(deck[i - 259]);
			}
		}
	}

	void ShuffleCardShoe() {
		std::shuffle(begin(shoe), end(shoe), std::random_device());
	}

	void PrintCardShoe() {
		for (int i = 0; i < shoe.size(); i++)
		{
			shoe[i].PrintCard();
		}
	}

	void PlayerAutoPlay(Player& p) {
		if ((p.playerHand.at(0).value + p.playerHand.at(1).value) <= 16)
		{
			PlayerHit(p);
			pHandValue = (p.playerHand.at(0).value + p.playerHand.at(1).value + p.playerHand.at(2).value);
			std::cout << "Player Hand is now --\t" << pHandValue << std::endl;
			if (pHandValue > 21)
			{
				std::cout << "\t--PLAYER HAS BUSTED--\t\n";
				dealHasntWon = false;
				return;
			}
			else if (pHandValue == 21)
			{
				std::cout << "\t--PLAYER HAS BLACKJACK--\t\n";
				playerHasntWon = false;
				return;
			}
			else if (pHandValue < 21)
			{
				if (pHandValue <= 16)
				{
					PlayerHit(p);
					pHandValue = (p.playerHand.at(0).value + p.playerHand.at(1).value + p.playerHand.at(2).value + p.playerHand.at(3).value);
					std::cout << "Player Hand is now --\t" << pHandValue << std::endl;
					if (pHandValue > 21)
					{
						std::cout << "\t--PLAYER HAS BUSTED--\t\n";
						dealHasntWon = false;
						return;
					}
					else if (pHandValue == 21)
					{
						std::cout << "\t--PLAYER HAS BLACKJACK--\t\n";
						playerHasntWon = false;
						return;
					}
					else
					{
						std::cout << "\t--PLAYER STANDS--\t" << std::endl;
						std::cout << "Player Hand is now --\t" << pHandValue << std::endl;
						std::cout << '\n';
						return;
					}
				}
			} 
		}
		else if ((p.playerHand.at(0).value + p.playerHand.at(1).value) == (dealerHand.at(0).value + dealerHand.at(1).value))
		{
			std::cout << "\t--ITS A DRAW, PUSH!--\t\n";
			NoDrawGame = false;
			return;
		}
		else if ((p.playerHand.at(0).value + p.playerHand.at(1).value) == 21)
		{
			std::cout << "\t--PLAYER HAS BLACKJACK--\t\n";
			playerHasntWon = false;
			return;
		}
		else if ((p.playerHand.at(0).value + p.playerHand.at(1).value) < 21)
		{
			pHandValue = (p.playerHand.at(0).value + p.playerHand.at(1).value);
			PlayerStand();
			return;
		}
	}

	void PlayerHit(Player& p) {
		p.playerHand.push_back(shoe.back());
		shoe.pop_back();
		std::cout << "\t--PLAYER HITS--\t" << std::endl;
	}

	void PlayerStand() {
		std::cout << "\t--PLAYER STANDS--\t" << std::endl;
		std::cout << "Player Hand is now --\t" << pHandValue << std::endl;
		std::cout << '\n';
	}

	void PlayerAceConversion(Player& p) {
		if (p.playerHand.at(0).value == (int)Value::ACE)
		{
			if (11 + p.playerHand.at(1).value <= 21)
			{
				p.playerHand.at(0).value = 11;
			}
			else
			{
				return;
			}
		}
		else if (p.playerHand.at(1).value == (int)Value::ACE)
		{
			if (p.playerHand.at(0).value + 11 <= 21)
			{
				p.playerHand.at(1).value = 11;
			}
			else
			{
				return;
			}
		}
		else
		{
			if (p.playerHand.at(0).value == (int)Value::ACE && p.playerHand.at(1).value == (int)Value::ACE)
			{
				p.playerHand.at(0).value = 11;
				p.playerHand.at(1).value = 1;
			}
		}
	}

	void DealerOneCard() {
		std::cout << '\n';
		std::cout << "Dealer's one card is -- " << (dealerHand.at(0).value) << '\n';
		std::cout << '\n';
	}

	void IsDealerStartingBJ() {
		if ((dealerHand.at(0).value + dealerHand.at(1).value) == 21)
		{
			std::cout << '\n';
			std::cout << "Dealer's cards value is -- " << (dealerHand.at(0).value + dealerHand.at(1).value) << '\n';
			dealNoBlackjack = false;
			std::cout << "\t--DEALER HAS BLACKJACK--\t\n";
			return;
		}
	}

	void DealerCardsValue() {
		std::cout << '\n';
		std::cout << "Dealer's cards value is -- " << (dealerHand.at(0).value + dealerHand.at(1).value) << '\n';
		std::cout << '\n';
	}

	void ResetHands(Player& p) {
		dealNoBlackjack = true;
		playerHasntWon = true;
		dealHasntWon = true;
		NoDrawGame = true;
		p.playerHand.clear();
		dealerHand.clear();
	}

	void CheckWinners(Player& p) {
		if (pHandValue == dHandValue)
		{
			std::cout << '\n' << "--ITS A DRAW, PUSH!--\n";
			NoDrawGame = false;
		}
		else if (pHandValue > 21)
		{
			std::cout << '\n' << "--PLAYER HAS BUSTED, DEALER HAS WON!--\n";
			dealHasntWon = false;
		}
		else if (dHandValue > 21)
		{
			std::cout << '\n' << "--DEALER HAS BUSTED, PLAYER HAS WON!--\n";
			playerHasntWon = false;
		}
		else if (pHandValue > dHandValue && pHandValue <= 21)
		{
			std::cout << '\n' << "--PLAYER HAS WON--\n";
			playerHasntWon = false;
		}
		else if (dHandValue > pHandValue && dHandValue <= 21)
		{
			std::cout << '\n' << "--DEALER HAS WON--\n";
			playerHasntWon = false;
		}
	}
private:
	std::vector<Card> deck;
	int dHandValue;
	int pHandValue;
};