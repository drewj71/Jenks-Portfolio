#pragma once
#include <iostream>
#include <string>
#include "User.h"
#include "Reservation.h"

class Menu {
private:
	std::string userInput = "";
	User u;
	Reservation r;

public:
	void displayReservationMenu() {
		do {
			std::cout << "Reservation Menu:\n";
			std::cout << "1) View Available Reservation Times\n";
			std::cout << "2) Make a Reservation\n";
			std::cout << "3) Cancel a Reservation\n";
			std::cout << "4) Logout\n";
			std::cin >> userInput;

			if (userInput == "1") {
				r.displayAvailableReservationTimes();
			}
			else if (userInput == "2") {
				std::string name, phone, time;
				std::cout << "Enter your name: ";
				std::cin >> name;
				std::cout << "Enter your phone number: ";
				std::cin >> phone;
				std::cout << "Choose a reservation time: ";
				std::cin >> time;

				r.setReservationDetails(name, phone, time);
				r.writeReservationToFile(r);
			}
			else if (userInput == "3") {
				std::cout << "Cancel reservation functionality is not implemented yet.\n";
			}
			else if (userInput == "4") {
				std::cout << "Logout successful!\n";
				break;
			}
			else {
				std::cout << "Invalid option.\n\nWould you like to try again? (y/n)\n";
				std::cin >> userInput;
				if (userInput != "y") break;
			}
		} while (true);
	}

	void displayLoginMenu() {
		do {
			std::cout << "Welcome to Antonio's! Please sign-in to book a reservation.\n";
			std::cout << "1) Login\n2) Register\n3) Exit\n";
			std::cin >> userInput;
			if (userInput == "1") {
				u.login();
				if (u.getLoginSuccess()) {
					displayReservationMenu();
					break;
				}
			}
			else if (userInput == "2") {
				u.registerUser();
				displayReservationMenu();
				break;
			}
			else if (userInput == "3") break;
			else {
				std::cout << "Invalid option.\n\nWould you like to try again? (y/n)\n";
				std::cin >> userInput;
				if (userInput != "y") break;
			}
		} while (true);
	}
};