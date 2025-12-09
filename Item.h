#include <iostream>

enum ItemType {
  heal
};

class Item {
    ItemType m_type;

    public:
    Item(ItemType type);
    void use();
};