void canvas_examp()
{
	TCanvas* canv = new TCanvas("canv", "canv");
	TH1F *h1 = new TH1F("h1", "first histo", 100, -2, 2);
	h1 -> FillRandom("gaus", 1000);
	canv -> Divide(2, 1);
	canv -> cd(1);
	h1 -> Draw();
	TH1F *h2 = new TH1F("h2", "second histo", 10, -1, 1);
	h2 -> FillRandom("gaus", 100);
	canv -> cd(2);
	h2 -> Draw();
	return;
}