#include "blank.h"

blank::blank(QWidget* parent,int R,int C):
    QObject(parent),row(R),col(C)
{
    button = new QPushButton(parent);
    button -> setGeometry(col*50,row*50,60,60);
    connect(button,SIGNAL(clicked()),this,SLOT(click()));
}

blank::~blank()
{

}

void blank::randomNum(){
    num = rand()%4+1;
    return;
}

void blank::setPicture(){
    switch (num){
    case 1:
        button -> setIcon( QIcon( QPixmap(":/icon/Orange_o.png") ) );
        button -> setIconSize(QSize(50,50));
        break;
    case 11:
        button -> setIcon( QIcon( QPixmap(":/icon/Orange_v.png") ) );
        button -> setIconSize(QSize(50,50));
        break;
    case 12:
        button -> setIcon( QIcon( QPixmap(":/icon/Orange_h.png") ) );
        button -> setIconSize(QSize(50,50));
        break;
    case 13:
        button -> setIcon( QIcon( QPixmap(":/icon/Orange_w.png") ) );
        button -> setIconSize(QSize(50,50));
        break;
    case 2:
        button -> setIcon( QIcon( QPixmap(":/icon/Purple_o.png") ) );
        button -> setIconSize(QSize(50,50));
        break;
    case 21:
        button -> setIcon( QIcon( QPixmap(":/icon/Purple_v.png") ) );
        button -> setIconSize(QSize(50,50));
        break;
    case 22:
        button -> setIcon( QIcon( QPixmap(":/icon/Purple_h.png") ) );
        button -> setIconSize(QSize(50,50));
        break;
    case 23:
        button -> setIcon( QIcon( QPixmap(":/icon/Purple_w.png") ) );
        button -> setIconSize(QSize(50,50));
        break;
    case 3:
        button -> setIcon( QIcon( QPixmap(":/icon/Yellow_o.png") ) );
        button -> setIconSize(QSize(50,50));
        break;
    case 31:
        button -> setIcon( QIcon( QPixmap(":/icon/Yellow_v.png") ) );
        button -> setIconSize(QSize(50,50));
        break;
    case 32:
        button -> setIcon( QIcon( QPixmap(":/icon/Yellow_h.png") ) );
        button -> setIconSize(QSize(50,50));
        break;
    case 33:
        button -> setIcon( QIcon( QPixmap(":/icon/Yellow_w.png") ) );
        button -> setIconSize(QSize(50,50));
        break;
    case 4:
        button -> setIcon( QIcon( QPixmap(":/icon/Green_o.png") ) );
        button -> setIconSize(QSize(50,50));
        break;
    case 41:
        button -> setIcon( QIcon( QPixmap(":/icon/Green_v.png") ) );
        button -> setIconSize(QSize(50,50));
        break;
    case 42:
        button -> setIcon( QIcon( QPixmap(":/icon/Green_h.png") ) );
        button -> setIconSize(QSize(50,50));
        break;
    case 43:
        button -> setIcon( QIcon( QPixmap(":/icon/Green_w.png") ) );
        button -> setIconSize(QSize(50,50));
        break;
    case 5:
        button -> setIcon( QIcon( QPixmap(":/icon/Bomb.png") ) );
        button -> setIconSize(QSize(50,50));
        break;
    default:
        button -> setIcon( QIcon( QPixmap("no picture") ) );
        break;
    }
}

void blank::operator+(blank *b){
    int temp;
    temp = b->num;
    b->num = num;
    num = temp;
    setPicture();
    b -> setPicture();
}

void blank::click(){
    emit clickSignal(row,col);
}
