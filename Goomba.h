#ifndef GOOMBA_H
#define GOOMBA_H
#include <iostream>
using namespace std;

class Mario;// Assuming the Mario class is defined elsewhere
class World;
class ostream;

class Goomba{
public:
    Goomba();
    ~Goomba();
    void interaction(std::ostream &outputStream, Mario &mario, World &world);
};

#endif
