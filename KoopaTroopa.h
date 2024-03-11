#ifndef KOOPATROOPA_H
#define KOOPATROOPA_H

<<<<<<< HEAD
#include <ctime>
#include <random>

class KoopaTroopa{
    public: 
        KoopaTroopa();
        ~KoopaTroopa();
        bool interaction();
        char getValue(){return 'k';};
=======
#include "Enemy.h"
#include "Mario.h" // Assuming Mario class is defined elsewhere

class KoopaTroopa : public Enemy {
public:
    KoopaTroopa();
    KoopaTroopa(int posX, int posY);
    virtual void Interact(Mario& mario) override;
>>>>>>> fcad4ea2971320e511db594d15b710186151257a
};

#endif
