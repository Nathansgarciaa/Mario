#include "Warp.h"
#include <random> // For random number generation

// Default constructor
Warp::Warp() {
    // Initialize posX and posY if needed
}

// Parameterized constructor
Warp::Warp(int posX, int posY) {
    this->posX = posX;
    this->posY = posY;
    interacted = false;
}


void Warp::Interact(Mario& mario) {

    //will generate marios random x and y in nb by n grid in level
}
