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
    int levelCount; // Initialize levelCount here or in the constructor

private:
    Level* levels; // Pointer to a dynamic array of Level objects
};

#endif
