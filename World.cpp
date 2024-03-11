#include "World.h"
#include <cstdlib>
#include <ostream>

World::World() {

}

World::World(int numberOfLevels, int gridSize, int percentCoins, int percentNothing, int percentGoombas, int percentKoopas, int percentMushrooms){
    N = gridSize;
    L = numberOfLevels;
    grid = new char[L * N * N];

    for (int level = 0; level < L; ++level)
    {
        for (int row = 0; row < N; ++row)
        {
            for (int col = 0; col < N; ++col) 
            {
                int randy = rand() % 100;
                char cellValue = 'x'; 
                
                if (randy < percentNothing)
                {
                    cellValue = 'x';
                }
                else if (randy < (percentMushrooms + percentNothing))
                {
                    cellValue = 'm';
                }
                else if (randy < (percentCoins + percentMushrooms + percentNothing))
                {
                    cellValue = 'c';
                }
                else if (randy < (percentGoombas + percentCoins + percentMushrooms + percentNothing))
                {
                    cellValue = 'g';
                }
                else if (randy < (percentKoopas + percentGoombas + percentCoins + percentMushrooms + percentNothing))
                {
                    cellValue = 'k';
                }

                setPos(level, row, col, cellValue);
            }
        }

        if (level < L - 1)
        {
            int warpCoordX = rand() % gridSize;
            int warpCoordY = rand() % gridSize;
            setPos(level, warpCoordX, warpCoordY, 'w');
        }

        int bossCoordX = rand() % gridSize;
        int bossCoordY = rand() % gridSize;
        setPos(level, bossCoordX, bossCoordY, 'b');
    }
}


World::~World() // default destructor
{
    delete[] grid;
}

int World::getGridSize(){
    return N;
}

int World::getNumOfLevels() {
    return L;
}

void World::printLevel(std::ostream &outputStream, int level)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            outputStream << getPos(level, i, j) << " ";
        }
        outputStream << endl;
    }
    outputStream << endl;
}
int World::calculatePos(int level, int row, int col) { // calculates position
    return level * (N * N) + row * N + col; 
}

void World::setPos(int level, int row, int col, char c) {
    int position = calculatePos(level, row, col);
    grid[position] = c;
}

char World::getPos(int level, int row, int col) {
    int position = calculatePos(level, row, col);
    return grid[position];
}
