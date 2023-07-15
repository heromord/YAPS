#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <string>
#include <QTextEdit>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QTime>
#include <QDate>
#include <QTextCursor>
#include <QRect>
#include <QMenu>
#include <QAction>
#include <QList>
#include <QMouseEvent>

class TextEdit : public QTextEdit
{
    Q_OBJECT
private:
QString fileName;
bool Change_Flag;
QAction* SelectStr;
QAction* Select;
public:
    TextEdit(QWidget *parent = 0);
    QString GetName();
    bool GetCh_Fl();
    void SetCh_Fl(bool fl);
    std::string svfale;
    int SimbNumb;
    int WordNumb;
    int Lines;
    double FSize;
    QTime time;
    QDate date;
protected:
void  contextMenuEvent(QContextMenuEvent *event);
public slots:
    void ssaveHow();
    void ssave();
    void oopen();
    void New();
    void Selllect();
    void SelectStri();
};

#endif // TEXTEDIT_H
