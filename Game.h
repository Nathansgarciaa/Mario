/*#ifndef GAME_H
#define GAME_H


#include "Mario.h"

class Game{
    public: 
        Game();
        ~Game();
        void play(int L, int N, int V, int coinP, int nothingP, int mushP, int goombaP, int koopaP);
    private: 
        Level test(int N);
        Coin coinT;
        Mushroom mush;
        Goomba goom;
        KoopaTroopa koop;
        Boss bos;
        Warp warpT;
        Mario mario(test, coinT, mush, goom, koop, bos, warpT);

};

#endif*/