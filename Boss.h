#ifndef BOSS_H
#define BOSS_H


#include <ctime>
#include <random>

class Boss{
    public: 
        Boss();
        ~Boss();

        bool interaction();
        char getValue(){return 'b';};

};


#endif
