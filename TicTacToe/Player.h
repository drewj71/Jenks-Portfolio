#pragma once
#include <iostream>
#include <string>
#include "Board.h"
#include "Menu.h"

class Player
{
public:
	bool hasPlayerWon = false;

	void MakePlay(Board& b) {
		std::cout << std::endl;
		std::cout << "Where would you like to go?\n";
		std::cout << "[LT] [MT] [RT]\n";
		std::cout << "[LM] [M] [RM]\n";
		std::cout << "[LB] [MB] [RB]\n";
		std::cin >> playerInput;
		if (playerInput == "LT")
		{
			b.line1[0].pop_back();
			b.line1[0].push_back('X');
		}
		else if (playerInput == "MT")
		{
			b.line1[1].pop_back();
			b.line1[1].push_back('X');
		}
		else if (playerInput == "RT")
		{
			b.line1[2].pop_back();
			b.line1[2].push_back('X');
		}
		else if (playerInput == "LM")
		{
			b.line2[0].pop_back();
			b.line2[0].push_back('X');
		}
		else if (playerInput == "M")
		{
			b.line2[1].pop_back();
			b.line2[1].push_back('X');
		}
		else if (playerInput == "RM")
		{
			b.line2[2].pop_back();
			b.line2[2].push_back('X');
		}
		else if (playerInput == "LB")
		{
			b.line3[0].pop_back();
			b.line3[0].push_back('X');
		}
		else if (playerInput == "MB")
		{
			b.line3[1].pop_back();
			b.line3[1].push_back('X');
		}
		else if (playerInput == "RB")
		{
			b.line3[2].pop_back();
			b.line3[2].push_back('X');
		}
		else
		{
			MakePlay(b);
		}
	}

	void MakePlayPlayer2(Board& b) {
		std::cout << std::endl;
		std::cout << "Where would you like to go?\n";
		std::cout << "[LT] [MT] [RT]\n";
		std::cout << "[LM] [M] [RM]\n";
		std::cout << "[LB] [MB] [RB]\n";
		std::cin >> playerInput;
		if (playerInput == "LT")
		{
			b.line1[0].pop_back();
			b.line1[0].push_back('O');
		}
		else if (playerInput == "MT")
		{
			b.line1[1].pop_back();
			b.line1[1].push_back('O');
		}
		else if (playerInput == "RT")
		{
			b.line1[2].pop_back();
			b.line1[2].push_back('O');
		}
		else if (playerInput == "LM")
		{
			b.line2[0].pop_back();
			b.line2[0].push_back('O');
		}
		else if (playerInput == "M")
		{
			b.line2[1].pop_back();
			b.line2[1].push_back('O');
		}
		else if (playerInput == "RM")
		{
			b.line2[2].pop_back();
			b.line2[2].push_back('O');
		}
		else if (playerInput == "LB")
		{
			b.line3[0].pop_back();
			b.line3[0].push_back('O');
		}
		else if (playerInput == "MB")
		{
			b.line3[1].pop_back();
			b.line3[1].push_back('O');
		}
		else if (playerInput == "RB")
		{
			b.line3[2].pop_back();
			b.line3[2].push_back('O');
		}
		else
		{
			MakePlayPlayer2(b);
		}
	}

	void PlayerCheckWinner(Menu& m, Board& b) {
		if (b.line1[0] == "X" && b.line1[1] == "X" && b.line1[2] == "X")
		{
			std::cout << std::endl;
			std::cout << m.name << " has WON!\n";
			hasPlayerWon = true;
		}
		else if (b.line2[0] == "X" && b.line2[1] == "X" && b.line2[2] == "X")
		{
			std::cout << std::endl;
			std::cout << m.name << " has WON!\n";
			hasPlayerWon = true;
		}
		else if (b.line3[0] == "X" && b.line3[1] == "X" && b.line3[2] == "X")
		{
			std::cout << std::endl;
			std::cout << m.name << " has WON!\n";
			hasPlayerWon = true;
		}
		else if (b.line1[0] == "X" && b.line2[0] == "X" && b.line3[0] == "X")
		{
			std::cout << std::endl;
			std::cout << m.name << " has WON!\n";
			hasPlayerWon = true;
		}
		else if (b.line1[1] == "X" && b.line2[1] == "X" && b.line3[1] == "X")
		{
			std::cout << std::endl;
			std::cout << m.name << " has WON!\n";
			hasPlayerWon = true;
		}
		else if (b.line1[2] == "X" && b.line2[2] == "X" && b.line3[2] == "X")
		{
			std::cout << std::endl;
			std::cout << m.name << " has WON!\n";
			hasPlayerWon = true;
		}
		else if (b.line1[0] == "X" && b.line2[1] == "X" && b.line3[2] == "X")
		{
			std::cout << std::endl;
			std::cout << m.name << " has WON!\n";
			hasPlayerWon = true;
		}
		else if (b.line3[0] == "X" && b.line2[1] == "X" && b.line1[2] == "X")
		{
			std::cout << std::endl;
			std::cout << m.name << " has WON!\n";
			hasPlayerWon = true;
		}
		else if (b.line1[0] != "E" && b.line1[1] != "E" && b.line1[2] != "E")
		{
			if (b.line2[0] != "E" && b.line2[1] != "E" && b.line2[2] != "E")
			{
				if (b.line3[0] != "E" && b.line3[1] != "E" && b.line3[2] != "E")
				{
					std::cout << std::endl;
					std::cout << "CAT'S GAME! NO WINNER!\n";
					hasPlayerWon = true;
				}
			}
		}
	}

	void Player2CheckWinner(Menu& m, Board& b) {
		if (b.line1[0] == "O" && b.line1[1] == "O" && b.line1[2] == "O")
		{
			std::cout << std::endl;
			std::cout << m.name2 << " has WON!\n";
			hasPlayerWon = true;
		}
		else if (b.line2[0] == "O" && b.line2[1] == "O" && b.line2[2] == "O")
		{
			std::cout << std::endl;
			std::cout << m.name2 << " has WON!\n";
			hasPlayerWon = true;
		}
		else if (b.line3[0] == "O" && b.line3[1] == "O" && b.line3[2] == "O")
		{
			std::cout << std::endl;
			std::cout << m.name2 << " has WON!\n";
			hasPlayerWon = true;
		}
		else if (b.line1[0] == "O" && b.line2[0] == "O" && b.line3[0] == "O")
		{
			std::cout << std::endl;
			std::cout << m.name2 << " has WON!\n";
			hasPlayerWon = true;
		}
		else if (b.line1[1] == "O" && b.line2[1] == "O" && b.line3[1] == "O")
		{
			std::cout << std::endl;
			std::cout << m.name2 << " has WON!\n";
			hasPlayerWon = true;
		}
		else if (b.line1[2] == "O" && b.line2[2] == "O" && b.line3[2] == "O")
		{
			std::cout << std::endl;
			std::cout << m.name2 << " has WON!\n";
			hasPlayerWon = true;
		}
		else if (b.line1[0] == "O" && b.line2[1] == "O" && b.line3[2] == "O")
		{
			std::cout << std::endl;
			std::cout << m.name2 << " has WON!\n";
			hasPlayerWon = true;
		}
		else if (b.line3[0] == "O" && b.line2[1] == "O" && b.line1[2] == "O")
		{
			std::cout << std::endl;
			std::cout << m.name2 << " has WON!\n";
			hasPlayerWon = true;
		}
		else if (b.line1[0] != "E" && b.line1[1] != "E" && b.line1[2] != "E")
		{
			if (b.line2[0] != "E" && b.line2[1] != "E" && b.line2[2] != "E")
			{
				if (b.line3[0] != "E" && b.line3[1] != "E" && b.line3[2] != "E")
				{
					std::cout << std::endl;
					std::cout << "CAT'S GAME! NO WINNER!\n";
					hasPlayerWon = true;
				}
			}
		}
	}
private: 
	std::string playerInput;
};
