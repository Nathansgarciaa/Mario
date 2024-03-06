#include "World.h"


World::World() {
    levelAmount = 10;
    levels = new Level[levelAmount];
    levelCount = 0; // Initialize levelCount
}

World::~World() {
    delete[] levels; // Deallocate the dynamic array
}

World::World(int levelCount) {
    this->levelAmount = levelCount;
    this->levels = new Level[this->levelAmount];
    this->levelCount = 0; // Initialize levelCount
}

void World::nextLevel() {
    levelCount++;
}

void World::endGame() {
    // Implementation depends on what "end game" should do
}

int World::getLevel() {
    return levelCount;
}
