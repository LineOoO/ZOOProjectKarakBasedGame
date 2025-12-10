#include <iostream>
#include "Map.h"
#include "Game.h"

int main() {

    Map* map = new Map(); // automatically creates one card at 0;0
    Renderer* renderer = new Renderer();
    InputReader* inputReader = new InputReader();

    Game* game = new Game(map, renderer, inputReader);
    game->mainLoop();

    std::cout << "Exiting game. Cleaning up resources..." << std::endl;

    
    delete map;
    delete renderer;
    delete inputReader;
    delete game;
    
    return 0;
}