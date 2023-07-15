#include "info.h"

Info::Info(QWidget *parent) :
    QDialog(parent, Qt::WindowTitleHint | Qt::WindowSystemMenuHint),VerUs(qVersion())
{
    LableFoto= new QLabel;
    QLabel* labelCreator = new QLabel("Creator");
    QLabel* labelName = new QLabel("Tashkinov Sergei");
    QLabel* Date1 = new QLabel("Build Date:");
    QLabel* Date2 = new QLabel("13.11.2020");
    QLabel* labelVersiaCr = new QLabel("Creator's Qt:");
    QLabel* labelVersiaUS = new QLabel("User's Qt:");
    QLabel* labelVersiaCr1 = new QLabel("4.8.4");
    QLabel* labelVersiaUS1 = new QLabel(VerUs);
    this->btnClose = new QPushButton("Close");
    btnClose->setCheckable(true);
    connect(btnClose,SIGNAL(clicked()),SLOT(close()));
    QIcon Foto=QIcon::fromTheme("Foto",QIcon("Ffoto.jpg"));
    QPixmap pixmap =Foto.pixmap(QSize(150,200));
    LableFoto->setPixmap(pixmap);
    QGridLayout* layout = new QGridLayout;
    layout->addWidget(LableFoto,1,1);
    layout->addWidget(labelCreator, 2, 0);
    layout->addWidget(labelName, 2, 1);
    layout->addWidget(labelVersiaCr, 3, 0);
    layout->addWidget(labelVersiaCr1,3, 1);
    layout->addWidget(labelVersiaUS, 4, 0);
    layout->addWidget(labelVersiaUS1,4, 1);
    layout->addWidget(Date1,5,0);
    layout->addWidget(Date2,5,1);
    layout->addWidget(btnClose, 6,0,6,2);
    setLayout(layout);
}
