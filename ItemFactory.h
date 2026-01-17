#pragma once
#include "Item.h"

/**
 * Tovární třída pro vytváření objektů Item.
 * Implementuje návrhový vzor Factory Method.
 */
class ItemFactory {
public:
    // vytvoří náhodný item
    static Item* createRandom();
    // vytvoří konkrétní typ itemu
    static Item* create(ItemType type);
};
