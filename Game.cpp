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
    delete this;
}

void Game::mainLoop() {

}