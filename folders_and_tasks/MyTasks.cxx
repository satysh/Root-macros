#include "TTask.h"
//-------------------------------------------------------------------
class MyRun : public TTask {
public:
   MyRun() { ; }
   MyRun(const char *name,const char *title);
   virtual ~MyRun() { ; }
   void Exec(Option_t *option="");
   ClassDef(MyRun,1)
};
ClassImp(MyRun)
MyRun::MyRun(const char *name,const char *title):TTask(name,title)
{
}
void MyRun::Exec(Option_t *option)
{
   printf("MyRun executingn");
}
//---------------------------------------------------------------------
class MyEvent : public TTask {
public:
   MyEvent() { ; }
   MyEvent(const char *name,const char *title);
   virtual ~MyEvent() { ; }
   void Exec(Option_t *option="");
   ClassDef(MyEvent,1)   //
};
ClassImp(MyEvent)
MyEvent::MyEvent(const char *name,const char *title):TTask(name,title)
{
}
void MyEvent::Exec(Option_t *option)
{
   printf("MyEvent executingn");
}
//--------------------------------------------------------------------
class MyGeomInit : public TTask {
public:
   MyGeomInit() { ; }
   MyGeomInit(const char *name,const char *title);
   virtual ~MyGeomInit() { ; }
   void Exec(Option_t *option="");
   ClassDef(MyGeomInit,1)
};
ClassImp(MyGeomInit)
MyGeomInit::MyGeomInit(const char *name,const char *title):TTask(name,title)
{
}
void MyGeomInit::Exec(Option_t *option)
{
   printf("MyGeomInit executingn");
}
//--------------------------------------------------------------------
class MyMaterialInit : public TTask {
public:
   MyMaterialInit() { ; }
   MyMaterialInit(const char *name,const char *title);
   virtual ~MyMaterialInit() { ; }
   void Exec(Option_t *option="");
   ClassDef(MyMaterialInit,1)
};
ClassImp(MyMaterialInit)
MyMaterialInit::MyMaterialInit(const char *name,const char *title):TTask(name,title)
{
}
void MyMaterialInit::Exec(Option_t *option)
{
   printf("MyMaterialInit executingn");
}
//----------------------------------------------------------------------
class MyTracker : public TTask {
public:
   MyTracker() { ; }
   MyTracker(const char *name,const char *title);
   virtual ~MyTracker() { ; }
   void Exec(Option_t *option="");
   ClassDef(MyTracker,1)
};
ClassImp(MyTracker)
MyTracker::MyTracker(const char *name,const char *title):TTask(name,title)
{
}
void MyTracker::Exec(Option_t *option)
{
   printf("MyTracker executingn");
}
//-----------------------------------------------------------------------
class MyRecTPC : public TTask {
public:
   MyRecTPC() { ; }
   MyRecTPC(const char *name,const char *title);
   virtual ~MyRecTPC() { ; }
   void Exec(Option_t *option="");
   ClassDef(MyRecTPC,1)
};
ClassImp(MyRecTPC)
MyRecTPC::MyRecTPC(const char *name,const char *title):TTask(name,title)
{
}
void MyRecTPC::Exec(Option_t *option)
{
   printf("MyRecTPC executingn");
}
//---------------------------------------------------------------------
class MyRecITS : public TTask {
public:
   MyRecITS() { ; }
   MyRecITS(const char *name,const char *title);
   virtual ~MyRecITS() { ; }
   void Exec(Option_t *option="");
   ClassDef(MyRecITS,1)
};
ClassImp(MyRecITS)
MyRecITS::MyRecITS(const char *name,const char *title):TTask(name,title)
{
}
void MyRecITS::Exec(Option_t *option)
{
   printf("MyRecITS executingn");
}
//---------------------------------------------------------------------
class MyRecMUON : public TTask {
public:
   MyRecMUON() { ; }
   MyRecMUON(const char *name,const char *title);
   virtual ~MyRecMUON() { ; }
   void Exec(Option_t *option="");
   ClassDef(MyRecMUON,1)
};
ClassImp(MyRecMUON)
MyRecMUON::MyRecMUON(const char *name,const char *title):TTask(name,title)
{
}
void MyRecMUON::Exec(Option_t *option)
{
   printf("MyRecMUON executingn");
}
//---------------------------------------------------------------------
class MyRecPHOS : public TTask {
public:
   MyRecPHOS() { ; }
   MyRecPHOS(const char *name,const char *title);
   virtual ~MyRecPHOS() { ; }
   void Exec(Option_t *option="");
   ClassDef(MyRecPHOS,1)
};
ClassImp(MyRecPHOS)
MyRecPHOS::MyRecPHOS(const char *name,const char *title):TTask(name,title)
{
}
void MyRecPHOS::Exec(Option_t *option)
{
   printf("MyRecPHOS executingn");
}
//---------------------------------------------------------------------
class MyRecRICH : public TTask {
public:
   MyRecRICH() { ; }
   MyRecRICH(const char *name,const char *title);
   virtual ~MyRecRICH() { ; }
   void Exec(Option_t *option="");
   ClassDef(MyRecRICH,1)
};
ClassImp(MyRecRICH)
MyRecRICH::MyRecRICH(const char *name,const char *title):TTask(name,title)
{
}
void MyRecRICH::Exec(Option_t *option)
{
   printf("MyRecRICH executingn");
}
//---------------------------------------------------------------------
class MyRecTRD : public TTask {
public:
   MyRecTRD() { ; }
   MyRecTRD(const char *name,const char *title);
   virtual ~MyRecTRD() { ; }
   void Exec(Option_t *option="");
   ClassDef(MyRecTRD,1)
};
ClassImp(MyRecTRD)
MyRecTRD::MyRecTRD(const char *name,const char *title):TTask(name,title)
{
}
void MyRecTRD::Exec(Option_t *option)
{
   printf("MyRecTRD executingn");
}
//---------------------------------------------------------------------
class MyRecGlobal : public TTask {
public:
   MyRecGlobal() { ; }
   MyRecGlobal(const char *name,const char *title);
   virtual ~MyRecGlobal() { ; }
   void Exec(Option_t *option="");
   ClassDef(MyRecGlobal,1)
};
ClassImp(MyRecGlobal)
MyRecGlobal::MyRecGlobal(const char *name,const char *title):TTask(name,title)
{
}
void MyRecGlobal::Exec(Option_t *option)
{
   printf("MyRecGlobal executingn");
}
//---------------------------------------------------------------------
