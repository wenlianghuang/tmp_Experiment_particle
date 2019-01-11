#define NEVENTS 40000
#include<TCanvas.h>
#include<TH1F.h>
#include<TTree.h>
#include<TFile.h>
#include<TTree.h>
#include<TLegend.h>
void show_ex02()
{
    TFile *fin = new TFile("example01.root");
    TTree *nt_sig = (TTree*)fin->Get("nt_sig");
    TTree *nt_bkg = (TTree*)fin->Get("nt_bkg");
    
    TCanvas *c1 = new TCanvas("c1","c1",600,400);
    c1->SetMargin(0.12,0.04,0.12,0.04);
    
    TH1F *h_sig_train = new TH1F("h_sig_train","",70,-17.,-3.);
    TH1F *h_bkg_train = new TH1F("h_bkg_train","",70,-17.,-3.);
    TH1F *h_sig_test = new TH1F("h_sig_test","",70,-17.,-3.);
    TH1F *h_bkg_test = new TH1F("h_bkg_test","",70,-17.,-3.);

    nt_sig->Project("h_sig_train","x*(-8.603)+y*(-4.977)","","",NEVENTS/2,0);
    nt_sig->Project("h_sig_test","x*(-8.603)+y*(-4.977)","","",NEVENTS/2,NEVENTS/2);
    nt_bkg->Project("h_bkg_train","x*(-8.603)+y*(-4.977)","","",NEVENTS/2,0);
    nt_bkg->Project("h_bkg_test","x*(-8.603)+y*(-4.977)","","",NEVENTS/2,NEVENTS/2);
   
    //Use the h_bkg_train to be the basic graph,other graph will add them on.
    
    h_bkg_train->SetStats(kFALSE);//Hide the statistics box 
    h_bkg_train->GetXaxis()->SetTitleSize(0.055);
    h_bkg_train->GetXaxis()->SetTitle("Fisher Disc.");
    h_bkg_train->SetLineColor(kRed);
    h_bkg_train->SetFillColor(kRed);
    h_bkg_train->SetFillStyle(3005);
    h_bkg_train->SetLineWidth(1);
    h_bkg_train->SetMaximum(h_bkg_train->GetMaximum()*1.3);
    h_bkg_train->Draw();
    
    h_bkg_test->SetLineColor(kRed+1);
    h_bkg_test->SetLineWidth(3);
    h_bkg_test->SetLineStyle(7);
    h_bkg_test->Draw("same");
    
    h_sig_train->SetLineColor(kBlue);
    h_sig_train->SetFillColor(kBlue);
    h_sig_train->SetFillStyle(3004);
    h_sig_train->SetLineWidth(2);
    h_sig_train->Draw("same");

    h_sig_test->SetLineColor(kBlue+1);
    h_sig_test->SetLineWidth(3);
    h_sig_test->SetLineStyle(7);
    h_sig_test->Draw("same");
    
    TLegend *leg = new TLegend(0.6,0.7,0.9,0.95);//left,down,right,upper
    leg->AddEntry(h_sig_train,"Signal (training)","F");//The first of AddEntry is the variable 
    leg->AddEntry(h_bkg_train,"Background (training)","F"); //"F" draw a box
    leg->AddEntry(h_sig_test,"Signal (testing)","l");//"l" draw line associated with TAttLine 
    leg->AddEntry(h_bkg_test,"Background (testing)","l");
    leg->Draw();
}
