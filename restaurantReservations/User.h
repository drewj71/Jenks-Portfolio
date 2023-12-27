#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class User {
private:
	std::string username = "";
	std::string password = "";
	bool loginSuccess = false;

public:
	void writeUserToFile(const User& user) {
		std::ofstream file("users.txt", std::ios::app);
		if (file.is_open()) {
			file << user.username << ' ' << user.password << '\n';
			file.close();
		}
		else {
			std::cerr << "Unable to open file for writing.\n";
		}
	};

	bool doesUserExist(const std::string& username) {
		std::ifstream file("users.txt");
		std::string line;
		while (std::getline(file, line)) {
			if (line.find(username) != std::string::npos) return true;	// User has been found
		}
		return false;	// User not found
	};

	void registerUser() {
		User newUser;
		std::cout << "Create a username: ";
		std::cin >> newUser.username;

		if (doesUserExist(newUser.username)) {
			std::cout << "Username already exists. Try again.\n";
			return;
		}
		std::cout << "Create a password: ";
		std::cin >> newUser.password;

		writeUserToFile(newUser);
		std::cout << "Registration successful!\n";
	};

	bool loginUser(const std::string& username, const std::string& password) {
		std::ifstream file("users.txt");
		std::string line;
		while (std::getline(file, line)) {
			std::istringstream iss(line);
			std::string storedUsername, storedPassword;
			iss >> storedUsername >> storedPassword;

			if (storedUsername == username && storedPassword == password) {
				loginSuccess = true;
				return true;	// Successful login
			}
		}
		loginSuccess = false;
		return false;	// Login failed
	};

	bool getLoginSuccess() const {
		return loginSuccess;
	}

	void login() {
		std::string username, password;
		std::cout << "Enter your username: ";
		std::cin >> username;
		std::cout << "Enter your password: ";
		std::cin >> password;

		if (loginUser(username, password)) {
			std::cout << "Login successful!\n";
			loginSuccess = true;
		}
		else std::cout << "Login failed. Invalid username or password.\n";
	}
};