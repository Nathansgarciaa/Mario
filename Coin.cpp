#include "Coin.h"

// Default constructor
Coin::Coin() {
}

Coin::~Coin(){};
// Interact me

int Coin::interaction(int c){
    if(c == 20){
        return 0;
    }else{
        return 1;
    }
}