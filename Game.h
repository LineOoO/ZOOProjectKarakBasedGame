#pragma once;
#include "Map.h";
#include "Renderer.h";
#include "InputReader.h";



class Game {
    Map* m_map;
    Renderer* m_renderer;
    InputReader* m_inputReader;
    

    public:
    Game(Map* map, Renderer* renderer, InputReader* inputReader);
    ~Game();

    void mainLoop();
};