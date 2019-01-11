#include "TMVA/Types.h"
#include "TFile.h"
#include "TNtupleD.h"
#include "TMVA/Factory.h"
using namespace TMVA;
void example07()
{
    TFile *file = new TFile("example01.root");
    TNtupleD *nt_sig = (TNtupleD*)file->Get("nt_sig");
    TNtupleD *nt_bkg = (TNtupleD*)file->Get("nt_bkg");

    TFile *fout = new TFile("TMVA.root","recreate");

    //TMVA is the namespace
    Factory *factory = new Factory("TMVAClassification",fout,"V:!Silent:Color:Transformations=I:DrawProgressBar:AnalysisType=Classification");

    factory->AddSignalTree(nt_sig,1.);
    factory->AddBackgroundTree(nt_bkg,1.);
    factory->AddVariable("x",'F');
    factory->AddVariable("y",'F');

    factory->PrepareTrainingAndTestTree("","","random");
    factory->BookMethod(Types::kFisher,"Fisher","H:!V:Fisher:VarTransform=None:CreateMVAPdfs:PDFInterpolMVAPdf=Spline2:NbinsMVApdf=50:NsmoothMVApdf=10");
    factory->BookMethod(Types::kMLP,"MLP","H:!V:NeuronType=tanh:VarTransform=N:NCycles=600:HiddenLayers=N+5:TestRate=5:!UseRegulator");

    factory->BookMethod(Types::kBDT,"BDT","NTrees=400:MaxDepth=2");
    factory->TrainAllMethods();
    factory->TestAllMethods();
    factory->EvaluateAllMethods();

    fout->Write();
    fout->Close();
}

