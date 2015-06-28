#ifndef HOR_H
#define HOR_H
#include"destroy.h"

class Hor:public Destroy
{
public:
    Hor();
    virtual ~Hor();
    virtual int state(blank *b[10][10],blank *me);
    virtual void spawn(blank *b[10][10],blank *me,int mode);
};

#endif // HOR_H
