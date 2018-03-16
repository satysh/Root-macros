void Line()
{
	TCanvas* canv = new TCanvas("canv", "Test Line on histo", 800, 800);
	canv->Divide(1, 2);
	TH2D* histo = new TH2D("histo", "Test Line on histo", 100, 0., 99., 100, 0., 99.);
	histo->SetMinimum(0.);
	histo->SetMaximum(50.);
	for(Int_t i = 0; i < 100; i++){
		for(Int_t j = 0; j < 100; j++){
			histo->SetBinContent((Double_t)i, (Double_t)j, (Double_t)j, (Double_t)i);
			histo->SetBinContent((Double_t)i, (Double_t)j, (Double_t)j, (Double_t)i);
		}
	}

	canv->cd(1);
	histo->Draw("COLZ");
	TLine* l1 = new TLine;
	l1->SetLineWidth(2);
	l1->SetLineColor(kRed);
	l1->DrawLine(30, 60., 60., 60.);
	l1->DrawLine(30., 30., 60., 30.);
	l1->DrawLine(60., 30., 60., 60.);
	l1->DrawLine(30., 30., 30., 60.);

	gStyle->SetOptStat(1111111);
	gStyle->SetPalette(kBird, 0, 57.);
	canv->cd(2);
	histo->Draw("COLZ");

	/*gStyle->SetMinimum(0.);
  	gStyle->SetMaximum(0.05);*/

}