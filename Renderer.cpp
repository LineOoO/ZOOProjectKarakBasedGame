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