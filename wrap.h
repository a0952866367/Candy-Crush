#ifndef WRAP_H
#define WRAP_H
#include"destroy.h"

class Wrap:public Destroy
{
public:
    Wrap();
    virtual ~Wrap();
    virtual int state(blank *b[10][10],blank *me);
    virtual void spawn(blank *b[10][10],blank *me,int mode);
};

#endif // WRAP_H
