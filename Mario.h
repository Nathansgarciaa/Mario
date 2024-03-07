#ifndef MARIO_H
#define MARIO_H
class Mario{
    public:
        Mario();
        ~Mario();
        int x;
        int y;
    
        unsigned int v;//lives
        unsigned int coinCount;
        unsigned int pl;//power level
    private:
        // move functions should update x and y
        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();
        void interaction(char d);//char d is the represenation of the other objects in the grid
        



}
;



#endif