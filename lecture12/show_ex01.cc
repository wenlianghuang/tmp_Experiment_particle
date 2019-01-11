//show_ex01 is the combination of training/test with x and y
#include<TFile.h>
#include<TTree.h>
#include<TCanvas.h>
#include<TH2F.h>

void show_ex01()
{
    TFile *fin = new TFile("example01.root");
    TTree *nt_sig = (TTree*)fin->Get("nt_sig");
    TTree *nt_bkg = (TTree*)fin->Get("nt_bkg");
    TCanvas *c2d = new TCanvas("c2d","c2d",900,600);
    c2d->SetMargin(0.12,0.04,0.12,0.04);
    
    TH2F *frame = new TH2F("frame"," ",10,0.0,1.5,10,0.0,1.5);
    frame->SetStats(kFALSE);
    frame->GetXaxis()->SetTitleSize(0.05);
    frame->GetXaxis()->SetTitle("x");
    frame->GetYaxis()->SetTitleSize(0.05);
    frame->GetYaxis()->SetTitle("y");
    frame->Draw();

    nt_sig->SetMarkerColor(kBlue);
    nt_sig->SetMarkerStyle(7); //In TAttMarker of medium dot
    nt_sig->Draw("y:x","","same");

    nt_bkg->SetMarkerColor(kRed);
    nt_bkg->SetMarkerStyle(7);
    nt_bkg->Draw("y:x","","same");
TCanvas *cx = new TCanvas("cx","cx",500,500);
    cx->SetMargin(0.12,0.04,0.12,0.04);
    
    TH1F *frame_x = new TH1F("frame_x","",150,0.0,1.5);
    frame_x->Draw();
    frame_x->SetStats(kFALSE);
    frame_x->SetMaximum(1100);
    frame_x->GetXaxis()->SetTitleSize(0.05);
    frame_x->GetXaxis()->SetTitle("x");
    nt_sig->SetLineColor(kBlue);
    nt_sig->SetFillColor(kBlue);
    nt_sig->SetFillStyle(3004);
    nt_sig->SetLineWidth(2);
    nt_sig->Draw("x","","same");
    nt_bkg->SetLineColor(kRed);
    nt_bkg->SetFillColor(kRed);
    nt_bkg->SetFillStyle(3005);
    nt_bkg->SetLineWidth(2);
    nt_bkg->Draw("x","","same");

    TH1F *frame_y = new TH1F("frame_y","",150,0.0,1.5);
    frame_y->Draw();
    frame_y->SetStats(kFALSE);
    frame_y->SetMaximum(1100);
    frame_y->GetXaxis()->SetTitleSize(0.05);
    frame_y->GetXaxis()->SetTitle("y");
    
    nt_sig->SetLineColor(kBlue);
    nt_sig->SetFillColor(kBlue);
    nt_sig->SetFillStyle(3004);
    nt_sig->SetLineWidth(2);
    nt_sig->Draw("y","","same");
    nt_bkg->SetLineColor(kRed);
    nt_bkg->SetFillColor(kRed);
    nt_bkg->SetFillStyle(3005);
    nt_bkg->SetLineWidth(2);
    nt_bkg->Draw("y","","same");

}
