#include "Coin.h"

// Default constructor
Coin::Coin() {
    posX = 0; // Default position X
    posY = 0; // Default position Y
    interacted = false; // Item has not been interacted with
}

// Parameterized constructor
Coin::Coin(int posX, int posY) {
    this->posX = posX; // Set position X to the argument posX
    this->posY = posY; // Set position Y to the argument posY
    interacted = false; // Item has not been interacted with
}

// Interact method increases Mario's coinCount
void Coin::Interact(Mario& mario) {
    mario.coinCount += 1; // Increment Mario's coin count by 1
}
