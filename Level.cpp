#include "Level.h"
#include "Coin.h"
#include "Mushroom.h"
#include "Warp.h"
#include "Goomba.h"
#include "KoopaTroopa.h"

Level::Level(){
    L = 1;
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
}

Coin coin;
Mushroom mushroom;
Warp warp;
Goomba goomba;
KoopaTroopa koop;

int Level::getLevel(){
    return L;
}

void Level::setLevel(int level){
    L = level;
}
void Level::printGrid() { // prints out the current level
    cout << endl;
    cout << ("=========\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i*N+j] << " ";
        }
        cout << ("\n");
    }
    cout << ("=========\n") << endl;
}

//fills grid with only enemies, items, or nothing
void Level::fillGrid(){
    srand(static_cast<unsigned int>(time(0))); // https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                int randy = rand() % 5;
                if(randy == 0){
                    grid[i*N+j] = coin.getValue();
                } else if(randy == 1){
                    grid[i*N+j] = mushroom.getValue();
                } else if(randy == 2){
                    grid[i*N+j] = koop.getValue();
                } else if(randy == 3){
                    grid[i*N+j] = goomba.getValue();
                } else if(randy == 4){
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
        grid[chance] = warp.getValue();
    } else{
        grid[chance - 1] = warp.getValue();
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
    char temp = grid[chance];
    if(grid[chance] != 'w'){
        grid[chance] = 'H';
    } else{
        temp = grid[chance -1];
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
