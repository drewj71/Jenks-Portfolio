#pragma once
#include <iostream>
#include "Board.h"
#include "Menu.h"
#include "Player.h"
#include "CPU.h"

class Gameplay
{
public:
	bool gameNotOver = true;
	bool playerWon = false;
	bool CPUWon = false;
	void PlayTicTacToe() {
		Menu m;
		if (showMenuAndName)
		{
			m.DisplayMenu();
			if (m.isMenuStillGoing == false)
			{
				std::cout << std::endl;
				return;
			}
		}
		std::cout << "Would you like to play against your friend, or against the CPU?\n [1] Play A Friend [2] Play CPU\n";
		std::cin >> userInput;
		if (userInput == 1)
		{
			Player p1;
			Player p2;
			m.GetPlayerName();
			m.GetPlayer2Name();
			Board b1;
			while (gameNotOver)
			{
				std::cout << "You will play against " << m.name2 << '\n';
				std::cout << std::endl;
				std::cout << "It is " << m.name << "'s turn!" << std::endl;
				b1.InitBoard();
				p1.MakePlay(b1);
				b1.InitBoard();
				p1.PlayerCheckWinner(m, b1);
				if (p1.hasPlayerWon == true)
				{
					m.isMenuStillGoing = false;
					playerWon = true;
					gameNotOver = false;
					return;
				}
				std::cout << std::endl;
				std::cout << "It is " << m.name2 << "'s turn!" << std::endl;
				p2.MakePlayPlayer2(b1);
				b1.InitBoard();
				p2.Player2CheckWinner(m, b1);
				if (p2.hasPlayerWon == true)
				{
					m.isMenuStillGoing = false;
					playerWon = true;
					gameNotOver = false;
					return;
				}
			}
			return;
		}
		else
		{
			std::cout << "You will play against the CPU!\n";
		}
		m.GetPlayerName();
		Board b;
		Player p;
		CPU bob;
		showMenuAndName = false;
		while (gameNotOver)
		{
			std::cout << std::endl;
			std::cout << "It is " << m.name << "'s turn!" << std::endl;
			b.InitBoard();
			p.MakePlay(b);
			b.InitBoard();
			p.PlayerCheckWinner(m, b);
			if (p.hasPlayerWon == true)
			{
				m.isMenuStillGoing = false;
				playerWon = true;
				gameNotOver = false;
				return;
			}
			std::cout << std::endl;
			std::cout << "It's the CPU's turn!\n";
			bob.CPUPlay(b);
			while (bob.CPUMadeMove == false)
			{
				bob.CPUPlay(b);
			}
			b.InitBoard();
			bob.CPUCheckWinner(b);
			if (bob.hasCPUWon == true)
			{
				m.isMenuStillGoing = false;
				CPUWon = true;
				gameNotOver = false;
				return;
			}
		}
	}

private:
	bool showMenuAndName = true;
	int userInput = 0;
};
