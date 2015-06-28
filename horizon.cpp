#include "horizon.h"

Horizon::Horizon()
{

}

Horizon::~Horizon()
{

}

int Horizon::state(blank *b[10][10], blank *me){
    int R = me->row;
    int C = me->col;
    int N = me->num;
    if( N>10 ) N /= 10;
    if( N!=0 && N!=5 ){
            if( R>=1 && R<=7 && ( N==b[R][C-1]->num || N==b[R][C-1]->num/10 )
                             && ( N==b[R][C+1]->num || N==b[R][C+1]->num/10 )
                             && ( N==b[R][C+2]->num || N==b[R][C+2]->num/10 ) ){
                return 1;
            }
            if( R>=2 && R<=8 && ( N==b[R][C-2]->num || N==b[R][C-2]->num/10 )
                             && ( N==b[R][C-1]->num || N==b[R][C-1]->num/10 )
                             && ( N==b[R][C+1]->num || N==b[R][C+1]->num/10 ) ){
                return 2;
            }
    }
    return 0;
}

void Horizon::spawn(blank *b[10][10], blank *me, int mode){
    int R = me->row;
    int C = me->col;
    int N = me->num;
    switch(mode){
    case 1:
        me->num = me->num*10 + 2;
        b[R][C-1]->num = 0;
        b[R][C+1]->num = 0;
        b[R][C+2]->num = 0;
        break;
    case 2:
        me->num = me->num*10 + 2;
        b[R][C-2]->num = 0;
        b[R][C-1]->num = 0;
        b[R][C+1]->num = 0;
        break;
    }
}

