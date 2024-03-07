#ifndef ITEM_H
#define ITEM_H
#include "Mario.h"
<<<<<<< HEAD

=======
#include "Level.h"
#include "World.h"
using namespace std;
>>>>>>> e14f69903a5aa3c42175d43e1cce24bc5312a7ff
class Item {
public:
    Item();
    Item(int posX, int posY);
    ~Item();
    int posX;
    int posY;
    bool interacted; // bool for if Mario interacted with or not


    // Making Interact a pure virtual function
    virtual void Interact(Mario& mario) = 0;
};

#endif
