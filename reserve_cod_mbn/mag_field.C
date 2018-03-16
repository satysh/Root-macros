#include "bmnloadlibs.C"

void all_gem_field_ilyas(TString in = "field_sp41v4_ascii_Extrap.root")
{
	#if ROOT_VERSION_CODE < ROOT_VERSION(5,99,99)
    gROOT->LoadMacro("$VMCWORKDIR/macro/run/bmnloadlibs.C");
	#endif
    bmnloadlibs(); // load libraries

    BmnFieldMap* magField = new BmnNewFieldMap(in);
    magField->SetScale(1.3);
    magField->Init();

    magField->Print();

    const Double_t Xmin = magField->GetXmin();
    const Double_t Xmax = magField->GetXmax();
    const Int_t Nx = magField->GetNx();
    const Double_t Xstep = magField->GetXstep();
    const Double_t Ymin = magField->GetYmin();
    const Double_t Ymax = magField->GetYmax();
    const Int_t Ny = magField->GetNy();
    const Double_t Ystep = magField->GetYstep();

    const Int_t GemsNum = 7;
    const Int_t DivideNum = 16;

	Double_t ZgemBeg[GemsNum];    
	Double_t ZgemEnd[GemsNum];

	ZgemBeg[0] = 320.; ZgemEnd[0] = ZgemBeg[0] + 23.;
	ZgemBeg[1] = 638.; ZgemEnd[1] = ZgemBeg[1] + 23.;
	ZgemBeg[2] = 958.; ZgemEnd[2] = ZgemBeg[2] + 23.;
	ZgemBeg[3] = 1278.; ZgemEnd[3] = ZgemBeg[3] + 25.;
	ZgemBeg[4] = 1303.; ZgemEnd[4] = ZgemBeg[4] + 23.;
	ZgemBeg[5] = 1596.; ZgemEnd[5] = ZgemBeg[5] + 39.;
	ZgemBeg[6] = 1916.; ZgemEnd[6] = ZgemBeg[6] + 39.;
	
	TH2D* histoBx[GemsNum][DivideNum];
	TH2D* histoBy[GemsNum][DivideNum];
	TH2D* histoBz[GemsNum][DivideNum];
	for(Int_t n = 0; n < GemsNum; n++)
	{
		for(Int_t i = 0; i < DivideNum; i++)
		{
			TString histoName;
			histoName.Form("GEM%d_histo_Bx_%d", n+1, i+1);
			histoBx[n][i] = new TH2D(histoName, histoName, Nx, Xmin, Xmax, Ny, Ymin, Ymax);
			histoName.Form("GEM%d_histo_By_%d", n+1, i+1);
			histoBy[n][i] = new TH2D(histoName, histoName, Nx, Xmin, Xmax, Ny, Ymin, Ymax);
			histoName.Form("GEM%d_histo_Bz_%d", n+1, i+1);
			histoBz[n][i] = new TH2D(histoName, histoName, Nx, Xmin, Xmax, Ny, Ymin, Ymax);
		}
	}

	for(Int_t n = 0; n < GemsNum; n++)
	{
		Double_t Zstep = (ZgemBeg[n] - ZgemEnd[n])/(Double_t)(DivideNum - 1);
		for(Int_t i = 0; i < DivideNum; i++)
		{
			Double_t Zcur = ZgemBeg[n] + i*Zstep;
			for(Int_t j = 0; j < Nx; j++)
			{
				Double_t Xcur = Xmin + j*Xstep;
				for(Int_t k = 0; k < Ny; k++)
				{
					Double_t Ycur = Ymin + k*Ystep;
					histoBx[n][i]->SetBinContent(j+1, k+1, magField->GetBx(Xcur, Ycur, Zcur));
					histoBy[n][i]->SetBinContent(j+1, k+1, magField->GetBy(Xcur, Ycur, Zcur));
					histoBz[n][i]->SetBinContent(j+1, k+1, magField->GetBz(Xcur, Ycur, Zcur));
				}
			}
		}
	}

	TCanvas* canvBx[GemsNum];
	TCanvas* canvBy[GemsNum];
	TCanvas* canvBz[GemsNum];
	//const Int_t canvDivides = (Int_t)(DivideNum/4);
	for(Int_t n = 0; n < GemsNum; n++)
	{
		TString canvName;
		canvName.Form("GEM%d_Bx", n+1);
		canvBx[n] = new TCanvas(canvName, canvName, 800, 800);
		canvBx[n]->Divide(4, 4);
		canvName.Form("GEM%d_By", n+1);
		canvBy[n] = new TCanvas(canvName, canvName, 800, 800);
		canvBy[n]->Divide(4, 4);
		canvName.Form("GEM%d_Bz", n+1);
		canvBz[n] = new TCanvas(canvName, canvName, 800, 800);
		canvBz[n]->Divide(4, 4);
	}

	for(Int_t n = 0; n < GemsNum; n++)
	{
		for(Int_t i = 0; i < DivideNum; i++)
		{
			canvBx[n]->cd(i+1); histoBx[n][i]->Draw("COL");
			canvBy[n]->cd(i+1); histoBy[n][i]->Draw("COL");
			canvBz[n]->cd(i+1); histoBz[n][i]->Draw("COL");
		}
	}

	TFile* outputFile = new TFile("FieldMap_allGEMs_Zsections.root", "RECREATE");

	for(Int_t n = 0; n < GemsNum; n++)
	{
		TString dirName;
		dirName.Form("GEM%d_Bx", n+1);
		outputFile->mkdir(dirName);
		outputFile->cd(dirName);
		canvBx[n]->Write();
		outputFile->cd("..");
		dirName.Form("GEM%d_By", n+1);
		outputFile->mkdir(dirName);
		outputFile->cd(dirName);
		canvBy[n]->Write();
		outputFile->cd("..");
		dirName.Form("GEM%d_Bz", n+1);
		outputFile->mkdir(dirName);
		outputFile->cd(dirName);
		canvBz[n]->Write();
	}
}