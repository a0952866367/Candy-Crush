#include "vertical.h"

Vertical::Vertical(){

}

Vertical::~Vertical(){

}

int Vertical::state(blank *b[10][10], blank *me){
    int R = me->row;
    int C = me->col;
    int N = me->num;
    if( N>10 ) N /= 10;
    if( N!=0 && N!=5 ){
            if( R>=1 && R<=7 && ( N==b[R-1][C]->num || N==b[R-1][C]->num/10 )
                             && ( N==b[R+1][C]->num || N==b[R+1][C]->num/10 )
                             && ( N==b[R+2][C]->num || N==b[R+2][C]->num/10 ) ){
                return 1;
            }
            if( R>=2 && R<=8 && ( N==b[R-2][C]->num || N==b[R-2][C]->num/10 )
                             && ( N==b[R-1][C]->num || N==b[R-1][C]->num/10 )
                             && ( N==b[R+1][C]->num || N==b[R+1][C]->num/10 ) ){
                return 2;
            }
    }
    return 0;
}

void Vertical::spawn(blank *b[10][10], blank *me, int mode){
    int R = me->row;
    int C = me->col;
    int N = me->num;
    switch(mode){
    case 1:
        me->num = me->num*10 + 1;
        b[R-1][C]->num = 0;
        b[R+1][C]->num = 0;
        b[R+2][C]->num = 0;
        break;
    case 2:
        me->num = me->num*10 + 1;
        b[R-2][C]->num = 0;
        b[R-1][C]->num = 0;
        b[R+1][C]->num = 0;
        break;
    }
}
