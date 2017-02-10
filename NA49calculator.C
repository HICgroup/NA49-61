#define NA49calculator_cxx
#include "NA49calculator.h"

void NA49calculator::Loop()
{
	if (fChain == 0) return;
	Long64_t nentries = fChain->GetEntriesFast();
	Long64_t nbytes = 0, nb = 0;

	Qvector Qv;

	MakeOutputTree("q_vect",Qv);
	OpenOutputFile("q_vectors.root");

	InitHist();

	for (Long64_t jentry=0; jentry<nentries;jentry++){
		Long64_t ientry = LoadTree(jentry);
		if (ientry < 0) break;
		nb = fChain->GetEntry(jentry);   nbytes += nb;
		// if (Cut(ientry) < 0) continue;
		if (jentry%1000==0) cout << "Tree Event: " << jentry << endl;
		if (!(EventCuts())) continue;
		GetQvector(Qv);
		Qv.TotalAdc = GetTotalEnergy(1)/_N_MODULES;
		FillOutputTree();
		FillHist(Qv);
	}
	SaveOutputTree();
	OpenHistFile("correlation_hist.root");
	SaveHistFile();
}
