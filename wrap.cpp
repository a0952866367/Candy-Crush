#include "wrap.h"

Wrap::Wrap(){

}

Wrap::~Wrap(){

}

int Wrap::state(blank *b[10][10], blank *me){
    int R = me->row;
    int C = me->col;
    int N = me->num;
    if( N>10 ) N /= 10;
    if( N!=0 && N!=5 ){
            if( R>=2 && C>=2 && ( N==b[R-2][C]->num || N==b[R-2][C]->num/10 )
                             && ( N==b[R-1][C]->num || N==b[R-1][C]->num/10 )
                             && ( N==b[R][C-1]->num || N==b[R][C-1]->num/10 )
                             && ( N==b[R][C-2]->num || N==b[R][C-2]->num/10 ) ){
                return 1;
            }
            if( R<=7 && C>=2 && ( N==b[R][C-1]->num || N==b[R][C-1]->num/10 )
                             && ( N==b[R][C-2]->num || N==b[R][C-2]->num/10 )
                             && ( N==b[R+1][C]->num || N==b[R+1][C]->num/10 )
                             && ( N==b[R+2][C]->num || N==b[R+2][C]->num/10 ) ){
                return 2;
            }
            if( R>=2 && C<=7 && ( N==b[R-2][C]->num || N==b[R-2][C]->num/10 )
                             && ( N==b[R-1][C]->num || N==b[R-1][C]->num/10 )
                             && ( N==b[R][C+1]->num || N==b[R][C+1]->num/10 )
                             && ( N==b[R][C+2]->num || N==b[R][C+2]->num/10 ) ){
                return 3;
            }
            if( R<=7 && C<=7 && ( N==b[R+2][C]->num || N==b[R+2][C]->num/10 )
                             && ( N==b[R+1][C]->num || N==b[R+1][C]->num/10 )
                             && ( N==b[R][C+1]->num || N==b[R][C+1]->num/10 )
                             && ( N==b[R][C+2]->num || N==b[R][C+2]->num/10 ) ){
                return 4;
            }
            if( R>=1 && R<=8 && C>=2 && ( N==b[R][C-2]->num || b[R][C-2]->num/10 )
                                     && ( N==b[R][C-1]->num || b[R][C-1]->num/10 )
                                     && ( N==b[R-1][C]->num || b[R-1][C]->num/10 )
                                     && ( N==b[R+1][C]->num || b[R+1][C]->num/10 ) ){
                return 5;
            }
            if( R>=1 && R<=8 && C<=7 && ( N==b[R][C+2]->num || b[R][C+2]->num/10 )
                                     && ( N==b[R][C+1]->num || b[R][C+1]->num/10 )
                                     && ( N==b[R-1][C]->num || b[R-1][C]->num/10 )
                                     && ( N==b[R+1][C]->num || b[R+1][C]->num/10 ) ){
                return 6;
            }
            if( R>=2 && C>=1 && C<=8 && ( N==b[R-2][C]->num || b[R-2][C]->num/10 )
                                     && ( N==b[R-1][C]->num || b[R-1][C]->num/10 )
                                     && ( N==b[R][C-1]->num || b[R][C-1]->num/10 )
                                     && ( N==b[R][C+1]->num || b[R][C+1]->num/10 ) ){
                return 7;
            }
            if( R<=7 && C>=1 && C<=8 && ( N==b[R][C+1]->num || b[R][C+1]->num/10 )
                                     && ( N==b[R][C-1]->num || b[R][C-1]->num/10 )
                                     && ( N==b[R+1][C]->num || b[R+1][C]->num/10 )
                                     && ( N==b[R+2][C]->num || b[R+2][C]->num/10 ) ){
                return 8;
            }
    }
    return 0;
}

void Wrap::spawn(blank *b[10][10], blank *me, int mode){
    int R = me->row;
    int C = me->col;
    int N = me->num;
    switch(mode){
    case 1:
        me->num = me->num*10 + 3;
        b[R-2][C]->num = 0;
        b[R-1][C]->num = 0;
        b[R][C-1]->num = 0;
        b[R][C-2]->num = 0;
        if( C<=8 && ( N==b[R][C+1]->num || N==b[R][C+1]->num/10 ) ){
            b[R][C+1]->num = 0;
        }
        if( R<=8 && ( N==b[R+1][C]->num || N==b[R+1][C]->num/10 ) ){
            b[R+1][C]->num = 0;
        }
        break;
    case 2:
        me->num = me->num*10 + 3;
        b[R][C-1]->num = 0;
        b[R][C-2]->num = 0;
        b[R+1][C]->num = 0;
        b[R+2][C]->num = 0;
        if( R>=1 && ( N==b[R-1][C]->num || N==b[R-1][C]->num/10 ) ){
            b[R-1][C]->num = 0;
        }
        if( C<=8 && ( N==b[R][C+1]->num || N==b[R][C+1]->num/10 ) ){
            b[R][C+1]->num = 0;
        }
        break;
    case 3:
        me->num = me->num*10 + 3;
        b[R-2][C]->num = 0;
        b[R-1][C]->num = 0;
        b[R][C+1]->num = 0;
        b[R][C+2]->num = 0;
        if( C>=1 && ( N==b[R][C-1]->num || N==b[R][C-1]->num/10 ) ){
            b[R][C-1]->num = 0;
        }
        if( R<=8 && ( N==b[R+1][C]->num || N==b[R+1][C]->num/10 ) ){
            b[R+1][C]->num = 0;
        }
        break;
    case 4:
        me->num = me->num*10 + 3;
        b[R+2][C]->num = 0;
        b[R+1][C]->num = 0;
        b[R][C+1]->num = 0;
        b[R][C+2]->num = 0;
        if( R>=1 && ( N==b[R-1][C]->num || N==b[R-1][C]->num/10 ) ){
            b[R-1][C]->num = 0;
        }
        if( C>=1 && ( N==b[R][C-1]->num || N==b[R][C-1]->num/10 ) ){
            b[R][C-1]->num = 0;
        }
        break;
    case 5:
        me->num = me->num*10 + 3;
        b[R][C-2]->num = 0;
        b[R][C-1]->num = 0;
        b[R-1][C]->num = 0;
        b[R+1][C]->num = 0;
        break;
    case 6:
        me->num = me->num*10 + 3;
        b[R][C+2]->num = 0;
        b[R][C+1]->num = 0;
        b[R-1][C]->num = 0;
        b[R+1][C]->num = 0;
        break;
    case 7:
        me->num = me->num*10 + 3;
        b[R-2][C]->num = 0;
        b[R-1][C]->num = 0;
        b[R][C-1]->num = 0;
        b[R][C+1]->num = 0;
        break;
    case 8:
        me->num = me->num*10 + 3;
        b[R][C+1]->num = 0;
        b[R][C-1]->num = 0;
        b[R+1][C]->num = 0;
        b[R+2][C]->num = 0;
        break;
    }
}
