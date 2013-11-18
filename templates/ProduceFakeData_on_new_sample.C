#include <TTree.h>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include <iostream>
#include <vector>
#include <string>
#include <TFile.h>
#include <TObject.h>
#include <TSystem.h>
#include <TROOT.h>
#include "TH1.h"

void ProduceFakeData_on_new_sample(){


// open the old histo

TFile  *f1 = new TFile("FakesFromJetsResults_Signal.root");

TH1F *h_Sig_Barrel_TIGHT_Quark =(TH1F*) f1->Get("Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark");
TH1F *h_Sig_Barrel_TIGHT_Gluon =(TH1F*) f1->Get("Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Gluon");
TH1F *h_Sig_Barrel_FO_Quark =(TH1F*) f1->Get("Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Quark");
TH1F *h_Sig_Barrel_FO_Gluon =(TH1F*) f1->Get("Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Gluon");

TH1F *h_Sig_Endcap_TIGHT_Quark =(TH1F*) f1->Get("Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Quark");
TH1F *h_Sig_Endcap_TIGHT_Gluon =(TH1F*) f1->Get("Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Gluon");
TH1F *h_Sig_Endcap_FO_Quark =(TH1F*) f1->Get("Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Quark");
TH1F *h_Sig_Endcap_FO_Gluon =(TH1F*) f1->Get("Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Gluon");

TFile  *f2 = new TFile("FakesFromJetsResults_Background.root");

TH1F *h_Bkg_Barrel_TIGHT_Quark =(TH1F*) f2->Get("Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark");
TH1F *h_Bkg_Barrel_TIGHT_Gluon =(TH1F*) f2->Get("Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Gluon");
TH1F *h_Bkg_Barrel_FO_Quark =(TH1F*) f2->Get("Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Quark");
TH1F *h_Bkg_Barrel_FO_Gluon =(TH1F*) f2->Get("Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Gluon");

TH1F *h_Bkg_Endcap_TIGHT_Quark =(TH1F*) f2->Get("Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Quark");
TH1F *h_Bkg_Endcap_TIGHT_Gluon =(TH1F*) f2->Get("Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Gluon");
TH1F *h_Bkg_Endcap_FO_Quark =(TH1F*) f2->Get("Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Quark");
TH1F *h_Bkg_Endcap_FO_Gluon =(TH1F*) f2->Get("Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Gluon");



// book the fake data histo

TH1F *h_FakeData_Barrel_TIGHT_Quark = new TH1F ("FakeData_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark","",2000,-1,1);
TH1F *h_FakeData_Barrel_TIGHT_Gluon = new TH1F ("FakeData_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Gluon","",2000,-1,1);
TH1F *h_FakeData_Barrel_FO_Quark = new TH1F ("FakeData_Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Quark","",2000,-1,1);
TH1F *h_FakeData_Barrel_FO_Gluon = new TH1F ("FakeData_Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Gluon","",2000,-1,1);

TH1F *h_FakeData_Endcap_TIGHT_Quark = new TH1F ("FakeData_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Quark","",2000,-1,1);
TH1F *h_FakeData_Endcap_TIGHT_Gluon = new TH1F ("FakeData_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Gluon","",2000,-1,1);
TH1F *h_FakeData_Endcap_FO_Quark = new TH1F ("FakeData_Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Quark","",2000,-1,1);
TH1F *h_FakeData_Endcap_FO_Gluon = new TH1F ("FakeData_Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Gluon","",2000,-1,1);



//clone the sig and bkg old histo

  TH1F *h_Sig_Barrel_TIGHT_Quark_new=(TH1F*)h_Sig_Barrel_TIGHT_Quark->Clone("Sig_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark");
  TH1F *h_Sig_Barrel_TIGHT_Gluon_new=(TH1F*)h_Sig_Barrel_TIGHT_Gluon->Clone("Sig_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Gluon");
  TH1F *h_Sig_Barrel_FO_Quark_new=(TH1F*)h_Sig_Barrel_FO_Quark->Clone("Sig_Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Quark");
  TH1F *h_Sig_Barrel_FO_Gluon_new=(TH1F*)h_Sig_Barrel_FO_Gluon->Clone("Sig_Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Gluon");

  TH1F *h_Sig_Endcap_TIGHT_Quark_new=(TH1F*)h_Sig_Endcap_TIGHT_Quark->Clone("Sig_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Quark");
  TH1F *h_Sig_Endcap_TIGHT_Gluon_new=(TH1F*)h_Sig_Endcap_TIGHT_Gluon->Clone("Sig_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Gluon");
  TH1F *h_Sig_Endcap_FO_Quark_new=(TH1F*)h_Sig_Endcap_FO_Quark->Clone("Sig_Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Quark");
  TH1F *h_Sig_Endcap_FO_Gluon_new=(TH1F*)h_Sig_Endcap_FO_Gluon->Clone("Sig_Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Gluon");


  TH1F *h_Bkg_Barrel_TIGHT_Quark_new=(TH1F*)h_Bkg_Barrel_TIGHT_Quark->Clone("Bkg_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark");
  TH1F *h_Bkg_Barrel_TIGHT_Gluon_new=(TH1F*)h_Bkg_Barrel_TIGHT_Gluon->Clone("Bkg_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Gluon");
  TH1F *h_Bkg_Barrel_FO_Quark_new=(TH1F*)h_Bkg_Barrel_FO_Quark->Clone("Bkg_Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Quark");
  TH1F *h_Bkg_Barrel_FO_Gluon_new=(TH1F*)h_Bkg_Barrel_FO_Gluon->Clone("Bkg_Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Gluon");

  TH1F *h_Bkg_Endcap_TIGHT_Quark_new=(TH1F*)h_Bkg_Endcap_TIGHT_Quark->Clone("Bkg_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Quark");
  TH1F *h_Bkg_Endcap_TIGHT_Gluon_new=(TH1F*)h_Bkg_Endcap_TIGHT_Gluon->Clone("Bkg_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Gluon");
  TH1F *h_Bkg_Endcap_FO_Quark_new=(TH1F*)h_Bkg_Endcap_FO_Quark->Clone("Bkg_Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Quark");
  TH1F *h_Bkg_Endcap_FO_Gluon_new=(TH1F*)h_Bkg_Endcap_FO_Gluon->Clone("Bkg_Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Gluon");


// normalise the cloned histo to 1

h_Sig_Barrel_TIGHT_Quark->Sumw2();
h_Sig_Barrel_TIGHT_Quark->Scale((1/h_Sig_Barrel_TIGHT_Quark->Integral() ));//use the Integral because we use the combined template so the GetEntry is wrong

h_Sig_Barrel_TIGHT_Gluon->Sumw2();
h_Sig_Barrel_TIGHT_Gluon->Scale((1/h_Sig_Barrel_TIGHT_Gluon->Integral() ));

h_Sig_Barrel_FO_Quark->Sumw2();
h_Sig_Barrel_FO_Quark->Scale((1/h_Sig_Barrel_FO_Quark->Integral() ));

h_Sig_Barrel_FO_Gluon->Sumw2();
h_Sig_Barrel_FO_Gluon->Scale((1/h_Sig_Barrel_FO_Gluon->Integral() ));

h_Sig_Endcap_TIGHT_Quark->Sumw2();
h_Sig_Endcap_TIGHT_Quark->Scale((1/h_Sig_Endcap_TIGHT_Quark->Integral() ));

h_Sig_Endcap_TIGHT_Gluon->Sumw2();
h_Sig_Endcap_TIGHT_Gluon->Scale((1/h_Sig_Endcap_TIGHT_Gluon->Integral() ));

h_Sig_Endcap_FO_Quark->Sumw2();
h_Sig_Endcap_FO_Quark->Scale((1/h_Sig_Endcap_FO_Quark->Integral() ));

h_Sig_Endcap_FO_Gluon->Sumw2();
h_Sig_Endcap_FO_Gluon->Scale((1/h_Sig_Endcap_FO_Gluon->Integral() ));



h_Bkg_Barrel_TIGHT_Quark->Sumw2();
h_Bkg_Barrel_TIGHT_Quark->Scale((1/h_Bkg_Barrel_TIGHT_Quark->Integral() ));

h_Bkg_Barrel_TIGHT_Gluon->Sumw2();
h_Bkg_Barrel_TIGHT_Gluon->Scale((1/h_Bkg_Barrel_TIGHT_Gluon->Integral() ));

h_Bkg_Barrel_FO_Quark->Sumw2();
h_Bkg_Barrel_FO_Quark->Scale((1/h_Bkg_Barrel_FO_Quark->Integral() ));

h_Bkg_Barrel_FO_Gluon->Sumw2();
h_Bkg_Barrel_FO_Gluon->Scale((1/h_Bkg_Barrel_FO_Gluon->Integral() ));

h_Bkg_Endcap_TIGHT_Quark->Sumw2();
h_Bkg_Endcap_TIGHT_Quark->Scale((1/h_Bkg_Endcap_TIGHT_Quark->Integral() ));

h_Bkg_Endcap_TIGHT_Gluon->Sumw2();
h_Bkg_Endcap_TIGHT_Gluon->Scale((1/h_Bkg_Endcap_TIGHT_Gluon->Integral() ));

h_Bkg_Endcap_FO_Quark->Sumw2();
h_Bkg_Endcap_FO_Quark->Scale((1/h_Bkg_Endcap_FO_Quark->Integral() ));

h_Bkg_Endcap_FO_Gluon->Sumw2();
h_Bkg_Endcap_FO_Gluon->Scale((1/h_Bkg_Endcap_FO_Gluon->Integral() ));


// add the cloned histo to get the fakedata histo with determined fraction of signal 

double fraction_of_signal = 0.7; 
//now the 8 category of histo is uesd to the same fraction of signal ,but you also can set different fraction of signal in each histograms 


h_FakeData_Barrel_TIGHT_Quark->Sumw2();
h_FakeData_Barrel_TIGHT_Quark->Add(h_Sig_Barrel_TIGHT_Quark,fraction_of_signal);
h_FakeData_Barrel_TIGHT_Quark->Add(h_Bkg_Barrel_TIGHT_Quark,(1-fraction_of_signal));

h_FakeData_Barrel_TIGHT_Gluon->Sumw2();
h_FakeData_Barrel_TIGHT_Gluon->Add(h_Sig_Barrel_TIGHT_Gluon,fraction_of_signal);
h_FakeData_Barrel_TIGHT_Gluon->Add(h_Bkg_Barrel_TIGHT_Gluon,(1-fraction_of_signal));

h_FakeData_Barrel_FO_Quark->Sumw2();
h_FakeData_Barrel_FO_Quark->Add(h_Sig_Barrel_FO_Quark,fraction_of_signal);
h_FakeData_Barrel_FO_Quark->Add(h_Bkg_Barrel_FO_Quark,(1-fraction_of_signal));

h_FakeData_Barrel_FO_Gluon->Sumw2();
h_FakeData_Barrel_FO_Gluon->Add(h_Sig_Barrel_FO_Gluon,fraction_of_signal);
h_FakeData_Barrel_FO_Gluon->Add(h_Bkg_Barrel_FO_Gluon,(1-fraction_of_signal));


h_FakeData_Endcap_TIGHT_Quark->Sumw2();
h_FakeData_Endcap_TIGHT_Quark->Add(h_Sig_Endcap_TIGHT_Quark,fraction_of_signal);
h_FakeData_Endcap_TIGHT_Quark->Add(h_Bkg_Endcap_TIGHT_Quark,(1-fraction_of_signal));

h_FakeData_Endcap_TIGHT_Gluon->Sumw2();
h_FakeData_Endcap_TIGHT_Gluon->Add(h_Sig_Endcap_TIGHT_Gluon,fraction_of_signal);
h_FakeData_Endcap_TIGHT_Gluon->Add(h_Bkg_Endcap_TIGHT_Gluon,(1-fraction_of_signal));

h_FakeData_Endcap_FO_Quark->Sumw2();
h_FakeData_Endcap_FO_Quark->Add(h_Sig_Endcap_FO_Quark,fraction_of_signal);
h_FakeData_Endcap_FO_Quark->Add(h_Bkg_Endcap_FO_Quark,(1-fraction_of_signal));

h_FakeData_Endcap_FO_Gluon->Sumw2();
h_FakeData_Endcap_FO_Gluon->Add(h_Sig_Endcap_FO_Gluon,fraction_of_signal);
h_FakeData_Endcap_FO_Gluon->Add(h_Bkg_Endcap_FO_Gluon,(1-fraction_of_signal));


//set name of fake data histo

      h_FakeData_Barrel_TIGHT_Quark-> SetName("FakeData_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark");
      h_FakeData_Barrel_TIGHT_Gluon-> SetName("FakeData_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Gluon");
      h_FakeData_Barrel_FO_Quark-> SetName("FakeData_Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Quark");
      h_FakeData_Barrel_FO_Gluon-> SetName("FakeData_Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Gluon");

      h_FakeData_Endcap_TIGHT_Quark-> SetName("FakeData_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Quark");
      h_FakeData_Endcap_TIGHT_Gluon-> SetName("FakeData_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Gluon");
      h_FakeData_Endcap_FO_Quark-> SetName("FakeData_Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Quark");
      h_FakeData_Endcap_FO_Gluon-> SetName("FakeData_Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Gluon");

// save the histos in root file 

     TFile *fout = new TFile("FakeData_new_sample_Fsig0.7.root","recreate");

//      h_Sig_Barrel_TIGHT_Quark_new ->SetXTitle("SigmaIetaIeta"); h_Sig_Barrel_TIGHT_Quark_new->Write();
//      h_Bkg_Barrel_TIGHT_Quark_new-> SetXTitle("SigmaIetaIeta"); h_Bkg_Barrel_TIGHT_Quark_new->Write();

      h_FakeData_Barrel_TIGHT_Quark->SetXTitle("SigmaIetaIeta");  h_FakeData_Barrel_TIGHT_Quark->Write();
      h_FakeData_Barrel_TIGHT_Gluon->SetXTitle("SigmaIetaIeta");  h_FakeData_Barrel_TIGHT_Gluon->Write();
      h_FakeData_Barrel_FO_Quark->SetXTitle("SigmaIetaIeta");     h_FakeData_Barrel_FO_Quark->Write();
      h_FakeData_Barrel_FO_Gluon->SetXTitle("SigmaIetaIeta");     h_FakeData_Barrel_FO_Gluon->Write();

      h_FakeData_Endcap_TIGHT_Quark->SetXTitle("SigmaIetaIeta");  h_FakeData_Endcap_TIGHT_Quark->Write();
      h_FakeData_Endcap_TIGHT_Gluon->SetXTitle("SigmaIetaIeta");  h_FakeData_Endcap_TIGHT_Gluon->Write();
      h_FakeData_Endcap_FO_Quark->SetXTitle("SigmaIetaIeta");     h_FakeData_Endcap_FO_Quark->Write();
      h_FakeData_Endcap_FO_Gluon->SetXTitle("SigmaIetaIeta");     h_FakeData_Endcap_FO_Gluon->Write();








}
