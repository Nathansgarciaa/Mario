#include "Game.h"
#include "World.h"
#include "Mario.h"
#include "Coin.h"
#include "Mushroom.h"
#include "Goomba.h"
#include "KoopaTroopa.h"
#include "Boss.h"
#include "Warp.h"

#include <iostream>
#include <cstdlib>
#include <ostream>
#include <fstream>

/*
    Description: This class runs the game of Mario. It also takes in the input from the inputFile
    and stores those values to it's variables. It also sends output to the outputFile.
*/

Game::Game(string &inputFile, const string &outputFile){
    //initialize variables
    int lines = 0; 
    int N = 5;
    int L = 3;
    int numOfLives = 3;
    int percentCoins = 20;
    int percentNothing = 20;
    int percentGoomba = 20;
    int percentKoopa = 20;
    int percentMushroom = 20;
    

    ofstream newOutputFile;
    if (!outputFile.empty()) // if the output file is empty, open new outputFile outputStream
    {
        newOutputFile.open(outputFile);
    }
    std::ostream &outputStream = (newOutputFile.is_open()) ? newOutputFile : cout; // CHATGPT, I think this allows compiler to understand << as cout

    ifstream MyReadFile(inputFile); 
    string fileString;

    //gets line from open file, storing integers to variables
    while (getline(MyReadFile, fileString))
    {
        switch (lines) {
        case 0:
            L = stoi(fileString);
            L += 1; 
            break;
        case 1:
            N = stoi(fileString); // CHATGPT = stoi turns string to int
            break;
        case 2:
            numOfLives = stoi(fileString);
            break;
        case 3:
            percentCoins = stoi(fileString);
            break;
        case 4:
            percentNothing = stoi(fileString);
            break;
        case 5:
            percentGoomba = stoi(fileString);
            break;
        case 6:
            percentKoopa = stoi(fileString);
            break;
        case 7:
            percentMushroom = stoi(fileString);
            break;
        default:
            break;
        }
        lines++;
    }


    srand(time(NULL));
    World world(L, N, percentCoins, percentNothing, percentGoomba, percentKoopa, percentMushroom);
    Mario mario(numOfLives);
    Coin coin;
    Mushroom mush;
    Goomba goomba;
    KoopaTroopa koopa;
    Boss boss;
    Warp warp;

    //game loop
    while (mario.isAlive() && !mario.savedPrincess(world)){
        if (mario.getCurrentLevel() != world.getNumOfLevels())
        {
            mario.printLevel(outputStream, world);
        }

        mario.printPos(outputStream);
        int choice = mario.action(outputStream, world, coin, mush, goomba, koopa, boss, warp);
        outputStream << "Power Level " << mario.getPowerLevel() << ". ";
        outputStream << "Mario has " << mario.getNumOfLives() << " lives. ";
        outputStream << "Mario has " << mario.getNumOfCoins() << " coins. ";
        outputStream << "Mario is on level " << mario.getCurrentLevel() << endl;
        
        if(choice == 0){
            outputStream << "Next move: left\n";
        } else if(choice == 1){
            outputStream << "Next move: right\n";
        } else if(choice == 2){
            outputStream << "Next move: up\n";
        } else if(choice == 3){
            outputStream << "Next move: down\n";
        } else if(choice == 4){
            outputStream << "Next move: stay put\n";
        }
        outputStream << "\n\n";
        mario.move(world, choice);
    }
    if(!mario.isAlive()){
        outputStream << "Mario ran out of lives. YOU LOST.\n";
        outputStream << "Total moves: " << mario.getMoves() << "\n";
    }
    if(mario.savedPrincess(world)){
        outputStream << "Mario saved the princess! YOU WON.\n";
        outputStream << "Total moves: " << mario.getMoves() << "\n";
    }
}

Game::~Game(){
}

