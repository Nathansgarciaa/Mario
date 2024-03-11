#ifndef WARP_H
#define WARP_H
#include <iostream>
using namespace std;

class Mario;
class World;
class ostream;

class Warp{
public:
    Warp();
    ~Warp();
    void interaction(std::ostream &outputStream, Mario  &mario, World &world);

};

#endif
