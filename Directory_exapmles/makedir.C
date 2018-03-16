void makedir()
{
	TH1::AddDirectory(kFALSE);

	TH1F* h1 = new TH1F("h1", "Histo 1", 100, -1., 1.);
	h1->FillRandom("gaus", 10000);
//	h1->Draw();


	// Export -----------------------------------------------------

	TFile* f = new TFile("DirTest.root", "RECREATE");

	f->mkdir("Histo1");
	f->cd("Histo1");
	f->mkdir("Histo1/other");
	f->cd("Histo1/other");

	h1->Write();

	f->Close();
}