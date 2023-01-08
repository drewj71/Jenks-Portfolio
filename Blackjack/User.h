#pragma once
#include <iostream>
#include <string>
#include "Player.h"

class User
{
public:
	std::string userName;
	int keepPlayingInput = 1;
	bool GameNotOver = true;

	void GetPlayerName() {
		std::cout << "Enter your name:\n";
		std::cin >> userName;
	}

	void PlayersTurn(Player& p) {
		std::cout << '\n' << "Wallet Balance -- $" << p.playerWallet << '\n';
		std::cout << '\n' << userName << "'s Bet -- $" << p.playerBet << '\n';
		std::cout << "Here is " << userName << "'s hand --\n";
		std::cout << '\n';
	}

	void PlayerCardsValue(Player& p) {
		std::cout << '\n';
		std::cout << userName << "'s cards value is -- " << (p.playerHand.at(0).value + p.playerHand.at(1).value) << '\n';
		std::cout << '\n';
	}

	void KeepPlaying() {
		std::cout << '\n';
		std::cout << "Would you like --\n";
		std::cout << "[1] Keep Playing [2] Quit\n";
		std::cin >> keepPlayingInput;
		if (keepPlayingInput == 1)
		{
			GameNotOver = true;
		}
		else
		{
			GameNotOver = false;
		}
	}
private:
};
