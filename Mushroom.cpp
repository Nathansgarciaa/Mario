#include "Mushroom.h"
#include "Mario.h"
#include "World.h"
#include <cstdlib>
#include <ostream>

/*
    Description: This class modifies Mario's variables based on it's interaction with a mushroom.
*/

// Default constructor
Mushroom::Mushroom() {
}

// Parameterized constructor
Mushroom::~Mushroom(){
}

// Interact method modifies Mario's pl variable
void Mushroom::interaction(std::ostream &outputStream, Mario &mario, World &world) {
    outputStream << "Mario ate a mushroom. ";
    mario.setPowerLevel(mario.getPowerLevel() + 1);
    if(mario.getPowerLevel() > 2){
        mario.setPowerLevel(2);
    }
}
