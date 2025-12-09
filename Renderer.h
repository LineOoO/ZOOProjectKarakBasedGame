#pragma once
#include "Card.h"

class Renderer {
    public:
    void renderIntroduction();
    void renderRoom(Card* card, bool hasEnemy, bool hasItem);
    void renderEnd(bool hasWon);
};
