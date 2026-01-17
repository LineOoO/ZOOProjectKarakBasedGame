#include "Game.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <ctime>

Game::Game(Map* map, Renderer* renderer, InputReader* inputReader, Hero* hero) {
    std::srand(std::time(nullptr));
    m_map = map;
    m_renderer = renderer;
    m_inputReader = inputReader;
    m_hero = hero;


}

Game::~Game() {

}

void Game::typeWriter(const std::string& text, int delayMs = 30, bool instant = false) {
    if (instant) {
        std::cout << text;
        return;
    }

    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    }
}

bool Game::tryMoveHero(int dx, int dy, int exitIndex, const std::string& direction) {
    Card* currentCard = m_map->getCard(m_hero->getX(), m_hero->getY());
    std::array<bool, 4> cardExits = currentCard->getExits();
    
    if (!cardExits[exitIndex]) {
        typeWriter("There is no exit at the " + direction + " of the card!\nTry again.\n", 30, false);
        return false;
    }
    
    int newX = m_hero->getX() + dx;
    int newY = m_hero->getY() + dy;
    
    if (!m_map->checkIfCardExists(newX, newY)) {
        typeWriter("Creating new Card at (" + std::to_string(newX) + ";" + std::to_string(newY) + ")\n", 30, false);
        m_map->createCard(newX, newY);
    }
    
    m_hero->move(newX, newY);
    return true;
}

void Game::processHeroMovement() {
    typeWriter("Move your hero! Use W, A, S, D keys to move. Or type 'q' to quit the game.\n");
    typeWriter("Your move: ");
    InputCommand input = m_inputReader->readInput();
    switch (input) {
        case InputCommand::UP:
            if (!tryMoveHero(0, 1, 1, "top")) { processHeroMovement(); return; }
            break;
        case InputCommand::DOWN:
            if (!tryMoveHero(0, -1, 3, "bottom")) { processHeroMovement(); return; }
            break;
        case InputCommand::RIGHT:
            if (!tryMoveHero(1, 0, 2, "right side")) { processHeroMovement(); return; }
            break;
        case InputCommand::LEFT:
            if (!tryMoveHero(-1, 0, 0, "left side")) { processHeroMovement(); return; }
            break;
        case InputCommand::QUIT:
            typeWriter("Game has been quit.\n");
            break;
        case InputCommand::None:
            typeWriter("Invalid input! Try again.\n");
            processHeroMovement();
            return;
    }
}

void Game::heroCombat(Enemy* enemy) {
    typeWriter("--- Combat encounter ---\n");
    std::string enemyInfo = "Encountered enemy: " + enemy->getName() + " (Health: " + std::to_string(enemy->getHealth()) + ")\n";
    typeWriter(enemyInfo);
    
    while (enemy->isAlive() && m_hero->isAlive())
    {
        enemy->takeDamage(m_hero->getAttack());
        m_hero->takeDamage(enemy->getAttack());
        if (!enemy->isAlive()) {
            std::string defeatedMsg = "Enemy " + enemy->getName() + " defeated!\n";
            typeWriter(defeatedMsg); 
            m_hero->addXP(20); // Award XP for defeating enemy
            typeWriter("Hero gained 20 XP!\n");
            break;
        }
        if (!m_hero->isAlive()) {
            std::string defeatedMsg = "Hero has been defeated by " + enemy->getName() + "!\n";
            typeWriter(defeatedMsg);
            break;
        }
        std::string statusMsg = "Hero Health: " + std::to_string(m_hero->getHealth()) + " | Enemy Health: " + std::to_string(enemy->getHealth()) + "\n";
        typeWriter(statusMsg);
    }
    typeWriter("------------------------\n");
    
}

void Game::heroDetails() {
        
        typeWriter("--- Hero Stats ---\n");
        std::string coords = "Hero is at (" + std::to_string(m_hero->getX()) + ";" + std::to_string(m_hero->getY()) + ")\n";
        typeWriter(coords);

        std::string health = "Health: " + std::to_string(m_hero->getHealth()) + "/" + std::to_string(m_hero->getMaxHealth()) + "\n";
        typeWriter(health);
        
        std::string attack = "Attack: " + std::to_string(m_hero->getAttack()) + "\n";
        typeWriter(attack);

        std::string defense = "Defense: " + std::to_string(m_hero->getDefense()) + "\n";
        typeWriter(defense);

        std::string level = "Level: " + std::to_string(m_hero->getLevel()) + "\n";
        typeWriter(level);

        std::string xp = "Current xp: " + std::to_string(m_hero->getXP()) + "\n";
        typeWriter(xp);
        typeWriter("------------------\n");
}

void Game::handleCardSetup(Card* card) {
    if (card->isVisited()) {
        return;
    }
    card->setIsVisited(true);
    bool cardHasEnemy = std::rand() % 3; // ~33% chance to have enemy
    bool cardHasItem = std::rand() % 4; // 25% chance to have item

    if (cardHasEnemy) {
        Enemy* enemy = EnemyFactory::createRandom();
        card->setEnemy(enemy);
        
    }

    if (cardHasItem) {
        Item* item = ItemFactory::createRandom();
        card->setItem(item);
    }
}


void Game::mainLoop() {
    bool hasWon = false;
    bool hadQuit = false;
    typeWriter(m_renderer->renderIntroduction());
    m_hero->setCoords(0, 0); // Start hero at (0,0)

    while(m_hero->isAlive() && !hadQuit) {
        
        
        Card* card = m_map->getCard(m_hero->getX(), m_hero->getY());

        handleCardSetup(card);

        heroDetails();
        
        m_renderer->renderRoom(card, card->hasEnemy(), card->hasItem());

        if (!card->isCleared() && card->hasEnemy()) {
            heroCombat(card->getEnemy());

            card->setIsCleared(true);
        }

        if (!m_hero->isAlive()) {
            break;
        }
        
       
        typeWriter("To quit the game type 'q' and to continue playing type 'c': ");
        InputCommand input = m_inputReader->readInput();
        if (input == InputCommand::QUIT) {
            hadQuit = true;
            typeWriter("Game has been quit.\n");
            break;
        }

        typeWriter("Continuing the game...\n");
        

        processHeroMovement();
        
        if (m_hero->getLevel() >= 5) {
            hasWon = true;
            
            break;
        }
        
    }

    typeWriter(m_renderer->renderEnd(hasWon)); // Hero has died, game over
    typeWriter("Exiting game. Cleaning up resources...");

}