#include <iostream>
#include <array>
#include "Card.h"
#include "Renderer.h"

// game introduction message :)
std::string Renderer::renderIntroduction() {
    return "Welcome to ZOO\nYour task as a hero is to navigate a maze, collect items and kill as many enemies as possible.\nBe quick!\n\n";
}

// render each room after per Hero move
void Renderer::renderRoom(Card* card, bool hasEnemy, bool hasItem) {
    std::array<bool, 4> exits = card->getExits();
    int width = 9;
    int height = 9;

    // 9x9 room
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (x == 4 && y == 4) {
                // render hero position
                std::cout << "H ";
            } else if (hasEnemy && x == 6 && y == 4) {
                // render enemy position
                std::cout << "E ";
            } else if (hasItem && x == 4 && y == 2) {
                // render item position
                std::cout << "I ";
            } else {
                // render room border (exclude wall for each exit)
                bool isWall = (y == 0 || y == 8 || x == 0 || x == 8);
                bool isExit = false;

                if (y == 0 && x == 4 && exits[1]) isExit = true;
                if (y == 8 && x == 4 && exits[3]) isExit = true;
                if (y == 4 && x == 0 && exits[0]) isExit = true;
                if (y == 4 && x == 8 && exits[2]) isExit = true;

                if (isWall && !isExit) {
                    std::cout << "# ";
                } else {
                    std::cout << "  ";
                }
            }
        }
        std::cout << "\n";
    }
}

// render game over message
std::string Renderer::renderEnd(bool hasWon) {
    if (hasWon) {
        return "You won, congrats! Collect your reward (6 ECTS have just arrived to your student account)!\n";
    } else {
        return  "Game Over! Try your luck again, learning is fun.\n";
    }
}

// vykresleni minimapy se vsemi prozkoumanymy mistnostmi
void Renderer::renderMinimap(const std::vector<Card*>& cards, int heroX, int heroY) {
    if (cards.empty()) {
        return;
    }

    // najdi ohraniceni vsech karet (min/max souradnice)
    int minX = heroX, maxX = heroX;
    int minY = heroY, maxY = heroY;
    
    for (const auto& card : cards) {
        auto coords = card->getCoords();
        int x = coords[0];
        int y = coords[1];
        if (x < minX) minX = x;
        if (x > maxX) maxX = x;
        if (y < minY) minY = y;
        if (y > maxY) maxY = y;
    }

    // vypocet velikosti mrizky (kazda bunka je 3 znaky siroka, 1 znak vysoka)
    // potrebujeme extra misto pro spojnice mezi mistnostmi
    int gridWidth = (maxX - minX + 1) * 4 + 1;
    int gridHeight = (maxY - minY + 1) * 2 + 1;

    // vytvoreni prazdne mrizky vyplnene mezerami
    std::vector<std::string> grid(gridHeight, std::string(gridWidth, ' '));

    // umisteni kazde karty do mrizky
    for (const auto& card : cards) {
        auto coords = card->getCoords();
        int cardX = coords[0];
        int cardY = coords[1];
        auto exits = card->getExits();

        // prevod souradnic karty na pozici v mrizce
        // pozn.: Y je obracene (vyssi Y = nize na obrazovce)
        int gx = (cardX - minX) * 4 + 1;
        int gy = (maxY - cardY) * 2 + 1;

        // vykresli mistnost: [ ] nebo [@] pro hrdinu
        if (cardX == heroX && cardY == heroY) {
            grid[gy][gx] = '[';
            grid[gy][gx + 1] = '@';
            grid[gy][gx + 2] = ']';
        } else {
            grid[gy][gx] = '[';
            grid[gy][gx + 1] = ' ';
            grid[gy][gx + 2] = ']';
        }

        // vykresli spojnice podle vychodu
        // LEVY vychod (index 0) - spojnice doleva
        if (exits[0]) {
            grid[gy][gx - 1] = '-';
        }
        // PRAVY vychod (index 2) - spojnice doprava
        if (exits[2]) {
            grid[gy][gx + 3] = '-';
        }
        // HORNI vychod (index 1) - spojnice nahoru (nizsi gy)
        if (exits[1] && gy > 0) {
            grid[gy - 1][gx + 1] = '|';
        }
        // DOLNI vychod (index 3) - spojnice dolu (vyssi gy)
        if (exits[3] && gy + 1 < gridHeight) {
            grid[gy + 1][gx + 1] = '|';
        }
    }

    // vytiskni minimapu
    std::cout << "--- Minimapa ---\n";
    for (const auto& row : grid) {
        std::cout << row << "\n";
    }
    std::cout << "----------------\n";
}