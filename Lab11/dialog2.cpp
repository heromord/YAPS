#include "dialog2.h"

dialog2::dialog2() : QDialog(0, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
    direct = 1;
    editW = new QLineEdit;
    editH = new QLineEdit;
    editAng = new QLineEdit;
    editP = new QLineEdit;
    editBX = new QLineEdit;
    editCX = new QLineEdit;
    editDX = new QLineEdit;

    QLabel* labelW = new QLabel("Width");
    QLabel* labelH = new QLabel("Height");
    QLabel* labelAngle = new QLabel("Angle");

    QLabel* labelP= new QLabel("P");
    QLabel* labelBX= new QLabel("BX");
    QLabel* labelCX= new QLabel("CX");
    QLabel* labelDX= new QLabel("DX");

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

    layout->addWidget(labelP, 3, 0);
    layout->addWidget(editP, 3, 1);

    layout->addWidget(labelBX, 4, 0);
    layout->addWidget(editBX, 4, 1);

    layout->addWidget(labelCX, 5, 0);
    layout->addWidget(editCX, 5, 1);

    layout->addWidget(labelDX, 6, 0);
    layout->addWidget(editDX, 6, 1);

    layout->addWidget(left, 7, 0);
    layout->addWidget(right, 7, 1);

    layout->addWidget(btnOK, 8, 0);
    layout->addWidget(btnCancel, 8, 1);

    setLayout(layout);
}

void dialog2::setEdit(int w, int h, int ang, int p, int bx, int cx, int dx)
{
    editW->setText(QString::number(w));
    editH->setText(QString::number(h));
    editAng->setText(QString::number(ang));
    editP->setText(QString::number(p));
    editBX->setText(QString::number(bx));
    editCX->setText(QString::number(cx));
    editDX->setText(QString::number(dx));
}

bool dialog2::isRight()
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

    temp = editP->text();
    int p = temp.toInt(&check, 10);
    if (!check || p == 0 || p > w / 4) return false;

    temp = editBX->text();
    int bx = temp.toInt(&check, 10);
    if (!check || bx == 0 || bx > h / 3) return false;

    temp = editCX->text();
    int cx = temp.toInt(&check, 10);
    if (!check || cx == 0 || cx > h / 3) return false;

    temp = editDX->text();
    int dx = temp.toInt(&check, 10);
    if (!check || dx == 0 || dx > h / 3) return false;

    this->w = w;
    this->h = h;
    this->ang = angle;
    this->p = p;
    this->bx = bx;
    this->cx = cx;
    this->dx = dx;

    return true;
}

int dialog2::getW()
{
    return w;
}

int dialog2::getH()
{
    return h;
}

int dialog2::getAngle()
{
    return ang;
}

int dialog2::getP()
{
    return p;
}


int dialog2::getBX()
{
    return bx;
}

int dialog2::getCX()
{
    return cx;
}

int dialog2::getDX()
{
    return dx;
}

int dialog2::getDirect()
{
    return direct;
}

void dialog2::leftClick()
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

void dialog2::rightClick()
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
