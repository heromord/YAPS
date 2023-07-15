#include "Figure2.h"
void Figure2::paintEvent(QPaintEvent *e)
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
    painter.drawLine(DX, 0, W,0);
    painter.drawLine(W,0, W,H-BX);
    painter.drawLine(W, H-BX, W-BX,H-BX);
    painter.drawLine(W-BX, H-BX, W-BX, H);
    painter.drawLine(W-BX, H, W/2 + P/2, H);
    painter.drawLine(W/2 + P/2, H, W/2 + P/2, H + P/2);
    painter.drawLine(W/2 + P/2, H + P/2, W/2 - P/2, H + P/2);
    painter.drawLine(W/2 - P/2, H + P/2, W/2 - P/2, H);
    painter.drawLine(W/2 - P/2, H, CX, H);
    painter.drawLine(CX, H, 0, H - CX);
    painter.drawLine(0, H- CX, 0, DX);
    painter.drawLine(0, DX, DX, DX);
    painter.drawLine(DX,DX,DX,0);

}
Figure2::Figure2(int W,int H,int P,int BX,int CX,int DX,int WinW,int WinH,QWidget *parent):
    QWidget(parent),BlueLight(false),ang(0),direct(1)
{
    this->WinW=WinW;
    this->WinH=WinH;
    this->W=W;
    this->H=H;
    this->P=P;
    this->BX=BX;
    this->CX=CX ;
    this->DX=DX;
}
 void Figure2::Resize(int WinW,int WinH)
{
  this->WinW=WinW;
  this->WinH=WinH;
}

 bool Figure2::GetBlue()
 {
  return BlueLight;
 }

 void Figure2::mousePressEvent(QMouseEvent* event)
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
     if (!BlueLight) BlueLight = true;
     QWidget::update();
     dialog2* dialog = new dialog2();
     dialog->move(600,100);
     dialog->setEdit(W, H, ang, P, BX, CX, DX);
     dialog->show();

     if ((dialog->exec() == QDialog::Accepted))
     {
         if (!dialog->isRight())
         {
         QMessageBox::information(0,"Information", "Incorrect data");
         }
         else
         {
         UpDate(dialog->getW(), dialog->getH(), dialog->getAngle(), dialog->getP(), dialog->getBX()
                , dialog->getCX(), dialog->getDX());
         direct = dialog->getDirect();
         QWidget::update();
         }
         }

     delete dialog;
     }
 }
void Figure2:: mouseMoveEvent(QMouseEvent* event)
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
void Figure2:: UpDate(int W,int H,int ang,int P,int BX,int CX,int DX)
{
    this->W=W;
    this->H=H;
    this->ang=ang;
    this->P=P;
    this->BX=BX;
    this->CX=CX;
    this->DX=DX;
}

Figure2:: ~Figure2()
{
}
