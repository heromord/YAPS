#include "findandreplace.h"

FindAndReplac::FindAndReplac(QWidget *parent) :
    QDialog(parent, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
  FindF = new QLineEdit;
  LFind = new QLabel("Find");
  FindR = new QLineEdit;
  RFind = new QLabel("Replace");

  btnOk = new QPushButton("OK");
  btnOk->setCheckable(true);

  btnClose = new QPushButton("Close");
  btnClose->setCheckable(true);

  connect(btnOk, SIGNAL(clicked()), SLOT(accept()));
  connect(btnClose, SIGNAL(clicked()), SLOT(reject()));

  QGridLayout* layout = new QGridLayout;
  layout->addWidget(LFind, 0, 0);
  layout->addWidget(FindF, 0, 1);
  layout->addWidget(RFind, 1, 0);
  layout->addWidget(FindR, 1, 1);
  layout->addWidget(btnOk, 2, 0);
  layout->addWidget(btnClose, 2, 1);
  setLayout(layout);

}

QString FindAndReplac::GetFind()
{
 return (FindF->text());
}
QString FindAndReplac::GetReplace()
{
 return (FindR->text());
}
