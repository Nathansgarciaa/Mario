#ifndef LEVEL_H
#define LEVEL_H
#include <fstream>
#include <iostream>
using namespace std;

class Level{
    public: 
        Level();
        Level(int sizeOfGrid);
        ~Level();
        int L;
        int getLevel();
        void setLevel(int level);
        int getSize(){return N;};
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
        int row;
        int col;
        char *grid; //2D grid


};

#endif