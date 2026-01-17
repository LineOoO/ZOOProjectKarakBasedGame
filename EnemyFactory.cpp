#include "EnemyFactory.h"
#include <cstdlib>

Enemy* EnemyFactory::createRandom() {
    int type = std::rand() % 4;
    return new Enemy(static_cast<EnemyType>(type));
}

Enemy* EnemyFactory::create(EnemyType type) {
    return new Enemy(type);
}
