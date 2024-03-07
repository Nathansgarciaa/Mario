#ifndef COIN_H
#define COIN_H

#include "Item.h"
 

class Coin : public Item {
public:
    Coin();
    Coin(int posX, int posY);
    char getValue(){return 'c';};
    virtual void Interact(Mario& mario); // Override Item's pure virtual function
};

#endif