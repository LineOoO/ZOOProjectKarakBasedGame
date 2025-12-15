#pragma once
#include "Card.h"

class Renderer {
    public:
    std::string renderIntroduction();
    void renderRoom(Card* card, bool hasEnemy, bool hasItem);
    std::string renderEnd(bool hasWon);
};
