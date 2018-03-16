void fit_test()
{
	srand(time(NULL));
	TCanvas *c1 = new TCanvas("c1", "Fit Test", 1);
	TH1F *h1 = new TH1F("h1", "Fit Test", 16, -4, 4);
	for(Int_t i = 0; i < 100; i++)
	{
		int rnd = -4 + rand()%8;
		h1 -> Fill(rnd);
	}
	TF1 *f1 = new TF1("f1", "x*sin(x)", -4,4);
	c1 -> Divide(2, 1);
	c1 -> cd(1);
	f1 -> Draw();
	c1 -> cd(2);
	//h1 -> FillRandom("landau", 1000);
	//h1 -> Fill(1, 10);
	//h1 -> Draw("E");
	h1 -> Draw();
	return;
}