#ifndef INFO_H
#define INFO_H

#include <QDialog>
#include <QLabel>
#include <QtGui>
#include <QPixmap>
#include <QBoxLayout>
#include <QtGlobal>
#include <QString>
#include <QIcon>
#include <QWidget>
class Info : public QDialog
{
    Q_OBJECT
private:
 QLabel* LableFoto;
 QPushButton* btnClose;
 QString VerUs;
public:
    Info(QWidget *parent = 0);
};

#endif // INFO_H
