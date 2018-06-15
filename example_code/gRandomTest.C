void gRandomTest()
{
	TH1F* h1 = new TH1F("h1", "gRandom histo", 10, -1., 1.);
	for(Int_t i = 0; i < 10000; i++)
	{
		Double_t  rnd, rnd1;
		gRandom->Rannor(rnd, rnd1);
		h1->Fill(rnd);
		h1->Fill(rnd1);
	}
	h1->Draw();
}