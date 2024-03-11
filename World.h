#ifndef WORLD_H
#define WORLD_H
#include <iostream>
#include <random>
using namespace std;
class ostream;

class World {
public:
    World();
    World(int numberOfLevels, int gridSize, int percentCoins, int percentNothing, int percentGoombas, int percentKoopas, int percentMushrooms);
    ~World();
    int getNumOfLevels();
    int calculatePos(int level, int row, int col);
    void setPos(int level, int row, int col, char c);
    char getPos(int level, int row, int col);
    void printLevel(std::ostream &outputStream, int level);
    int getGridSize();

private:
    int L;
    int N;
    char *grid;

};
#endif
