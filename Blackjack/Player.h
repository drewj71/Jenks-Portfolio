#pragma once
#include <iostream>
#include <vector>
#include "Card.h"

class Player
{
public:
	int playerWallet = 100000;
	int playerBet = 1;
	std::vector<Card> playerHand;
};