#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),score(0),step(10),star(0),
    ui(new Ui::MainWindow)
{   srand( (unsigned)time(NULL) );
    ui->setupUi(this);
    ui->currStep->display(step);
    this->setMaximumSize(620,510);
    this->setMinimumSize(620,510);

    for( int i=0 ; i<10 ; i++ ){
        for( int j=0 ; j<10 ; j++ ){
            b[i][j] = new blank(this,i,j);
            connect( b[i][j] , SIGNAL( clickSignal(int,int) ) , this , SLOT( buttonClick(int,int) ) );

        }
    }
}

MainWindow::~MainWindow()
{
    emit quit(star,score);
    delete ui;
}

void MainWindow::gameStart(){
    firstClick = 0;
    for( int i=0 ; i<10 ; i++ ){
        for( int j=0 ; j<10 ; j++ ){
            b[i][j] -> randomNum();
            b[i][j] -> setPicture();
            if( j>=2 && b[i][j]->num==b[i][j-1]->num && b[i][j]->num==b[i][j-2]->num ){
                j--;//row ckeck
            }
            if( i>=2 && b[i][j]->num==b[i-1][j]->num && b[i][j]->num==b[i-2][j]->num ){
                j--;//column check
            }
        }
    }
}

bool MainWindow::judge( int r1 , int c1 , int r2 , int c2 ){
    bool judgeArray[12];
    judgeArray[0] = judgeBomb(r1,c1);
    judgeArray[1] = judgeBomb(r2,c2);
    judgeArray[2] = judgeBlock(r1,c1);
    judgeArray[3] = judgeBlock(r2,c2);
    judgeArray[4] = judgeVertical(r1,c1);
    judgeArray[5] = judgeVertical(r2,c2);
    judgeArray[6] = judgeHorizon(r1,c1);
    judgeArray[7] = judgeHorizon(r2,c2);
    judgeArray[8] = judgeVer(r1,r2);
    judgeArray[9] = judgeVer(r2,c2);
    judgeArray[10] = judgeHor(r1,c1);
    judgeArray[11] = judgeHor(r2,c2);
    refresh();
    fillZero();
    bornZero();
    refresh();
    for( int i=0 ; i<12 ; i++ ){
        if( judgeArray[i]==true )
            return true;
    }
    return false;
}

bool MainWindow::judgeBomb( int R, int C ){
    int bombState;
    bool spawned = false;
    del = new Bomb;
    bombState = del->state(b,b[R][C]);
    if( bombState>0 ){
        switch (bombState) {
        case 1:
            del->spawn(b,b[R][C],1);
            spawned = true;
            score+=50;
            break;
        case 2:
            del->spawn(b,b[R][C],2);
            spawned = true;
            score+=50;
            break;
        case 3:
            del->spawn(b,b[R][C],3);
            spawned = true;
            score+=50;
            break;
        case 4:
            del->spawn(b,b[R][C],4);
            spawned = true;
            score+=50;
            break;
        }
    }
    delete del;
    return spawned;
}

bool MainWindow::judgeBlock(int R, int C){
    int blockState;
    bool spawned = false;
    del = new Wrap;
    blockState = del->state(b,b[R][C]);
    if( blockState>0 ){
        switch (blockState) {
        case 1:
            del->spawn(b,b[R][C],1);
            spawned = true;
            score+=30;
            break;
        case 2:
            del->spawn(b,b[R][C],2);
            spawned = true;
            score+=30;
            break;
        case 3:
            del->spawn(b,b[R][C],3);
            spawned = true;
            score+=30;
            break;
        case 4:
            del->spawn(b,b[R][C],4);
            spawned = true;
            score+=30;
            break;
        case 5:
            del->spawn(b,b[R][C],5);
            spawned = true;
            score+=30;
            break;
        case 6:
            del->spawn(b,b[R][C],6);
            spawned = true;
            score+=30;
            break;
        case 7:
            del->spawn(b,b[R][C],7);
            spawned = true;
            score+=30;
            break;
        case 8:
            del->spawn(b,b[R][C],8);
            spawned = true;
            score+=30;
            break;
        }
    }
    delete del;
    return spawned;
}

bool MainWindow::judgeVertical(int R, int C){
    int VState;
    bool spawned = false;
    del = new Vertical;
    VState = del->state(b,b[R][C]);
    if( VState>0 ){
        switch (VState) {
            case 1:
                del->spawn(b,b[R][C],1);
                spawned = true;
                score+=20;
                break;
            case 2:
                del->spawn(b,b[R][C],2);
                spawned = true;
                score+=20;
                break;
        }
    }
    delete del;
    return spawned;
}

bool MainWindow::judgeHorizon(int R, int C){
    int HState;
    bool spawned = false;
    del = new Horizon;
    HState = del->state(b,b[R][C]);
    if( HState>0 ){
        switch (HState) {
            case 1:
                del->spawn(b,b[R][C],1);
                spawned = true;
                score+=20;
                break;
            case 2:
                del->spawn(b,b[R][C],2);
                spawned = true;
                score+=20;
                break;
        }
    }
    delete del;
    return spawned;
}

bool MainWindow::judgeVer(int R, int C)
{
    int VState;
    bool spawned = false;
    del = new Ver;
    VState = del->state(b,b[R][C]);
    if( VState>0 ){
        switch (VState) {
            case 1:
                del->spawn(b,b[R][C],1);
                spawned = true;
                score+=7;
                break;
            case 2:
                del->spawn(b,b[R][C],2);
                spawned = true;
                score+=7;
                break;
            case 3:
                del->spawn(b,b[R][C],3);
                spawned = true;
                score+=7;
                break;
        }
    }
    delete del;
    return spawned;
}

bool MainWindow::judgeHor(int R, int C)
{
    int HState;
    bool spawned = false;
    del = new Hor;
    HState = del->state(b,b[R][C]);
    if( HState>0 ){
        switch (HState) {
            case 1:
                del->spawn(b,b[R][C],1);
                spawned = true;
                score+=7;
                break;
            case 2:
                del->spawn(b,b[R][C],2);
                spawned = true;
                score+=7;
                break;
            case 3:
                del->spawn(b,b[R][C],3);
                spawned = true;
                score+=7;
                break;
        }
    }
    delete del;
    return spawned;
}

void MainWindow::refresh(){
    for( int i=0 ; i<10 ; i++ ){
        for( int j=0 ; j<10 ; j++ ){
            b[i][j] -> setPicture();
        }
    }
    ui->currStep->display(step);
    ui->currS->display(score);
    if( score>best ){
        best = score;
        ui->bestS->display(best);
    }
    if( score<200 ) star = 0;
    if( score>=200 && score<400 ) star = 1;
    if( score>=400 && score<700 ) star = 2;
    if( score>=1000 ) star = 3;
}

void MainWindow::fillZero()
{
    do{
        refresh();
        for( int i=9 ; i>=0 ; i-- ){
            for( int j=9 ; j>=0 ; j-- ){
                if( b[i][j]->num==0 ){
                    for( int k=i ; k>=0 ; k-- ){
                        if( b[k][j]->num!=0 ){
                            b[i][j]->num = b[k][j]->num;
                            b[k][j]->num = 0;
                            break;
                        }
                    }
                }
            }
        }
        refresh();
    }while( fallCheck()==true );
}

void MainWindow::bornZero()
{
    bool goin = true;
    do{
        for( int i=9 ; i>=0 ; i-- ){
            for( int j=9 ; j>=0 ; j-- ){
                if( b[i][j]->num==0 ){
                    b[i][j] -> randomNum();
                    b[i][j] -> setPicture();
                }
            }
        }
        goin = fallCheck();
    }while(goin==true);
}

bool MainWindow::fallCheck()
{
    bool result = false;
    for( int i=0 ; i<10 ; i++ ){
        for( int j=0 ; j<10 ; j++ ){
            if( judgeBomb(i,j) )
                result = true;
        }
    }
    for( int i=0 ; i<10 ; i++ ){
        for( int j=0 ; j<10 ; j++ ){
            if( judgeBlock(i,j) )
                result = true;
        }
    }
    for( int i=0 ; i<10 ; i++ ){
        for( int j=0 ; j<10 ; j++ ){
            if( judgeVertical(i,j) )
                result = true;
        }
    }
    for( int i=0 ; i<10 ; i++ ){
        for( int j=0 ; j<10 ; j++ ){
            if( judgeHorizon(i,j) )
                result = true;
        }
    }
    for( int i=0 ; i<10 ; i++ ){
        for( int j=0 ; j<10 ; j++ ){
            if( judgeVer(i,j) )
                result = true;
        }
    }
    for( int i=0 ; i<10 ; i++ ){
        for( int j=0 ; j<10 ; j++ ){
            if( judgeHor(i,j) )
                result = true;
        }
    }
    refresh();
    return result;
}

void MainWindow::buttonClick(int R, int C){
    if( firstClick!=1 ){
        clickC = C;
        clickR = R;
        firstClick = 1;
    }
    else{
        if( clickR==R && clickC==C-1 ){
            *b[clickR][clickC]+b[R][C];
            step--;
            if( step==0 ) {
                emit quit(star,score);
                this->close();
            }
            if( !judge(clickR,clickC,R,C) ){
                *b[clickR][clickC]+b[R][C];
                step++;
            }
        }
        else if( clickR==R && clickC==C+1 ){
            *b[clickR][clickC]+b[R][C];
            step--;
            if( step==0 ) {
                emit quit(star,score);
                this->close();
            }
            if( !judge(clickR,clickC,R,C) ){
                *b[clickR][clickC]+b[R][C];
                step++;
            }
        }
        else if( clickR==R-1 && clickC==C ){
            *b[clickR][clickC]+b[R][C];
            step--;
            if( step==0 ) {
                emit quit(star,score);
                this->close();
            }
            if( !judge(clickR,clickC,R,C) ){
                *b[clickR][clickC]+b[R][C];
                step++;
            }
        }
        else if( clickR==R+1 && clickC==C ){
            *b[clickR][clickC]+b[R][C];
            step--;
            if( step==0 ) {
                emit quit(star,score);
                this->close();
            }
            if( !judge(clickR,clickC,R,C) ){
                *b[clickR][clickC]+b[R][C];
                step++;
            }
        }
        firstClick = 0;
    }
}
