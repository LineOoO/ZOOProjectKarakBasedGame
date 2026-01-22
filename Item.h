#pragma once
#include <iostream>
#include <string>

enum ItemType {
    HEAL_POTION,
    MANA_POTION,
    STRENGTH_BOOST,
    TREASURE,
    KEY
};

class Item {
    ItemType m_type;
    std::string m_name;
    int m_value; 
    bool m_isUsed;

public:
    Item(ItemType type);
    Item(ItemType type, int value);
    
    void use();
    ItemType getType();
    std::string getName();
    int getValue();
    bool isUsed();
    char getSymbol();
};
