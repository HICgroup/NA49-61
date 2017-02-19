#ifndef NA49calculator_h
#define NA49calculator_h

#include "variables.h"

class NA49calculator {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain
   TFile          *foutFile;
   TTree          *foutTree;
   TFile          *foutHistFile;

   // Declaration of leaf types
   Float_t         fVertex_fPchi2;
   Float_t         fVeto_fAdcHadron[4];
   Int_t           fNRun;
   Int_t           fNEvent;
   Int_t           fTriggerMask;
   Int_t           fDate;
   Int_t           fTime;
   Float_t         fEveto;
   Float_t         fVertexX;
   Float_t         fVertexY;
   Float_t         fVertexZ;
   Int_t           fWfaNbeam;
   Int_t           fWfaNinter;
   Int_t           fWfaBeamTime;
   Int_t           fWfaInterTime;
   Int_t           fNPrimaryParticles;
   Char_t          fPrimaryParticles_fIdDet[_MAX_TRACKS];   //[fNPrimaryParticles]
   Char_t          fPrimaryParticles_fCharge[_MAX_TRACKS];   //[fNPrimaryParticles]
   UChar_t         fPrimaryParticles_fNPoint[_MAX_TRACKS][_N_DIM];   //[fNPrimaryParticles]
   UChar_t         fPrimaryParticles_fNFitPoint[_MAX_TRACKS][_N_DIM];   //[fNPrimaryParticles]
   UChar_t         fPrimaryParticles_fNDedxPoint[_MAX_TRACKS][_N_DIM];   //[fNPrimaryParticles]
   UChar_t         fPrimaryParticles_fNMaxPoint[_MAX_TRACKS][_N_DIM];   //[fNPrimaryParticles]
   UShort_t        fPrimaryParticles_fTmeanCharge[_MAX_TRACKS][_N_DIM];   //[fNPrimaryParticles]
   Float_t         fPrimaryParticles_fPz[_MAX_TRACKS];   //[fNPrimaryParticles]
   Float_t         fPrimaryParticles_fEta[_MAX_TRACKS];   //[fNPrimaryParticles]
   Float_t         fPrimaryParticles_fPhi[_MAX_TRACKS];   //[fNPrimaryParticles]
   Float_t         fPrimaryParticles_fPt[_MAX_TRACKS];   //[fNPrimaryParticles]
   Float_t         fPrimaryParticles_fSigPx[_MAX_TRACKS];   //[fNPrimaryParticles]
   Float_t         fPrimaryParticles_fSigPy[_MAX_TRACKS];   //[fNPrimaryParticles]
   Float_t         fPrimaryParticles_fBx[_MAX_TRACKS];   //[fNPrimaryParticles]
   Float_t         fPrimaryParticles_fBy[_MAX_TRACKS];   //[fNPrimaryParticles]
   Float_t         fPrimaryParticles_fPchi2[_MAX_TRACKS];   //[fNPrimaryParticles]
   Float_t         fPrimaryParticles_fXFirst[_MAX_TRACKS][_N_DIM];   //[fNPrimaryParticles]
   Float_t         fPrimaryParticles_fYFirst[_MAX_TRACKS][_N_DIM];   //[fNPrimaryParticles]
   Float_t         fPrimaryParticles_fZFirst[_MAX_TRACKS][_N_DIM];   //[fNPrimaryParticles]
   Float_t         fPrimaryParticles_fXLast[_MAX_TRACKS][_N_DIM];   //[fNPrimaryParticles]
   Float_t         fPrimaryParticles_fYLast[_MAX_TRACKS][_N_DIM];   //[fNPrimaryParticles]
   Float_t         fPrimaryParticles_fZLast[_MAX_TRACKS][_N_DIM];   //[fNPrimaryParticles]
   Float_t         fPrimaryParticles_fLabel [_MAX_TRACKS];   //[fNPrimaryParticles]
   Int_t           fPrimaryParticles_fTofIflag[_MAX_TRACKS];   //[fNPrimaryParticles]
   Int_t           fPrimaryParticles_fTofId[_MAX_TRACKS];   //[fNPrimaryParticles]
   Float_t         fPrimaryParticles_fTofX[_MAX_TRACKS];   //[fNPrimaryParticles]
   Float_t         fPrimaryParticles_fTofY[_MAX_TRACKS];   //[fNPrimaryParticles]
   Float_t         fPrimaryParticles_fTofPathl[_MAX_TRACKS];   //[fNPrimaryParticles]
   Float_t         fPrimaryParticles_fTofCharge[_MAX_TRACKS];   //[fNPrimaryParticles]
   Float_t         fPrimaryParticles_fTofMass2[_MAX_TRACKS];   //[fNPrimaryParticles]
   Float_t         fPrimaryParticles_fTofSigMass2[_MAX_TRACKS];   //[fNPrimaryParticles]
   Float_t         fRing_fADChadron[_N_MODULES];

   // List of branches
   TBranch        *b_fVertex_fPchi2;   //!
   TBranch        *b_Veto_fAdcHadron;   //!
   TBranch        *b_fNRun;   //!
   TBranch        *b_fNEvent;   //!
   TBranch        *b_fTriggerMask;   //!
   TBranch        *b_fDate;   //!
   TBranch        *b_fTime;   //!
   TBranch        *b_fEveto;   //!
   TBranch        *b_fVertexX;   //!
   TBranch        *b_fVertexY;   //!
   TBranch        *b_fVertexZ;   //!
   TBranch        *b_fWfaNbeam;   //!
   TBranch        *b_fWfaNinter;   //!
   TBranch        *b_fWfaBeamTime;   //!
   TBranch        *b_fWfaInterTime;   //!
   TBranch        *b_fNPrimaryParticles;   //!
   TBranch        *b_fPrimaryParticles_fIdDet;   //!
   TBranch        *b_fPrimaryParticles_fCharge;   //!
   TBranch        *b_fPrimaryParticles_fNPoint;   //!
   TBranch        *b_fPrimaryParticles_fNFitPoint;   //!
   TBranch        *b_fPrimaryParticles_fNDedxPoint;   //!
   TBranch        *b_fPrimaryParticles_fNMaxPoint;   //!
   TBranch        *b_fPrimaryParticles_fTmeanCharge;   //!
   TBranch        *b_fPrimaryParticles_fPz;   //!
   TBranch        *b_fPrimaryParticles_fEta;   //!
   TBranch        *b_fPrimaryParticles_fPhi;   //!
   TBranch        *b_fPrimaryParticles_fPt;   //!
   TBranch        *b_fPrimaryParticles_fSigPx;   //!
   TBranch        *b_fPrimaryParticles_fSigPy;   //!
   TBranch        *b_fPrimaryParticles_fBx;   //!
   TBranch        *b_fPrimaryParticles_fBy;   //!
   TBranch        *b_fPrimaryParticles_fPchi2;   //!
   TBranch        *b_fPrimaryParticles_fXFirst;   //!
   TBranch        *b_fPrimaryParticles_fYFirst;   //!
   TBranch        *b_fPrimaryParticles_fZFirst;   //!
   TBranch        *b_fPrimaryParticles_fXLast;   //!
   TBranch        *b_fPrimaryParticles_fYLast;   //!
   TBranch        *b_fPrimaryParticles_fZLast;   //!
   TBranch        *b_fPrimaryParticles_fLabel ;   //!
   TBranch        *b_fPrimaryParticles_fTofIflag;   //!
   TBranch        *b_fPrimaryParticles_fTofId;   //!
   TBranch        *b_fPrimaryParticles_fTofX;   //!
   TBranch        *b_fPrimaryParticles_fTofY;   //!
   TBranch        *b_fPrimaryParticles_fTofPathl;   //!
   TBranch        *b_fPrimaryParticles_fTofCharge;   //!
   TBranch        *b_fPrimaryParticles_fTofMass2;   //!
   TBranch        *b_fPrimaryParticles_fTofSigMass2;   //!
   TBranch        *b_fRing_fADChadron;   //!

   TH2F           *h_qv_vs_Mult[2][2][2][2]; //[TPC,Calorimeter][n_harm][n_mode][n_projection];
   TH2F           *h_qv_vs_Adc[2][2][2][2];  //[TPC,Calorimeter][n_harm][n_mode][n_projection];

   NA49calculator(TTree *tree=0);
   NA49calculator(TChain *chain);
   NA49calculator(TString inFileName);
   virtual ~NA49calculator();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   //=======================================================================================//
   virtual void     GetQvTPC(Int_t harm, Int_t sign, Int_t mode, Double_t &Qx, Double_t &Qy);
   virtual void     GetQvFCal(Int_t harm, Int_t mode, Double_t &Qx, Double_t &Qy);
   virtual void     GetQvector(Qvector &Q);
   virtual void     OpenOutputFile(TString outFileName);
   virtual void     OpenHistFile(TString outHistFileName);
   virtual void     MakeOutputTree(TString tree_name, Qvector &Q);
   virtual void     SaveOutputTree();
   virtual void     FillOutputTree();
   virtual Double_t GetTotalMomenta(Int_t mode);
   virtual Double_t GetTotalEnergy(Int_t mode);
   virtual Int_t    GetNRing(Int_t module);
   virtual Int_t    GetRingSector(Int_t module);
   virtual Double_t GetRingAngle(Int_t module);
   virtual void     SaveHistFile();
   virtual void     InitHist();
   virtual void     FillHist(Qvector &Q);
   virtual Bool_t   EventCuts();
   virtual Bool_t   TrackCuts();
   //=======================================================================================//
};

#endif

#ifdef NA49calculator_cxx
NA49calculator::NA49calculator(TTree *tree) : fChain(0)
{
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("t49run3133.0tree.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("t49run3133.0tree.root");
      }
      f->GetObject("data",tree);
   }
   Init(tree);
}

NA49calculator::NA49calculator(TString inFileName) : fChain(0)
{
   TTree* tree;
   TChain * chain = new TChain("data","");
   cout << "Add tree: " << inFileName.Data() << endl;
   chain->Add(inFileName.Data());
   tree = chain;
   Init(tree);
}

NA49calculator::NA49calculator(TChain* chain) : fChain(0)
{
   TTree* tree;
   tree = chain;
   Init(tree);
}

NA49calculator::~NA49calculator()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t NA49calculator::GetEntry(Long64_t entry)
{
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t NA49calculator::LoadTree(Long64_t entry)
{
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void NA49calculator::Init(TTree *tree)
{
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("fVertex_fPchi2", &fVertex_fPchi2, &b_fVertex_fPchi2);
   fChain->SetBranchAddress("fVeto_fAdcHadron", fVeto_fAdcHadron, &b_Veto_fAdcHadron);
   fChain->SetBranchAddress("fNRun", &fNRun, &b_fNRun);
   fChain->SetBranchAddress("fNEvent", &fNEvent, &b_fNEvent);
   fChain->SetBranchAddress("fTriggerMask", &fTriggerMask, &b_fTriggerMask);
   fChain->SetBranchAddress("fDate", &fDate, &b_fDate);
   fChain->SetBranchAddress("fTime", &fTime, &b_fTime);
   fChain->SetBranchAddress("fEveto", &fEveto, &b_fEveto);
   fChain->SetBranchAddress("fVertexX", &fVertexX, &b_fVertexX);
   fChain->SetBranchAddress("fVertexY", &fVertexY, &b_fVertexY);
   fChain->SetBranchAddress("fVertexZ", &fVertexZ, &b_fVertexZ);
   fChain->SetBranchAddress("fWfaNbeam", &fWfaNbeam, &b_fWfaNbeam);
   fChain->SetBranchAddress("fWfaNinter", &fWfaNinter, &b_fWfaNinter);
   fChain->SetBranchAddress("fWfaBeamTime", &fWfaBeamTime, &b_fWfaBeamTime);
   fChain->SetBranchAddress("fWfaInterTime", &fWfaInterTime, &b_fWfaInterTime);
   fChain->SetBranchAddress("fNPrimaryParticles", &fNPrimaryParticles, &b_fNPrimaryParticles);
   fChain->SetBranchAddress("fPrimaryParticles_fIdDet", fPrimaryParticles_fIdDet, &b_fPrimaryParticles_fIdDet);
   fChain->SetBranchAddress("fPrimaryParticles_fCharge", fPrimaryParticles_fCharge, &b_fPrimaryParticles_fCharge);
   fChain->SetBranchAddress("fPrimaryParticles_fNPoint", fPrimaryParticles_fNPoint, &b_fPrimaryParticles_fNPoint);
   fChain->SetBranchAddress("fPrimaryParticles_fNFitPoint", fPrimaryParticles_fNFitPoint, &b_fPrimaryParticles_fNFitPoint);
   fChain->SetBranchAddress("fPrimaryParticles_fNDedxPoint", fPrimaryParticles_fNDedxPoint, &b_fPrimaryParticles_fNDedxPoint);
   fChain->SetBranchAddress("fPrimaryParticles_fNMaxPoint", fPrimaryParticles_fNMaxPoint, &b_fPrimaryParticles_fNMaxPoint);
   fChain->SetBranchAddress("fPrimaryParticles_fTmeanCharge", fPrimaryParticles_fTmeanCharge, &b_fPrimaryParticles_fTmeanCharge);
   fChain->SetBranchAddress("fPrimaryParticles_fPz", fPrimaryParticles_fPz, &b_fPrimaryParticles_fPz);
   fChain->SetBranchAddress("fPrimaryParticles_fEta", fPrimaryParticles_fEta, &b_fPrimaryParticles_fEta);
   fChain->SetBranchAddress("fPrimaryParticles_fPhi", fPrimaryParticles_fPhi, &b_fPrimaryParticles_fPhi);
   fChain->SetBranchAddress("fPrimaryParticles_fPt", fPrimaryParticles_fPt, &b_fPrimaryParticles_fPt);
   fChain->SetBranchAddress("fPrimaryParticles_fSigPx", fPrimaryParticles_fSigPx, &b_fPrimaryParticles_fSigPx);
   fChain->SetBranchAddress("fPrimaryParticles_fSigPy", fPrimaryParticles_fSigPy, &b_fPrimaryParticles_fSigPy);
   fChain->SetBranchAddress("fPrimaryParticles_fBx", fPrimaryParticles_fBx, &b_fPrimaryParticles_fBx);
   fChain->SetBranchAddress("fPrimaryParticles_fBy", fPrimaryParticles_fBy, &b_fPrimaryParticles_fBy);
   fChain->SetBranchAddress("fPrimaryParticles_fPchi2", fPrimaryParticles_fPchi2, &b_fPrimaryParticles_fPchi2);
   fChain->SetBranchAddress("fPrimaryParticles_fXFirst", fPrimaryParticles_fXFirst, &b_fPrimaryParticles_fXFirst);
   fChain->SetBranchAddress("fPrimaryParticles_fYFirst", fPrimaryParticles_fYFirst, &b_fPrimaryParticles_fYFirst);
   fChain->SetBranchAddress("fPrimaryParticles_fZFirst", fPrimaryParticles_fZFirst, &b_fPrimaryParticles_fZFirst);
   fChain->SetBranchAddress("fPrimaryParticles_fXLast", fPrimaryParticles_fXLast, &b_fPrimaryParticles_fXLast);
   fChain->SetBranchAddress("fPrimaryParticles_fYLast", fPrimaryParticles_fYLast, &b_fPrimaryParticles_fYLast);
   fChain->SetBranchAddress("fPrimaryParticles_fZLast", fPrimaryParticles_fZLast, &b_fPrimaryParticles_fZLast);
   fChain->SetBranchAddress("fPrimaryParticles_fLabel ", fPrimaryParticles_fLabel , &b_fPrimaryParticles_fLabel );
   fChain->SetBranchAddress("fPrimaryParticles_fTofIflag", fPrimaryParticles_fTofIflag, &b_fPrimaryParticles_fTofIflag);
   fChain->SetBranchAddress("fPrimaryParticles_fTofId", fPrimaryParticles_fTofId, &b_fPrimaryParticles_fTofId);
   fChain->SetBranchAddress("fPrimaryParticles_fTofX", fPrimaryParticles_fTofX, &b_fPrimaryParticles_fTofX);
   fChain->SetBranchAddress("fPrimaryParticles_fTofY", fPrimaryParticles_fTofY, &b_fPrimaryParticles_fTofY);
   fChain->SetBranchAddress("fPrimaryParticles_fTofPathl", fPrimaryParticles_fTofPathl, &b_fPrimaryParticles_fTofPathl);
   fChain->SetBranchAddress("fPrimaryParticles_fTofCharge", fPrimaryParticles_fTofCharge, &b_fPrimaryParticles_fTofCharge);
   fChain->SetBranchAddress("fPrimaryParticles_fTofMass2", fPrimaryParticles_fTofMass2, &b_fPrimaryParticles_fTofMass2);
   fChain->SetBranchAddress("fPrimaryParticles_fTofSigMass2", fPrimaryParticles_fTofSigMass2, &b_fPrimaryParticles_fTofSigMass2);
   fChain->SetBranchAddress("fRing_fADChadron", fRing_fADChadron, &b_fRing_fADChadron);
   Notify();
}

Bool_t NA49calculator::Notify()
{
   return kTRUE;
}

void NA49calculator::Show(Long64_t entry)
{
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t NA49calculator::Cut(Long64_t entry)
{
   return 1;
}

#include <NA49analysis.h>

#endif // #ifdef NA49calculator_cxx
