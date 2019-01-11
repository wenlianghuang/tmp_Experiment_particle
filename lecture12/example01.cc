#include<TRandom3.h>
#include<TCanvas.h>
#include<TFile.h>
#include<TNtupleD.h>
#include<TH2F.h>
#include<TMath.h>

#define NEVENTS 40000
void example01()
{
    TRandom3 rnd(1234);

    TFile *file = new TFile("example01.root","recreate");

    TNtupleD *nt_sig = new TNtupleD("nt_sig","Ntuple of signal","x:y");
    TNtupleD *nt_bkg = new TNtupleD("nt_bkg","Ntuple of background","x:y");

    double r,phi,var[2];
    for(int i = 0;i<NEVENTS;i++){
        r = rnd.Gaus(1.2,0.1);
        phi = rnd.Gaus(TMath::Pi()/6.0,0.30);
        var[0] = r*cos(phi);
        var[1] = r*sin(phi)+0.2;
        nt_sig->Fill(var);
    }

    for(int i = 0;i<NEVENTS;i++){
        r = rnd.Gaus(0.8,0.15);
        phi = rnd.Gaus(TMath::Pi()/6.0,0.25);
        var[0] = r*cos(phi);
        var[1] = r*sin(phi)+0.2;
        nt_bkg->Fill(var);
    }

    file->Write();
    file->Close();
}


    



