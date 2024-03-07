#include "Level.h"
<<<<<<< HEAD
#include "Coin.h"

=======
#include <fstream>
#include <cstdlib> 
>>>>>>> e14f69903a5aa3c42175d43e1cce24bc5312a7ff
Level::Level(){
    N = 1;
    row = 0;
    col = 0;
    grid = new char[N*N]; //https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new 
}
Level::Level(int sizeOfGrid){
    N = sizeOfGrid;
    row = 0;
    col = 0;
    grid = new char[N*N];
}
Level::~Level(){
    delete[] grid;
};

Coin coin;

void Level::printGrid() { // prints out the current level
    cout << ("=========\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i*N+j] << " ";
        }
        cout << ("\n");
    }
    cout << ("=========\n");
}

//fills grid with only enemies, items, or nothing
void Level::fillGrid(){
    srand(static_cast<unsigned int>(time(0))); // https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                int randy = rand() % 4;
            if(randy == 0){
<<<<<<< HEAD
                grid[i*N+j] = coin.getValue();
=======
                grid[i*N+j] = 'c';
>>>>>>> e14f69903a5aa3c42175d43e1cce24bc5312a7ff
            } else if(randy == 1){
                grid[i*N+j] = 'm';
            } else if(randy == 2){
                if((rand()%1) == 1){
                    grid[i*N+j] = 'k';
                }else{
                    grid[i*N+j] = 'g';
                }
            } else if(randy == 3){
                grid[i*N+j] = 'x';
            }
        }
    }
    placeBoss();
    placeWarp();
    placeMario();
}

//overrides a random spot to place singular Boss
void Level::placeBoss(){
    int chance = rand() % (N*N);
    grid[chance] = 'b';
}

//overrides a random spot to place singular warp pipe
void Level::placeWarp(){
    //need to check if Level is final level
    int chance = rand() % (N*N);
    if(grid[chance] != 'b'){
        grid[chance] = 'w';
    } else{
        grid[chance - 1] = 'w';
    }
}

//returns value at grid[row][column]
char Level::getPos(int row, int col){
    return grid[row*N+col];
}

//sets value at [i][j] with char value
void Level::setPos(int i, int j, char value){
    grid[i*N+j] = value;
}

void Level::placeMario(){
    int chance = rand() % (N*N);
    if(grid[chance] != 'w'){
        grid[chance] = 'H';
    } else{
        grid[chance - 1] = 'H';
    }
}

//iterates through array to find 'H', once found, sets row and col to i and j.
void Level::getCoord(char value, int& row, int& col){
    row = -1;
    col = -1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(grid[i*N+j] == value){
                row = i;
                col = j;
                return;
            }
        }
    }
}



/*1. array[row][col]

2. array[rol*Size+col]*/
