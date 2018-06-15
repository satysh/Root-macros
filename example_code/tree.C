struct event {
	Int_t a;
	Int_t b;
};

void tree()
{
	TFile* f = new TFile("out.root", "RECREATE");

	event object;
	TTree* t = new TTree("t", "myTree");
	t->Branch("brA", &object.a, "memberA/I");
	t->Branch("brB", &object.b, "memberB/I");

	for(Int_t i = 0; i < 10000; i++)
	{
		object.a = i;
		object.b = i;
		t->Fill();
	}

	t->Write();

	t->StartViewer();

	TCanvas* canv = new TCanvas("canv", "canv");
}
