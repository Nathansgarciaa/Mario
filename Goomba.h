#ifndef GOOMBA_H
#define GOOMBA_H

#include "Enemy.h"
#include "Mario.h" // Assuming the Mario class is defined elsewhere

class Goomba : public Enemy {
public:
    Goomba();
    Goomba(int posX, int posY);
    virtual void Interact(Mario& mario) override;
};

#endif
