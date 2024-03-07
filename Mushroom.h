#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "Item.h"
#include "Mario.h" // We assume that Mario.h has the declaration for the Mario class

class Mushroom : public Item {
public:
    Mushroom();
    Mushroom(int posX, int posY);
<<<<<<< HEAD
    virtual void Interact(Mario& mario);
=======
    virtual void Interact(Mario& mario) override;
>>>>>>> e14f69903a5aa3c42175d43e1cce24bc5312a7ff
};

#endif // MUSHROOM_H
