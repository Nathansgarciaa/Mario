<<<<<<< HEAD
// #ifndef ENEMY_H
// #define ENEMY_H
// #include "Mario.h"
// #include "World.h"

// class Enemy {
// public:
//     static int enemiesDefeated; // Count of enemies defeated
//     bool isDefeated;            // Boolean to track if this enemy has been defeated
//     int posX;                   // X position of the enemy
//     int posY;                   // Y position of the enemy

//     Enemy();                              // Default constructor
//     Enemy(int x, int y);                  // Parameterized constructor
//     virtual ~Enemy();                     // Virtual destructor for proper cleanup of derived classes

//     virtual void Interact(Mario &mario);          // Pure virtual function for interaction
//     static int GetEnemiesDefeatedCount(); // Static member function to get count of defeated enemies
// };

// #endif
=======
#ifndef ENEMY_H
#define ENEMY_H
#include "Mario.h"
#include "World.h"

class Enemy {
public:
    static int enemiesDefeated; // Count of enemies defeated
    bool isDefeated;            // Boolean to track if this enemy has been defeated
    int posX;                   // X position of the enemy
    int posY;                   // Y position of the enemy

    Enemy();                              // Default constructor
    Enemy(int x, int y);                  // Parameterized constructor
    virtual ~Enemy();                     // Virtual destructor for proper cleanup of derived classes

    virtual void Interact(Mario& mario) = 0;          // Pure virtual function for interaction
    static int GetEnemiesDefeatedCount(); // Static member function to get count of defeated enemies
};

#endif
>>>>>>> fcad4ea2971320e511db594d15b710186151257a
