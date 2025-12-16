#pragma once

enum class InputCommand {
    None,
    QUIT,
    LEFT,
    UP,
    RIGHT,
    DOWN
};

class InputReader {
    public:
    InputCommand readInput();
};