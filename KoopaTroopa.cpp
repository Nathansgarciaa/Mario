#include "KoopaTroopa.h"

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