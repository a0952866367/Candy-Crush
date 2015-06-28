#ifndef BOMB_H
#define BOMB_H
#include"destroy.h"

class Bomb:public Destroy
{
public:
    Bomb();
    virtual ~Bomb();
    virtual int state(blank *b[10][10],blank *me);
    virtual void spawn(blank *b[10][10],blank *me,int mode);
};

#endif // BOMB_H
