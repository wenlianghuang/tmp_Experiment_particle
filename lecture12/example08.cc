#include "weights/TMVAClassification_Fisher.class.C"
#define NEVENTS 20000
#include "TFile.h"
#include "TRandom3.h"
#include "TNtuple.h"

void example08()
{
    TFile *file = new TFile("example08.root","recreate");
    std::vector<std::string>inputVars;
    
    inputVars.push_back("x");
    inputVars.push_back("y");

    ReadFisher MyMVA(inputVars);


    float var[3];

    TNtuple *nt_data = new TNtuple("nt_data","nt_data","x:y:mva");

    TRandom3 rnd(5678);
    std::vector<double> inputValue;

    for(int i =0;i<NEVENTS;i++)
    {
        var[0] = rnd.Gaus(0.,1.);
        var[1] = rnd.Gaus(0.,1.);

        inputValue.push_back(var[0]);
        inputValue.push_back(var[1]);

        var[2] = MyMVA.GetMvaValue(inputValue);
        nt_data->Fill(var);
    }

    file->Write();
    file->Close();
}



