#include <iostream>
#include "Map.h"
#include "Game.h"

int main() {

    Map* map = new Map(); // automatically creates one card at 0;0
    Renderer* renderer = new Renderer();
    InputReader* inputReader = new InputReader();
    Hero* hero = new Hero();

    Game* game = new Game(map, renderer, inputReader, hero);
    game->mainLoop();

    
    delete map;
    delete renderer;
    delete inputReader;
    delete game;
    delete hero;
    
    return 0;
}