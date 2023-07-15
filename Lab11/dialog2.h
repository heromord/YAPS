#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>
#include <QLabel>
#include <QtGui>
class dialog2 : public QDialog
{
Q_OBJECT
private:
        QLineEdit* editW;
        QLineEdit* editH;
        QLineEdit* editAng;
        QLineEdit* editP;
        QLineEdit* editBX;
        QLineEdit* editCX;
        QLineEdit* editDX;


        QPushButton* left;
        QPushButton* right;

        int w;
        int h;
        int ang;
        int p;
        int bx;
        int cx;
        int dx;
        int direct;

    public:
        dialog2();

        void setEdit(int w, int h, int ang, int p, int bx, int cx, int dx);

        bool isRight();

        int getW();
        int getH();
        int getAngle();
        int getP();
        int getBX();
        int getCX();
        int getDX();
        int getDirect();

public slots:
    void leftClick();
    void rightClick();

};

#endif // DIALOG2_H
