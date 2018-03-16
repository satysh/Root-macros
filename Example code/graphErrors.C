void graphErrors()
{
	const Int_t n = 20;
	Double_t x[n];
	Double_t y[n];
	Double_t ex[n], ey[n];
	for(Int_t i = 0 ; i < n; i++)
	{
		x[i] = 0.5*i;
		y[i] = 5*sin(x[i] +0.12);
		if(i%2 == 0)
		{
			ex[i] = 0.1;
			ey[i] = 0.2;
		}
		else
		{
			ex[i] = 0.2;
			ey[i] = 0.1;
		}
	}

	TGraphErrors* gr = new TGraphErrors(n, x, y, ex, ey);
	gr->SetLineColor(4);
	gr->SetLineWidth(2);
	gr->SetMarkerStyle(29);
	gr->SetTitle("TGraphErrors Example");
	gr->Draw("ACP");

}