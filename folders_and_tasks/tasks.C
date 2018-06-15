void tasks() {
   gROOT->ProcessLine(".L /home/satyshev/Documents/root_work/folders_and_tasks/MyTasks.cxx+");
   if (!TClass::GetDict("ABC")) {
      gROOT->ProcessLine(".L MyTasks.cxx+");
   }

   TTask *run = new MyRun("run","Process one run");
   TTask *event = new MyEvent("event","Process one event");
   TTask *geomInit = new MyGeomInit("geomInit", "Geometry Initialisation");
   TTask *matInit = new MyMaterialInit("matInit", "MaterialsInitialisation");
   TTask *tracker = new MyTracker("tracker","Tracker manager");
   TTask *tpc     = new MyRecTPC("tpc","TPC Reconstruction");
   TTask *its     = new MyRecITS("its","ITS Reconstruction");
   TTask *muon    = new MyRecMUON("muon","MUON Reconstruction");
   TTask *phos    = new MyRecPHOS("phos","PHOS Reconstruction");
   TTask *rich    = new MyRecRICH("rich","RICH Reconstruction");
   TTask *trd     = new MyRecTRD("trd","TRD Reconstruction");
   TTask *global  = new MyRecGlobal("global","Global Reconstruction");

   // Create a hierarchy by adding sub tasks
   run->Add(geomInit);
   run->Add(matInit);
   run->Add(event);
   event->Add(tracker);
   event->Add(global);
   tracker->Add(tpc);
   tracker->Add(its);
   tracker->Add(muon);
   tracker->Add(phos);
   tracker->Add(rich);
   tracker->Add(trd);

   // Add the top level task
   gROOT->GetListOfTasks()->Add(run);

   // Add the task to the browser
   gROOT->GetListOfBrowsables()->Add(run);

   new TBrowser;
}
