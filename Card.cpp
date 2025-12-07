#include "Card.h"

Card::Card(int x, int y)
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
