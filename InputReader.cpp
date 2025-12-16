#include "InputReader.h"
#include <iostream>

InputCommand InputReader::readInput() {
    // ask for user input in the console
    char input;
    std::cin >> input;
    
    // process the char input and return as an enum value
    switch (input) {
        case 'u': return InputCommand::UP;
        case 'd': return InputCommand::DOWN;
        case 'r': return InputCommand::RIGHT;
        case 'l': return InputCommand::LEFT;
        case 'q': return InputCommand::QUIT;
        case 'c': return InputCommand::None; // continue game
        default: return InputCommand::None;
    }
}