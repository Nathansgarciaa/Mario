#ifndef KOOPATROOPA_H
#define KOOPATROOPA_H

#include <ctime>
#include <random>

class KoopaTroopa{
    public: 
        KoopaTroopa();
        ~KoopaTroopa();
        bool interaction();
        char getValue(){return 'k';};
};

#endif
