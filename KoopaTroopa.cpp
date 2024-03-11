#include "KoopaTroopa.h"
<<<<<<< HEAD

KoopaTroopa::KoopaTroopa(){
    srand((unsigned)time(0));
}
KoopaTroopa::~KoopaTroopa(){
}

bool KoopaTroopa::interaction(){

    //win
    if((rand() % 100) >= 35){
        return true;
    }
    //lose
    else{
        return false;
    }
}
=======
#include <cstdlib> // Include for access to rand() and srand()
#include <ctime>   // Include for access to time() for seeding srand()

KoopaTroopa::KoopaTroopa() {
    // Inherits posX, posY, and isDefeated initialization from Enemy
}

KoopaTroopa::KoopaTroopa(int posX, int posY) {
    this->posX = posX;
    this->posY = posY;
    this->isDefeated = false;
}

void KoopaTroopa::Interact(Mario& mario) {
    // Seed the random number generator only once
    static bool isSeeded = false;
    if (!isSeeded) {
        srand(static_cast<unsigned int>(time(0))); // Use current time as seed for random generator
        isSeeded = true;
    }

    int randomValue = rand() % 100; // Generate a random number between 0 and 99

    if (randomValue < 65) { // 65% chance for Mario to defeat the Koopa
        this->isDefeated = true;
        Enemy::enemiesDefeated += 1;
    } else { // 35% chance for Mario to lose
        if (mario.pl > 0) {
            mario.pl -= 1;
        } else {
            mario.v -= 1;
            if (mario.v > 0) {
                mario.pl = 0;
            } else {
                // Handle game over scenario, possibly with a flag or a function call
                // Game ends - not represented here, but this is where you'd trigger it
            }
        }
    }

    // Note: The concept of Mario moving on, and what happens specifically when the game is lost,
    // is not covered here and should be handled by the game logic outside this function.
}
>>>>>>> fcad4ea2971320e511db594d15b710186151257a
