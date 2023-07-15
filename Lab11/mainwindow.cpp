#include "mainwindow.h"

QToolBar* MainWindow::createToolBar()
{
    QToolBar *toolbar = addToolBar("main toolbar");
    toolbar->setMovable(false);
    QPalette toolBarPal(palette());
    toolBarPal.setColor(QPalette::Background, Qt::gray);
    toolbar->setAutoFillBackground(true);
    toolbar->setPalette(toolBarPal);

    this->fig1 = new QPushButton("1 Figure",this);
    this->fig2 = new QPushButton("2 Figure",this);
    this->AdF  = new QPushButton("Add figure", this);
    toolbar->addWidget(fig1);
    toolbar->addWidget(fig2);
    toolbar->addWidget(AdF);
    toolbar->addSeparator();

    this->DelF = new QPushButton("Delete Figure",this);
    toolbar->addWidget(DelF);
    this->DelF->setEnabled(false);
    connect(DelF,SIGNAL(clicked()),this,SLOT(DelButton()));

    this->fig1->setCheckable(true);
    connect(fig1, SIGNAL(toggled(bool)), this, SLOT(ButtonToggled1(bool)));

    this->fig2->setCheckable(true);
    connect(fig2, SIGNAL(toggled(bool)), this, SLOT(ButtonToggled2(bool)));

    this->AdF->setEnabled(false);
    connect(AdF,SIGNAL(clicked()),this,SLOT(AdButton()));
    return toolbar;

}


MainWindow::MainWindow()
    : QMainWindow(),fl_resize(false)
{
    this->move(400,0);
    this->resize(1000,800);

    QPalette WindowPal(palette());
    WindowPal.setColor(QPalette::Background, Qt::white);
    this->setPalette(WindowPal);

    addToolBar(Qt::TopToolBarArea, createToolBar());

    connect(&timer, SIGNAL(timeout()), this, SLOT(DelEnable()));
    timer.start(5);
}

void MainWindow::ButtonToggled1(bool state)
{
    this->firstB=state;
    if(state)
    {
        if(this->fig2->isChecked()){this->fig2->setChecked(false);}
        this->AdF->setEnabled(true);
    }
else
    {
        if((this->firstB)==false &&(this->secondB)==false){this->AdF->setEnabled(false);}
   }

}
void MainWindow::ButtonToggled2(bool state)
{
    this->secondB=state;
    if(state)
    {
     if(this->fig1->isChecked()){this->fig1->setChecked(false);}
     this->AdF->setEnabled(true);
    }
else
    {
     if((this->secondB)==false &&(this->firstB)==false){this->AdF->setEnabled(false);}
   }

}
Figure1* MainWindow::createFigure1()
{
    int StX=35+(rand() % (width() - 200)) ;
    int StY=35+(rand() % (height() - 200)) ;
    int W=4+(rand() % (width() - StX)) ;
    int H=3+(rand() % (std::min(W-3, height() - StY)));
    int Q=1+(rand() % (W/4));
    int x=1+(rand() % (H/3)) ;
    int AR=1+(rand() % (H/3)) ;
    int BR=1+(rand() % (H/3)) ;
    int CR=1+(rand() % (H/3)) ;
    Figure1* figure = new Figure1( W, H, Q, x, AR, BR,CR,width(),height(), this);
   figure->show();
   figure->move(StX,StY);
   figure->resize(width(),height());
   return figure;
}
Figure2* MainWindow::createFigure2()
{
    int StX=35+rand() % (width() - 200) ;
    int StY=35+rand() % (height() - 200) ;
    int W=4+rand() % (width() - StX) ;
    int H=3+rand() % (std::min(W-3, height() - StY));
    int P=1+rand() % (W/4);
    int BX=1+rand() % (H/3) ;
    int CX=1+rand() % (H/3) ;
    int DX=1+rand() % (H/3) ;
    Figure2* figure = new Figure2(W, H, P,BX, CX,DX,width(),height(), this);
   figure->show();
   figure->move(StX,StY);
   figure->resize(width(),height());
   return figure;
}

void MainWindow::AdButton()
{
    if((firstB==true)&&(secondB==false))
    {
    Figures1.push_back(createFigure1());
    }
    else if((secondB==true)&&(firstB==false))
    {
    Figures2.push_back(createFigure2());
    }
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    Q_UNUSED(event);
    if (!fl_resize)
    {
        fl_resize = true;
    }
    else
    {
        for (size_t i=0;i<Figures1.size();i++)
        {
            Figures1[i]->Resize(width(), height());
            Figures1[i]->repaint();
        }
        for (size_t i=0;i<Figures2.size();i++)
        {
            Figures2[i]->Resize(width(), height());
            Figures2[i]->repaint();
        }

    }
}

void MainWindow::DelButton()
{
    vector <Figure1*> :: iterator it1 ;
    vector <Figure2*> :: iterator it2 ;
    if (DelF->isEnabled())
    {
    for (int i = Figures1.size() - 1; i >= 0; --i)
    {
        if (Figures1[i]->GetBlue())
        {
        delete Figures1[i];
        it1 = (Figures1.begin()+i);
        Figures1.erase(it1);
        }
    }

    for (int i = Figures2.size() - 1; i >= 0; --i)
    {
        if (Figures2[i]->GetBlue())
        {
        delete Figures2[i];
        it2 =( Figures2.begin() + i);
        Figures2.erase(it2);
        }
    }
    }
    }
void MainWindow::DelEnable()
{
    bool trigger = false;
    for (size_t i=0;i<Figures1.size();i++)
    {
    if (Figures1[i]->GetBlue())
    {
        trigger = true;
        break;
    }
    }
    for (size_t i=0;i<Figures2.size();i++)
    {
    if (Figures2[i]->GetBlue())
    {
        trigger = true;
        break;
    }
    }

    if (trigger) {DelF->setEnabled(true);}
    else {DelF->setEnabled(false);}
}
MainWindow::~MainWindow(){}
