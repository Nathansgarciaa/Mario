#ifndef COIN_H
#define COIN_H

#include "Item.h"
 

class Coin : public Item {
public:
    Coin();
    Coin(int posX, int posY);
<<<<<<< HEAD
    char getValue(){return 'c';};
    virtual void Interact(Mario& mario); // Override Item's pure virtual function
};

#endif
=======
    virtual void Interact(Mario& mario) override; // Override Item's pure virtual function
};

#endif
>>>>>>> e14f69903a5aa3c42175d43e1cce24bc5312a7ff
