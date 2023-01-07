#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include "Board.h"

class CPU
{
public:
	bool hasCPUWon = false;
	bool CPUMadeMove = true;

	void CPUPlay(Board& b) {

		srand(unsigned(time(0)));
		int x = ((rand() % 9) + 1); 
		if (x == 1 && b.line1[0] != "X" && b.line1[0] != "O")
		{
			b.line1[0].pop_back();
			b.line1[0].push_back('O');
			CPUMadeMove = true;
		}
		else if (x == 2 && b.line1[1] != "X" && b.line1[1] != "O")
		{
			b.line1[1].pop_back();
			b.line1[1].push_back('O');
			CPUMadeMove = true;
		}
		else if (x == 3 && b.line1[2] != "X" && b.line1[2] != "O")
		{
			b.line1[2].pop_back();
			b.line1[2].push_back('O');
			CPUMadeMove = true;
		}
		else if (x == 4 && b.line2[0] != "X" && b.line2[0] != "O")
		{
			b.line2[0].pop_back();
			b.line2[0].push_back('O');
			CPUMadeMove = true;
		}
		else if (x == 5 && b.line2[1] != "X" && b.line2[1] != "O")
		{
			b.line2[1].pop_back();
			b.line2[1].push_back('O');
			CPUMadeMove = true;
		}
		else if (x == 6 && b.line2[2] != "X" && b.line2[2] != "O")
		{
			b.line2[2].pop_back();
			b.line2[2].push_back('O');
			CPUMadeMove = true;
		}
		else if (x == 7 && b.line3[0] != "X" && b.line3[0] != "O")
		{
			b.line3[0].pop_back();
			b.line3[0].push_back('O');
			CPUMadeMove = true;
		}
		else if (x == 8 && b.line3[1] != "X" && b.line3[1] != "O")
		{
			b.line3[1].pop_back();
			b.line3[1].push_back('O');
			CPUMadeMove = true;
		}
		else if (x == 9 && b.line3[2] != "X" && b.line3[2] != "O")
		{
			b.line3[2].pop_back();
			b.line3[2].push_back('O');
			CPUMadeMove = true;
		}
		else
		{
			CPUMadeMove = false;
		}
	}

	void CPUCheckWinner(Board& b) {
		if (b.line1[0] == "O" && b.line1[1] == "O" && b.line1[2] == "O")
		{
			std::cout << std::endl;
			std::cout << "CPU has WON!\n";
			hasCPUWon = true;
		}
		else if (b.line2[0] == "O" && b.line2[1] == "O" && b.line2[2] == "O")
		{
			std::cout << std::endl;
			std::cout << "CPU has WON!\n";
			hasCPUWon = true;
		}
		else if (b.line3[0] == "O" && b.line3[1] == "O" && b.line3[2] == "O")
		{
			std::cout << std::endl;
			std::cout << "CPU has WON!\n";
			hasCPUWon = true;
		}
		else if (b.line1[0] == "O" && b.line2[0] == "O" && b.line3[0] == "O")
		{
			std::cout << std::endl;
			std::cout << "CPU has WON!\n";
			hasCPUWon = true;
		}
		else if (b.line1[1] == "O" && b.line2[1] == "O" && b.line3[1] == "O")
		{
			std::cout << std::endl;
			std::cout << "CPU has WON!\n";
			hasCPUWon = true;
		}
		else if (b.line1[2] == "O" && b.line2[2] == "O" && b.line3[2] == "O")
		{
			std::cout << std::endl;
			std::cout << "CPU has WON!\n";
			hasCPUWon = true;
		}
		else if (b.line1[0] == "O" && b.line2[1] == "O" && b.line3[2] == "O")
		{
			std::cout << std::endl;
			std::cout << "CPU has WON!\n";
			hasCPUWon = true;
		}
		else if (b.line3[0] == "O" && b.line2[1] == "O" && b.line1[2] == "O")
		{
			std::cout << std::endl;
			std::cout << "CPU has WON!\n";
			hasCPUWon = true;
		}
		else if (b.line1[0] != "E" && b.line1[1] != "E" && b.line1[2] != "E")
		{
			if (b.line2[0] != "E" && b.line2[1] != "E" && b.line2[2] != "E")
			{
				if (b.line3[0] != "E" && b.line3[1] != "E" && b.line3[2] != "E")
				{
					std::cout << std::endl;
					std::cout << "CAT'S GAME! NO WINNER!\n";
					hasCPUWon = true;
				}
			}
		}
	}

private:
};
