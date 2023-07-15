#include <Figure1.h>

void Figure1::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter painter(this);
    resize(W * sqrt(2) + 1, W * sqrt(2) + 1);

    painter.translate(W * sqrt(2)/2, W * sqrt(2)/2);
    painter.rotate(ang*direct);
    painter.translate(-W/2,-W/2);
    if(BlueLight)
    { 
     painter.setPen(QPen(Qt::blue, 3, Qt::SolidLine, Qt::FlatCap));
    }
    else
    {
    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::FlatCap));
    }
    painter.drawLine(x, Q/2, W/2 - Q/2, Q/2);
    painter.drawArc(W/2 - Q/2, 0, Q, Q, +180 * 16, -180 * 16);
    painter.drawLine(W/2 + Q/2, Q/2, W - AR, Q/2);
    painter.drawArc(W-AR, Q/2-AR, 2 * AR, 2 * AR, 180 * 16, 90 * 16);
    painter.drawLine(W, Q/2+AR, W, H - BR);
    painter.drawArc(W-BR, H-BR, 2 * BR, 2 * BR, 90 * 16, 90 * 16);
    painter.drawLine(W-BR, H, CR, H);
    painter.drawArc(-CR, H-CR, 2 * CR, 2 * CR, 0, 90 * 16);
    painter.drawLine(0, H -CR, 0, x+Q/2);
    painter.drawLine(0,x+Q/2,x,Q/2);
}
Figure1::Figure1(int W,int H,int Q,int x,int AR,int BR,int CR,int WinW,int WinH,QWidget *parent):
    QWidget(parent),BlueLight(false),ang(0),direct(1)
{
    this->WinW=WinW;
    this->WinH=WinH;
    this->W=W;
    this->H=H;
    this->Q=Q;
    this->x=x;
    this->AR=AR;
    this->BR=BR ;
    this->CR=CR;
}
void Figure1::Resize(int WinW,int WinH)
{
  this->WinW=WinW;
  this->WinH=WinH;
  QWidget::update();
}

bool Figure1::GetBlue()
{
 return BlueLight;
}

void Figure1::mousePressEvent(QMouseEvent* event)
{
    if (event->buttons() & Qt::LeftButton)
    {
    if (BlueLight){ BlueLight= false;}
    else BlueLight = true;
    QWidget::update();

    ofset = event->globalPos() - pos();
    }
    if (event->buttons() & Qt::RightButton)
    {
    if (!BlueLight) BlueLight = true;
    QWidget::update();
    dialog1* dialog = new dialog1();
    dialog->move(600,100);
    dialog->setEdit(W, H, ang, Q, x, AR, BR, CR);
    dialog->show();

    if ((dialog->exec() == QDialog::Accepted))
    {
        if (!dialog->isRight())
        {
        QMessageBox::information(0,"Information", "Incorrect data");
        }
        else
        {
        UpDate(dialog->getW(), dialog->getH(), dialog->getAngle(), dialog->getQ(), dialog->getX()
               , dialog->getAR(), dialog->getBR(), dialog->getCR());
        direct = dialog->getDirect();
        QWidget::update();
        }
        }

    delete dialog;
    }
  }
void Figure1::mouseMoveEvent(QMouseEvent* event)
{
    BlueLight = true;
    QWidget::update();

    if (event->buttons() & Qt::LeftButton)
    {
    if (((event->globalPos() - ofset).x() + width() > WinW) ||
        ((event->globalPos() - ofset).y() + height() > WinH) ||
        ((event->globalPos() - ofset).x() <= 0) ||
        ((event->globalPos() - ofset).y() <= 35))
        ofset = event->globalPos() - pos();
    else
        move(event->globalPos() - ofset);
    }
}

 void Figure1:: UpDate(int W,int H,int ang,int Q,int x,int AR,int BR,int CR)
 {
     this->W=W;
     this->H=H;
     this->ang=ang;
     this->Q=Q;
     this->x=x;
     this->AR=AR;
     this->BR=BR;
     this->CR=CR;
 }

Figure1:: ~Figure1()
{
}
