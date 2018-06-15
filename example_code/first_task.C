void first_task()
{
	TCanvas *c1 = new TCanvas("c1", "Canvasss", 800, 800);
	c1 -> Divide(2, 1);
	c1 -> cd(1);
	TH1F *h1 = new TH1F("h1", "Random gaus", 100, -3, 3);
	h1 -> FillRandom("gaus", 1000);
	h1 -> GetXaxis() -> SetTitle("random numbers");
	h1 -> GetYaxis() -> SetTitle("number of numbers");
	h1 -> SetLineWidth(2);
	h1 -> Draw();
	c1 -> cd(2);
	Int_t n = 64*2;
	Double_t x[n], y[n];
	for(Int_t i = 0; i < n; i++)
	{
		x[i] = i*0.1;
		y[i] = sin(x[i]);
	}
	TGraph *gr1 = new TGraph(n, x, y);
	gr1 -> SetTitle("y = sin(x)");
	gr1 -> GetXaxis() -> SetTitle("x");
	gr1 -> GetYaxis() -> SetTitle("y");
	gr1 -> SetLineColor(kRed);
	gr1 -> SetLineWidth(3);
	gr1 -> Draw("ACP");
	return;
}
