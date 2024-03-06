#ifndef MARIO_H
#define MARIO_H
class Mario{
    public:
        unsigned int v;//lives
        unsigned int coinCount;
        unsigned int pl;
        
        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();
        
        void interaction(char d);//char d is the represenation of the other objects in the grid
        



}
;



#endif