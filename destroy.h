#ifndef DESTROY_H
#define DESTROY_H
#include"blank.h"

class Destroy
{
public:
    Destroy();
    ~Destroy();
    virtual int state(blank *b[10][10],blank *me) = 0;
    virtual void spawn(blank *b[10][10],blank *me,int mode) = 0;
};

#endif // DESTROY_H
