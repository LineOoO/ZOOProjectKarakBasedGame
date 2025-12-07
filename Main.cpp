#include <iostream>
#include "Map.h"

int main() {

    Map* map = new Map(); // automatically creates one card at 0;0
    
    delete map;
    
    return 0;
}