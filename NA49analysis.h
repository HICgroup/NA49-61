#define NA49analysis_h

void NA49calculator::OpenOutputFile(TString outFileName)
{
   foutFile = new TFile(outFileName.Data(),"recreate");
   foutFile->cd();
}

void NA49calculator::SaveOutputTree()
{
	if (!(foutFile->cd())) foutFile->cd();
   	foutTree ->Write();
}

void NA49calculator::FillOutputTree()
{
   foutTree ->Fill();
}

void NA49calculator::MakeOutputTree(TString tree_name, Qvector &Q)
{
   foutTree = new TTree(tree_name.Data(),tree_name.Data());

   foutTree-> Branch("Q1xTPC0",&Q.Tpc0X1,"Q.Tpc0X1/D");
   foutTree-> Branch("Q1yTPC0",&Q.Tpc0Y1,"Q.Tpc0Y1/D");
   foutTree-> Branch("Q2xTPC0",&Q.Tpc0X2,"Q.Tpc0X2/D");
   foutTree-> Branch("Q2yTPC0",&Q.Tpc0Y2,"Q.Tpc0Y2/D");
   foutTree-> Branch("Q1xCal0",&Q.Cal0X1,"Q.Cal0X1/D");
   foutTree-> Branch("Q1yCal0",&Q.Cal0Y1,"Q.Cal0Y1/D");
   foutTree-> Branch("Q2xCal0",&Q.Cal0X2,"Q.Cal0X2/D");
   foutTree-> Branch("Q2yCal0",&Q.Cal0Y2,"Q.Cal0Y2/D");
   foutTree-> Branch("Q1xTPC1",&Q.Tpc1X1,"Q.Tpc1X1/D");
   foutTree-> Branch("Q1yTPC1",&Q.Tpc1Y1,"Q.Tpc1Y1/D");
   foutTree-> Branch("Q2xTPC1",&Q.Tpc1X2,"Q.Tpc1X2/D");
   foutTree-> Branch("Q2yTPC1",&Q.Tpc1Y2,"Q.Tpc1Y2/D");
   foutTree-> Branch("Q1xCal1",&Q.Cal1X1,"Q.Cal1X1/D");
   foutTree-> Branch("Q1yCal1",&Q.Cal1Y1,"Q.Cal1Y1/D");
   foutTree-> Branch("Q2xCal1",&Q.Cal1X2,"Q.Cal1X2/D");
   foutTree-> Branch("Q2yCal1",&Q.Cal1Y2,"Q.Cal1Y2/D");
   foutTree-> Branch("AdcRing",&Q.TotalAdc,"Q.TotalAdc/D");
}

Double_t NA49calculator::GetTotalMomenta(Int_t mode)
{
   Double_t result=0.;
   Int_t    counter=0;
   for (Int_t jtrack=0; jtrack<fNPrimaryParticles; jtrack++){
   		if (!(TrackCuts())) continue;
		result += fPrimaryParticles_fPt[jtrack];
		counter++;
   }
   if (mode==1) return result;
   if (mode==0) return (Double_t)counter;
}

Int_t NA49calculator::GetNRing(Int_t module)
{
   return (Int_t)module/24;
}

Int_t NA49calculator::GetRingSector(Int_t module)
{
   return (Int_t)module%24;
}

Double_t NA49calculator::GetRingAngle(Int_t module)
{
	Double_t phi = 7.5 + GetRingSector(module)*15.;
	return phi;
}

Double_t NA49calculator::GetTotalEnergy(Int_t mode)
{
	Double_t charge=0.;
	for (Int_t jmodules=0; jmodules<_N_MODULES; jmodules++){
		charge += fRing_fADChadron[jmodules];
	}
	if (mode==1) return charge;
	if (mode==0) return _N_MODULES;
}

void NA49calculator::GetQvTPC(Int_t harm, Int_t sign, Int_t mode, Double_t &Qx, Double_t &Qy)
{
	Double_t Qcos=0., Qsin=0. , total_sum = 0, weight = 0;
	Qx=0;
	Qy=0;

	Int_t w_sign = 0;
	if (harm == 2) w_sign = 1;
	else w_sign = sign;

	for (Int_t jtrack=0; jtrack<fNPrimaryParticles; jtrack++){
		if (!(fPrimaryParticles_fEta[jtrack]*sign > 0)) continue;
		if (!(TrackCuts())) continue;
		if (mode == 0) weight = 1;
		if (mode == 1) weight = fPrimaryParticles_fPt[jtrack];

		Qcos += w_sign*weight*Cos(harm*fPrimaryParticles_fPhi[jtrack]);
		Qsin += w_sign*weight*Sin(harm*fPrimaryParticles_fPhi[jtrack]);
	}

	total_sum=GetTotalMomenta(mode);

	Qx = (Double_t)Qcos/total_sum;
	Qy = (Double_t)Qsin/total_sum;
}

void NA49calculator::GetQvFCal(Int_t harm, Int_t mode, Double_t &Qx, Double_t &Qy)
{
	Double_t Qcos=0., Qsin=0. , total_sum = 0., weight = 0.;
	Qx=0;
	Qy=0;
	Double_t Phi;

	for (Int_t jmodules=0; jmodules<_N_MODULES; jmodules++){
		if (mode == 0) weight = 1.;
		if (mode == 1) weight = fRing_fADChadron[jmodules];
		Phi   = GetRingAngle(jmodules);
		Qcos += weight*Cos(harm*Phi);
		Qsin += weight*Sin(harm*Phi);
	}

	total_sum = GetTotalEnergy(mode);

	Qx = (Double_t)Qcos/total_sum;
	Qy = (Double_t)Qsin/total_sum;
}

void NA49calculator::GetQvector(Qvector &Q)
{
	GetQvTPC(1, 1, 0, Q.Tpc0X1, Q.Tpc0Y1);
	GetQvTPC(2, 1, 0, Q.Tpc0X2, Q.Tpc0Y2);
	GetQvTPC(1, 1, 1, Q.Tpc1X1, Q.Tpc1Y1);
	GetQvTPC(2, 1, 1, Q.Tpc1X2, Q.Tpc1Y2);
	GetQvFCal(1, 0, Q.Cal0X1, Q.Cal0Y1);
	GetQvFCal(2, 0, Q.Cal0X2, Q.Cal0Y2);
	GetQvFCal(1, 1, Q.Cal1X1, Q.Cal1Y1);
	GetQvFCal(2, 1, Q.Cal1X2, Q.Cal1Y2);
}

void NA49calculator::OpenHistFile(TString outHistFileName)
{
	foutHistFile = new TFile(outHistFileName.Data(),"recreate");
	foutHistFile->cd();
}

void NA49calculator::SaveHistFile()
{
	if (!(foutHistFile->cd())) foutHistFile->cd();
	for (Int_t i_type=0;i_type<2;i_type++){
		for (Int_t i_harm=0; i_harm<2; i_harm++){
			for (Int_t i_mode=0; i_mode<2; i_mode++){
				for (Int_t i_proj=0; i_proj<2;i_proj++){
					h_qv_vs_Mult[i_type][i_harm][i_mode][i_proj]->Write();
					h_qv_vs_Adc[i_type][i_harm][i_mode][i_proj]->Write();
				}
			}
		}
	}
}

void NA49calculator::InitHist()
{
	for (Int_t i_type=0;i_type<2;i_type++){
		for (Int_t i_harm=0; i_harm<2; i_harm++){
			for (Int_t i_mode=0; i_mode<2; i_mode++){
				for (Int_t i_proj=0; i_proj<2;i_proj++){
					h_qv_vs_Mult[i_type][i_harm][i_mode][i_proj] = new TH2F(Form("h_qv_vs_Mult%i%i%i%i",i_type,i_harm,i_mode,i_proj),Form("h_qv_vs_Mult%i%i%i%i",i_type,i_harm,i_mode,i_proj),1000,0,1000,1000,-2.,2.);
					h_qv_vs_Adc[i_type][i_harm][i_mode][i_proj] = new TH2F(Form("h_qv_vs_Adc%i%i%i%i",i_type,i_harm,i_mode,i_proj),Form("h_qv_vs_Adc%i%i%i%i",i_type,i_harm,i_mode,i_proj),100,20,150,1000,-2.,2.);
				}
			}
		}
	}
}

void NA49calculator::FillHist(Qvector &Q)
{
	h_qv_vs_Mult[0][0][0][0]->Fill(fNPrimaryParticles,Q.Tpc0X1);
	h_qv_vs_Mult[0][0][0][1]->Fill(fNPrimaryParticles,Q.Tpc0Y1);
	h_qv_vs_Mult[0][1][0][0]->Fill(fNPrimaryParticles,Q.Tpc0X2);
	h_qv_vs_Mult[0][1][0][1]->Fill(fNPrimaryParticles,Q.Tpc0Y2);
	h_qv_vs_Mult[0][0][1][0]->Fill(fNPrimaryParticles,Q.Tpc1X1);
	h_qv_vs_Mult[0][0][1][1]->Fill(fNPrimaryParticles,Q.Tpc1Y1);
	h_qv_vs_Mult[0][1][1][0]->Fill(fNPrimaryParticles,Q.Tpc1X2);
	h_qv_vs_Mult[0][1][1][1]->Fill(fNPrimaryParticles,Q.Tpc1Y2);
	h_qv_vs_Mult[1][0][0][0]->Fill(fNPrimaryParticles,Q.Cal0X1);
	h_qv_vs_Mult[1][0][0][1]->Fill(fNPrimaryParticles,Q.Cal0Y1);
	h_qv_vs_Mult[1][1][0][0]->Fill(fNPrimaryParticles,Q.Cal0X2);
	h_qv_vs_Mult[1][1][0][1]->Fill(fNPrimaryParticles,Q.Cal0Y2);
	h_qv_vs_Mult[1][0][1][0]->Fill(fNPrimaryParticles,Q.Cal1X1);
	h_qv_vs_Mult[1][0][1][1]->Fill(fNPrimaryParticles,Q.Cal1Y1);
	h_qv_vs_Mult[1][1][1][0]->Fill(fNPrimaryParticles,Q.Cal1X2);
	h_qv_vs_Mult[1][1][1][1]->Fill(fNPrimaryParticles,Q.Cal1Y2);

	h_qv_vs_Adc[0][0][0][0]->Fill(Q.TotalAdc,Q.Tpc0X1);
	h_qv_vs_Adc[0][0][0][1]->Fill(Q.TotalAdc,Q.Tpc0Y1);
	h_qv_vs_Adc[0][1][0][0]->Fill(Q.TotalAdc,Q.Tpc0X2);
	h_qv_vs_Adc[0][1][0][1]->Fill(Q.TotalAdc,Q.Tpc0Y2);
	h_qv_vs_Adc[0][0][1][0]->Fill(Q.TotalAdc,Q.Tpc1X1);
	h_qv_vs_Adc[0][0][1][1]->Fill(Q.TotalAdc,Q.Tpc1Y1);
	h_qv_vs_Adc[0][1][1][0]->Fill(Q.TotalAdc,Q.Tpc1X2);
	h_qv_vs_Adc[0][1][1][1]->Fill(Q.TotalAdc,Q.Tpc1Y2);
	h_qv_vs_Adc[1][0][0][0]->Fill(Q.TotalAdc,Q.Cal0X1);
	h_qv_vs_Adc[1][0][0][1]->Fill(Q.TotalAdc,Q.Cal0Y1);
	h_qv_vs_Adc[1][1][0][0]->Fill(Q.TotalAdc,Q.Cal0X2);
	h_qv_vs_Adc[1][1][0][1]->Fill(Q.TotalAdc,Q.Cal0Y2);
	h_qv_vs_Adc[1][0][1][0]->Fill(Q.TotalAdc,Q.Cal1X1);
	h_qv_vs_Adc[1][0][1][1]->Fill(Q.TotalAdc,Q.Cal1Y1);
	h_qv_vs_Adc[1][1][1][0]->Fill(Q.TotalAdc,Q.Cal1X2);
	h_qv_vs_Adc[1][1][1][1]->Fill(Q.TotalAdc,Q.Cal1Y2);
}

Bool_t NA49calculator::EventCuts()
{
	return kTRUE;
}

Bool_t NA49calculator::TrackCuts()
{
	return kTRUE;
}
