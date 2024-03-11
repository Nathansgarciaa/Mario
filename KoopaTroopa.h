#ifndef KOOPATROOPA_H
#define KOOPATROOPA_H
#include <iostream>
using namespace std;

class Mario;
class World;
class ostream;

class KoopaTroopa{
public:
    KoopaTroopa();
    ~KoopaTroopa();
    void interaction(std::ostream &outputStream, Mario &mario, World &world);
};

#endif
