#include "Hero.h"

Hero::Hero() : m_maxHealth(100), m_health(100), m_attack(10), m_defense(5), m_xp(0), m_level(1)
{
	m_coords[0] = 0;
	m_coords[1] = 0;
}

Hero::Hero(int x, int y) : m_maxHealth(100), m_health(100), m_attack(10), m_defense(5), m_xp(0), m_level(1)
{
	m_coords[0] = x;
	m_coords[1] = y;
}

Hero::~Hero()
{
	for (Item* item : m_inventory) {
		delete item;
	}
	m_inventory.clear();
}

std::array<int, 2> Hero::getCoords() const
{
	return m_coords;
}

int Hero::getX() const
{
	return m_coords[0];
}

int Hero::getY() const
{
	return m_coords[1];
}

void Hero::setCoords(int x, int y)
{
	m_coords[0] = x;
	m_coords[1] = y;
}

void Hero::move(int x, int y)
{
	setCoords(x, y);
}

// Combat stats
int Hero::getHealth() const
{
	return m_health;
}

int Hero::getMaxHealth() const
{
	return m_maxHealth;
}

int Hero::getAttack() const
{
	return m_attack;
}

int Hero::getDefense() const
{
	return m_defense;
}

void Hero::takeDamage(int amount)
{
}

void Hero::heal(int amount)
{
	m_health += amount;
	if (m_health > m_maxHealth) {
		m_health = m_maxHealth;
	}
}

bool Hero::isAlive() const
{
	return m_health > 0;
}


int Hero::getXP() const
{
	return m_xp;
}

int Hero::getLevel() const
{
	return m_level;
}

void Hero::addXP(int amount)
{
}

void Hero::levelUp()
{
}

void Hero::addItem(Item* item)
{
	if (item != nullptr) {
		m_inventory.push_back(item);
	}
}

void Hero::removeItem(Item* item)
{
    
}

void Hero::useItem(int index)
{
}

std::vector<Item*>& Hero::getInventory()
{
	return m_inventory;
}

Item* Hero::getItem(int index)
{
	if (index >= 0 && index < static_cast<int>(m_inventory.size())) {
		return m_inventory[index];
	}
	return nullptr;
}

int Hero::getInventorySize() const
{
	return static_cast<int>(m_inventory.size());
}
