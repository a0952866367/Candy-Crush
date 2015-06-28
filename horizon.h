#ifndef HORIZON_H
#define HORIZON_H
#include"destroy.h"

class Horizon:public Destroy
{
public:
    Horizon();
    virtual ~Horizon();
    virtual int state(blank *b[10][10],blank *me);
    virtual void spawn(blank *b[10][10],blank *me,int mode);
};

#endif // HORIZON_H
