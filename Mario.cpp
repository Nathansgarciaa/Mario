#include "Mario.h"

<<<<<<< HEAD


Mario::Mario(Level &level, Coin &coin, Mushroom &mushroom, Goomba &goomba, KoopaTroopa &koopa, Boss &boss, Warp &warp) : test(level), coinT(coin), mush(mushroom), goom(goomba), koop(koopa), bos(boss), warpT(warp){
    srand((unsigned)time(0));
    row = 0;
    col = 0;
    v = 3;
    coinCount = 0;
    pl = 0;
    value = "";
    wonOrLost = "";
    isAlive = true;
    currRow = 0;
    currCol = 0;
    goombCheck = 0;
    koopCheck = 0;
}
Mario::~Mario(){
}




//movement

char Mario::moveLeft(){
    test.getCoord('H', row, col);
    setRow(row);
    setCol(col);
    char tempValue;
    
    if(col == 0){
        tempValue = test.getPos(row, test.getSize() - 1);
        test.setPos(row, test.getSize() - 1,'H');
        
    } else{

        tempValue = test.getPos(row,col-1);
        test.setPos(row,col-1,'H');
        
    }
    return tempValue;
}

char Mario::moveRight(){
    test.getCoord('H', row, col);
    setRow(row);
    setCol(col);
    char tempValue;
    if(col == test.getSize() - 1){
        tempValue = test.getPos(row, 0);
        test.setPos(row, 0,'H');
        
    } else{
        tempValue = test.getPos(row,col+1);
        test.setPos(row,col+1,'H');
        
    }
    return tempValue;
}

char Mario::moveDown(){
    test.getCoord('H', row, col);
    setRow(row);
    setCol(col);
    char tempValue;
    if(row == test.getSize() - 1){
        tempValue = test.getPos(0, col);
        test.setPos(0, col,'H');
        
    } else{
        tempValue = test.getPos(row+1,col);
        test.setPos(row+1,col,'H');
        
    }
    return tempValue;
}

char Mario::moveUp(){
    test.getCoord('H', row, col);
    setRow(row);
    setCol(col);
    char tempValue;
    if(row == 0){
        tempValue = test.getPos(test.getSize() - 1, col);
        test.setPos(test.getSize() - 1, col,'H');
        
    } else{
        tempValue = test.getPos(row-1,col);
        test.setPos(row-1,col,'H');
        
    }
    return tempValue;
}

char Mario::movement(){
    switch(rand() % 4){
        case 0: 
            return moveUp();
        case 1: 
            return moveDown();
        case 2: 
            return moveRight();
        case 3: 
            return moveLeft();
    }
    return -1;
}
void Mario::coinInteraction(){

    // Coin interaction
    if(coinT.interaction(getCoinCount()) == 0){ // if coins = 20, mario gains extra life
        setCoinCount(0);
        v++;
    } else{
        coinCount += coinT.interaction(getCoinCount());
    }
}

void Mario::mushInteraction(){
    if(getPL() == 2){
        setPL(2);
    }else {
        pl += mush.interaction();
    }
}

bool Mario::goombaInteraction(){
    if(!goom.interaction()){
        /*setWonOrLost("lost");
        if(getPL() < 0){
            setPL(getPL() - 1);
        }else{
            setLives(getLives()-1);
            if(getLives() < 0){
                isAlive = false;
            }
        }*/
        return false;
    } else{
        //setWonOrLost("won");
        return true;
    }
}

void Mario::koopaInteraction(){
    int tempRow;
    int tempCol;
    if(!koop.interaction()){
        setWonOrLost("lost");
        tempCol = getCol();
        tempRow = getRow();
        if(getPL() < 0){
            setPL(getPL() - 1);
        }else{
            setLives(getLives()-1);
            if(getLives() < 0){
                isAlive = false;
            }
        }
        test.setPos(tempRow, tempCol, 'g');
    } else{
        setWonOrLost("won");
    }
}

void Mario::bossInteraction(){
    //lose
    bool temp = bos.interaction();
    if(!temp){
        setWonOrLost("lost");
        setPL(getPL() - 2);
        if(getPL() < 0){
            setLives(getLives() - 1);
            if(getLives() < 0){
                isAlive = false;
            }
        } else{
            bossInteraction(); // recursion, untill either power levels are less than 0
        }
    } else{
        //won
        test.setLevel(test.getLevel() + 1);
    }
}

void Mario::warpInteraction(){
    bool temp = warpT.interaction();
    if(temp){
        test.setLevel(test.getLevel() + 1);
    }
}

void Mario::interaction(){
    cout <<  "Old coord: " << "(" <<getRow() << "," << getCol() << ")" << endl;
    char value = movement();

    if(value == 'c'){
        test.setPos(row,col, 'x');
        goombCheck = 0;
        koopCheck = 0;
        setPrintVal(" Mario collected a coin. ");
    } else if(value == 'm'){
        test.setPos(row,col, 'x');
        goombCheck = 0;
        koopCheck = 0;
        setPrintVal(" Mario ate a mushroom. ");
    } else if(value == 'g'){
        int chance = rand() % 100;
        if(chance <= 19){
            setPrintVal(" Mario fought a goomba and won. ");
            goombCheck = 0;
            test.setPos(row,col, 'x');
        } else{
            if(getPL() == 0){
                setPrintVal(" Mario fought a goomba and lost a life. ");
                test.setPos(row,col, 'x');
                goombCheck = 1;
            }
            setPL(getPL() - 1);
            setPrintVal(" Mario fought a goomba and lost. ");
            test.setPos(row,col, 'x');
            goombCheck = 1;
        }
    } else if(value == 'k'){
        int chance = rand() % 100;
        if(chance <= 34){
            koopCheck = 0;
            setPrintVal(" Mario fought a koopa troop and won. ");
            test.setPos(row,col, 'x');
        } else{
            if(getPL() == 0){
                setPrintVal(" Mario fought a koopa troop and lost a life. ");
                test.setPos(row,col, 'x');
                koopCheck = 1;
                
            }
            setPL(getPL() - 1);
            setPrintVal(" Mario fought a koopa troopa and lost. ");
            test.setPos(row,col, 'x');
            koopCheck = 1;
        }
    } else if(value == 'b'){
        test.setPos(row,col, 'x');
        setPrintVal(" Mario fought a boss. ");
    } else if(value == 'w'){
        test.setPos(row,col, 'x');
        setPrintVal(" Mario found a warp pipe. ");
    } else {
        test.setPos(row,col, 'x');
        setPrintVal(" The position is empty. ");
    }
    if(goombCheck == 1){
        test.setPos(currRow, currCol, 'g');
    }
    if(koopCheck == 1){
        test.setPos(currRow, currCol, 'k');
    }
    setCurrRow(getCurrRow());
    setCurrCol(getCurrCol());
    cout <<  "Current coord: " << "(" <<getCurrRow() << "," << getCurrCol() << ")" << endl;
}
/*switch(tempValue) {
            case 'c':
                test.setPos(row,col, 'x');
                setPrintVal(" Mario collected a coin. ");
                break;
            case 'm':
                test.setPos(row,col, 'x');
                setPrintVal(" Mario ate a mushroom. ");
                break;
            case 'g':
                setPrintVal(" Mario fought a Goomba and " + getWonOrLost() + ". ");
                if(getWonOrLost() == "lost"){
                    test.setPos(row,col, 'g');
                }
                break;
            case 'k':
                setPrintVal(" Mario fought a Koopa and " + getWonOrLost() + ". ");
                if(getWonOrLost() == "lost"){
                    test.setPos(row,col, 'k');
                }
                break;
            case 'w':
                setPrintVal(" Mario warped. ");
                break;
            case 'b':
                setPrintVal(" Mario fought a boss and " + getWonOrLost() + ". ");
                break;
            default:
                setPrintVal(" The position is empty. ");
            }*/
=======
// Constructor
Mario::Mario() {
    
    x = 0;
    y = 0;
    v = 3; 
    coinCount = 0;
    pl = 0; 
}

// Destructor
Mario::~Mario() {
    
}

// moveLeft function
void Mario::moveLeft() {
    x = x - 1;

}

// moveRight function
void Mario::moveRight() {
   x = x + 1;
}

// moveUp function
void Mario::moveUp() {
    y = y + 1;
}

// moveDown function
void Mario::moveDown() {
    y = y - 1;
}


>>>>>>> fcad4ea2971320e511db594d15b710186151257a
