#pragma once

enum class InputCommand {
    None,
    QUIT,
    LEFT,
    UP,
    RIGHT,
    DOWN,
    INVENTORY,
    DETAILS
};

class InputReader {
    public:
    InputCommand readInput();
};