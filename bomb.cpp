#include "bomb.h"

Bomb::Bomb()
{

}

Bomb::~Bomb()
{

}

int Bomb::state(blank *b[10][10], blank *me){
    int R = me->row;
    int C = me->col;
    int N = me->num;
    if( N>10 ) N /= 10;
    if( N!=0 && N!=5 ){
            if( R>=2 && R<=7 && ( N==b[R-2][C]->num || N==b[R-2][C]->num/10 )
                             && ( N==b[R-1][C]->num || N==b[R-1][C]->num/10 )
                             && ( N==b[R+1][C]->num || N==b[R+1][C]->num/10 )
                             && ( N==b[R+2][C]->num || N==b[R+2][C]->num/10 ) ){
                return 1;
            }
            if( C>=2 && C<=7 && ( N==b[R][C-2]->num || N==b[R][C-2]->num/10 )
                             && ( N==b[R][C-1]->num || N==b[R][C-1]->num/10 )
                             && ( N==b[R][C+1]->num || N==b[R][C+1]->num/10 )
                             && ( N==b[R][C+2]->num || N==b[R][C+2]->num/10 ) ){
                return 2;
            }
    }
    return 0;
}

void Bomb::spawn(blank *b[10][10], blank *me, int mode){
    int R = me->row;
    int C = me->col;
    int N = me->num;
    switch(mode){
    case 1:
        me->num = 5;
        b[R-2][C]->num = 0;
        b[R-1][C]->num = 0;
        b[R+1][C]->num = 0;
        b[R+2][C]->num = 0;
        if( C>=2 && ( N==b[R][C-2]->num || N==b[R][C-2]->num/10 )
                 && ( N==b[R][C-1]->num || N==b[R][C-1]->num/10 ) ){
            b[R][C-2]->num = 0;
            b[R][C-1]->num = 0;
        }
        if( C<=7 && ( N==b[R][C+2]->num || N==b[R][C+2]->num/10 )
                 && ( N==b[R][C+1]->num || N==b[R][C+1]->num/10 ) ){
            b[R][C+2]->num = 0;
            b[R][C+1]->num = 0;
        }

        break;
    case 2:
        me->num = 5;
        b[R][C-2]->num = 0;
        b[R][C-1]->num = 0;
        b[R][C+1]->num = 0;
        b[R][C+2]->num = 0;
        if( R>=2 && ( N==b[R-2][C]->num || N==b[R-2][C]->num/10 )
                 && ( N==b[R-1][C]->num || N==b[R-1][C]->num/10 ) ){
            b[R-2][C]->num = 0;
            b[R-1][C]->num = 0;
        }
        if( R<=7 && ( N==b[R+2][C]->num || N==b[R+2][C]->num/10 )
                 && ( N==b[R+1][C]->num || N==b[R+1][C]->num/10 ) ){
            b[R+1][C]->num = 0;
            b[R+2][C]->num = 0;
        }
        break;
    }
}

