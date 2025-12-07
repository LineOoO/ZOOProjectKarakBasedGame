#pragma once
#include "Card.h"
#include <random>
class Map
{
	std::vector<Card*> m_map; // 1D vector for the world map
public:
	Map();
	void createCard(int x, int y); // Will try to create a new card in our map at x y position, this function should be called only if the player is about to enter this position x y
	bool checkIfCardExists(int x, int y); // Will return true if Map already has a card with these coords, otherwise false
	Card* getCard(int x, int y); // will return Card at these coords, if it doesnt exist, it returns nullptr!!
	bool randBool();
	~Map();

};

