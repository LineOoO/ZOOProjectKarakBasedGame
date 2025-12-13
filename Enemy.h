#pragma once
#include <iostream>
#include <string>

enum EnemyType {
    GOBLIN,
    ORC,
    SKELETON,
    DRAGON
};

class Enemy {
    int m_maxHealth;
    int m_health;
    int m_attack;
    EnemyType m_type;
    std::string m_name;
    bool m_isAlive;
 public:
    Enemy(EnemyType type);
    Enemy(int health, int attack, EnemyType type, const std::string& name);
    
    void takeDamage(int amount);
    bool isAlive() const;
    int getHealth() const;
    int getMaxHealth() const;
    int getAttack() const;
    EnemyType getType() const;
    std::string getName() const;
    char getSymbol() const; // Symbol for rendering on the map
};