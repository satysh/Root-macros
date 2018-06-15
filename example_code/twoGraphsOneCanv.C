void twoGraphsOneCanv()
{
	const Int_t n = 20;
	Double_t x[n];
	Double_t y[n];
	Double_t y1[n];
	for(Int_t i = 0 ; i < n; i++)
	{
		x[i] = 0.5*i;
		y[i] = 5*cos(x[i] + 0.2);
		y1[i]  = 5*sin(x[i] + 0.2);
	}
	TGraph* gr1 = new TGraph(n, x, y);
	TGraph* gr2 = new TGraph(n, x, y1);
	TCanvas* c1 = new TCanvas("c1", "Two Graphs", 200, 10, 600, 400);
	gr1->SetLineColor(4);
	gr1->Draw("AC*");
	gr2->SetLineWidth(3);
	gr2->SetMarkerStyle(21);
	gr2->SetLineColor(2);
	gr2->Draw("CP");
}