#include "textedit.h"

TextEdit::TextEdit(QWidget *parent) :
    QTextEdit(parent),fileName(""),Change_Flag(false),SimbNumb(0),WordNumb(0),Lines(0),FSize(0)
  ,date(QDate::currentDate())
{
}
void TextEdit::oopen()
{
    this->fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
        tr("Text Files (*.txt);;C++ Files (*.cpp *.h);;C89 Files (*.c *.h)"));

    if (fileName != "")
    {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly))
         {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
         }
        QTextStream in(&file);
        this->setText(in.readAll());
        this->FSize=(file.size())/1000;
        file.close();
        this->Change_Flag=false;
    }
    this->WordNumb = this->toPlainText().split(QRegExp("(\\s|\\n|\\r)+")
       , QString::SkipEmptyParts).count();

    this->SimbNumb=this->toPlainText().length();
    this->Lines =(this->document()->lineCount());

}
void TextEdit::ssave()
{
    if (fileName != "")
    {

        svfale=fileName.toStdString();
        svfale=svfale.substr(fileName.size()-2,2);
        if(svfale=="xt"||svfale==".c"||svfale=="pp"||svfale==".h")
         {
           fileName=fileName;
         }
        else
         {
            fileName=fileName+".txt";
         }
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly))
          {
            QMessageBox::critical(this, tr("Error"), tr("Could not save file"));
            return;
          }
        else
        {
            QTextStream stream(&file);
            stream <<this->toPlainText();
            stream.flush();
            this->FSize=(file.size())/1000;
            file.close();
            this->Change_Flag=false;
        }
    }
    this->WordNumb = this->toPlainText().split(QRegExp("(\\s|\\n|\\r)+")
       , QString::SkipEmptyParts).count();

    this->SimbNumb=this->toPlainText().length();
    this->Lines =(this->document()->lineCount());
    this->time=QTime::currentTime();
    this->date=QDate::currentDate();

}

void TextEdit::ssaveHow()
{
    this->fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "",
    tr("Text Files (*.txt);;C++ Files (*.cpp *.h);;C89 Files (*.c *.h)"));

    if (fileName != "")
    {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly))
          {
            QMessageBox::critical(this, tr("Error"), tr("Could not save file"));
            return;
          }
        else
        {
            QTextStream stream(&file);
            stream <<this->toPlainText();
            stream.flush();
            this->FSize=(file.size())/1000;
            file.close();
            this->Change_Flag=false;
        }
    }
    this->WordNumb = this->toPlainText().split(QRegExp("(\\s|\\n|\\r)+")
       , QString::SkipEmptyParts).count();

    this->SimbNumb=this->toPlainText().length();
    this->Lines =(this->document()->lineCount());
    this->time=QTime::currentTime();
    this->date=QDate::currentDate();
}
void TextEdit::New()
{
  this->fileName="New";
  this->clear();
  this->Change_Flag=true;
  this->FSize=0;
  this->Lines=1;
}

void TextEdit::contextMenuEvent(QContextMenuEvent *event)
{


    QMenu *menu = createStandardContextMenu();
    this->SelectStr=menu->addAction("Select String");
    connect(SelectStr,SIGNAL(triggered()),this,SLOT(SelectStri()));
    this->Select=menu->addAction("Select");
    connect(Select,SIGNAL(triggered()),this,SLOT(Selllect()));
    menu->exec(event->globalPos());
    delete menu;
}

QString TextEdit::GetName()
{
  return this->fileName;
}
bool TextEdit::GetCh_Fl()
{
  return this->Change_Flag;
}
void TextEdit::SetCh_Fl(bool fl)
{
  this->Change_Flag=fl;
}
void TextEdit::Selllect()
{
    QTextCursor textCursor = this->textCursor();
    textCursor.select(QTextCursor::WordUnderCursor);
    this->setTextCursor(textCursor);
}
void TextEdit::SelectStri()
{
    QTextCursor cursor=this->textCursor();
    cursor.movePosition(QTextCursor::StartOfLine);
    cursor.movePosition(QTextCursor::EndOfLine, QTextCursor::KeepAnchor);
    this->setTextCursor(cursor);
}
