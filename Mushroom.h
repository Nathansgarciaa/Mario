#ifndef MUSHROOM_H
#define MUSHROOM_H
#include <iostream>
using namespace std;

class Mario;
class World;
class ostream;

class Mushroom{
public:
    Mushroom();
    ~Mushroom();
    void interaction(std::ostream &outputStream, Mario &mario, World &world);
};

#endif 
