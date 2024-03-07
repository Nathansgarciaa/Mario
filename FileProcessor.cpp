#include "FileProcessor.h"

FileProcessor::FileProcessor(){};
FileProcessor::~FileProcessor(){};
Level ba;

void FileProcessor::processFile(string input, string output){
    fstream fin;
    ofstream fout;
    Level ba;

    fin.open(input, ios::in);
    fout.open(output);

    

    fout.close();
    fin.close();
};
