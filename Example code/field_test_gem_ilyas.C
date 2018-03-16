#include "bmnloadlibs.C"

void field_test_gem_ilyas()
{
	#if ROOT_VERSION_CODE < ROOT_VERSION(5,99,99)
    gROOT->LoadMacro("$VMCWORKDIR/macro/run/bmnloadlibs.C");
	#endif
    bmnloadlibs(); // load libraries
    TString in = "field_sp41v4_ascii_Extrap.root";
    BmnFieldMap* magField = new BmnNewFieldMap(in);
    magField->SetScale(1.3);
    magField->Init();

	magField->Print();

	const Int_t Nx = magField->GetNx();
	const Int_t Ny = magField->GetNy();
	const Int_t Nz = magField->GetNz();
	const Double_t Xmin = magField->GetXmin();
	const Double_t Xmax = magField->GetXmax();
	const Double_t Ymin = magField->GetYmin();
	const Double_t Ymax = magField->GetYmax();
	const Double_t Zmin = magField->GetZmin();
	const Double_t Zmax = magField->GetZmax();
	const Double_t Xstep = (Xmax - Xmin)/(Double_t)(Nx - 1);
	const Double_t Ystep = (Ymax - Ymin)/(Double_t)(Ny - 1);
	const Double_t Zstep = (Zmax - Zmin)/(Double_t)(Nz - 1);

	const Double_t small_gem_long = 66.;
	const Double_t small_gem_height = 41.;
	const Double_t small_gem_width = 23.;

	const Double_t Xgem1_Beg = -0.5*small_gem_long - 15.;
	const Double_t Xgem1_End = 0.5*small_gem_long - 15.;
	const Double_t Ygem1_Beg = -0.5*small_gem_height;
	const Double_t Ygem1_End = 0.5*small_gem_height;
	const Double_t Zgem1_Beg = 320.;
	const Double_t Zgem1_End = Zgem1_Beg + small_gem_width;


	const Double_t Xgem2_Beg = Xgem1_Beg;
	const Double_t Xgem2_End = Xgem1_End;
	const Double_t Ygem2_Beg = Ygem1_Beg;
	const Double_t Ygem2_End = Ygem1_End;
	const Double_t Zgem2_Beg = 638.;
	const Double_t Zgem2_End = Zgem2_Beg + small_gem_width;

	const Double_t Xgem3_Beg = Xgem1_Beg;
	const Double_t Xgem3_End = Xgem1_End;
	const Double_t Ygem3_Beg = Ygem1_Beg;
	const Double_t Ygem3_End = Ygem1_End;
	const Double_t Zgem3_Beg = 958.;
	const Double_t Zgem3_End = Zgem3_Beg + small_gem_width;

	const Double_t small_gem4_width = 25.;

	const Double_t Xgem4_Beg = -0.5*small_gem_long + 27.7;
	const Double_t Xgem4_End = 0.5*small_gem_long + 27.7;
	const Double_t Ygem4_Beg = Ygem1_Beg;
	const Double_t Ygem4_End = Ygem1_End;
	const Double_t Zgem4_Beg = 1278.;
	const Double_t Zgem4_End = Zgem4_Beg + small_gem4_width;

	const Double_t Xgem5_Beg = -0.5*small_gem_long - 34.7;
	const Double_t Xgem5_End = 0.5*small_gem_long - 34.7;
	const Double_t Ygem5_Beg = Ygem1_Beg;
	const Double_t Ygem5_End = Ygem1_End;
	const Double_t Zgem5_Beg = 1303.;
	const Double_t Zgem5_End = Zgem5_Beg + small_gem_width;

	const Double_t big_gem_long = 163.;
	const Double_t big_gem_height = 45.;
	const Double_t big_gem_width = 39.;
	
	const Double_t Xgem6_Beg = -0.5*big_gem_long;
	const Double_t Xgem6_End = 0.5*big_gem_long;
	const Double_t Ygem6_Beg = -0.5*big_gem_height;
	const Double_t Ygem6_End = 0.5*big_gem_height;
	const Double_t Zgem6_End = 1596.;
	const Double_t Zgem6_Beg = Zgem6_Beg + big_gem_width;

	const Double_t Xgem7_Beg = Xgem6_Beg;
	const Double_t Xgem7_End = Xgem6_End;
	const Double_t Ygem7_Beg = Ygem6_Beg;
	const Double_t Ygem7_End = Ygem6_End;
	const Double_t Zgem7_Beg = 1916.;
	const Double_t Zgem7_End = Zgem6_Beg + big_gem_width;

	const Int_t sgnNx = (Int_t)(small_gem_long/Xstep);
	const Int_t sgnNy = (Int_t)(small_gem_height/Ystep);

	const Int_t small_gem_histoNum = 3;
	TH2D* histoBx_small_gem[small_gem_histoNum];
	TH2D* histoBy_small_gem[small_gem_histoNum];
	TH2D* histoBz_small_gem[small_gem_histoNum];
	for(Int_t i = 0; i < small_gem_histoNum; i++)
	{
		TString histoName;
		histoName.Form("histoBxGEM_%d", i);
		histoBx_small_gem[i] = new TH2D(histoName, histoName, sgnNx, Xgem1_Beg, Xgem1_End, sgnNy, Ygem1_Beg, Ygem1_End);
		histoName.Form("histoByGEM_%d", i);
		histoBx_small_gem[i] = new TH2D(histoName, histoName, sgnNx, Xgem1_Beg, Xgem1_End, sgnNy, Ygem1_Beg, Ygem1_End);
		histoName.Form("histoBzGEM_%d", i);
		histoBx_small_gem[i] = new TH2D(histoName, histoName, sgnNx, Xgem1_Beg, Xgem1_End, sgnNy, Ygem1_Beg, Ygem1_End);
	}

	Double_t Zcur = Zgem1_Beg;
	for(Int_t i =0; i < sgnNx; i++)
	{
		Double_t Xcur = Xgem1_Beg + i*Xstep;
		for(Int_t j = 0; j < sgnNy; j++)
		{
			Double_t Ycur = Ygem1_Beg + i*Ystep;
			histoBx_small_gem[0]->SetBinContent(i+1, j+1, magField->GetBx(Xcur, Ycur, Zcur));
		}
	}

	Zcur = 0.5*(Zgem1_Beg + Zgem1_End);
	for(Int_t i =0; i < sgnNx; i++)
	{
		Double_t Xcur = Xgem1_Beg + i*Xstep;
		for(Int_t j = 0; j < sgnNy; j++)
		{
			Double_t Ycur = Ygem1_Beg + i*Ystep;
			histoBx_small_gem[1]->SetBinContent(i+1, j+1, magField->GetBx(Xcur, Ycur, Zcur));
		}
	}

	Zcur = Zgem1_End;
	for(Int_t i =0; i < sgnNx; i++)
	{
		Double_t Xcur = Xgem1_Beg + i*Xstep;
		for(Int_t j = 0; j < sgnNy; j++)
		{
			Double_t Ycur = Ygem1_Beg + i*Ystep;
			histoBx_small_gem[2]->SetBinContent(i+1, j+1, magField->GetBx(Xcur, Ycur, Zcur));
		}
	}

	TCanvas* canvBx = TCanvas("canv1", "Bx", 800, 800);
	TCanvas* canvBy = TCanvas("canv1", "By", 800, 800);
	TCanvas* canvBz = TCanvas("canv1", "Bz", 800, 800);

	canvBx->cd();
	histoBx_small_gem[0]->Draw(" ")
	
}