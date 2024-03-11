#include "Mario.h"
#include "Coin.h"
#include "Mushroom.h"
#include "Goomba.h"
#include "KoopaTroopa.h"
#include "Boss.h"
#include "Warp.h"
#include <cstdlib>
#include <ctime>
#include <random>

/*
    Description: This class has all variables of Mario's life. It utilizes other classes and their functions
    to interact with certain items or enemies. Based on that interaction, variables will change. It also 
    determines where Mario will move next on the map and what action he will be doing. 
*/

//Constructor
Mario::Mario(){
    numOfLives = 0;
    numOfCoins = 0;
    powerLevel = 0;
    currentLevel = 0;
    currentRow = 3;
    currentCol = 3;
    numOfMoves = 0;
    numOfEnemiesDefeated = 0;
    moves = 0;
    bool stay = false;
    srand(static_cast<unsigned int>(time(nullptr)));
}
//overloaded constructor
Mario::Mario(int lives){
    numOfLives = lives;
    numOfCoins = 0;
    powerLevel = 0;
    currentLevel = 0;
    currentRow = 3;
    currentCol = 3;
    numOfMoves = 0;
    numOfEnemiesDefeated = 0;
    moves = 0;
    bool stay = false;
    srand(static_cast<unsigned int>(time(nullptr)));
}

//Destructor
Mario::~Mario() {
    
}

void Mario::placeMario(World &world) { 
    currentCol = rand() % world.getGridSize();
    currentRow = rand() % world.getGridSize();
}


bool Mario::savedPrincess(World &world){
    return currentLevel >= world.getNumOfLevels(); // returns true once currentlevel is past num of levels
}

void Mario::printPos(std::ostream &outputStream) {
    outputStream << "Mario's Location : (" << getCurrentRow() << ", " << getCurrentCol() << "). ";
}

void Mario::printLevel(std::ostream &outputStream, World &world){
    for(int k = 0; k < world.getGridSize() * 2; k++){
        outputStream << "=";
    }
    outputStream << "\n";
    for (int i = 0; i < world.getGridSize(); ++i)
    {
        for (int j = 0; j < world.getGridSize(); ++j)
        {
            if(i == currentRow && j == currentCol){
                outputStream << 'H' << ' ';
            }else{
                outputStream << world.getPos(currentLevel, i, j) << " ";
            }
        }
        outputStream  << endl;
    }
    for(int k = 0; k < world.getGridSize() * 2; k++){
        outputStream << "=";
    }
    outputStream << "\n";
}

//choosing which direction
int Mario::direction(){
    return rand() % 3;
}

//movement logic, wrapping around array
int Mario::move(World &world, int direction){
    moves++;
    if(this->getStay()){
        return 4;
    }else if(direction == 0){
        this->setCurrentCol(this->getCurrentCol() - 1);
        if (this->getCurrentCol() < 0) {
            this->setCurrentCol(world.getGridSize() - 1);
        }
        return 0;
    }else if(direction == 1){
        this->setCurrentCol(this->getCurrentCol() + 1);
        if (this->getCurrentCol() > world.getGridSize() - 1) {
            this->setCurrentCol(0);
        }
        return 1;
    }else if(direction == 2){
        this->setCurrentRow(this->getCurrentRow()-1);
        if (this->getCurrentRow()< 0) {
            this->setCurrentRow(world.getGridSize() - 1); 
        }
        return 2;
    }else if(direction == 3){
        this->setCurrentRow(this->getCurrentRow()+1);
        if (this->getCurrentRow() > world.getGridSize() - 1) {
            this->setCurrentRow(0);
        }
        return 3;
    }
    return -1;
}


//interaction logic
int Mario::action(std::ostream &outputStream, World &world, Coin &coin, Mushroom &mush, Goomba &goomba, KoopaTroopa &koopa, Boss &boss, Warp &warp){
    char encounter = world.getPos(currentLevel, currentRow, currentCol);
    setStay(false);
    if(encounter == 'x'){//nothing
        outputStream << "The position is empty. "; 
        return direction();
    }else if(encounter == 'c'){//coin
        world.setPos(this->getCurrentLevel(), this->getCurrentRow(), this->getCurrentCol(), 'x');
        coin.interaction(outputStream, *this, world);
        return direction();
    } else if(encounter == 'm'){//mushroom
        world.setPos(this->getCurrentLevel(), this->getCurrentRow(), this->getCurrentCol(), 'x');
        mush.interaction(outputStream, *this, world);
        return direction();
    } else if(encounter == 'g'){//gooba
        goomba.interaction(outputStream, *this, world);
        if(getStay()){
            return 4;
        }else{
            world.setPos(this->getCurrentLevel(), this->getCurrentRow(), this->getCurrentCol(), 'x');
            return direction();
        }
    } else if(encounter == 'k'){//koopa troopa
        koopa.interaction(outputStream, *this, world);
        if(getStay()){
            return 4;
        }else{
            world.setPos(this->getCurrentLevel(), this->getCurrentRow(), this->getCurrentCol(), 'x');
            return direction();
        }
    } else if(encounter == 'w'){//warp
        warp.interaction(outputStream, *this, world);
        return direction();
    } else if(encounter == 'b'){//boss
        boss.interaction(outputStream, *this, world);
        if(getStay()){
            return 4;
        }else{
            world.setPos(this->getCurrentLevel(), this->getCurrentRow(), this->getCurrentCol(), 'x');
            return direction();
        }
    } else{
        return direction();
    }
}






