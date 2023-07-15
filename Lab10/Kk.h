#ifndef KK_H
#define KK_H
#include <QObject>
#include <QTimerEvent>
#include <QFile>

#include <QFileInfo>
#include <QDir>
#include <QDebug>
#include <QString>
#include <QSocketNotifier>

#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <cmath>
#include <cstdlib>
#include <iterator>
using namespace std;


 class Klass :public QObject
 {
 Q_OBJECT

 public:
 vector <pair<QString, int> > fileInfo;
 vector <pair<QString, int> > savefile;
 int timer;
 int timerID;
 QSocketNotifier *notifier;

 void timerEvent(QTimerEvent* e);
 Klass();
 void stop ();
 void start ();
 void restart ();
 void timeout(int t);
 public slots:

 void CommandEntered();
 };

#endif // KK_H
