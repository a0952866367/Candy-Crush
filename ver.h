#ifndef VER_H
#define VER_H
#include"destroy.h"

class Ver:public Destroy
{
public:
    Ver();
    virtual ~Ver();
    virtual int state(blank *b[10][10],blank *me);
    virtual void spawn(blank *b[10][10],blank *me,int mode);
};

#endif // VER_H
