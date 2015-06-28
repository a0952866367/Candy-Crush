#ifndef VERTICAL_H
#define VERTICAL_H
#include"destroy.h"

class Vertical:public Destroy
{
public:
    Vertical();
    virtual ~Vertical();
    virtual int state(blank *b[10][10],blank *me);
    virtual void spawn(blank *b[10][10],blank *me,int mode);
};

#endif // VERTICAL_H
