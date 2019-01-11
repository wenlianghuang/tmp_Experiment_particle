#define NEVENTS 20000
#include "TFile.h"
#include "TNtuple.h"
#include "TRandom3.h"
#include "TMVA/Types.h"
#include "TMVA/Reader.h"
using namespace TMVA;
void example09()
{
    TFile *file = new TFile("example09.root","recreate");
    float var[3];
    
    Reader *reader = new Reader("V:Color:!Slient");
    reader->AddVariable("x",&var[0]);
    reader->AddVariable("y",&var[1]);
    reader->BookMVA("MyMVA2","weights/TMVAClassification_Fisher.weights.xml");

    TNtuple *nt_data = new TNtuple("nt_data","nt_data","x:y:mva");

    TRandom3 rnd(5678);

    for(int i = 0;i<NEVENTS;i++)
    {
        var[0] = rnd.Gaus(0.,1.);
        var[1] = rnd.Gaus(0.,1.);

        var[2] = reader->EvaluateMVA("MyMVA2");
        nt_data->Fill(var);
    }

    file->Write();
    file->Close();
}

