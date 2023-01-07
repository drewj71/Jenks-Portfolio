#pragma once
#include <iostream>
#include <string>
class Menu
{
public:
	bool isMenuStillGoing = true;
	int input = 0;
	std::string name;
	std::string name2;

	void DisplayMenu() {
		std::cout << "\t--Welcome to the Game of Tic Tac Toe!--\t\n";
		std::cout << "[1] Rules\t[2] Play\t[3] Quit\n";
		std::cin >> input;
		if (input == 1)
		{
			std::cout << "\nBoard made up of 3x3 squares. To win you must get three in a row or diagnol of X's / O's.\n";
			std::cout << "The X's will go first, and you will be first to play. You will play against a CPU, goodluck!\n";
			std::cout << std::endl;
			std::cout << "\t[1] Play\t[2] Quit\n";
			std::cin >> input;
			if (input == 2)
			{
				std::cout << "Come again soon!\n";
				isMenuStillGoing = false;
				return;
			}
			else
			{
				return;
			}
		}
		else if (input == 3)
		{
			std::cout << "Come again soon!\n";
			isMenuStillGoing = false;
			return;
		}
		else
		{
			return;
		}
	}

	void GetPlayerName() {
		std::cout << "Please enter your name: \n";
		std::cin >> name;
		std::cout << std::endl;
	}

	void GetPlayer2Name() {
		std::cout << "Please enter your name PLAYER2: \n";
		std::cin >> name2;
		std::cout << std::endl;
	}
private:
};
