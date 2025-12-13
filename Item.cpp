#include <stdio.h>

#include "Item.h"

Item::Item(ItemType type) : m_type(type), m_isUsed(false) {
    // Set default values based on item type
    switch(type) {
        case HEAL_POTION:
            m_name = "Health Potion";
            m_value = 30;
            break;
        case MANA_POTION:
            m_name = "Mana Potion";
            m_value = 20;
            break;
        case STRENGTH_BOOST:
            m_name = "Strength Boost";
            m_value = 5;
            break;
        case TREASURE:
            m_name = "Treasure";
            m_value = 100;
            break;
        case KEY:
            m_name = "Key";
            m_value = 1;
            break;
    }
}

Item::Item(ItemType type, int value) 
    : m_type(type), m_value(value), m_isUsed(false) {
    switch(type) {
        case HEAL_POTION:
            m_name = "Health Potion";
            break;
        case MANA_POTION:
            m_name = "Mana Potion";
            break;
        case STRENGTH_BOOST:
            m_name = "Strength Boost";
            break;
        case TREASURE:
            m_name = "Treasure";
            break;
        case KEY:
            m_name = "Key";
            break;
    }
}

void Item::use() {
    m_isUsed = true;
}

ItemType Item::getType() const {
    return m_type;
}

std::string Item::getName() const {
    return m_name;
}

int Item::getValue() const {
    return m_value;
}

bool Item::isUsed() const {
    return m_isUsed;
}

char Item::getSymbol() const {
    // Return symbol for rendering based on item type
    switch(m_type) {
        case HEAL_POTION: return 'H';
        case MANA_POTION: return 'M';
        case STRENGTH_BOOST: return '+';
        case TREASURE: return '$';
        case KEY: return 'K';
        default: return 'I';
    }
}