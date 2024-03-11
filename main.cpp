#include <iostream>
#include <fstream>
#include "Game.h"
#include "Mario.h"
#include "World.h"

using namespace std;
/*
    Description: This file is used to compile all other .cpp files and also get input from the 
    command line of the inputFile and outputFile name.
*/

int main(int argc, char* argv[]) {
    string inputFile = argv[1];
    string outputFile = argv[2];

    Game game(inputFile, outputFile);
    
    return 0;
}