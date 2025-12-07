#pragma once
#include <vector>
#include <array>
#include <iostream>

#include "Log.h"

class Card
{
	unsigned int m_width; // Max width of the card for rendering purposes
	unsigned int m_height; // Max height of the card for rendering purposes
	std::vector<std::vector<char>> m_room; // Data how to room looks graphically, this will used for rendering the rooms look
	std::array<bool, 4> m_exits{}; // The Card has 4 possible exits (entrances to the next cards), this tracks if they are open, the order is LEFT, UP, RIGHT, DOWN
	std::array<int, 2> m_coords{}; // Coordinates for where the card is positioned in the world (Map), used for checking if this position is occupied or if a new exit or entrance should be generated
	// TODO: variable for card content (enemy, item etc)
public:
	Card(int x, int y);
	//void generateArt();
	std::array<int, 2> getCoords();
	void setCoords(int x, int y);
	std::array<bool, 4> getExits(); // Returns exits, the order is LEFT, UP, RIGHT, DOWN
	void setExit(int exit, bool value); // Set one of the exits status, the order is LEFT, UP, RIGHT, DOWN

};

