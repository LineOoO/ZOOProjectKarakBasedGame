#pragma once
#include "Map.h"
#include "Renderer.h"
#include "InputReader.h"
#include "Card.h"
#include "Hero.h"
#include "Enemy.h"
#include "Item.h"
#include "ItemFactory.h"
#include "EnemyFactory.h"



class Game {
    Map* m_map;
    Renderer* m_renderer;
    InputReader* m_inputReader;
    Hero* m_hero;
    
    void processHeroMovement();
    void heroCombat(Enemy* enemy);
    void heroDetails();
    void handleCardSetup(Card* card);
    void typeWriter(const std::string& text, int delayMs, bool instant);
    bool tryMoveHero(int dx, int dy, int exitIndex, const std::string& direction);
    void openInventory();

    public:
    Game(Map* map, Renderer* renderer, InputReader* inputReader, Hero* hero);
    ~Game();

    void mainLoop();
};