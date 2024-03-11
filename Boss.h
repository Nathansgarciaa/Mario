#ifndef BOSS_H
#define BOSS_H

<<<<<<< HEAD

#include <ctime>
#include <random>

class Boss{
    public: 
        Boss();
        ~Boss();

        bool interaction();
        char getValue(){return 'b';};

};


=======
#include "Mario.h" // Assuming the Mario class is defined elsewhere

class Boss {
public:
    int posX; // X position of the Boss
    int posY; // Y position of the Boss
    bool isDefeated; // Status of the Boss

    Boss();
    Boss(int posX, int posY);
    void Encounter(Mario& mario, int levelCount, int levelAmount);
};

>>>>>>> fcad4ea2971320e511db594d15b710186151257a
#endif
