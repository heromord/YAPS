#ifndef TEXTHIGLIGT_H
#define TEXTHIGLIGT_H

#include <QSyntaxHighlighter>
#include <QHash>
#include <QTextCharFormat>

class QTextDocument;

class Highlighter : public QSyntaxHighlighter
{
     Q_OBJECT

 public:
     Highlighter(QTextDocument *parent = 0);
     void getHigh(QString &standart, int style);

 protected:
     void highlightBlock(const QString &text);

 private:
     struct HighlightingRule
     {
         QRegExp pattern;
         QTextCharFormat format;
     };
     QVector<HighlightingRule> highlightingRules;

     QRegExp commentStartExpression;
     QRegExp commentEndExpression;

     QTextCharFormat keywordFormat1;
     QTextCharFormat keywordFormat2;
     QTextCharFormat singleLineCommentFormat;
     QTextCharFormat multiLineCommentFormat;
     QTextCharFormat quotationFormat;
     QTextCharFormat tfFormat;

     QTextCharFormat CFormat;
     QTextCharFormat inc;
     QTextCharFormat def;
     QTextCharFormat end;
     QTextCharFormat ifnd;
};

#endif // TEXTHIGLIGT_H
