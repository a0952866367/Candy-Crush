#ifndef BLANK_H
#define BLANK_H
#include<QObject>
#include<QPushButton>
#include<QPixmap>

class blank:public QObject
{
    Q_OBJECT

public:
    explicit blank( QWidget *parent , int R , int C );
    ~blank();
    QPushButton *button;
    const int row;
    const int col;
    int num;
    void randomNum();
    void setPicture();
    void operator+(blank *b);

public slots:
    void click();

signals:
    void clickSignal(int R,int C);
};

#endif // BLANK_H
