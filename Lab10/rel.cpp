#include "Kk.h"
vector <pair<QString, int> > gfile;

struct cmp{
bool operator()(const QString a, const QString b)
{
int size1=0;
int size2=0;
for (size_t i = 0; i <gfile.size(); ++i)
{
    if(a==gfile[i].first){size1=gfile[i].second;}
    if(b==gfile[i].first){size2=gfile[i].second;}
}
if(size1==0||size2==0){exit(1);}
return size1<size2;
}
};


Klass:: Klass() :timer(5000)
{
    QString directory = QDir::currentPath();
    QDir dir(directory);

    if(!dir.exists())
    {
    qWarning("The directory does not exist");
    }

    dir.setFilter(QDir::Files );


    dir.setSorting(QDir::Size | QDir::Reversed);


    QFileInfoList list = dir.entryInfoList();
    vector <pair<QString, int> > file;

    for (int i = 0; i < list.size(); ++i)
    {

    QFileInfo fileInfo = list.at(i);
    QString name = fileInfo.fileName();
    unsigned int sz = fileInfo.size();
    file.push_back(make_pair(name, sz));
    }

this->fileInfo=file;
this->savefile=file ;
gfile=file;
notifier = new QSocketNotifier( fileno(stdin), QSocketNotifier::Read, this );
connect(notifier,SIGNAL(activated(int)),this,SLOT(CommandEntered()));
this->timerID=startTimer(timer);
}

void Klass::timerEvent(QTimerEvent *e)
{
    if ( this->timerID==e->timerId()){

    vector <pair<QString, int> > vec;
    vec=this->fileInfo;

    set <QString,cmp> st;
    for(size_t i = 0; i < vec.size(); ++i)
     {
        st.insert(vec[i].first);
     }
   if(st.empty())
    {
      cout<<"{}"<<endl<<">"<<endl;
    }
   else
   {
    set<QString,cmp>::iterator it;


    for (it = st.begin(); it != st.end(); ++it)
    {
        if(it==st.begin()){cout << "{"<<"";}
        cout <<(*it).toStdString() ;
        if(it!=(--st.end())){ cout<<", ";};
        if(it==(--st.end())){cout<<"} ";};
    }

    cout<<endl;
    cout<<">"<<endl;

     int t=0;
     int avg=0;
     int sum=0;

    for (size_t i = 0; i < vec.size(); ++i)
     {
      sum+=vec[i].second;
     }
    avg=sum/vec.size();
    int min = avg;
    for (size_t i = 0; i < vec.size(); ++i)
     {
      if(sqrt((vec[i].second-(avg*3/4)*(vec[i].second-(avg*3/4)))<=min))
      {
        min=vec[i].second;
        t=i;
      }
    }

    vec.erase(vec.begin() + t);
    this->fileInfo=vec;
   }
   }
else {this->timerID=e->timerId();}
}

void Klass::stop()
{
killTimer(this->timerID);
}
void Klass::start()
{
 this->timerID=startTimer(this->timer);
}
void Klass::restart()
{
    killTimer(this->timerID);
    this->fileInfo=this->savefile;
    this->timerID=startTimer(this->timer);
}
void Klass::timeout(int t)
{
this->timer=t;
this->stop();
this->timerID=startTimer(t);
}
void Klass::CommandEntered()
{
    string cmd;
    getline(std::cin,cmd);
    if(cmd=="stop"){this->stop();}
    else if(cmd=="start"){this->start();}
    else if(cmd=="restart"){this->restart();}
    else if(cmd=="exit"){exit(0);}
    else
    {
    if(0==cmd.find("timeout"))
    {
    cmd = cmd.substr(8,cmd.size() - 8);
    this->timeout(atoi(cmd.c_str()));
    }
    else{cout<<"Wrong command"<<endl;}
    }
}
