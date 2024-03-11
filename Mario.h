#ifndef MARIO_H
#define MARIO_H
#include "World.h"
#include <iostream>
using namespace std;

class Coin;
class Mushroom;
class Goomba;
class KoopaTroopa;
class Boss;
class Warp;
class ostream;

class Mario{
    public:
        Mario();
        Mario(int lives);
        ~Mario();
        int move(World &world, int direction);
        int action(std::ostream &outputStream, World &world, Coin &coin, Mushroom &mush, Goomba &goomba, KoopaTroopa &koopa, Boss &boss, Warp &warp);
        int numOfLives;
        int numOfCoins;
        int powerLevel;
        int currentLevel;
        int currentRow;
        int currentCol;
        int numOfMoves;
        int numOfEnemiesDefeated;
        int moves;
        bool stay;

        bool isAlive(){return numOfLives > 0;};
        int getNumOfLives(){return numOfLives;};
        void setNumOfLives(int lives){numOfLives = lives;};
        int getNumOfCoins(){return numOfCoins;};
        void setNumOfCoins(int coins){numOfCoins = coins;};
        int getPowerLevel(){return powerLevel;};
        void setPowerLevel(int pl){powerLevel = pl;};
        int getCurrentLevel(){return currentLevel;};
        void setCurrentLevel(int cl){currentLevel = cl;};
        int getCurrentRow(){return currentRow;};
        void setCurrentRow(int row){currentRow = row;};
        int getCurrentCol(){return currentCol;};
        void setCurrentCol(int col){currentCol = col;};
        int getMoves(){return moves;};
        bool getStay(){return stay;};
        void setStay(bool temp){stay = temp;};

        void placeMario(World &world);
        int direction();
        bool savedPrincess(World &world);
        void printPos(std::ostream &outputStream);
        void printLevel(std::ostream &outputStream, World &world);

        
}
;



#endif