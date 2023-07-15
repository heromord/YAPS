#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),standart("C89"),style(0)
{
    this->resize(1000,800);
    QPalette WindowPal(palette());
    WindowPal.setColor(QPalette::Background, Qt::white);
    this->setPalette(WindowPal);
    QPixmap cpix("iconC.png");
    this->setWindowIcon(QIcon(cpix));
    this->redac=new TextEdit();

    setCentralWidget(redac);
    CreateMenuFiel();
    CreateMenuCorrection();
    CreateMenuFormat();
    CreateMenuView();
    CreateMenuInfo();
    addToolBar(Qt::TopToolBarArea, createToolBar());
    createStBar();
    connect(redac,SIGNAL(textChanged()),this,SLOT(TextChanged()));
    connect(&timer,SIGNAL(timeout()),this,SLOT(ReName()));
    connect(redac,SIGNAL(textChanged()),this,SLOT(DateTime()));
    highlighter = new Highlighter(redac->document());
    highlighter->getHigh(standart, style);
    timer.start(10);
}
QMenu* MainWindow::CreateMenuFiel()
{
QMenu* File;
File =menuBar()->addMenu("&File");
this->Newf= new  QAction("&New",this);
File->addAction(Newf);
connect(Newf,SIGNAL(triggered()),redac,SLOT(New()));
this->Openf= new QAction("&Open",this);
File->addAction(Openf);
connect(Openf,SIGNAL(triggered()),redac,SLOT(oopen()));
this->Sawe= new QAction("&Save",this);
File->addAction(Sawe);
connect(Sawe,SIGNAL(triggered()),redac,SLOT(ssave()));
this->SaweHow= new QAction("&Save How",this);
File->addAction(SaweHow);
connect(SaweHow,SIGNAL(triggered()),redac,SLOT(ssaveHow()));
File->addSeparator();
this->Exit= new QAction("&Exit",this);
File->addAction(Exit);
connect(Exit,SIGNAL(triggered()), qApp, SLOT(quit()));
return File;
}
QMenu* MainWindow::CreateMenuCorrection()
{
 QMenu* Correction;
 Correction=menuBar()->addMenu("&Correction");
 this->Cancelf= new  QAction("&Cancel",this);
 Correction->addAction(Cancelf);
 connect(Cancelf,SIGNAL(triggered()),redac,SLOT(undo()));
 this->Repeat= new QAction("&Repeat",this);
 Correction->addAction(Repeat);
 connect(Repeat,SIGNAL(triggered()),redac,SLOT(redo()));
 this->CopyC= new QAction("&Copy",this);
 Correction->addAction(CopyC);
 connect(CopyC,SIGNAL(triggered()),redac,SLOT(copy()));
 this->CutC= new QAction("&Cut",this);
 Correction->addAction(CutC);
 connect(CutC,SIGNAL(triggered()),redac,SLOT(cut()));
 this->PasteC= new QAction("&Paste",this);
 Correction->addAction(PasteC);
 connect(PasteC,SIGNAL(triggered()),redac,SLOT(paste()));
 this->FindC= new QAction("&Find",this);
 Correction->addAction(FindC);
 connect(FindC,SIGNAL(triggered()),this,SLOT(Ffind()));
 this->FindAndReplace = new QAction("&Find and Replace",this);
 Correction->addAction(FindAndReplace);
 connect(FindAndReplace,SIGNAL(triggered()),this,SLOT(FindAndRep()));
 this->SelectAllC= new QAction("&Select All",this);
 Correction->addAction(SelectAllC);
 connect(SelectAllC,SIGNAL(triggered()),redac,SLOT(selectAll()));
 return Correction;
}

QMenu* MainWindow::CreateMenuInfo()
{
  QMenu* Note;
  Note=menuBar()->addMenu("&Note");
  this->InfoM= new  QAction("&Info",this);
  Note->addAction(InfoM);
  connect(InfoM,SIGNAL(triggered()),this,SLOT( Modal()));
  return Note;
}

QToolBar* MainWindow::createToolBar()
{
    this->toolbar = addToolBar("main toolbar");
    toolbar->setMovable(false);
    QPalette toolBarPal(palette());
    toolBarPal.setColor(QPalette::Background, Qt::gray);
    toolbar->setAutoFillBackground(true);
    toolbar->setPalette(toolBarPal);
    QPixmap newpix("new.png");
    QPixmap openpix("open.png");
    QPixmap savepix("save.png");
    QPixmap canpix("cancel.png");
    QPixmap repeatpix("repeat.png");
    QPixmap copypix("copy.png");
    QPixmap cutpix("cut.png");
    QPixmap findpix("find.png");
    QPixmap findAndpix("findnext.png");
    QPixmap pastepix("insert.png");
    this->Newf=toolbar->addAction(QIcon(newpix),"New");
    connect(Newf,SIGNAL(triggered()),redac,SLOT(New()));
    this->Openf=toolbar->addAction(QIcon(openpix), "Open File");
    connect(Openf,SIGNAL(triggered()),redac,SLOT(oopen()));
    this->Sawe=toolbar->addAction(QIcon(savepix), "Save");
    connect(Sawe,SIGNAL(triggered()),redac,SLOT(ssave()));
    this->Cancelf=toolbar->addAction(QIcon(canpix), "Cancel");
    connect(Cancelf,SIGNAL(triggered()),redac,SLOT(undo()));
    this->Repeat=toolbar->addAction(QIcon(repeatpix), "Repeat");
    connect(Repeat,SIGNAL(triggered()),redac,SLOT(redo()));
    this->CopyC=toolbar->addAction(QIcon(copypix), "Copy");
    connect(CopyC,SIGNAL(triggered()),redac,SLOT(copy()));
    this->CutC=toolbar->addAction(QIcon(cutpix), "Cut");
    connect(CutC,SIGNAL(triggered()),redac,SLOT(cut()));
    this->PasteC=toolbar->addAction(QIcon(pastepix),"Past");
    connect(PasteC,SIGNAL(triggered()),redac,SLOT(paste()));
    this->FindC=toolbar->addAction(QIcon(findpix), "Find");
    connect(FindC,SIGNAL(triggered()),this,SLOT(Ffind()));

    QMenu * MenFind = new QMenu(this);
    this->FindAndReplace=MenFind->addAction(QIcon(findAndpix), "Find and Replace");
    connect(FindAndReplace,SIGNAL(triggered()),this,SLOT(FindAndRep()));
    this->FindC->setMenu(MenFind);
    return toolbar;
}
QMenu* MainWindow::CreateMenuFormat()
{
    QMenu* Format;
    Format=menuBar()->addMenu("&Format");
    this->Hyphenation= new  QAction("&Word wrap",this);
    Hyphenation->setCheckable(true);
    Hyphenation->setChecked(true);
    Format->addAction(Hyphenation);
    connect(Hyphenation,SIGNAL(triggered()),this,SLOT(WordWrap()));
    this->FontSelect= new QAction("&Font Selection",this);
    Format->addAction(FontSelect);
    connect(FontSelect,SIGNAL(triggered()),this,SLOT(SetFFont()));
    return Format;
}
QMenu* MainWindow::CreateMenuView()
{
    QMenu* View;
    View=menuBar()->addMenu("&View");
    this->BackdColor= new  QAction("Backgraund Color",this);
    View->addAction(BackdColor);
    connect(BackdColor,SIGNAL(triggered()),this,SLOT(SetWinColor()));
    this->LineColor= new  QAction("Line Color",this);
    View->addAction(LineColor);
    connect(LineColor,SIGNAL(triggered()),this,SLOT(SetLineColor()));
    this->Numeration= new  QAction("Numeration",this);
    Numeration->setCheckable(true);
    Numeration->setChecked(false);
    connect(Numeration,SIGNAL(triggered()),this,SLOT(numerat()));
    View->addAction(Numeration);
    this->ToolB= new  QAction("ToolBar visible",this);
    ToolB->setCheckable(true);
    ToolB->setChecked(true);
    connect(ToolB,SIGNAL(triggered()),this,SLOT(VisibleToolB()));
    View->addAction(ToolB);
    this->StB= new  QAction("StatusBar visible",this);
    StB->setCheckable(true);
    StB->setChecked(true);
    connect(StB,SIGNAL(triggered()),this,SLOT(VisibleStatusB()));
    View->addAction(StB);
    this->SyntaLight = new QAction("Syntax Backlight",this);
    SyntaLight->setCheckable(true);
    SyntaLight->setChecked(true);
    View->addAction(SyntaLight);
    connect(SyntaLight,SIGNAL(triggered()),this,SLOT(pods()));
    this->Synta = new QAction("Syntax",this);
    View->addAction(Synta);

    QMenu* MenSynta = new QMenu(this);
    this->SyntaC89=MenSynta->addAction("C89");
    SyntaC89->setCheckable(true);
    SyntaC89->setChecked(true);
    connect(SyntaC89,SIGNAL(triggered()),this,SLOT(ChooseSyntaC()));
    this->SyntaCu98=MenSynta->addAction("C++98/03");
    SyntaCu98->setCheckable(true);
    connect(SyntaCu98,SIGNAL(triggered()),this,SLOT(ChooseSyntaCu()));
    this->Synta->setMenu(MenSynta);
    this->SyntaCu1114=MenSynta->addAction("C++11/14");
    SyntaCu1114->setCheckable(true);
    connect(SyntaCu1114,SIGNAL(triggered()),this,SLOT(ChooseSyntaCu11()));


    this->Editing = new QAction("Editing",this);
    View->addAction(Editing);

    QMenu* MenEd = new QMenu(this);
    this->ChangeEd=MenEd->addAction("Change");
    ChangeEd->setDisabled(true);
    this->DownloadEd=MenEd->addAction("Downlaud Style from file");
    DownloadEd->setDisabled(true);
    this->DefaultEd=MenEd->addAction("Default");
    connect(DefaultEd,SIGNAL(triggered()),this,SLOT(Def()));
    this->AvailableStyles=MenEd->addAction("Available Styles");
    QMenu* AvailableStyl= new  QMenu(this);  //MenEd->addAction("Available Styles");
    this->FirstSt=AvailableStyl->addAction("First Style");
    connect(FirstSt,SIGNAL(triggered()),this,SLOT(fer()));
    this->SecondSt=AvailableStyl->addAction("Second Style");
    connect(SecondSt,SIGNAL(triggered()),this,SLOT(sec()));
    this->ThirdSt=AvailableStyl->addAction("Third Style");
    connect(SecondSt,SIGNAL(triggered()),this,SLOT(thri()));


    this->AvailableStyles->setMenu(AvailableStyl);
    this->Editing->setMenu(MenEd);

    return View;
}

void MainWindow::createStBar()
{
    this->firstS= new QLabel(this);
    this->secondS= new QLabel(this);
    this->thirdS= new QLabel("",this);
    statusBar()->addWidget(firstS,1);
    statusBar()->addWidget(secondS,1);
    statusBar()->addWidget(thirdS,1);
}

void MainWindow::Modal()
{
    Info* dialog = new Info();
    dialog->exec();
    delete dialog;
}
void MainWindow::VisibleToolB()
{
 if (this->ToolB->isChecked())
    {
        this->toolbar->show();
    }
 else
    {
        this->toolbar->hide();
    }
}

void MainWindow::VisibleStatusB()
{
    if(this->StB->isChecked())
      {
        statusBar()->show();
      }
    else
      {
       statusBar()->hide();
      }
}

void MainWindow::ChooseSyntaC()
{
    if (this->SyntaC89->isChecked())
    {
       this->SyntaCu98->setChecked(false);
       this->SyntaCu1114->setChecked(false);
       standart = "C89";
            delete highlighter;
            highlighter = new Highlighter(redac->document());
            highlighter->getHigh(standart, style);

    }
    else
     {
       this->SyntaCu98->setChecked(true);
       standart = "C++99/03";
             delete highlighter;
             highlighter = new Highlighter(redac->document());
             highlighter->getHigh(standart, style);

     }
}
void MainWindow::ChooseSyntaCu()
{
   if(this->SyntaCu98->isChecked())
   {
       this->SyntaC89->setChecked(false);
       this->SyntaCu1114->setChecked(false);
       standart = "C++99/03";
             delete highlighter;
             highlighter = new Highlighter(redac->document());
             highlighter->getHigh(standart, style);
   }
   else
   {
     this->SyntaCu1114->setChecked(true);
     standart = "C89";
            delete highlighter;
            highlighter = new Highlighter(redac->document());
            highlighter->getHigh(standart, style);
   }
}

void MainWindow::ChooseSyntaCu11()
{
    if(this->SyntaCu1114->isChecked())
     {
        this->SyntaC89->setChecked(false);
        this->SyntaCu98->setChecked(false);
        standart = "C++11/14";
        delete highlighter;
            highlighter = new Highlighter(redac->document());
            highlighter->getHigh(standart,style);
     }
    else
     {
        this->SyntaC89->setChecked(true);
        this->SyntaCu98->setChecked(false);
        standart = "C89";
               delete highlighter;
               highlighter = new Highlighter(redac->document());
               highlighter->getHigh(standart, style);
     }
}

void MainWindow::Def()
{
    style = 0;
    delete highlighter;
        highlighter = new Highlighter(redac->document());
        highlighter->getHigh(standart,style);
}

void MainWindow::fer()
{
    style = 1;
        delete highlighter;
        highlighter = new Highlighter(redac->document());
        highlighter->getHigh(standart,style);
}

void MainWindow::sec()
{
    style = 2;
        delete highlighter;
        highlighter = new Highlighter(redac->document());
        highlighter->getHigh(standart,style);

}
void MainWindow::thri()
{
    style = 3;
        delete highlighter;
        highlighter = new Highlighter(redac->document());
        highlighter->getHigh(standart,style);
}

void MainWindow::ReName()
{
    this->WinName=redac->GetName();
    if(WinName.size()<=32)
       {
        if(redac->GetCh_Fl())
         {
            this->WinName32="*"+WinName;
            this->setWindowTitle(WinName32);

            this->WordNumb = redac->toPlainText().split(QRegExp("(\\s|\\n|\\r)+")
               , QString::SkipEmptyParts).count();

            this->SimbNumb=redac->toPlainText().length();
            this->Lines =(redac->document()->lineCount());
            this->FSize=redac->FSize;
            this->thirdS->setText("Lines:" + QString::number(Lines)+" "+"Simbols:"+QString::number(SimbNumb)
                                  +" "+"Words:"+QString::number(WordNumb)+" "+"Size:"+QString::number(FSize));

            QTextCursor control_cur=redac->textCursor();
            this->cur_X=control_cur.columnNumber();
            this->cur_Y = control_cur.blockNumber()+1;
            this->firstS->setText("Line:"+QString::number(cur_Y)+" "+"Column:" + QString::number(cur_X));

         }
        else
         {
          this->setWindowTitle(WinName);

            this->WordNumb=redac->WordNumb;
            this->SimbNumb=redac->SimbNumb;
            this->Lines=redac->Lines;
            this->FSize=redac->FSize;
            this->thirdS->setText("Lines:" + QString::number(Lines)+" "+"Simbols:"+QString::number(SimbNumb)
                                  +" "+"Words:"+QString::number(WordNumb)+" "+"Size:"+QString::number(FSize));

            this->date=redac->date;
            this->time=redac->time;
            if(this->date==QDate::currentDate())
              {
               this->secondS->setText("Time:"+ time.toString());
              }
            else
              {
                this->secondS->setText("Date"+date.toString()+" "+"Time:"+ time.toString());
                this->date=QDate::currentDate();
              }
            QTextCursor control_cur=redac->textCursor();
            this->cur_X=control_cur.columnNumber();
            this->cur_Y = control_cur.blockNumber()+1;
            this->firstS->setText("Line:"+QString::number(cur_Y)+" "+"Column:" + QString::number(cur_X));
         }
       }
    else
       {
        if(redac->GetCh_Fl())
         {
           this->WinName32=this->WinName;
           WinName32.resize(32);
           this->WinName32="*"+WinName32+"...";
           this->setWindowTitle(WinName32);

           this->WordNumb = redac->toPlainText().split(QRegExp("(\\s|\\n|\\r)+")
              , QString::SkipEmptyParts).count();

           this->SimbNumb=redac->toPlainText().length();
           this->Lines =(redac->document()->lineCount());
           this->FSize=redac->FSize;
           this->thirdS->setText("Lines:" + QString::number(Lines)+""+"Simbols:"+QString::number(SimbNumb)
                                 +" "+"Words:"+QString::number(WordNumb)+" "+"Size:"+QString::number(FSize));

           QTextCursor control_cur=redac->textCursor();
           this->cur_X=control_cur.columnNumber();
           this->cur_Y = control_cur.blockNumber()+1;
           this->firstS->setText("Line:"+QString::number(cur_Y)+" "+"Column:" + QString::number(cur_X));

         }
        else
         {
            this->WinName32=this->WinName;
            WinName32.resize(32);
            this->WinName32=WinName32+"...";
            this->setWindowTitle(WinName32);

            this->WordNumb=redac->WordNumb;
            this->SimbNumb=redac->SimbNumb;
            this->Lines=redac->Lines;
            this->FSize=redac->FSize;
            this->thirdS->setText("Lines:" + QString::number(Lines)+" "+"Simbols:"+QString::number(SimbNumb)
                                  +" "+"Words:"+QString::number(WordNumb)+" "+"Size:"+QString::number(FSize));

            this->date=redac->date;
            this->time=redac->time;

            if(this->date==QDate::currentDate())
              {
               this->secondS->setText("Time:"+ time.toString());
              }
            else
              {
                this->secondS->setText("Date"+date.toString()+" "+"Time:"+ time.toString());
                this->date=QDate::currentDate();
              }

            QTextCursor control_cur=redac->textCursor();
            this->cur_X=control_cur.columnNumber();
            this->cur_Y = control_cur.blockNumber()+1;
            this->firstS->setText("Line:"+QString::number(cur_Y)+" "+"Column:" + QString::number(cur_X));
         }
       }
}
void MainWindow::SetWinColor()
{
  this->WinColor=QColorDialog::getColor(Qt::white,this);
  QPalette pallet;
    if(WinColor.isValid())
     {
        pallet.setColor(QPalette::Base,WinColor);
        qApp->setPalette(pallet);
     }
    else
    {
      WinColor=Qt::white;
      pallet.setColor(QPalette::Base,WinColor);
      qApp->setPalette(pallet);
    }
}

void MainWindow::SetLineColor()
{
    this->LineCColor=QColorDialog::getColor(Qt::white,this);
      if(LineCColor.isValid())
       {
        this->redac->setTextBackgroundColor(LineCColor);

       }
      else
      {
       LineCColor=Qt::white;
       this->redac->setTextBackgroundColor(LineCColor);
      }
}

void MainWindow::SetFFont()
{
    bool ok;
    this->font = QFontDialog::getFont(&ok, QFont("Courier New", 12), this, "Choose Font");
    if (ok)
     {
       redac->setCurrentFont(font);
     }
    else
     {
      redac->setCurrentFont(QFont("Courier New", 12));
     }
}

void MainWindow::DateTime()
{
    this->time=QTime::currentTime();
    if(this->date==QDate::currentDate())
      {
       this->secondS->setText("Time:"+ time.toString());
      }
    else
      {
        this->secondS->setText("Date"+date.toString()+" "+"Time:"+ time.toString());
        this->date=QDate::currentDate();
      }

}

void MainWindow::WordWrap()
{
    if(this->Hyphenation->isChecked())
     {
        redac->setLineWrapMode(QTextEdit::FixedColumnWidth);
     }
    else
     {
        redac->setLineWrapMode(QTextEdit::NoWrap);
     }
}

void MainWindow::Ffind()
{
    redac->moveCursor(QTextCursor::Start);
    Find* dialog = new Find();
    dialog->exec();
    redac->find(dialog->GetFind());
    delete dialog;
}

void MainWindow::pods()
{
    if(SyntaLight->isChecked())
     {
      this->SyntaC89->setEnabled(true);
      this->SyntaCu98->setEnabled(true);
      this->SyntaCu1114->setEnabled(true);
      this->DefaultEd->setEnabled(true);
      highlighter = new Highlighter(redac->document());
      highlighter->getHigh(standart,style);

     }
    else
    {
        this->SyntaC89->setEnabled(false);
        this->SyntaCu98->setEnabled(false);
        this->SyntaCu1114->setEnabled(false);
        this->DefaultEd->setEnabled(false);
        delete  highlighter;
    }


}

void MainWindow::FindAndRep()
{
    redac->moveCursor(QTextCursor::Start);
    FindAndReplac* dialog=new FindAndReplac();
    dialog->exec();
    while (!redac->textCursor().isNull() && !redac->textCursor().atEnd())
    {
     if( redac->find(dialog->GetFind()))
     {
      redac->moveCursor(QTextCursor::Start);
      redac->find(dialog->GetFind());
      redac->insertPlainText(dialog->GetReplace());
     }
     else
     {
      redac->moveCursor(QTextCursor::End);
     }
    }
    delete dialog;
}

void MainWindow::numerat()
{
    if(Numeration->isChecked())
    {
        QString str;
        redac->moveCursor(QTextCursor::Start);
        for(int i=1;i<=redac->Lines;i++)
        {
          str=QString::number(i)+"|";
          redac->insertPlainText(str);
          redac->moveCursor(QTextCursor::Down);
          redac->moveCursor(QTextCursor::StartOfLine);
        }

    }
    else
    {
      redac->moveCursor(QTextCursor::Start);
      QString str;
      for(int i=1;i<=redac->Lines;i++)
        {
         str=QString::number(i)+"|";
         redac->find(str);
         redac->insertPlainText(" ");
    }
      }

}

void MainWindow::TextChanged()
{
    bool j=true;
    redac->SetCh_Fl(j);
}

MainWindow::~MainWindow()
{    
}
