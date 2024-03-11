#ifndef COIN_H
#define COIN_H
#include <iostream>

class Mario;
class World;
class ostream;

class Coin{
public:
    Coin();
    ~Coin();
    void interaction(std::ostream &outputStream, Mario &mario, World &world); 
};

#endif
