#include "InputReader.h"
#include <iostream>

InputCommand InputReader::readInput() {
    char input;
    std::cin >> input;
    
    switch (input) {
        case 'u': return InputCommand::UP;
        case 'd': return InputCommand::DOWN;
        case 'r': return InputCommand::RIGHT;
        case 'l': return InputCommand::LEFT;
        default: return InputCommand::None;
    }
}