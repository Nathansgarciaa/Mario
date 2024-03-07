#ifndef COIN_H
#define COIN_H

#include "Item.h"
 

class Coin : public Item {
public:
    Coin();
    Coin(int posX, int posY);
    virtual void Interact(Mario& mario) override; // Override Item's pure virtual function
};

#endif
