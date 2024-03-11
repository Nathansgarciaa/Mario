#include "Mushroom.h"

// Default constructor
Mushroom::Mushroom() {
    posX = 0;
    posY = 0;
    interacted = false;
}

// Parameterized constructor
Mushroom::Mushroom(int posX, int posY) {
    this->posX = posX;
    this->posY = posY;
    interacted = false;
}

// Interact method modifies Mario's pl variable
void Mushroom::Interact(Mario& mario) {
    if (mario.pl < 2) { // If Mario's power level is less than 2
        mario.pl += 1; // Increment the power level by 1
    }
    // If Mario's power level is 2, do nothing (it remains 2)
}
