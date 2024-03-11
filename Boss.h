#ifndef BOSS_H
#define BOSS_H
#include <iostream>

class Mario;
class World;
class ostream;

class Boss {
public:
    Boss();
    ~Boss();
    void interaction(std::ostream &outputStream, Mario& mario, World &world);
};

#endif
