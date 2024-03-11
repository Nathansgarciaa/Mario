#include "Coin.h"
#include "Mario.h"
#include "World.h"
#include <cstdlib>
#include <ostream>

/*
    Description: This class modifies Mario's variables based on it's interaction with a coin.
*/

// Default constructor
Coin::Coin() {
}

// Parameterized constructor
Coin::~Coin() {
}

// Coin interaction
void Coin::interaction(std::ostream &outputStream, Mario &mario, World &world) {
    outputStream << "Mario collected a coin. ";
    mario.setNumOfCoins(mario.getNumOfCoins() + 1); // Increment Mario's coin count by 1
    if(mario.getNumOfCoins() == 20){ // if mario has 20 coins
        mario.setNumOfLives(mario.getNumOfLives() + 1); //gain extra life
        mario.setNumOfCoins(0); //reset coin to 0
    }
}
