#include<TFile.h>
#include<TTree.h>
#include<TCanvas.h>
#include<TMatrixD.h>
#include<TNtupleD.h>

#define NEVENTS 40000
#define NVAR    2
void example02()
{
    TFile *file = new TFile("example01.root");
    TNtupleD *nt_sig = (TNtupleD*)file->Get("nt_sig");
    TNtupleD *nt_bkg = (TNtupleD*)file->Get("nt_bkg");

    
    TMatrixD vec(NVAR,1);
    TMatrixD mu_sig(NVAR,1);
    TMatrixD mu_bkg(NVAR,1);

    mu_sig = mu_bkg = 0.;

    for (int evt = 0;evt<NEVENTS/2;evt++)
    {
        nt_sig->GetEntry(evt);

        for(int i = 0;i<NVAR;i++)
            vec(i,0) = nt_sig->GetArgs()[i];
        mu_sig += vec;
    }

    mu_sig *= 1./(double)(NEVENTS/2);

    for (int evt = 0;evt<NEVENTS/2;evt++)
    {
        nt_bkg->GetEntry(evt);

        for(int i = 0 ;i<NVAR;i++)
            vec(i,0) = nt_bkg->GetArgs()[i];
        mu_bkg += vec;

    }

    mu_bkg *=1./(double)(NEVENTS/2);

    TMatrixD S_sig(NVAR,NVAR);
    TMatrixD S_bkg(NVAR,NVAR);
    S_sig = S_bkg = 0.;

    for (int evt = 0;evt<NEVENTS/2;evt++)
    {
        nt_sig->GetEntry(evt);

        for(int i = 0;i<NVAR;i++)
            vec(i,0) = nt_sig->GetArgs()[i];
        S_sig += (vec-mu_sig)*(vec-mu_sig).T();
    }

    S_sig = 1./(double)NEVENTS/2;

    for(int evt = 0;evt<NEVENTS/2;evt++)
    {
        nt_bkg->GetEntry(evt);

        for(int i = 0;i<NVAR;i++)
            vec(i,0) = nt_bkg->GetArgs()[i];
        S_bkg += (vec-mu_bkg)*(vec-mu_bkg).T();
    }

    S_bkg *= 1./(double)(NEVENTS/2);

    TMatrixD weight = (S_sig+S_bkg).Invert() * (mu_sig-mu_bkg);
    weight.Print();
}


