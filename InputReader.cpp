#include "InputReader.h"
#include <iostream>

InputCommand InputReader::readInput() {
    char input;
    std::cin >> input;
    
    switch (input) {
        case 'u': return InputCommand::Up;
        case 'd': return InputCommand::Down;
        case 'r': return InputCommand::Right;
        case 'l': return InputCommand::Left;
        default: return InputCommand::None;
    }
}