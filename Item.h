#ifndef ITEM_H
#define ITEM_H
#include "Mario.h"

class Item {
public:
    Item();
    Item(int posX, int posY);
    ~Item();
    int posX;
    int posY;
    bool interacted; // bool for if Mario interacted with or not


    // Making Interact a pure virtual function
    virtual void Interact(Mario& mario) = 0;
};

#endif
