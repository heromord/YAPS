#ifndef PAINTFIGURE_H
#define PAINTFIGURE_H
#include <QPainter>
#include <QWidget>
#include <QPainter>
#include <QWidget>
#include <QMouseEvent>
#include <cmath>
#include<dialog1.h>
class Figure1 : public QWidget {
Q_OBJECT
  private:
    int Q;
    int H;
    int W;
    int x;
    int AR;
    int BR;
    int CR;
    int ang;
    int WinW;
    int WinH;
    int direct;
    bool BlueLight;
    QPoint ofset;

public:
    Figure1(int W,int H,int Q,int x,int AR,int BR,int CR,int WinW,int WinH,QWidget *parent=0);
    ~Figure1();
    void Resize(int WinW,int WinH);
    bool GetBlue();
    void UpDate(int W,int H,int ang,int Q,int x,int AR,int BR,int CR);

protected:
   void paintEvent(QPaintEvent *event);
   void mousePressEvent(QMouseEvent* event);
   void mouseMoveEvent(QMouseEvent* event);
};

#endif // PAINTFIGURE_H
