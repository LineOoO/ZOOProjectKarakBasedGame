#include "InputReader.h"
#include <iostream>

InputCommand InputReader::readInput() {
    // ask for user input in the console
    char input;
    std::cin >> input;
    
    // process the char input and return as an enum value
    switch (input) {
        case 'w': return InputCommand::UP;
        case 's': return InputCommand::DOWN;
        case 'd': return InputCommand::RIGHT;
        case 'a': return InputCommand::LEFT;
        case 'q': return InputCommand::QUIT;
        case 'c': return InputCommand::None; // continue game
        default: return InputCommand::None;
    }
}