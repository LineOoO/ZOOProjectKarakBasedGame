#pragma once
#include "Enemy.h"

/**
 * Tovární třída pro vytváření objektů Enemy.
 * Implementuje návrhový vzor Factory Method.
 */
class EnemyFactory {
public:
    // vytvoří náhodného nepřítele
    static Enemy* createRandom();
    // ytvoří konkrétní typ nepřítele
    static Enemy* create(EnemyType type);
};
