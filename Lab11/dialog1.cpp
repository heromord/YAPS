#include "dialog1.h"

dialog1::dialog1() : QDialog(0, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
    direct = 1;
    editW = new QLineEdit;
    editH = new QLineEdit;
    editAng = new QLineEdit;
    editQ = new QLineEdit;
    editX = new QLineEdit;
    editAR = new QLineEdit;
    editBR = new QLineEdit;
    editCR = new QLineEdit;

    QLabel* labelW = new QLabel("Width");
    QLabel* labelH = new QLabel("Height");
    QLabel* labelAngle = new QLabel("Angle");

    QLabel* labelQ= new QLabel("Q");
    QLabel* labelX= new QLabel("X");
    QLabel* labelAR= new QLabel("AR");
    QLabel* labelBR= new QLabel("BR");
    QLabel* labelCR= new QLabel("CR");

    left = new QPushButton("Left");
    left->setCheckable(true);
    connect(left, SIGNAL(clicked()), this, SLOT(leftClick()));

    right = new QPushButton("Right");
    right->setCheckable(true);
    connect(right, SIGNAL(clicked()), this, SLOT(rightClick()));

    QPushButton* btnOK = new QPushButton("OK");
    QPushButton* btnCancel = new QPushButton("Cancel");

    connect(btnOK, SIGNAL(clicked()), SLOT(accept()));
    connect(btnCancel, SIGNAL(clicked()), SLOT(reject()));

    QGridLayout* layout = new QGridLayout;
    layout->addWidget(labelW, 0, 0);
    layout->addWidget(editW, 0, 1);

    layout->addWidget(labelH, 1, 0);
    layout->addWidget(editH, 1, 1);

    layout->addWidget(labelAngle, 2, 0);
    layout->addWidget(editAng, 2, 1);

    layout->addWidget(labelQ, 3, 0);
    layout->addWidget(editQ, 3, 1);

    layout->addWidget(labelX, 4, 0);
    layout->addWidget(editX, 4, 1);

    layout->addWidget(labelAR, 5, 0);
    layout->addWidget(editAR, 5, 1);

    layout->addWidget(labelBR, 6, 0);
    layout->addWidget(editBR, 6, 1);

    layout->addWidget(labelCR, 7, 0);
    layout->addWidget(editCR, 7, 1);

    layout->addWidget(left, 8, 0);
    layout->addWidget(right, 8, 1);

    layout->addWidget(btnOK, 9, 0);
    layout->addWidget(btnCancel, 9, 1);

    setLayout(layout);
}

void dialog1::setEdit(int w, int h, int ang, int q, int x, int ar, int br, int cr)
{
    editW->setText(QString::number(w));
    editH->setText(QString::number(h));
    editAng->setText(QString::number(ang));
    editQ->setText(QString::number(q));
    editX->setText(QString::number(x));
    editAR->setText(QString::number(ar));
    editBR->setText(QString::number(br));
    editCR->setText(QString::number(cr));
}

bool dialog1::isRight()
{
    bool check;
    QString temp = editW->text();
    int w = temp.toInt(&check, 10);
    if (!check || w == 0) return false;

    temp = editH->text();
    int h = temp.toInt(&check, 10);
    if (!check || h == 0 || h > w) return false;

    temp = editAng->text();
    int angle = temp.toInt(&check, 10);
    if (!check) return false;

    temp = editQ->text();
    int q = temp.toInt(&check, 10);
    if (!check || q == 0 || q > w / 4) return false;

    temp = editX->text();
    int x = temp.toInt(&check, 10);
    if (!check || x == 0 || x > h / 3) return false;

    temp = editAR->text();
    int ar = temp.toInt(&check, 10);
    if (!check || ar == 0 || ar > h / 3) return false;

    temp = editBR->text();
    int br = temp.toInt(&check, 10);
    if (!check || br == 0 || br > h / 3) return false;

    temp = editCR->text();
    int cr = temp.toInt(&check, 10);
    if (!check || cr == 0 || cr > h / 3) return false;

    this->w = w;
    this->h = h;
    this->ang = angle;
    this->q = q;
    this->x = x;
    this->ar = ar;
    this->br = br;
    this->cr = cr;

    return true;
}

int dialog1::getW()
{
    return w;
}

int dialog1::getH()
{
    return h;
}

int dialog1::getAngle()
{
    return ang;
}

int dialog1::getQ()
{
    return q;
}

int dialog1::getX()
{
    return x;
}

int dialog1::getAR()
{
    return ar;
}

int dialog1::getBR()
{
    return br;
}

int dialog1::getCR()
{
    return cr;
}

int dialog1::getDirect()
{
    return direct;
}

void dialog1::leftClick()
{
    if (left->isChecked())
    {
    if (right->isChecked())
    {
        right->setChecked(false);
    }
    direct = 1;
    }
}

void dialog1::rightClick()
{
    if (right->isChecked())
    {
    if (left->isChecked())
    {
        left->setChecked(false);
    }
    direct = -1;
    }
}
