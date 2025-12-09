#include <iostream>

class Enemy {
    int m_health;
    int m_attack;

    public:
        Enemy(int health, int attack);
        void takeDamage(int amount);
};