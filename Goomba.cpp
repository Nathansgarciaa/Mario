#include "Goomba.h"
#include "Mario.h"
#include "World.h"
#include <ostream>
#include <cstdlib> 
#include <ctime> 

/*
    Description: This class modifies Mario's variables based on it's interaction with a goomba.
*/

Goomba::Goomba(){
    srand(static_cast<unsigned int>(time(0)));
}

Goomba::~Goomba() {
}

//Goomba interaction
void Goomba::interaction(std::ostream &outputStream, Mario &mario, World &world) {
    int chance = rand() % 100; // Generate a random number between 0 and 99

    if (chance < 80) { // 80% chance for Mario to defeat the Goomba
        outputStream << "Mario fought a Goomba and won. ";
    } else { // 20% chance for Mario to lose
        if (mario.getPowerLevel() > 0) {
            mario.setPowerLevel(mario.getPowerLevel()-1);
            outputStream << "Mario fought a Goomba and lost\n";
        } else {
            outputStream << "Mario fought a Goomba and lost\n";
            mario.setNumOfLives(mario.getNumOfLives() - 1);
            if (mario.getNumOfLives() > 0) {
                mario.setStay(true);
                mario.setPowerLevel(0);
            }
        }
    }
}
