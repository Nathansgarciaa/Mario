#ifndef KOOPATROOPA_H
#define KOOPATROOPA_H

#include "Enemy.h"
#include "Mario.h" // Assuming Mario class is defined elsewhere

class KoopaTroopa : public Enemy {
public:
    KoopaTroopa();
    KoopaTroopa(int posX, int posY);
    virtual void Interact(Mario& mario) override;
};

#endif
