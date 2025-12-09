#pragma once

enum InputCommand {
    None,
    Up,
    Down,
    Left,
    Right
};

class InputReader {
    public:
    InputCommand readInput();
};