#include "Warp.h"
#include "Mario.h"
#include "World.h"
#include <cstdlib>
#include <ostream>
#include <random> 

/*
    Description: This class modifies Mario's variables based on it's interaction with a warp pipe.
*/

Warp::Warp() {}
Warp::~Warp() {}

//Warp interaction
void Warp::interaction(std::ostream &outputStream, Mario &mario, World &world) {
    outputStream << "Mario warped. ";
    mario.setCurrentLevel(mario.getCurrentLevel() + 1); // increments current level
    mario.placeMario(world); //places mario in next level
    mario.setStay(true); // stay put
}
