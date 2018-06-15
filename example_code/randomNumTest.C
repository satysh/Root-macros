void randomNumTest()
{
	TRandom3 *r1 = new TRandom3();
	TH1D *h1 = new TH1D("h1", "Histo", 2000, -10., 10.);
	for(Int_t i = 0; i < 100000; i++)
	{
		Double_t rnd = r1->Gaus(0.5, 0.6);
		h1->Fill(rnd);
	}
	const Double_t Pi = TMath::Pi();
	const char* funcExpr = "[2]*exp(-(x - [0])*(x - [0])/(2*[1]*[1]))/sqrt(2*TMath::Pi()*[1]*[1])";
	TF1 *fa1 = new TF1("fa1", funcExpr, -10., 10.);
	fa1->SetParameter(0, 2.);
	fa1->SetParameter(1, 2.);
	fa1->SetParameter(2, 200.);
	//fa1->SetParameters(1, 0.5, 0.6);
	h1->Draw();
	//fa1->Draw("same");
	h1->Fit(fa1);
	gPad->SetGrid(1,1);
	gStyle->SetOptStat(1111111);
}
