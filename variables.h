#ifndef VARIABLES_H

#define VARIABLES_H

#define _MAX_TRACKS 1000
#define _N_DIM      4
#define _N_MODULES  240

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1.h>
#include <TTree.h>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TH2F.h>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <TMath.h>

using TMath::Abs;
using TMath::Cos;
using TMath::Sin;
using TMath::ATan2;
using TMath::Sqrt;
using TMath::LocMin;
using TMath::Pi;

using std::cout;
using std::endl;

class Qvector
{
public:
	Double_t Tpc0X1;
	Double_t Tpc0Y1;
	Double_t Tpc0X2;
	Double_t Tpc0Y2;
	Double_t Cal0X1;
	Double_t Cal0Y1;
	Double_t Cal0X2;
	Double_t Cal0Y2;
	Double_t Tpc1X1;
	Double_t Tpc1Y1;
	Double_t Tpc1X2;
	Double_t Tpc1Y2;
	Double_t Cal1X1;
	Double_t Cal1Y1;
	Double_t Cal1X2;
	Double_t Cal1Y2;
	Double_t TotalAdc;
	Qvector()
	{
		Tpc0X1=0.;
		Tpc0Y1=0.;
		Tpc0X2=0.;
		Tpc0Y2=0.;
		Cal0X1=0.;
		Cal0Y1=0.;
		Cal0X2=0.;
		Cal0Y2=0.;
		Tpc1X1=0.;
		Tpc1Y1=0.;
		Tpc1X2=0.;
		Tpc1Y2=0.;
		Cal1X1=0.;
		Cal1Y1=0.;
		Cal1X2=0.;
		Cal1Y2=0.;
		TotalAdc=0.;
	}
};

#endif