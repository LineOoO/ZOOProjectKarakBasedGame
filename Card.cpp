#include "Card.h"

Card::Card(int x, int y)
	:m_enemy(nullptr), m_item(nullptr), m_isCleared(false), m_isVisited(false)
{
	setCoords(x, y);
}

std::array<int, 2> Card::getCoords()
{
	return this->m_coords;
}

void Card::setCoords(int x, int y)
{
	this->m_coords.at(0) = x;
	this->m_coords.at(1) = y;
}

std::array<bool, 4> Card::getExits()
{
	return this->m_exits;
}

void Card::setExit(int exit, bool value)
{
	this->m_exits.at(exit) = value;
}

void Card::setEnemy(Enemy* enemy)
{
	this->m_enemy = enemy;
}

void Card::setItem(Item* item)
{
	this->m_item = item;
}

Item* Card::getItem()
{
	return this->m_item;
}

Enemy* Card::getEnemy()
{
	return this->m_enemy;
}

bool Card::hasEnemy() const
{
	if (this->m_enemy != nullptr)
	{
		return true;
	}
	else {
		return false;
	}
}

bool Card::hasItem() const
{
	if (this->m_item != nullptr)
	{
		return true;
	}
	else {
		return false;
	}
}

void Card::setIsCleared(bool set)
{
	this->m_isCleared = set;
}

void Card::setIsVisited(bool set)
{
	this->m_isVisited = set;
}

bool Card::isVisited()
{
	return this->m_isVisited;
}

bool Card::isCleared()
{
	return this->m_isCleared;
}

Card::~Card()
{
	if (this->m_enemy != nullptr)
	{
		delete this->m_enemy;
		this->m_enemy = nullptr;
	}
	if (this->m_item != nullptr) {
		delete this->m_item;
		this->m_item = nullptr;
	}
}
