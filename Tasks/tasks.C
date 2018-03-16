#include "MyTasks.cxx"

void tasks()
{
    gROOT->ProcessLine(".L MyTasks.cxx+");

    TTask* run = new MyRun("run", "Process one run");
    TTask* event = new MyEvent("event", "Process one event");

    run->Add(event);

    gROOT->GetListOfTasks()->Add(run);

    gROOT->GetListOfBrowsables()->Add(run);
    new TBrowser;
}