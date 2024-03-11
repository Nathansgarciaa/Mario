#include "Item.h"

// Default constructor
Item::Item() {
    posX = 0; // Set default position X to 0
    posY = 0; // Set default position Y to 0
    interacted = false; // Item has not been interacted with
}

// Parameterized constructor
Item::Item(int posX, int posY) {
    this->posX = posX; // Set position X to provided value
    this->posY = posY; // Set position Y to provided value
    interacted = false; // Item has not been interacted with
}

// Destructor
Item::~Item() {
    // Cleanup code goes here (if any needed)
    // For this class, the destructor is empty because we are not dynamically allocating memory
}

// Since Interact is a pure virtual function, its implementation will be provided by derived classes.
