#ifndef FIGURE2_H
#define FIGURE2_H

#include <QPainter>
#include <QWidget>
#include <QPainter>
#include <QWidget>
#include <QMouseEvent>
#include <cmath>
#include <dialog2.h>
class Figure2 : public QWidget
{
Q_OBJECT
      private:
        int H;
        int W;
        int P;
        int BX;
        int CX;
        int DX;
        int ang;
        int WinW;
        int WinH;
        int direct;
        bool BlueLight;
        QPoint ofset;
     public:
        Figure2(int W,int H,int P,int BX,int CX,int DX,int WinW,int WinH,QWidget *parent=0);
         ~Figure2();
        void Resize(int WinW,int WinH);
        bool GetBlue();
        void UpDate(int W,int H,int ang,int P,int BX,int CX,int DX);

     protected:
        void paintEvent(QPaintEvent *event);
        void mousePressEvent(QMouseEvent* event);
        void mouseMoveEvent(QMouseEvent* event);
};

#endif // FIGURE2_H
