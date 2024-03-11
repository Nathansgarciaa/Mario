#include "Boss.h"

Boss::Boss(){
    srand((unsigned)time(0));
}
Boss::~Boss(){

}

bool Boss::interaction(){
    //win
    if((rand() % 100) >= 50){
        return true;
    }
    //lose
    else{
        return false;
    }
}
