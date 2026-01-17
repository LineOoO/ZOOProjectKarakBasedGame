#include "ItemFactory.h"
#include <cstdlib>

Item* ItemFactory::createRandom() {
    int type = std::rand() % 5;
    return new Item(static_cast<ItemType>(type));
}

Item* ItemFactory::create(ItemType type) {
    return new Item(type);
}
