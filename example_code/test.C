void test()
{

	cout << "asdasdasda" << endl;

	TCanvas* canv = new TCanvas("canv", "canv");
	TH1D* histo = new TH1D("histo", "histo", 100, 0., 100.);

	for (UInt_t i=0; i<10000; i++) {
		Double_t a = rand() % 100;
		histo->Fill(a);
	}

	histo->Draw();
	histo->GetXaxis()->SetTitle("alibaba");
	histo->GetYaxis()->SetTitle("baba-yaga");
	histo->SetLineColor(kRed);
	histo->SetLineWidth(4);
	gPad->SetGrid(1, 1);
	gStyle->SetOptStat(111111111);

	return;
}
