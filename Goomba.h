#ifndef GOOMBA_H
#define GOOMBA_H

#include <ctime>
#include <random>

class Goomba{
    public: 
        Goomba();
        ~Goomba();
        bool interaction();
        char getValue(){return 'g';};
};

#endif
