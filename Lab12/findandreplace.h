#ifndef FINDANDREPLACE_H
#define FINDANDREPLACE_H

#include <QDialog>
#include <QLabel>
#include <QBoxLayout>
#include <QString>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
class FindAndReplac : public QDialog
{
    Q_OBJECT
private:
    QLabel* LFind;
    QLabel* RFind;
    QLineEdit* FindF;
    QLineEdit* FindR;
    QPushButton* btnOk;
    QPushButton* btnClose;
public:
   FindAndReplac(QWidget *parent = 0);
   QString GetFind();
   QString GetReplace();
    
public slots:
    
};

#endif // FINDANDREPLACE_H
