#ifndef FIND_H
#define FIND_H

#include <QDialog>
#include <QLabel>
#include <QBoxLayout>
#include <QString>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
class Find : public QDialog
{
    Q_OBJECT
private:
    QLabel* FindL;
    QLineEdit* FindE;
    QPushButton* btnOk;
    QPushButton* btnClose;
public:
   Find(QWidget *parent = 0);
   QString GetFind();
};

#endif // FIND_H
