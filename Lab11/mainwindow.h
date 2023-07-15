#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QToolBar>
#include <QActionGroup>
#include <QPalette>
#include <QPushButton>
#include <Figure1.h>
#include <Figure2.h>
#include <vector>
#include <QTimer>
#include <iterator>
using namespace std;
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
private:
    vector <Figure1*> Figures1;
    vector <Figure2*> Figures2;
    bool firstB;
    bool secondB;
    bool fl_resize;

    QPushButton*fig1;
    QPushButton*fig2;
    QPushButton* AdF;
    QPushButton*DelF;

    QToolBar* createToolBar();
    Figure1* createFigure1();
    Figure2* createFigure2();

    QTimer timer;
public:
    MainWindow();
    ~MainWindow();
 public slots:
 void ButtonToggled1(bool st);
 void ButtonToggled2(bool st);
 void AdButton();
 void DelEnable();
 void DelButton();
protected:
    void resizeEvent(QResizeEvent* event);
};

#endif // MAINWINDOW_H
