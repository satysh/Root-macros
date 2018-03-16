void histoAndBorder()
{
	TH2D* h1 = new TH2D("h1", "Test Histo", 100, -5., 5., 100, -5., 5.);
	
	TRandom* r1 = new TRandom();

	for(Int_t i = 0; i < 9999999; i++)
	{
		Double_t rnd = r1->Gaus(0., 5.);
		Double_t rnd1 = r1->Gaus(0., 5.);
		h1->Fill(rnd, rnd1);
	}

	TCanvas* canv = new TCanvas("canv", "Test canvas", 800, 800);

	TF1* f1 = new TF1("f1", "-1", -1., 1.);
	TF1* f2 = new TF1("f1", "1", -1., 1.);
	
	const Int_t dotsNum = 100;
	Double_t xBord[dotsNum];
	Double_t yBord[dotsNum];
	Int_t bordStep = -50;
	for(Int_t i = 0; i < dotsNum; i++)
	{
		xBord[i] = -1.;
		yBord[i] = (Double_t)(bordStep*0.02);
		bordStep++;
	}
	TGraph* f3 = new TGraph(dotsNum, xBord, yBord);

	bordStep = -50;
	for(Int_t i = 0; i < dotsNum; i++)
	{
		xBord[i] = 1.;
		yBord[i] = (Double_t)(bordStep*0.02);
		bordStep++;
	}
	TGraph* f4 = new TGraph(dotsNum, xBord, yBord);

	h1->Draw("COL");

	f1->Draw("same");
	f2->Draw("same");
	f3->Draw("same");
	f4->Draw("same");
	f1->SetLineColor(kBlack);
	f2->SetLineColor(kBlack);
	f3->SetLineColor(kBlack);
	f4->SetLineColor(kBlack);
	f1->SetLineWidth(2);
	f2->SetLineWidth(2);
	f3->SetLineWidth(2);
	f4->SetLineWidth(2);

}