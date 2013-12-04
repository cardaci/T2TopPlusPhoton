#include "TTree.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TH1F.h"
#include "TH2F.h"
#include "interface/format.h"
#include "TChain.h"
#include "TCanvas.h"
//#include "interface/TriggerBooking.h"
#include "interface/DPHI.h"
#include "interface/RecoLeptonSelection.h"
#include "interface/RecoPhotonSelectionFONoSigmaIetaIeta.h"
#include "interface/RecoJetSelection.h"
//#include "interface/SolutionOfWNeutrino.h"
//#include "Math.h"
#include "interface/ConstantNumbers.h"
#include "TLorentzVector.h"
#include <string>
#include <iostream>
#include <vector>

#include <TFile.h>//Add by Yuhsiang

#include "interface/EffectiveAreaPhoton.h"

void FO_Optimization_1()
{
    gROOT->ProcessLine(".L interface/setTDRStyle.C");
    gROOT->ProcessLine("setTDRStyle()");
    gStyle->SetPalette(1);

    TChain * root[34]; 

    for(unsigned int i=0; i<34; i++){
      root[i] = new TChain("bprimeKit/root");
    }


//    root[0]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/v4/QCD_Pt_20_30_EMEnriched_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[1]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/v4/QCD_Pt_80_170_EMEnriched_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
/*
    root[2]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/v4/QCD_Pt_170_250_EMEnriched_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[3]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/v4/QCD_Pt_250_350_EMEnriched_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[4]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/v4/QCD_Pt_350_EMEnriched_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
*/
    //root[5]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/v4/QCD_Pt_30_80_EMEnriched_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root
//    root[5]->Add("/data4/cardaci/stableQCD_Pt_30_80_EMEnriched_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");



/*    
    root[6]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/sync/GJets_HT-40To100_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V19-v1/*.root");
    root[7]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/sync/GJets_HT-100To200_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V19-v1/*.root");
    root[8]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/sync/GJets_HT-200To400_8TeV-madgraph_v2_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[9]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/sync/GJets_HT-400ToInf_8TeV-madgraph_v3_Summer12_DR53X-PU_S10_START53_V7C-v1/*.root");
*/

  /*

    root[0]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_noSigmaIetaIeta_QCD_Pt_20_30_EMEnriched_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1.root");
    root[1]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_noSigmaIetaIeta_QCD_Pt_80_170_EMEnriched_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1.root");
    root[2]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_noSigmaIetaIeta_QCD_Pt_170_250_EMEnriched_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1.root");
    root[3]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_noSigmaIetaIeta_QCD_Pt_250_350_EMEnriched_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1.root");
    root[4]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_noSigmaIetaIeta_QCD_Pt_350_EMEnriched_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1.root");
    root[5]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_noSigmaIetaIeta_stableQCD_Pt_30_80_EMEnriched_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1.root");
    root[6]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_noSigmaIetaIeta_GJets_HT-40To100_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V19-v1.root");
    root[7]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_noSigmaIetaIeta_GJets_HT-100To200_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V19-v1.root");
    root[8]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_noSigmaIetaIeta_GJets_HT-200To400_8TeV-madgraph_v2_Summer12_DR53X-PU_S10_START53_V7A-v1.root");
    root[9]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_noSigmaIetaIeta_GJets_HT-400ToInf_8TeV-madgraph_v3_Summer12_DR53X-PU_S10_START53_V7C-v1.root");

    */
/*
    root[10]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-450_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[11]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-475_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[12]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-500_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[13]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-525_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[14]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-550_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[15]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-575_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[16]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-600_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[17]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-625_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[18]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-650_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[19]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-675_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[20]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-700_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[21]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-725_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[22]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-750_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[23]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-775_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[24]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-800_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[25]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-850_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7C-v1/*.root");
    root[26]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-900_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7C-v1/*.root");
    root[27]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-950_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7C-v1/*.root");
    root[28]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-1000_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7C-v1/*.root"); 
    root[29]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-1100_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7C-v1/*.root"); 
    root[30]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-1200_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7C-v1/*.root");
    root[31]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-1300_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7C-v1/*.root");
    root[32]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-1400_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7C-v1/*.root");
    root[33]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-1500_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7C-v1/*.root");
*/

    /*
    EvtInfoBranches EvtInfo;
    EvtInfo.Register(root);
    GenInfoBranches GenInfo;
    GenInfo.Register(root);
    LepInfoBranches LepInfo;
    LepInfo.Register(root,"PFLepInfo");
    JetInfoBranches JetInfo;
    JetInfo.Register(root,"PFJetInfo");
    PhotonInfoBranches PhotonInfo;
    PhotonInfo.Register(root,"PhotonInfo");
    VertexInfoBranches VertexInfo;
    VertexInfo.Register(root);
    */


    /*
    root->SetBranchStatus("*"      ,0);
    oot->SetBranchStatus("GenInfo.*"      ,1);
    root->SetBranchStatus("PFLepInfo.*"      ,1);
    root->SetBranchStatus("PFJetInfo.*"      ,1);
    root->SetBranchStatus("PhotonInfo.*"      ,1);
    */


	





    EvtInfoBranches EvtInfo;
    GenInfoBranches GenInfo;
    LepInfoBranches LepInfo;
    JetInfoBranches JetInfo;
    PhotonInfoBranches PhotonInfo;
    VertexInfoBranches VertexInfo;

    // QCD PtHat 30-80 is put as last and not used given that the weight is much larger than 1 (about 46).
    // Cross check if the number of events for QCD PtHat 170-250 is that or the double as found by Yu-hsiang some time ago



    float set_of_xsections[34]={288600000, 1191000, 30990, 4250, 810, 74330000, 20930, 5212, 960.5, 107.5, 0.71, 0.51, 0.37, 0.27, 0.2, 0.51, 0.11, 0.085, 0.068, 0.05, 0.039, 0.03, 0.024, 0.019, 0.015, 0.0091, 0.0058, 0.037, 0.0024, 0.001, 0.00044, 0.00019, 0.000084, 0.000037};

    float set_of_filter_efficiency[34]={0.0101, 0.1539, 0.148, 0.131, 0.11, 0.0621, 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1.};

    float set_of_number_of_events[34] = {0};
/*
    // QCD
    set_of_number_of_events[0] = 27212467;
    set_of_number_of_events[1] = 12557989;
    set_of_number_of_events[2] = 2705404;
    set_of_number_of_events[3] = 1506866;
    set_of_number_of_events[4] = 26292910;
    set_of_number_of_events[5] = 16867284;
    // GJets
    set_of_number_of_events[6] = 19800506;
    set_of_number_of_events[7] = 9246629;
    set_of_number_of_events[8] = 42365645;
    set_of_number_of_events[9] = 36215351;
    // Tprime
*/

    for(int sample_index=0;sample_index<34;sample_index++){
     set_of_number_of_events[sample_index] = root[sample_index]->GetEntries();
    }

    float set_of_weights[34] = {0};


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



               for(int i=0;i<10 ;i++) {
               for(int j=0;j<10 ;j++) {
               for(int k=0;k<10 ;k++) {
               for(int l=0;l<10 ;l++) {


                 sprintf(name_Barrel_Quark_Background_counter[i][j][k][l],"h_Barrel_Quark_Background_counter_%d_%d_%d_%d", i, j, k, l);
		 h_Barrel_Quark_Background_counter[i][j][k][l] = new TH1F(name_Barrel_Quark_Background_counter[i][j][k][l],name_Barrel_Quark_Background_counter[i][j][k][l], 1, -1, 1);

                 sprintf(name_Barrel_Gluon_Background_counter[i][j][k][l],"h_Barrel_Gluon_Background_counter_%d_%d_%d_%d", i, j, k, l);
		 h_Barrel_Gluon_Background_counter[i][j][k][l] = new TH1F(name_Barrel_Gluon_Background_counter[i][j][k][l],name_Barrel_Gluon_Background_counter[i][j][k][l], 1, -1, 1);


                 sprintf(name_Endcap_Quark_Background_counter[i][j][k][l],"h_Endcap_Quark_Background_counter_%d_%d_%d_%d", i, j, k, l);
		 h_Endcap_Quark_Background_counter[i][j][k][l] = new TH1F(name_Endcap_Quark_Background_counter[i][j][k][l],name_Endcap_Quark_Background_counter[i][j][k][l], 1, -1, 1);

                 sprintf(name_Endcap_Gluon_Background_counter[i][j][k][l],"h_Endcap_Gluon_Background_counter_%d_%d_%d_%d", i, j, k, l);
		 h_Endcap_Gluon_Background_counter[i][j][k][l] = new TH1F(name_Endcap_Gluon_Background_counter[i][j][k][l],name_Endcap_Gluon_Background_counter[i][j][k][l], 1, -1, 1);



                 sprintf(name_Barrel_Quark_ISR_counter[i][j][k][l],"h_Barrel_Quark_ISR_counter_%d_%d_%d_%d", i, j, k, l);
		 h_Barrel_Quark_ISR_counter[i][j][k][l] = new TH1F(name_Barrel_Quark_ISR_counter[i][j][k][l],name_Barrel_Quark_ISR_counter[i][j][k][l], 1, -1, 1);

                 sprintf(name_Barrel_Gluon_ISR_counter[i][j][k][l],"h_Barrel_Gluon_ISR_counter_%d_%d_%d_%d", i, j, k, l);
		 h_Barrel_Gluon_ISR_counter[i][j][k][l] = new TH1F(name_Barrel_Gluon_ISR_counter[i][j][k][l],name_Barrel_Gluon_ISR_counter[i][j][k][l], 1, -1, 1);


                 sprintf(name_Endcap_Quark_ISR_counter[i][j][k][l],"h_Endcap_Quark_ISR_counter_%d_%d_%d_%d", i, j, k, l);
		 h_Endcap_Quark_ISR_counter[i][j][k][l] = new TH1F(name_Endcap_Quark_ISR_counter[i][j][k][l],name_Endcap_Quark_ISR_counter[i][j][k][l], 1, -1, 1);

                 sprintf(name_Endcap_Gluon_ISR_counter[i][j][k][l],"h_Endcap_Gluon_ISR_counter_%d_%d_%d_%d", i, j, k, l);
		 h_Endcap_Gluon_ISR_counter[i][j][k][l] = new TH1F(name_Endcap_Gluon_ISR_counter[i][j][k][l],name_Endcap_Gluon_ISR_counter[i][j][k][l], 1, -1, 1);



                 sprintf(name_Barrel_Quark_FSR_counter[i][j][k][l],"h_Barrel_Quark_FSR_counter_%d_%d_%d_%d", i, j, k, l);
		 h_Barrel_Quark_FSR_counter[i][j][k][l] = new TH1F(name_Barrel_Quark_FSR_counter[i][j][k][l],name_Barrel_Quark_FSR_counter[i][j][k][l], 1, -1, 1);

                 sprintf(name_Barrel_Gluon_FSR_counter[i][j][k][l],"h_Barrel_Gluon_FSR_counter_%d_%d_%d_%d", i, j, k, l);
		 h_Barrel_Gluon_FSR_counter[i][j][k][l] = new TH1F(name_Barrel_Gluon_FSR_counter[i][j][k][l],name_Barrel_Gluon_FSR_counter[i][j][k][l], 1, -1, 1);


                 sprintf(name_Endcap_Quark_FSR_counter[i][j][k][l],"h_Endcap_Quark_FSR_counter_%d_%d_%d_%d", i, j, k, l);
		 h_Endcap_Quark_FSR_counter[i][j][k][l] = new TH1F(name_Endcap_Quark_FSR_counter[i][j][k][l],name_Endcap_Quark_FSR_counter[i][j][k][l], 1, -1, 1);

                 sprintf(name_Endcap_Gluon_FSR_counter[i][j][k][l],"h_Endcap_Gluon_FSR_counter_%d_%d_%d_%d", i, j, k, l);
		 h_Endcap_Gluon_FSR_counter[i][j][k][l] = new TH1F(name_Endcap_Gluon_FSR_counter[i][j][k][l],name_Endcap_Gluon_FSR_counter[i][j][k][l], 1, -1, 1);



                 sprintf(name_Barrel_Quark_Signal_counter[i][j][k][l],"h_Barrel_Quark_Signal_counter_%d_%d_%d_%d", i, j, k, l);
		 h_Barrel_Quark_Signal_counter[i][j][k][l] = new TH1F(name_Barrel_Quark_Signal_counter[i][j][k][l],name_Barrel_Quark_Signal_counter[i][j][k][l], 1, -1, 1);

                 sprintf(name_Barrel_Gluon_Signal_counter[i][j][k][l],"h_Barrel_Gluon_Signal_counter_%d_%d_%d_%d", i, j, k, l);
		 h_Barrel_Gluon_Signal_counter[i][j][k][l] = new TH1F(name_Barrel_Gluon_Signal_counter[i][j][k][l],name_Barrel_Gluon_Signal_counter[i][j][k][l], 1, -1, 1);


                 sprintf(name_Endcap_Quark_Signal_counter[i][j][k][l],"h_Endcap_Quark_Signal_counter_%d_%d_%d_%d", i, j, k, l);
		 h_Endcap_Quark_Signal_counter[i][j][k][l] = new TH1F(name_Endcap_Quark_Signal_counter[i][j][k][l],name_Endcap_Quark_Signal_counter[i][j][k][l], 1, -1, 1);

                 sprintf(name_Endcap_Gluon_Signal_counter[i][j][k][l],"h_Endcap_Gluon_Signal_counter_%d_%d_%d_%d", i, j, k, l);
		 h_Endcap_Gluon_Signal_counter[i][j][k][l] = new TH1F(name_Endcap_Gluon_Signal_counter[i][j][k][l],name_Endcap_Gluon_Signal_counter[i][j][k][l], 1, -1, 1);


	       }}}}




               for(int i=0;i<10 ;i++) {
               for(int j=0;j<10 ;j++) {
               for(int k=0;k<10 ;k++) {
               for(int l=0;l<10 ;l++) {


                 h_Barrel_Quark_Background_counter[i][j][k][l]->Sumw2();
                 h_Endcap_Quark_Background_counter[i][j][k][l]->Sumw2();
                 h_Barrel_Gluon_Background_counter[i][j][k][l]->Sumw2();
                 h_Endcap_Gluon_Background_counter[i][j][k][l]->Sumw2();

                 h_Barrel_Quark_ISR_counter[i][j][k][l]->Sumw2();
                 h_Endcap_Quark_ISR_counter[i][j][k][l]->Sumw2();
                 h_Barrel_Gluon_ISR_counter[i][j][k][l]->Sumw2();
                 h_Endcap_Gluon_ISR_counter[i][j][k][l]->Sumw2();

                 h_Barrel_Quark_FSR_counter[i][j][k][l]->Sumw2();
                 h_Endcap_Quark_FSR_counter[i][j][k][l]->Sumw2();
                 h_Barrel_Gluon_FSR_counter[i][j][k][l]->Sumw2();
                 h_Endcap_Gluon_FSR_counter[i][j][k][l]->Sumw2();

                 h_Barrel_Quark_Signal_counter[i][j][k][l]->Sumw2();
                 h_Endcap_Quark_Signal_counter[i][j][k][l]->Sumw2();
                 h_Barrel_Gluon_Signal_counter[i][j][k][l]->Sumw2();
                 h_Endcap_Gluon_Signal_counter[i][j][k][l]->Sumw2();



	       }}}}


	       for(int sample_index=1;sample_index<2;sample_index++){


     set_of_weights[sample_index] = set_of_xsections[sample_index] * set_of_filter_efficiency[sample_index] / set_of_number_of_events[sample_index];

     cout<<"sample_index:"<<sample_index<<endl;

     EvtInfo.Register(root[sample_index]);
     GenInfo.Register(root[sample_index]);
     LepInfo.Register(root[sample_index],"PFLepInfo");
     JetInfo.Register(root[sample_index],"PFJetInfo");
     PhotonInfo.Register(root[sample_index],"PhotonInfo");
     VertexInfo.Register(root[sample_index]);

        map< pair<int, int>, int > evtlist;//to remove duplicate event in data
       //Event loop begin
	for(int entry=0; entry < root[sample_index]->GetEntries(); entry++) {
        int tot_entries = root[sample_index]->GetEntries();

        root[sample_index]->GetEntry(entry);

        if(!EvtInfo.McFlag) {
            // remove duplicate event
            map< pair<int, int> , int>::iterator evtitr;
            evtitr = evtlist.find( pair<int, int>(EvtInfo.RunNo, EvtInfo.EvtNo) );
            if( evtitr == evtlist.end() )
                evtlist.insert( pair<pair<int, int>, int>(pair<int, int>(EvtInfo.RunNo, EvtInfo.EvtNo), 1));
            else
                continue;
        }

	if (entry % 500 == 0) cout << "Entry: " << entry << " / " << tot_entries << endl;

   	
	int E_Index[MAX_LEPTONS];
	int M_Index[MAX_LEPTONS];
	int L_Index[MAX_LEPTONS];
	int J_Index[MAX_JETS];
	int P_Index[MAX_PHOTONS];
	int P_Index_FO[MAX_PHOTONS];
	int P_Index_TIGHT[MAX_PHOTONS];

	for(int m=0;m<MAX_LEPTONS/2;m++) M_Index[m] = 0;
	for(int e=0;e<MAX_LEPTONS/2;e++) E_Index[e] = 0;
	for(int l=0;l<MAX_LEPTONS/2*2;l++) L_Index[l] = 0;
	for(int j=0;j<MAX_PHOTONS;j++) J_Index[j] = 0;
	for(int p=0;p<MAX_PHOTONS;p++) P_Index[p] = 0;
	for(int p=0;p<MAX_PHOTONS;p++) P_Index_FO[p] = 0;
	for(int p=0;p<MAX_PHOTONS;p++) P_Index_TIGHT[p] = 0;

        int NMuons = 0;
	int NElectrons = 0;
	int NLeptons = 0;
	int NJets = 0;
        int NPhotons = 0;
        int NPhotons_FO = 0;
        int NPhotons_TIGHT = 0;

       	RecoLeptonSelection(EvtInfo, LepInfo, NMuons, M_Index, NElectrons, E_Index, NLeptons, L_Index);
       	RecoJetSelection(LepInfo, JetInfo, PhotonInfo, NMuons, M_Index, NElectrons, E_Index, NJets, J_Index, NPhotons, P_Index);
	RecoPhotonSelectionFONoSigmaIetaIeta(LepInfo, PhotonInfo, JetInfo, NJets, J_Index, NMuons, M_Index, NElectrons, E_Index, NPhotons_FO, P_Index_FO, EvtInfo.RhoPU[0]);

        int NVertices=0;
        int V_Index[50];
        for(int v=0;v<50;v++) V_Index[v] = 0;
        for(int j=0;j<VertexInfo.Size;j++) {
            if(VertexInfo.isValid[j]!=1) continue;
            if(VertexInfo.Type[j]!=0) continue;
            if(VertexInfo.Ndof[j]<=4) continue;
            if(fabs(VertexInfo.Rho[j])>=2) continue;
            if(fabs(VertexInfo.z[j])>=24) continue;
            V_Index[NVertices] = j;
            NVertices++;
        }

        float RhoPU = EvtInfo.RhoPU[0];


	    for(int g=0;g<NPhotons_FO;g++) { // loop on FO photons


     	      double dR_aux = 0.5;
              int jindex;
	      for(int j=0;j<NJets;j++) { // loop on jets
 	         double dphi = DPHI(PhotonInfo.Phi[P_Index_FO[g]], JetInfo.Phi[J_Index[j]]);
	         double deta = fabs(PhotonInfo.Eta[P_Index_FO[g]]- JetInfo.Eta[J_Index[j]]);
                 double dR   = pow(dphi*dphi+deta*deta, 0.5);
                 if(dR < dR_aux){ dR_aux = dR; jindex = j;}
	      }

               double dR_aux2 = 0.5;

               int mindex;
               for(int m=0;m<GenInfo.Size ;m++) { // loop on GenInfo
                 double dphi = DPHI(PhotonInfo.Phi[P_Index_FO[g]], GenInfo.Phi[m]);
                 double deta = fabs(PhotonInfo.Eta[P_Index_FO[g]]-GenInfo.Eta[m]);
                 double dR   = pow(dphi*dphi+deta*deta, 0.5);
                 if(dR < dR_aux2){ dR_aux2 = dR; mindex = m;}
                 
               }




               for(int i=0;i<10 ;i++) {
               for(int j=0;j<10 ;j++) {
               for(int k=0;k<10 ;k++) {
               for(int l=0;l<10 ;l++) {




	        if(dR_aux < 0.5 /*&& NJets >=4*/){





  	  	   if(
		     PhotonInfo.hadTowOverEm[P_Index_FO[g]] > i * 0.01 &&
                    (max(PhotonInfo.phoPFChIsoDR03[P_Index_FO[g]]-EffectiveAreaPhoton(PhotonInfo.Eta[P_Index_FO[g]],0)*RhoPU,(float)0.) > j * 0.7) &&
                    (max(PhotonInfo.phoPFNeuIsoDR03[P_Index_FO[g]]-EffectiveAreaPhoton(PhotonInfo.Eta[P_Index_FO[g]],1)*RhoPU,(float)0.)> k * (0.4+0.04*PhotonInfo.Pt[P_Index_FO[g]])) &&
                    (max(PhotonInfo.phoPFPhoIsoDR03[P_Index_FO[g]]-EffectiveAreaPhoton(PhotonInfo.Eta[P_Index_FO[g]],2)*RhoPU,(float)0.)> l * (0.5+0.005*PhotonInfo.Pt[P_Index_FO[g]]))
                    ){



  		        if(fabs(PhotonInfo.Eta[P_Index_FO[g]])< 1.4442){//Barrel
		          if( JetInfo.QGTagsLikelihood[J_Index[jindex]] > 0.9){ // Quark-like
  			        if( (dR_aux2 != 0.5) && (GenInfo.PhotonFlag[mindex]==1)  ) h_Barrel_Quark_Background_counter[i][j][k][l]->Fill(0.,set_of_weights[sample_index]);;
	                        if( (dR_aux2 != 0.5) && (GenInfo.PhotonFlag[mindex]==0)  ) h_Barrel_Quark_Signal_counter[i][j][k][l]->Fill(0.,set_of_weights[sample_index]);;
	                        if( (dR_aux2 != 0.5) && (GenInfo.PhotonFlag[mindex]==2)  ) h_Barrel_Quark_ISR_counter[i][j][k][l]->Fill(0.,set_of_weights[sample_index]);;
	                        if( (dR_aux2 != 0.5) && (GenInfo.PhotonFlag[mindex]==3)  ) h_Barrel_Quark_FSR_counter[i][j][k][l]->Fill(0.,set_of_weights[sample_index]);;

			  }
                          if( JetInfo.QGTagsLikelihood[J_Index[jindex]] < 0.9 && JetInfo.QGTagsLikelihood[J_Index[jindex]] >= 0.){ // Gluon-like
			        if( (dR_aux2 != 0.5) && (GenInfo.PhotonFlag[mindex]==1)  ) h_Barrel_Gluon_Background_counter[i][j][k][l]->Fill(0.,set_of_weights[sample_index]);;
	                        if( (dR_aux2 != 0.5) && (GenInfo.PhotonFlag[mindex]==0)  ) h_Barrel_Gluon_Signal_counter[i][j][k][l]->Fill(0.,set_of_weights[sample_index]);;
	                        if( (dR_aux2 != 0.5) && (GenInfo.PhotonFlag[mindex]==2)  ) h_Barrel_Gluon_ISR_counter[i][j][k][l]->Fill(0.,set_of_weights[sample_index]);;
	                        if( (dR_aux2 != 0.5) && (GenInfo.PhotonFlag[mindex]==3)  ) h_Barrel_Gluon_FSR_counter[i][j][k][l]->Fill(0.,set_of_weights[sample_index]);;

			  }
			}

		   }


  	  	   if(
		     PhotonInfo.hadTowOverEm[P_Index_FO[g]]> i * 0.01 &&
                    (max(PhotonInfo.phoPFChIsoDR03[P_Index_FO[g]]-EffectiveAreaPhoton(PhotonInfo.Eta[P_Index_FO[g]],0)*RhoPU,(float)0.) > j * 0.5) &&
                    (max(PhotonInfo.phoPFNeuIsoDR03[P_Index_FO[g]]-EffectiveAreaPhoton(PhotonInfo.Eta[P_Index_FO[g]],1)*RhoPU,(float)0.)> k * (1.5+0.04*PhotonInfo.Pt[P_Index_FO[g]])) &&
                    (max(PhotonInfo.phoPFPhoIsoDR03[P_Index_FO[g]]-EffectiveAreaPhoton(PhotonInfo.Eta[P_Index_FO[g]],2)*RhoPU,(float)0.)> l * (1.0+0.005*PhotonInfo.Pt[P_Index_FO[g]]))
                    ){



			if(fabs(PhotonInfo.Eta[P_Index_FO[g]])< 2.4 && fabs(PhotonInfo.Eta[P_Index_FO[g]])>= 1.566){//Endcap
		          if( JetInfo.QGTagsLikelihood[J_Index[jindex]] > 0.9){ // Quark-like
   	                        if( (dR_aux2 != 0.5) && (GenInfo.PhotonFlag[mindex]==1)  ) h_Endcap_Quark_Background_counter[i][j][k][l]->Fill(0.,set_of_weights[sample_index]);;
	                        if( (dR_aux2 != 0.5) && (GenInfo.PhotonFlag[mindex]==0)  ) h_Endcap_Quark_Signal_counter[i][j][k][l]->Fill(0.,set_of_weights[sample_index]);;
	                        if( (dR_aux2 != 0.5) && (GenInfo.PhotonFlag[mindex]==2)  ) h_Endcap_Quark_ISR_counter[i][j][k][l]->Fill(0.,set_of_weights[sample_index]);;
	                        if( (dR_aux2 != 0.5) && (GenInfo.PhotonFlag[mindex]==3)  ) h_Endcap_Quark_FSR_counter[i][j][k][l]->Fill(0.,set_of_weights[sample_index]);;


			  }
                          if( JetInfo.QGTagsLikelihood[J_Index[jindex]] < 0.9 && JetInfo.QGTagsLikelihood[J_Index[jindex]] >= 0.){ // Gluon-like
	                        if( (dR_aux2 != 0.5) && (GenInfo.PhotonFlag[mindex]==1)  ) h_Endcap_Gluon_Background_counter[i][j][k][l]->Fill(0.,set_of_weights[sample_index]);;
	                        if( (dR_aux2 != 0.5) && (GenInfo.PhotonFlag[mindex]==0)  ) h_Endcap_Gluon_Signal_counter[i][j][k][l]->Fill(0.,set_of_weights[sample_index]);;
	                        if( (dR_aux2 != 0.5) && (GenInfo.PhotonFlag[mindex]==2)  ) h_Endcap_Gluon_ISR_counter[i][j][k][l]->Fill(0.,set_of_weights[sample_index]);;
	                        if( (dR_aux2 != 0.5) && (GenInfo.PhotonFlag[mindex]==3)  ) h_Endcap_Gluon_FSR_counter[i][j][k][l]->Fill(0.,set_of_weights[sample_index]);;

			  }
			}

		   }






		}


		 


	       }
	       }
	       }
	       }





	    } // loop on FO photons

       } //event loop end

    } // sample loop end

 


	       /*

               for(int i=0;i<10 ;i++) {
               for(int j=0;j<10 ;j++) {
               for(int k=0;k<10 ;k++) {
               for(int l=0;l<10 ;l++) {

		 cout << "Barrel_Quark_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Quark_Background_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Quark_Background_squared_weight[i][j][k][l])*20000 << endl;
		 cout << "Barrel_Gluon_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Gluon_Background_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Gluon_Background_squared_weight[i][j][k][l])*20000 << endl;
		 cout << "Endcap_Quark_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Quark_Background_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Quark_Background_squared_weight[i][j][k][l])*20000 << endl;
		 cout << "Endcap_Gluon_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Gluon_Background_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Gluon_Background_squared_weight[i][j][k][l])*20000 << endl;

		 cout << "Barrel_Quark_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Quark_ISR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Quark_ISR_squared_weight[i][j][k][l])*20000 << endl;
		 cout << "Barrel_Gluon_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Gluon_ISR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Gluon_ISR_squared_weight[i][j][k][l])*20000 << endl;
		 cout << "Endcap_Quark_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Quark_ISR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Quark_ISR_squared_weight[i][j][k][l])*20000 << endl;
		 cout << "Endcap_Gluon_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Gluon_ISR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Gluon_ISR_squared_weight[i][j][k][l])*20000 << endl;

		 cout << "Barrel_Quark_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Quark_FSR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Quark_FSR_squared_weight[i][j][k][l])*20000 << endl;
		 cout << "Barrel_Gluon_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Gluon_FSR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Gluon_FSR_squared_weight[i][j][k][l])*20000 << endl;
		 cout << "Endcap_Quark_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Quark_FSR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Quark_FSR_squared_weight[i][j][k][l])*20000 << endl;
		 cout << "Endcap_Gluon_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Gluon_FSR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Gluon_FSR_squared_weight[i][j][k][l])*20000 << endl;

		 cout << "Barrel_Quark_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Quark_Signal_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Quark_Signal_squared_weight[i][j][k][l])*20000 << endl;
		 cout << "Barrel_Gluon_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Gluon_Signal_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Gluon_Signal_squared_weight[i][j][k][l])*20000 << endl;
		 cout << "Endcap_Quark_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Quark_Signal_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Quark_Signal_squared_weight[i][j][k][l])*20000 << endl;
		 cout << "Endcap_Gluon_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Gluon_Signal_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Gluon_Signal_squared_weight[i][j][k][l])*20000 << endl;



                 cout << "*********************************************" << endl;
		 
		 if ((Barrel_Quark_Background_counter[i][j][k][l]+Barrel_Quark_ISR_counter[i][j][k][l]+Barrel_Quark_FSR_counter[i][j][k][l]) > 0){
		    float num = Barrel_Quark_Signal_counter[i][j][k][l];
                    float den = Barrel_Quark_Background_counter[i][j][k][l]+Barrel_Quark_ISR_counter[i][j][k][l]+Barrel_Quark_FSR_counter[i][j][k][l];
                    float sum_square_num = Barrel_Quark_Signal_squared_weight[i][j][k][l];
                    float sum_square_den = Barrel_Quark_Background_squared_weight[i][j][k][l]+Barrel_Quark_ISR_squared_weight[i][j][k][l]+Barrel_Quark_FSR_squared_weight[i][j][k][l];
		    float err = ( sqrt(sum_square_num) + sqrt(sum_square_den) * num / den ) / den;
                    cout << "Barrel_Quark_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< Barrel_Quark_Signal_counter[i][j][k][l]/(Barrel_Quark_Background_counter[i][j][k][l]+Barrel_Quark_ISR_counter[i][j][k][l]+Barrel_Quark_FSR_counter[i][j][k][l]) << " +/- " << err << endl;
		 }

		 if ((Barrel_Gluon_Background_counter[i][j][k][l]+Barrel_Gluon_ISR_counter[i][j][k][l]+Barrel_Gluon_FSR_counter[i][j][k][l]) > 0){
		    float num = Barrel_Gluon_Signal_counter[i][j][k][l];
                    float den = Barrel_Gluon_Background_counter[i][j][k][l]+Barrel_Gluon_ISR_counter[i][j][k][l]+Barrel_Gluon_FSR_counter[i][j][k][l];
                    float sum_square_num = Barrel_Gluon_Signal_squared_weight[i][j][k][l];
                    float sum_square_den = Barrel_Gluon_Background_squared_weight[i][j][k][l]+Barrel_Gluon_ISR_squared_weight[i][j][k][l]+Barrel_Gluon_FSR_squared_weight[i][j][k][l];
		    float err = ( sqrt(sum_square_num) + sqrt(sum_square_den) * num / den ) / den;
                    cout << "Barrel_Gluon_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< Barrel_Gluon_Signal_counter[i][j][k][l]/(Barrel_Gluon_Background_counter[i][j][k][l]+Barrel_Gluon_ISR_counter[i][j][k][l]+Barrel_Gluon_FSR_counter[i][j][k][l]) << " +/- " << err << endl;
		 }

		 if ((Endcap_Quark_Background_counter[i][j][k][l]+Endcap_Quark_ISR_counter[i][j][k][l]+Endcap_Quark_FSR_counter[i][j][k][l]) > 0){
		    float num = Endcap_Quark_Signal_counter[i][j][k][l];
                    float den = Endcap_Quark_Background_counter[i][j][k][l]+Endcap_Quark_ISR_counter[i][j][k][l]+Endcap_Quark_FSR_counter[i][j][k][l];
                    float sum_square_num = Endcap_Quark_Signal_squared_weight[i][j][k][l];
                    float sum_square_den = Endcap_Quark_Background_squared_weight[i][j][k][l]+Endcap_Quark_ISR_squared_weight[i][j][k][l]+Endcap_Quark_FSR_squared_weight[i][j][k][l];
		    float err = ( sqrt(sum_square_num) + sqrt(sum_square_den) * num / den ) / den;
                    cout << "Endcap_Quark_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< Endcap_Quark_Signal_counter[i][j][k][l]/(Endcap_Quark_Background_counter[i][j][k][l]+Endcap_Quark_ISR_counter[i][j][k][l]+Endcap_Quark_FSR_counter[i][j][k][l]) << " +/- " << err << endl;
		 }

		 if ((Endcap_Gluon_Background_counter[i][j][k][l]+Endcap_Gluon_ISR_counter[i][j][k][l]+Endcap_Gluon_FSR_counter[i][j][k][l]) > 0){
		    float num = Endcap_Gluon_Signal_counter[i][j][k][l];
                    float den = Endcap_Gluon_Background_counter[i][j][k][l]+Endcap_Gluon_ISR_counter[i][j][k][l]+Endcap_Gluon_FSR_counter[i][j][k][l];
                    float sum_square_num = Endcap_Gluon_Signal_squared_weight[i][j][k][l];
                    float sum_square_den = Endcap_Gluon_Background_squared_weight[i][j][k][l]+Endcap_Gluon_ISR_squared_weight[i][j][k][l]+Endcap_Gluon_FSR_squared_weight[i][j][k][l];
		    float err = ( sqrt(sum_square_num) + sqrt(sum_square_den) * num / den ) / den;
                    cout << "Endcap_Gluon_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< Endcap_Gluon_Signal_counter[i][j][k][l]/(Endcap_Gluon_Background_counter[i][j][k][l]+Endcap_Gluon_ISR_counter[i][j][k][l]+Endcap_Gluon_FSR_counter[i][j][k][l]) << " +/- " << err << endl;
		 }

		 
                 cout << "*********************************************" << endl;
                 cout << "*********************************************" << endl;
                 cout << "*********************************************" << endl;

          
	       }}}}



               cout << "*********************************************" << endl;
               cout << "**************** BEST OF 0.01 ***************" << endl;
               cout << "*********************************************" << endl;

               for(int i=0;i<10 ;i++) {
               for(int j=0;j<10 ;j++) {
               for(int k=0;k<10 ;k++) {
               for(int l=0;l<10 ;l++) {




		 if ((Barrel_Quark_Background_counter[i][j][k][l]+Barrel_Quark_ISR_counter[i][j][k][l]+Barrel_Quark_FSR_counter[i][j][k][l]) > 0 &&
		     (Endcap_Quark_Background_counter[i][j][k][l]+Endcap_Quark_ISR_counter[i][j][k][l]+Endcap_Quark_FSR_counter[i][j][k][l]) > 0 &&
		     (Barrel_Quark_Signal_counter[i][j][k][l]/(Barrel_Quark_Background_counter[i][j][k][l]+Barrel_Quark_ISR_counter[i][j][k][l]+Barrel_Quark_FSR_counter[i][j][k][l])) < 0.01 &&
		     (Endcap_Quark_Signal_counter[i][j][k][l]/(Endcap_Quark_Background_counter[i][j][k][l]+Endcap_Quark_ISR_counter[i][j][k][l]+Endcap_Quark_FSR_counter[i][j][k][l])) < 0.01){


		    cout << "Barrel_Quark_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Quark_Background_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Quark_Background_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Barrel_Quark_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Quark_ISR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Quark_ISR_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Barrel_Quark_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Quark_FSR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Quark_FSR_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Barrel_Quark_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Quark_Signal_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Quark_Signal_squared_weight[i][j][k][l])*20000 << endl;

		    cout << "Endcap_Quark_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Quark_Background_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Quark_Background_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Endcap_Quark_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Quark_ISR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Quark_ISR_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Endcap_Quark_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Quark_FSR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Quark_FSR_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Endcap_Quark_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Quark_Signal_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Quark_Signal_squared_weight[i][j][k][l])*20000 << endl;


		    float num = Barrel_Quark_Signal_counter[i][j][k][l];
                    float den = Barrel_Quark_Background_counter[i][j][k][l]+Barrel_Quark_ISR_counter[i][j][k][l]+Barrel_Quark_FSR_counter[i][j][k][l];
                    float sum_square_num = Barrel_Quark_Signal_squared_weight[i][j][k][l];
                    float sum_square_den = Barrel_Quark_Background_squared_weight[i][j][k][l]+Barrel_Quark_ISR_squared_weight[i][j][k][l]+Barrel_Quark_FSR_squared_weight[i][j][k][l];
		    float err = ( sqrt(sum_square_num) + sqrt(sum_square_den) * num / den ) / den;
                    cout << "Barrel_Quark_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< Barrel_Quark_Signal_counter[i][j][k][l]/(Barrel_Quark_Background_counter[i][j][k][l]+Barrel_Quark_ISR_counter[i][j][k][l]+Barrel_Quark_FSR_counter[i][j][k][l]) << " +/- " << err << endl;

		    num = Endcap_Quark_Signal_counter[i][j][k][l];
                    den = Endcap_Quark_Background_counter[i][j][k][l]+Endcap_Quark_ISR_counter[i][j][k][l]+Endcap_Quark_FSR_counter[i][j][k][l];
                    sum_square_num = Endcap_Quark_Signal_squared_weight[i][j][k][l];
                    sum_square_den = Endcap_Quark_Background_squared_weight[i][j][k][l]+Endcap_Quark_ISR_squared_weight[i][j][k][l]+Endcap_Quark_FSR_squared_weight[i][j][k][l];
		    err = ( sqrt(sum_square_num) + sqrt(sum_square_den) * num / den ) / den;
                    cout << "Endcap_Quark_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< Endcap_Quark_Signal_counter[i][j][k][l]/(Endcap_Quark_Background_counter[i][j][k][l]+Endcap_Quark_ISR_counter[i][j][k][l]+Endcap_Quark_FSR_counter[i][j][k][l]) << " +/- " << err << endl;
		 }

		 
		 if ((Barrel_Gluon_Background_counter[i][j][k][l]+Barrel_Gluon_ISR_counter[i][j][k][l]+Barrel_Gluon_FSR_counter[i][j][k][l]) > 0 &&
		     (Endcap_Gluon_Background_counter[i][j][k][l]+Endcap_Gluon_ISR_counter[i][j][k][l]+Endcap_Gluon_FSR_counter[i][j][k][l]) > 0 &&
		     (Barrel_Gluon_Signal_counter[i][j][k][l]/(Barrel_Gluon_Background_counter[i][j][k][l]+Barrel_Gluon_ISR_counter[i][j][k][l]+Barrel_Gluon_FSR_counter[i][j][k][l])) < 0.01 &&
		     (Endcap_Gluon_Signal_counter[i][j][k][l]/(Endcap_Gluon_Background_counter[i][j][k][l]+Endcap_Gluon_ISR_counter[i][j][k][l]+Endcap_Gluon_FSR_counter[i][j][k][l])) < 0.01){


		    cout << "Barrel_Gluon_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Gluon_Background_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Gluon_Background_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Barrel_Gluon_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Gluon_ISR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Gluon_ISR_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Barrel_Gluon_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Gluon_FSR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Gluon_FSR_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Barrel_Gluon_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Gluon_Signal_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Gluon_Signal_squared_weight[i][j][k][l])*20000 << endl;

		    cout << "Endcap_Gluon_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Gluon_Background_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Gluon_Background_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Endcap_Gluon_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Gluon_ISR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Gluon_ISR_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Endcap_Gluon_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Gluon_FSR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Gluon_FSR_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Endcap_Gluon_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Gluon_Signal_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Gluon_Signal_squared_weight[i][j][k][l])*20000 << endl;


		    float num = Barrel_Gluon_Signal_counter[i][j][k][l];
                    float den = Barrel_Gluon_Background_counter[i][j][k][l]+Barrel_Gluon_ISR_counter[i][j][k][l]+Barrel_Gluon_FSR_counter[i][j][k][l];
                    float sum_square_num = Barrel_Gluon_Signal_squared_weight[i][j][k][l];
                    float sum_square_den = Barrel_Gluon_Background_squared_weight[i][j][k][l]+Barrel_Gluon_ISR_squared_weight[i][j][k][l]+Barrel_Gluon_FSR_squared_weight[i][j][k][l];
		    float err = ( sqrt(sum_square_num) + sqrt(sum_square_den) * num / den ) / den;
                    cout << "Barrel_Gluon_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< Barrel_Gluon_Signal_counter[i][j][k][l]/(Barrel_Gluon_Background_counter[i][j][k][l]+Barrel_Gluon_ISR_counter[i][j][k][l]+Barrel_Gluon_FSR_counter[i][j][k][l]) << " +/- " << err << endl;

		    num = Endcap_Gluon_Signal_counter[i][j][k][l];
                    den = Endcap_Gluon_Background_counter[i][j][k][l]+Endcap_Gluon_ISR_counter[i][j][k][l]+Endcap_Gluon_FSR_counter[i][j][k][l];
                    sum_square_num = Endcap_Gluon_Signal_squared_weight[i][j][k][l];
                    sum_square_den = Endcap_Gluon_Background_squared_weight[i][j][k][l]+Endcap_Gluon_ISR_squared_weight[i][j][k][l]+Endcap_Gluon_FSR_squared_weight[i][j][k][l];
		    err = ( sqrt(sum_square_num) + sqrt(sum_square_den) * num / den ) / den;
                    cout << "Endcap_Gluon_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< Endcap_Gluon_Signal_counter[i][j][k][l]/(Endcap_Gluon_Background_counter[i][j][k][l]+Endcap_Gluon_ISR_counter[i][j][k][l]+Endcap_Gluon_FSR_counter[i][j][k][l]) << " +/- " << err << endl;


		 }

		 
                 cout << "*********************************************" << endl;
                 cout << "*********************************************" << endl;
                 cout << "*********************************************" << endl;

          

	       }}}}




               cout << "*********************************************" << endl;
               cout << "**************** BEST OF 0.005 **************" << endl;
               cout << "*********************************************" << endl;

               for(int i=0;i<10 ;i++) {
               for(int j=0;j<10 ;j++) {
               for(int k=0;k<10 ;k++) {
               for(int l=0;l<10 ;l++) {




		 if ((Barrel_Quark_Background_counter[i][j][k][l]+Barrel_Quark_ISR_counter[i][j][k][l]+Barrel_Quark_FSR_counter[i][j][k][l]) > 0 &&
		     (Endcap_Quark_Background_counter[i][j][k][l]+Endcap_Quark_ISR_counter[i][j][k][l]+Endcap_Quark_FSR_counter[i][j][k][l]) > 0 &&
		     (Barrel_Quark_Signal_counter[i][j][k][l]/(Barrel_Quark_Background_counter[i][j][k][l]+Barrel_Quark_ISR_counter[i][j][k][l]+Barrel_Quark_FSR_counter[i][j][k][l])) < 0.005 &&
		     (Endcap_Quark_Signal_counter[i][j][k][l]/(Endcap_Quark_Background_counter[i][j][k][l]+Endcap_Quark_ISR_counter[i][j][k][l]+Endcap_Quark_FSR_counter[i][j][k][l])) < 0.005){


		    cout << "Barrel_Quark_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Quark_Background_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Quark_Background_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Barrel_Quark_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Quark_ISR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Quark_ISR_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Barrel_Quark_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Quark_FSR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Quark_FSR_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Barrel_Quark_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Quark_Signal_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Quark_Signal_squared_weight[i][j][k][l])*20000 << endl;

		    cout << "Endcap_Quark_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Quark_Background_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Quark_Background_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Endcap_Quark_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Quark_ISR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Quark_ISR_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Endcap_Quark_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Quark_FSR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Quark_FSR_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Endcap_Quark_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Quark_Signal_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Quark_Signal_squared_weight[i][j][k][l])*20000 << endl;


		    float num = Barrel_Quark_Signal_counter[i][j][k][l];
                    float den = Barrel_Quark_Background_counter[i][j][k][l]+Barrel_Quark_ISR_counter[i][j][k][l]+Barrel_Quark_FSR_counter[i][j][k][l];
                    float sum_square_num = Barrel_Quark_Signal_squared_weight[i][j][k][l];
                    float sum_square_den = Barrel_Quark_Background_squared_weight[i][j][k][l]+Barrel_Quark_ISR_squared_weight[i][j][k][l]+Barrel_Quark_FSR_squared_weight[i][j][k][l];
		    float err = ( sqrt(sum_square_num) + sqrt(sum_square_den) * num / den ) / den;
                    cout << "Barrel_Quark_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< Barrel_Quark_Signal_counter[i][j][k][l]/(Barrel_Quark_Background_counter[i][j][k][l]+Barrel_Quark_ISR_counter[i][j][k][l]+Barrel_Quark_FSR_counter[i][j][k][l]) << " +/- " << err << endl;

		    num = Endcap_Quark_Signal_counter[i][j][k][l];
                    den = Endcap_Quark_Background_counter[i][j][k][l]+Endcap_Quark_ISR_counter[i][j][k][l]+Endcap_Quark_FSR_counter[i][j][k][l];
                    sum_square_num = Endcap_Quark_Signal_squared_weight[i][j][k][l];
                    sum_square_den = Endcap_Quark_Background_squared_weight[i][j][k][l]+Endcap_Quark_ISR_squared_weight[i][j][k][l]+Endcap_Quark_FSR_squared_weight[i][j][k][l];
		    err = ( sqrt(sum_square_num) + sqrt(sum_square_den) * num / den ) / den;
                    cout << "Endcap_Quark_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< Endcap_Quark_Signal_counter[i][j][k][l]/(Endcap_Quark_Background_counter[i][j][k][l]+Endcap_Quark_ISR_counter[i][j][k][l]+Endcap_Quark_FSR_counter[i][j][k][l]) << " +/- " << err << endl;
		 }

		 
		 if ((Barrel_Gluon_Background_counter[i][j][k][l]+Barrel_Gluon_ISR_counter[i][j][k][l]+Barrel_Gluon_FSR_counter[i][j][k][l]) > 0 &&
		     (Endcap_Gluon_Background_counter[i][j][k][l]+Endcap_Gluon_ISR_counter[i][j][k][l]+Endcap_Gluon_FSR_counter[i][j][k][l]) > 0 &&
		     (Barrel_Gluon_Signal_counter[i][j][k][l]/(Barrel_Gluon_Background_counter[i][j][k][l]+Barrel_Gluon_ISR_counter[i][j][k][l]+Barrel_Gluon_FSR_counter[i][j][k][l])) < 0.005 &&
		     (Endcap_Gluon_Signal_counter[i][j][k][l]/(Endcap_Gluon_Background_counter[i][j][k][l]+Endcap_Gluon_ISR_counter[i][j][k][l]+Endcap_Gluon_FSR_counter[i][j][k][l])) < 0.005){


		    cout << "Barrel_Gluon_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Gluon_Background_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Gluon_Background_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Barrel_Gluon_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Gluon_ISR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Gluon_ISR_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Barrel_Gluon_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Gluon_FSR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Gluon_FSR_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Barrel_Gluon_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Gluon_Signal_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Gluon_Signal_squared_weight[i][j][k][l])*20000 << endl;

		    cout << "Endcap_Gluon_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Gluon_Background_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Gluon_Background_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Endcap_Gluon_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Gluon_ISR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Gluon_ISR_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Endcap_Gluon_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Gluon_FSR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Gluon_FSR_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Endcap_Gluon_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Gluon_Signal_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Gluon_Signal_squared_weight[i][j][k][l])*20000 << endl;


		    float num = Barrel_Gluon_Signal_counter[i][j][k][l];
                    float den = Barrel_Gluon_Background_counter[i][j][k][l]+Barrel_Gluon_ISR_counter[i][j][k][l]+Barrel_Gluon_FSR_counter[i][j][k][l];
                    float sum_square_num = Barrel_Gluon_Signal_squared_weight[i][j][k][l];
                    float sum_square_den = Barrel_Gluon_Background_squared_weight[i][j][k][l]+Barrel_Gluon_ISR_squared_weight[i][j][k][l]+Barrel_Gluon_FSR_squared_weight[i][j][k][l];
		    float err = ( sqrt(sum_square_num) + sqrt(sum_square_den) * num / den ) / den;
                    cout << "Barrel_Gluon_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< Barrel_Gluon_Signal_counter[i][j][k][l]/(Barrel_Gluon_Background_counter[i][j][k][l]+Barrel_Gluon_ISR_counter[i][j][k][l]+Barrel_Gluon_FSR_counter[i][j][k][l]) << " +/- " << err << endl;

		    num = Endcap_Gluon_Signal_counter[i][j][k][l];
                    den = Endcap_Gluon_Background_counter[i][j][k][l]+Endcap_Gluon_ISR_counter[i][j][k][l]+Endcap_Gluon_FSR_counter[i][j][k][l];
                    sum_square_num = Endcap_Gluon_Signal_squared_weight[i][j][k][l];
                    sum_square_den = Endcap_Gluon_Background_squared_weight[i][j][k][l]+Endcap_Gluon_ISR_squared_weight[i][j][k][l]+Endcap_Gluon_FSR_squared_weight[i][j][k][l];
		    err = ( sqrt(sum_square_num) + sqrt(sum_square_den) * num / den ) / den;
                    cout << "Endcap_Gluon_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< Endcap_Gluon_Signal_counter[i][j][k][l]/(Endcap_Gluon_Background_counter[i][j][k][l]+Endcap_Gluon_ISR_counter[i][j][k][l]+Endcap_Gluon_FSR_counter[i][j][k][l]) << " +/- " << err << endl;


		 }

		 
                 cout << "*********************************************" << endl;
                 cout << "*********************************************" << endl;
                 cout << "*********************************************" << endl;

          

	       }}}}






               cout << "*********************************************" << endl;
               cout << "**************** BEST OF 0.001 **************" << endl;
               cout << "*********************************************" << endl;

               for(int i=0;i<10 ;i++) {
               for(int j=0;j<10 ;j++) {
               for(int k=0;k<10 ;k++) {
               for(int l=0;l<10 ;l++) {




		 if ((Barrel_Quark_Background_counter[i][j][k][l]+Barrel_Quark_ISR_counter[i][j][k][l]+Barrel_Quark_FSR_counter[i][j][k][l]) > 0 &&
		     (Endcap_Quark_Background_counter[i][j][k][l]+Endcap_Quark_ISR_counter[i][j][k][l]+Endcap_Quark_FSR_counter[i][j][k][l]) > 0 &&
		     (Barrel_Quark_Signal_counter[i][j][k][l]/(Barrel_Quark_Background_counter[i][j][k][l]+Barrel_Quark_ISR_counter[i][j][k][l]+Barrel_Quark_FSR_counter[i][j][k][l])) < 0.001 &&
		     (Endcap_Quark_Signal_counter[i][j][k][l]/(Endcap_Quark_Background_counter[i][j][k][l]+Endcap_Quark_ISR_counter[i][j][k][l]+Endcap_Quark_FSR_counter[i][j][k][l])) < 0.001){


		    cout << "Barrel_Quark_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Quark_Background_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Quark_Background_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Barrel_Quark_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Quark_ISR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Quark_ISR_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Barrel_Quark_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Quark_FSR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Quark_FSR_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Barrel_Quark_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Quark_Signal_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Quark_Signal_squared_weight[i][j][k][l])*20000 << endl;

		    cout << "Endcap_Quark_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Quark_Background_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Quark_Background_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Endcap_Quark_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Quark_ISR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Quark_ISR_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Endcap_Quark_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Quark_FSR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Quark_FSR_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Endcap_Quark_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Quark_Signal_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Quark_Signal_squared_weight[i][j][k][l])*20000 << endl;


		    float num = Barrel_Quark_Signal_counter[i][j][k][l];
                    float den = Barrel_Quark_Background_counter[i][j][k][l]+Barrel_Quark_ISR_counter[i][j][k][l]+Barrel_Quark_FSR_counter[i][j][k][l];
                    float sum_square_num = Barrel_Quark_Signal_squared_weight[i][j][k][l];
                    float sum_square_den = Barrel_Quark_Background_squared_weight[i][j][k][l]+Barrel_Quark_ISR_squared_weight[i][j][k][l]+Barrel_Quark_FSR_squared_weight[i][j][k][l];
		    float err = ( sqrt(sum_square_num) + sqrt(sum_square_den) * num / den ) / den;
                    cout << "Barrel_Quark_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< Barrel_Quark_Signal_counter[i][j][k][l]/(Barrel_Quark_Background_counter[i][j][k][l]+Barrel_Quark_ISR_counter[i][j][k][l]+Barrel_Quark_FSR_counter[i][j][k][l]) << " +/- " << err << endl;

		    num = Endcap_Quark_Signal_counter[i][j][k][l];
                    den = Endcap_Quark_Background_counter[i][j][k][l]+Endcap_Quark_ISR_counter[i][j][k][l]+Endcap_Quark_FSR_counter[i][j][k][l];
                    sum_square_num = Endcap_Quark_Signal_squared_weight[i][j][k][l];
                    sum_square_den = Endcap_Quark_Background_squared_weight[i][j][k][l]+Endcap_Quark_ISR_squared_weight[i][j][k][l]+Endcap_Quark_FSR_squared_weight[i][j][k][l];
		    err = ( sqrt(sum_square_num) + sqrt(sum_square_den) * num / den ) / den;
                    cout << "Endcap_Quark_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< Endcap_Quark_Signal_counter[i][j][k][l]/(Endcap_Quark_Background_counter[i][j][k][l]+Endcap_Quark_ISR_counter[i][j][k][l]+Endcap_Quark_FSR_counter[i][j][k][l]) << " +/- " << err << endl;
		 }

		 if ((Barrel_Gluon_Background_counter[i][j][k][l]+Barrel_Gluon_ISR_counter[i][j][k][l]+Barrel_Gluon_FSR_counter[i][j][k][l]) > 0 &&
		     (Endcap_Gluon_Background_counter[i][j][k][l]+Endcap_Gluon_ISR_counter[i][j][k][l]+Endcap_Gluon_FSR_counter[i][j][k][l]) > 0 &&
		     (Barrel_Gluon_Signal_counter[i][j][k][l]/(Barrel_Gluon_Background_counter[i][j][k][l]+Barrel_Gluon_ISR_counter[i][j][k][l]+Barrel_Gluon_FSR_counter[i][j][k][l])) < 0.001 &&
		     (Endcap_Gluon_Signal_counter[i][j][k][l]/(Endcap_Gluon_Background_counter[i][j][k][l]+Endcap_Gluon_ISR_counter[i][j][k][l]+Endcap_Gluon_FSR_counter[i][j][k][l])) < 0.001){


		    cout << "Barrel_Gluon_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Gluon_Background_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Gluon_Background_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Barrel_Gluon_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Gluon_ISR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Gluon_ISR_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Barrel_Gluon_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Gluon_FSR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Gluon_FSR_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Barrel_Gluon_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Barrel_Gluon_Signal_counter[i][j][k][l]*20000 << " +/- " << sqrt(Barrel_Gluon_Signal_squared_weight[i][j][k][l])*20000 << endl;

		    cout << "Endcap_Gluon_Background["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Gluon_Background_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Gluon_Background_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Endcap_Gluon_ISR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Gluon_ISR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Gluon_ISR_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Endcap_Gluon_FSR["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Gluon_FSR_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Gluon_FSR_squared_weight[i][j][k][l])*20000 << endl;
		    cout << "Endcap_Gluon_Signal["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]=~ "<< Endcap_Gluon_Signal_counter[i][j][k][l]*20000 << " +/- " << sqrt(Endcap_Gluon_Signal_squared_weight[i][j][k][l])*20000 << endl;


		    float num = Barrel_Gluon_Signal_counter[i][j][k][l];
                    float den = Barrel_Gluon_Background_counter[i][j][k][l]+Barrel_Gluon_ISR_counter[i][j][k][l]+Barrel_Gluon_FSR_counter[i][j][k][l];
                    float sum_square_num = Barrel_Gluon_Signal_squared_weight[i][j][k][l];
                    float sum_square_den = Barrel_Gluon_Background_squared_weight[i][j][k][l]+Barrel_Gluon_ISR_squared_weight[i][j][k][l]+Barrel_Gluon_FSR_squared_weight[i][j][k][l];
		    float err = ( sqrt(sum_square_num) + sqrt(sum_square_den) * num / den ) / den;
                    cout << "Barrel_Gluon_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< Barrel_Gluon_Signal_counter[i][j][k][l]/(Barrel_Gluon_Background_counter[i][j][k][l]+Barrel_Gluon_ISR_counter[i][j][k][l]+Barrel_Gluon_FSR_counter[i][j][k][l]) << " +/- " << err << endl;

		    num = Endcap_Gluon_Signal_counter[i][j][k][l];
                    den = Endcap_Gluon_Background_counter[i][j][k][l]+Endcap_Gluon_ISR_counter[i][j][k][l]+Endcap_Gluon_FSR_counter[i][j][k][l];
                    sum_square_num = Endcap_Gluon_Signal_squared_weight[i][j][k][l];
                    sum_square_den = Endcap_Gluon_Background_squared_weight[i][j][k][l]+Endcap_Gluon_ISR_squared_weight[i][j][k][l]+Endcap_Gluon_FSR_squared_weight[i][j][k][l];
		    err = ( sqrt(sum_square_num) + sqrt(sum_square_den) * num / den ) / den;
                    cout << "Endcap_Gluon_Signal/(Background+FSR+ISR)["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]: "<< Endcap_Gluon_Signal_counter[i][j][k][l]/(Endcap_Gluon_Background_counter[i][j][k][l]+Endcap_Gluon_ISR_counter[i][j][k][l]+Endcap_Gluon_FSR_counter[i][j][k][l]) << " +/- " << err << endl;


		 }

		 
                 cout << "*********************************************" << endl;
                 cout << "*********************************************" << endl;
                 cout << "*********************************************" << endl;

          

	       }}}}

	       */







       TFile* file_FO_Optimization_Results = new TFile("FO_Optimization_Results_QCD_80_170.root","RECREATE");
       file_FO_Optimization_Results->cd();


               for(int i=0;i<10 ;i++) {
               for(int j=0;j<10 ;j++) {
               for(int k=0;k<10 ;k++) {
               for(int l=0;l<10 ;l++) {





                 h_Barrel_Quark_Background_counter[i][j][k][l]->Write();
                 h_Endcap_Quark_Background_counter[i][j][k][l]->Write();
                 h_Barrel_Gluon_Background_counter[i][j][k][l]->Write();
                 h_Endcap_Gluon_Background_counter[i][j][k][l]->Write();

                 h_Barrel_Quark_ISR_counter[i][j][k][l]->Write();
                 h_Endcap_Quark_ISR_counter[i][j][k][l]->Write();
                 h_Barrel_Gluon_ISR_counter[i][j][k][l]->Write();
                 h_Endcap_Gluon_ISR_counter[i][j][k][l]->Write();

                 h_Barrel_Quark_FSR_counter[i][j][k][l]->Write();
                 h_Endcap_Quark_FSR_counter[i][j][k][l]->Write();
                 h_Barrel_Gluon_FSR_counter[i][j][k][l]->Write();
                 h_Endcap_Gluon_FSR_counter[i][j][k][l]->Write();

                 h_Barrel_Quark_Signal_counter[i][j][k][l]->Write();
                 h_Endcap_Quark_Signal_counter[i][j][k][l]->Write();
                 h_Barrel_Gluon_Signal_counter[i][j][k][l]->Write();
                 h_Endcap_Gluon_Signal_counter[i][j][k][l]->Write();






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


       //Put loop to save histograms here....


       file_FO_Optimization_Results->Write();
       file_FO_Optimization_Results->Close();
       delete file_FO_Optimization_Results;





}
