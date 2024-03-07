#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
#include <fstream>
#include <string>
#include "Level.h"
using namespace std;

class FileProcessor{
    public: 
        FileProcessor();//constructor
        ~FileProcessor();//deconstructor

        //function
        void processFile(string input, string output);
};

#endif