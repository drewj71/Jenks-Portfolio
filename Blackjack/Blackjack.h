#pragma once
#include <iostream>
#include "Dealer.h"
#include "Player.h"
#include "User.h"

class Blackjack
{
public:
	void Gameplay() {
		User one;
		one.GetPlayerName();
		while (one.keepPlayingInput == 1)
		{
			Dealer bigMan;
			Player drew;
			bigMan.SetupCardDeck();
			bigMan.SetupCardShoe();
			bigMan.ShuffleCardShoe();
			bigMan.DealCards(drew);
			one.PlayersTurn(drew);
			drew.playerHand.at(0).PrintCard();
			drew.playerHand.at(1).PrintCard();
			bigMan.PlayerAceConversion(drew);
			one.PlayerCardsValue(drew);
			bigMan.dealerHand.at(0).PrintCard();
			bigMan.DealerOneCard();
			bigMan.DealerAceConversion();
			bigMan.IsDealerStartingBJ();
			if (bigMan.dealNoBlackjack == false) {
				bigMan.ResetHands(drew);
				return;
			}
			bigMan.PlayerAutoPlay(drew);
			if (bigMan.playerHasntWon == false) {
				bigMan.CheckWinners(drew);
				bigMan.ResetHands(drew);
				return;
			}
			if (bigMan.dealHasntWon == false) {
				bigMan.CheckWinners(drew);
				bigMan.ResetHands(drew);
				return;
			}
			bigMan.dealerHand.at(0).PrintCard();
			bigMan.dealerHand.at(1).PrintCard();
			bigMan.DealerCardsValue();
			if (bigMan.NoDrawGame == false) {
				bigMan.CheckWinners(drew);
				bigMan.ResetHands(drew);
				return;
			}
			bigMan.DealerAutoPlay();
			if (bigMan.dealHasntWon == false) {
				bigMan.CheckWinners(drew);
				bigMan.ResetHands(drew);
				return;
			}
			if (bigMan.playerHasntWon == false) {
				bigMan.CheckWinners(drew);
				bigMan.ResetHands(drew);
				return;
			}
			if (bigMan.NoDrawGame == false) {
				bigMan.CheckWinners(drew);
				bigMan.ResetHands(drew);
				return;
			}
		}
	}
};
