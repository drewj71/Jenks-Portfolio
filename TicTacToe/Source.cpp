#include <iostream>
#include "Menu.h"
#include "Gameplay.h"
using namespace std;

int main() {
	bool isGameStillGoing = true;
	int userInput;
	Gameplay xo;
	Menu m;
	do
	{
		xo.PlayTicTacToe();
		if (xo.CPUWon == true)
			m.isMenuStillGoing = false;
		if (xo.playerWon == true)
			m.isMenuStillGoing = false;
		if (m.isMenuStillGoing == true)
		{
			return 0;
		}
		cout << endl;
		cout << "\t[1] Play Again\t[2] Quit\n";
		cin >> userInput;
		if (userInput == 2)
		{
			cout << endl;
			cout << "Thanks for playing -- Come again soon!\n";
			isGameStillGoing = false;
		}
		else
		{
			xo.gameNotOver = true;
		}
	} while (isGameStillGoing);

	return 0;
}