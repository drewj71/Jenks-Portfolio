#include <iostream>
#include <string>
#include "User.h"

int main() {
	User u;
	std::string userInput = "";
	bool invalidOption = true;
	std::cout << "Welcome to the Application!\nChoose an option:\n\n";
	
	do {
		std::cout << "1) Register\n2) Login\n3) Exit\n";
		std::cin >> userInput;
		if (userInput == "1") u.registerUser();
		else if (userInput == "2") u.login();
		else if (userInput == "3") invalidOption = false;
		else {
			std::cout << "Invalid option.\n\nWould you like to try again? (y/n)\n";
			std::cin >> userInput;
			if (userInput != "y") invalidOption = false;
		}
	} while (invalidOption == true);

	return 0;
}