#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <info.h>
#include <textedit.h>
#include <find.h>
#include <findandreplace.h>
#include <texthigligt.h>

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QWidget>
#include <QApplication>
#include <QToolBar>
#include <QStatusBar>
#include <QTimer>
#include <QFont>
#include <QColor>
#include <QColorDialog>
#include <QFontDialog>
#include <QPalette>
#include <QPainter>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
QAction* Newf;
QAction* Sawe;
QAction* Openf;
QAction* SaweHow;
QAction* Exit;
QAction* Cancelf;
QAction* Repeat;
QAction* CopyC ;
QAction* CutC;
QAction* PasteC;
QAction* FindC ;
QAction* FindAndReplace;
QAction* SelectAllC;
QAction* InfoM;
QAction* Hyphenation;
QAction* FontSelect;
QAction* BackdColor;
QAction* LineColor;
QAction* Numeration;
QAction* ToolB;
QAction* StB;
QAction* SyntaLight;
QAction* Synta;
QAction* SyntaC89;
QAction* SyntaCu98;
QAction* SyntaCu1114;
QAction* Editing;
QAction* ChangeEd;
QAction* DownloadEd;
QAction* DefaultEd;
QAction* AvailableStyles;
QAction* FirstSt;
QAction* SecondSt;
QAction* ThirdSt;
QToolBar* toolbar;
TextEdit* redac;
QString WinName;
QString WinName32;
QTimer timer;
QColor WinColor;
QColor LineCColor;
int SimbNumb;
int WordNumb;
int Lines;
double FSize;
QLabel* firstS;
QLabel* secondS;
QLabel* thirdS;
QTime time;
QDate date;
QFont font;
int cur_X;
int cur_Y;
QString standart;
Highlighter* highlighter;
int style;
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QMenu* CreateMenuFiel();
    QMenu* CreateMenuCorrection();
    QMenu* CreateMenuInfo();
    QMenu* CreateMenuFormat();
    QMenu* CreateMenuView();
    QToolBar* createToolBar();
    void createStBar();
public slots:
    void Modal();
    void VisibleToolB();
    void VisibleStatusB();
    void ChooseSyntaC();
    void ChooseSyntaCu();
    void ChooseSyntaCu11();
    void ReName();
    void TextChanged();
    void SetWinColor();
    void SetLineColor();
    void SetFFont();
    void DateTime();
    void WordWrap();
    void Ffind();
    void FindAndRep();
    void Def();
    void fer();
    void sec();
    void thri();
    void pods();
    void numerat();
};

#endif // MAINWINDOW_H
