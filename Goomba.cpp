#include "Goomba.h"

Goomba::Goomba(){
    srand((unsigned)time(0));
}
Goomba::~Goomba(){

}

bool Goomba::interaction(){
    //win
    if((rand() % 100) >= 20){
        return true;
    }
    //lose
    else{
        return false;
    }
}