#pragma once
#include "Card.h"
#include <vector>

class Renderer {
    public:
    std::string renderIntroduction();
    void renderRoom(Card* card, bool hasEnemy, bool hasItem);
    void renderMinimap(const std::vector<Card*>& cards, int heroX, int heroY);
    std::string renderEnd(bool hasWon);
};
