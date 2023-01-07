#pragma once
#include <iostream>
#include <vector>
#include <string>

class Board
{
public:
	std::vector<std::string> line1 = { "E", "E", "E" };
	std::vector<std::string> line2 = { "E", "E", "E" };
	std::vector<std::string> line3 = { "E", "E", "E" };

	void InitBoard() {
		std::cout << std::endl;
		line1.push_back(line1[0]);
		std::cout << line1[0];
		std::cout << "  |  ";
		line1.push_back(line1[1]);
		std::cout << line1[1];
		std::cout << "  |  ";
		line1.push_back(line1[2]);
		std::cout << line1[2] << std::endl;
		std::cout << "--------------" << std::endl;
		line2.push_back(line2[0]);
		std::cout << line2[0];
		std::cout << "  |  ";
		line2.push_back(line2[1]);
		std::cout << line2[1];
		std::cout << "  |  ";
		line2.push_back(line2[2]);
		std::cout << line2[2] << std::endl;
		std::cout << "--------------" << std::endl;
		line3.push_back(line3[0]);
		std::cout << line3[0];
		std::cout << "  |  ";
		line3.push_back(line3[1]);
		std::cout << line3[1];
		std::cout << "  |  ";
		line3.push_back(line3[2]);
		std::cout << line3[2] << std::endl;
	}

	void ClearBoard() {
		for (int i = 0; i < 3; i++)
		{
			line1.at(i) = 'E';
			line2.at(i) = 'E';
			line3.at(i) = 'E';
		}
	}

private:
	bool isThereAWinner = false;
};
