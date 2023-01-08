// Blackjack recoded -- Andrew Jenks
#include <iostream>
#include <vector>
#include "Menu.h"
#include "Blackjack.h"
#include "User.h"

using namespace std;

int main() {
	Menu blackjack;
	User one;
	blackjack.PrintMenu();
	if (blackjack.MenuStillGoing == false)
	{
		return 0;
	}
	do
	{
		Blackjack game;
		game.Gameplay();
		one.KeepPlaying();
	} while (one.GameNotOver == true);
	std::cout << '\n';
	std::cout << "Thanks for playing! Come again soon!\n";
	return 0;
}