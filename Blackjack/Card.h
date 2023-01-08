#pragma once
#include <iostream>

enum class Value {
	ACE = 1,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING
};

enum class Suit {
	HEARTS = 0,
	DIAMONDS,
	SPADES,
	CLUBS
};

class Card
{
public:
	Value values;
	Suit suits;
	int value;

	void PrintSuit() {
		if (suits == Suit::HEARTS) {
			std::cout << "Hearts";
		}
		else if (suits == Suit::DIAMONDS) {
			std::cout << "Diamonds";
		}
		else if (suits == Suit::SPADES) {
			std::cout << "Spades";
		}
		else if (suits == Suit::CLUBS) {
			std::cout << "Clubs";
		}
	}

	void PrintValue() {
		if (values == Value::JACK) {
			std::cout << "Jack";
		}
		else if (values == Value::QUEEN) {
			std::cout << "Queen";
		}
		else if (values == Value::KING) {
			std::cout << "King";
		}
		else {
			std::cout << value;
		}
	}

	void PrintCard() {
		PrintValue();
		std::cout << " of ";
		PrintSuit();
		std::cout << std::endl;
	}
};