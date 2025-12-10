#pragma once

enum class InputCommand {
    None,
    LEFT,
    UP,
    RIGHT,
    DOWN
};

class InputReader {
    public:
    InputCommand readInput();
};