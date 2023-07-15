#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QtGui>
class dialog1 : public QDialog
{
Q_OBJECT
private:
        QLineEdit* editW;
        QLineEdit* editH;
        QLineEdit* editAng;
        QLineEdit* editQ;
        QLineEdit* editX;
        QLineEdit* editAR;
        QLineEdit* editBR;
        QLineEdit* editCR;


        QPushButton* left;
        QPushButton* right;

        int w;
        int h;
        int ang;
        int q;
        int x;
        int ar;
        int br;
        int cr;
        int direct;

    public:
        dialog1();

        void setEdit(int w, int h, int ang, int q, int x, int ar, int br, int cr);

        bool isRight();

        int getW();
        int getH();
        int getAngle();
        int getQ();
        int getX();
        int getAR();
        int getBR();
        int getCR();
        int getDirect();

public slots:
    void leftClick();
    void rightClick();
    
};

#endif // DIALOG_H
