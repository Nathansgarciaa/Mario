#include "Level.h"
int main(int argc, char **argv){
    Level test(5);
    int j = 0;
    int i = 0;

    test.fillGrid();
    test.printGrid();
    test.getCoord('H', i, j);

    cout << "Mario[" << i << "][" << j << "]" << endl;
}
