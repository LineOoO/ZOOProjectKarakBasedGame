#include "Game.h"
#include <thread>
#include <chrono>
#include <iostream>

Game::Game(Map* map, Renderer* renderer, InputReader* inputReader, Hero* hero) {
    m_map = map;
    m_renderer = renderer;
    m_inputReader = inputReader;
    m_hero = hero;


}

Game::~Game() {

}



void Game::processHeroMovement() {
    Card* currentCard = m_map->getCard(m_hero->getX(), m_hero->getY());
    std::cout << "Move your hero! Use u, r, d, l keys to move UP, RIGHT, DOWN, LEFT respectively.\n";
    std::cout << "Your move: ";
    InputCommand input = m_inputReader->readInput();
    std::array<bool, 4> cardExits =  currentCard->getExits();
    switch (input) {
        case InputCommand::UP: {
            if (cardExits[1] == 0) {
                std::cout << "There is no exit at the top of the card!\nTry again.\n";
                processHeroMovement();
                return;
            }
            else {
                if(m_map->checkIfCardExists(m_hero->getX(), m_hero->getY() + 1)) {
                    std::cout << "Creating new Card at (" << m_hero->getX() + 1 << ";" << m_hero->getY() << ")\n";
                    m_hero->move(m_hero->getX(), m_hero->getY() + 1);

                }

                else {
                    m_map->createCard(m_hero->getX(), m_hero->getY() + 1);
                    m_hero->move(m_hero->getX(), m_hero->getY() + 1);
                }
                break;
            }

                
            
        };
        case InputCommand::DOWN: {
            if (cardExits[3] == 0) {
                std::cout << "There is no exit at the bottom of the card!\nTry again.\n";
                processHeroMovement();
                return;
            }
            else {
                if(m_map->checkIfCardExists(m_hero->getX(), m_hero->getY() - 1) && m_hero->getY() - 1 >= 0) {
                    std::cout << "Creating new Card at (" << m_hero->getX() - 1 << ";" << m_hero->getY() << ")\n";
                    m_hero->move(m_hero->getX(), m_hero->getY() - 1);

                }

                else {
                    m_map->createCard(m_hero->getX(), m_hero->getY() - 1);
                    m_hero->move(m_hero->getX(), m_hero->getY() - 1);
                }
                break;
            }

        };
        case InputCommand::RIGHT: {
            if (cardExits[2] == 0) {
                std::cout << "There is no exit at the right side of the card!!\nTry again.\n";
                processHeroMovement();
                return;
            }
            else {
                if(m_map->checkIfCardExists(m_hero->getX() + 1, m_hero->getY())) {
                    std::cout << "Creating new Card at (" << m_hero->getX() - 1 << ";" << m_hero->getY() << ")\n";
                    m_hero->move(m_hero->getX() + 1, m_hero->getY());

                }

                else {
                    m_map->createCard(m_hero->getX() + 1, m_hero->getY());
                    m_hero->move(m_hero->getX() + 1, m_hero->getY());
                }
                break;
            }

        } ;
        case InputCommand::LEFT: {
            if (cardExits[0] == 0) {
                std::cout << "There is no exit at the left side of the card!\nTry again.\n";
                processHeroMovement();
                return;
            }
            else {
                if(m_map->checkIfCardExists(m_hero->getX() - 1, m_hero->getY()) && m_hero->getX() - 1 >= 0) {
                    m_hero->move(m_hero->getX() - 1, m_hero->getY());

                }

                else {
                    std::cout << "Creating new Card at (" << m_hero->getX() - 1 << ";" << m_hero->getY() << ")\n";
                    m_map->createCard(m_hero->getX() - 1, m_hero->getY());
                    m_hero->move(m_hero->getX() - 1, m_hero->getY());
                }
                break;
            }

        } ;

        case InputCommand::None: {

        }
        
    }
}

void Game::heroCombat(Enemy* enemy) {
    std::cout << "--- Combat encounter ---\n";
    std::cout << "Encountered enemy: " << enemy->getName() << " (Health: " << enemy->getHealth() << ")\n";
    while (enemy->isAlive() || m_hero->isAlive())
    {
        enemy->takeDamage(m_hero->getAttack());
        m_hero->takeDamage(enemy->getAttack());
        if (!enemy->isAlive()) {
            std::cout << "Enemy " << enemy->getName() << " defeated!\n";
            m_hero->addXP(20); // Award XP for defeating enemy
            std::cout << "Hero gained 20 XP!\n";
            break;
        }
        std::cout << "Hero Health: " << m_hero->getHealth() << " | Enemy Health: " << enemy->getHealth() << "\n";
    }
    std::cout << "------------------------\n" << std::endl;
    
}

void Game::heroDetails() {
        
        std::cout << "--- Hero Stats ---\n";
        std::cout << "Hero is at (" << m_hero->getX() << ";" << m_hero->getY() << ")\n";
        std::cout << "Health: " << m_hero->getHealth() << "/" << m_hero->getMaxHealth() << "\n";
        std::cout << "Attack: " << m_hero->getAttack() << "\n";
        std::cout << "Defense: " << m_hero->getDefense() << "\n";
        std::cout << "Level: " << m_hero->getLevel() << "\n";
        std::cout << "Current xp: " << m_hero->getXP() << "\n";
        std::cout << "------------------\n" << std::endl;
}


void Game::mainLoop() {
    
    bool cardHasEnemy = false;
    bool cardHasItem = false;
    m_renderer->renderIntroduction();
    m_hero->setCoords(0, 0); // Start hero at (0,0)

    while(m_hero->isAlive()) {
        
        
        Card* card = m_map->getCard(m_hero->getX(), m_hero->getY());

        cardHasEnemy = std::rand() % 3; // ~33% chance to have enemy
        cardHasItem = std::rand() % 4; // 25% chance to have item

        if (cardHasEnemy) {
            Enemy* enemy = new Enemy(EnemyType::GOBLIN); // For simplicity, always a goblin
            card->setEnemy(enemy);
        }

        if (cardHasItem) {
            Item* item = new Item(ItemType::HEAL_POTION, 20); // For simplicity, always a heal potion
            card->setItem(item);
        }

        heroDetails();
        
        m_renderer->renderRoom(card, cardHasEnemy, cardHasItem);


        heroCombat(card->getEnemy());
        
        processHeroMovement();
        
        
        
    }

}