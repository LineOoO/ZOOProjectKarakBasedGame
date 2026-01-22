#pragma once
#include <array>
#include <vector>
#include <string>
#include "Item.h"

class Hero
{
	std::array<int, 2> m_coords{};
	int m_maxHealth;
	int m_health;
	int m_attack;
	int m_defense;
	int m_xp;
	int m_level;
	std::vector<Item*> m_inventory;

public:
	Hero();
	Hero(int x, int y);
	~Hero();
	
	std::array<int, 2> getCoords();
	int getX();
	int getY();
	void setCoords(int x, int y);
	void move(int x, int y);
	
	int getHealth();
	int getMaxHealth();
	int getAttack();
	int getDefense();
	void takeDamage(int amount);
	void heal(int amount);
	bool isAlive();
	
	int getXP();
	int getLevel();
	void addXP(int amount);
	void levelUp();
	
    
	void addItem(Item* item);
	void removeItem(Item* item);
	void useItem(int index);
	std::vector<Item*>& getInventory();
	Item* getItem(int index);
	int getInventorySize();
};
