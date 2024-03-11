
#ifndef MARIO_H
#define MARIO_H
#include "Level.h"
#include "Coin.h"
#include "Mushroom.h"
#include "Goomba.h"
#include "KoopaTroopa.h"
#include "Boss.h"
#include "Warp.h"
#include <ctime>


class Mario{
    public:
        Mario(Level &test, Coin &coin, Mushroom &mush, Goomba &goomba, KoopaTroopa &koopa, Boss &boss, Warp &warp);
        ~Mario();
        int row;
        int col;
        int currRow;
        int currCol;
        bool isAlive;
        int goombCheck;
        int koopCheck;
    
        unsigned int v;//lives
        unsigned int coinCount;
        unsigned int pl;//power level
        string value;
        string wonOrLost;

        string getWonOrLost(){return wonOrLost;};
        void setWonOrLost(string wl){
            wonOrLost = wl;
        }

        string getPrintVal(){
            return value;
        }
        void setPrintVal(string va){
            value = va;
        }

        int getCurrRow(){
            int i;
            int j;
            test.getCoord('H', i, j);
            return i;

        }
        int getCurrCol(){
            int i;
            int j;
            test.getCoord('H', i, j);
            return j;
        }

        void setCurrRow(int r){currRow = r;}

        void setCurrCol(int c){currCol = c;}
        int getRow(){
            int i;
            int j;
            test.getCoord('H', i, j);
            return i;

        }
        int getCol(){
            int i;
            int j;
            test.getCoord('H', i, j);
            return j;
        }

        void setRow(int r){row = r;}

        void setCol(int c){col = c;}

        int getCoinCount(){return coinCount;}
        void setCoinCount(int c){coinCount = c;}
        int getPL(){return pl;}
        void setPL(int c){pl = c;}
        int getLives(){return v;};
        void setLives(int lives){v = lives;}
        //movement
        char movement();
        char moveLeft();
        char moveRight();
        char moveUp();
        char moveDown();

        //interaction
        void coinInteraction();//char d is the represenation of the other objects in the grid
        void mushInteraction();
        bool goombaInteraction();
        void koopaInteraction();
        void bossInteraction();
        void warpInteraction();
        void interaction();
    private:
        Level &test;
        Coin &coinT;
        Mushroom &mush;
        Goomba &goom;
        KoopaTroopa &koop;
        Boss &bos;
        Warp &warpT;



}
;



#endif