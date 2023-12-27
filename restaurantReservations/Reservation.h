#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class Reservation {
private:
	std::string name = "";
	std::string phoneNumber = "";
	std::string reservationTime = "";
	std::vector<std::string> availableTimes;
public:
	Reservation() {
		initializeAvailableTimes();
	}

	bool isReservationAvailable(const std::string& chosenTime) {
		int reservationsCount = countReservationsForTime(chosenTime);
		return reservationsCount < 5;
	}
	std::vector<std::string> getAvailableReservationTimes() {
		std::vector<int> reservationsCount;
		for (const std::string& time : availableTimes) {
			reservationsCount.push_back(countReservationsForTime(time));
		}
		std::vector<std::string> filteredTimes;
		for (size_t i = 0; i < availableTimes.size(); ++i) {
			if (reservationsCount[i] < 5) filteredTimes.push_back(availableTimes[i]);
		}
		return filteredTimes;
	}

	void displayAvailableReservationTimes() {
		std::vector<std::string> availableTimes = getAvailableReservationTimes();
		std::cout << "Available Reservation Times for Tonight:\n";
		for (const std::string& time : availableTimes) std::cout << time << '\n';
		std::cout << '\n';
	}

	void writeReservationToFile(const Reservation& res) {
		if (isReservationAvailable(res.getReservationTime())) {
			std::ofstream file("reservations.txt", std::ios::app);
			if (file.is_open()) {
				file << res.getName() << ' ' << res.getPhoneNumber() << ' ' << res.getReservationTime() << '\n';
				file.close();
				std::cout << "Reservation successful!\n";
				updateAvailableTimes(res.getReservationTime());
			}
			else {
				std::cerr << "Unable to open file for writing.\n";
			}
		}
		else std::cout << "Reservations are full for the chosen time. Please choose another time.\n";
	}

	int countReservationsForTime(const std::string& chosenTime) {
		std::ifstream file("reservations.txt");
		std::string line;
		int count = 0;

		while (std::getline(file, line)) {
			std::istringstream iss(line);
			std::string name, phone, time;
			iss >> name >> phone >> time;

			if (time == chosenTime) count++;
		}
		return count;
	}

	void initializeAvailableTimes() {
		for (int hour = 1; hour <= 8; ++hour) {
			availableTimes.push_back(std::to_string(hour) + ":00pm");
			availableTimes.push_back(std::to_string(hour) + ":30pm");
		}
	}

	void updateAvailableTimes(const std::string& chosenTime) {
		auto it = std::find(availableTimes.begin(), availableTimes.end(), chosenTime);
		if (it != availableTimes.end()) availableTimes.erase(it);
	}

	void setReservationDetails(const std::string& name, const std::string& phoneNumber, const std::string& reservationTime) {
		this->name = name;
		this->phoneNumber = phoneNumber;
		this->reservationTime = reservationTime;
	}
	
	std::string getName() const {
		return name;
	}
	
	void setName(const std::string& newName) {
		name = newName;
	}

	std::string getPhoneNumber() const {
		return phoneNumber;
	}

	void setPhoneNumber(const std::string& newPhoneNumber) {
		phoneNumber = newPhoneNumber;
	}

	std::string getReservationTime() const {
		return reservationTime;
	}

	void setReservationTime(const std::string& newReservationTime) {
		reservationTime = newReservationTime;
	}
};