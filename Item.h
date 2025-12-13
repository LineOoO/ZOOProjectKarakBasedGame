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
    int m_value; // Value for healing, damage boost, or treasure worth
    bool m_isUsed;

public:
    Item(ItemType type);
    Item(ItemType type, int value);
    
    void use();
    ItemType getType() const;
    std::string getName() const;
    int getValue() const;
    bool isUsed() const;
    char getSymbol() const; // Symbol for rendering on the map
};
