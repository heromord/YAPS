#include <QtGui>
#include "texthigligt.h"

 Highlighter::Highlighter(QTextDocument *parent)
     : QSyntaxHighlighter(parent)
 {
    }

void Highlighter::getHigh(QString &standart,int style){
      HighlightingRule rule;
     if (style == 0){
             keywordFormat1.setForeground(Qt::darkGreen);
         keywordFormat1.setFontWeight(QFont::Bold);
     }else if(style == 1) {
         keywordFormat1.setFontItalic(true);
         keywordFormat1.setForeground(Qt::darkGreen);
             keywordFormat1.setFontWeight(QFont::Bold);

     }
     else if (style == 2){
         keywordFormat1.setForeground(Qt::green);
             keywordFormat1.setFontWeight(QFont::Normal);

     }else if (style == 3){
          keywordFormat1.setFontItalic(true);
          keywordFormat1.setForeground(Qt::green);
              keywordFormat1.setFontWeight(QFont::Normal);

     }
     QStringList keywordPatterns1;
     if (standart == "C89" || standart == "C++99/03" || standart == "C++11/14"){
     keywordPatterns1 << "\\bchar\\b" << "\\bauto\\b" << "\\bconst\\b"
                     << "\\bdouble\\b" << "\\benum\\b" << "\\bextern\\b"
                     << "\\bfloat\\b" << "\\bint\\b" << "\\bregister\\b"
                     << "\\blong\\b" << "\\bshort\\b" << "\\bsigned\\b"
             << "\\bstatic\\b" << "\\bstruct\\b" << "\\typedef\\b"
                     << "\\bunion\\b" << "\\bunsigned\\b" << "\\bvoid\\b"
                     << "\\bvolatile\\b";
     }
     if (standart == "C++99/03" || standart == "C++11/14"){
         keywordPatterns1 << "\\bbool\\b" << "\\bclass\\b" << "\\bexplicit\\b"
                     << "\\bexport\\b" << "\\binline\\b" << "\\bmutable\\b"
                     << "\\bnamespace\\b" << "\\btemplate\\b" << "\\btypename\\b"
                     << "\\bvirtual\\b" << "\\bwchar_t\\b" << "\\bfinal\\b"
             << "\\boverride\\b";
     }
     if (standart == "C++11/14"){
         keywordPatterns1 << "\\balignas\\b" << "\\bauto\\b" << "\\bchar16_t\\b"
                      << "\\bchar32_t\\b" << "\\bconstexpr\\b" << "\\bdecltype\\b"
                  << "\\thread_local\\b";
     }
     foreach (const QString &pattern, keywordPatterns1) {
         rule.pattern = QRegExp(pattern);
         rule.format = keywordFormat1;
         highlightingRules.append(rule);
     }

     if (style == 0){
         keywordFormat2.setForeground(Qt::darkRed);
             keywordFormat2.setFontWeight(QFont::Bold);

     }else if(style == 1) {
         keywordFormat2.setFontItalic(true);

         keywordFormat2.setForeground(Qt::darkRed);
             keywordFormat2.setFontWeight(QFont::Bold);

     }
     else if (style == 2){
         keywordFormat2.setForeground(Qt::red);
             keywordFormat2.setFontWeight(QFont::Normal);

     }else if (style == 3){
         keywordFormat2.setFontItalic(true);
         keywordFormat2.setForeground(Qt::red);
         keywordFormat2.setFontWeight(QFont::Normal);

     }

          QStringList keywordPatterns2;
     if (standart == "C89" || standart == "C++99/03" || standart == "C++11/14"){
     keywordPatterns2 << "\\bbreak\\b" << "\\bcase\\b" << "\\bcontinue\\b"
                     << "\\bdefault\\b" << "\\bdo\\b" << "\\else\\b"
                     << "\\bfor\\b" << "\\bgoto\\b" << "\\bif\\b"
                     << "\\breturn\\b" << "\\bsizeof\\b" << "\\bswitch\\b"
             << "\\bwhile\\b";
     }
     if (standart == "C++99/03" || standart == "C++11/14"){
         keywordPatterns2 << "\\basm\\b" << "\\bcatch\\b" << "\\bconst_cast\\b"
                          << "\\bdelete\\b" << "\\bdynamic_cast\\b" << "\\friend\\b"
                              << "\\bnew\\b" << "\\boperator\\b" << "\\bprivate\\b"
                          << "\\bprotected\\b" << "\\bpublic\\b" << "\\breinterpret_cast\\b"
                  << "\\bstatic_cast\\b" << "\\bthis\\b" << "\\bthrow\\b"
                  << "\\btry\\b" << "\\btypeid\\b" << "\\busing\\b";

     }
     if (standart == "C++11/14"){
         keywordPatterns2 << "\\balignog\\b" << "\\bnoexcept\\b" << "\\bstatic_assert\\b"
             <<"\\band\\b" << "\\band_eq\\b" << "\\bbitand\\b" << "\\bbitor\\b"
             <<"\\bcompl\\b" << "\\bnot\\b" << "\\bnot_eq\\b" << "\\bor\\b"
             <<"\\bor_eq\\b" << "\\bxor\\b" << "\\bxor_eq\\b";
     }


     foreach (const QString &pattern, keywordPatterns2) {
         rule.pattern = QRegExp(pattern);
         rule.format = keywordFormat2;
         highlightingRules.append(rule);
     }

     if (style == 0){
         def.setForeground(Qt::darkMagenta);
         end.setForeground(Qt::darkMagenta);
         ifnd.setForeground(Qt::darkMagenta);
         inc.setForeground(Qt::darkMagenta);
         CFormat.setForeground(Qt::magenta);
         quotationFormat.setForeground(Qt::magenta);
         tfFormat.setForeground(Qt::magenta);
         singleLineCommentFormat.setForeground(Qt::blue);
             multiLineCommentFormat.setForeground(Qt::blue);
     }else if (style == 1){
         def.setForeground(Qt::darkMagenta);
         end.setForeground(Qt::darkMagenta);
         ifnd.setForeground(Qt::darkMagenta);
         inc.setForeground(Qt::darkMagenta);
         CFormat.setForeground(Qt::magenta);
         quotationFormat.setForeground(Qt::magenta);
         tfFormat.setForeground(Qt::magenta);
         singleLineCommentFormat.setForeground(Qt::blue);
             multiLineCommentFormat.setForeground(Qt::blue);
         def.setFontWeight(QFont::Bold);
         end.setFontWeight(QFont::Bold);
         ifnd.setFontWeight(QFont::Bold);
         inc.setFontWeight(QFont::Bold);
         CFormat.setFontWeight(QFont::Bold);
         quotationFormat.setFontWeight(QFont::Bold);
         tfFormat.setFontWeight(QFont::Bold);
         singleLineCommentFormat.setFontWeight(QFont::Bold);
         multiLineCommentFormat.setFontWeight(QFont::Bold);
     }else if (style == 2){
         def.setForeground(Qt::darkMagenta);
         end.setForeground(Qt::darkMagenta);
         ifnd.setForeground(Qt::darkMagenta);
         inc.setForeground(Qt::darkMagenta);
         CFormat.setForeground(Qt::magenta);
         quotationFormat.setForeground(Qt::magenta);
         tfFormat.setForeground(Qt::magenta);
         singleLineCommentFormat.setForeground(Qt::blue);
             multiLineCommentFormat.setForeground(Qt::blue);
         def.setFontItalic(true);
         end.setFontItalic(true);
         ifnd.setFontItalic(true);
         inc.setFontItalic(true);
         CFormat.setFontItalic(true);
         quotationFormat.setFontItalic(true);
         tfFormat.setFontItalic(true);
         singleLineCommentFormat.setFontItalic(true);
             multiLineCommentFormat.setFontItalic(true);

     }else if (style == 3){
         def.setForeground(Qt::darkMagenta);
         end.setForeground(Qt::darkMagenta);
         ifnd.setForeground(Qt::darkMagenta);
         inc.setForeground(Qt::darkMagenta);
         CFormat.setForeground(Qt::magenta);
         quotationFormat.setForeground(Qt::magenta);
         tfFormat.setForeground(Qt::magenta);
         singleLineCommentFormat.setForeground(Qt::blue);
             multiLineCommentFormat.setForeground(Qt::blue);
         def.setFontWeight(QFont::Bold);
         end.setFontWeight(QFont::Bold);
         ifnd.setFontWeight(QFont::Bold);
         inc.setFontWeight(QFont::Bold);
         CFormat.setFontWeight(QFont::Bold);
         quotationFormat.setFontWeight(QFont::Bold);
         tfFormat.setFontWeight(QFont::Bold);
         singleLineCommentFormat.setFontWeight(QFont::Bold);
         multiLineCommentFormat.setFontWeight(QFont::Bold);
         def.setFontItalic(true);
         end.setFontItalic(true);
         ifnd.setFontItalic(true);
         inc.setFontItalic(true);
         CFormat.setFontItalic(true);
         quotationFormat.setFontItalic(true);
         tfFormat.setFontItalic(true);
         singleLineCommentFormat.setFontItalic(true);
             multiLineCommentFormat.setFontItalic(true);

     }
     rule.pattern = QRegExp("#define [A-Za-z_=()0-9 ]+$");
     rule.format = def;
     highlightingRules.append(rule);

     rule.pattern = QRegExp("#endif");
     rule.format = end;
     highlightingRules.append(rule);

     rule.pattern = QRegExp("#ifndef [A-Za-z_]+$");
     rule.format = ifnd;
     highlightingRules.append(rule);


     rule.pattern = QRegExp("(#include|#pragma once)");
     rule.format = inc;
     highlightingRules.append(rule);

     rule.pattern = QRegExp("[A-Za-z./]+(?=>)");
     rule.format = CFormat;
     highlightingRules.append(rule);

     rule.pattern = QRegExp("\".*\"");
     rule.format = quotationFormat;
     highlightingRules.append(rule);


     rule.pattern = QRegExp("(\\b[0-9]+\\b|true|false)");
     rule.format = tfFormat;
     highlightingRules.append(rule);


     rule.pattern = QRegExp("//[^\n]*");
     rule.format = singleLineCommentFormat;
     highlightingRules.append(rule);



     commentStartExpression = QRegExp("/\\*");
     commentEndExpression = QRegExp("\\*/");

}


 void Highlighter::highlightBlock(const QString &text)
 {
     foreach (const HighlightingRule &rule, highlightingRules) {
         QRegExp expression(rule.pattern);
         int index = expression.indexIn(text);
         while (index >= 0) {
             int length = expression.matchedLength();
             setFormat(index, length, rule.format);
             index = expression.indexIn(text, index + length);
         }
     }
     setCurrentBlockState(0);

     int startIndex = 0;
     if (previousBlockState() != 1)
         startIndex = commentStartExpression.indexIn(text);

     while (startIndex >= 0) {
         int endIndex = commentEndExpression.indexIn(text, startIndex);
         int commentLength;
         if (endIndex == -1) {
             setCurrentBlockState(1);
             commentLength = text.length() - startIndex;
         } else {
             commentLength = endIndex - startIndex
                             + commentEndExpression.matchedLength();
         }
         setFormat(startIndex, commentLength, multiLineCommentFormat);
         startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
     }
 }
