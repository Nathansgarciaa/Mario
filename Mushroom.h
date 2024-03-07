#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "Item.h"
#include "Mario.h" // We assume that Mario.h has the declaration for the Mario class

class Mushroom : public Item {
public:
    Mushroom();
    Mushroom(int posX, int posY);
    virtual void Interact(Mario& mario) override;
};

#endif // MUSHROOM_H
