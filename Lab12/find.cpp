#include "find.h"

Find::Find(QWidget *parent) :
    QDialog(parent, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
  FindE = new QLineEdit;
  FindL = new QLabel("Find");

  btnOk = new QPushButton("OK");
  btnOk->setCheckable(true);

  btnClose = new QPushButton("Close");
  btnClose->setCheckable(true);

  connect(btnOk, SIGNAL(clicked()), SLOT(accept()));
  connect(btnClose, SIGNAL(clicked()), SLOT(reject()));

  QGridLayout* layout = new QGridLayout;
  layout->addWidget(FindL, 0, 0);
  layout->addWidget(FindE, 0, 1);
  layout->addWidget(btnOk, 1, 0);
  layout->addWidget(btnClose, 1, 1);
  setLayout(layout);

}

QString Find::GetFind()
{
 return (FindE->text());
}
