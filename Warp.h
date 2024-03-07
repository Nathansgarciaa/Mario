#ifndef WARP_H
#define WARP_H

#include "Item.h"
#include "Mario.h"
#include "World.h" // This should contain the declaration of World and its levelCount

class Warp : public Item {
public:
    Warp();
    Warp(int posX, int posY);
<<<<<<< HEAD
    virtual void Interact(Mario& mario); // Added World& parameter
=======
    virtual void Interact(Mario& mario) override; // Added World& parameter
>>>>>>> e14f69903a5aa3c42175d43e1cce24bc5312a7ff
};

#endif
