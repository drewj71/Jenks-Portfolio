#pragma once
#include <iostream>
#include <vector>

class Menu
{
public:
	bool MenuStillGoing = true;

	void PrintMenu() {
		std::cout << "\tWelcome to the Casino!\n";
		std::cout << "---------------------------------\n";
		std::cout << "Here are your options: (1) Menu (2) Play Blackjack (3) Quit\n";
		std::cin >> choice;
		if (choice == 1)
		{
			std::cout << "Blackjack is a casino banking game. It is also known as Twenty-One because\n";
			std::cout << "the objective is to get your cards equal to or as close to 21 without going over.\n";
			std::cout << "You start with 2 cards and the dealer starts with 2 cards, one face down. You\n";
			std::cout << "have the choice to hit or stand based on your starting value. If the dealer has\n";
			std::cout << "Blackjack right away then he wins. If you have it right away then you win, if both\n";
			std::cout << "have it then there is a draw. This Blackjack game uses a shoe of 6 decks of cards.\n";
			std::cout << std::endl << "Press (1) Play Blackjack (2) Quit\n";
			std::cin >> choice;
			if (choice == 1)
			{
				return;
			}
			else if (choice == 2)
			{
				MenuStillGoing = false;
				std::cout << "Come again soon! Goodbye!\n";
				return;
			}
		}
		else if (choice == 2)
		{
			return;
		}
		else if (choice == 3)
		{
			MenuStillGoing = false;
			std::cout << "Come again soon! Goodbye!\n";
			return;
		}
		else
		{
			MenuStillGoing = false;
			std::cout << "Not a valid option. Goodbye!\n";
			return;
		}
	}

private:
	int choice = 0;
};

