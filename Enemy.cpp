#include <iostream>

#include "Enemy.h"

Enemy::Enemy(EnemyType type) : m_type(type), m_isAlive(true) {
    switch(type) {
        case GOBLIN:
            m_maxHealth = 30;
            m_attack = 5;
            m_name = "Goblin";
            break;
        case ORC:
            m_maxHealth = 50;
            m_attack = 10;
            m_name = "Orc";
            break;
        case SKELETON:
            m_maxHealth = 40;
            m_attack = 8;
            m_name = "Skeleton";
            break;
        case DRAGON:
            m_maxHealth = 100;
            m_attack = 20;
            m_name = "Dragon";
            break;
    }
    m_health = m_maxHealth;
}

Enemy::Enemy(int health, int attack, EnemyType type, std::string& name) 
    : m_maxHealth(health), m_health(health), m_attack(attack), m_type(type), m_name(name), m_isAlive(true) {
}

void Enemy::takeDamage(int amount) {
m_health -= amount;
    if (m_health <= 0) {
        m_health = 0;
        m_isAlive = false;
    }
}

bool Enemy::isAlive() {
    return m_isAlive;
}

int Enemy::getHealth() {
    return m_health;
}

int Enemy::getMaxHealth() {
    return m_maxHealth;
}

int Enemy::getAttack() {
    return m_attack;
}

EnemyType Enemy::getType() {
    return m_type;
}

std::string Enemy::getName() {
    return m_name;
}

char Enemy::getSymbol() {
    // Return symbol for rendering based on enemy type
    switch(m_type) {
        case GOBLIN: return 'G';
        case ORC: return 'O';
        case SKELETON: return 'S';
        case DRAGON: return 'D';
        default: return 'E';
    }
}