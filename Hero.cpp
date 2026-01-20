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
	// Calculate actual damage after defense
	int actualDamage = amount - m_defense;
	if (actualDamage < 0) {
		actualDamage = 0;
	}
	
	m_health -= actualDamage;
	if (m_health < 0) {
		m_health = 0;
	}
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
	m_xp += amount;
	
	int xpNeeded = m_level * 100;
	while (m_xp >= xpNeeded) {
		m_xp -= xpNeeded;
		levelUp();
		xpNeeded = m_level * 100;
	}
}

void Hero::levelUp()
{
	m_level++;
	
	m_maxHealth += 20;
	m_health = m_maxHealth; 
	m_attack += 5;
	m_defense += 2;
}

void Hero::addItem(Item* item)
{
	if (item != nullptr) {
		m_inventory.push_back(item);
	}
}

void Hero::removeItem(Item* item)
{
	if (item == nullptr) {
		return;
	}
	
	for (auto it = m_inventory.begin(); it != m_inventory.end(); ++it) {
		if (*it == item) {
			delete *it;
			m_inventory.erase(it);
			break;
		}
	}
}

void Hero::useItem(int index)
{
	if (index < 0 || index >= static_cast<int>(m_inventory.size())) {
		return;
	}
	
	Item* item = m_inventory[index];
	if (item == nullptr) {
		return;
	}
	
	switch (item->getType()) {
		case HEAL_POTION:
			heal(item->getValue());
			break;
		case STRENGTH_BOOST:
			m_attack += item->getValue();
			break;
		case MANA_POTION:
			break;
		case TREASURE:
			break;
		case KEY:
			break;
	}
	
	item->use();
	m_inventory.erase(m_inventory.begin() + index);
	delete item;
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
