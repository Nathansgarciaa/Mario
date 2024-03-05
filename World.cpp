#include "World.h"
World::World(){
    levelAmount = 10;
    levels = new Level[levelAmonut];


}
World::~World(){

}
World::World(int levels){
   levelAmount = levels;
   levels = new Level[levelAmount];


}
void World::nextLevel(){
    levelCount = levelCount + 1;
}
void World::endGame(){

}

int World::getLevel(){
    return levelCount;
}


