void run(TString inFileName)
{
	gSystem->Load("NA49calculator_C.so");

	NA49calculator* t = new NA49calculator(inFileName.Data());
	t->Loop();
}

void run(Int_t i)
{
	gSystem->Load("NA49calculator_C.so");
	TChain* chain = new TChain("data");
	chain->Add("../t49run*root");

	NA49calculator* t = new NA49calculator(chain);
	t->Loop();
}