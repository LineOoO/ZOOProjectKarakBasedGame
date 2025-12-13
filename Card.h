#pragma once
#include <vector>
#include <array>
#include <iostream>
#include <string>

#include "Log.h"
#include "Enemy.h"
#include "Item.h"

class Card
{
	unsigned int m_width; // Max width of the card for rendering purposes
	unsigned int m_height; // Max height of the card for rendering purposes
	std::vector<std::vector<char>> m_room; // Data how to room looks graphically, this will used for rendering the rooms look
	std::array<bool, 4> m_exits{}; // The Card has 4 possible exits (entrances to the next cards), this tracks if they are open, the order is LEFT, UP, RIGHT, DOWN
	std::array<int, 2> m_coords{}; // Coordinates for where the card is positioned in the world (Map), used for checking if this position is occupied or if a new exit or entrance should be generated
	
	// Card content (enemies and items in this room)
	//std::vector<Enemy*> m_enemies;
	//std::vector<Item*> m_items;
	Enemy* m_enemy;
	Item* m_item;
	bool m_isCleared; // True if all enemies are defeated
	bool m_isVisited; // True if player has been here before



public:
	Card(int x, int y);
	//void generateArt();
	std::array<int, 2> getCoords();
	void setCoords(int x, int y);
	std::array<bool, 4> getExits(); // Returns exits, the order is LEFT, UP, RIGHT, DOWN
	void setExit(int exit, bool value); // Set one of the exits status, the order is LEFT, UP, RIGHT, DOWN

	void setEnemy(Enemy* enemy);
	void setItem(Item* item);
	bool hasEnemy() const;
	bool hasItem() const;

	~Card();

};

