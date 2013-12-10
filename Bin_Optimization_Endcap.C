#include "TH1.h"
#include "TFile.h"
#include "TStyle.h"
#include "TSystem.h"
#include "TRandom.h"
#include "TCanvas.h"
#include <fstream>

float MyIntegral(TH1F *histo, int bin_first, int bin_last){

  float integral;
  for(int i=bin_first; i<bin_last+1; i++){
    integral += (histo->GetBinError(i))*(histo->GetBinError(i));
  }
  return integral;
}


void Bin_Optimization_Endcap(){ 



    float PT_Min = 30;
    float PT_Max = 1200;
    int PT_N_bins = 10000;


    TFile *f1 = new TFile("FakesFromJetsResults_Background_forBin_Optimization.root");

    TH1F *h_Denominator_Quark_PT;
    h_Denominator_Quark_PT =(TH1F*) f1->Get("Denominator_Quark_PT_Endcap");
    float Num_Denominator_Quark_PT_1_over_4 = h_Denominator_Quark_PT->Integral()/4;
    cout << "h_Denominator_Quark_PT->Integral()/4: " << h_Denominator_Quark_PT->Integral()/4 << endl;
    cout << "MyIntegral(h_Denominator_Quark_PT,1,10000)/4: " << MyIntegral(h_Denominator_Quark_PT,1,10000)/4 << endl;

    float pT_subranges_Denominator_Quark_PT[6] = {0};
    pT_subranges_Denominator_Quark_PT[0] = 0.;
    pT_subranges_Denominator_Quark_PT[1] = 30.;
    pT_subranges_Denominator_Quark_PT[5] = 1200.;

    int aux_Denominator_Quark_PT[6] = {0};
    for(int i=0; i<10000; i++){
      if( h_Denominator_Quark_PT->Integral(0, i) > Num_Denominator_Quark_PT_1_over_4){
        pT_subranges_Denominator_Quark_PT[2] = PT_Min + (i+1) * (PT_Max - PT_Min)/10000;
        aux_Denominator_Quark_PT[2] = i; 
        cout << "h_Denominator_Quark_PT->Integral(0, i) : " << h_Denominator_Quark_PT->Integral(0, i) << endl;
        break;
      }
    }
    for(int i=aux_Denominator_Quark_PT[2]+1; i<10000; i++){
      if( h_Denominator_Quark_PT->Integral(aux_Denominator_Quark_PT[2]+1, i) > Num_Denominator_Quark_PT_1_over_4){
        pT_subranges_Denominator_Quark_PT[3] = PT_Min + (i+1) * (PT_Max - PT_Min)/10000;
        aux_Denominator_Quark_PT[3] = i; 
        cout << "h_Denominator_Quark_PT->Integral(aux_Denominator_Quark_PT[2]+1, i): " <<  h_Denominator_Quark_PT->Integral(aux_Denominator_Quark_PT[2]+1, i) << endl;
        break;
      }
    }
    for(int i=aux_Denominator_Quark_PT[3]+1; i<10000; i++){
      if( h_Denominator_Quark_PT->Integral(aux_Denominator_Quark_PT[3]+1, i) > Num_Denominator_Quark_PT_1_over_4){
        pT_subranges_Denominator_Quark_PT[4] = PT_Min + (i+1) * (PT_Max - PT_Min)/10000;
        aux_Denominator_Quark_PT[4] = i; 
        cout << "h_Denominator_Quark_PT->Integral(aux_Denominator_Quark_PT[3]+1, i): " <<  h_Denominator_Quark_PT->Integral(aux_Denominator_Quark_PT[3]+1, i) << endl;
        break;
      }
    }
    cout << "h_Denominator_Quark_PT->Integral(aux_Denominator_Quark_PT[4]+1, 10000): " <<  h_Denominator_Quark_PT->Integral(aux_Denominator_Quark_PT[4]+1, 10000) << endl;   

    for(int i=0; i<6; i++){
      cout << "aux_Denominator_Quark_PT[i]: " << aux_Denominator_Quark_PT[i]  << endl;
      cout << "Optimized pT_subranges_Denominator_Quark_PT[i]: " << pT_subranges_Denominator_Quark_PT[i] << endl;
    }



    TH1F *h_Numerator_Quark_PT;
    h_Numerator_Quark_PT =(TH1F*) f1->Get("Numerator_Quark_PT_Endcap");
    float Num_Numerator_Quark_PT_1_over_4 = h_Numerator_Quark_PT->Integral()/4;
    cout << "h_Numerator_Quark_PT->Integral()/4: " << h_Numerator_Quark_PT->Integral()/4 << endl;
    float pT_subranges_Numerator_Quark_PT[6] = {0};
    pT_subranges_Numerator_Quark_PT[0] = 0.;
    pT_subranges_Numerator_Quark_PT[1] = 30.;
    pT_subranges_Numerator_Quark_PT[5] = 1200.;

    int aux_Numerator_Quark_PT[6] = {0};
    for(int i=0; i<10000; i++){
      if( h_Numerator_Quark_PT->Integral(0, i) > Num_Numerator_Quark_PT_1_over_4){
        pT_subranges_Numerator_Quark_PT[2] = PT_Min + (i+1) * (PT_Max - PT_Min)/10000;
        aux_Numerator_Quark_PT[2] = i; 
        cout << "h_Numerator_Quark_PT->Integral(0, i) : " << h_Numerator_Quark_PT->Integral(0, i) << endl;
        break;
      }
    }
    for(int i=aux_Numerator_Quark_PT[2]+1; i<10000; i++){
      if( h_Numerator_Quark_PT->Integral(aux_Numerator_Quark_PT[2]+1, i) > Num_Numerator_Quark_PT_1_over_4){
        pT_subranges_Numerator_Quark_PT[3] = PT_Min + (i+1) * (PT_Max - PT_Min)/10000;
        aux_Numerator_Quark_PT[3] = i; 
        cout << "h_Numerator_Quark_PT->Integral(aux_Numerator_Quark_PT[2]+1, i): " <<  h_Numerator_Quark_PT->Integral(aux_Numerator_Quark_PT[2]+1, i) << endl;
        break;
      }
    }
    for(int i=aux_Numerator_Quark_PT[3]+1; i<10000; i++){
      if( h_Numerator_Quark_PT->Integral(aux_Numerator_Quark_PT[3]+1, i) > Num_Numerator_Quark_PT_1_over_4){
        pT_subranges_Numerator_Quark_PT[4] = PT_Min + (i+1) * (PT_Max - PT_Min)/10000;
        aux_Numerator_Quark_PT[4] = i; 
        cout << "h_Numerator_Quark_PT->Integral(aux_Numerator_Quark_PT[3]+1, i): " <<  h_Numerator_Quark_PT->Integral(aux_Numerator_Quark_PT[3]+1, i) << endl;
        break;
      }
    }
    cout << "h_Numerator_Quark_PT->Integral(aux_Numerator_Quark_PT[4]+1, 10000): " <<  h_Numerator_Quark_PT->Integral(aux_Numerator_Quark_PT[4]+1, 10000) << endl;   

    for(int i=0; i<6; i++){
      cout << "aux_Numerator_Quark_PT[i]: " << aux_Numerator_Quark_PT[i]  << endl;
      cout << "Optimized pT_subranges_Numerator_Quark_PT[i]: " << pT_subranges_Numerator_Quark_PT[i] << endl;
    }







    TH1F *h_Denominator_Gluon_PT;
    h_Denominator_Gluon_PT =(TH1F*) f1->Get("Denominator_Gluon_PT_Endcap");
    float Num_Denominator_Gluon_PT_1_over_4 = h_Denominator_Gluon_PT->Integral()/4;
    cout << "h_Denominator_Gluon_PT->Integral()/4: " << h_Denominator_Gluon_PT->Integral()/4 << endl;
    float pT_subranges_Denominator_Gluon_PT[6] = {0};
    pT_subranges_Denominator_Gluon_PT[0] = 0.;
    pT_subranges_Denominator_Gluon_PT[1] = 30.;
    pT_subranges_Denominator_Gluon_PT[5] = 1200.;

    int aux_Denominator_Gluon_PT[6] = {0};
    for(int i=0; i<10000; i++){
      if( h_Denominator_Gluon_PT->Integral(0, i) > Num_Denominator_Gluon_PT_1_over_4){
        pT_subranges_Denominator_Gluon_PT[2] = PT_Min + (i+1) * (PT_Max - PT_Min)/10000;
        aux_Denominator_Gluon_PT[2] = i; 
        cout << "h_Denominator_Gluon_PT->Integral(0, i) : " << h_Denominator_Gluon_PT->Integral(0, i) << endl;
        break;
      }
    }
    for(int i=aux_Denominator_Gluon_PT[2]+1; i<10000; i++){
      if( h_Denominator_Gluon_PT->Integral(aux_Denominator_Gluon_PT[2]+1, i) > Num_Denominator_Gluon_PT_1_over_4){
        pT_subranges_Denominator_Gluon_PT[3] = PT_Min + (i+1) * (PT_Max - PT_Min)/10000;
        aux_Denominator_Gluon_PT[3] = i; 
        cout << "h_Denominator_Gluon_PT->Integral(aux_Denominator_Gluon_PT[2]+1, i): " <<  h_Denominator_Gluon_PT->Integral(aux_Denominator_Gluon_PT[2]+1, i) << endl;
        break;
      }
    }
    for(int i=aux_Denominator_Gluon_PT[3]+1; i<10000; i++){
      if( h_Denominator_Gluon_PT->Integral(aux_Denominator_Gluon_PT[3]+1, i) > Num_Denominator_Gluon_PT_1_over_4){
        pT_subranges_Denominator_Gluon_PT[4] = PT_Min + (i+1) * (PT_Max - PT_Min)/10000;
        aux_Denominator_Gluon_PT[4] = i; 
        cout << "h_Denominator_Gluon_PT->Integral(aux_Denominator_Gluon_PT[3]+1, i): " <<  h_Denominator_Gluon_PT->Integral(aux_Denominator_Gluon_PT[3]+1, i) << endl;
        break;
      }
    }
    cout << "h_Denominator_Gluon_PT->Integral(aux_Denominator_Gluon_PT[4]+1, 10000): " <<  h_Denominator_Gluon_PT->Integral(aux_Denominator_Gluon_PT[4]+1, 10000) << endl;   

    for(int i=0; i<6; i++){
      cout << "aux_Denominator_Gluon_PT[i]: " << aux_Denominator_Gluon_PT[i]  << endl;
      cout << "Optimized pT_subranges_Denominator_Gluon_PT[i]: " << pT_subranges_Denominator_Gluon_PT[i] << endl;
    }



    TH1F *h_Numerator_Gluon_PT;
    h_Numerator_Gluon_PT =(TH1F*) f1->Get("Numerator_Gluon_PT_Endcap");
    float Num_Numerator_Gluon_PT_1_over_4 = h_Numerator_Gluon_PT->Integral()/4;
    cout << "h_Numerator_Gluon_PT->Integral()/4: " << h_Numerator_Gluon_PT->Integral()/4 << endl;
    float pT_subranges_Numerator_Gluon_PT[6] = {0};
    pT_subranges_Numerator_Gluon_PT[0] = 0.;
    pT_subranges_Numerator_Gluon_PT[1] = 30.;
    pT_subranges_Numerator_Gluon_PT[5] = 1200.;

    int aux_Numerator_Gluon_PT[6] = {0};
    for(int i=0; i<10000; i++){
      if( h_Numerator_Gluon_PT->Integral(0, i) > Num_Numerator_Gluon_PT_1_over_4){
        pT_subranges_Numerator_Gluon_PT[2] = PT_Min + (i+1) * (PT_Max - PT_Min)/10000;
        aux_Numerator_Gluon_PT[2] = i; 
        cout << "h_Numerator_Gluon_PT->Integral(0, i) : " << h_Numerator_Gluon_PT->Integral(0, i) << endl;
        break;
      }
    }
    for(int i=aux_Numerator_Gluon_PT[2]+1; i<10000; i++){
      if( h_Numerator_Gluon_PT->Integral(aux_Numerator_Gluon_PT[2]+1, i) > Num_Numerator_Gluon_PT_1_over_4){
        pT_subranges_Numerator_Gluon_PT[3] = PT_Min + (i+1) * (PT_Max - PT_Min)/10000;
        aux_Numerator_Gluon_PT[3] = i; 
        cout << "h_Numerator_Gluon_PT->Integral(aux_Numerator_Gluon_PT[2]+1, i): " <<  h_Numerator_Gluon_PT->Integral(aux_Numerator_Gluon_PT[2]+1, i) << endl;
        break;
      }
    }
    for(int i=aux_Numerator_Gluon_PT[3]+1; i<10000; i++){
      if( h_Numerator_Gluon_PT->Integral(aux_Numerator_Gluon_PT[3]+1, i) > Num_Numerator_Gluon_PT_1_over_4){
        pT_subranges_Numerator_Gluon_PT[4] = PT_Min + (i+1) * (PT_Max - PT_Min)/10000;
        aux_Numerator_Gluon_PT[4] = i; 
        cout << "h_Numerator_Gluon_PT->Integral(aux_Numerator_Gluon_PT[3]+1, i): " <<  h_Numerator_Gluon_PT->Integral(aux_Numerator_Gluon_PT[3]+1, i) << endl;
        break;
      }
    }
    cout << "h_Numerator_Gluon_PT->Integral(aux_Numerator_Gluon_PT[4]+1, 10000): " <<  h_Numerator_Gluon_PT->Integral(aux_Numerator_Gluon_PT[4]+1, 10000) << endl;   

    for(int i=0; i<6; i++){
      cout << "aux_Numerator_Gluon_PT[i]: " << aux_Numerator_Gluon_PT[i]  << endl;
      cout << "Optimized pT_subranges_Numerator_Gluon_PT[i]: " << pT_subranges_Numerator_Gluon_PT[i] << endl;
    }



    float pT_subranges_Quark_PT[6] = {0};
    pT_subranges_Quark_PT[0] = 0.;
    pT_subranges_Quark_PT[1] = 30.;
    /*
    pT_subranges_Quark_PT[2] = (pT_subranges_Numerator_Quark_PT[2] + pT_subranges_Denominator_Quark_PT[2] ) /2;
    pT_subranges_Quark_PT[3] = (pT_subranges_Numerator_Quark_PT[3] + pT_subranges_Denominator_Quark_PT[3] ) /2;
    pT_subranges_Quark_PT[4] = (pT_subranges_Numerator_Quark_PT[4] + pT_subranges_Denominator_Quark_PT[4] ) /2;
    */
    pT_subranges_Quark_PT[2] = pT_subranges_Numerator_Quark_PT[2];
    pT_subranges_Quark_PT[3] = pT_subranges_Numerator_Quark_PT[3];
    pT_subranges_Quark_PT[4] = pT_subranges_Numerator_Quark_PT[4];
    pT_subranges_Quark_PT[5] = 1200.;
    int bin_pT_subranges_Quark_PT[6] = {0};
      for(int j=0; j<6; j++){  
       for(int i=0; i<10000; i++){
	if( (PT_Min + (i+1) * (PT_Max - PT_Min)/10000) >  pT_subranges_Quark_PT[j] ){ bin_pT_subranges_Quark_PT[j] = i; break;}
      } 
    }
    for(int j=0; j<5; j++){
      cout << "bin_pT_subranges_Quark_PT[j]: " << bin_pT_subranges_Quark_PT[j] << endl;
      cout << "h_Denominator_Quark_PT->Integral(bin_pT_subranges_Quark_PT[j],bin_pT_subranges_Quark_PT[j+1]): " <<h_Denominator_Quark_PT->Integral(bin_pT_subranges_Quark_PT[j],bin_pT_subranges_Quark_PT[j+1]) << endl;
      cout << "h_Numerator_Quark_PT->Integral(bin_pT_subranges_Quark_PT[j],bin_pT_subranges_Quark_PT[j+1]): " <<h_Numerator_Quark_PT->Integral(bin_pT_subranges_Quark_PT[j],bin_pT_subranges_Quark_PT[j+1]) << endl;
    }







    float pT_subranges_Gluon_PT[6] = {0};
    pT_subranges_Gluon_PT[0] = 0.;
    pT_subranges_Gluon_PT[1] = 30.;
    /*
    pT_subranges_Gluon_PT[2] = (pT_subranges_Numerator_Gluon_PT[2] + pT_subranges_Denominator_Gluon_PT[2] ) /2;
    pT_subranges_Gluon_PT[3] = (pT_subranges_Numerator_Gluon_PT[3] + pT_subranges_Denominator_Gluon_PT[3] ) /2;
    pT_subranges_Gluon_PT[4] = (pT_subranges_Numerator_Gluon_PT[4] + pT_subranges_Denominator_Gluon_PT[4] ) /2;
    */
    pT_subranges_Gluon_PT[2] = pT_subranges_Numerator_Gluon_PT[2];
    pT_subranges_Gluon_PT[3] = pT_subranges_Numerator_Gluon_PT[3];
    pT_subranges_Gluon_PT[4] = pT_subranges_Numerator_Gluon_PT[4];
    pT_subranges_Gluon_PT[5] = 1200.;
    int bin_pT_subranges_Gluon_PT[6] = {0};
      for(int j=0; j<6; j++){  
       for(int i=0; i<10000; i++){
	if( (PT_Min + (i+1) * (PT_Max - PT_Min)/10000) >  pT_subranges_Gluon_PT[j] ){ bin_pT_subranges_Gluon_PT[j] = i; break;}
      } 
    }
    for(int j=0; j<5; j++){
      cout << "bin_pT_subranges_Gluon_PT[j]: " << bin_pT_subranges_Gluon_PT[j] << endl;
      cout << "h_Denominator_Gluon_PT->Integral(bin_pT_subranges_Gluon_PT[j],bin_pT_subranges_Gluon_PT[j+1]): " <<h_Denominator_Gluon_PT->Integral(bin_pT_subranges_Gluon_PT[j],bin_pT_subranges_Gluon_PT[j+1]) << endl;
      cout << "h_Numerator_Gluon_PT->Integral(bin_pT_subranges_Gluon_PT[j],bin_pT_subranges_Gluon_PT[j+1]): " <<h_Numerator_Gluon_PT->Integral(bin_pT_subranges_Gluon_PT[j],bin_pT_subranges_Gluon_PT[j+1]) << endl;
    }







}
