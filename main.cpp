
#include "Mario.h"
int main(int argc, char **argv){
    Level test(5);
    Coin coinT;
    Mushroom mush;
    Goomba goom;
    KoopaTroopa koop;
    Boss bos;
    Warp warpT;
    Mario mario(test, coinT, mush, goom, koop, bos, warpT);

    
    test.fillGrid();
    test.printGrid();
    for(int i = 0; i < 5; i++){
        mario.interaction();
        test.printGrid();
        cout << mario.getPrintVal() << endl;
    }
    
        

    return 0;

}
