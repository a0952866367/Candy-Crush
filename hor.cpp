#include "hor.h"

Hor::Hor()
{

}

Hor::~Hor()
{

}

int Hor::state(blank *b[10][10], blank *me)
{
    int R = me->row;
    int C = me->col;
    int N = me->num;
    if( N>10 ) N /= 10;
    if( N!=0 && N!=5 ){
            if( C<=7 && ( N==b[R][C+1]->num || N==b[R][C+1]->num/10 )
                     && ( N==b[R][C+2]->num || N==b[R][C+2]->num/10 ) ){
                return 1;
            }
            if( C>=1 && C<=8 && ( N==b[R][C-1]->num || N==b[R][C-1]->num/10 )
                             && ( N==b[R][C+1]->num || N==b[R][C+1]->num/10 ) ){
                return 2;
            }
            if( C>=2 && ( N==b[R][C-1]->num || N==b[R][C-1]->num/10 )
                     && ( N==b[R][C-2]->num || N==b[R][C-2]->num/10 ) ){
                return 3;
            }
    }
    return 0;
}

void Hor::spawn(blank *b[10][10], blank *me, int mode)
{
    int R = me->row;
    int C = me->col;
    int N = me->num;
    switch(mode){
    case 1:
        me->num = 0;
        b[R][C+1]->num = 0;
        b[R][C+2]->num = 0;
        break;
    case 2:
        me->num = 0;
        b[R][C-1]->num = 0;
        b[R][C+1]->num = 0;
        break;
    case 3:
        me->num = 0;
        b[R][C-1]->num = 0;
        b[R][C-2]->num = 0;
        break;
    }
}
