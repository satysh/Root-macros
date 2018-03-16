#include "TTask.h"

class MyRun : public TTask {
public:
    MyRun(){ ; }
    MyRun(const char* name, const char* title);
    virtual ~MyRun(){ ; }
    void Exec(Option_t* option="");
    ClassDef(MyRun, 1)
};

class MyEvent : public TTask {
public:
    MyEvent(){ printf("%s\n", "I work");; }
    MyEvent(const char* name, const char* title);
    virtual ~MyEvent(){ ; }
    void Exec(Option_t* option="");
    ClassDef(MyEvent, 1)
};

ClassImp(MyRun)
MyRun::MyRun(const char* name, const char* title) : TTask(name, title)
{

}
void MyRun::Exec(Option_t* option)
{
    printf("MyRun executing");
}