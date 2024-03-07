<<<<<<< HEAD
=======
//create grid, fill grid with items, enemies, 


//funcs
//getValue of position
//setValue of position

>>>>>>> e14f69903a5aa3c42175d43e1cce24bc5312a7ff
#ifndef LEVEL_H
#include <fstream>
#include <iostream>
using namespace std;

class Level{
    public: 
        Level();
        Level(int sizeOfGrid);
        ~Level();
        void printGrid();
        void fillGrid();
        void placeBoss();
        void placeWarp();
        void placeMario();
        void getCoord(char value, int& row, int &col);
        char getPos(int i, int j);
        void setPos(int i, int j, char value);


    private: 
        int N; //size of grid
        int M; // size of grid
        int row;
        int col;
        char *grid; //2D grid


};

#endif