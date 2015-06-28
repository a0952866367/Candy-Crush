#include "ver.h"

Ver::Ver()
{

}

Ver::~Ver()
{

}

int Ver::state(blank *b[10][10], blank *me)
{
    int R = me->row;
    int C = me->col;
    int N = me->num;
    if( N>10 ) N /= 10;
    if( N!=0 && N!=5 ){
            if( R<=7 && ( N==b[R+1][C]->num || N==b[R+1][C]->num/10 )
                     && ( N==b[R+2][C]->num || N==b[R+2][C]->num/10 ) ){
                return 1;
            }
            if( R>=1 && R<=8 && ( N==b[R-1][C]->num || N==b[R-1][C]->num/10 )
                             && ( N==b[R+1][C]->num || N==b[R+1][C]->num/10 ) ){
                return 2;
            }
            if( R>=2 && ( N==b[R-1][C]->num || N==b[R-1][C]->num/10 )
                     && ( N==b[R-2][C]->num || N==b[R-2][C]->num/10 ) ){
                return 3;
            }
    }
    return 0;
}

void Ver::spawn(blank *b[10][10], blank *me, int mode)
{
    int R = me->row;
    int C = me->col;
    int N = me->num;
    switch(mode){
    case 1:
        me->num = 0;
        b[R+1][C]->num = 0;
        b[R+2][C]->num = 0;
        break;
    case 2:
        me->num = 0;
        b[R-1][C]->num = 0;
        b[R+1][C]->num = 0;
        break;
    case 3:
        me->num = 0;
        b[R-1][C]->num = 0;
        b[R-2][C]->num = 0;
        break;
    }
}

