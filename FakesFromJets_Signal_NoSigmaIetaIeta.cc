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
#include "interface/RecoPhotonSelectionNoSigmaIetaIeta.h"
#include "interface/RecoJetSelection.h"
//#include "interface/SolutionOfWNeutrino.h"
//#include "Math.h"
#include "interface/ConstantNumbers.h"
#include "TLorentzVector.h"
#include <string>
#include <iostream>
#include <vector>

#include <TFile.h>//Add by Yuhsiang

void FakesFromJets_Signal_NoSigmaIetaIeta()
{
    gROOT->ProcessLine(".L interface/setTDRStyle.C");
    gROOT->ProcessLine("setTDRStyle()");
    gStyle->SetPalette(1);

    TChain * root[28]; 

    for(unsigned int i=0; i<28; i++){
     root[i] = new TChain("bprimeKit/root");
    }

    root[0]->Add("/data3/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_noSigmaIetaIeta_GJets_HT-40To100_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V19-v1.root");
    root[1]->Add("/data3/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_noSigmaIetaIeta_GJets_HT-100To200_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V19-v1.root");
    root[2]->Add("/data3/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_noSigmaIetaIeta_GJets_HT-200To400_8TeV-madgraph_v2_Summer12_DR53X-PU_S10_START53_V7A-v1.root");
    root[3]->Add("/data3/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_noSigmaIetaIeta_GJets_HT-400ToInf_8TeV-madgraph_v3_Summer12_DR53X-PU_S10_START53_V7C-v1.root");
    root[4]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-450_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[5]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-475_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[6]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-500_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[7]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-525_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[8]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-550_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[9]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-575_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[10]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-600_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[11]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-625_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[12]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-650_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[13]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-675_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[14]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-700_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[15]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-725_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[16]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-750_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[17]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-775_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[18]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-800_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root");
    root[19]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-850_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7C-v1/*.root");
    root[20]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-900_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7C-v1/*.root");
    root[21]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-950_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7C-v1/*.root");
    root[22]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-1000_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7C-v1/*.root"); 
    root[23]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-1100_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7C-v1/*.root"); 
    root[24]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-1200_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7C-v1/*.root");
    root[25]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-1300_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7C-v1/*.root");
    root[26]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-1400_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7C-v1/*.root");
    root[27]->Add("/BprimeKitNtuples/Production_CMSSW5311/CMSSW5_3_11_MC_AOD_v3/TprimeTprimeToTgammaTgammainc_M-1500_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7C-v1/*.root");


    //root->Add("/afs/cern.ch/work/c/cardaci/MultiJet_Run2012A-13Jul2012-v1_190456-193686/*");
    //root->Add("/afs/cern.ch/work/y/ymtzeng/public/1photon1lepton_DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball_Summer12_DR53X-PU_S10_START53_V7A-v1.root ");
    //root->Add("/afs/cern.ch/work/c/cardaci/REDUCE_DATA_Summer12_1lepton4jets_id_vtx_recover/1lepton4jets_DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball_Summer12_DR53X-PU_S10_START53_V7A-v1.root");



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


	


       float NVTX_Min = -0.5;
       float NVTX_Max = 30.5;
       int NVTX_N_bins = 31;

       float Inclusive_Min = -0.5;
       float Inclusive_Max = 0.5;
       int Inclusive_N_bins = 1;

       float NJets_Min = -0.5;
       float NJets_Max = 10.5;
       int NJets_N_bins = 11;

       float Eta_Min = -2.4;
       float Eta_Max =  2.4;
       int Eta_N_bins = 20;

       float PT_Min =   30;
       float PT_Max = 1200;
       int PT_N_bins = 100;

       float pT_subranges[6] = {0 ,30, 99, 133, 173, 1200};
       float pT_Gluon_subranges[6] = {0 ,30, 90, 125, 160, 1200};
       float pT_Quark_subranges[6] = {0 ,30, 108, 140, 186, 1200};

       TH1F * Inclusive_QGTagsMLP_Matched_FO = new TH1F ("Inclusive_QGTagsMLP_Matched_FO","Inclusive_QGTagsMLP_Matched_FO", 40000, -2, 2);
       Inclusive_QGTagsMLP_Matched_FO->Sumw2();
       TH1F * Inclusive_QGTagsLikelihood_Matched_FO = new TH1F ("Inclusive_QGTagsLikelihood_Matched_FO","Inclusive_QGTagsLikelihood_Matched_FO", 40000, -2, 2);
       Inclusive_QGTagsLikelihood_Matched_FO->Sumw2();
       TH1F * Inclusive_QGTagsMLP_Matched_TIGHT = new TH1F ("Inclusive_QGTagsMLP_Matched_TIGHT","Inclusive_QGTagsMLP_Matched_TIGHT", 40000, -2, 2);
       Inclusive_QGTagsMLP_Matched_TIGHT->Sumw2();
       TH1F * Inclusive_QGTagsLikelihood_Matched_TIGHT = new TH1F ("Inclusive_QGTagsLikelihood_Matched_TIGHT","Inclusive_QGTagsLikelihood_Matched_TIGHT", 40000, -2, 2);
       Inclusive_QGTagsLikelihood_Matched_TIGHT->Sumw2();


       TH1F * Inclusive_Sigma_Ieta_Ieta_TIGHT_Gluon = new TH1F ("Inclusive_Sigma_Ieta_Ieta_TIGHT_Gluon","Inclusive_Sigma_Ieta_Ieta_TIGHT_Gluon", 20000, -1, 1);//Add by Yuhsiang
       Inclusive_Sigma_Ieta_Ieta_TIGHT_Gluon->Sumw2();
       TH1F * Inclusive_Sigma_Ieta_Ieta_FO_Gluon = new TH1F ("Inclusive_Sigma_Ieta_Ieta_FO_Gluon","Inclusive_Sigma_Ieta_Ieta_FO_Gluon",  20000, -1, 1);//Add by Yuhsiang
       Inclusive_Sigma_Ieta_Ieta_FO_Gluon->Sumw2();
       TH1F * Inclusive_Sigma_Ieta_Ieta_TIGHT_Quark = new TH1F ("Inclusive_Sigma_Ieta_Ieta_TIGHT_Quark","Inclusive_Sigma_Ieta_Ieta_TIGHT_Quark",  20000, -1, 1);//Add by Yuhsiang
       Inclusive_Sigma_Ieta_Ieta_TIGHT_Quark->Sumw2();
       TH1F * Inclusive_Sigma_Ieta_Ieta_FO_Quark = new TH1F ("Inclusive_Sigma_Ieta_Ieta_FO_Quark","Inclusive_Sigma_Ieta_Ieta_FO_Quark",  20000, -1, 1);//Add by Yuhsiang
       Inclusive_Sigma_Ieta_Ieta_FO_Quark->Sumw2();

       TH1F * Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Gluon = new TH1F ("Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Gluon","Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Gluon", 20000, -1, 1);
       Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Gluon->Sumw2();
       TH1F * Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Gluon = new TH1F ("Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Gluon","Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Gluon", 20000, -1, 1);
       Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Gluon->Sumw2();
       TH1F * Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark = new TH1F ("Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark","Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark", 20000, -1, 1);
       Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark->Sumw2();
       TH1F * Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Quark = new TH1F ("Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Quark","Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Quark", 20000, -1, 1);
       Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Quark->Sumw2();

       TH1F * Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Gluon = new TH1F ("Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Gluon","Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Gluon", 20000, -1, 1);
       Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Gluon->Sumw2();
       TH1F * Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Gluon = new TH1F ("Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Gluon","Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Gluon", 20000, -1, 1);
       Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Gluon->Sumw2();
       TH1F * Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Quark = new TH1F ("Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Quark","Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Quark", 20000, -1, 1);
       Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Quark->Sumw2();
       TH1F * Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Quark = new TH1F ("Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Quark","Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Quark", 20000, -1, 1);
       Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Quark->Sumw2();

       TH1F * Inclusive_noNJetsCut_QGTagsMLP_Matched_FO = new TH1F ("Inclusive_noNJetsCut_QGTagsMLP_Matched_FO","Inclusive_noNJetsCut_QGTagsMLP_Matched_FO", 40000, -2, 2);
       Inclusive_noNJetsCut_QGTagsMLP_Matched_FO->Sumw2();
       TH1F * Inclusive_noNJetsCut_QGTagsLikelihood_Matched_FO = new TH1F ("Inclusive_noNJetsCut_QGTagsLikelihood_Matched_FO","Inclusive_noNJetsCut_QGTagsLikelihood_Matched_FO", 40000, -2, 2);
       Inclusive_noNJetsCut_QGTagsLikelihood_Matched_FO->Sumw2();
       TH1F * Inclusive_noNJetsCut_QGTagsMLP_Matched_TIGHT = new TH1F ("Inclusive_noNJetsCut_QGTagsMLP_Matched_TIGHT","Inclusive_noNJetsCut_QGTagsMLP_Matched_TIGHT", 40000, -2, 2);
       Inclusive_noNJetsCut_QGTagsMLP_Matched_TIGHT->Sumw2();
       TH1F * Inclusive_noNJetsCut_QGTagsLikelihood_Matched_TIGHT = new TH1F ("Inclusive_noNJetsCut_QGTagsLikelihood_Matched_TIGHT","Inclusive_noNJetsCut_QGTagsLikelihood_Matched_TIGHT", 40000, -2, 2);
       Inclusive_noNJetsCut_QGTagsLikelihood_Matched_TIGHT->Sumw2();

       TH1F * Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Gluon = new TH1F ("Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Gluon","Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Gluon", 20000, -1, 1);
       Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Gluon->Sumw2();
       TH1F * Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Gluon = new TH1F ("Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Gluon","Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Gluon", 20000, -1, 1);
       Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Gluon->Sumw2();
       TH1F * Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Quark = new TH1F ("Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Quark","Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Quark", 20000, -1, 1);
       Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Quark->Sumw2();
       TH1F * Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Quark = new TH1F ("Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Quark","Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Quark", 20000, -1, 1);
       Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Quark->Sumw2();


       TH1F * h_QGTagsMLP_Matched_FO[5][5];
       TH1F * h_QGTagsMLP_Matched_TIGHT[5][5];
       TH1F * h_Sigma_Ieta_Ieta_TIGHT_Gluon[5][5];
       TH1F * h_Sigma_Ieta_Ieta_TIGHT_Quark[5][5];
       TH1F * h_Sigma_Ieta_Ieta_FO_Gluon[5][5];
       TH1F * h_Sigma_Ieta_Ieta_FO_Quark[5][5];


       h_QGTagsMLP_Matched_FO[0][0] = new TH1F("Eta_0_PT_0_QGTagsMLP_Matched_FO", "Eta_0_PT_0_QGTagsMLP_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_Matched_FO[1][0] = new TH1F("Eta_1_PT_0_QGTagsMLP_Matched_FO", "Eta_1_PT_0_QGTagsMLP_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_Matched_FO[2][0] = new TH1F("Eta_2_PT_0_QGTagsMLP_Matched_FO", "Eta_2_PT_0_QGTagsMLP_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_Matched_FO[3][0] = new TH1F("Eta_3_PT_0_QGTagsMLP_Matched_FO", "Eta_3_PT_0_QGTagsMLP_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_Matched_FO[4][0] = new TH1F("Eta_4_PT_0_QGTagsMLP_Matched_FO", "Eta_4_PT_0_QGTagsMLP_Matched_FO",40000, -2, 2);

       h_QGTagsMLP_Matched_FO[0][1] = new TH1F("Eta_0_PT_1_QGTagsMLP_Matched_FO", "Eta_0_PT_1_QGTagsMLP_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_Matched_FO[1][1] = new TH1F("Eta_1_PT_1_QGTagsMLP_Matched_FO", "Eta_1_PT_1_QGTagsMLP_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_Matched_FO[2][1] = new TH1F("Eta_2_PT_1_QGTagsMLP_Matched_FO", "Eta_2_PT_1_QGTagsMLP_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_Matched_FO[3][1] = new TH1F("Eta_3_PT_1_QGTagsMLP_Matched_FO", "Eta_3_PT_1_QGTagsMLP_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_Matched_FO[4][1] = new TH1F("Eta_4_PT_1_QGTagsMLP_Matched_FO", "Eta_4_PT_1_QGTagsMLP_Matched_FO",40000, -2, 2);

       h_QGTagsMLP_Matched_FO[0][2] = new TH1F("Eta_0_PT_2_QGTagsMLP_Matched_FO", "Eta_0_PT_2_QGTagsMLP_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_Matched_FO[1][2] = new TH1F("Eta_1_PT_2_QGTagsMLP_Matched_FO", "Eta_1_PT_2_QGTagsMLP_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_Matched_FO[2][2] = new TH1F("Eta_2_PT_2_QGTagsMLP_Matched_FO", "Eta_2_PT_2_QGTagsMLP_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_Matched_FO[3][2] = new TH1F("Eta_3_PT_2_QGTagsMLP_Matched_FO", "Eta_3_PT_2_QGTagsMLP_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_Matched_FO[4][2] = new TH1F("Eta_4_PT_2_QGTagsMLP_Matched_FO", "Eta_4_PT_2_QGTagsMLP_Matched_FO",40000, -2, 2);

       h_QGTagsMLP_Matched_FO[0][3] = new TH1F("Eta_0_PT_3_QGTagsMLP_Matched_FO", "Eta_0_PT_3_QGTagsMLP_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_Matched_FO[1][3] = new TH1F("Eta_1_PT_3_QGTagsMLP_Matched_FO", "Eta_1_PT_3_QGTagsMLP_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_Matched_FO[2][3] = new TH1F("Eta_2_PT_3_QGTagsMLP_Matched_FO", "Eta_2_PT_3_QGTagsMLP_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_Matched_FO[3][3] = new TH1F("Eta_3_PT_3_QGTagsMLP_Matched_FO", "Eta_3_PT_3_QGTagsMLP_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_Matched_FO[4][3] = new TH1F("Eta_4_PT_3_QGTagsMLP_Matched_FO", "Eta_4_PT_3_QGTagsMLP_Matched_FO",40000, -2, 2);

       h_QGTagsMLP_Matched_FO[0][4] = new TH1F("Eta_0_PT_4_QGTagsMLP_Matched_FO", "Eta_0_PT_4_QGTagsMLP_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_Matched_FO[1][4] = new TH1F("Eta_1_PT_4_QGTagsMLP_Matched_FO", "Eta_1_PT_4_QGTagsMLP_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_Matched_FO[2][4] = new TH1F("Eta_2_PT_4_QGTagsMLP_Matched_FO", "Eta_2_PT_4_QGTagsMLP_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_Matched_FO[3][4] = new TH1F("Eta_3_PT_4_QGTagsMLP_Matched_FO", "Eta_3_PT_4_QGTagsMLP_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_Matched_FO[4][4] = new TH1F("Eta_4_PT_4_QGTagsMLP_Matched_FO", "Eta_4_PT_4_QGTagsMLP_Matched_FO",40000, -2, 2);



       h_QGTagsMLP_Matched_TIGHT[0][0] = new TH1F("Eta_0_PT_0_QGTagsMLP_Matched_TIGHT", "Eta_0_PT_0_QGTagsMLP_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_Matched_TIGHT[1][0] = new TH1F("Eta_1_PT_0_QGTagsMLP_Matched_TIGHT", "Eta_1_PT_0_QGTagsMLP_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_Matched_TIGHT[2][0] = new TH1F("Eta_2_PT_0_QGTagsMLP_Matched_TIGHT", "Eta_2_PT_0_QGTagsMLP_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_Matched_TIGHT[3][0] = new TH1F("Eta_3_PT_0_QGTagsMLP_Matched_TIGHT", "Eta_3_PT_0_QGTagsMLP_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_Matched_TIGHT[4][0] = new TH1F("Eta_4_PT_0_QGTagsMLP_Matched_TIGHT", "Eta_4_PT_0_QGTagsMLP_Matched_TIGHT",40000, -2, 2);

       h_QGTagsMLP_Matched_TIGHT[0][1] = new TH1F("Eta_0_PT_1_QGTagsMLP_Matched_TIGHT", "Eta_0_PT_1_QGTagsMLP_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_Matched_TIGHT[1][1] = new TH1F("Eta_1_PT_1_QGTagsMLP_Matched_TIGHT", "Eta_1_PT_1_QGTagsMLP_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_Matched_TIGHT[2][1] = new TH1F("Eta_2_PT_1_QGTagsMLP_Matched_TIGHT", "Eta_2_PT_1_QGTagsMLP_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_Matched_TIGHT[3][1] = new TH1F("Eta_3_PT_1_QGTagsMLP_Matched_TIGHT", "Eta_3_PT_1_QGTagsMLP_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_Matched_TIGHT[4][1] = new TH1F("Eta_4_PT_1_QGTagsMLP_Matched_TIGHT", "Eta_4_PT_1_QGTagsMLP_Matched_TIGHT",40000, -2, 2);

       h_QGTagsMLP_Matched_TIGHT[0][2] = new TH1F("Eta_0_PT_2_QGTagsMLP_Matched_TIGHT", "Eta_0_PT_2_QGTagsMLP_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_Matched_TIGHT[1][2] = new TH1F("Eta_1_PT_2_QGTagsMLP_Matched_TIGHT", "Eta_1_PT_2_QGTagsMLP_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_Matched_TIGHT[2][2] = new TH1F("Eta_2_PT_2_QGTagsMLP_Matched_TIGHT", "Eta_2_PT_2_QGTagsMLP_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_Matched_TIGHT[3][2] = new TH1F("Eta_3_PT_2_QGTagsMLP_Matched_TIGHT", "Eta_3_PT_2_QGTagsMLP_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_Matched_TIGHT[4][2] = new TH1F("Eta_4_PT_2_QGTagsMLP_Matched_TIGHT", "Eta_4_PT_2_QGTagsMLP_Matched_TIGHT",40000, -2, 2);

       h_QGTagsMLP_Matched_TIGHT[0][3] = new TH1F("Eta_0_PT_3_QGTagsMLP_Matched_TIGHT", "Eta_0_PT_3_QGTagsMLP_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_Matched_TIGHT[1][3] = new TH1F("Eta_1_PT_3_QGTagsMLP_Matched_TIGHT", "Eta_1_PT_3_QGTagsMLP_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_Matched_TIGHT[2][3] = new TH1F("Eta_2_PT_3_QGTagsMLP_Matched_TIGHT", "Eta_2_PT_3_QGTagsMLP_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_Matched_TIGHT[3][3] = new TH1F("Eta_3_PT_3_QGTagsMLP_Matched_TIGHT", "Eta_3_PT_3_QGTagsMLP_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_Matched_TIGHT[4][3] = new TH1F("Eta_4_PT_3_QGTagsMLP_Matched_TIGHT", "Eta_4_PT_3_QGTagsMLP_Matched_TIGHT",40000, -2, 2);

       h_QGTagsMLP_Matched_TIGHT[0][4] = new TH1F("Eta_0_PT_4_QGTagsMLP_Matched_TIGHT", "Eta_0_PT_4_QGTagsMLP_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_Matched_TIGHT[1][4] = new TH1F("Eta_1_PT_4_QGTagsMLP_Matched_TIGHT", "Eta_1_PT_4_QGTagsMLP_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_Matched_TIGHT[2][4] = new TH1F("Eta_2_PT_4_QGTagsMLP_Matched_TIGHT", "Eta_2_PT_4_QGTagsMLP_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_Matched_TIGHT[3][4] = new TH1F("Eta_3_PT_4_QGTagsMLP_Matched_TIGHT", "Eta_3_PT_4_QGTagsMLP_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_Matched_TIGHT[4][4] = new TH1F("Eta_4_PT_4_QGTagsMLP_Matched_TIGHT", "Eta_4_PT_4_QGTagsMLP_Matched_TIGHT",40000, -2, 2);



       h_Sigma_Ieta_Ieta_TIGHT_Gluon[0][0] = new TH1F("Eta_0_PT_0_Sigma_Ieta_Ieta_TIGHT_Gluon", "Eta_0_PT_0_Sigma_Ieta_Ieta_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Gluon[1][0] = new TH1F("Eta_1_PT_0_Sigma_Ieta_Ieta_TIGHT_Gluon", "Eta_1_PT_0_Sigma_Ieta_Ieta_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Gluon[2][0] = new TH1F("Eta_2_PT_0_Sigma_Ieta_Ieta_TIGHT_Gluon", "Eta_2_PT_0_Sigma_Ieta_Ieta_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Gluon[3][0] = new TH1F("Eta_3_PT_0_Sigma_Ieta_Ieta_TIGHT_Gluon", "Eta_3_PT_0_Sigma_Ieta_Ieta_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Gluon[4][0] = new TH1F("Eta_4_PT_0_Sigma_Ieta_Ieta_TIGHT_Gluon", "Eta_4_PT_0_Sigma_Ieta_Ieta_TIGHT_Gluon",20000, -1, 1);

       h_Sigma_Ieta_Ieta_TIGHT_Gluon[0][1] = new TH1F("Eta_0_PT_1_Sigma_Ieta_Ieta_TIGHT_Gluon", "Eta_0_PT_1_Sigma_Ieta_Ieta_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Gluon[1][1] = new TH1F("Eta_1_PT_1_Sigma_Ieta_Ieta_TIGHT_Gluon", "Eta_1_PT_1_Sigma_Ieta_Ieta_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Gluon[2][1] = new TH1F("Eta_2_PT_1_Sigma_Ieta_Ieta_TIGHT_Gluon", "Eta_2_PT_1_Sigma_Ieta_Ieta_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Gluon[3][1] = new TH1F("Eta_3_PT_1_Sigma_Ieta_Ieta_TIGHT_Gluon", "Eta_3_PT_1_Sigma_Ieta_Ieta_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Gluon[4][1] = new TH1F("Eta_4_PT_1_Sigma_Ieta_Ieta_TIGHT_Gluon", "Eta_4_PT_1_Sigma_Ieta_Ieta_TIGHT_Gluon",20000, -1, 1);

       h_Sigma_Ieta_Ieta_TIGHT_Gluon[0][2] = new TH1F("Eta_0_PT_2_Sigma_Ieta_Ieta_TIGHT_Gluon", "Eta_0_PT_2_Sigma_Ieta_Ieta_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Gluon[1][2] = new TH1F("Eta_1_PT_2_Sigma_Ieta_Ieta_TIGHT_Gluon", "Eta_1_PT_2_Sigma_Ieta_Ieta_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Gluon[2][2] = new TH1F("Eta_2_PT_2_Sigma_Ieta_Ieta_TIGHT_Gluon", "Eta_2_PT_2_Sigma_Ieta_Ieta_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Gluon[3][2] = new TH1F("Eta_3_PT_2_Sigma_Ieta_Ieta_TIGHT_Gluon", "Eta_3_PT_2_Sigma_Ieta_Ieta_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Gluon[4][2] = new TH1F("Eta_4_PT_2_Sigma_Ieta_Ieta_TIGHT_Gluon", "Eta_4_PT_2_Sigma_Ieta_Ieta_TIGHT_Gluon",20000, -1, 1);

       h_Sigma_Ieta_Ieta_TIGHT_Gluon[0][3] = new TH1F("Eta_0_PT_3_Sigma_Ieta_Ieta_TIGHT_Gluon", "Eta_0_PT_3_Sigma_Ieta_Ieta_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Gluon[1][3] = new TH1F("Eta_1_PT_3_Sigma_Ieta_Ieta_TIGHT_Gluon", "Eta_1_PT_3_Sigma_Ieta_Ieta_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Gluon[2][3] = new TH1F("Eta_2_PT_3_Sigma_Ieta_Ieta_TIGHT_Gluon", "Eta_2_PT_3_Sigma_Ieta_Ieta_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Gluon[3][3] = new TH1F("Eta_3_PT_3_Sigma_Ieta_Ieta_TIGHT_Gluon", "Eta_3_PT_3_Sigma_Ieta_Ieta_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Gluon[4][3] = new TH1F("Eta_4_PT_3_Sigma_Ieta_Ieta_TIGHT_Gluon", "Eta_4_PT_3_Sigma_Ieta_Ieta_TIGHT_Gluon",20000, -1, 1);

       h_Sigma_Ieta_Ieta_TIGHT_Gluon[0][4] = new TH1F("Eta_0_PT_4_Sigma_Ieta_Ieta_TIGHT_Gluon", "Eta_0_PT_4_Sigma_Ieta_Ieta_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Gluon[1][4] = new TH1F("Eta_1_PT_4_Sigma_Ieta_Ieta_TIGHT_Gluon", "Eta_1_PT_4_Sigma_Ieta_Ieta_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Gluon[2][4] = new TH1F("Eta_2_PT_4_Sigma_Ieta_Ieta_TIGHT_Gluon", "Eta_2_PT_4_Sigma_Ieta_Ieta_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Gluon[3][4] = new TH1F("Eta_3_PT_4_Sigma_Ieta_Ieta_TIGHT_Gluon", "Eta_3_PT_4_Sigma_Ieta_Ieta_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Gluon[4][4] = new TH1F("Eta_4_PT_4_Sigma_Ieta_Ieta_TIGHT_Gluon", "Eta_4_PT_4_Sigma_Ieta_Ieta_TIGHT_Gluon",20000, -1, 1);



       h_Sigma_Ieta_Ieta_TIGHT_Quark[0][0] = new TH1F("Eta_0_PT_0_Sigma_Ieta_Ieta_TIGHT_Quark", "Eta_0_PT_0_Sigma_Ieta_Ieta_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Quark[1][0] = new TH1F("Eta_1_PT_0_Sigma_Ieta_Ieta_TIGHT_Quark", "Eta_1_PT_0_Sigma_Ieta_Ieta_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Quark[2][0] = new TH1F("Eta_2_PT_0_Sigma_Ieta_Ieta_TIGHT_Quark", "Eta_2_PT_0_Sigma_Ieta_Ieta_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Quark[3][0] = new TH1F("Eta_3_PT_0_Sigma_Ieta_Ieta_TIGHT_Quark", "Eta_3_PT_0_Sigma_Ieta_Ieta_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Quark[4][0] = new TH1F("Eta_4_PT_0_Sigma_Ieta_Ieta_TIGHT_Quark", "Eta_4_PT_0_Sigma_Ieta_Ieta_TIGHT_Quark",20000, -1, 1);

       h_Sigma_Ieta_Ieta_TIGHT_Quark[0][1] = new TH1F("Eta_0_PT_1_Sigma_Ieta_Ieta_TIGHT_Quark", "Eta_0_PT_1_Sigma_Ieta_Ieta_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Quark[1][1] = new TH1F("Eta_1_PT_1_Sigma_Ieta_Ieta_TIGHT_Quark", "Eta_1_PT_1_Sigma_Ieta_Ieta_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Quark[2][1] = new TH1F("Eta_2_PT_1_Sigma_Ieta_Ieta_TIGHT_Quark", "Eta_2_PT_1_Sigma_Ieta_Ieta_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Quark[3][1] = new TH1F("Eta_3_PT_1_Sigma_Ieta_Ieta_TIGHT_Quark", "Eta_3_PT_1_Sigma_Ieta_Ieta_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Quark[4][1] = new TH1F("Eta_4_PT_1_Sigma_Ieta_Ieta_TIGHT_Quark", "Eta_4_PT_1_Sigma_Ieta_Ieta_TIGHT_Quark",20000, -1, 1);

       h_Sigma_Ieta_Ieta_TIGHT_Quark[0][2] = new TH1F("Eta_0_PT_2_Sigma_Ieta_Ieta_TIGHT_Quark", "Eta_0_PT_2_Sigma_Ieta_Ieta_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Quark[1][2] = new TH1F("Eta_1_PT_2_Sigma_Ieta_Ieta_TIGHT_Quark", "Eta_1_PT_2_Sigma_Ieta_Ieta_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Quark[2][2] = new TH1F("Eta_2_PT_2_Sigma_Ieta_Ieta_TIGHT_Quark", "Eta_2_PT_2_Sigma_Ieta_Ieta_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Quark[3][2] = new TH1F("Eta_3_PT_2_Sigma_Ieta_Ieta_TIGHT_Quark", "Eta_3_PT_2_Sigma_Ieta_Ieta_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Quark[4][2] = new TH1F("Eta_4_PT_2_Sigma_Ieta_Ieta_TIGHT_Quark", "Eta_4_PT_2_Sigma_Ieta_Ieta_TIGHT_Quark",20000, -1, 1);

       h_Sigma_Ieta_Ieta_TIGHT_Quark[0][3] = new TH1F("Eta_0_PT_3_Sigma_Ieta_Ieta_TIGHT_Quark", "Eta_0_PT_3_Sigma_Ieta_Ieta_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Quark[1][3] = new TH1F("Eta_1_PT_3_Sigma_Ieta_Ieta_TIGHT_Quark", "Eta_1_PT_3_Sigma_Ieta_Ieta_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Quark[2][3] = new TH1F("Eta_2_PT_3_Sigma_Ieta_Ieta_TIGHT_Quark", "Eta_2_PT_3_Sigma_Ieta_Ieta_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Quark[3][3] = new TH1F("Eta_3_PT_3_Sigma_Ieta_Ieta_TIGHT_Quark", "Eta_3_PT_3_Sigma_Ieta_Ieta_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Quark[4][3] = new TH1F("Eta_4_PT_3_Sigma_Ieta_Ieta_TIGHT_Quark", "Eta_4_PT_3_Sigma_Ieta_Ieta_TIGHT_Quark",20000, -1, 1);

       h_Sigma_Ieta_Ieta_TIGHT_Quark[0][4] = new TH1F("Eta_0_PT_4_Sigma_Ieta_Ieta_TIGHT_Quark", "Eta_0_PT_4_Sigma_Ieta_Ieta_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Quark[1][4] = new TH1F("Eta_1_PT_4_Sigma_Ieta_Ieta_TIGHT_Quark", "Eta_1_PT_4_Sigma_Ieta_Ieta_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Quark[2][4] = new TH1F("Eta_2_PT_4_Sigma_Ieta_Ieta_TIGHT_Quark", "Eta_2_PT_4_Sigma_Ieta_Ieta_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Quark[3][4] = new TH1F("Eta_3_PT_4_Sigma_Ieta_Ieta_TIGHT_Quark", "Eta_3_PT_4_Sigma_Ieta_Ieta_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_TIGHT_Quark[4][4] = new TH1F("Eta_4_PT_4_Sigma_Ieta_Ieta_TIGHT_Quark", "Eta_4_PT_4_Sigma_Ieta_Ieta_TIGHT_Quark",20000, -1, 1);






       h_Sigma_Ieta_Ieta_FO_Gluon[0][0] = new TH1F("Eta_0_PT_0_Sigma_Ieta_Ieta_FO_Gluon", "Eta_0_PT_0_Sigma_Ieta_Ieta_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Gluon[1][0] = new TH1F("Eta_1_PT_0_Sigma_Ieta_Ieta_FO_Gluon", "Eta_1_PT_0_Sigma_Ieta_Ieta_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Gluon[2][0] = new TH1F("Eta_2_PT_0_Sigma_Ieta_Ieta_FO_Gluon", "Eta_2_PT_0_Sigma_Ieta_Ieta_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Gluon[3][0] = new TH1F("Eta_3_PT_0_Sigma_Ieta_Ieta_FO_Gluon", "Eta_3_PT_0_Sigma_Ieta_Ieta_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Gluon[4][0] = new TH1F("Eta_4_PT_0_Sigma_Ieta_Ieta_FO_Gluon", "Eta_4_PT_0_Sigma_Ieta_Ieta_FO_Gluon",20000, -1, 1);

       h_Sigma_Ieta_Ieta_FO_Gluon[0][1] = new TH1F("Eta_0_PT_1_Sigma_Ieta_Ieta_FO_Gluon", "Eta_0_PT_1_Sigma_Ieta_Ieta_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Gluon[1][1] = new TH1F("Eta_1_PT_1_Sigma_Ieta_Ieta_FO_Gluon", "Eta_1_PT_1_Sigma_Ieta_Ieta_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Gluon[2][1] = new TH1F("Eta_2_PT_1_Sigma_Ieta_Ieta_FO_Gluon", "Eta_2_PT_1_Sigma_Ieta_Ieta_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Gluon[3][1] = new TH1F("Eta_3_PT_1_Sigma_Ieta_Ieta_FO_Gluon", "Eta_3_PT_1_Sigma_Ieta_Ieta_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Gluon[4][1] = new TH1F("Eta_4_PT_1_Sigma_Ieta_Ieta_FO_Gluon", "Eta_4_PT_1_Sigma_Ieta_Ieta_FO_Gluon",20000, -1, 1);

       h_Sigma_Ieta_Ieta_FO_Gluon[0][2] = new TH1F("Eta_0_PT_2_Sigma_Ieta_Ieta_FO_Gluon", "Eta_0_PT_2_Sigma_Ieta_Ieta_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Gluon[1][2] = new TH1F("Eta_1_PT_2_Sigma_Ieta_Ieta_FO_Gluon", "Eta_1_PT_2_Sigma_Ieta_Ieta_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Gluon[2][2] = new TH1F("Eta_2_PT_2_Sigma_Ieta_Ieta_FO_Gluon", "Eta_2_PT_2_Sigma_Ieta_Ieta_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Gluon[3][2] = new TH1F("Eta_3_PT_2_Sigma_Ieta_Ieta_FO_Gluon", "Eta_3_PT_2_Sigma_Ieta_Ieta_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Gluon[4][2] = new TH1F("Eta_4_PT_2_Sigma_Ieta_Ieta_FO_Gluon", "Eta_4_PT_2_Sigma_Ieta_Ieta_FO_Gluon",20000, -1, 1);

       h_Sigma_Ieta_Ieta_FO_Gluon[0][3] = new TH1F("Eta_0_PT_3_Sigma_Ieta_Ieta_FO_Gluon", "Eta_0_PT_3_Sigma_Ieta_Ieta_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Gluon[1][3] = new TH1F("Eta_1_PT_3_Sigma_Ieta_Ieta_FO_Gluon", "Eta_1_PT_3_Sigma_Ieta_Ieta_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Gluon[2][3] = new TH1F("Eta_2_PT_3_Sigma_Ieta_Ieta_FO_Gluon", "Eta_2_PT_3_Sigma_Ieta_Ieta_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Gluon[3][3] = new TH1F("Eta_3_PT_3_Sigma_Ieta_Ieta_FO_Gluon", "Eta_3_PT_3_Sigma_Ieta_Ieta_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Gluon[4][3] = new TH1F("Eta_4_PT_3_Sigma_Ieta_Ieta_FO_Gluon", "Eta_4_PT_3_Sigma_Ieta_Ieta_FO_Gluon",20000, -1, 1);

       h_Sigma_Ieta_Ieta_FO_Gluon[0][4] = new TH1F("Eta_0_PT_4_Sigma_Ieta_Ieta_FO_Gluon", "Eta_0_PT_4_Sigma_Ieta_Ieta_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Gluon[1][4] = new TH1F("Eta_1_PT_4_Sigma_Ieta_Ieta_FO_Gluon", "Eta_1_PT_4_Sigma_Ieta_Ieta_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Gluon[2][4] = new TH1F("Eta_2_PT_4_Sigma_Ieta_Ieta_FO_Gluon", "Eta_2_PT_4_Sigma_Ieta_Ieta_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Gluon[3][4] = new TH1F("Eta_3_PT_4_Sigma_Ieta_Ieta_FO_Gluon", "Eta_3_PT_4_Sigma_Ieta_Ieta_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Gluon[4][4] = new TH1F("Eta_4_PT_4_Sigma_Ieta_Ieta_FO_Gluon", "Eta_4_PT_4_Sigma_Ieta_Ieta_FO_Gluon",20000, -1, 1);



       h_Sigma_Ieta_Ieta_FO_Quark[0][0] = new TH1F("Eta_0_PT_0_Sigma_Ieta_Ieta_FO_Quark", "Eta_0_PT_0_Sigma_Ieta_Ieta_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Quark[1][0] = new TH1F("Eta_1_PT_0_Sigma_Ieta_Ieta_FO_Quark", "Eta_1_PT_0_Sigma_Ieta_Ieta_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Quark[2][0] = new TH1F("Eta_2_PT_0_Sigma_Ieta_Ieta_FO_Quark", "Eta_2_PT_0_Sigma_Ieta_Ieta_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Quark[3][0] = new TH1F("Eta_3_PT_0_Sigma_Ieta_Ieta_FO_Quark", "Eta_3_PT_0_Sigma_Ieta_Ieta_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Quark[4][0] = new TH1F("Eta_4_PT_0_Sigma_Ieta_Ieta_FO_Quark", "Eta_4_PT_0_Sigma_Ieta_Ieta_FO_Quark",20000, -1, 1);

       h_Sigma_Ieta_Ieta_FO_Quark[0][1] = new TH1F("Eta_0_PT_1_Sigma_Ieta_Ieta_FO_Quark", "Eta_0_PT_1_Sigma_Ieta_Ieta_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Quark[1][1] = new TH1F("Eta_1_PT_1_Sigma_Ieta_Ieta_FO_Quark", "Eta_1_PT_1_Sigma_Ieta_Ieta_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Quark[2][1] = new TH1F("Eta_2_PT_1_Sigma_Ieta_Ieta_FO_Quark", "Eta_2_PT_1_Sigma_Ieta_Ieta_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Quark[3][1] = new TH1F("Eta_3_PT_1_Sigma_Ieta_Ieta_FO_Quark", "Eta_3_PT_1_Sigma_Ieta_Ieta_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Quark[4][1] = new TH1F("Eta_4_PT_1_Sigma_Ieta_Ieta_FO_Quark", "Eta_4_PT_1_Sigma_Ieta_Ieta_FO_Quark",20000, -1, 1);

       h_Sigma_Ieta_Ieta_FO_Quark[0][2] = new TH1F("Eta_0_PT_2_Sigma_Ieta_Ieta_FO_Quark", "Eta_0_PT_2_Sigma_Ieta_Ieta_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Quark[1][2] = new TH1F("Eta_1_PT_2_Sigma_Ieta_Ieta_FO_Quark", "Eta_1_PT_2_Sigma_Ieta_Ieta_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Quark[2][2] = new TH1F("Eta_2_PT_2_Sigma_Ieta_Ieta_FO_Quark", "Eta_2_PT_2_Sigma_Ieta_Ieta_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Quark[3][2] = new TH1F("Eta_3_PT_2_Sigma_Ieta_Ieta_FO_Quark", "Eta_3_PT_2_Sigma_Ieta_Ieta_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Quark[4][2] = new TH1F("Eta_4_PT_2_Sigma_Ieta_Ieta_FO_Quark", "Eta_4_PT_2_Sigma_Ieta_Ieta_FO_Quark",20000, -1, 1);

       h_Sigma_Ieta_Ieta_FO_Quark[0][3] = new TH1F("Eta_0_PT_3_Sigma_Ieta_Ieta_FO_Quark", "Eta_0_PT_3_Sigma_Ieta_Ieta_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Quark[1][3] = new TH1F("Eta_1_PT_3_Sigma_Ieta_Ieta_FO_Quark", "Eta_1_PT_3_Sigma_Ieta_Ieta_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Quark[2][3] = new TH1F("Eta_2_PT_3_Sigma_Ieta_Ieta_FO_Quark", "Eta_2_PT_3_Sigma_Ieta_Ieta_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Quark[3][3] = new TH1F("Eta_3_PT_3_Sigma_Ieta_Ieta_FO_Quark", "Eta_3_PT_3_Sigma_Ieta_Ieta_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Quark[4][3] = new TH1F("Eta_4_PT_3_Sigma_Ieta_Ieta_FO_Quark", "Eta_4_PT_3_Sigma_Ieta_Ieta_FO_Quark",20000, -1, 1);

       h_Sigma_Ieta_Ieta_FO_Quark[0][4] = new TH1F("Eta_0_PT_4_Sigma_Ieta_Ieta_FO_Quark", "Eta_0_PT_4_Sigma_Ieta_Ieta_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Quark[1][4] = new TH1F("Eta_1_PT_4_Sigma_Ieta_Ieta_FO_Quark", "Eta_1_PT_4_Sigma_Ieta_Ieta_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Quark[2][4] = new TH1F("Eta_2_PT_4_Sigma_Ieta_Ieta_FO_Quark", "Eta_2_PT_4_Sigma_Ieta_Ieta_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Quark[3][4] = new TH1F("Eta_3_PT_4_Sigma_Ieta_Ieta_FO_Quark", "Eta_3_PT_4_Sigma_Ieta_Ieta_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_FO_Quark[4][4] = new TH1F("Eta_4_PT_4_Sigma_Ieta_Ieta_FO_Quark", "Eta_4_PT_4_Sigma_Ieta_Ieta_FO_Quark",20000, -1, 1);




       TH1F * h_QGTagsMLP_noNJetsCut_Matched_FO[5][5];
       TH1F * h_QGTagsMLP_noNJetsCut_Matched_TIGHT[5][5];
       TH1F * h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[5][5];
       TH1F * h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[5][5];
       TH1F * h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[5][5];
       TH1F * h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[5][5];


       h_QGTagsMLP_noNJetsCut_Matched_FO[0][0] = new TH1F("Eta_0_PT_0_QGTagsMLP_noNJetsCut_Matched_FO", "Eta_0_PT_0_QGTagsMLP_noNJetsCut_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_FO[1][0] = new TH1F("Eta_1_PT_0_QGTagsMLP_noNJetsCut_Matched_FO", "Eta_1_PT_0_QGTagsMLP_noNJetsCut_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_FO[2][0] = new TH1F("Eta_2_PT_0_QGTagsMLP_noNJetsCut_Matched_FO", "Eta_2_PT_0_QGTagsMLP_noNJetsCut_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_FO[3][0] = new TH1F("Eta_3_PT_0_QGTagsMLP_noNJetsCut_Matched_FO", "Eta_3_PT_0_QGTagsMLP_noNJetsCut_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_FO[4][0] = new TH1F("Eta_4_PT_0_QGTagsMLP_noNJetsCut_Matched_FO", "Eta_4_PT_0_QGTagsMLP_noNJetsCut_Matched_FO",40000, -2, 2);

       h_QGTagsMLP_noNJetsCut_Matched_FO[0][1] = new TH1F("Eta_0_PT_1_QGTagsMLP_noNJetsCut_Matched_FO", "Eta_0_PT_1_QGTagsMLP_noNJetsCut_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_FO[1][1] = new TH1F("Eta_1_PT_1_QGTagsMLP_noNJetsCut_Matched_FO", "Eta_1_PT_1_QGTagsMLP_noNJetsCut_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_FO[2][1] = new TH1F("Eta_2_PT_1_QGTagsMLP_noNJetsCut_Matched_FO", "Eta_2_PT_1_QGTagsMLP_noNJetsCut_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_FO[3][1] = new TH1F("Eta_3_PT_1_QGTagsMLP_noNJetsCut_Matched_FO", "Eta_3_PT_1_QGTagsMLP_noNJetsCut_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_FO[4][1] = new TH1F("Eta_4_PT_1_QGTagsMLP_noNJetsCut_Matched_FO", "Eta_4_PT_1_QGTagsMLP_noNJetsCut_Matched_FO",40000, -2, 2);

       h_QGTagsMLP_noNJetsCut_Matched_FO[0][2] = new TH1F("Eta_0_PT_2_QGTagsMLP_noNJetsCut_Matched_FO", "Eta_0_PT_2_QGTagsMLP_noNJetsCut_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_FO[1][2] = new TH1F("Eta_1_PT_2_QGTagsMLP_noNJetsCut_Matched_FO", "Eta_1_PT_2_QGTagsMLP_noNJetsCut_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_FO[2][2] = new TH1F("Eta_2_PT_2_QGTagsMLP_noNJetsCut_Matched_FO", "Eta_2_PT_2_QGTagsMLP_noNJetsCut_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_FO[3][2] = new TH1F("Eta_3_PT_2_QGTagsMLP_noNJetsCut_Matched_FO", "Eta_3_PT_2_QGTagsMLP_noNJetsCut_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_FO[4][2] = new TH1F("Eta_4_PT_2_QGTagsMLP_noNJetsCut_Matched_FO", "Eta_4_PT_2_QGTagsMLP_noNJetsCut_Matched_FO",40000, -2, 2);

       h_QGTagsMLP_noNJetsCut_Matched_FO[0][3] = new TH1F("Eta_0_PT_3_QGTagsMLP_noNJetsCut_Matched_FO", "Eta_0_PT_3_QGTagsMLP_noNJetsCut_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_FO[1][3] = new TH1F("Eta_1_PT_3_QGTagsMLP_noNJetsCut_Matched_FO", "Eta_1_PT_3_QGTagsMLP_noNJetsCut_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_FO[2][3] = new TH1F("Eta_2_PT_3_QGTagsMLP_noNJetsCut_Matched_FO", "Eta_2_PT_3_QGTagsMLP_noNJetsCut_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_FO[3][3] = new TH1F("Eta_3_PT_3_QGTagsMLP_noNJetsCut_Matched_FO", "Eta_3_PT_3_QGTagsMLP_noNJetsCut_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_FO[4][3] = new TH1F("Eta_4_PT_3_QGTagsMLP_noNJetsCut_Matched_FO", "Eta_4_PT_3_QGTagsMLP_noNJetsCut_Matched_FO",40000, -2, 2);

       h_QGTagsMLP_noNJetsCut_Matched_FO[0][4] = new TH1F("Eta_0_PT_4_QGTagsMLP_noNJetsCut_Matched_FO", "Eta_0_PT_4_QGTagsMLP_noNJetsCut_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_FO[1][4] = new TH1F("Eta_1_PT_4_QGTagsMLP_noNJetsCut_Matched_FO", "Eta_1_PT_4_QGTagsMLP_noNJetsCut_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_FO[2][4] = new TH1F("Eta_2_PT_4_QGTagsMLP_noNJetsCut_Matched_FO", "Eta_2_PT_4_QGTagsMLP_noNJetsCut_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_FO[3][4] = new TH1F("Eta_3_PT_4_QGTagsMLP_noNJetsCut_Matched_FO", "Eta_3_PT_4_QGTagsMLP_noNJetsCut_Matched_FO",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_FO[4][4] = new TH1F("Eta_4_PT_4_QGTagsMLP_noNJetsCut_Matched_FO", "Eta_4_PT_4_QGTagsMLP_noNJetsCut_Matched_FO",40000, -2, 2);



       h_QGTagsMLP_noNJetsCut_Matched_TIGHT[0][0] = new TH1F("Eta_0_PT_0_QGTagsMLP_noNJetsCut_Matched_TIGHT", "Eta_0_PT_0_QGTagsMLP_noNJetsCut_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_TIGHT[1][0] = new TH1F("Eta_1_PT_0_QGTagsMLP_noNJetsCut_Matched_TIGHT", "Eta_1_PT_0_QGTagsMLP_noNJetsCut_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_TIGHT[2][0] = new TH1F("Eta_2_PT_0_QGTagsMLP_noNJetsCut_Matched_TIGHT", "Eta_2_PT_0_QGTagsMLP_noNJetsCut_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_TIGHT[3][0] = new TH1F("Eta_3_PT_0_QGTagsMLP_noNJetsCut_Matched_TIGHT", "Eta_3_PT_0_QGTagsMLP_noNJetsCut_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_TIGHT[4][0] = new TH1F("Eta_4_PT_0_QGTagsMLP_noNJetsCut_Matched_TIGHT", "Eta_4_PT_0_QGTagsMLP_noNJetsCut_Matched_TIGHT",40000, -2, 2);

       h_QGTagsMLP_noNJetsCut_Matched_TIGHT[0][1] = new TH1F("Eta_0_PT_1_QGTagsMLP_noNJetsCut_Matched_TIGHT", "Eta_0_PT_1_QGTagsMLP_noNJetsCut_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_TIGHT[1][1] = new TH1F("Eta_1_PT_1_QGTagsMLP_noNJetsCut_Matched_TIGHT", "Eta_1_PT_1_QGTagsMLP_noNJetsCut_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_TIGHT[2][1] = new TH1F("Eta_2_PT_1_QGTagsMLP_noNJetsCut_Matched_TIGHT", "Eta_2_PT_1_QGTagsMLP_noNJetsCut_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_TIGHT[3][1] = new TH1F("Eta_3_PT_1_QGTagsMLP_noNJetsCut_Matched_TIGHT", "Eta_3_PT_1_QGTagsMLP_noNJetsCut_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_TIGHT[4][1] = new TH1F("Eta_4_PT_1_QGTagsMLP_noNJetsCut_Matched_TIGHT", "Eta_4_PT_1_QGTagsMLP_noNJetsCut_Matched_TIGHT",40000, -2, 2);

       h_QGTagsMLP_noNJetsCut_Matched_TIGHT[0][2] = new TH1F("Eta_0_PT_2_QGTagsMLP_noNJetsCut_Matched_TIGHT", "Eta_0_PT_2_QGTagsMLP_noNJetsCut_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_TIGHT[1][2] = new TH1F("Eta_1_PT_2_QGTagsMLP_noNJetsCut_Matched_TIGHT", "Eta_1_PT_2_QGTagsMLP_noNJetsCut_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_TIGHT[2][2] = new TH1F("Eta_2_PT_2_QGTagsMLP_noNJetsCut_Matched_TIGHT", "Eta_2_PT_2_QGTagsMLP_noNJetsCut_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_TIGHT[3][2] = new TH1F("Eta_3_PT_2_QGTagsMLP_noNJetsCut_Matched_TIGHT", "Eta_3_PT_2_QGTagsMLP_noNJetsCut_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_TIGHT[4][2] = new TH1F("Eta_4_PT_2_QGTagsMLP_noNJetsCut_Matched_TIGHT", "Eta_4_PT_2_QGTagsMLP_noNJetsCut_Matched_TIGHT",40000, -2, 2);

       h_QGTagsMLP_noNJetsCut_Matched_TIGHT[0][3] = new TH1F("Eta_0_PT_3_QGTagsMLP_noNJetsCut_Matched_TIGHT", "Eta_0_PT_3_QGTagsMLP_noNJetsCut_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_TIGHT[1][3] = new TH1F("Eta_1_PT_3_QGTagsMLP_noNJetsCut_Matched_TIGHT", "Eta_1_PT_3_QGTagsMLP_noNJetsCut_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_TIGHT[2][3] = new TH1F("Eta_2_PT_3_QGTagsMLP_noNJetsCut_Matched_TIGHT", "Eta_2_PT_3_QGTagsMLP_noNJetsCut_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_TIGHT[3][3] = new TH1F("Eta_3_PT_3_QGTagsMLP_noNJetsCut_Matched_TIGHT", "Eta_3_PT_3_QGTagsMLP_noNJetsCut_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_TIGHT[4][3] = new TH1F("Eta_4_PT_3_QGTagsMLP_noNJetsCut_Matched_TIGHT", "Eta_4_PT_3_QGTagsMLP_noNJetsCut_Matched_TIGHT",40000, -2, 2);

       h_QGTagsMLP_noNJetsCut_Matched_TIGHT[0][4] = new TH1F("Eta_0_PT_4_QGTagsMLP_noNJetsCut_Matched_TIGHT", "Eta_0_PT_4_QGTagsMLP_noNJetsCut_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_TIGHT[1][4] = new TH1F("Eta_1_PT_4_QGTagsMLP_noNJetsCut_Matched_TIGHT", "Eta_1_PT_4_QGTagsMLP_noNJetsCut_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_TIGHT[2][4] = new TH1F("Eta_2_PT_4_QGTagsMLP_noNJetsCut_Matched_TIGHT", "Eta_2_PT_4_QGTagsMLP_noNJetsCut_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_TIGHT[3][4] = new TH1F("Eta_3_PT_4_QGTagsMLP_noNJetsCut_Matched_TIGHT", "Eta_3_PT_4_QGTagsMLP_noNJetsCut_Matched_TIGHT",40000, -2, 2);
       h_QGTagsMLP_noNJetsCut_Matched_TIGHT[4][4] = new TH1F("Eta_4_PT_4_QGTagsMLP_noNJetsCut_Matched_TIGHT", "Eta_4_PT_4_QGTagsMLP_noNJetsCut_Matched_TIGHT",40000, -2, 2);



       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[0][0] = new TH1F("Eta_0_PT_0_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon", "Eta_0_PT_0_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[1][0] = new TH1F("Eta_1_PT_0_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon", "Eta_1_PT_0_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[2][0] = new TH1F("Eta_2_PT_0_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon", "Eta_2_PT_0_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[3][0] = new TH1F("Eta_3_PT_0_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon", "Eta_3_PT_0_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[4][0] = new TH1F("Eta_4_PT_0_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon", "Eta_4_PT_0_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon",20000, -1, 1);

       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[0][1] = new TH1F("Eta_0_PT_1_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon", "Eta_0_PT_1_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[1][1] = new TH1F("Eta_1_PT_1_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon", "Eta_1_PT_1_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[2][1] = new TH1F("Eta_2_PT_1_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon", "Eta_2_PT_1_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[3][1] = new TH1F("Eta_3_PT_1_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon", "Eta_3_PT_1_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[4][1] = new TH1F("Eta_4_PT_1_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon", "Eta_4_PT_1_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon",20000, -1, 1);

       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[0][2] = new TH1F("Eta_0_PT_2_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon", "Eta_0_PT_2_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[1][2] = new TH1F("Eta_1_PT_2_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon", "Eta_1_PT_2_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[2][2] = new TH1F("Eta_2_PT_2_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon", "Eta_2_PT_2_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[3][2] = new TH1F("Eta_3_PT_2_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon", "Eta_3_PT_2_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[4][2] = new TH1F("Eta_4_PT_2_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon", "Eta_4_PT_2_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon",20000, -1, 1);

       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[0][3] = new TH1F("Eta_0_PT_3_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon", "Eta_0_PT_3_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[1][3] = new TH1F("Eta_1_PT_3_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon", "Eta_1_PT_3_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[2][3] = new TH1F("Eta_2_PT_3_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon", "Eta_2_PT_3_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[3][3] = new TH1F("Eta_3_PT_3_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon", "Eta_3_PT_3_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[4][3] = new TH1F("Eta_4_PT_3_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon", "Eta_4_PT_3_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon",20000, -1, 1);

       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[0][4] = new TH1F("Eta_0_PT_4_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon", "Eta_0_PT_4_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[1][4] = new TH1F("Eta_1_PT_4_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon", "Eta_1_PT_4_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[2][4] = new TH1F("Eta_2_PT_4_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon", "Eta_2_PT_4_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[3][4] = new TH1F("Eta_3_PT_4_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon", "Eta_3_PT_4_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[4][4] = new TH1F("Eta_4_PT_4_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon", "Eta_4_PT_4_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon",20000, -1, 1);



       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[0][0] = new TH1F("Eta_0_PT_0_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark", "Eta_0_PT_0_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[1][0] = new TH1F("Eta_1_PT_0_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark", "Eta_1_PT_0_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[2][0] = new TH1F("Eta_2_PT_0_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark", "Eta_2_PT_0_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[3][0] = new TH1F("Eta_3_PT_0_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark", "Eta_3_PT_0_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[4][0] = new TH1F("Eta_4_PT_0_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark", "Eta_4_PT_0_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark",20000, -1, 1);

       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[0][1] = new TH1F("Eta_0_PT_1_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark", "Eta_0_PT_1_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[1][1] = new TH1F("Eta_1_PT_1_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark", "Eta_1_PT_1_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[2][1] = new TH1F("Eta_2_PT_1_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark", "Eta_2_PT_1_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[3][1] = new TH1F("Eta_3_PT_1_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark", "Eta_3_PT_1_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[4][1] = new TH1F("Eta_4_PT_1_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark", "Eta_4_PT_1_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark",20000, -1, 1);

       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[0][2] = new TH1F("Eta_0_PT_2_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark", "Eta_0_PT_2_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[1][2] = new TH1F("Eta_1_PT_2_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark", "Eta_1_PT_2_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[2][2] = new TH1F("Eta_2_PT_2_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark", "Eta_2_PT_2_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[3][2] = new TH1F("Eta_3_PT_2_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark", "Eta_3_PT_2_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[4][2] = new TH1F("Eta_4_PT_2_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark", "Eta_4_PT_2_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark",20000, -1, 1);

       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[0][3] = new TH1F("Eta_0_PT_3_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark", "Eta_0_PT_3_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[1][3] = new TH1F("Eta_1_PT_3_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark", "Eta_1_PT_3_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[2][3] = new TH1F("Eta_2_PT_3_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark", "Eta_2_PT_3_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[3][3] = new TH1F("Eta_3_PT_3_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark", "Eta_3_PT_3_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[4][3] = new TH1F("Eta_4_PT_3_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark", "Eta_4_PT_3_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark",20000, -1, 1);

       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[0][4] = new TH1F("Eta_0_PT_4_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark", "Eta_0_PT_4_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[1][4] = new TH1F("Eta_1_PT_4_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark", "Eta_1_PT_4_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[2][4] = new TH1F("Eta_2_PT_4_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark", "Eta_2_PT_4_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[3][4] = new TH1F("Eta_3_PT_4_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark", "Eta_3_PT_4_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[4][4] = new TH1F("Eta_4_PT_4_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark", "Eta_4_PT_4_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark",20000, -1, 1);






       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[0][0] = new TH1F("Eta_0_PT_0_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon", "Eta_0_PT_0_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[1][0] = new TH1F("Eta_1_PT_0_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon", "Eta_1_PT_0_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[2][0] = new TH1F("Eta_2_PT_0_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon", "Eta_2_PT_0_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[3][0] = new TH1F("Eta_3_PT_0_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon", "Eta_3_PT_0_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[4][0] = new TH1F("Eta_4_PT_0_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon", "Eta_4_PT_0_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon",20000, -1, 1);

       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[0][1] = new TH1F("Eta_0_PT_1_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon", "Eta_0_PT_1_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[1][1] = new TH1F("Eta_1_PT_1_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon", "Eta_1_PT_1_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[2][1] = new TH1F("Eta_2_PT_1_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon", "Eta_2_PT_1_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[3][1] = new TH1F("Eta_3_PT_1_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon", "Eta_3_PT_1_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[4][1] = new TH1F("Eta_4_PT_1_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon", "Eta_4_PT_1_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon",20000, -1, 1);

       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[0][2] = new TH1F("Eta_0_PT_2_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon", "Eta_0_PT_2_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[1][2] = new TH1F("Eta_1_PT_2_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon", "Eta_1_PT_2_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[2][2] = new TH1F("Eta_2_PT_2_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon", "Eta_2_PT_2_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[3][2] = new TH1F("Eta_3_PT_2_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon", "Eta_3_PT_2_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[4][2] = new TH1F("Eta_4_PT_2_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon", "Eta_4_PT_2_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon",20000, -1, 1);

       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[0][3] = new TH1F("Eta_0_PT_3_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon", "Eta_0_PT_3_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[1][3] = new TH1F("Eta_1_PT_3_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon", "Eta_1_PT_3_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[2][3] = new TH1F("Eta_2_PT_3_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon", "Eta_2_PT_3_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[3][3] = new TH1F("Eta_3_PT_3_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon", "Eta_3_PT_3_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[4][3] = new TH1F("Eta_4_PT_3_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon", "Eta_4_PT_3_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon",20000, -1, 1);

       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[0][4] = new TH1F("Eta_0_PT_4_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon", "Eta_0_PT_4_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[1][4] = new TH1F("Eta_1_PT_4_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon", "Eta_1_PT_4_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[2][4] = new TH1F("Eta_2_PT_4_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon", "Eta_2_PT_4_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[3][4] = new TH1F("Eta_3_PT_4_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon", "Eta_3_PT_4_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[4][4] = new TH1F("Eta_4_PT_4_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon", "Eta_4_PT_4_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon",20000, -1, 1);



       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[0][0] = new TH1F("Eta_0_PT_0_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark", "Eta_0_PT_0_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[1][0] = new TH1F("Eta_1_PT_0_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark", "Eta_1_PT_0_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[2][0] = new TH1F("Eta_2_PT_0_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark", "Eta_2_PT_0_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[3][0] = new TH1F("Eta_3_PT_0_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark", "Eta_3_PT_0_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[4][0] = new TH1F("Eta_4_PT_0_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark", "Eta_4_PT_0_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark",20000, -1, 1);

       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[0][1] = new TH1F("Eta_0_PT_1_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark", "Eta_0_PT_1_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[1][1] = new TH1F("Eta_1_PT_1_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark", "Eta_1_PT_1_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[2][1] = new TH1F("Eta_2_PT_1_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark", "Eta_2_PT_1_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[3][1] = new TH1F("Eta_3_PT_1_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark", "Eta_3_PT_1_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[4][1] = new TH1F("Eta_4_PT_1_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark", "Eta_4_PT_1_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark",20000, -1, 1);

       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[0][2] = new TH1F("Eta_0_PT_2_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark", "Eta_0_PT_2_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[1][2] = new TH1F("Eta_1_PT_2_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark", "Eta_1_PT_2_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[2][2] = new TH1F("Eta_2_PT_2_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark", "Eta_2_PT_2_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[3][2] = new TH1F("Eta_3_PT_2_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark", "Eta_3_PT_2_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[4][2] = new TH1F("Eta_4_PT_2_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark", "Eta_4_PT_2_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark",20000, -1, 1);

       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[0][3] = new TH1F("Eta_0_PT_3_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark", "Eta_0_PT_3_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[1][3] = new TH1F("Eta_1_PT_3_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark", "Eta_1_PT_3_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[2][3] = new TH1F("Eta_2_PT_3_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark", "Eta_2_PT_3_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[3][3] = new TH1F("Eta_3_PT_3_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark", "Eta_3_PT_3_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[4][3] = new TH1F("Eta_4_PT_3_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark", "Eta_4_PT_3_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark",20000, -1, 1);

       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[0][4] = new TH1F("Eta_0_PT_4_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark", "Eta_0_PT_4_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[1][4] = new TH1F("Eta_1_PT_4_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark", "Eta_1_PT_4_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[2][4] = new TH1F("Eta_2_PT_4_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark", "Eta_2_PT_4_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[3][4] = new TH1F("Eta_3_PT_4_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark", "Eta_3_PT_4_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark",20000, -1, 1);
       h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[4][4] = new TH1F("Eta_4_PT_4_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark", "Eta_4_PT_4_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark",20000, -1, 1);




        for(unsigned int i=0; i<5; i++){
          for(unsigned int k=0; k<5; k++){

            h_QGTagsMLP_Matched_FO[i][k]->Sumw2();
            h_QGTagsMLP_Matched_TIGHT[i][k]->Sumw2();
            h_Sigma_Ieta_Ieta_TIGHT_Gluon[i][k]->Sumw2();
            h_Sigma_Ieta_Ieta_TIGHT_Quark[i][k]->Sumw2();
            h_Sigma_Ieta_Ieta_FO_Gluon[i][k]->Sumw2();
            h_Sigma_Ieta_Ieta_FO_Quark[i][k]->Sumw2();
            h_QGTagsMLP_noNJetsCut_Matched_FO[i][k]->Sumw2();
            h_QGTagsMLP_noNJetsCut_Matched_TIGHT[i][k]->Sumw2();
            h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[i][k]->Sumw2();
            h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[i][k]->Sumw2();
            h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[i][k]->Sumw2();
            h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[i][k]->Sumw2();

	  }
	}



       TH1F * Numerator_FO_Matching = new TH1F ("Numerator_FO_Matching","Numerator_FO_Matching", Inclusive_N_bins, Inclusive_Min, Inclusive_Max);
       Numerator_FO_Matching->Sumw2();
       TH1F * Denominator_FO_Matching = new TH1F ("Denominator_FO_Matching","Denominator_FO_Matching", Inclusive_N_bins, Inclusive_Min, Inclusive_Max);
       Denominator_FO_Matching->Sumw2();
       TH1F * Efficiency_FO_Matching = new TH1F ("Efficiency_FO_Matching","Efficiency_FO_Matching", Inclusive_N_bins, Inclusive_Min, Inclusive_Max);
       Efficiency_FO_Matching->Sumw2();

       TH1F * Numerator_TIGHT_Matching = new TH1F ("Numerator_TIGHT_Matching","Numerator_TIGHT_Matching", Inclusive_N_bins, Inclusive_Min, Inclusive_Max);
       Numerator_TIGHT_Matching->Sumw2();
       TH1F * Denominator_TIGHT_Matching = new TH1F ("Denominator_TIGHT_Matching","Denominator_TIGHT_Matching", Inclusive_N_bins, Inclusive_Min, Inclusive_Max);
       Denominator_TIGHT_Matching->Sumw2();
       TH1F * Efficiency_TIGHT_Matching = new TH1F ("Efficiency_TIGHT_Matching","Efficiency_TIGHT_Matching", Inclusive_N_bins, Inclusive_Min, Inclusive_Max);
       Numerator_TIGHT_Matching->Sumw2();


       TH1F * Numerator_Gluon_NJets = new TH1F ("Numerator_Gluon_NJets","Numerator_Gluon_NJets", NJets_N_bins, NJets_Min, NJets_Max);
       Numerator_Gluon_NJets->Sumw2();
       TH1F * Denominator_Gluon_NJets = new TH1F ("Denominator_Gluon_NJets","Denominator_Gluon_NJets", NJets_N_bins, NJets_Min, NJets_Max);
       Denominator_Gluon_NJets->Sumw2();
       TH1F * FakeRateRatio_Gluon_NJets = new TH1F ("FakeRateRatio_Gluon_NJets","FakeRateRatio_Gluon_NJets", NJets_N_bins, NJets_Min, NJets_Max);
       FakeRateRatio_Gluon_NJets->Sumw2();

       TH1F * Numerator_Gluon_Eta = new TH1F ("Numerator_Gluon_Eta","Numerator_Gluon_Eta", Eta_N_bins, Eta_Min, Eta_Max);
       Numerator_Gluon_Eta->Sumw2();
       TH1F * Denominator_Gluon_Eta = new TH1F ("Denominator_Gluon_Eta","Denominator_Gluon_Eta", Eta_N_bins, Eta_Min, Eta_Max);
       Denominator_Gluon_Eta->Sumw2();
       TH1F * FakeRateRatio_Gluon_Eta = new TH1F ("FakeRateRatio_Gluon_Eta","FakeRateRatio_Gluon_Eta", Eta_N_bins, Eta_Min, Eta_Max);
       FakeRateRatio_Gluon_Eta->Sumw2();

       TH1F * Numerator_Gluon_PT = new TH1F ("Numerator_Gluon_PT","Numerator_Gluon_PT", PT_N_bins, PT_Min, PT_Max);
       Numerator_Gluon_PT->Sumw2();
       TH1F * Denominator_Gluon_PT = new TH1F ("Denominator_Gluon_PT","Denominator_Gluon_PT", PT_N_bins, PT_Min, PT_Max);
       Denominator_Gluon_PT->Sumw2();
       TH1F * FakeRateRatio_Gluon_PT = new TH1F ("FakeRateRatio_Gluon_PT","FakeRateRatio_Gluon_PT", PT_N_bins, PT_Min, PT_Max);
       FakeRateRatio_Gluon_PT->Sumw2();

       TH2F * Numerator_Gluon_Eta_PT = new TH2F ("Numerator_Gluon_Eta_PT","Numerator_Gluon_Eta_PT", Eta_N_bins, Eta_Min, Eta_Max, PT_N_bins, PT_Min, PT_Max);
       Numerator_Gluon_Eta_PT->Sumw2();
       TH2F * Denominator_Gluon_Eta_PT = new TH2F ("Denominator_Gluon_Eta_PT","Denominator_Gluon_Eta_PT", Eta_N_bins, Eta_Min, Eta_Max, PT_N_bins, PT_Min, PT_Max);
       Denominator_Gluon_Eta_PT->Sumw2();
       TH2F * FakeRateRatio_Gluon_Eta_PT = new TH2F ("FakeRateRatio_Gluon_Eta_PT","FakeRateRatio_Gluon_Eta_PT", Eta_N_bins, Eta_Min, Eta_Max, PT_N_bins, PT_Min, PT_Max);
       FakeRateRatio_Gluon_Eta_PT->Sumw2();

       TH1F * Numerator_Gluon_NVTX = new TH1F ("Numerator_Gluon_NVTX","Numerator_Gluon_NVTX", NVTX_N_bins, NVTX_Min, NVTX_Max);
       Numerator_Gluon_NVTX->Sumw2();
       TH1F * Denominator_Gluon_NVTX = new TH1F ("Denominator_Gluon_NVTX","Denominator_Gluon_NVTX", NVTX_N_bins, NVTX_Min, NVTX_Max);
       Denominator_Gluon_NVTX->Sumw2();
       TH1F * FakeRateRatio_Gluon_NVTX = new TH1F ("FakeRateRatio_Gluon_NVTX","FakeRateRatio_Gluon_NVTX", NVTX_N_bins, NVTX_Min, NVTX_Max);
       FakeRateRatio_Gluon_NVTX->Sumw2();

       TH1F * Numerator_Gluon_Inclusive = new TH1F ("Numerator_Gluon_Inclusive","Numerator_Gluon_Inclusive", Inclusive_N_bins, Inclusive_Min, Inclusive_Max);
       Numerator_Gluon_Inclusive->Sumw2();
       TH1F * Denominator_Gluon_Inclusive = new TH1F ("Denominator_Gluon_Inclusive","Denominator_Gluon_Inclusive", Inclusive_N_bins, Inclusive_Min, Inclusive_Max);
       Denominator_Gluon_Inclusive->Sumw2();
       TH1F * FakeRateRatio_Gluon_Inclusive = new TH1F ("FakeRateRatio_Gluon_Inclusive","FakeRateRatio_Gluon_Inclusive", Inclusive_N_bins, Inclusive_Min, Inclusive_Max);
       FakeRateRatio_Gluon_Inclusive->Sumw2();








       TH1F * Numerator_Quark_NJets = new TH1F ("Numerator_Quark_NJets","Numerator_Quark_NJets", NJets_N_bins, NJets_Min, NJets_Max);
       Numerator_Quark_NJets->Sumw2();
       TH1F * Denominator_Quark_NJets = new TH1F ("Denominator_Quark_NJets","Denominator_Quark_NJets", NJets_N_bins, NJets_Min, NJets_Max);
       Denominator_Quark_NJets->Sumw2();
       TH1F * FakeRateRatio_Quark_NJets = new TH1F ("FakeRateRatio_Quark_NJets","FakeRateRatio_Quark_NJets", NJets_N_bins, NJets_Min, NJets_Max);
       FakeRateRatio_Quark_NJets->Sumw2();

       TH1F * Numerator_Quark_Eta = new TH1F ("Numerator_Quark_Eta","Numerator_Quark_Eta", Eta_N_bins, Eta_Min, Eta_Max);
       Numerator_Quark_Eta->Sumw2();
       TH1F * Denominator_Quark_Eta = new TH1F ("Denominator_Quark_Eta","Denominator_Quark_Eta", Eta_N_bins, Eta_Min, Eta_Max);
       Denominator_Quark_Eta->Sumw2();
       TH1F * FakeRateRatio_Quark_Eta = new TH1F ("FakeRateRatio_Quark_Eta","FakeRateRatio_Quark_Eta", Eta_N_bins, Eta_Min, Eta_Max);
       FakeRateRatio_Quark_Eta->Sumw2();

       TH1F * Numerator_Quark_PT = new TH1F ("Numerator_Quark_PT","Numerator_Quark_PT", PT_N_bins, PT_Min, PT_Max);
       Numerator_Quark_PT->Sumw2();
       TH1F * Denominator_Quark_PT = new TH1F ("Denominator_Quark_PT","Denominator_Quark_PT", PT_N_bins, PT_Min, PT_Max);
       Denominator_Quark_PT->Sumw2();
       TH1F * FakeRateRatio_Quark_PT = new TH1F ("FakeRateRatio_Quark_PT","FakeRateRatio_Quark_PT", PT_N_bins, PT_Min, PT_Max);
       FakeRateRatio_Quark_PT->Sumw2();

       TH2F * Numerator_Quark_Eta_PT = new TH2F ("Numerator_Quark_Eta_PT","Numerator_Quark_Eta_PT", Eta_N_bins, Eta_Min, Eta_Max, PT_N_bins, PT_Min, PT_Max);
       Numerator_Quark_Eta_PT->Sumw2();
       TH2F * Denominator_Quark_Eta_PT = new TH2F ("Denominator_Quark_Eta_PT","Denominator_Quark_Eta_PT", Eta_N_bins, Eta_Min, Eta_Max, PT_N_bins, PT_Min, PT_Max);
       Denominator_Quark_Eta_PT->Sumw2();
       TH2F * FakeRateRatio_Quark_Eta_PT = new TH2F ("FakeRateRatio_Quark_Eta_PT","FakeRateRatio_Quark_Eta_PT", Eta_N_bins, Eta_Min, Eta_Max, PT_N_bins, PT_Min, PT_Max);
       FakeRateRatio_Quark_Eta_PT->Sumw2();

       TH1F * Numerator_Quark_NVTX = new TH1F ("Numerator_Quark_NVTX","Numerator_Quark_NVTX", NVTX_N_bins, NVTX_Min, NVTX_Max);
       Numerator_Quark_NVTX->Sumw2();
       TH1F * Denominator_Quark_NVTX = new TH1F ("Denominator_Quark_NVTX","Denominator_Quark_NVTX", NVTX_N_bins, NVTX_Min, NVTX_Max);
       Denominator_Quark_NVTX->Sumw2();
       TH1F * FakeRateRatio_Quark_NVTX = new TH1F ("FakeRateRatio_Quark_NVTX","FakeRateRatio_Quark_NVTX", NVTX_N_bins, NVTX_Min, NVTX_Max);
       FakeRateRatio_Quark_NVTX->Sumw2();

       TH1F * Numerator_Quark_Inclusive = new TH1F ("Numerator_Quark_Inclusive","Numerator_Quark_Inclusive", Inclusive_N_bins, Inclusive_Min, Inclusive_Max);
       Numerator_Quark_Inclusive->Sumw2();
       TH1F * Denominator_Quark_Inclusive = new TH1F ("Denominator_Quark_Inclusive","Denominator_Quark_Inclusive", Inclusive_N_bins, Inclusive_Min, Inclusive_Max);
       Denominator_Quark_Inclusive->Sumw2();
       TH1F * FakeRateRatio_Quark_Inclusive = new TH1F ("FakeRateRatio_Quark_Inclusive","FakeRateRatio_Quark_Inclusive", Inclusive_N_bins, Inclusive_Min, Inclusive_Max);
       FakeRateRatio_Quark_Inclusive->Sumw2();



    EvtInfoBranches EvtInfo;
    GenInfoBranches GenInfo;
    LepInfoBranches LepInfo;
    JetInfoBranches JetInfo;
    PhotonInfoBranches PhotonInfo;
    VertexInfoBranches VertexInfo;


    float set_of_number_of_events[28] = {0};
    set_of_number_of_events[0] = 19800506;
    set_of_number_of_events[1] = 9246629;
    set_of_number_of_events[2] = 42365645;
    set_of_number_of_events[3] = 36215351;
    for(int sample_index=4;sample_index<28;sample_index++){
     set_of_number_of_events[sample_index] = root[sample_index]->GetEntries();
    }

    float set_of_xsections[28] = {20930, 5212, 960.5, 107.5, 0.71, 0.51, 0.37, 0.27, 0.2, 0.51, 0.11, 0.085, 0.068, 0.05, 0.039, 0.03, 0.024, 0.019, 0.015, 0.0091, 0.0058, 0.037, 0.0024, 0.001, 0.00044, 0.00019, 0.000084, 0.000037};


    float set_of_weights[28] = {0};
    for(int sample_index=0;sample_index<28;sample_index++){


      set_of_weights[sample_index] = set_of_xsections[sample_index] / set_of_number_of_events[sample_index];

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
        float Zmass = 0.;

       	RecoLeptonSelection(EvtInfo, LepInfo, NMuons, M_Index, NElectrons, E_Index, NLeptons, L_Index);
       	RecoJetSelection(LepInfo, JetInfo, PhotonInfo, NMuons, M_Index, NElectrons, E_Index, NJets, J_Index, NPhotons, P_Index);
        RecoPhotonSelectionFONoSigmaIetaIeta(LepInfo, PhotonInfo, JetInfo, NJets, J_Index, NMuons, M_Index, NElectrons, E_Index, NPhotons_FO, P_Index_FO, EvtInfo.RhoPU[0]);
	RecoPhotonSelectionNoSigmaIetaIeta(LepInfo, PhotonInfo, NMuons, M_Index, NElectrons, E_Index, NPhotons_TIGHT, P_Index_TIGHT, EvtInfo.RhoPU[0]);

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


       //cout<<"entry:"<<entry <<endl;
       //cout<<"GenInfo.Size:"<<GenInfo.Size <<endl;
       //cout<<"PhotonInfo.Size:"<<PhotonInfo.Size <<endl;


	    for(int g=0;g<NPhotons_FO;g++) { // loop on FO photons

//              if(GenInfo.PhotonFlag[P_Index_FO[g]]==1 ){//Add by Yuhsiang
//              cout<<"PhotonFlag:"<<GenInfo.PhotonFlag[P_Index_FO[g]] <<endl;}//Add by Yuhsiang
//              if(GenInfo.PhotonFlag[P_Index_FO[g]]!=1){continue;}//Add by Yuhsiang

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

		 if( (dR_aux2 == 0.5) || (GenInfo.PhotonFlag[mindex]!=0)  ) continue;
//              cout<<"GenInfo.PhotonFlag[mindex]:"<<GenInfo.PhotonFlag[mindex] <<endl;


              Denominator_FO_Matching->Fill(0.);

              if(dR_aux < 0.5){
                Inclusive_noNJetsCut_QGTagsMLP_Matched_FO->Fill(JetInfo.QGTagsMLP[J_Index[jindex]],set_of_weights[sample_index]);
                Inclusive_noNJetsCut_QGTagsLikelihood_Matched_FO->Fill(JetInfo.QGTagsLikelihood[J_Index[jindex]],set_of_weights[sample_index]);
                for(unsigned int i=0; i<5; i++){
                  for(unsigned int k=0; k<5; k++){
		   if(
  		      PhotonInfo.Eta[P_Index_FO[g]] >= (Eta_Min + i * (Eta_Max - Eta_Min)/ 5) && PhotonInfo.Eta[P_Index_FO[g]] < (Eta_Min + (i+1) * (Eta_Max - Eta_Min) / 5) &&
              //PhotonInfo.Pt[P_Index_FO[g]] >= (PT_Min + k * (PT_Max - PT_Min)/ 5) && PhotonInfo.Pt[P_Index_FO[g]] < (PT_Min + (k+1) * (PT_Max - PT_Min) / 5)
              PhotonInfo.Pt[P_Index_FO[g]] >= pT_subranges[k] && PhotonInfo.Pt[P_Index_FO[g]] < pT_subranges[k+1] 
		     ) h_QGTagsMLP_noNJetsCut_Matched_FO[i][k]->Fill(JetInfo.QGTagsLikelihood[J_Index[jindex]],set_of_weights[sample_index]);
		  }
		}
		if(NJets >=4){
                  Numerator_FO_Matching->Fill(0.);
                  Inclusive_QGTagsMLP_Matched_FO->Fill(JetInfo.QGTagsMLP[J_Index[jindex]],set_of_weights[sample_index]);
                  Inclusive_QGTagsLikelihood_Matched_FO->Fill(JetInfo.QGTagsLikelihood[J_Index[jindex]],set_of_weights[sample_index]);
                  for(unsigned int i=0; i<5; i++){
                    for(unsigned int k=0; k<5; k++){
		     if(
		        PhotonInfo.Eta[P_Index_FO[g]] >= (Eta_Min + i * (Eta_Max - Eta_Min)/ 5) && PhotonInfo.Eta[P_Index_FO[g]] < (Eta_Min + (i+1) * (Eta_Max - Eta_Min) / 5) &&
                //PhotonInfo.Pt[P_Index_FO[g]] >= (PT_Min + k * (PT_Max - PT_Min)/ 5) && PhotonInfo.Pt[P_Index_FO[g]] < (PT_Min + (k+1) * (PT_Max - PT_Min) / 5)
                PhotonInfo.Pt[P_Index_FO[g]] >= pT_subranges[k] && PhotonInfo.Pt[P_Index_FO[g]] < pT_subranges[k+1] 
		       ) h_QGTagsMLP_Matched_FO[i][k]->Fill(JetInfo.QGTagsLikelihood[J_Index[jindex]],set_of_weights[sample_index]);
		     }
		  }
		}
		if(JetInfo.QGTagsLikelihood[J_Index[jindex]] > 0.9){ //Quark-like
                  if(fabs(PhotonInfo.Eta[P_Index_FO[g]])<=1.4442) Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Quark->Fill(((PhotonInfo.SigmaIetaIeta[P_Index_FO[g]]-0.0090405)*1.04+0.0089405),set_of_weights[sample_index]);
		  if(fabs(PhotonInfo.Eta[P_Index_FO[g]])<=2.4 && fabs(PhotonInfo.Eta[P_Index_FO[g]])>=1.566) Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Quark->Fill((PhotonInfo.SigmaIetaIeta[P_Index_FO[g]]*1.1-0.0025),set_of_weights[sample_index]);
                  for(unsigned int i=0; i<5; i++){
                    for(unsigned int k=0; k<5; k++){
		      if(
 		         PhotonInfo.Eta[P_Index_FO[g]] >= (Eta_Min + i * (Eta_Max - Eta_Min)/ 5) && PhotonInfo.Eta[P_Index_FO[g]] < (Eta_Min + (i+1) * (Eta_Max - Eta_Min) / 5) &&
                 //PhotonInfo.Pt[P_Index_FO[g]] >= (PT_Min + k * (PT_Max - PT_Min)/ 5) && PhotonInfo.Pt[P_Index_FO[g]] < (PT_Min + (k+1) * (PT_Max - PT_Min) / 5)
                 PhotonInfo.Pt[P_Index_FO[g]] >= pT_Quark_subranges[k] && PhotonInfo.Pt[P_Index_FO[g]] < pT_Quark_subranges[k+1] 		      		         
			 ){
                           if(fabs(PhotonInfo.Eta[P_Index_FO[g]])<=1.4442) h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[i][k]->Fill(((PhotonInfo.SigmaIetaIeta[P_Index_FO[g]]-0.0090405)*1.04+0.0089405),set_of_weights[sample_index]);
		           if(fabs(PhotonInfo.Eta[P_Index_FO[g]])<=2.4 && fabs(PhotonInfo.Eta[P_Index_FO[g]])>=1.566) h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[i][k]->Fill((PhotonInfo.SigmaIetaIeta[P_Index_FO[g]]*1.1-0.0025),set_of_weights[sample_index]);
		      }
		    }
		  }
		  if(NJets >=4){
                     Denominator_Quark_Inclusive->Fill(0.);
                     if(fabs(PhotonInfo.Eta[P_Index_FO[g]])<=1.4442) Inclusive_Sigma_Ieta_Ieta_FO_Quark->Fill(((PhotonInfo.SigmaIetaIeta[P_Index_FO[g]]-0.0090405)*1.04+0.0089405),set_of_weights[sample_index]);
		     if(fabs(PhotonInfo.Eta[P_Index_FO[g]])<=2.4 && fabs(PhotonInfo.Eta[P_Index_FO[g]])>=1.566) Inclusive_Sigma_Ieta_Ieta_FO_Quark->Fill((PhotonInfo.SigmaIetaIeta[P_Index_FO[g]]*1.1-0.0025),set_of_weights[sample_index]);
                     if(fabs(PhotonInfo.Eta[P_Index_FO[g]])<=1.4442) Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Quark->Fill(((PhotonInfo.SigmaIetaIeta[P_Index_FO[g]]-0.0090405)*1.04+0.0089405),set_of_weights[sample_index]);
                     if(fabs(PhotonInfo.Eta[P_Index_FO[g]])<=2.4 && fabs(PhotonInfo.Eta[P_Index_FO[g]])>=1.566) Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Quark->Fill((PhotonInfo.SigmaIetaIeta[P_Index_FO[g]]*1.1-0.0025),set_of_weights[sample_index]);
                     for(unsigned int i=0; i<5; i++){
                       for(unsigned int k=0; k<5; k++){
		        if(
 		           PhotonInfo.Eta[P_Index_FO[g]] >= (Eta_Min + i * (Eta_Max - Eta_Min)/ 5) && PhotonInfo.Eta[P_Index_FO[g]] < (Eta_Min + (i+1) * (Eta_Max - Eta_Min) / 5) &&
                   //PhotonInfo.Pt[P_Index_FO[g]] >= (PT_Min + k * (PT_Max - PT_Min)/ 5) && PhotonInfo.Pt[P_Index_FO[g]] < (PT_Min + (k+1) * (PT_Max - PT_Min) / 5)
                   PhotonInfo.Pt[P_Index_FO[g]] >= pT_Quark_subranges[k] && PhotonInfo.Pt[P_Index_FO[g]] < pT_Quark_subranges[k+1] 
			   ){
                             if(fabs(PhotonInfo.Eta[P_Index_FO[g]])<=1.4442) h_Sigma_Ieta_Ieta_FO_Quark[i][k]->Fill(((PhotonInfo.SigmaIetaIeta[P_Index_FO[g]]-0.0090405)*1.04+0.0089405),set_of_weights[sample_index]);
		             if(fabs(PhotonInfo.Eta[P_Index_FO[g]])<=2.4 && fabs(PhotonInfo.Eta[P_Index_FO[g]])>=1.566) h_Sigma_Ieta_Ieta_FO_Quark[i][k]->Fill((PhotonInfo.SigmaIetaIeta[P_Index_FO[g]]*1.1-0.0025),set_of_weights[sample_index]);
			}
		       }
		     }
		  }
		  Denominator_Quark_NVTX->Fill(NVertices);
		  Denominator_Quark_NJets->Fill(NJets);
		  Denominator_Quark_PT->Fill(PhotonInfo.Pt[P_Index_FO[g]]);
		  Denominator_Quark_Eta->Fill(PhotonInfo.Eta[P_Index_FO[g]]);
		  Denominator_Quark_Eta_PT->Fill(PhotonInfo.Eta[P_Index_FO[g]],PhotonInfo.Pt[P_Index_FO[g]]);
		}



		if(JetInfo.QGTagsLikelihood[J_Index[jindex]] < 0.9 && JetInfo.QGTagsLikelihood[J_Index[jindex]] >= 0.){ //Gluon/b-jet-like
                  if(fabs(PhotonInfo.Eta[P_Index_FO[g]])<=1.4442) Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Gluon->Fill(((PhotonInfo.SigmaIetaIeta[P_Index_FO[g]]-0.0090405)*1.04+0.0089405),set_of_weights[sample_index]);
		  if(fabs(PhotonInfo.Eta[P_Index_FO[g]])<=2.4 && fabs(PhotonInfo.Eta[P_Index_FO[g]])>=1.566) Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Gluon->Fill((PhotonInfo.SigmaIetaIeta[P_Index_FO[g]]*1.1-0.0025),set_of_weights[sample_index]);

                  for(unsigned int i=0; i<5; i++){
                    for(unsigned int k=0; k<5; k++){
		      if(
 		         PhotonInfo.Eta[P_Index_FO[g]] >= (Eta_Min + i * (Eta_Max - Eta_Min)/ 5) && PhotonInfo.Eta[P_Index_FO[g]] < (Eta_Min + (i+1) * (Eta_Max - Eta_Min) / 5) &&
                 //PhotonInfo.Pt[P_Index_FO[g]] >= (PT_Min + k * (PT_Max - PT_Min)/ 5) && PhotonInfo.Pt[P_Index_FO[g]] < (PT_Min + (k+1) * (PT_Max - PT_Min) / 5)
                 PhotonInfo.Pt[P_Index_FO[g]] >= pT_Gluon_subranges[k] && PhotonInfo.Pt[P_Index_FO[g]] < pT_Gluon_subranges[k+1] 
			 ){
                           if(fabs(PhotonInfo.Eta[P_Index_FO[g]])<=1.4442) h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[i][k]->Fill(((PhotonInfo.SigmaIetaIeta[P_Index_FO[g]]-0.0090405)*1.04+0.0089405),set_of_weights[sample_index]);
	   	           if(fabs(PhotonInfo.Eta[P_Index_FO[g]])<=2.4 && fabs(PhotonInfo.Eta[P_Index_FO[g]])>=1.566) h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[i][k]->Fill((PhotonInfo.SigmaIetaIeta[P_Index_FO[g]]*1.1-0.0025),set_of_weights[sample_index]);
		      }
		    }
		  }
		  if(NJets >=4){
                     Denominator_Gluon_Inclusive->Fill(0.);
                     if(fabs(PhotonInfo.Eta[P_Index_FO[g]])<=1.4442) Inclusive_Sigma_Ieta_Ieta_FO_Gluon->Fill(((PhotonInfo.SigmaIetaIeta[P_Index_FO[g]]-0.0090405)*1.04+0.0089405),set_of_weights[sample_index]);
		     if(fabs(PhotonInfo.Eta[P_Index_FO[g]])<=2.4 && fabs(PhotonInfo.Eta[P_Index_FO[g]])>=1.566) Inclusive_Sigma_Ieta_Ieta_FO_Gluon->Fill((PhotonInfo.SigmaIetaIeta[P_Index_FO[g]]*1.1-0.0025),set_of_weights[sample_index]);
                     if(fabs(PhotonInfo.Eta[P_Index_FO[g]])<=1.4442) Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Gluon->Fill(((PhotonInfo.SigmaIetaIeta[P_Index_FO[g]]-0.0090405)*1.04+0.0089405),set_of_weights[sample_index]);
                     if(fabs(PhotonInfo.Eta[P_Index_FO[g]])<=2.4 && fabs(PhotonInfo.Eta[P_Index_FO[g]])>=1.566) Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Gluon->Fill((PhotonInfo.SigmaIetaIeta[P_Index_FO[g]]*1.1-0.0025),set_of_weights[sample_index]);
                     for(unsigned int i=0; i<5; i++){
                       for(unsigned int k=0; k<5; k++){
		        if(
   		           PhotonInfo.Eta[P_Index_FO[g]] >= (Eta_Min + i * (Eta_Max - Eta_Min)/ 5) && PhotonInfo.Eta[P_Index_FO[g]] < (Eta_Min + (i+1) * (Eta_Max - Eta_Min) / 5) &&
                   //PhotonInfo.Pt[P_Index_FO[g]] >= (PT_Min + k * (PT_Max - PT_Min)/ 5) && PhotonInfo.Pt[P_Index_FO[g]] < (PT_Min + (k+1) * (PT_Max - PT_Min) / 5)
                   PhotonInfo.Pt[P_Index_FO[g]] >= pT_Gluon_subranges[k] && PhotonInfo.Pt[P_Index_FO[g]] < pT_Gluon_subranges[k+1] 
			   ){
                             if(fabs(PhotonInfo.Eta[P_Index_FO[g]])<=1.4442) h_Sigma_Ieta_Ieta_FO_Gluon[i][k]->Fill(((PhotonInfo.SigmaIetaIeta[P_Index_FO[g]]-0.0090405)*1.04+0.0089405),set_of_weights[sample_index]);
		             if(fabs(PhotonInfo.Eta[P_Index_FO[g]])<=2.4 && fabs(PhotonInfo.Eta[P_Index_FO[g]])>=1.566) h_Sigma_Ieta_Ieta_FO_Gluon[i][k]->Fill((PhotonInfo.SigmaIetaIeta[P_Index_FO[g]]*1.1-0.0025),set_of_weights[sample_index]);
			}
		       }
		     }
		  }

		  Denominator_Gluon_NVTX->Fill(NVertices);
		  Denominator_Gluon_NJets->Fill(NJets);
		  Denominator_Gluon_PT->Fill(PhotonInfo.Pt[P_Index_FO[g]]);
		  Denominator_Gluon_Eta->Fill(PhotonInfo.Eta[P_Index_FO[g]]);
		  Denominator_Gluon_Eta_PT->Fill(PhotonInfo.Eta[P_Index_FO[g]],PhotonInfo.Pt[P_Index_FO[g]]);
		}

	      } //Matching
	    } // loop on FO photons




	    for(int g=0;g<NPhotons_TIGHT;g++) { // loop on TIGHT photons

//              if(GenInfo.PhotonFlag[P_Index_TIGHT[g]]==1 ){//Add by Yuhsiang
//              cout<<"PhotonFlag:"<<GenInfo.PhotonFlag[P_Index_TIGHT[g]] <<endl;}//Add by Yuhsiang
//              if(GenInfo.PhotonFlag[P_Index_TIGHT[g]]!=1){continue;}//Add by Yuhsiang

     	      double dR_aux = 0.5;
              int jindex;
	      for(int j=0;j<NJets;j++) { // loop on jets
 	         double dphi = DPHI(PhotonInfo.Phi[P_Index_TIGHT[g]], JetInfo.Phi[J_Index[j]]);
	         double deta = fabs(PhotonInfo.Eta[P_Index_TIGHT[g]]- JetInfo.Eta[J_Index[j]]);
                 double dR   = pow(dphi*dphi+deta*deta, 0.5);
                 if(dR < dR_aux){ dR_aux = dR; jindex = j;}
	      }

               double dR_aux2 = 0.5;

               int mindex;
               for(int m=0;m<GenInfo.Size ;m++) { // loop on GenInfo
                 double dphi = DPHI(PhotonInfo.Phi[P_Index_TIGHT[g]], GenInfo.Phi[m]);
                 double deta = fabs(PhotonInfo.Eta[P_Index_TIGHT[g]]-GenInfo.Eta[m]);
                 double dR   = pow(dphi*dphi+deta*deta, 0.5);
                 if(dR < dR_aux2){ dR_aux2 = dR; mindex = m;}
                 
               }

		 if( (dR_aux2 == 0.5) || (GenInfo.PhotonFlag[mindex]!=0)  ) continue;
//              cout<<"GenInfo.PhotonFlag[mindex]:"<<GenInfo.PhotonFlag[mindex] <<endl;


              Numerator_TIGHT_Matching->Fill(0.);

              if(dR_aux < 0.5){
                Inclusive_noNJetsCut_QGTagsMLP_Matched_TIGHT->Fill(JetInfo.QGTagsMLP[J_Index[jindex]],set_of_weights[sample_index]);
                Inclusive_noNJetsCut_QGTagsLikelihood_Matched_TIGHT->Fill(JetInfo.QGTagsLikelihood[J_Index[jindex]],set_of_weights[sample_index]);
                for(unsigned int i=0; i<5; i++){
                  for(unsigned int k=0; k<5; k++){
		   if(
  		      PhotonInfo.Eta[P_Index_TIGHT[g]] >= (Eta_Min + i * (Eta_Max - Eta_Min)/ 5) && PhotonInfo.Eta[P_Index_TIGHT[g]] < (Eta_Min + (i+1) * (Eta_Max - Eta_Min) / 5) &&
              //PhotonInfo.Pt[P_Index_TIGHT[g]] >= (PT_Min + k * (PT_Max - PT_Min)/ 5) && PhotonInfo.Pt[P_Index_TIGHT[g]] < (PT_Min + (k+1) * (PT_Max - PT_Min) / 5)
              PhotonInfo.Pt[P_Index_TIGHT[g]] >= pT_subranges[k] && PhotonInfo.Pt[P_Index_TIGHT[g]] < pT_subranges[k+1] 
		     ) h_QGTagsMLP_noNJetsCut_Matched_TIGHT[i][k]->Fill(JetInfo.QGTagsLikelihood[J_Index[jindex]],set_of_weights[sample_index]);
		  }
		}
		if(NJets >=4){
                  Numerator_TIGHT_Matching->Fill(0.);
                  Inclusive_QGTagsMLP_Matched_TIGHT->Fill(JetInfo.QGTagsMLP[J_Index[jindex]],set_of_weights[sample_index]);
                  Inclusive_QGTagsLikelihood_Matched_TIGHT->Fill(JetInfo.QGTagsLikelihood[J_Index[jindex]],set_of_weights[sample_index]);
                  for(unsigned int i=0; i<5; i++){
                    for(unsigned int k=0; k<5; k++){
		     if(
		        PhotonInfo.Eta[P_Index_TIGHT[g]] >= (Eta_Min + i * (Eta_Max - Eta_Min)/ 5) && PhotonInfo.Eta[P_Index_TIGHT[g]] < (Eta_Min + (i+1) * (Eta_Max - Eta_Min) / 5) &&
                //PhotonInfo.Pt[P_Index_TIGHT[g]] >= (PT_Min + k * (PT_Max - PT_Min)/ 5) && PhotonInfo.Pt[P_Index_TIGHT[g]] < (PT_Min + (k+1) * (PT_Max - PT_Min) / 5)
                PhotonInfo.Pt[P_Index_TIGHT[g]] >= pT_subranges[k] && PhotonInfo.Pt[P_Index_TIGHT[g]] < pT_subranges[k+1] 
		       ) h_QGTagsMLP_Matched_TIGHT[i][k]->Fill(JetInfo.QGTagsLikelihood[J_Index[jindex]],set_of_weights[sample_index]);
		     }
		  }
		}
		if(JetInfo.QGTagsLikelihood[J_Index[jindex]] > 0.9){ //Quark-like
                  if(fabs(PhotonInfo.Eta[P_Index_TIGHT[g]])<=1.4442) Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Quark->Fill(((PhotonInfo.SigmaIetaIeta[P_Index_TIGHT[g]]-0.0090405)*1.04+0.0089405),set_of_weights[sample_index]);
		  if(fabs(PhotonInfo.Eta[P_Index_TIGHT[g]])<=2.4 && fabs(PhotonInfo.Eta[P_Index_TIGHT[g]])>=1.566) Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Quark->Fill((PhotonInfo.SigmaIetaIeta[P_Index_TIGHT[g]]*1.1-0.0025),set_of_weights[sample_index]);
                  for(unsigned int i=0; i<5; i++){
                    for(unsigned int k=0; k<5; k++){
		      if(
 		         PhotonInfo.Eta[P_Index_TIGHT[g]] >= (Eta_Min + i * (Eta_Max - Eta_Min)/ 5) && PhotonInfo.Eta[P_Index_TIGHT[g]] < (Eta_Min + (i+1) * (Eta_Max - Eta_Min) / 5) &&
                 //PhotonInfo.Pt[P_Index_TIGHT[g]] >= (PT_Min + k * (PT_Max - PT_Min)/ 5) && PhotonInfo.Pt[P_Index_TIGHT[g]] < (PT_Min + (k+1) * (PT_Max - PT_Min) / 5)
                 PhotonInfo.Pt[P_Index_TIGHT[g]] >= pT_Quark_subranges[k] && PhotonInfo.Pt[P_Index_TIGHT[g]] < pT_Quark_subranges[k+1] 		      		         
			 ){
                           if(fabs(PhotonInfo.Eta[P_Index_TIGHT[g]])<=1.4442) h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[i][k]->Fill(((PhotonInfo.SigmaIetaIeta[P_Index_TIGHT[g]]-0.0090405)*1.04+0.0089405),set_of_weights[sample_index]);
		           if(fabs(PhotonInfo.Eta[P_Index_TIGHT[g]])<=2.4 && fabs(PhotonInfo.Eta[P_Index_TIGHT[g]])>=1.566) h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[i][k]->Fill((PhotonInfo.SigmaIetaIeta[P_Index_TIGHT[g]]*1.1-0.0025),set_of_weights[sample_index]);
		      }
		    }
		  }
		  if(NJets >=4){
                     Numerator_Quark_Inclusive->Fill(0.);
                     if(fabs(PhotonInfo.Eta[P_Index_TIGHT[g]])<=1.4442) Inclusive_Sigma_Ieta_Ieta_TIGHT_Quark->Fill(((PhotonInfo.SigmaIetaIeta[P_Index_TIGHT[g]]-0.0090405)*1.04+0.0089405),set_of_weights[sample_index]);
		     if(fabs(PhotonInfo.Eta[P_Index_TIGHT[g]])<=2.4 && fabs(PhotonInfo.Eta[P_Index_TIGHT[g]])>=1.566) Inclusive_Sigma_Ieta_Ieta_TIGHT_Quark->Fill((PhotonInfo.SigmaIetaIeta[P_Index_TIGHT[g]]*1.1-0.0025),set_of_weights[sample_index]);
                     if(fabs(PhotonInfo.Eta[P_Index_TIGHT[g]])<=1.4442) Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark->Fill(((PhotonInfo.SigmaIetaIeta[P_Index_TIGHT[g]]-0.0090405)*1.04+0.0089405),set_of_weights[sample_index]);
                     if(fabs(PhotonInfo.Eta[P_Index_TIGHT[g]])<=2.4 && fabs(PhotonInfo.Eta[P_Index_TIGHT[g]])>=1.566) Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Quark->Fill((PhotonInfo.SigmaIetaIeta[P_Index_TIGHT[g]]*1.1-0.0025),set_of_weights[sample_index]);
                     for(unsigned int i=0; i<5; i++){
                       for(unsigned int k=0; k<5; k++){
		        if(
 		           PhotonInfo.Eta[P_Index_TIGHT[g]] >= (Eta_Min + i * (Eta_Max - Eta_Min)/ 5) && PhotonInfo.Eta[P_Index_TIGHT[g]] < (Eta_Min + (i+1) * (Eta_Max - Eta_Min) / 5) &&
                   //PhotonInfo.Pt[P_Index_TIGHT[g]] >= (PT_Min + k * (PT_Max - PT_Min)/ 5) && PhotonInfo.Pt[P_Index_TIGHT[g]] < (PT_Min + (k+1) * (PT_Max - PT_Min) / 5)
                   PhotonInfo.Pt[P_Index_TIGHT[g]] >= pT_Quark_subranges[k] && PhotonInfo.Pt[P_Index_TIGHT[g]] < pT_Quark_subranges[k+1] 
			   ){
                             if(fabs(PhotonInfo.Eta[P_Index_TIGHT[g]])<=1.4442) h_Sigma_Ieta_Ieta_TIGHT_Quark[i][k]->Fill(((PhotonInfo.SigmaIetaIeta[P_Index_TIGHT[g]]-0.0090405)*1.04+0.0089405),set_of_weights[sample_index]);
		             if(fabs(PhotonInfo.Eta[P_Index_TIGHT[g]])<=2.4 && fabs(PhotonInfo.Eta[P_Index_TIGHT[g]])>=1.566) h_Sigma_Ieta_Ieta_TIGHT_Quark[i][k]->Fill((PhotonInfo.SigmaIetaIeta[P_Index_TIGHT[g]]*1.1-0.0025),set_of_weights[sample_index]);
			}
		       }
		     }
		  }
		  Numerator_Quark_NVTX->Fill(NVertices);
		  Numerator_Quark_NJets->Fill(NJets);
		  Numerator_Quark_PT->Fill(PhotonInfo.Pt[P_Index_TIGHT[g]]);
		  Numerator_Quark_Eta->Fill(PhotonInfo.Eta[P_Index_TIGHT[g]]);
		  Numerator_Quark_Eta_PT->Fill(PhotonInfo.Eta[P_Index_TIGHT[g]],PhotonInfo.Pt[P_Index_TIGHT[g]]);
		}



		if(JetInfo.QGTagsLikelihood[J_Index[jindex]] < 0.9 && JetInfo.QGTagsLikelihood[J_Index[jindex]] >= 0.){ //Gluon/b-jet-like
                  if(fabs(PhotonInfo.Eta[P_Index_TIGHT[g]])<=1.4442) Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Gluon->Fill(((PhotonInfo.SigmaIetaIeta[P_Index_TIGHT[g]]-0.0090405)*1.04+0.0089405),set_of_weights[sample_index]);
		  if(fabs(PhotonInfo.Eta[P_Index_TIGHT[g]])<=2.4 && fabs(PhotonInfo.Eta[P_Index_TIGHT[g]])>=1.566) Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Gluon->Fill((PhotonInfo.SigmaIetaIeta[P_Index_TIGHT[g]]*1.1-0.0025),set_of_weights[sample_index]);

                  for(unsigned int i=0; i<5; i++){
                    for(unsigned int k=0; k<5; k++){
		      if(
 		         PhotonInfo.Eta[P_Index_TIGHT[g]] >= (Eta_Min + i * (Eta_Max - Eta_Min)/ 5) && PhotonInfo.Eta[P_Index_TIGHT[g]] < (Eta_Min + (i+1) * (Eta_Max - Eta_Min) / 5) &&
                 //PhotonInfo.Pt[P_Index_TIGHT[g]] >= (PT_Min + k * (PT_Max - PT_Min)/ 5) && PhotonInfo.Pt[P_Index_TIGHT[g]] < (PT_Min + (k+1) * (PT_Max - PT_Min) / 5)
                 PhotonInfo.Pt[P_Index_TIGHT[g]] >= pT_Gluon_subranges[k] && PhotonInfo.Pt[P_Index_TIGHT[g]] < pT_Gluon_subranges[k+1] 
			 ){
                           if(fabs(PhotonInfo.Eta[P_Index_TIGHT[g]])<=1.4442) h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[i][k]->Fill(((PhotonInfo.SigmaIetaIeta[P_Index_TIGHT[g]]-0.0090405)*1.04+0.0089405),set_of_weights[sample_index]);
	   	           if(fabs(PhotonInfo.Eta[P_Index_TIGHT[g]])<=2.4 && fabs(PhotonInfo.Eta[P_Index_TIGHT[g]])>=1.566) h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[i][k]->Fill((PhotonInfo.SigmaIetaIeta[P_Index_TIGHT[g]]*1.1-0.0025),set_of_weights[sample_index]);
		      }
		    }
		  }
		  if(NJets >=4){
                     Numerator_Gluon_Inclusive->Fill(0.);
                     if(fabs(PhotonInfo.Eta[P_Index_TIGHT[g]])<=1.4442) Inclusive_Sigma_Ieta_Ieta_TIGHT_Gluon->Fill(((PhotonInfo.SigmaIetaIeta[P_Index_TIGHT[g]]-0.0090405)*1.04+0.0089405),set_of_weights[sample_index]);
		     if(fabs(PhotonInfo.Eta[P_Index_TIGHT[g]])<=2.4 && fabs(PhotonInfo.Eta[P_Index_TIGHT[g]])>=1.566) Inclusive_Sigma_Ieta_Ieta_TIGHT_Gluon->Fill((PhotonInfo.SigmaIetaIeta[P_Index_TIGHT[g]]*1.1-0.0025),set_of_weights[sample_index]);
                     if(fabs(PhotonInfo.Eta[P_Index_TIGHT[g]])<=1.4442) Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Gluon->Fill(((PhotonInfo.SigmaIetaIeta[P_Index_TIGHT[g]]-0.0090405)*1.04+0.0089405),set_of_weights[sample_index]);
                     if(fabs(PhotonInfo.Eta[P_Index_TIGHT[g]])<=2.4 && fabs(PhotonInfo.Eta[P_Index_TIGHT[g]])>=1.566) Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Gluon->Fill((PhotonInfo.SigmaIetaIeta[P_Index_TIGHT[g]]*1.1-0.0025),set_of_weights[sample_index]);
                     for(unsigned int i=0; i<5; i++){
                       for(unsigned int k=0; k<5; k++){
		        if(
   		           PhotonInfo.Eta[P_Index_TIGHT[g]] >= (Eta_Min + i * (Eta_Max - Eta_Min)/ 5) && PhotonInfo.Eta[P_Index_TIGHT[g]] < (Eta_Min + (i+1) * (Eta_Max - Eta_Min) / 5) &&
                   //PhotonInfo.Pt[P_Index_TIGHT[g]] >= (PT_Min + k * (PT_Max - PT_Min)/ 5) && PhotonInfo.Pt[P_Index_TIGHT[g]] < (PT_Min + (k+1) * (PT_Max - PT_Min) / 5)
                   PhotonInfo.Pt[P_Index_TIGHT[g]] >= pT_Gluon_subranges[k] && PhotonInfo.Pt[P_Index_TIGHT[g]] < pT_Gluon_subranges[k+1] 
			   ){
                             if(fabs(PhotonInfo.Eta[P_Index_TIGHT[g]])<=1.4442) h_Sigma_Ieta_Ieta_TIGHT_Gluon[i][k]->Fill(((PhotonInfo.SigmaIetaIeta[P_Index_TIGHT[g]]-0.0090405)*1.04+0.0089405),set_of_weights[sample_index]);
		             if(fabs(PhotonInfo.Eta[P_Index_TIGHT[g]])<=2.4 && fabs(PhotonInfo.Eta[P_Index_TIGHT[g]])>=1.566) h_Sigma_Ieta_Ieta_TIGHT_Gluon[i][k]->Fill((PhotonInfo.SigmaIetaIeta[P_Index_TIGHT[g]]*1.1-0.0025),set_of_weights[sample_index]);
			}
		       }
		     }
		  }

		  Numerator_Gluon_NVTX->Fill(NVertices);
		  Numerator_Gluon_NJets->Fill(NJets);
		  Numerator_Gluon_PT->Fill(PhotonInfo.Pt[P_Index_TIGHT[g]]);
		  Numerator_Gluon_Eta->Fill(PhotonInfo.Eta[P_Index_TIGHT[g]]);
		  Numerator_Gluon_Eta_PT->Fill(PhotonInfo.Eta[P_Index_TIGHT[g]],PhotonInfo.Pt[P_Index_TIGHT[g]]);
		}

	      } //Matching
	    } // loop on TIGHT photons




       } //event loop end






    } // sample loop end





       ////////////////////////////
       //  Computation after loops
       ////////////////////////////


       TFile* file_TPResults = new TFile("FakesFromJetsResults_Signal_NoSigmaIetaIeta.root","RECREATE");
       file_TPResults->cd();


       Inclusive_QGTagsMLP_Matched_FO->Write();
       Inclusive_QGTagsMLP_Matched_FO = 0;
       delete Inclusive_QGTagsMLP_Matched_FO;

       Inclusive_QGTagsLikelihood_Matched_FO->Write();
       Inclusive_QGTagsLikelihood_Matched_FO = 0;
       delete Inclusive_QGTagsLikelihood_Matched_FO;

       Inclusive_QGTagsMLP_Matched_TIGHT->Write();
       Inclusive_QGTagsMLP_Matched_TIGHT = 0;
       delete Inclusive_QGTagsMLP_Matched_TIGHT;

       Inclusive_QGTagsLikelihood_Matched_TIGHT->Write();
       Inclusive_QGTagsLikelihood_Matched_TIGHT = 0;
       delete Inclusive_QGTagsLikelihood_Matched_TIGHT;


///////////////  produce  four catogries templates
       Inclusive_Sigma_Ieta_Ieta_TIGHT_Gluon->Write();
       Inclusive_Sigma_Ieta_Ieta_TIGHT_Gluon = 0;
       delete Inclusive_Sigma_Ieta_Ieta_TIGHT_Gluon;

       Inclusive_Sigma_Ieta_Ieta_TIGHT_Quark->Write();
       Inclusive_Sigma_Ieta_Ieta_TIGHT_Quark = 0;
       delete Inclusive_Sigma_Ieta_Ieta_TIGHT_Quark;

       Inclusive_Sigma_Ieta_Ieta_FO_Gluon->Write();
       Inclusive_Sigma_Ieta_Ieta_FO_Gluon = 0;
       delete Inclusive_Sigma_Ieta_Ieta_FO_Gluon;

       Inclusive_Sigma_Ieta_Ieta_FO_Quark->Write();
       Inclusive_Sigma_Ieta_Ieta_FO_Quark = 0;
       delete Inclusive_Sigma_Ieta_Ieta_FO_Quark;
///////////////////



       Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Gluon->Write();
       Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Gluon = 0;
       delete Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Gluon;

       Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark->Write();
       Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark = 0;
       delete Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark;

       Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Gluon->Write();
       Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Gluon = 0;
       delete Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Gluon;

       Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Quark->Write();
       Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Quark = 0;
       delete Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Quark;




       Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Gluon->Write();
       Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Gluon = 0;
       delete Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Gluon;

       Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Quark->Write();
       Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Quark = 0;
       delete Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Quark;

       Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Gluon->Write();
       Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Gluon = 0;
       delete Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Gluon;

       Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Quark->Write();
       Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Quark = 0;
       delete Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Quark;








       Inclusive_noNJetsCut_QGTagsMLP_Matched_FO->Write();
       Inclusive_noNJetsCut_QGTagsMLP_Matched_FO = 0;
       delete Inclusive_noNJetsCut_QGTagsMLP_Matched_FO;

       Inclusive_noNJetsCut_QGTagsLikelihood_Matched_FO->Write();
       Inclusive_noNJetsCut_QGTagsLikelihood_Matched_FO = 0;
       delete Inclusive_noNJetsCut_QGTagsLikelihood_Matched_FO;

       Inclusive_noNJetsCut_QGTagsMLP_Matched_TIGHT->Write();
       Inclusive_noNJetsCut_QGTagsMLP_Matched_TIGHT = 0;
       delete Inclusive_noNJetsCut_QGTagsMLP_Matched_TIGHT;

       Inclusive_noNJetsCut_QGTagsLikelihood_Matched_TIGHT->Write();
       Inclusive_noNJetsCut_QGTagsLikelihood_Matched_TIGHT = 0;
       delete Inclusive_noNJetsCut_QGTagsLikelihood_Matched_TIGHT;



       Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Gluon->Write();
       Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Gluon = 0;
       delete Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Gluon;

       Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Quark->Write();
       Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Quark = 0;
       delete Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Quark;

       Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Gluon->Write();
       Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Gluon = 0;
       delete Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Gluon;

       Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Quark->Write();
       Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Quark = 0;
       delete Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Quark;



        for(unsigned int i=0; i<5; i++){
          for(unsigned int k=0; k<5; k++){
            h_QGTagsMLP_Matched_FO[i][k]->Write();
            h_QGTagsMLP_Matched_FO[i][k] = 0;
            delete h_QGTagsMLP_Matched_FO[i][k];


            h_QGTagsMLP_Matched_TIGHT[i][k]->Write();
            h_QGTagsMLP_Matched_TIGHT[i][k] = 0;
            delete h_QGTagsMLP_Matched_TIGHT[i][k];


            h_Sigma_Ieta_Ieta_TIGHT_Gluon[i][k]->Write();
            h_Sigma_Ieta_Ieta_TIGHT_Gluon[i][k] = 0;
            delete h_Sigma_Ieta_Ieta_TIGHT_Gluon[i][k];


            h_Sigma_Ieta_Ieta_TIGHT_Quark[i][k]->Write();
            h_Sigma_Ieta_Ieta_TIGHT_Quark[i][k] = 0;
            delete h_Sigma_Ieta_Ieta_TIGHT_Quark[i][k];


            h_Sigma_Ieta_Ieta_FO_Gluon[i][k]->Write();
            h_Sigma_Ieta_Ieta_FO_Gluon[i][k] = 0;
            delete h_Sigma_Ieta_Ieta_FO_Gluon[i][k];


            h_Sigma_Ieta_Ieta_FO_Quark[i][k]->Write();
            h_Sigma_Ieta_Ieta_FO_Quark[i][k] = 0;
            delete h_Sigma_Ieta_Ieta_FO_Quark[i][k];





            h_QGTagsMLP_noNJetsCut_Matched_FO[i][k]->Write();
            h_QGTagsMLP_noNJetsCut_Matched_FO[i][k] = 0;
            delete h_QGTagsMLP_noNJetsCut_Matched_FO[i][k];


            h_QGTagsMLP_noNJetsCut_Matched_TIGHT[i][k]->Write();
            h_QGTagsMLP_noNJetsCut_Matched_TIGHT[i][k] = 0;
            delete h_QGTagsMLP_noNJetsCut_Matched_TIGHT[i][k];


            h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[i][k]->Write();
            h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[i][k] = 0;
            delete h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Gluon[i][k];


            h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[i][k]->Write();
            h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[i][k] = 0;
            delete h_Sigma_Ieta_Ieta_noNJetsCut_TIGHT_Quark[i][k];


            h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[i][k]->Write();
            h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[i][k] = 0;
            delete h_Sigma_Ieta_Ieta_noNJetsCut_FO_Gluon[i][k];


            h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[i][k]->Write();
            h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[i][k] = 0;
            delete h_Sigma_Ieta_Ieta_noNJetsCut_FO_Quark[i][k];



  	  }
        }






       for(unsigned int i=0; i<Inclusive_N_bins; i++){
          float num_s = (float)Numerator_FO_Matching->GetBinContent(i+1);
          float den_s = (float)Denominator_FO_Matching->GetBinContent(i+1);
          float eff_s = 0.;
          float err_s = 0.;
          if(den_s != 0.) {
            eff_s = num_s/den_s;
            err_s = (sqrt(num_s*(1-(num_s/den_s)))/den_s);
          }
          Efficiency_FO_Matching->SetBinContent(i+1, eff_s);
          Efficiency_FO_Matching->SetBinError(i+1, err_s);
       }

       Numerator_FO_Matching->Write();
       Numerator_FO_Matching = 0;
       delete Numerator_FO_Matching;

       Denominator_FO_Matching->Write();
       Denominator_FO_Matching = 0;
       delete Denominator_FO_Matching;

       Efficiency_FO_Matching->Write();
       Efficiency_FO_Matching = 0;
       delete Efficiency_FO_Matching;






       for(unsigned int i=0; i<Inclusive_N_bins; i++){
          float num_s = (float)Numerator_TIGHT_Matching->GetBinContent(i+1);
          float den_s = (float)Denominator_TIGHT_Matching->GetBinContent(i+1);
          float eff_s = 0.;
          float err_s = 0.;
          if(den_s != 0.) {
            eff_s = num_s/den_s;
            err_s = (sqrt(num_s*(1-(num_s/den_s)))/den_s);
          }
          Efficiency_TIGHT_Matching->SetBinContent(i+1, eff_s);
          Efficiency_TIGHT_Matching->SetBinError(i+1, err_s);
       }

       Numerator_TIGHT_Matching->Write();
       Numerator_TIGHT_Matching = 0;
       delete Numerator_TIGHT_Matching;

       Denominator_TIGHT_Matching->Write();
       Denominator_TIGHT_Matching = 0;
       delete Denominator_TIGHT_Matching;

       Efficiency_TIGHT_Matching->Write();
       Efficiency_TIGHT_Matching = 0;
       delete Efficiency_TIGHT_Matching;










       for(unsigned int i=0; i<Eta_N_bins; i++){
          float num_s = (float)Numerator_Gluon_Eta->GetBinContent(i+1);
          float den_s = (float)Numerator_Gluon_Eta->GetBinContent(i+1)+Denominator_Gluon_Eta->GetBinContent(i+1);
          float eff_s = 0.;
          float err_s = 0.;
          if(den_s != 0.) {
            eff_s = num_s/den_s;
            err_s = (sqrt(num_s*(1-(num_s/den_s)))/den_s);
          }
          FakeRateRatio_Gluon_Eta->SetBinContent(i+1, eff_s);
          FakeRateRatio_Gluon_Eta->SetBinError(i+1, err_s);
       }

       Numerator_Gluon_Eta->Write();
       Numerator_Gluon_Eta = 0;
       delete Numerator_Gluon_Eta;

       Denominator_Gluon_Eta->Write();
       Denominator_Gluon_Eta = 0;
       delete Denominator_Gluon_Eta;

       FakeRateRatio_Gluon_Eta->Write();
       FakeRateRatio_Gluon_Eta = 0;
       delete FakeRateRatio_Gluon_Eta;


       for(unsigned int i=0; i<PT_N_bins; i++){
          float num_s = (float)Numerator_Gluon_PT->GetBinContent(i+1);
          float den_s = (float)Numerator_Gluon_PT->GetBinContent(i+1)+Denominator_Gluon_PT->GetBinContent(i+1);
          float eff_s = 0.;
          float err_s = 0.;
          if(den_s != 0.) {
            eff_s = num_s/den_s;
            err_s = (sqrt(num_s*(1-(num_s/den_s)))/den_s);
          }
          FakeRateRatio_Gluon_PT->SetBinContent(i+1, eff_s);
          FakeRateRatio_Gluon_PT->SetBinError(i+1, err_s);
       }

       Numerator_Gluon_PT->Write();
       Numerator_Gluon_PT = 0;
       delete Numerator_Gluon_PT;

       Denominator_Gluon_PT->Write();
       Denominator_Gluon_PT = 0;
       delete Denominator_Gluon_PT;

       FakeRateRatio_Gluon_PT->Write();
       FakeRateRatio_Gluon_PT = 0;
       delete FakeRateRatio_Gluon_PT;


       for(unsigned int i=0; i<Eta_N_bins; i++){
        for(unsigned int k=0; k<PT_N_bins; k++){
          float num_s = (float)Numerator_Gluon_Eta_PT->GetBinContent(i+1,k+1);
          float den_s = (float)Numerator_Gluon_Eta_PT->GetBinContent(i+1,k+1)+Denominator_Gluon_Eta_PT->GetBinContent(i+1,k+1);
          float eff_s = 0.;
          float err_s = 0.;
          if(den_s != 0.) {
            eff_s = num_s/den_s;
            err_s = (sqrt(num_s*(1-(num_s/den_s)))/den_s);
          }
          FakeRateRatio_Gluon_Eta_PT->SetBinContent(i+1,k+1, eff_s);
	  FakeRateRatio_Gluon_Eta_PT->SetBinError(i+1,k+1, err_s);
	} 

      }

       Numerator_Gluon_Eta_PT->Write();
       Numerator_Gluon_Eta_PT = 0;
       delete Numerator_Gluon_Eta_PT;

       Denominator_Gluon_Eta_PT->Write();
       Denominator_Gluon_Eta_PT = 0;
       delete Denominator_Gluon_Eta_PT;

       FakeRateRatio_Gluon_Eta_PT->Write();
       FakeRateRatio_Gluon_Eta_PT = 0;
       delete FakeRateRatio_Gluon_Eta_PT;


       for(unsigned int i=0; i<NJets_N_bins; i++){
          float num_s = (float)Numerator_Gluon_NJets->GetBinContent(i+1);
          float den_s = (float)Numerator_Gluon_NJets->GetBinContent(i+1)+Denominator_Gluon_NJets->GetBinContent(i+1);
          float eff_s = 0.;
          float err_s = 0.;
          if(den_s != 0.) {
            eff_s = num_s/den_s;
            err_s = (sqrt(num_s*(1-(num_s/den_s)))/den_s);
          }
          FakeRateRatio_Gluon_NJets->SetBinContent(i+1, eff_s);
          FakeRateRatio_Gluon_NJets->SetBinError(i+1, err_s);
       }

       Numerator_Gluon_NJets->Write();
       Numerator_Gluon_NJets = 0;
       delete Numerator_Gluon_NJets;

       Denominator_Gluon_NJets->Write();
       Denominator_Gluon_NJets = 0;
       delete Denominator_Gluon_NJets;

       FakeRateRatio_Gluon_NJets->Write();
       FakeRateRatio_Gluon_NJets = 0;
       delete FakeRateRatio_Gluon_NJets;


       for(unsigned int i=0; i<NVTX_N_bins; i++){
          float num_s = (float)Numerator_Gluon_NVTX->GetBinContent(i+1);
          float den_s = (float)Numerator_Gluon_NVTX->GetBinContent(i+1)+Denominator_Gluon_NVTX->GetBinContent(i+1);
          float eff_s = 0.;
          float err_s = 0.;
          if(den_s != 0.) {
            eff_s = num_s/den_s;
            err_s = (sqrt(num_s*(1-(num_s/den_s)))/den_s);
          }
          FakeRateRatio_Gluon_NVTX->SetBinContent(i+1, eff_s);
          FakeRateRatio_Gluon_NVTX->SetBinError(i+1, err_s);
       }

       Numerator_Gluon_NVTX->Write();
       Numerator_Gluon_NVTX = 0;
       delete Numerator_Gluon_NVTX;

       Denominator_Gluon_NVTX->Write();
       Denominator_Gluon_NVTX = 0;
       delete Denominator_Gluon_NVTX;

       FakeRateRatio_Gluon_NVTX->Write();
       FakeRateRatio_Gluon_NVTX = 0;
       delete FakeRateRatio_Gluon_NVTX;


       for(unsigned int i=0; i<Inclusive_N_bins; i++){
          float num_s = (float)Numerator_Gluon_Inclusive->GetBinContent(i+1);
          float den_s = (float)Numerator_Gluon_Inclusive->GetBinContent(i+1)+Denominator_Gluon_Inclusive->GetBinContent(i+1);
          float eff_s = 0.;
          float err_s = 0.;
          if(den_s != 0.) {
            eff_s = num_s/den_s;
            err_s = (sqrt(num_s*(1-(num_s/den_s)))/den_s);
          }
          FakeRateRatio_Gluon_Inclusive->SetBinContent(i+1, eff_s);
          FakeRateRatio_Gluon_Inclusive->SetBinError(i+1, err_s);
       }

       Numerator_Gluon_Inclusive->Write();
       Numerator_Gluon_Inclusive = 0;
       delete Numerator_Gluon_Inclusive;

       Denominator_Gluon_Inclusive->Write();
       Denominator_Gluon_Inclusive = 0;
       delete Denominator_Gluon_Inclusive;

       FakeRateRatio_Gluon_Inclusive->Write();
       FakeRateRatio_Gluon_Inclusive = 0;
       delete FakeRateRatio_Gluon_Inclusive;
















       for(unsigned int i=0; i<Eta_N_bins; i++){
          float num_s = (float)Numerator_Quark_Eta->GetBinContent(i+1);
          float den_s = (float)Numerator_Quark_Eta->GetBinContent(i+1)+Denominator_Quark_Eta->GetBinContent(i+1);
          float eff_s = 0.;
          float err_s = 0.;
          if(den_s != 0.) {
            eff_s = num_s/den_s;
            err_s = (sqrt(num_s*(1-(num_s/den_s)))/den_s);
          }
          FakeRateRatio_Quark_Eta->SetBinContent(i+1, eff_s);
          FakeRateRatio_Quark_Eta->SetBinError(i+1, err_s);
       }

       Numerator_Quark_Eta->Write();
       Numerator_Quark_Eta = 0;
       delete Numerator_Quark_Eta;

       Denominator_Quark_Eta->Write();
       Denominator_Quark_Eta = 0;
       delete Denominator_Quark_Eta;

       FakeRateRatio_Quark_Eta->Write();
       FakeRateRatio_Quark_Eta = 0;
       delete FakeRateRatio_Quark_Eta;


       for(unsigned int i=0; i<PT_N_bins; i++){
          float num_s = (float)Numerator_Quark_PT->GetBinContent(i+1);
          float den_s = (float)Numerator_Quark_PT->GetBinContent(i+1)+Denominator_Quark_PT->GetBinContent(i+1);
          float eff_s = 0.;
          float err_s = 0.;
          if(den_s != 0.) {
            eff_s = num_s/den_s;
            err_s = (sqrt(num_s*(1-(num_s/den_s)))/den_s);
          }
          FakeRateRatio_Quark_PT->SetBinContent(i+1, eff_s);
          FakeRateRatio_Quark_PT->SetBinError(i+1, err_s);
       }

       Numerator_Quark_PT->Write();
       Numerator_Quark_PT = 0;
       delete Numerator_Quark_PT;

       Denominator_Quark_PT->Write();
       Denominator_Quark_PT = 0;
       delete Denominator_Quark_PT;

       FakeRateRatio_Quark_PT->Write();
       FakeRateRatio_Quark_PT = 0;
       delete FakeRateRatio_Quark_PT;


       for(unsigned int i=0; i<Eta_N_bins; i++){
        for(unsigned int k=0; k<PT_N_bins; k++){
          float num_s = (float)Numerator_Quark_Eta_PT->GetBinContent(i+1,k+1);
          float den_s = (float)Numerator_Quark_Eta_PT->GetBinContent(i+1,k+1)+Denominator_Quark_Eta_PT->GetBinContent(i+1,k+1);
          float eff_s = 0.;
          float err_s = 0.;
          if(den_s != 0.) {
            eff_s = num_s/den_s;
            err_s = (sqrt(num_s*(1-(num_s/den_s)))/den_s);
          }
          FakeRateRatio_Quark_Eta_PT->SetBinContent(i+1,k+1, eff_s);
	  FakeRateRatio_Quark_Eta_PT->SetBinError(i+1,k+1, err_s);
	} 

      }

       Numerator_Quark_Eta_PT->Write();
       Numerator_Quark_Eta_PT = 0;
       delete Numerator_Quark_Eta_PT;

       Denominator_Quark_Eta_PT->Write();
       Denominator_Quark_Eta_PT = 0;
       delete Denominator_Quark_Eta_PT;

       FakeRateRatio_Quark_Eta_PT->Write();
       FakeRateRatio_Quark_Eta_PT = 0;
       delete FakeRateRatio_Quark_Eta_PT;




       for(unsigned int i=0; i<NJets_N_bins; i++){
          float num_s = (float)Numerator_Quark_NJets->GetBinContent(i+1);
          float den_s = (float)Numerator_Quark_NJets->GetBinContent(i+1)+Denominator_Quark_NJets->GetBinContent(i+1);
          float eff_s = 0.;
          float err_s = 0.;
          if(den_s != 0.) {
            eff_s = num_s/den_s;
            err_s = (sqrt(num_s*(1-(num_s/den_s)))/den_s);
          }
          FakeRateRatio_Quark_NJets->SetBinContent(i+1, eff_s);
          FakeRateRatio_Quark_NJets->SetBinError(i+1, err_s);
       }

       Numerator_Quark_NJets->Write();
       Numerator_Quark_NJets = 0;
       delete Numerator_Quark_NJets;

       Denominator_Quark_NJets->Write();
       Denominator_Quark_NJets = 0;
       delete Denominator_Quark_NJets;

       FakeRateRatio_Quark_NJets->Write();
       FakeRateRatio_Quark_NJets = 0;
       delete FakeRateRatio_Quark_NJets;


       for(unsigned int i=0; i<NVTX_N_bins; i++){
          float num_s = (float)Numerator_Quark_NVTX->GetBinContent(i+1);
          float den_s = (float)Numerator_Quark_NVTX->GetBinContent(i+1)+Denominator_Quark_NVTX->GetBinContent(i+1);
          float eff_s = 0.;
          float err_s = 0.;
          if(den_s != 0.) {
            eff_s = num_s/den_s;
            err_s = (sqrt(num_s*(1-(num_s/den_s)))/den_s);
          }
          FakeRateRatio_Quark_NVTX->SetBinContent(i+1, eff_s);
          FakeRateRatio_Quark_NVTX->SetBinError(i+1, err_s);
       }

       Numerator_Quark_NVTX->Write();
       Numerator_Quark_NVTX = 0;
       delete Numerator_Quark_NVTX;

       Denominator_Quark_NVTX->Write();
       Denominator_Quark_NVTX = 0;
       delete Denominator_Quark_NVTX;

       FakeRateRatio_Quark_NVTX->Write();
       FakeRateRatio_Quark_NVTX = 0;
       delete FakeRateRatio_Quark_NVTX;


       for(unsigned int i=0; i<Inclusive_N_bins; i++){
          float num_s = (float)Numerator_Quark_Inclusive->GetBinContent(i+1);
          float den_s = (float)Numerator_Quark_Inclusive->GetBinContent(i+1)+Denominator_Quark_Inclusive->GetBinContent(i+1);
          float eff_s = 0.;
          float err_s = 0.;
          if(den_s != 0.) {
            eff_s = num_s/den_s;
            err_s = (sqrt(num_s*(1-(num_s/den_s)))/den_s);
          }
          FakeRateRatio_Quark_Inclusive->SetBinContent(i+1, eff_s);
          FakeRateRatio_Quark_Inclusive->SetBinError(i+1, err_s);
       }

       Numerator_Quark_Inclusive->Write();
       Numerator_Quark_Inclusive = 0;
       delete Numerator_Quark_Inclusive;

       Denominator_Quark_Inclusive->Write();
       Denominator_Quark_Inclusive = 0;
       delete Denominator_Quark_Inclusive;

       FakeRateRatio_Quark_Inclusive->Write();
       FakeRateRatio_Quark_Inclusive = 0;
       delete FakeRateRatio_Quark_Inclusive;













       file_TPResults->Write();
       file_TPResults->Close();
       delete file_TPResults;








}
