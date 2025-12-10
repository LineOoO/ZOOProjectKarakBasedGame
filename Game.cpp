#include "Game.h";

Game::Game(Map* map, Renderer* renderer, InputReader* inputReader) {
    m_map = map;
    m_renderer = renderer;
    m_inputReader = inputReader;
}

Game::~Game() {
    delete m_map;
    delete m_renderer;
    delete m_inputReader;
}

void Game::mainLoop() {
    bool isAlive = true;

    m_renderer->renderIntroduction();

    while(isAlive) {
        // Game loop logic would go here
        //m_renderer->renderRoom();
        //m_inputReader->readInput();
        
        
        
    }

}