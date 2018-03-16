void twoDH()
{
					//	(name, title, nbinsx, xlow, xup, nybins, ylow, yup)
	TH2F *h1 = new TH2F("h1", "2D histo", 6, -1., 1., 6, -1., 1.);
	//h1 -> FillRandom("gaus");
	/*for(Int_t i = 0; i < 1000; i++)
	{
		Double_t rnd1 = -10 + rand()%20;
		Double_t rnd2 = -10 + rand()%20;
		h1 = Fill(rnd1, rnd2);
	}*/
	for(Int_t i = -1000; i < 1000; i++)
	{
		for(Int_t j = -1000; j < 1000; j++)
		h1->Fill(0.001*i, 0.001*j);
	}
	h1->Draw("LEGO");
	cout << "finish";
}