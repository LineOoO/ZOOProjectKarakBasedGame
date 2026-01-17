#pragma once
#include "Map.h"
#include "Renderer.h"
#include "InputReader.h"
#include "Card.h"
#include "Hero.h"
#include "Enemy.h"
#include "Item.h"



class Game {
    Map* m_map;
    Renderer* m_renderer;
    InputReader* m_inputReader;
    Hero* m_hero;
    
    void processHeroMovement();
    void heroCombat(Enemy* enemy);
    void heroDetails();
    Item* generateItem();
    Enemy* generateEnemy();
    void handleCardSetup(Card* card);
    void typeWriter(const std::string& text, int delayMs, bool instant);
    bool tryMoveHero(int dx, int dy, int exitIndex, const std::string& direction);

    public:
    Game(Map* map, Renderer* renderer, InputReader* inputReader, Hero* hero);
    ~Game();

    void mainLoop();
};