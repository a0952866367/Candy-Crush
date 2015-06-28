#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTimer>
#include "blank.h"
#include "destroy.h"
#include "bomb.h"
#include "wrap.h"
#include "vertical.h"
#include "horizon.h"
#include "ver.h"
#include "hor.h"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void gameStart();
    bool judge( int r1 , int c1 , int r2 , int c2 );
    bool judgeBomb( int R , int C );
    bool judgeBlock( int R , int C );
    bool judgeVertical( int R , int C );
    bool judgeHorizon( int R , int C );
    bool judgeVer( int R , int C );
    bool judgeHor( int R , int C );
    void refresh();
    void fillZero();
    void bornZero();
    bool fallCheck();
    int score;
    int best;
    int step;
    int star;


public slots:
    void buttonClick(int R,int C);

private:
    Ui::MainWindow *ui;
    blank *b[10][10];
    int clickR;
    int clickC;
    int firstClick;
    Destroy *del;
signals:
    void quit( int star,int score);
};

#endif // MAINWINDOW_H
