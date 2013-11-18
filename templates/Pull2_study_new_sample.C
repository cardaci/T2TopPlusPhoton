#include "TH1.h"
#include "TFile.h"
#include "fit_chi2_err.C"
#include "TStyle.h"
#include "TSystem.h"
#include "TRandom.h"
#include "TCanvas.h"

void Pull2_study_new_sample(){

  TFile *fGetData = new TFile("FakeData_Tight_Quark_Barrel_Fsig0.7.root");
//  TH1F *h_Data_TIGHT_Quark_Barrel = new TH1F("Data_TIGHT_Quark_Barrel","",50,0,0.05);
TH1F  *h_Data_TIGHT_Quark_Barrel = (TH1F*)fGetData->Get("FakeData_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark");

  TFile *fSignal = new TFile("FakesFromJetsResults_Signal.root");
//  TH1F *h_Signal_TIGHT_Quark_Barrel = new TH1F("Signal_TIGHT_Quark_Barrel","",50,0,0.05);
TH1F  *h_Signal_TIGHT_Quark_Barrel = (TH1F*)fSignal->Get("Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark");

  TFile *fBackground = new TFile("FakesFromJetsResults_Background.root");
//  TH1F *h_Background_TIGHT_Quark_Barrel = new TH1F("Background_TIGHT_Quark_Barrel","",50,0,0.05);
TH1F  *h_Background_TIGHT_Quark_Barrel = (TH1F*)fBackground->Get("Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark");


TCanvas *c1 = new TCanvas("c1","",640,640);
  h_Data_TIGHT_Quark_Barrel->GetXaxis()->SetRangeUser(0,0.05);
  h_Data_TIGHT_Quark_Barrel->Draw();

TCanvas *c2 = new TCanvas("c2","",640,640);
  h_Signal_TIGHT_Quark_Barrel->GetXaxis()->SetRangeUser(0,0.05);
  h_Signal_TIGHT_Quark_Barrel->Draw();

TCanvas *c3 = new TCanvas("c3","",640,640);
  h_Background_TIGHT_Quark_Barrel ->GetXaxis()->SetRangeUser(0,0.05);
  h_Background_TIGHT_Quark_Barrel ->Draw();


      double sig, sigerr,chi2;
//     fit_chi2_err(h_Data_TIGHT_Quark_Barrel,h_Signal_TIGHT_Quark_Barrel,h_Background_TIGHT_Quark_Barrel,sig,sigerr,chi2);
//      cout << "Fitted result = " << sig << " +- " << sigerr << endl;


///////////  start Pull2   //////////////////

//float Purity = sig ;// the Purity from Data have been saved
float Purity = 0.7 ;//input the fake data purity 
//cout<<"Purity:"<<Purity<<endl;

int GetNum = h_Data_TIGHT_Quark_Barrel ->GetEntries();

//cout<<"GetNum integral:"<<GetNum<<endl;

float Nsig = GetNum*Purity;
float Nbkg = GetNum*(1-Purity);
//cout<<"Nsig:"<<Nsig<<endl;
//cout<<"Nbkg:"<<Nbkg<<endl;

//TH1F *h_fillSig,*h_fillBkg,*h_pseudoexperiment;
//h_fillSig= (TH1F*)h_Signal_TIGHT_Quark_Barrel->Clone("fillSig");
//h_fillBkg= (TH1F*)h_Background_TIGHT_Quark_Barrel->Clone("fillBkg");

  TH1F *h_fillSig = new TH1F("fillSig","",2000,-1,1);
  TH1F *h_fillBkg = new TH1F("fillBkg","",2000,-1,1);
  TH1F *h_pseudoexperiment = new TH1F("pseudoexperiment","",2000,-1,1);

  TH1F *h_Pull1 = new TH1F("Pull1","",50,-5,5);
  TH1F *h_Pull2 = new TH1F("Pull2","",100,-0.2,0.2);

TCanvas *c4 = new TCanvas("c4","",640,640);

  for(int i=0;i<1000;i++){// pseudo-experiment

      //preapre the pseudo-experiment
      int temp_nsig = gRandom->Poisson(Nsig);
      int temp_nbkg = gRandom->Poisson(Nbkg);
cout<<"i:"<<i<<endl;
//cout<<"temp_nsig:"<<temp_nsig<<endl;
//cout<<"temp_nbkg:"<<temp_nbkg<<endl;


      h_fillSig->Reset();
      h_fillBkg->Reset();
      h_pseudoexperiment->Reset();

      h_fillSig ->FillRandom(h_Signal_TIGHT_Quark_Barrel, temp_nsig);
      h_fillBkg ->FillRandom(h_Background_TIGHT_Quark_Barrel, temp_nbkg);

//h_fillSig->Draw();

      h_pseudoexperiment ->Add(h_fillSig);
      h_pseudoexperiment ->Add(h_fillBkg);

//      h_pseudoexperiment->Draw();


      //fit it and get Pull1 and Pull2  
      fit_chi2_err(h_pseudoexperiment,h_Signal_TIGHT_Quark_Barrel,h_Background_TIGHT_Quark_Barrel,sig,sigerr,chi2);

      cout << "Fitted result = " << sig << " +- " << sigerr << endl;
      cout << "Purity = " << Purity << endl;

      float pull1_value = (sig-Purity)/sigerr;
      float pull2_value = (sig-Purity)/Purity;

      if(sigerr>1e-6)h_Pull1->Fill(pull1_value);
      if(Purity>1e-6)h_Pull2->Fill(pull2_value);

  }



 gStyle->SetOptStat(1);
 gStyle->SetOptFit(1);

TCanvas *c5 = new TCanvas("c5","",640,640);

//c5->cd();
// gStyle->SetOptStat(1);
// gStyle->SetOptFit(1);
//    h_Pull1->Draw();
//    h_Pull1->ResetStats();
    h_Pull1 ->Fit("gaus");
//    h_Pull1->Draw();
// gStyle->SetOptStat(1);
// gStyle->SetOptFit(1);

c5 ->Update();

TCanvas *c6 = new TCanvas("c6","",640,640);

 gStyle->SetOptStat(1);
 gStyle->SetOptFit(1);

    h_Pull2 ->Fit("gaus");

c6 ->Update();

    TFile *myFile = new TFile("Pull1_and_Pull2_new_sample.root","recreate");

    h_Pull1->SetXTitle("Pull: (fit-input)/fit_err");
    h_Pull1->Write();

    h_Pull2->SetXTitle("Bias: (fit-input)/input");
    h_Pull2->Write();




}
