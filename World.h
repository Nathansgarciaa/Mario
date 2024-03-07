#ifndef WORLD_H
#define WORLD_H
#include "Level.h"


class World {
public:
    World();
    ~World();
    World(int levels);
    void nextLevel();
    void endGame();
    int getLevel();

    int levelAmount;
<<<<<<< HEAD
    int levelCount; // Initialize levelCount here or in the constructor
=======
    int levelCount = 0; // Initialize levelCount here or in the constructor
>>>>>>> e14f69903a5aa3c42175d43e1cce24bc5312a7ff

private:
    Level* levels; // Pointer to a dynamic array of Level objects
};

#endif
