#ifndef WARP_H
#define WARP_H

#include "Item.h"
#include "Mario.h"
#include "World.h" // This should contain the declaration of World and its levelCount

class Warp : public Item {
public:
    Warp();
    Warp(int posX, int posY);
    virtual void Interact(Mario& mario) override; // Added World& parameter
};

#endif
