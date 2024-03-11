#include "Boss.h"
#include "Mario.h"
#include "World.h"
#include <ostream>
#include <cstdlib> 
#include <ctime>   

/*
    Description: This class modifies Mario's variables based on it's interaction with a boss.
*/

//Constructor
Boss::Boss() {
    srand((unsigned)time(NULL));
}
//Destructor
Boss::~Boss() {
}

//Boss interaction function
void Boss::interaction(std::ostream &outputStream, Mario& mario, World &world) {

    int chance = rand() % 100; // Generate a random number between 0 and 99

    if (chance < 50) { // 50% chance for Mario to win
        outputStream << "Mario fought the level boss and won\n";
        mario.setCurrentLevel(mario.getCurrentLevel() + 1); //increase level by 1
        mario.placeMario(world); //place mario in level L
        mario.setStay(true); //stay put
    } else { // 50% chance for Mario to lose
        if (mario.getPowerLevel() > 1) {
            mario.setPowerLevel(mario.getPowerLevel() - 2); // Decrease Mario's power level by 2
            outputStream << "Mario fought the level boss and lost\n";
        } else {
            outputStream << "Mario fought the level boss and lost\n";
            mario.setNumOfLives(mario.getNumOfLives() - 1); // Mario loses a life
            if (mario.getNumOfLives() > 0) {
                mario.setPowerLevel(0); // Reset Mario's power level to 0
                mario.setStay(true); //stay put
            }
        }
        mario.setStay(true); //stay put
    }
}
