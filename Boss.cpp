#include "Boss.h"
<<<<<<< HEAD

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
=======
#include <cstdlib> // Include for access to rand() and srand()
#include <ctime>   // Include for access to time() for seeding srand()

Boss::Boss() {
    posX = 0; // Initialize X position of the Boss to 0
    posY = 0; // Initialize Y position of the Boss to 0
    isDefeated = false; // Boss is not defeated initially
}

Boss::Boss(int posX, int posY) {
    this->posX = posX; // Set X position to the given argument
    this->posY = posY; // Set Y position to the given argument
    isDefeated = false; // Boss is not defeated initially
}

void Boss::Encounter(Mario& mario, int currentLevel, int totalLevels) {
    // Seed the random number generator only once
    static bool seeded = false; // Static variable to ensure srand is called only once
    if (!seeded) {
        srand((unsigned)time(NULL)); // Use current time as seed for random generator
        seeded = true;
    }

    int fightOutcome = rand() % 100; // Generate a random number between 0 and 99

    if (fightOutcome < 50) { // 50% chance for Mario to win
        isDefeated = true; // Mark the Boss as defeated
        if (currentLevel == totalLevels) {
            // Mario saves the princess and wins the game
            // Implement game win logic here
        } else {
            // Mario moves on to the next level
            // Implement level progression logic here
        }
    } else { // 50% chance for Mario to lose
        if (mario.pl > 1) {
            mario.pl -= 2; // Decrease Mario's power level by 2
        } else {
            mario.v -= 1; // Mario loses a life
            if (mario.v > 0) {
                mario.pl = 0; // Reset Mario's power level to 0
                // Mario continues at the same location
            } else {
                // Mario has no more lives - game over
                // Implement game over logic here
            }
        }
        // Logic to retry the fight with the boss could be added here
>>>>>>> fcad4ea2971320e511db594d15b710186151257a
    }
}
