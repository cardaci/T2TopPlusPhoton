#include "TH1.h"
#include "TFile.h"
#include "TStyle.h"
#include "TSystem.h"
#include "TRandom.h"
#include "TCanvas.h"
#include <fstream>


void Add_EtaBins_Barrel_and_Endcap(){ 


       //booking new histograms


    TH1F  *Sigma_Ieta_Ieta_TIGHT_Gluon_Barrel_Pt_Bin_[5];
    TH1F  *Sigma_Ieta_Ieta_TIGHT_Quark_Barrel_Pt_Bin_[5];
    TH1F  *Sigma_Ieta_Ieta_FO_Gluon_Barrel_Pt_Bin_[5];
    TH1F  *Sigma_Ieta_Ieta_FO_Quark_Barrel_Pt_Bin_[5];

    TH1F  *Sigma_Ieta_Ieta_TIGHT_Gluon_Endcap_Pt_Bin_[5];
    TH1F  *Sigma_Ieta_Ieta_TIGHT_Quark_Endcap_Pt_Bin_[5];
    TH1F  *Sigma_Ieta_Ieta_FO_Gluon_Endcap_Pt_Bin_[5];
    TH1F  *Sigma_Ieta_Ieta_FO_Quark_Endcap_Pt_Bin_[5];

    char newhname[500];

    for(int i=0;i<5;i++){

    sprintf( newhname,"Sigma_Ieta_Ieta_TIGHT_Gluon_Barrel_Pt_Bin_%d",i);
    Sigma_Ieta_Ieta_TIGHT_Gluon_Barrel_Pt_Bin_[i]  = new TH1F ( newhname ,"", 2000, -1, 1);

    sprintf( newhname,"Sigma_Ieta_Ieta_TIGHT_Quark_Barrel_Pt_Bin_%d",i);
    Sigma_Ieta_Ieta_TIGHT_Quark_Barrel_Pt_Bin_[i]  = new TH1F ( newhname ,"", 2000, -1, 1);

    sprintf( newhname,"Sigma_Ieta_Ieta_FO_Gluon_Barrel_Pt_Bin_%d",i);
    Sigma_Ieta_Ieta_FO_Gluon_Barrel_Pt_Bin_[i]  = new TH1F ( newhname ,"", 2000, -1, 1);

    sprintf( newhname,"Sigma_Ieta_Ieta_FO_Quark_Barrel_Pt_Bin_%d",i);
    Sigma_Ieta_Ieta_FO_Quark_Barrel_Pt_Bin_[i]  = new TH1F ( newhname ,"", 2000, -1, 1);


    sprintf( newhname,"Sigma_Ieta_Ieta_TIGHT_Gluon_Endcap_Pt_Bin_%d",i);
    Sigma_Ieta_Ieta_TIGHT_Gluon_Endcap_Pt_Bin_[i]  = new TH1F ( newhname ,"", 2000, -1, 1);

    sprintf( newhname,"Sigma_Ieta_Ieta_TIGHT_Quark_Endcap_Pt_Bin_%d",i);
    Sigma_Ieta_Ieta_TIGHT_Quark_Endcap_Pt_Bin_[i]  = new TH1F ( newhname ,"", 2000, -1, 1);

    sprintf( newhname,"Sigma_Ieta_Ieta_FO_Gluon_Endcap_Pt_Bin_%d",i);
    Sigma_Ieta_Ieta_FO_Gluon_Endcap_Pt_Bin_[i]  = new TH1F ( newhname ,"", 2000, -1, 1);

    sprintf( newhname,"Sigma_Ieta_Ieta_FO_Quark_Endcap_Pt_Bin_%d",i);
    Sigma_Ieta_Ieta_FO_Quark_Endcap_Pt_Bin_[i]  = new TH1F ( newhname ,"", 2000, -1, 1);

    }


       //open old histograms

    TFile *f1 = new TFile("FakesFromJetsResults_GJets.root");

       TH1F *h_Sigma_Ieta_Ieta_TIGHT_Gluon_Eta_Pt[5][5];
       TH1F *h_Sigma_Ieta_Ieta_TIGHT_Quark_Eta_Pt[5][5];
       TH1F *h_Sigma_Ieta_Ieta_FO_Gluon_Eta_Pt[5][5];
       TH1F *h_Sigma_Ieta_Ieta_FO_Quark_Eta_Pt[5][5];

       char hname[500];

       for(int i=0;i<5;i++){//i for Pt 		
           for (int f=0;f<5;f++ ){//f for Eta

           sprintf( hname,"Eta_%d_PT_%d_Sigma_Ieta_Ieta_TIGHT_Gluon",f,i);       
           h_Sigma_Ieta_Ieta_TIGHT_Gluon_Eta_Pt[f][i] =(TH1F*) f1->Get(hname); 

           sprintf( hname,"Eta_%d_PT_%d_Sigma_Ieta_Ieta_TIGHT_Quark",f,i);
           h_Sigma_Ieta_Ieta_TIGHT_Quark_Eta_Pt[f][i] =(TH1F*) f1->Get(hname);

           sprintf( hname,"Eta_%d_PT_%d_Sigma_Ieta_Ieta_FO_Gluon",f,i);
           h_Sigma_Ieta_Ieta_FO_Gluon_Eta_Pt[f][i] =(TH1F*) f1->Get(hname);

           sprintf( hname,"Eta_%d_PT_%d_Sigma_Ieta_Ieta_FO_Quark",f,i);
           h_Sigma_Ieta_Ieta_FO_Quark_Eta_Pt[f][i] =(TH1F*) f1->Get(hname);
           }
       }


//h_Sigma_Ieta_Ieta_TIGHT_Gluon_Eta_Pt[0][0]->Draw();




      //Add the Eta bins      


  for(int i;i<5;i++){//loop Pt Bin [i] 
      for (int j=0;j<5;j++){//loop j on Eta bins 

           if (j==1 || j==2 || j==3){//barrel

               Sigma_Ieta_Ieta_TIGHT_Gluon_Barrel_Pt_Bin_[i]->Add(h_Sigma_Ieta_Ieta_TIGHT_Gluon_Eta_Pt[j][i]);

               Sigma_Ieta_Ieta_TIGHT_Quark_Barrel_Pt_Bin_[i]->Add(h_Sigma_Ieta_Ieta_TIGHT_Quark_Eta_Pt[j][i]);

               Sigma_Ieta_Ieta_FO_Gluon_Barrel_Pt_Bin_[i]->Add(h_Sigma_Ieta_Ieta_FO_Gluon_Eta_Pt[j][i]);

               Sigma_Ieta_Ieta_FO_Quark_Barrel_Pt_Bin_[i]->Add(h_Sigma_Ieta_Ieta_FO_Quark_Eta_Pt[j][i]);

              }//end if barrel

           if (j==0 || j==4){//endcap 
               Sigma_Ieta_Ieta_TIGHT_Gluon_Endcap_Pt_Bin_[i]->Add(h_Sigma_Ieta_Ieta_TIGHT_Gluon_Eta_Pt[j][i]);

               Sigma_Ieta_Ieta_TIGHT_Quark_Endcap_Pt_Bin_[i]->Add(h_Sigma_Ieta_Ieta_TIGHT_Quark_Eta_Pt[j][i]);

               Sigma_Ieta_Ieta_FO_Gluon_Endcap_Pt_Bin_[i]->Add(h_Sigma_Ieta_Ieta_FO_Gluon_Eta_Pt[j][i]);

               Sigma_Ieta_Ieta_FO_Quark_Endcap_Pt_Bin_[i]->Add(h_Sigma_Ieta_Ieta_FO_Quark_Eta_Pt[j][i]);

               }//end if endcap


      }//end j loop 
  }//end i loop




//Sigma_Ieta_Ieta_TIGHT_Gluon_Pt_Bin_0->Draw();


       //change the x-axis in histo

   for(int i=0;i<5;i++){

       Sigma_Ieta_Ieta_TIGHT_Gluon_Barrel_Pt_Bin_[i]->GetXaxis()->SetRangeUser(0,0.04);
       Sigma_Ieta_Ieta_TIGHT_Quark_Barrel_Pt_Bin_[i]->GetXaxis()->SetRangeUser(0,0.04);
       Sigma_Ieta_Ieta_FO_Gluon_Barrel_Pt_Bin_[i]->GetXaxis()->SetRangeUser(0,0.04);
       Sigma_Ieta_Ieta_FO_Quark_Barrel_Pt_Bin_[i]->GetXaxis()->SetRangeUser(0,0.04);

       Sigma_Ieta_Ieta_TIGHT_Gluon_Endcap_Pt_Bin_[i]->GetXaxis()->SetRangeUser(0,0.04);
       Sigma_Ieta_Ieta_TIGHT_Quark_Endcap_Pt_Bin_[i]->GetXaxis()->SetRangeUser(0,0.04);
       Sigma_Ieta_Ieta_FO_Gluon_Endcap_Pt_Bin_[i]->GetXaxis()->SetRangeUser(0,0.04);
       Sigma_Ieta_Ieta_FO_Quark_Endcap_Pt_Bin_[i]->GetXaxis()->SetRangeUser(0,0.04);

       }

       //Save in root file

       TFile *myFile = new TFile("GJets_5_Pt_Bins_Barrel_and_Endcap.root","recreate");       

   for(int i=0;i<5;i++){
       Sigma_Ieta_Ieta_TIGHT_Gluon_Barrel_Pt_Bin_[i]->Write();
       Sigma_Ieta_Ieta_TIGHT_Quark_Barrel_Pt_Bin_[i]->Write();
       Sigma_Ieta_Ieta_FO_Gluon_Barrel_Pt_Bin_[i]->Write();
       Sigma_Ieta_Ieta_FO_Quark_Barrel_Pt_Bin_[i]->Write();

       Sigma_Ieta_Ieta_TIGHT_Gluon_Endcap_Pt_Bin_[i]->Write();
       Sigma_Ieta_Ieta_TIGHT_Quark_Endcap_Pt_Bin_[i]->Write();
       Sigma_Ieta_Ieta_FO_Gluon_Endcap_Pt_Bin_[i]->Write();
       Sigma_Ieta_Ieta_FO_Quark_Endcap_Pt_Bin_[i]->Write();
       }




}
