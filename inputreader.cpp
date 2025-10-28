#include <iostream>
#include <stdio.h>
#include <string>

class InputReader {
    std::string m_input;
    public:
        InputReader();
        std::string getInput() {
            return m_input;
        };
        void processInput() {};
};