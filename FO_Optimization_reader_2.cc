#include "TROOT.h"
#include "TStyle.h"
#include "TH1F.h"
#include <string>
#include <iostream>
#include <vector>
#include <TFile.h>

void FO_Optimization_reader_2(){

  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);

  TFile * file_Input   = new TFile("/afs/cern.ch/work/c/cardaci/FO_Optimization_Results/FO_Optimization_Results_TOTAL.root");


  file_Input->cd();

    char name_Barrel_Quark_Background_counter[10][10][10][10][30];
    char name_Endcap_Quark_Background_counter[10][10][10][10][30];
    char name_Barrel_Gluon_Background_counter[10][10][10][10][30];
    char name_Endcap_Gluon_Background_counter[10][10][10][10][30];

    char name_Barrel_Quark_ISR_counter[10][10][10][10][30];
    char name_Endcap_Quark_ISR_counter[10][10][10][10][30];
    char name_Barrel_Gluon_ISR_counter[10][10][10][10][30];
    char name_Endcap_Gluon_ISR_counter[10][10][10][10][30];

    char name_Barrel_Quark_FSR_counter[10][10][10][10][30];
    char name_Endcap_Quark_FSR_counter[10][10][10][10][30];
    char name_Barrel_Gluon_FSR_counter[10][10][10][10][30];
    char name_Endcap_Gluon_FSR_counter[10][10][10][10][30];


    char name_Barrel_Quark_Signal_counter[10][10][10][10][30];
    char name_Endcap_Quark_Signal_counter[10][10][10][10][30];
    char name_Barrel_Gluon_Signal_counter[10][10][10][10][30];
    char name_Endcap_Gluon_Signal_counter[10][10][10][10][30];



    TH1F * h_Barrel_Quark_Background_counter[10][10][10][10];
    TH1F * h_Endcap_Quark_Background_counter[10][10][10][10];
    TH1F * h_Barrel_Gluon_Background_counter[10][10][10][10];
    TH1F * h_Endcap_Gluon_Background_counter[10][10][10][10];

    TH1F * h_Barrel_Quark_ISR_counter[10][10][10][10];
    TH1F * h_Endcap_Quark_ISR_counter[10][10][10][10];
    TH1F * h_Barrel_Gluon_ISR_counter[10][10][10][10];
    TH1F * h_Endcap_Gluon_ISR_counter[10][10][10][10];

    TH1F * h_Barrel_Quark_FSR_counter[10][10][10][10];
    TH1F * h_Endcap_Quark_FSR_counter[10][10][10][10];
    TH1F * h_Barrel_Gluon_FSR_counter[10][10][10][10];
    TH1F * h_Endcap_Gluon_FSR_counter[10][10][10][10];


    TH1F * h_Barrel_Quark_Signal_counter[10][10][10][10];
    TH1F * h_Endcap_Quark_Signal_counter[10][10][10][10];
    TH1F * h_Barrel_Gluon_Signal_counter[10][10][10][10];
    TH1F * h_Endcap_Gluon_Signal_counter[10][10][10][10];





               for(int i=5;i<10 ;i++) {
               for(int j=0;j<10 ;j++) {
               for(int k=0;k<10 ;k++) {
               for(int l=0;l<10 ;l++) {


		 cout << "Loaded histos: " << i << "_" << j << "_" << k << "_" << l << endl;


                 sprintf(name_Barrel_Quark_Background_counter[i][j][k][l],"h_Barrel_Quark_Background_counter_%d_%d_%d_%d", i, j, k, l);
                 h_Barrel_Quark_Background_counter[i][j][k][l] = (TH1F*)gDirectory->Get(name_Barrel_Quark_Background_counter[i][j][k][l]);

                 sprintf(name_Barrel_Gluon_Background_counter[i][j][k][l],"h_Barrel_Gluon_Background_counter_%d_%d_%d_%d", i, j, k, l);
                 h_Barrel_Gluon_Background_counter[i][j][k][l] = (TH1F*)gDirectory->Get(name_Barrel_Gluon_Background_counter[i][j][k][l]);


                 sprintf(name_Endcap_Quark_Background_counter[i][j][k][l],"h_Endcap_Quark_Background_counter_%d_%d_%d_%d", i, j, k, l);
                 h_Endcap_Quark_Background_counter[i][j][k][l] = (TH1F*)gDirectory->Get(name_Endcap_Quark_Background_counter[i][j][k][l]);

                 sprintf(name_Endcap_Gluon_Background_counter[i][j][k][l],"h_Endcap_Gluon_Background_counter_%d_%d_%d_%d", i, j, k, l);
                 h_Endcap_Gluon_Background_counter[i][j][k][l] = (TH1F*)gDirectory->Get(name_Endcap_Gluon_Background_counter[i][j][k][l]);



                 sprintf(name_Barrel_Quark_ISR_counter[i][j][k][l],"h_Barrel_Quark_ISR_counter_%d_%d_%d_%d", i, j, k, l);
                 h_Barrel_Quark_ISR_counter[i][j][k][l] = (TH1F*)gDirectory->Get(name_Barrel_Quark_ISR_counter[i][j][k][l]);

                 sprintf(name_Barrel_Gluon_ISR_counter[i][j][k][l],"h_Barrel_Gluon_ISR_counter_%d_%d_%d_%d", i, j, k, l);
                 h_Barrel_Gluon_ISR_counter[i][j][k][l] = (TH1F*)gDirectory->Get(name_Barrel_Gluon_ISR_counter[i][j][k][l]);


                 sprintf(name_Endcap_Quark_ISR_counter[i][j][k][l],"h_Endcap_Quark_ISR_counter_%d_%d_%d_%d", i, j, k, l);
                 h_Endcap_Quark_ISR_counter[i][j][k][l] = (TH1F*)gDirectory->Get(name_Endcap_Quark_ISR_counter[i][j][k][l]);

	       
                 sprintf(name_Endcap_Gluon_ISR_counter[i][j][k][l],"h_Endcap_Gluon_ISR_counter_%d_%d_%d_%d", i, j, k, l);
                 h_Endcap_Gluon_ISR_counter[i][j][k][l] = (TH1F*)gDirectory->Get(name_Endcap_Gluon_ISR_counter[i][j][k][l]);



                 sprintf(name_Barrel_Quark_FSR_counter[i][j][k][l],"h_Barrel_Quark_FSR_counter_%d_%d_%d_%d", i, j, k, l);
                 h_Barrel_Quark_FSR_counter[i][j][k][l] = (TH1F*)gDirectory->Get(name_Barrel_Quark_FSR_counter[i][j][k][l]);

                 sprintf(name_Barrel_Gluon_FSR_counter[i][j][k][l],"h_Barrel_Gluon_FSR_counter_%d_%d_%d_%d", i, j, k, l);
                 h_Barrel_Gluon_FSR_counter[i][j][k][l] = (TH1F*)gDirectory->Get(name_Barrel_Gluon_FSR_counter[i][j][k][l]);


                 sprintf(name_Endcap_Quark_FSR_counter[i][j][k][l],"h_Endcap_Quark_FSR_counter_%d_%d_%d_%d", i, j, k, l);
                 h_Endcap_Quark_FSR_counter[i][j][k][l] = (TH1F*)gDirectory->Get(name_Endcap_Quark_FSR_counter[i][j][k][l]);

                 sprintf(name_Endcap_Gluon_FSR_counter[i][j][k][l],"h_Endcap_Gluon_FSR_counter_%d_%d_%d_%d", i, j, k, l);
                 h_Endcap_Gluon_FSR_counter[i][j][k][l] = (TH1F*)gDirectory->Get(name_Endcap_Gluon_FSR_counter[i][j][k][l]);



                 sprintf(name_Barrel_Quark_Signal_counter[i][j][k][l],"h_Barrel_Quark_Signal_counter_%d_%d_%d_%d", i, j, k, l);
                 h_Barrel_Quark_Signal_counter[i][j][k][l] = (TH1F*)gDirectory->Get(name_Barrel_Quark_Signal_counter[i][j][k][l]);

                 sprintf(name_Barrel_Gluon_Signal_counter[i][j][k][l],"h_Barrel_Gluon_Signal_counter_%d_%d_%d_%d", i, j, k, l);
                 h_Barrel_Gluon_Signal_counter[i][j][k][l] = (TH1F*)gDirectory->Get(name_Barrel_Gluon_Signal_counter[i][j][k][l]);


                 sprintf(name_Endcap_Quark_Signal_counter[i][j][k][l],"h_Endcap_Quark_Signal_counter_%d_%d_%d_%d", i, j, k, l);
                 h_Endcap_Quark_Signal_counter[i][j][k][l] = (TH1F*)gDirectory->Get(name_Endcap_Quark_Signal_counter[i][j][k][l]);

                 sprintf(name_Endcap_Gluon_Signal_counter[i][j][k][l],"h_Endcap_Gluon_Signal_counter_%d_%d_%d_%d", i, j, k, l);
                 h_Endcap_Gluon_Signal_counter[i][j][k][l] = (TH1F*)gDirectory->Get(name_Endcap_Gluon_Signal_counter[i][j][k][l]);

         }}}} 




    float n_Barrel_Quark_Background_counter[10][10][10][10];
    float n_Endcap_Quark_Background_counter[10][10][10][10];
    float n_Barrel_Gluon_Background_counter[10][10][10][10];
    float n_Endcap_Gluon_Background_counter[10][10][10][10];

    float n_Barrel_Quark_ISR_counter[10][10][10][10];
    float n_Endcap_Quark_ISR_counter[10][10][10][10];
    float n_Barrel_Gluon_ISR_counter[10][10][10][10];
    float n_Endcap_Gluon_ISR_counter[10][10][10][10];

    float n_Barrel_Quark_FSR_counter[10][10][10][10];
    float n_Endcap_Quark_FSR_counter[10][10][10][10];
    float n_Barrel_Gluon_FSR_counter[10][10][10][10];
    float n_Endcap_Gluon_FSR_counter[10][10][10][10];


    float n_Barrel_Quark_Signal_counter[10][10][10][10];
    float n_Endcap_Quark_Signal_counter[10][10][10][10];
    float n_Barrel_Gluon_Signal_counter[10][10][10][10];
    float n_Endcap_Gluon_Signal_counter[10][10][10][10];




    float err_Barrel_Quark_Background_counter[10][10][10][10];
    float err_Endcap_Quark_Background_counter[10][10][10][10];
    float err_Barrel_Gluon_Background_counter[10][10][10][10];
    float err_Endcap_Gluon_Background_counter[10][10][10][10];

    float err_Barrel_Quark_ISR_counter[10][10][10][10];
    float err_Endcap_Quark_ISR_counter[10][10][10][10];
    float err_Barrel_Gluon_ISR_counter[10][10][10][10];
    float err_Endcap_Gluon_ISR_counter[10][10][10][10];

    float err_Barrel_Quark_FSR_counter[10][10][10][10];
    float err_Endcap_Quark_FSR_counter[10][10][10][10];
    float err_Barrel_Gluon_FSR_counter[10][10][10][10];
    float err_Endcap_Gluon_FSR_counter[10][10][10][10];


    float err_Barrel_Quark_Signal_counter[10][10][10][10];
    float err_Endcap_Quark_Signal_counter[10][10][10][10];
    float err_Barrel_Gluon_Signal_counter[10][10][10][10];
    float err_Endcap_Gluon_Signal_counter[10][10][10][10];




            for(int i=5;i<10 ;i++) {
            for(int j=0;j<10 ;j++) {
            for(int k=0;k<10 ;k++) {
            for(int l=0;l<10 ;l++) {



    n_Barrel_Quark_Background_counter[i][j][k][l] = h_Barrel_Quark_Background_counter[i][j][k][l]->GetBinContent(1);
    n_Endcap_Quark_Background_counter[i][j][k][l] = h_Endcap_Quark_Background_counter[i][j][k][l]->GetBinContent(1);
    n_Barrel_Gluon_Background_counter[i][j][k][l] = h_Barrel_Gluon_Background_counter[i][j][k][l]->GetBinContent(1);
    n_Endcap_Gluon_Background_counter[i][j][k][l] = h_Endcap_Gluon_Background_counter[i][j][k][l]->GetBinContent(1);

    n_Barrel_Quark_ISR_counter[i][j][k][l] = h_Barrel_Quark_ISR_counter[i][j][k][l]->GetBinContent(1);
    n_Endcap_Quark_ISR_counter[i][j][k][l] = h_Endcap_Quark_ISR_counter[i][j][k][l]->GetBinContent(1);
    n_Barrel_Gluon_ISR_counter[i][j][k][l] = h_Barrel_Gluon_ISR_counter[i][j][k][l]->GetBinContent(1);
    n_Endcap_Gluon_ISR_counter[i][j][k][l] = h_Endcap_Gluon_ISR_counter[i][j][k][l]->GetBinContent(1);

    n_Barrel_Quark_FSR_counter[i][j][k][l] = h_Barrel_Quark_FSR_counter[i][j][k][l]->GetBinContent(1);
    n_Endcap_Quark_FSR_counter[i][j][k][l] = h_Endcap_Quark_FSR_counter[i][j][k][l]->GetBinContent(1);
    n_Barrel_Gluon_FSR_counter[i][j][k][l] = h_Barrel_Gluon_FSR_counter[i][j][k][l]->GetBinContent(1);
    n_Endcap_Gluon_FSR_counter[i][j][k][l] = h_Endcap_Gluon_FSR_counter[i][j][k][l]->GetBinContent(1);


    n_Barrel_Quark_Signal_counter[i][j][k][l] = h_Barrel_Quark_Signal_counter[i][j][k][l]->GetBinContent(1);
    n_Endcap_Quark_Signal_counter[i][j][k][l] = h_Endcap_Quark_Signal_counter[i][j][k][l]->GetBinContent(1);
    n_Barrel_Gluon_Signal_counter[i][j][k][l] = h_Barrel_Gluon_Signal_counter[i][j][k][l]->GetBinContent(1);
    n_Endcap_Gluon_Signal_counter[i][j][k][l] = h_Endcap_Gluon_Signal_counter[i][j][k][l]->GetBinContent(1);




    err_Barrel_Quark_Background_counter[i][j][k][l] = h_Barrel_Quark_Background_counter[i][j][k][l]->GetBinError(1);
    err_Endcap_Quark_Background_counter[i][j][k][l] = h_Endcap_Quark_Background_counter[i][j][k][l]->GetBinError(1);
    err_Barrel_Gluon_Background_counter[i][j][k][l] = h_Barrel_Gluon_Background_counter[i][j][k][l]->GetBinError(1);
    err_Endcap_Gluon_Background_counter[i][j][k][l] = h_Endcap_Gluon_Background_counter[i][j][k][l]->GetBinError(1);

    err_Barrel_Quark_ISR_counter[i][j][k][l] = h_Barrel_Quark_ISR_counter[i][j][k][l]->GetBinError(1);
    err_Endcap_Quark_ISR_counter[i][j][k][l] = h_Endcap_Quark_ISR_counter[i][j][k][l]->GetBinError(1);
    err_Barrel_Gluon_ISR_counter[i][j][k][l] = h_Barrel_Gluon_ISR_counter[i][j][k][l]->GetBinError(1);
    err_Endcap_Gluon_ISR_counter[i][j][k][l] = h_Endcap_Gluon_ISR_counter[i][j][k][l]->GetBinError(1);

    err_Barrel_Quark_FSR_counter[i][j][k][l] = h_Barrel_Quark_FSR_counter[i][j][k][l]->GetBinError(1);
    err_Endcap_Quark_FSR_counter[i][j][k][l] = h_Endcap_Quark_FSR_counter[i][j][k][l]->GetBinError(1);
    err_Barrel_Gluon_FSR_counter[i][j][k][l] = h_Barrel_Gluon_FSR_counter[i][j][k][l]->GetBinError(1);
    err_Endcap_Gluon_FSR_counter[i][j][k][l] = h_Endcap_Gluon_FSR_counter[i][j][k][l]->GetBinError(1);


    err_Barrel_Quark_Signal_counter[i][j][k][l] = h_Barrel_Quark_Signal_counter[i][j][k][l]->GetBinError(1);
    err_Endcap_Quark_Signal_counter[i][j][k][l] = h_Endcap_Quark_Signal_counter[i][j][k][l]->GetBinError(1);
    err_Barrel_Gluon_Signal_counter[i][j][k][l] = h_Barrel_Gluon_Signal_counter[i][j][k][l]->GetBinError(1);
    err_Endcap_Gluon_Signal_counter[i][j][k][l] = h_Endcap_Gluon_Signal_counter[i][j][k][l]->GetBinError(1);


	    }}}}





            for(int i=5;i<10 ;i++) {
            for(int j=0;j<10 ;j++) {
            for(int k=0;k<10 ;k++) {
            for(int l=0;l<10 ;l++) {


    h_Barrel_Quark_Background_counter[i][j][k][l] = 0;
    h_Endcap_Quark_Background_counter[i][j][k][l] = 0;
    h_Barrel_Gluon_Background_counter[i][j][k][l] = 0;
    h_Endcap_Gluon_Background_counter[i][j][k][l] = 0;

    h_Barrel_Quark_ISR_counter[i][j][k][l] = 0;
    h_Endcap_Quark_ISR_counter[i][j][k][l] = 0;
    h_Barrel_Gluon_ISR_counter[i][j][k][l] = 0;
    h_Endcap_Gluon_ISR_counter[i][j][k][l] = 0;

    h_Barrel_Quark_FSR_counter[i][j][k][l] = 0;
    h_Endcap_Quark_FSR_counter[i][j][k][l] = 0;
    h_Barrel_Gluon_FSR_counter[i][j][k][l] = 0;
    h_Endcap_Gluon_FSR_counter[i][j][k][l] = 0;


    h_Barrel_Quark_Signal_counter[i][j][k][l] = 0;
    h_Endcap_Quark_Signal_counter[i][j][k][l] = 0;
    h_Barrel_Gluon_Signal_counter[i][j][k][l] = 0;
    h_Endcap_Gluon_Signal_counter[i][j][k][l] = 0;





    delete h_Barrel_Quark_Background_counter[i][j][k][l];
    delete h_Endcap_Quark_Background_counter[i][j][k][l];
    delete h_Barrel_Gluon_Background_counter[i][j][k][l];
    delete h_Endcap_Gluon_Background_counter[i][j][k][l];

    delete h_Barrel_Quark_ISR_counter[i][j][k][l];
    delete h_Endcap_Quark_ISR_counter[i][j][k][l];
    delete h_Barrel_Gluon_ISR_counter[i][j][k][l];
    delete h_Endcap_Gluon_ISR_counter[i][j][k][l];

    delete h_Barrel_Quark_FSR_counter[i][j][k][l];
    delete h_Endcap_Quark_FSR_counter[i][j][k][l];
    delete h_Barrel_Gluon_FSR_counter[i][j][k][l];
    delete h_Endcap_Gluon_FSR_counter[i][j][k][l];


    delete h_Barrel_Quark_Signal_counter[i][j][k][l];
    delete h_Endcap_Quark_Signal_counter[i][j][k][l];
    delete h_Barrel_Gluon_Signal_counter[i][j][k][l];
    delete h_Endcap_Gluon_Signal_counter[i][j][k][l];



	    }}}}



	       file_Input->Close();
	       delete file_Input;         


            for(int i=5;i<10 ;i++) {
            for(int j=0;j<10 ;j++) {
            for(int k=0;k<10 ;k++) {
            for(int l=0;l<10 ;l++) {

                             cout << "n_Barrel_Quark_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Quark_Background_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Quark_Background_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Barrel_Gluon_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Gluon_Background_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Gluon_Background_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Endcap_Quark_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Quark_Background_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Quark_Background_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Endcap_Gluon_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Gluon_Background_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Gluon_Background_counter[i][j][k][l])*sqrt(20000) << endl;

                             cout << "n_Barrel_Quark_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Quark_ISR_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Quark_ISR_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Barrel_Gluon_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Gluon_ISR_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Gluon_ISR_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Endcap_Quark_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Quark_ISR_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Quark_ISR_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Endcap_Gluon_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Gluon_ISR_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Gluon_ISR_counter[i][j][k][l])*sqrt(20000) << endl;

                             cout << "n_Barrel_Quark_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Quark_FSR_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Quark_FSR_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Barrel_Gluon_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Gluon_FSR_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Gluon_FSR_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Endcap_Quark_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Quark_FSR_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Quark_FSR_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Endcap_Gluon_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Gluon_FSR_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Gluon_FSR_counter[i][j][k][l])*sqrt(20000) << endl;

                             cout << "n_Barrel_Quark_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Quark_Signal_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Quark_Signal_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Barrel_Gluon_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Gluon_Signal_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Gluon_Signal_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Endcap_Quark_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Quark_Signal_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Quark_Signal_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Endcap_Gluon_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Gluon_Signal_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Gluon_Signal_counter[i][j][k][l])*sqrt(20000) << endl;



            cout << "*********************************************" << endl;
                
                             if ((n_Barrel_Quark_Background_counter[i][j][k][l]+n_Barrel_Quark_ISR_counter[i][j][k][l]+n_Barrel_Quark_FSR_counter[i][j][k][l]) > 0){
                             float num = n_Barrel_Quark_Signal_counter[i][j][k][l];
            float den = n_Barrel_Quark_Background_counter[i][j][k][l]+n_Barrel_Quark_ISR_counter[i][j][k][l]+n_Barrel_Quark_FSR_counter[i][j][k][l];
            float sum_square_num = err_Barrel_Quark_Signal_counter[i][j][k][l];
            float sum_square_den = err_Barrel_Quark_Background_counter[i][j][k][l]*err_Barrel_Quark_Background_counter[i][j][k][l]+err_Barrel_Quark_ISR_counter[i][j][k][l]*err_Barrel_Quark_ISR_counter[i][j][k][l]+err_Barrel_Quark_FSR_counter[i][j][k][l]*err_Barrel_Quark_FSR_counter[i][j][k][l];
                             float err = ( sum_square_num + sqrt(sum_square_den) * num / den ) / den;
            cout << "n_Barrel_Quark_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< n_Barrel_Quark_Signal_counter[i][j][k][l]/(n_Barrel_Quark_Background_counter[i][j][k][l]+n_Barrel_Quark_ISR_counter[i][j][k][l]+n_Barrel_Quark_FSR_counter[i][j][k][l]) << " +/- " << err << endl;
                             }

                             if ((n_Barrel_Gluon_Background_counter[i][j][k][l]+n_Barrel_Gluon_ISR_counter[i][j][k][l]+n_Barrel_Gluon_FSR_counter[i][j][k][l]) > 0){
                             float num = n_Barrel_Gluon_Signal_counter[i][j][k][l];
            float den = n_Barrel_Gluon_Background_counter[i][j][k][l]+n_Barrel_Gluon_ISR_counter[i][j][k][l]+n_Barrel_Gluon_FSR_counter[i][j][k][l];
            float sum_square_num = err_Barrel_Gluon_Signal_counter[i][j][k][l];
            float sum_square_den = err_Barrel_Gluon_Background_counter[i][j][k][l]*err_Barrel_Gluon_Background_counter[i][j][k][l]+err_Barrel_Gluon_ISR_counter[i][j][k][l]*err_Barrel_Gluon_ISR_counter[i][j][k][l]+err_Barrel_Gluon_FSR_counter[i][j][k][l]*err_Barrel_Gluon_FSR_counter[i][j][k][l];
                             float err = ( sum_square_num + sqrt(sum_square_den) * num / den ) / den;
            cout << "n_Barrel_Gluon_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< n_Barrel_Gluon_Signal_counter[i][j][k][l]/(n_Barrel_Gluon_Background_counter[i][j][k][l]+n_Barrel_Gluon_ISR_counter[i][j][k][l]+n_Barrel_Gluon_FSR_counter[i][j][k][l]) << " +/- " << err << endl;
                             }

                             if ((n_Endcap_Quark_Background_counter[i][j][k][l]+n_Endcap_Quark_ISR_counter[i][j][k][l]+n_Endcap_Quark_FSR_counter[i][j][k][l]) > 0){
                             float num = n_Endcap_Quark_Signal_counter[i][j][k][l];
            float den = n_Endcap_Quark_Background_counter[i][j][k][l]+n_Endcap_Quark_ISR_counter[i][j][k][l]+n_Endcap_Quark_FSR_counter[i][j][k][l];
            float sum_square_num = err_Endcap_Quark_Signal_counter[i][j][k][l];
            float sum_square_den = err_Endcap_Quark_Background_counter[i][j][k][l]*err_Endcap_Quark_Background_counter[i][j][k][l]+err_Endcap_Quark_ISR_counter[i][j][k][l]*err_Endcap_Quark_ISR_counter[i][j][k][l]+err_Endcap_Quark_FSR_counter[i][j][k][l]*err_Endcap_Quark_FSR_counter[i][j][k][l];
                             float err = ( sum_square_num + sqrt(sum_square_den) * num / den ) / den;
            cout << "n_Endcap_Quark_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< n_Endcap_Quark_Signal_counter[i][j][k][l]/(n_Endcap_Quark_Background_counter[i][j][k][l]+n_Endcap_Quark_ISR_counter[i][j][k][l]+n_Endcap_Quark_FSR_counter[i][j][k][l]) << " +/- " << err << endl;
                             }

                             if ((n_Endcap_Gluon_Background_counter[i][j][k][l]+n_Endcap_Gluon_ISR_counter[i][j][k][l]+n_Endcap_Gluon_FSR_counter[i][j][k][l]) > 0){
                             float num = n_Endcap_Gluon_Signal_counter[i][j][k][l];
            float den = n_Endcap_Gluon_Background_counter[i][j][k][l]+n_Endcap_Gluon_ISR_counter[i][j][k][l]+n_Endcap_Gluon_FSR_counter[i][j][k][l];
            float sum_square_num = err_Endcap_Gluon_Signal_counter[i][j][k][l];
            float sum_square_den = err_Endcap_Gluon_Background_counter[i][j][k][l]*err_Endcap_Gluon_Background_counter[i][j][k][l]+err_Endcap_Gluon_ISR_counter[i][j][k][l]*err_Endcap_Gluon_ISR_counter[i][j][k][l]+err_Endcap_Gluon_FSR_counter[i][j][k][l]*err_Endcap_Gluon_FSR_counter[i][j][k][l];
                             float err = ( sum_square_num + sqrt(sum_square_den) * num / den ) / den;
            cout << "n_Endcap_Gluon_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< n_Endcap_Gluon_Signal_counter[i][j][k][l]/(n_Endcap_Gluon_Background_counter[i][j][k][l]+n_Endcap_Gluon_ISR_counter[i][j][k][l]+n_Endcap_Gluon_FSR_counter[i][j][k][l]) << " +/- " << err << endl;
                             }

                
            cout << "*********************************************" << endl;
            cout << "*********************************************" << endl;
            cout << "*********************************************" << endl;

                     }}}}



            cout << "*********************************************" << endl;
            cout << "**************** BEST OF 0.01 ***************" << endl;
            cout << "*********************************************" << endl;

            for(int i=5;i<10 ;i++) {
            for(int j=0;j<10 ;j++) {
            for(int k=0;k<10 ;k++) {
            for(int l=0;l<10 ;l++) {




                             if ((n_Barrel_Quark_Background_counter[i][j][k][l]+n_Barrel_Quark_ISR_counter[i][j][k][l]+n_Barrel_Quark_FSR_counter[i][j][k][l]) > 0 &&
                             (n_Endcap_Quark_Background_counter[i][j][k][l]+n_Endcap_Quark_ISR_counter[i][j][k][l]+n_Endcap_Quark_FSR_counter[i][j][k][l]) > 0 &&
                             (n_Barrel_Quark_Signal_counter[i][j][k][l]/(n_Barrel_Quark_Background_counter[i][j][k][l]+n_Barrel_Quark_ISR_counter[i][j][k][l]+n_Barrel_Quark_FSR_counter[i][j][k][l])) < 0.01 &&
                             (n_Endcap_Quark_Signal_counter[i][j][k][l]/(n_Endcap_Quark_Background_counter[i][j][k][l]+n_Endcap_Quark_ISR_counter[i][j][k][l]+n_Endcap_Quark_FSR_counter[i][j][k][l])) < 0.01){


                             cout << "n_Barrel_Quark_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Quark_Background_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Quark_Background_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Barrel_Quark_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Quark_ISR_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Quark_ISR_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Barrel_Quark_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Quark_FSR_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Quark_FSR_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Barrel_Quark_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Quark_Signal_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Quark_Signal_counter[i][j][k][l])*sqrt(20000) << endl;

                             cout << "n_Endcap_Quark_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Quark_Background_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Quark_Background_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Endcap_Quark_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Quark_ISR_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Quark_ISR_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Endcap_Quark_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Quark_FSR_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Quark_FSR_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Endcap_Quark_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Quark_Signal_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Quark_Signal_counter[i][j][k][l])*sqrt(20000) << endl;


                             float num = n_Barrel_Quark_Signal_counter[i][j][k][l];
            float den = n_Barrel_Quark_Background_counter[i][j][k][l]+n_Barrel_Quark_ISR_counter[i][j][k][l]+n_Barrel_Quark_FSR_counter[i][j][k][l];
            float sum_square_num = err_Barrel_Quark_Signal_counter[i][j][k][l];
            float sum_square_den = err_Barrel_Quark_Background_counter[i][j][k][l]*err_Barrel_Quark_Background_counter[i][j][k][l]+err_Barrel_Quark_ISR_counter[i][j][k][l]*err_Barrel_Quark_ISR_counter[i][j][k][l]+err_Barrel_Quark_FSR_counter[i][j][k][l]*err_Barrel_Quark_FSR_counter[i][j][k][l];
                             float err = ( sum_square_num + sqrt(sum_square_den) * num / den ) / den;
            cout << "n_Barrel_Quark_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< n_Barrel_Quark_Signal_counter[i][j][k][l]/(n_Barrel_Quark_Background_counter[i][j][k][l]+n_Barrel_Quark_ISR_counter[i][j][k][l]+n_Barrel_Quark_FSR_counter[i][j][k][l]) << " +/- " << err << endl;

                             num = n_Endcap_Quark_Signal_counter[i][j][k][l];
            den = n_Endcap_Quark_Background_counter[i][j][k][l]+n_Endcap_Quark_ISR_counter[i][j][k][l]+n_Endcap_Quark_FSR_counter[i][j][k][l];
            sum_square_num = err_Endcap_Quark_Signal_counter[i][j][k][l];
            sum_square_den = err_Endcap_Quark_Background_counter[i][j][k][l]*err_Endcap_Quark_Background_counter[i][j][k][l]+err_Endcap_Quark_ISR_counter[i][j][k][l]*err_Endcap_Quark_ISR_counter[i][j][k][l]+err_Endcap_Quark_FSR_counter[i][j][k][l]*err_Endcap_Quark_FSR_counter[i][j][k][l];
                             err = ( sum_square_num + sqrt(sum_square_den) * num / den ) / den;
            cout << "n_Endcap_Quark_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< n_Endcap_Quark_Signal_counter[i][j][k][l]/(n_Endcap_Quark_Background_counter[i][j][k][l]+n_Endcap_Quark_ISR_counter[i][j][k][l]+n_Endcap_Quark_FSR_counter[i][j][k][l]) << " +/- " << err << endl;
                             }

                
                             if ((n_Barrel_Gluon_Background_counter[i][j][k][l]+n_Barrel_Gluon_ISR_counter[i][j][k][l]+n_Barrel_Gluon_FSR_counter[i][j][k][l]) > 0 &&
                             (n_Endcap_Gluon_Background_counter[i][j][k][l]+n_Endcap_Gluon_ISR_counter[i][j][k][l]+n_Endcap_Gluon_FSR_counter[i][j][k][l]) > 0 &&
                             (n_Barrel_Gluon_Signal_counter[i][j][k][l]/(n_Barrel_Gluon_Background_counter[i][j][k][l]+n_Barrel_Gluon_ISR_counter[i][j][k][l]+n_Barrel_Gluon_FSR_counter[i][j][k][l])) < 0.01 &&
                             (n_Endcap_Gluon_Signal_counter[i][j][k][l]/(n_Endcap_Gluon_Background_counter[i][j][k][l]+n_Endcap_Gluon_ISR_counter[i][j][k][l]+n_Endcap_Gluon_FSR_counter[i][j][k][l])) < 0.01){


                             cout << "n_Barrel_Gluon_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Gluon_Background_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Gluon_Background_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Barrel_Gluon_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Gluon_ISR_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Gluon_ISR_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Barrel_Gluon_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Gluon_FSR_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Gluon_FSR_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Barrel_Gluon_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Gluon_Signal_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Gluon_Signal_counter[i][j][k][l])*sqrt(20000) << endl;

                             cout << "n_Endcap_Gluon_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Gluon_Background_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Gluon_Background_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Endcap_Gluon_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Gluon_ISR_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Gluon_ISR_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Endcap_Gluon_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Gluon_FSR_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Gluon_FSR_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Endcap_Gluon_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Gluon_Signal_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Gluon_Signal_counter[i][j][k][l])*sqrt(20000) << endl;


                             float num = n_Barrel_Gluon_Signal_counter[i][j][k][l];
            float den = n_Barrel_Gluon_Background_counter[i][j][k][l]+n_Barrel_Gluon_ISR_counter[i][j][k][l]+n_Barrel_Gluon_FSR_counter[i][j][k][l];
            float sum_square_num = err_Barrel_Gluon_Signal_counter[i][j][k][l];
            float sum_square_den = err_Barrel_Gluon_Background_counter[i][j][k][l]*err_Barrel_Gluon_Background_counter[i][j][k][l]+err_Barrel_Gluon_ISR_counter[i][j][k][l]*err_Barrel_Gluon_ISR_counter[i][j][k][l]+err_Barrel_Gluon_FSR_counter[i][j][k][l]*err_Barrel_Gluon_FSR_counter[i][j][k][l];
                             float err = ( sum_square_num + sqrt(sum_square_den) * num / den ) / den;
            cout << "n_Barrel_Gluon_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< n_Barrel_Gluon_Signal_counter[i][j][k][l]/(n_Barrel_Gluon_Background_counter[i][j][k][l]+n_Barrel_Gluon_ISR_counter[i][j][k][l]+n_Barrel_Gluon_FSR_counter[i][j][k][l]) << " +/- " << err << endl;

                             num = n_Endcap_Gluon_Signal_counter[i][j][k][l];
            den = n_Endcap_Gluon_Background_counter[i][j][k][l]+n_Endcap_Gluon_ISR_counter[i][j][k][l]+n_Endcap_Gluon_FSR_counter[i][j][k][l];
            sum_square_num = err_Endcap_Gluon_Signal_counter[i][j][k][l];
            sum_square_den = err_Endcap_Gluon_Background_counter[i][j][k][l]*err_Endcap_Gluon_Background_counter[i][j][k][l]+err_Endcap_Gluon_ISR_counter[i][j][k][l]*err_Endcap_Gluon_ISR_counter[i][j][k][l]+err_Endcap_Gluon_FSR_counter[i][j][k][l]*err_Endcap_Gluon_FSR_counter[i][j][k][l];
                             err = ( sum_square_num + sqrt(sum_square_den) * num / den ) / den;
            cout << "n_Endcap_Gluon_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< n_Endcap_Gluon_Signal_counter[i][j][k][l]/(n_Endcap_Gluon_Background_counter[i][j][k][l]+n_Endcap_Gluon_ISR_counter[i][j][k][l]+n_Endcap_Gluon_FSR_counter[i][j][k][l]) << " +/- " << err << endl;


                             }

                
            cout << "*********************************************" << endl;
            cout << "*********************************************" << endl;
            cout << "*********************************************" << endl;


                     }}}}




            cout << "*********************************************" << endl;
            cout << "**************** BEST OF 0.005 **************" << endl;
            cout << "*********************************************" << endl;

            for(int i=5;i<10 ;i++) {
            for(int j=0;j<10 ;j++) {
            for(int k=0;k<10 ;k++) {
            for(int l=0;l<10 ;l++) {




                             if ((n_Barrel_Quark_Background_counter[i][j][k][l]+n_Barrel_Quark_ISR_counter[i][j][k][l]+n_Barrel_Quark_FSR_counter[i][j][k][l]) > 0 &&
                             (n_Endcap_Quark_Background_counter[i][j][k][l]+n_Endcap_Quark_ISR_counter[i][j][k][l]+n_Endcap_Quark_FSR_counter[i][j][k][l]) > 0 &&
                             (n_Barrel_Quark_Signal_counter[i][j][k][l]/(n_Barrel_Quark_Background_counter[i][j][k][l]+n_Barrel_Quark_ISR_counter[i][j][k][l]+n_Barrel_Quark_FSR_counter[i][j][k][l])) < 0.005 &&
                             (n_Endcap_Quark_Signal_counter[i][j][k][l]/(n_Endcap_Quark_Background_counter[i][j][k][l]+n_Endcap_Quark_ISR_counter[i][j][k][l]+n_Endcap_Quark_FSR_counter[i][j][k][l])) < 0.005){


                             cout << "n_Barrel_Quark_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Quark_Background_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Quark_Background_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Barrel_Quark_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Quark_ISR_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Quark_ISR_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Barrel_Quark_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Quark_FSR_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Quark_FSR_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Barrel_Quark_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Quark_Signal_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Quark_Signal_counter[i][j][k][l])*sqrt(20000) << endl;

                             cout << "n_Endcap_Quark_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Quark_Background_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Quark_Background_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Endcap_Quark_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Quark_ISR_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Quark_ISR_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Endcap_Quark_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Quark_FSR_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Quark_FSR_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Endcap_Quark_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Quark_Signal_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Quark_Signal_counter[i][j][k][l])*sqrt(20000) << endl;


                             float num = n_Barrel_Quark_Signal_counter[i][j][k][l];
            float den = n_Barrel_Quark_Background_counter[i][j][k][l]+n_Barrel_Quark_ISR_counter[i][j][k][l]+n_Barrel_Quark_FSR_counter[i][j][k][l];
            float sum_square_num = err_Barrel_Quark_Signal_counter[i][j][k][l];
            float sum_square_den = err_Barrel_Quark_Background_counter[i][j][k][l]*err_Barrel_Quark_Background_counter[i][j][k][l]+err_Barrel_Quark_ISR_counter[i][j][k][l]*err_Barrel_Quark_ISR_counter[i][j][k][l]+err_Barrel_Quark_FSR_counter[i][j][k][l]*err_Barrel_Quark_FSR_counter[i][j][k][l];
                             float err = ( sum_square_num + sqrt(sum_square_den) * num / den ) / den;
            cout << "n_Barrel_Quark_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< n_Barrel_Quark_Signal_counter[i][j][k][l]/(n_Barrel_Quark_Background_counter[i][j][k][l]+n_Barrel_Quark_ISR_counter[i][j][k][l]+n_Barrel_Quark_FSR_counter[i][j][k][l]) << " +/- " << err << endl;

                             num = n_Endcap_Quark_Signal_counter[i][j][k][l];
            den = n_Endcap_Quark_Background_counter[i][j][k][l]+n_Endcap_Quark_ISR_counter[i][j][k][l]+n_Endcap_Quark_FSR_counter[i][j][k][l];
            sum_square_num = err_Endcap_Quark_Signal_counter[i][j][k][l];
            sum_square_den = err_Endcap_Quark_Background_counter[i][j][k][l]*err_Endcap_Quark_Background_counter[i][j][k][l]+err_Endcap_Quark_ISR_counter[i][j][k][l]*err_Endcap_Quark_ISR_counter[i][j][k][l]+err_Endcap_Quark_FSR_counter[i][j][k][l]*err_Endcap_Quark_FSR_counter[i][j][k][l];
                             err = ( sum_square_num + sqrt(sum_square_den) * num / den ) / den;
            cout << "n_Endcap_Quark_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< n_Endcap_Quark_Signal_counter[i][j][k][l]/(n_Endcap_Quark_Background_counter[i][j][k][l]+n_Endcap_Quark_ISR_counter[i][j][k][l]+n_Endcap_Quark_FSR_counter[i][j][k][l]) << " +/- " << err << endl;
                             }

                
                             if ((n_Barrel_Gluon_Background_counter[i][j][k][l]+n_Barrel_Gluon_ISR_counter[i][j][k][l]+n_Barrel_Gluon_FSR_counter[i][j][k][l]) > 0 &&
                             (n_Endcap_Gluon_Background_counter[i][j][k][l]+n_Endcap_Gluon_ISR_counter[i][j][k][l]+n_Endcap_Gluon_FSR_counter[i][j][k][l]) > 0 &&
                             (n_Barrel_Gluon_Signal_counter[i][j][k][l]/(n_Barrel_Gluon_Background_counter[i][j][k][l]+n_Barrel_Gluon_ISR_counter[i][j][k][l]+n_Barrel_Gluon_FSR_counter[i][j][k][l])) < 0.005 &&
                             (n_Endcap_Gluon_Signal_counter[i][j][k][l]/(n_Endcap_Gluon_Background_counter[i][j][k][l]+n_Endcap_Gluon_ISR_counter[i][j][k][l]+n_Endcap_Gluon_FSR_counter[i][j][k][l])) < 0.005){


                             cout << "n_Barrel_Gluon_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Gluon_Background_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Gluon_Background_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Barrel_Gluon_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Gluon_ISR_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Gluon_ISR_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Barrel_Gluon_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Gluon_FSR_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Gluon_FSR_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Barrel_Gluon_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Gluon_Signal_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Gluon_Signal_counter[i][j][k][l])*sqrt(20000) << endl;

                             cout << "n_Endcap_Gluon_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Gluon_Background_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Gluon_Background_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Endcap_Gluon_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Gluon_ISR_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Gluon_ISR_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Endcap_Gluon_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Gluon_FSR_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Gluon_FSR_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Endcap_Gluon_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Gluon_Signal_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Gluon_Signal_counter[i][j][k][l])*sqrt(20000) << endl;


                             float num = n_Barrel_Gluon_Signal_counter[i][j][k][l];
            float den = n_Barrel_Gluon_Background_counter[i][j][k][l]+n_Barrel_Gluon_ISR_counter[i][j][k][l]+n_Barrel_Gluon_FSR_counter[i][j][k][l];
            float sum_square_num = err_Barrel_Gluon_Signal_counter[i][j][k][l];
            float sum_square_den = err_Barrel_Gluon_Background_counter[i][j][k][l]*err_Barrel_Gluon_Background_counter[i][j][k][l]+err_Barrel_Gluon_ISR_counter[i][j][k][l]*err_Barrel_Gluon_ISR_counter[i][j][k][l]+err_Barrel_Gluon_FSR_counter[i][j][k][l]*err_Barrel_Gluon_FSR_counter[i][j][k][l];
                             float err = ( sum_square_num + sqrt(sum_square_den) * num / den ) / den;
            cout << "n_Barrel_Gluon_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< n_Barrel_Gluon_Signal_counter[i][j][k][l]/(n_Barrel_Gluon_Background_counter[i][j][k][l]+n_Barrel_Gluon_ISR_counter[i][j][k][l]+n_Barrel_Gluon_FSR_counter[i][j][k][l]) << " +/- " << err << endl;

                             num = n_Endcap_Gluon_Signal_counter[i][j][k][l];
            den = n_Endcap_Gluon_Background_counter[i][j][k][l]+n_Endcap_Gluon_ISR_counter[i][j][k][l]+n_Endcap_Gluon_FSR_counter[i][j][k][l];
            sum_square_num = err_Endcap_Gluon_Signal_counter[i][j][k][l];
            sum_square_den = err_Endcap_Gluon_Background_counter[i][j][k][l]*err_Endcap_Gluon_Background_counter[i][j][k][l]+err_Endcap_Gluon_ISR_counter[i][j][k][l]*err_Endcap_Gluon_ISR_counter[i][j][k][l]+err_Endcap_Gluon_FSR_counter[i][j][k][l]*err_Endcap_Gluon_FSR_counter[i][j][k][l];
                             err = ( sum_square_num + sqrt(sum_square_den) * num / den ) / den;
            cout << "n_Endcap_Gluon_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< n_Endcap_Gluon_Signal_counter[i][j][k][l]/(n_Endcap_Gluon_Background_counter[i][j][k][l]+n_Endcap_Gluon_ISR_counter[i][j][k][l]+n_Endcap_Gluon_FSR_counter[i][j][k][l]) << " +/- " << err << endl;


                             }

                
            cout << "*********************************************" << endl;
            cout << "*********************************************" << endl;
            cout << "*********************************************" << endl;


                     }}}}






            cout << "*********************************************" << endl;
            cout << "**************** BEST OF 0.001 **************" << endl;
            cout << "*********************************************" << endl;

            for(int i=5;i<10 ;i++) {
            for(int j=0;j<10 ;j++) {
            for(int k=0;k<10 ;k++) {
            for(int l=0;l<10 ;l++) {




                             if ((n_Barrel_Quark_Background_counter[i][j][k][l]+n_Barrel_Quark_ISR_counter[i][j][k][l]+n_Barrel_Quark_FSR_counter[i][j][k][l]) > 0 &&
                             (n_Endcap_Quark_Background_counter[i][j][k][l]+n_Endcap_Quark_ISR_counter[i][j][k][l]+n_Endcap_Quark_FSR_counter[i][j][k][l]) > 0 &&
                             (n_Barrel_Quark_Signal_counter[i][j][k][l]/(n_Barrel_Quark_Background_counter[i][j][k][l]+n_Barrel_Quark_ISR_counter[i][j][k][l]+n_Barrel_Quark_FSR_counter[i][j][k][l])) < 0.001 &&
                             (n_Endcap_Quark_Signal_counter[i][j][k][l]/(n_Endcap_Quark_Background_counter[i][j][k][l]+n_Endcap_Quark_ISR_counter[i][j][k][l]+n_Endcap_Quark_FSR_counter[i][j][k][l])) < 0.001){


                             cout << "n_Barrel_Quark_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Quark_Background_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Quark_Background_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Barrel_Quark_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Quark_ISR_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Quark_ISR_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Barrel_Quark_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Quark_FSR_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Quark_FSR_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Barrel_Quark_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Quark_Signal_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Quark_Signal_counter[i][j][k][l])*sqrt(20000) << endl;

                             cout << "n_Endcap_Quark_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Quark_Background_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Quark_Background_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Endcap_Quark_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Quark_ISR_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Quark_ISR_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Endcap_Quark_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Quark_FSR_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Quark_FSR_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Endcap_Quark_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Quark_Signal_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Quark_Signal_counter[i][j][k][l])*sqrt(20000) << endl;


                             float num = n_Barrel_Quark_Signal_counter[i][j][k][l];
            float den = n_Barrel_Quark_Background_counter[i][j][k][l]+n_Barrel_Quark_ISR_counter[i][j][k][l]+n_Barrel_Quark_FSR_counter[i][j][k][l];
            float sum_square_num = err_Barrel_Quark_Signal_counter[i][j][k][l];
            float sum_square_den = err_Barrel_Quark_Background_counter[i][j][k][l]*err_Barrel_Quark_Background_counter[i][j][k][l]+err_Barrel_Quark_ISR_counter[i][j][k][l]*err_Barrel_Quark_ISR_counter[i][j][k][l]+err_Barrel_Quark_FSR_counter[i][j][k][l]*err_Barrel_Quark_FSR_counter[i][j][k][l];
                             float err = ( sum_square_num + sqrt(sum_square_den) * num / den ) / den;
            cout << "n_Barrel_Quark_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< n_Barrel_Quark_Signal_counter[i][j][k][l]/(n_Barrel_Quark_Background_counter[i][j][k][l]+n_Barrel_Quark_ISR_counter[i][j][k][l]+n_Barrel_Quark_FSR_counter[i][j][k][l]) << " +/- " << err << endl;

                             num = n_Endcap_Quark_Signal_counter[i][j][k][l];
            den = n_Endcap_Quark_Background_counter[i][j][k][l]+n_Endcap_Quark_ISR_counter[i][j][k][l]+n_Endcap_Quark_FSR_counter[i][j][k][l];
            sum_square_num = err_Endcap_Quark_Signal_counter[i][j][k][l];
            sum_square_den = err_Endcap_Quark_Background_counter[i][j][k][l]*err_Endcap_Quark_Background_counter[i][j][k][l]+err_Endcap_Quark_ISR_counter[i][j][k][l]*err_Endcap_Quark_ISR_counter[i][j][k][l]+err_Endcap_Quark_FSR_counter[i][j][k][l]*err_Endcap_Quark_FSR_counter[i][j][k][l];
                             err = ( sum_square_num + sqrt(sum_square_den) * num / den ) / den;
            cout << "n_Endcap_Quark_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< n_Endcap_Quark_Signal_counter[i][j][k][l]/(n_Endcap_Quark_Background_counter[i][j][k][l]+n_Endcap_Quark_ISR_counter[i][j][k][l]+n_Endcap_Quark_FSR_counter[i][j][k][l]) << " +/- " << err << endl;
                             }

                             if ((n_Barrel_Gluon_Background_counter[i][j][k][l]+n_Barrel_Gluon_ISR_counter[i][j][k][l]+n_Barrel_Gluon_FSR_counter[i][j][k][l]) > 0 &&
                             (n_Endcap_Gluon_Background_counter[i][j][k][l]+n_Endcap_Gluon_ISR_counter[i][j][k][l]+n_Endcap_Gluon_FSR_counter[i][j][k][l]) > 0 &&
                             (n_Barrel_Gluon_Signal_counter[i][j][k][l]/(n_Barrel_Gluon_Background_counter[i][j][k][l]+n_Barrel_Gluon_ISR_counter[i][j][k][l]+n_Barrel_Gluon_FSR_counter[i][j][k][l])) < 0.001 &&
                             (n_Endcap_Gluon_Signal_counter[i][j][k][l]/(n_Endcap_Gluon_Background_counter[i][j][k][l]+n_Endcap_Gluon_ISR_counter[i][j][k][l]+n_Endcap_Gluon_FSR_counter[i][j][k][l])) < 0.001){


                             cout << "n_Barrel_Gluon_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Gluon_Background_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Gluon_Background_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Barrel_Gluon_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Gluon_ISR_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Gluon_ISR_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Barrel_Gluon_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Gluon_FSR_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Gluon_FSR_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Barrel_Gluon_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Barrel_Gluon_Signal_counter[i][j][k][l]*20000 << " +/- " << (err_Barrel_Gluon_Signal_counter[i][j][k][l])*sqrt(20000) << endl;

                             cout << "n_Endcap_Gluon_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Gluon_Background_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Gluon_Background_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Endcap_Gluon_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Gluon_ISR_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Gluon_ISR_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Endcap_Gluon_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Gluon_FSR_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Gluon_FSR_counter[i][j][k][l])*sqrt(20000) << endl;
                             cout << "n_Endcap_Gluon_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< n_Endcap_Gluon_Signal_counter[i][j][k][l]*20000 << " +/- " << (err_Endcap_Gluon_Signal_counter[i][j][k][l])*sqrt(20000) << endl;


                             float num = n_Barrel_Gluon_Signal_counter[i][j][k][l];
            float den = n_Barrel_Gluon_Background_counter[i][j][k][l]+n_Barrel_Gluon_ISR_counter[i][j][k][l]+n_Barrel_Gluon_FSR_counter[i][j][k][l];
            float sum_square_num = err_Barrel_Gluon_Signal_counter[i][j][k][l];
            float sum_square_den = err_Barrel_Gluon_Background_counter[i][j][k][l]*err_Barrel_Gluon_Background_counter[i][j][k][l]+err_Barrel_Gluon_ISR_counter[i][j][k][l]*err_Barrel_Gluon_ISR_counter[i][j][k][l]+err_Barrel_Gluon_FSR_counter[i][j][k][l]*err_Endcap_Quark_FSR_counter[i][j][k][l];

                             float err = ( sum_square_num + sqrt(sum_square_den) * num / den ) / den;
            cout << "n_Barrel_Gluon_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< n_Barrel_Gluon_Signal_counter[i][j][k][l]/(n_Barrel_Gluon_Background_counter[i][j][k][l]+n_Barrel_Gluon_ISR_counter[i][j][k][l]+n_Barrel_Gluon_FSR_counter[i][j][k][l]) << " +/- " << err << endl;

                             num = n_Endcap_Gluon_Signal_counter[i][j][k][l];
            den = n_Endcap_Gluon_Background_counter[i][j][k][l]+n_Endcap_Gluon_ISR_counter[i][j][k][l]+n_Endcap_Gluon_FSR_counter[i][j][k][l];
            sum_square_num = err_Endcap_Gluon_Signal_counter[i][j][k][l];
            sum_square_den = err_Endcap_Gluon_Background_counter[i][j][k][l]*err_Endcap_Gluon_Background_counter[i][j][k][l]+err_Endcap_Gluon_ISR_counter[i][j][k][l]*err_Endcap_Gluon_ISR_counter[i][j][k][l]+err_Endcap_Gluon_FSR_counter[i][j][k][l]*err_Endcap_Gluon_FSR_counter[i][j][k][l];
                             err = ( sum_square_num + sqrt(sum_square_den) * num / den ) / den;
            cout << "n_Endcap_Gluon_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< n_Endcap_Gluon_Signal_counter[i][j][k][l]/(n_Endcap_Gluon_Background_counter[i][j][k][l]+n_Endcap_Gluon_ISR_counter[i][j][k][l]+n_Endcap_Gluon_FSR_counter[i][j][k][l]) << " +/- " << err << endl;


                             }

                
            cout << "*********************************************" << endl;
            cout << "*********************************************" << endl;
            cout << "*********************************************" << endl;


                    }}}}






}
