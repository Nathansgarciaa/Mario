#include "Mario.h"

// Constructor
Mario::Mario() {
    
    x = 0;
    y = 0;
    v = 3; 
    coinCount = 0;
    pl = 0; 
}

// Destructor
Mario::~Mario() {
    
}

// moveLeft function
void Mario::moveLeft() {
    x = x - 1;

}

// moveRight function
void Mario::moveRight() {
   x = x + 1;
}

// moveUp function
void Mario::moveUp() {
    y = y + 1;
}

// moveDown function
void Mario::moveDown() {
    y = y - 1;
}


