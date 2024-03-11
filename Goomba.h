#ifndef GOOMBA_H
#define GOOMBA_H

<<<<<<< HEAD
#include <ctime>
#include <random>

class Goomba{
    public: 
        Goomba();
        ~Goomba();
        bool interaction();
        char getValue(){return 'g';};
=======
#include "Enemy.h"
#include "Mario.h" // Assuming the Mario class is defined elsewhere

class Goomba : public Enemy {
public:
    Goomba();
    Goomba(int posX, int posY);
    virtual void Interact(Mario& mario) override;
>>>>>>> fcad4ea2971320e511db594d15b710186151257a
};

#endif
