#include "TFile.h"
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
#include "interface/RecoLeptonSelection_low_pT_muons.h"
#include "interface/RecoPhotonSelectionFO_NoPtCut.h"
#include "interface/RecoPhotonSelectionNoElectronVeto_NoPtCut.h"
#include "interface/RecoPhotonSelectionTIGHT_NoPtCut.h"
#include "interface/RecoJetSelection.h"
//#include "interface/SolutionOfWNeutrino.h"
//#include "Math.h"
#include "interface/ConstantNumbers.h"
#include "TLorentzVector.h"
#include <string>
#include <iostream>
#include <vector>

void TagAndProbeEfficiency()
{
    gROOT->ProcessLine(".L interface/setTDRStyle.C");
    gROOT->ProcessLine("setTDRStyle()");
    gStyle->SetPalette(1);

    TChain *root = new TChain("bprimeKit/root");

    root->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_low_pT_muons*.root");
    //root->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_DoubleMuParked*.root");
    //root->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_SingleMu*.root");
    //root->Add("/afs/cern.ch/work/c/cardaci/REDUCE_DATA_DoubleMuon/*");
    //root->Add("/afs/cern.ch/work/c/cardaci/DoubleMu_Run2012A-22Jan2013-v1_190456-193686/*");
    //root->Add("/afs/cern.ch/work/c/cardaci/SingleMu_Run2012A-22Jan2013-v1_190456-193686/*");
    //root->Add("/afs/cern.ch/work/c/cardaci/MultiJet_Run2012A-13Jul2012-v1_190456-193686/*");
    //root->Add("/afs/cern.ch/work/y/ymtzeng/public/1photon1lepton_DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball_Summer12_DR53X-PU_S10_START53_V7A-v1.root ");
    //root->Add("/afs/cern.ch/work/c/cardaci/REDUCE_DATA_Summer12_1lepton4jets_id_vtx_recover/1lepton4jets_DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball_Summer12_DR53X-PU_S10_START53_V7A-v1.root");



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


    /*
    root->SetBranchStatus("*"      ,0);
    root->SetBranchStatus("GenInfo.*"      ,1);
    root->SetBranchStatus("PFLepInfo.*"      ,1);
    root->SetBranchStatus("PFJetInfo.*"      ,1);
    root->SetBranchStatus("PhotonInfo.*"      ,1);
    */

       TH1F *h_Zmass_Inclusive_FO = new TH1F("Zmass_Inclusive_FO","Zmass_Inclusive_FO",1000,0,1000);
       TH1F *h_Zmass_Inclusive_NoElectronVeto = new TH1F("Zmass_Inclusive_NoElectronVeto","Zmass_Inclusive_NoElectronVeto",1000,0,1000);
       TH1F *h_Zmass_Inclusive_TIGHT = new TH1F("Zmass_Inclusive_TIGHT","Zmass_Inclusive_TIGHT",1000,0,1000);

       TH1F *h_Zmass_Inclusive_noPtCut_noNJetsCut_FO = new TH1F("Zmass_Inclusive_noPtCut_noNJetsCut_FO","Zmass_Inclusive_noPtCut_noNJetsCut_FO",1000,0,1000);
       TH1F *h_Zmass_Inclusive_noPtCut_noNJetsCut_NoElectronVeto = new TH1F("Zmass_Inclusive_noPtCut_noNJetsCut_NoElectronVeto","Zmass_Inclusive_noPtCut_noNJetsCut_NoElectronVeto",1000,0,1000);
       TH1F *h_Zmass_Inclusive_noPtCut_noNJetsCut_TIGHT = new TH1F("Zmass_Inclusive_noPtCut_noNJetsCut_TIGHT","Zmass_Inclusive_noPtCut_noNJetsCut_TIGHT",1000,0,1000);


       TH1F *h_Zmass_Inclusive_noNJetsCut_FO = new TH1F("Zmass_Inclusive_noNJetsCut_FO","Zmass_Inclusive_noNJetsCut_FO",1000,0,1000);
       TH1F *h_Zmass_Inclusive_noNJetsCut_NoElectronVeto = new TH1F("Zmass_Inclusive_noNJetsCut_NoElectronVeto","Zmass_Inclusive_noNJetsCut_NoElectronVeto",1000,0,1000);
       TH1F *h_Zmass_Inclusive_noNJetsCut_TIGHT = new TH1F("Zmass_Inclusive_noNJetsCut_TIGHT","Zmass_Inclusive_noNJetsCut_TIGHT",1000,0,1000);




       TH1F *h_Zmass_Inclusive_noMuMuCut_FO = new TH1F("Zmass_Inclusive_noMuMuCut_FO","Zmass_Inclusive_noMuMuCut_FO",1000,0,1000);
       TH1F *h_Zmass_Inclusive_noMuMuCut_NoElectronVeto = new TH1F("Zmass_Inclusive_noMuMuCut_NoElectronVeto","Zmass_Inclusive_noMuMuCut_NoElectronVeto",1000,0,1000);
       TH1F *h_Zmass_Inclusive_noMuMuCut_TIGHT = new TH1F("Zmass_Inclusive_noMuMuCut_TIGHT","Zmass_Inclusive_noMuMuCut_TIGHT",1000,0,1000);

       TH1F *h_Zmass_Inclusive_noMuMuCut_noPtCut_noNJetsCut_FO = new TH1F("Zmass_Inclusive_noMuMuCut_noPtCut_noNJetsCut_FO","Zmass_Inclusive_noMuMuCut_noPtCut_noNJetsCut_FO",1000,0,1000);
       TH1F *h_Zmass_Inclusive_noMuMuCut_noPtCut_noNJetsCut_NoElectronVeto = new TH1F("Zmass_Inclusive_noMuMuCut_noPtCut_noNJetsCut_NoElectronVeto","Zmass_Inclusive_noMuMuCut_noPtCut_noNJetsCut_NoElectronVeto",1000,0,1000);
       TH1F *h_Zmass_Inclusive_noMuMuCut_noPtCut_noNJetsCut_TIGHT = new TH1F("Zmass_Inclusive_noMuMuCut_noPtCut_noNJetsCut_TIGHT","Zmass_Inclusive_noMuMuCut_noPtCut_noNJetsCut_TIGHT",1000,0,1000);


       TH1F *h_Zmass_Inclusive_noMuMuCut_noNJetsCut_FO = new TH1F("Zmass_Inclusive_noMuMuCut_noNJetsCut_FO","Zmass_Inclusive_noMuMuCut_noNJetsCut_FO",1000,0,1000);
       TH1F *h_Zmass_Inclusive_noMuMuCut_noNJetsCut_NoElectronVeto = new TH1F("Zmass_Inclusive_noMuMuCut_noNJetsCut_NoElectronVeto","Zmass_Inclusive_noMuMuCut_noNJetsCut_NoElectronVeto",1000,0,1000);
       TH1F *h_Zmass_Inclusive_noMuMuCut_noNJetsCut_TIGHT = new TH1F("Zmass_Inclusive_noMuMuCut_noNJetsCut_TIGHT","Zmass_Inclusive_noMuMuCut_noNJetsCut_TIGHT",1000,0,1000);



	
       TLorentzVector gammatight_ , muontight1_ , muontight2_ , z4v, mumu4v;

       float NVTX_Min = -0.5;
       float NVTX_Max = 30.5;
       int NVTX_N_bins = 31;

       float Inclusive_Min = -0.5;
       float Inclusive_Max = 0.5;
       int Inclusive_N_bins = 1;

       float NJets_Min = -0.5;
       float NJets_Max = 10.5;
       int NJets_N_bins = 11;

       float Eta_Min = -3;
       float Eta_Max = 3;
       int Eta_N_bins = 20;

       float PT_Min = 0;
       float PT_Max = 1000;
       int PT_N_bins = 100;



       TH1F * h_Zmass_FO[5][5];
       TH1F * h_Zmass_NoElectronVeto[5][5];
       TH1F * h_Zmass_TIGHT[5][5];

       h_Zmass_FO[0][0] = new TH1F("FO_Eta_0_PT_0_Zmass", "FO_Eta_0_PT_0_Zmass",400, 0, 400);
       h_Zmass_FO[1][0] = new TH1F("FO_Eta_1_PT_0_Zmass", "FO_Eta_1_PT_0_Zmass",400, 0, 400);
       h_Zmass_FO[2][0] = new TH1F("FO_Eta_2_PT_0_Zmass", "FO_Eta_2_PT_0_Zmass",400, 0, 400);
       h_Zmass_FO[3][0] = new TH1F("FO_Eta_3_PT_0_Zmass", "FO_Eta_3_PT_0_Zmass",400, 0, 400);
       h_Zmass_FO[4][0] = new TH1F("FO_Eta_4_PT_0_Zmass", "FO_Eta_4_PT_0_Zmass",400, 0, 400);

       h_Zmass_FO[0][1] = new TH1F("FO_Eta_0_PT_1_Zmass", "FO_Eta_0_PT_1_Zmass",400, 0, 400);
       h_Zmass_FO[1][1] = new TH1F("FO_Eta_1_PT_1_Zmass", "FO_Eta_1_PT_1_Zmass",400, 0, 400);
       h_Zmass_FO[2][1] = new TH1F("FO_Eta_2_PT_1_Zmass", "FO_Eta_2_PT_1_Zmass",400, 0, 400);
       h_Zmass_FO[3][1] = new TH1F("FO_Eta_3_PT_1_Zmass", "FO_Eta_3_PT_1_Zmass",400, 0, 400);
       h_Zmass_FO[4][1] = new TH1F("FO_Eta_4_PT_1_Zmass", "FO_Eta_4_PT_1_Zmass",400, 0, 400);

       h_Zmass_FO[0][2] = new TH1F("FO_Eta_0_PT_2_Zmass", "FO_Eta_0_PT_2_Zmass",400, 0, 400);
       h_Zmass_FO[1][2] = new TH1F("FO_Eta_1_PT_2_Zmass", "FO_Eta_1_PT_2_Zmass",400, 0, 400);
       h_Zmass_FO[2][2] = new TH1F("FO_Eta_2_PT_2_Zmass", "FO_Eta_2_PT_2_Zmass",400, 0, 400);
       h_Zmass_FO[3][2] = new TH1F("FO_Eta_3_PT_2_Zmass", "FO_Eta_3_PT_2_Zmass",400, 0, 400);
       h_Zmass_FO[4][2] = new TH1F("FO_Eta_4_PT_2_Zmass", "FO_Eta_4_PT_2_Zmass",400, 0, 400);

       h_Zmass_FO[0][3] = new TH1F("FO_Eta_0_PT_3_Zmass", "FO_Eta_0_PT_3_Zmass",400, 0, 400);
       h_Zmass_FO[1][3] = new TH1F("FO_Eta_1_PT_3_Zmass", "FO_Eta_1_PT_3_Zmass",400, 0, 400);
       h_Zmass_FO[2][3] = new TH1F("FO_Eta_2_PT_3_Zmass", "FO_Eta_2_PT_3_Zmass",400, 0, 400);
       h_Zmass_FO[3][3] = new TH1F("FO_Eta_3_PT_3_Zmass", "FO_Eta_3_PT_3_Zmass",400, 0, 400);
       h_Zmass_FO[4][3] = new TH1F("FO_Eta_4_PT_3_Zmass", "FO_Eta_4_PT_3_Zmass",400, 0, 400);

       h_Zmass_FO[0][4] = new TH1F("FO_Eta_0_PT_4_Zmass", "FO_Eta_0_PT_4_Zmass",400, 0, 400);
       h_Zmass_FO[1][4] = new TH1F("FO_Eta_1_PT_4_Zmass", "FO_Eta_1_PT_4_Zmass",400, 0, 400);
       h_Zmass_FO[2][4] = new TH1F("FO_Eta_2_PT_4_Zmass", "FO_Eta_2_PT_4_Zmass",400, 0, 400);
       h_Zmass_FO[3][4] = new TH1F("FO_Eta_3_PT_4_Zmass", "FO_Eta_3_PT_4_Zmass",400, 0, 400);
       h_Zmass_FO[4][4] = new TH1F("FO_Eta_4_PT_4_Zmass", "FO_Eta_4_PT_4_Zmass",400, 0, 400);




       h_Zmass_NoElectronVeto[0][0] = new TH1F("NoElectronVeto_Eta_0_PT_0_Zmass", "NoElectronVeto_Eta_0_PT_0_Zmass",400, 0, 400);
       h_Zmass_NoElectronVeto[1][0] = new TH1F("NoElectronVeto_Eta_1_PT_0_Zmass", "NoElectronVeto_Eta_1_PT_0_Zmass",400, 0, 400);
       h_Zmass_NoElectronVeto[2][0] = new TH1F("NoElectronVeto_Eta_2_PT_0_Zmass", "NoElectronVeto_Eta_2_PT_0_Zmass",400, 0, 400);
       h_Zmass_NoElectronVeto[3][0] = new TH1F("NoElectronVeto_Eta_3_PT_0_Zmass", "NoElectronVeto_Eta_3_PT_0_Zmass",400, 0, 400);
       h_Zmass_NoElectronVeto[4][0] = new TH1F("NoElectronVeto_Eta_4_PT_0_Zmass", "NoElectronVeto_Eta_4_PT_0_Zmass",400, 0, 400);

       h_Zmass_NoElectronVeto[0][1] = new TH1F("NoElectronVeto_Eta_0_PT_1_Zmass", "NoElectronVeto_Eta_0_PT_1_Zmass",400, 0, 400);
       h_Zmass_NoElectronVeto[1][1] = new TH1F("NoElectronVeto_Eta_1_PT_1_Zmass", "NoElectronVeto_Eta_1_PT_1_Zmass",400, 0, 400);
       h_Zmass_NoElectronVeto[2][1] = new TH1F("NoElectronVeto_Eta_2_PT_1_Zmass", "NoElectronVeto_Eta_2_PT_1_Zmass",400, 0, 400);
       h_Zmass_NoElectronVeto[3][1] = new TH1F("NoElectronVeto_Eta_3_PT_1_Zmass", "NoElectronVeto_Eta_3_PT_1_Zmass",400, 0, 400);
       h_Zmass_NoElectronVeto[4][1] = new TH1F("NoElectronVeto_Eta_4_PT_1_Zmass", "NoElectronVeto_Eta_4_PT_1_Zmass",400, 0, 400);

       h_Zmass_NoElectronVeto[0][2] = new TH1F("NoElectronVeto_Eta_0_PT_2_Zmass", "NoElectronVeto_Eta_0_PT_2_Zmass",400, 0, 400);
       h_Zmass_NoElectronVeto[1][2] = new TH1F("NoElectronVeto_Eta_1_PT_2_Zmass", "NoElectronVeto_Eta_1_PT_2_Zmass",400, 0, 400);
       h_Zmass_NoElectronVeto[2][2] = new TH1F("NoElectronVeto_Eta_2_PT_2_Zmass", "NoElectronVeto_Eta_2_PT_2_Zmass",400, 0, 400);
       h_Zmass_NoElectronVeto[3][2] = new TH1F("NoElectronVeto_Eta_3_PT_2_Zmass", "NoElectronVeto_Eta_3_PT_2_Zmass",400, 0, 400);
       h_Zmass_NoElectronVeto[4][2] = new TH1F("NoElectronVeto_Eta_4_PT_2_Zmass", "NoElectronVeto_Eta_4_PT_2_Zmass",400, 0, 400);

       h_Zmass_NoElectronVeto[0][3] = new TH1F("NoElectronVeto_Eta_0_PT_3_Zmass", "NoElectronVeto_Eta_0_PT_3_Zmass",400, 0, 400);
       h_Zmass_NoElectronVeto[1][3] = new TH1F("NoElectronVeto_Eta_1_PT_3_Zmass", "NoElectronVeto_Eta_1_PT_3_Zmass",400, 0, 400);
       h_Zmass_NoElectronVeto[2][3] = new TH1F("NoElectronVeto_Eta_2_PT_3_Zmass", "NoElectronVeto_Eta_2_PT_3_Zmass",400, 0, 400);
       h_Zmass_NoElectronVeto[3][3] = new TH1F("NoElectronVeto_Eta_3_PT_3_Zmass", "NoElectronVeto_Eta_3_PT_3_Zmass",400, 0, 400);
       h_Zmass_NoElectronVeto[4][3] = new TH1F("NoElectronVeto_Eta_4_PT_3_Zmass", "NoElectronVeto_Eta_4_PT_3_Zmass",400, 0, 400);

       h_Zmass_NoElectronVeto[0][4] = new TH1F("NoElectronVeto_Eta_0_PT_4_Zmass", "NoElectronVeto_Eta_0_PT_4_Zmass",400, 0, 400);
       h_Zmass_NoElectronVeto[1][4] = new TH1F("NoElectronVeto_Eta_1_PT_4_Zmass", "NoElectronVeto_Eta_1_PT_4_Zmass",400, 0, 400);
       h_Zmass_NoElectronVeto[2][4] = new TH1F("NoElectronVeto_Eta_2_PT_4_Zmass", "NoElectronVeto_Eta_2_PT_4_Zmass",400, 0, 400);
       h_Zmass_NoElectronVeto[3][4] = new TH1F("NoElectronVeto_Eta_3_PT_4_Zmass", "NoElectronVeto_Eta_3_PT_4_Zmass",400, 0, 400);
       h_Zmass_NoElectronVeto[4][4] = new TH1F("NoElectronVeto_Eta_4_PT_4_Zmass", "NoElectronVeto_Eta_4_PT_4_Zmass",400, 0, 400);





       h_Zmass_TIGHT[0][0] = new TH1F("TIGHT_Eta_0_PT_0_Zmass", "TIGHT_Eta_0_PT_0_Zmass",400, 0, 400);
       h_Zmass_TIGHT[1][0] = new TH1F("TIGHT_Eta_1_PT_0_Zmass", "TIGHT_Eta_1_PT_0_Zmass",400, 0, 400);
       h_Zmass_TIGHT[2][0] = new TH1F("TIGHT_Eta_2_PT_0_Zmass", "TIGHT_Eta_2_PT_0_Zmass",400, 0, 400);
       h_Zmass_TIGHT[3][0] = new TH1F("TIGHT_Eta_3_PT_0_Zmass", "TIGHT_Eta_3_PT_0_Zmass",400, 0, 400);
       h_Zmass_TIGHT[4][0] = new TH1F("TIGHT_Eta_4_PT_0_Zmass", "TIGHT_Eta_4_PT_0_Zmass",400, 0, 400);

       h_Zmass_TIGHT[0][1] = new TH1F("TIGHT_Eta_0_PT_1_Zmass", "TIGHT_Eta_0_PT_1_Zmass",400, 0, 400);
       h_Zmass_TIGHT[1][1] = new TH1F("TIGHT_Eta_1_PT_1_Zmass", "TIGHT_Eta_1_PT_1_Zmass",400, 0, 400);
       h_Zmass_TIGHT[2][1] = new TH1F("TIGHT_Eta_2_PT_1_Zmass", "TIGHT_Eta_2_PT_1_Zmass",400, 0, 400);
       h_Zmass_TIGHT[3][1] = new TH1F("TIGHT_Eta_3_PT_1_Zmass", "TIGHT_Eta_3_PT_1_Zmass",400, 0, 400);
       h_Zmass_TIGHT[4][1] = new TH1F("TIGHT_Eta_4_PT_1_Zmass", "TIGHT_Eta_4_PT_1_Zmass",400, 0, 400);

       h_Zmass_TIGHT[0][2] = new TH1F("TIGHT_Eta_0_PT_2_Zmass", "TIGHT_Eta_0_PT_2_Zmass",400, 0, 400);
       h_Zmass_TIGHT[1][2] = new TH1F("TIGHT_Eta_1_PT_2_Zmass", "TIGHT_Eta_1_PT_2_Zmass",400, 0, 400);
       h_Zmass_TIGHT[2][2] = new TH1F("TIGHT_Eta_2_PT_2_Zmass", "TIGHT_Eta_2_PT_2_Zmass",400, 0, 400);
       h_Zmass_TIGHT[3][2] = new TH1F("TIGHT_Eta_3_PT_2_Zmass", "TIGHT_Eta_3_PT_2_Zmass",400, 0, 400);
       h_Zmass_TIGHT[4][2] = new TH1F("TIGHT_Eta_4_PT_2_Zmass", "TIGHT_Eta_4_PT_2_Zmass",400, 0, 400);

       h_Zmass_TIGHT[0][3] = new TH1F("TIGHT_Eta_0_PT_3_Zmass", "TIGHT_Eta_0_PT_3_Zmass",400, 0, 400);
       h_Zmass_TIGHT[1][3] = new TH1F("TIGHT_Eta_1_PT_3_Zmass", "TIGHT_Eta_1_PT_3_Zmass",400, 0, 400);
       h_Zmass_TIGHT[2][3] = new TH1F("TIGHT_Eta_2_PT_3_Zmass", "TIGHT_Eta_2_PT_3_Zmass",400, 0, 400);
       h_Zmass_TIGHT[3][3] = new TH1F("TIGHT_Eta_3_PT_3_Zmass", "TIGHT_Eta_3_PT_3_Zmass",400, 0, 400);
       h_Zmass_TIGHT[4][3] = new TH1F("TIGHT_Eta_4_PT_3_Zmass", "TIGHT_Eta_4_PT_3_Zmass",400, 0, 400);

       h_Zmass_TIGHT[0][4] = new TH1F("TIGHT_Eta_0_PT_4_Zmass", "TIGHT_Eta_0_PT_4_Zmass",400, 0, 400);
       h_Zmass_TIGHT[1][4] = new TH1F("TIGHT_Eta_1_PT_4_Zmass", "TIGHT_Eta_1_PT_4_Zmass",400, 0, 400);
       h_Zmass_TIGHT[2][4] = new TH1F("TIGHT_Eta_2_PT_4_Zmass", "TIGHT_Eta_2_PT_4_Zmass",400, 0, 400);
       h_Zmass_TIGHT[3][4] = new TH1F("TIGHT_Eta_3_PT_4_Zmass", "TIGHT_Eta_3_PT_4_Zmass",400, 0, 400);
       h_Zmass_TIGHT[4][4] = new TH1F("TIGHT_Eta_4_PT_4_Zmass", "TIGHT_Eta_4_PT_4_Zmass",400, 0, 400);








       TH1F * h_Zmass_noNJetsCut_FO[5][5];
       TH1F * h_Zmass_noNJetsCut_NoElectronVeto[5][5];
       TH1F * h_Zmass_noNJetsCut_TIGHT[5][5];

       h_Zmass_noNJetsCut_FO[0][0] = new TH1F("FO_Eta_0_PT_0_Zmass_noNJetsCut", "FO_Eta_0_PT_0_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_FO[1][0] = new TH1F("FO_Eta_1_PT_0_Zmass_noNJetsCut", "FO_Eta_1_PT_0_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_FO[2][0] = new TH1F("FO_Eta_2_PT_0_Zmass_noNJetsCut", "FO_Eta_2_PT_0_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_FO[3][0] = new TH1F("FO_Eta_3_PT_0_Zmass_noNJetsCut", "FO_Eta_3_PT_0_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_FO[4][0] = new TH1F("FO_Eta_4_PT_0_Zmass_noNJetsCut", "FO_Eta_4_PT_0_Zmass_noNJetsCut",400, 0, 400);

       h_Zmass_noNJetsCut_FO[0][1] = new TH1F("FO_Eta_0_PT_1_Zmass_noNJetsCut", "FO_Eta_0_PT_1_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_FO[1][1] = new TH1F("FO_Eta_1_PT_1_Zmass_noNJetsCut", "FO_Eta_1_PT_1_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_FO[2][1] = new TH1F("FO_Eta_2_PT_1_Zmass_noNJetsCut", "FO_Eta_2_PT_1_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_FO[3][1] = new TH1F("FO_Eta_3_PT_1_Zmass_noNJetsCut", "FO_Eta_3_PT_1_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_FO[4][1] = new TH1F("FO_Eta_4_PT_1_Zmass_noNJetsCut", "FO_Eta_4_PT_1_Zmass_noNJetsCut",400, 0, 400);

       h_Zmass_noNJetsCut_FO[0][2] = new TH1F("FO_Eta_0_PT_2_Zmass_noNJetsCut", "FO_Eta_0_PT_2_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_FO[1][2] = new TH1F("FO_Eta_1_PT_2_Zmass_noNJetsCut", "FO_Eta_1_PT_2_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_FO[2][2] = new TH1F("FO_Eta_2_PT_2_Zmass_noNJetsCut", "FO_Eta_2_PT_2_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_FO[3][2] = new TH1F("FO_Eta_3_PT_2_Zmass_noNJetsCut", "FO_Eta_3_PT_2_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_FO[4][2] = new TH1F("FO_Eta_4_PT_2_Zmass_noNJetsCut", "FO_Eta_4_PT_2_Zmass_noNJetsCut",400, 0, 400);

       h_Zmass_noNJetsCut_FO[0][3] = new TH1F("FO_Eta_0_PT_3_Zmass_noNJetsCut", "FO_Eta_0_PT_3_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_FO[1][3] = new TH1F("FO_Eta_1_PT_3_Zmass_noNJetsCut", "FO_Eta_1_PT_3_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_FO[2][3] = new TH1F("FO_Eta_2_PT_3_Zmass_noNJetsCut", "FO_Eta_2_PT_3_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_FO[3][3] = new TH1F("FO_Eta_3_PT_3_Zmass_noNJetsCut", "FO_Eta_3_PT_3_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_FO[4][3] = new TH1F("FO_Eta_4_PT_3_Zmass_noNJetsCut", "FO_Eta_4_PT_3_Zmass_noNJetsCut",400, 0, 400);

       h_Zmass_noNJetsCut_FO[0][4] = new TH1F("FO_Eta_0_PT_4_Zmass_noNJetsCut", "FO_Eta_0_PT_4_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_FO[1][4] = new TH1F("FO_Eta_1_PT_4_Zmass_noNJetsCut", "FO_Eta_1_PT_4_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_FO[2][4] = new TH1F("FO_Eta_2_PT_4_Zmass_noNJetsCut", "FO_Eta_2_PT_4_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_FO[3][4] = new TH1F("FO_Eta_3_PT_4_Zmass_noNJetsCut", "FO_Eta_3_PT_4_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_FO[4][4] = new TH1F("FO_Eta_4_PT_4_Zmass_noNJetsCut", "FO_Eta_4_PT_4_Zmass_noNJetsCut",400, 0, 400);




       h_Zmass_noNJetsCut_NoElectronVeto[0][0] = new TH1F("NoElectronVeto_Eta_0_PT_0_Zmass_noNJetsCut", "NoElectronVeto_Eta_0_PT_0_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_NoElectronVeto[1][0] = new TH1F("NoElectronVeto_Eta_1_PT_0_Zmass_noNJetsCut", "NoElectronVeto_Eta_1_PT_0_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_NoElectronVeto[2][0] = new TH1F("NoElectronVeto_Eta_2_PT_0_Zmass_noNJetsCut", "NoElectronVeto_Eta_2_PT_0_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_NoElectronVeto[3][0] = new TH1F("NoElectronVeto_Eta_3_PT_0_Zmass_noNJetsCut", "NoElectronVeto_Eta_3_PT_0_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_NoElectronVeto[4][0] = new TH1F("NoElectronVeto_Eta_4_PT_0_Zmass_noNJetsCut", "NoElectronVeto_Eta_4_PT_0_Zmass_noNJetsCut",400, 0, 400);

       h_Zmass_noNJetsCut_NoElectronVeto[0][1] = new TH1F("NoElectronVeto_Eta_0_PT_1_Zmass_noNJetsCut", "NoElectronVeto_Eta_0_PT_1_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_NoElectronVeto[1][1] = new TH1F("NoElectronVeto_Eta_1_PT_1_Zmass_noNJetsCut", "NoElectronVeto_Eta_1_PT_1_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_NoElectronVeto[2][1] = new TH1F("NoElectronVeto_Eta_2_PT_1_Zmass_noNJetsCut", "NoElectronVeto_Eta_2_PT_1_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_NoElectronVeto[3][1] = new TH1F("NoElectronVeto_Eta_3_PT_1_Zmass_noNJetsCut", "NoElectronVeto_Eta_3_PT_1_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_NoElectronVeto[4][1] = new TH1F("NoElectronVeto_Eta_4_PT_1_Zmass_noNJetsCut", "NoElectronVeto_Eta_4_PT_1_Zmass_noNJetsCut",400, 0, 400);

       h_Zmass_noNJetsCut_NoElectronVeto[0][2] = new TH1F("NoElectronVeto_Eta_0_PT_2_Zmass_noNJetsCut", "NoElectronVeto_Eta_0_PT_2_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_NoElectronVeto[1][2] = new TH1F("NoElectronVeto_Eta_1_PT_2_Zmass_noNJetsCut", "NoElectronVeto_Eta_1_PT_2_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_NoElectronVeto[2][2] = new TH1F("NoElectronVeto_Eta_2_PT_2_Zmass_noNJetsCut", "NoElectronVeto_Eta_2_PT_2_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_NoElectronVeto[3][2] = new TH1F("NoElectronVeto_Eta_3_PT_2_Zmass_noNJetsCut", "NoElectronVeto_Eta_3_PT_2_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_NoElectronVeto[4][2] = new TH1F("NoElectronVeto_Eta_4_PT_2_Zmass_noNJetsCut", "NoElectronVeto_Eta_4_PT_2_Zmass_noNJetsCut",400, 0, 400);

       h_Zmass_noNJetsCut_NoElectronVeto[0][3] = new TH1F("NoElectronVeto_Eta_0_PT_3_Zmass_noNJetsCut", "NoElectronVeto_Eta_0_PT_3_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_NoElectronVeto[1][3] = new TH1F("NoElectronVeto_Eta_1_PT_3_Zmass_noNJetsCut", "NoElectronVeto_Eta_1_PT_3_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_NoElectronVeto[2][3] = new TH1F("NoElectronVeto_Eta_2_PT_3_Zmass_noNJetsCut", "NoElectronVeto_Eta_2_PT_3_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_NoElectronVeto[3][3] = new TH1F("NoElectronVeto_Eta_3_PT_3_Zmass_noNJetsCut", "NoElectronVeto_Eta_3_PT_3_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_NoElectronVeto[4][3] = new TH1F("NoElectronVeto_Eta_4_PT_3_Zmass_noNJetsCut", "NoElectronVeto_Eta_4_PT_3_Zmass_noNJetsCut",400, 0, 400);

       h_Zmass_noNJetsCut_NoElectronVeto[0][4] = new TH1F("NoElectronVeto_Eta_0_PT_4_Zmass_noNJetsCut", "NoElectronVeto_Eta_0_PT_4_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_NoElectronVeto[1][4] = new TH1F("NoElectronVeto_Eta_1_PT_4_Zmass_noNJetsCut", "NoElectronVeto_Eta_1_PT_4_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_NoElectronVeto[2][4] = new TH1F("NoElectronVeto_Eta_2_PT_4_Zmass_noNJetsCut", "NoElectronVeto_Eta_2_PT_4_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_NoElectronVeto[3][4] = new TH1F("NoElectronVeto_Eta_3_PT_4_Zmass_noNJetsCut", "NoElectronVeto_Eta_3_PT_4_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_NoElectronVeto[4][4] = new TH1F("NoElectronVeto_Eta_4_PT_4_Zmass_noNJetsCut", "NoElectronVeto_Eta_4_PT_4_Zmass_noNJetsCut",400, 0, 400);





       h_Zmass_noNJetsCut_TIGHT[0][0] = new TH1F("TIGHT_Eta_0_PT_0_Zmass_noNJetsCut", "TIGHT_Eta_0_PT_0_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_TIGHT[1][0] = new TH1F("TIGHT_Eta_1_PT_0_Zmass_noNJetsCut", "TIGHT_Eta_1_PT_0_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_TIGHT[2][0] = new TH1F("TIGHT_Eta_2_PT_0_Zmass_noNJetsCut", "TIGHT_Eta_2_PT_0_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_TIGHT[3][0] = new TH1F("TIGHT_Eta_3_PT_0_Zmass_noNJetsCut", "TIGHT_Eta_3_PT_0_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_TIGHT[4][0] = new TH1F("TIGHT_Eta_4_PT_0_Zmass_noNJetsCut", "TIGHT_Eta_4_PT_0_Zmass_noNJetsCut",400, 0, 400);

       h_Zmass_noNJetsCut_TIGHT[0][1] = new TH1F("TIGHT_Eta_0_PT_1_Zmass_noNJetsCut", "TIGHT_Eta_0_PT_1_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_TIGHT[1][1] = new TH1F("TIGHT_Eta_1_PT_1_Zmass_noNJetsCut", "TIGHT_Eta_1_PT_1_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_TIGHT[2][1] = new TH1F("TIGHT_Eta_2_PT_1_Zmass_noNJetsCut", "TIGHT_Eta_2_PT_1_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_TIGHT[3][1] = new TH1F("TIGHT_Eta_3_PT_1_Zmass_noNJetsCut", "TIGHT_Eta_3_PT_1_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_TIGHT[4][1] = new TH1F("TIGHT_Eta_4_PT_1_Zmass_noNJetsCut", "TIGHT_Eta_4_PT_1_Zmass_noNJetsCut",400, 0, 400);

       h_Zmass_noNJetsCut_TIGHT[0][2] = new TH1F("TIGHT_Eta_0_PT_2_Zmass_noNJetsCut", "TIGHT_Eta_0_PT_2_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_TIGHT[1][2] = new TH1F("TIGHT_Eta_1_PT_2_Zmass_noNJetsCut", "TIGHT_Eta_1_PT_2_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_TIGHT[2][2] = new TH1F("TIGHT_Eta_2_PT_2_Zmass_noNJetsCut", "TIGHT_Eta_2_PT_2_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_TIGHT[3][2] = new TH1F("TIGHT_Eta_3_PT_2_Zmass_noNJetsCut", "TIGHT_Eta_3_PT_2_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_TIGHT[4][2] = new TH1F("TIGHT_Eta_4_PT_2_Zmass_noNJetsCut", "TIGHT_Eta_4_PT_2_Zmass_noNJetsCut",400, 0, 400);

       h_Zmass_noNJetsCut_TIGHT[0][3] = new TH1F("TIGHT_Eta_0_PT_3_Zmass_noNJetsCut", "TIGHT_Eta_0_PT_3_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_TIGHT[1][3] = new TH1F("TIGHT_Eta_1_PT_3_Zmass_noNJetsCut", "TIGHT_Eta_1_PT_3_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_TIGHT[2][3] = new TH1F("TIGHT_Eta_2_PT_3_Zmass_noNJetsCut", "TIGHT_Eta_2_PT_3_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_TIGHT[3][3] = new TH1F("TIGHT_Eta_3_PT_3_Zmass_noNJetsCut", "TIGHT_Eta_3_PT_3_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_TIGHT[4][3] = new TH1F("TIGHT_Eta_4_PT_3_Zmass_noNJetsCut", "TIGHT_Eta_4_PT_3_Zmass_noNJetsCut",400, 0, 400);

       h_Zmass_noNJetsCut_TIGHT[0][4] = new TH1F("TIGHT_Eta_0_PT_4_Zmass_noNJetsCut", "TIGHT_Eta_0_PT_4_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_TIGHT[1][4] = new TH1F("TIGHT_Eta_1_PT_4_Zmass_noNJetsCut", "TIGHT_Eta_1_PT_4_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_TIGHT[2][4] = new TH1F("TIGHT_Eta_2_PT_4_Zmass_noNJetsCut", "TIGHT_Eta_2_PT_4_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_TIGHT[3][4] = new TH1F("TIGHT_Eta_3_PT_4_Zmass_noNJetsCut", "TIGHT_Eta_3_PT_4_Zmass_noNJetsCut",400, 0, 400);
       h_Zmass_noNJetsCut_TIGHT[4][4] = new TH1F("TIGHT_Eta_4_PT_4_Zmass_noNJetsCut", "TIGHT_Eta_4_PT_4_Zmass_noNJetsCut",400, 0, 400);




















       TH1F * h_Zmass_noMuMuCut_FO[5][5];
       TH1F * h_Zmass_noMuMuCut_NoElectronVeto[5][5];
       TH1F * h_Zmass_noMuMuCut_TIGHT[5][5];

       h_Zmass_noMuMuCut_FO[0][0] = new TH1F("FO_Eta_0_PT_0_Zmass_noMuMuCut", "FO_Eta_0_PT_0_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_FO[1][0] = new TH1F("FO_Eta_1_PT_0_Zmass_noMuMuCut", "FO_Eta_1_PT_0_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_FO[2][0] = new TH1F("FO_Eta_2_PT_0_Zmass_noMuMuCut", "FO_Eta_2_PT_0_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_FO[3][0] = new TH1F("FO_Eta_3_PT_0_Zmass_noMuMuCut", "FO_Eta_3_PT_0_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_FO[4][0] = new TH1F("FO_Eta_4_PT_0_Zmass_noMuMuCut", "FO_Eta_4_PT_0_Zmass_noMuMuCut",400, 0, 400);

       h_Zmass_noMuMuCut_FO[0][1] = new TH1F("FO_Eta_0_PT_1_Zmass_noMuMuCut", "FO_Eta_0_PT_1_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_FO[1][1] = new TH1F("FO_Eta_1_PT_1_Zmass_noMuMuCut", "FO_Eta_1_PT_1_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_FO[2][1] = new TH1F("FO_Eta_2_PT_1_Zmass_noMuMuCut", "FO_Eta_2_PT_1_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_FO[3][1] = new TH1F("FO_Eta_3_PT_1_Zmass_noMuMuCut", "FO_Eta_3_PT_1_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_FO[4][1] = new TH1F("FO_Eta_4_PT_1_Zmass_noMuMuCut", "FO_Eta_4_PT_1_Zmass_noMuMuCut",400, 0, 400);

       h_Zmass_noMuMuCut_FO[0][2] = new TH1F("FO_Eta_0_PT_2_Zmass_noMuMuCut", "FO_Eta_0_PT_2_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_FO[1][2] = new TH1F("FO_Eta_1_PT_2_Zmass_noMuMuCut", "FO_Eta_1_PT_2_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_FO[2][2] = new TH1F("FO_Eta_2_PT_2_Zmass_noMuMuCut", "FO_Eta_2_PT_2_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_FO[3][2] = new TH1F("FO_Eta_3_PT_2_Zmass_noMuMuCut", "FO_Eta_3_PT_2_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_FO[4][2] = new TH1F("FO_Eta_4_PT_2_Zmass_noMuMuCut", "FO_Eta_4_PT_2_Zmass_noMuMuCut",400, 0, 400);

       h_Zmass_noMuMuCut_FO[0][3] = new TH1F("FO_Eta_0_PT_3_Zmass_noMuMuCut", "FO_Eta_0_PT_3_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_FO[1][3] = new TH1F("FO_Eta_1_PT_3_Zmass_noMuMuCut", "FO_Eta_1_PT_3_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_FO[2][3] = new TH1F("FO_Eta_2_PT_3_Zmass_noMuMuCut", "FO_Eta_2_PT_3_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_FO[3][3] = new TH1F("FO_Eta_3_PT_3_Zmass_noMuMuCut", "FO_Eta_3_PT_3_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_FO[4][3] = new TH1F("FO_Eta_4_PT_3_Zmass_noMuMuCut", "FO_Eta_4_PT_3_Zmass_noMuMuCut",400, 0, 400);

       h_Zmass_noMuMuCut_FO[0][4] = new TH1F("FO_Eta_0_PT_4_Zmass_noMuMuCut", "FO_Eta_0_PT_4_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_FO[1][4] = new TH1F("FO_Eta_1_PT_4_Zmass_noMuMuCut", "FO_Eta_1_PT_4_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_FO[2][4] = new TH1F("FO_Eta_2_PT_4_Zmass_noMuMuCut", "FO_Eta_2_PT_4_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_FO[3][4] = new TH1F("FO_Eta_3_PT_4_Zmass_noMuMuCut", "FO_Eta_3_PT_4_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_FO[4][4] = new TH1F("FO_Eta_4_PT_4_Zmass_noMuMuCut", "FO_Eta_4_PT_4_Zmass_noMuMuCut",400, 0, 400);




       h_Zmass_noMuMuCut_NoElectronVeto[0][0] = new TH1F("NoElectronVeto_Eta_0_PT_0_Zmass_noMuMuCut", "NoElectronVeto_Eta_0_PT_0_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_NoElectronVeto[1][0] = new TH1F("NoElectronVeto_Eta_1_PT_0_Zmass_noMuMuCut", "NoElectronVeto_Eta_1_PT_0_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_NoElectronVeto[2][0] = new TH1F("NoElectronVeto_Eta_2_PT_0_Zmass_noMuMuCut", "NoElectronVeto_Eta_2_PT_0_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_NoElectronVeto[3][0] = new TH1F("NoElectronVeto_Eta_3_PT_0_Zmass_noMuMuCut", "NoElectronVeto_Eta_3_PT_0_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_NoElectronVeto[4][0] = new TH1F("NoElectronVeto_Eta_4_PT_0_Zmass_noMuMuCut", "NoElectronVeto_Eta_4_PT_0_Zmass_noMuMuCut",400, 0, 400);

       h_Zmass_noMuMuCut_NoElectronVeto[0][1] = new TH1F("NoElectronVeto_Eta_0_PT_1_Zmass_noMuMuCut", "NoElectronVeto_Eta_0_PT_1_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_NoElectronVeto[1][1] = new TH1F("NoElectronVeto_Eta_1_PT_1_Zmass_noMuMuCut", "NoElectronVeto_Eta_1_PT_1_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_NoElectronVeto[2][1] = new TH1F("NoElectronVeto_Eta_2_PT_1_Zmass_noMuMuCut", "NoElectronVeto_Eta_2_PT_1_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_NoElectronVeto[3][1] = new TH1F("NoElectronVeto_Eta_3_PT_1_Zmass_noMuMuCut", "NoElectronVeto_Eta_3_PT_1_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_NoElectronVeto[4][1] = new TH1F("NoElectronVeto_Eta_4_PT_1_Zmass_noMuMuCut", "NoElectronVeto_Eta_4_PT_1_Zmass_noMuMuCut",400, 0, 400);

       h_Zmass_noMuMuCut_NoElectronVeto[0][2] = new TH1F("NoElectronVeto_Eta_0_PT_2_Zmass_noMuMuCut", "NoElectronVeto_Eta_0_PT_2_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_NoElectronVeto[1][2] = new TH1F("NoElectronVeto_Eta_1_PT_2_Zmass_noMuMuCut", "NoElectronVeto_Eta_1_PT_2_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_NoElectronVeto[2][2] = new TH1F("NoElectronVeto_Eta_2_PT_2_Zmass_noMuMuCut", "NoElectronVeto_Eta_2_PT_2_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_NoElectronVeto[3][2] = new TH1F("NoElectronVeto_Eta_3_PT_2_Zmass_noMuMuCut", "NoElectronVeto_Eta_3_PT_2_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_NoElectronVeto[4][2] = new TH1F("NoElectronVeto_Eta_4_PT_2_Zmass_noMuMuCut", "NoElectronVeto_Eta_4_PT_2_Zmass_noMuMuCut",400, 0, 400);

       h_Zmass_noMuMuCut_NoElectronVeto[0][3] = new TH1F("NoElectronVeto_Eta_0_PT_3_Zmass_noMuMuCut", "NoElectronVeto_Eta_0_PT_3_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_NoElectronVeto[1][3] = new TH1F("NoElectronVeto_Eta_1_PT_3_Zmass_noMuMuCut", "NoElectronVeto_Eta_1_PT_3_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_NoElectronVeto[2][3] = new TH1F("NoElectronVeto_Eta_2_PT_3_Zmass_noMuMuCut", "NoElectronVeto_Eta_2_PT_3_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_NoElectronVeto[3][3] = new TH1F("NoElectronVeto_Eta_3_PT_3_Zmass_noMuMuCut", "NoElectronVeto_Eta_3_PT_3_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_NoElectronVeto[4][3] = new TH1F("NoElectronVeto_Eta_4_PT_3_Zmass_noMuMuCut", "NoElectronVeto_Eta_4_PT_3_Zmass_noMuMuCut",400, 0, 400);

       h_Zmass_noMuMuCut_NoElectronVeto[0][4] = new TH1F("NoElectronVeto_Eta_0_PT_4_Zmass_noMuMuCut", "NoElectronVeto_Eta_0_PT_4_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_NoElectronVeto[1][4] = new TH1F("NoElectronVeto_Eta_1_PT_4_Zmass_noMuMuCut", "NoElectronVeto_Eta_1_PT_4_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_NoElectronVeto[2][4] = new TH1F("NoElectronVeto_Eta_2_PT_4_Zmass_noMuMuCut", "NoElectronVeto_Eta_2_PT_4_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_NoElectronVeto[3][4] = new TH1F("NoElectronVeto_Eta_3_PT_4_Zmass_noMuMuCut", "NoElectronVeto_Eta_3_PT_4_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_NoElectronVeto[4][4] = new TH1F("NoElectronVeto_Eta_4_PT_4_Zmass_noMuMuCut", "NoElectronVeto_Eta_4_PT_4_Zmass_noMuMuCut",400, 0, 400);





       h_Zmass_noMuMuCut_TIGHT[0][0] = new TH1F("TIGHT_Eta_0_PT_0_Zmass_noMuMuCut", "TIGHT_Eta_0_PT_0_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_TIGHT[1][0] = new TH1F("TIGHT_Eta_1_PT_0_Zmass_noMuMuCut", "TIGHT_Eta_1_PT_0_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_TIGHT[2][0] = new TH1F("TIGHT_Eta_2_PT_0_Zmass_noMuMuCut", "TIGHT_Eta_2_PT_0_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_TIGHT[3][0] = new TH1F("TIGHT_Eta_3_PT_0_Zmass_noMuMuCut", "TIGHT_Eta_3_PT_0_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_TIGHT[4][0] = new TH1F("TIGHT_Eta_4_PT_0_Zmass_noMuMuCut", "TIGHT_Eta_4_PT_0_Zmass_noMuMuCut",400, 0, 400);

       h_Zmass_noMuMuCut_TIGHT[0][1] = new TH1F("TIGHT_Eta_0_PT_1_Zmass_noMuMuCut", "TIGHT_Eta_0_PT_1_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_TIGHT[1][1] = new TH1F("TIGHT_Eta_1_PT_1_Zmass_noMuMuCut", "TIGHT_Eta_1_PT_1_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_TIGHT[2][1] = new TH1F("TIGHT_Eta_2_PT_1_Zmass_noMuMuCut", "TIGHT_Eta_2_PT_1_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_TIGHT[3][1] = new TH1F("TIGHT_Eta_3_PT_1_Zmass_noMuMuCut", "TIGHT_Eta_3_PT_1_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_TIGHT[4][1] = new TH1F("TIGHT_Eta_4_PT_1_Zmass_noMuMuCut", "TIGHT_Eta_4_PT_1_Zmass_noMuMuCut",400, 0, 400);

       h_Zmass_noMuMuCut_TIGHT[0][2] = new TH1F("TIGHT_Eta_0_PT_2_Zmass_noMuMuCut", "TIGHT_Eta_0_PT_2_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_TIGHT[1][2] = new TH1F("TIGHT_Eta_1_PT_2_Zmass_noMuMuCut", "TIGHT_Eta_1_PT_2_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_TIGHT[2][2] = new TH1F("TIGHT_Eta_2_PT_2_Zmass_noMuMuCut", "TIGHT_Eta_2_PT_2_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_TIGHT[3][2] = new TH1F("TIGHT_Eta_3_PT_2_Zmass_noMuMuCut", "TIGHT_Eta_3_PT_2_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_TIGHT[4][2] = new TH1F("TIGHT_Eta_4_PT_2_Zmass_noMuMuCut", "TIGHT_Eta_4_PT_2_Zmass_noMuMuCut",400, 0, 400);

       h_Zmass_noMuMuCut_TIGHT[0][3] = new TH1F("TIGHT_Eta_0_PT_3_Zmass_noMuMuCut", "TIGHT_Eta_0_PT_3_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_TIGHT[1][3] = new TH1F("TIGHT_Eta_1_PT_3_Zmass_noMuMuCut", "TIGHT_Eta_1_PT_3_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_TIGHT[2][3] = new TH1F("TIGHT_Eta_2_PT_3_Zmass_noMuMuCut", "TIGHT_Eta_2_PT_3_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_TIGHT[3][3] = new TH1F("TIGHT_Eta_3_PT_3_Zmass_noMuMuCut", "TIGHT_Eta_3_PT_3_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_TIGHT[4][3] = new TH1F("TIGHT_Eta_4_PT_3_Zmass_noMuMuCut", "TIGHT_Eta_4_PT_3_Zmass_noMuMuCut",400, 0, 400);

       h_Zmass_noMuMuCut_TIGHT[0][4] = new TH1F("TIGHT_Eta_0_PT_4_Zmass_noMuMuCut", "TIGHT_Eta_0_PT_4_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_TIGHT[1][4] = new TH1F("TIGHT_Eta_1_PT_4_Zmass_noMuMuCut", "TIGHT_Eta_1_PT_4_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_TIGHT[2][4] = new TH1F("TIGHT_Eta_2_PT_4_Zmass_noMuMuCut", "TIGHT_Eta_2_PT_4_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_TIGHT[3][4] = new TH1F("TIGHT_Eta_3_PT_4_Zmass_noMuMuCut", "TIGHT_Eta_3_PT_4_Zmass_noMuMuCut",400, 0, 400);
       h_Zmass_noMuMuCut_TIGHT[4][4] = new TH1F("TIGHT_Eta_4_PT_4_Zmass_noMuMuCut", "TIGHT_Eta_4_PT_4_Zmass_noMuMuCut",400, 0, 400);








       TH1F * h_Zmass_noMuMuCut_noNJetsCut_FO[5][5];
       TH1F * h_Zmass_noMuMuCut_noNJetsCut_NoElectronVeto[5][5];
       TH1F * h_Zmass_noMuMuCut_noNJetsCut_TIGHT[5][5];

       h_Zmass_noMuMuCut_noNJetsCut_FO[0][0] = new TH1F("FO_Eta_0_PT_0_Zmass_noMuMuCut_noNJetsCut", "FO_Eta_0_PT_0_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_FO[1][0] = new TH1F("FO_Eta_1_PT_0_Zmass_noMuMuCut_noNJetsCut", "FO_Eta_1_PT_0_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_FO[2][0] = new TH1F("FO_Eta_2_PT_0_Zmass_noMuMuCut_noNJetsCut", "FO_Eta_2_PT_0_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_FO[3][0] = new TH1F("FO_Eta_3_PT_0_Zmass_noMuMuCut_noNJetsCut", "FO_Eta_3_PT_0_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_FO[4][0] = new TH1F("FO_Eta_4_PT_0_Zmass_noMuMuCut_noNJetsCut", "FO_Eta_4_PT_0_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);

       h_Zmass_noMuMuCut_noNJetsCut_FO[0][1] = new TH1F("FO_Eta_0_PT_1_Zmass_noMuMuCut_noNJetsCut", "FO_Eta_0_PT_1_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_FO[1][1] = new TH1F("FO_Eta_1_PT_1_Zmass_noMuMuCut_noNJetsCut", "FO_Eta_1_PT_1_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_FO[2][1] = new TH1F("FO_Eta_2_PT_1_Zmass_noMuMuCut_noNJetsCut", "FO_Eta_2_PT_1_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_FO[3][1] = new TH1F("FO_Eta_3_PT_1_Zmass_noMuMuCut_noNJetsCut", "FO_Eta_3_PT_1_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_FO[4][1] = new TH1F("FO_Eta_4_PT_1_Zmass_noMuMuCut_noNJetsCut", "FO_Eta_4_PT_1_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);

       h_Zmass_noMuMuCut_noNJetsCut_FO[0][2] = new TH1F("FO_Eta_0_PT_2_Zmass_noMuMuCut_noNJetsCut", "FO_Eta_0_PT_2_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_FO[1][2] = new TH1F("FO_Eta_1_PT_2_Zmass_noMuMuCut_noNJetsCut", "FO_Eta_1_PT_2_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_FO[2][2] = new TH1F("FO_Eta_2_PT_2_Zmass_noMuMuCut_noNJetsCut", "FO_Eta_2_PT_2_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_FO[3][2] = new TH1F("FO_Eta_3_PT_2_Zmass_noMuMuCut_noNJetsCut", "FO_Eta_3_PT_2_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_FO[4][2] = new TH1F("FO_Eta_4_PT_2_Zmass_noMuMuCut_noNJetsCut", "FO_Eta_4_PT_2_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);

       h_Zmass_noMuMuCut_noNJetsCut_FO[0][3] = new TH1F("FO_Eta_0_PT_3_Zmass_noMuMuCut_noNJetsCut", "FO_Eta_0_PT_3_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_FO[1][3] = new TH1F("FO_Eta_1_PT_3_Zmass_noMuMuCut_noNJetsCut", "FO_Eta_1_PT_3_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_FO[2][3] = new TH1F("FO_Eta_2_PT_3_Zmass_noMuMuCut_noNJetsCut", "FO_Eta_2_PT_3_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_FO[3][3] = new TH1F("FO_Eta_3_PT_3_Zmass_noMuMuCut_noNJetsCut", "FO_Eta_3_PT_3_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_FO[4][3] = new TH1F("FO_Eta_4_PT_3_Zmass_noMuMuCut_noNJetsCut", "FO_Eta_4_PT_3_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);

       h_Zmass_noMuMuCut_noNJetsCut_FO[0][4] = new TH1F("FO_Eta_0_PT_4_Zmass_noMuMuCut_noNJetsCut", "FO_Eta_0_PT_4_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_FO[1][4] = new TH1F("FO_Eta_1_PT_4_Zmass_noMuMuCut_noNJetsCut", "FO_Eta_1_PT_4_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_FO[2][4] = new TH1F("FO_Eta_2_PT_4_Zmass_noMuMuCut_noNJetsCut", "FO_Eta_2_PT_4_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_FO[3][4] = new TH1F("FO_Eta_3_PT_4_Zmass_noMuMuCut_noNJetsCut", "FO_Eta_3_PT_4_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_FO[4][4] = new TH1F("FO_Eta_4_PT_4_Zmass_noMuMuCut_noNJetsCut", "FO_Eta_4_PT_4_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);




       h_Zmass_noMuMuCut_noNJetsCut_NoElectronVeto[0][0] = new TH1F("NoElectronVeto_Eta_0_PT_0_Zmass_noMuMuCut_noNJetsCut", "NoElectronVeto_Eta_0_PT_0_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_NoElectronVeto[1][0] = new TH1F("NoElectronVeto_Eta_1_PT_0_Zmass_noMuMuCut_noNJetsCut", "NoElectronVeto_Eta_1_PT_0_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_NoElectronVeto[2][0] = new TH1F("NoElectronVeto_Eta_2_PT_0_Zmass_noMuMuCut_noNJetsCut", "NoElectronVeto_Eta_2_PT_0_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_NoElectronVeto[3][0] = new TH1F("NoElectronVeto_Eta_3_PT_0_Zmass_noMuMuCut_noNJetsCut", "NoElectronVeto_Eta_3_PT_0_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_NoElectronVeto[4][0] = new TH1F("NoElectronVeto_Eta_4_PT_0_Zmass_noMuMuCut_noNJetsCut", "NoElectronVeto_Eta_4_PT_0_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);

       h_Zmass_noMuMuCut_noNJetsCut_NoElectronVeto[0][1] = new TH1F("NoElectronVeto_Eta_0_PT_1_Zmass_noMuMuCut_noNJetsCut", "NoElectronVeto_Eta_0_PT_1_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_NoElectronVeto[1][1] = new TH1F("NoElectronVeto_Eta_1_PT_1_Zmass_noMuMuCut_noNJetsCut", "NoElectronVeto_Eta_1_PT_1_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_NoElectronVeto[2][1] = new TH1F("NoElectronVeto_Eta_2_PT_1_Zmass_noMuMuCut_noNJetsCut", "NoElectronVeto_Eta_2_PT_1_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_NoElectronVeto[3][1] = new TH1F("NoElectronVeto_Eta_3_PT_1_Zmass_noMuMuCut_noNJetsCut", "NoElectronVeto_Eta_3_PT_1_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_NoElectronVeto[4][1] = new TH1F("NoElectronVeto_Eta_4_PT_1_Zmass_noMuMuCut_noNJetsCut", "NoElectronVeto_Eta_4_PT_1_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);

       h_Zmass_noMuMuCut_noNJetsCut_NoElectronVeto[0][2] = new TH1F("NoElectronVeto_Eta_0_PT_2_Zmass_noMuMuCut_noNJetsCut", "NoElectronVeto_Eta_0_PT_2_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_NoElectronVeto[1][2] = new TH1F("NoElectronVeto_Eta_1_PT_2_Zmass_noMuMuCut_noNJetsCut", "NoElectronVeto_Eta_1_PT_2_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_NoElectronVeto[2][2] = new TH1F("NoElectronVeto_Eta_2_PT_2_Zmass_noMuMuCut_noNJetsCut", "NoElectronVeto_Eta_2_PT_2_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_NoElectronVeto[3][2] = new TH1F("NoElectronVeto_Eta_3_PT_2_Zmass_noMuMuCut_noNJetsCut", "NoElectronVeto_Eta_3_PT_2_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_NoElectronVeto[4][2] = new TH1F("NoElectronVeto_Eta_4_PT_2_Zmass_noMuMuCut_noNJetsCut", "NoElectronVeto_Eta_4_PT_2_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);

       h_Zmass_noMuMuCut_noNJetsCut_NoElectronVeto[0][3] = new TH1F("NoElectronVeto_Eta_0_PT_3_Zmass_noMuMuCut_noNJetsCut", "NoElectronVeto_Eta_0_PT_3_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_NoElectronVeto[1][3] = new TH1F("NoElectronVeto_Eta_1_PT_3_Zmass_noMuMuCut_noNJetsCut", "NoElectronVeto_Eta_1_PT_3_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_NoElectronVeto[2][3] = new TH1F("NoElectronVeto_Eta_2_PT_3_Zmass_noMuMuCut_noNJetsCut", "NoElectronVeto_Eta_2_PT_3_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_NoElectronVeto[3][3] = new TH1F("NoElectronVeto_Eta_3_PT_3_Zmass_noMuMuCut_noNJetsCut", "NoElectronVeto_Eta_3_PT_3_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_NoElectronVeto[4][3] = new TH1F("NoElectronVeto_Eta_4_PT_3_Zmass_noMuMuCut_noNJetsCut", "NoElectronVeto_Eta_4_PT_3_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);

       h_Zmass_noMuMuCut_noNJetsCut_NoElectronVeto[0][4] = new TH1F("NoElectronVeto_Eta_0_PT_4_Zmass_noMuMuCut_noNJetsCut", "NoElectronVeto_Eta_0_PT_4_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_NoElectronVeto[1][4] = new TH1F("NoElectronVeto_Eta_1_PT_4_Zmass_noMuMuCut_noNJetsCut", "NoElectronVeto_Eta_1_PT_4_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_NoElectronVeto[2][4] = new TH1F("NoElectronVeto_Eta_2_PT_4_Zmass_noMuMuCut_noNJetsCut", "NoElectronVeto_Eta_2_PT_4_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_NoElectronVeto[3][4] = new TH1F("NoElectronVeto_Eta_3_PT_4_Zmass_noMuMuCut_noNJetsCut", "NoElectronVeto_Eta_3_PT_4_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_NoElectronVeto[4][4] = new TH1F("NoElectronVeto_Eta_4_PT_4_Zmass_noMuMuCut_noNJetsCut", "NoElectronVeto_Eta_4_PT_4_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);





       h_Zmass_noMuMuCut_noNJetsCut_TIGHT[0][0] = new TH1F("TIGHT_Eta_0_PT_0_Zmass_noMuMuCut_noNJetsCut", "TIGHT_Eta_0_PT_0_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_TIGHT[1][0] = new TH1F("TIGHT_Eta_1_PT_0_Zmass_noMuMuCut_noNJetsCut", "TIGHT_Eta_1_PT_0_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_TIGHT[2][0] = new TH1F("TIGHT_Eta_2_PT_0_Zmass_noMuMuCut_noNJetsCut", "TIGHT_Eta_2_PT_0_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_TIGHT[3][0] = new TH1F("TIGHT_Eta_3_PT_0_Zmass_noMuMuCut_noNJetsCut", "TIGHT_Eta_3_PT_0_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_TIGHT[4][0] = new TH1F("TIGHT_Eta_4_PT_0_Zmass_noMuMuCut_noNJetsCut", "TIGHT_Eta_4_PT_0_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);

       h_Zmass_noMuMuCut_noNJetsCut_TIGHT[0][1] = new TH1F("TIGHT_Eta_0_PT_1_Zmass_noMuMuCut_noNJetsCut", "TIGHT_Eta_0_PT_1_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_TIGHT[1][1] = new TH1F("TIGHT_Eta_1_PT_1_Zmass_noMuMuCut_noNJetsCut", "TIGHT_Eta_1_PT_1_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_TIGHT[2][1] = new TH1F("TIGHT_Eta_2_PT_1_Zmass_noMuMuCut_noNJetsCut", "TIGHT_Eta_2_PT_1_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_TIGHT[3][1] = new TH1F("TIGHT_Eta_3_PT_1_Zmass_noMuMuCut_noNJetsCut", "TIGHT_Eta_3_PT_1_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_TIGHT[4][1] = new TH1F("TIGHT_Eta_4_PT_1_Zmass_noMuMuCut_noNJetsCut", "TIGHT_Eta_4_PT_1_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);

       h_Zmass_noMuMuCut_noNJetsCut_TIGHT[0][2] = new TH1F("TIGHT_Eta_0_PT_2_Zmass_noMuMuCut_noNJetsCut", "TIGHT_Eta_0_PT_2_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_TIGHT[1][2] = new TH1F("TIGHT_Eta_1_PT_2_Zmass_noMuMuCut_noNJetsCut", "TIGHT_Eta_1_PT_2_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_TIGHT[2][2] = new TH1F("TIGHT_Eta_2_PT_2_Zmass_noMuMuCut_noNJetsCut", "TIGHT_Eta_2_PT_2_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_TIGHT[3][2] = new TH1F("TIGHT_Eta_3_PT_2_Zmass_noMuMuCut_noNJetsCut", "TIGHT_Eta_3_PT_2_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_TIGHT[4][2] = new TH1F("TIGHT_Eta_4_PT_2_Zmass_noMuMuCut_noNJetsCut", "TIGHT_Eta_4_PT_2_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);

       h_Zmass_noMuMuCut_noNJetsCut_TIGHT[0][3] = new TH1F("TIGHT_Eta_0_PT_3_Zmass_noMuMuCut_noNJetsCut", "TIGHT_Eta_0_PT_3_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_TIGHT[1][3] = new TH1F("TIGHT_Eta_1_PT_3_Zmass_noMuMuCut_noNJetsCut", "TIGHT_Eta_1_PT_3_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_TIGHT[2][3] = new TH1F("TIGHT_Eta_2_PT_3_Zmass_noMuMuCut_noNJetsCut", "TIGHT_Eta_2_PT_3_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_TIGHT[3][3] = new TH1F("TIGHT_Eta_3_PT_3_Zmass_noMuMuCut_noNJetsCut", "TIGHT_Eta_3_PT_3_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_TIGHT[4][3] = new TH1F("TIGHT_Eta_4_PT_3_Zmass_noMuMuCut_noNJetsCut", "TIGHT_Eta_4_PT_3_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);

       h_Zmass_noMuMuCut_noNJetsCut_TIGHT[0][4] = new TH1F("TIGHT_Eta_0_PT_4_Zmass_noMuMuCut_noNJetsCut", "TIGHT_Eta_0_PT_4_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_TIGHT[1][4] = new TH1F("TIGHT_Eta_1_PT_4_Zmass_noMuMuCut_noNJetsCut", "TIGHT_Eta_1_PT_4_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_TIGHT[2][4] = new TH1F("TIGHT_Eta_2_PT_4_Zmass_noMuMuCut_noNJetsCut", "TIGHT_Eta_2_PT_4_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_TIGHT[3][4] = new TH1F("TIGHT_Eta_3_PT_4_Zmass_noMuMuCut_noNJetsCut", "TIGHT_Eta_3_PT_4_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);
       h_Zmass_noMuMuCut_noNJetsCut_TIGHT[4][4] = new TH1F("TIGHT_Eta_4_PT_4_Zmass_noMuMuCut_noNJetsCut", "TIGHT_Eta_4_PT_4_Zmass_noMuMuCut_noNJetsCut",400, 0, 400);














       TH1F * Numerator_NJets = new TH1F ("Numerator_NJets","Numerator_NJets", NJets_N_bins, NJets_Min, NJets_Max);
       TH1F * Denominator_NJets = new TH1F ("Denominator_NJets","Denominator_NJets", NJets_N_bins, NJets_Min, NJets_Max);
       TH1F * EfficiencyRatio_NJets = new TH1F ("EfficiencyRatio_NJets","EfficiencyRatio_NJets", NJets_N_bins, NJets_Min, NJets_Max);

       TH1F * Numerator_Eta = new TH1F ("Numerator_Eta","Numerator_Eta", Eta_N_bins, Eta_Min, Eta_Max);
       TH1F * Denominator_Eta = new TH1F ("Denominator_Eta","Denominator_Eta", Eta_N_bins, Eta_Min, Eta_Max);
       TH1F * EfficiencyRatio_Eta = new TH1F ("EfficiencyRatio_Eta","EfficiencyRatio_Eta", Eta_N_bins, Eta_Min, Eta_Max);

       TH1F * Numerator_PT = new TH1F ("Numerator_PT","Numerator_PT", PT_N_bins, PT_Min, PT_Max);
       TH1F * Denominator_PT = new TH1F ("Denominator_PT","Denominator_PT", PT_N_bins, PT_Min, PT_Max);
       TH1F * EfficiencyRatio_PT = new TH1F ("EfficiencyRatio_PT","EfficiencyRatio_PT", PT_N_bins, PT_Min, PT_Max);

       TH2F * Numerator_Eta_PT = new TH2F ("Numerator_Eta_PT","Numerator_Eta_PT", Eta_N_bins, Eta_Min, Eta_Max, PT_N_bins, PT_Min, PT_Max);
       TH2F * Denominator_Eta_PT = new TH2F ("Denominator_Eta_PT","Denominator_Eta_PT", Eta_N_bins, Eta_Min, Eta_Max, PT_N_bins, PT_Min, PT_Max);
       TH2F * EfficiencyRatio_Eta_PT = new TH2F ("EfficiencyRatio_Eta_PT","EfficiencyRatio_Eta_PT", Eta_N_bins, Eta_Min, Eta_Max, PT_N_bins, PT_Min, PT_Max);

       TH1F * Numerator_NVTX = new TH1F ("Numerator_NVTX","Numerator_NVTX", NVTX_N_bins, NVTX_Min, NVTX_Max);
       TH1F * Denominator_NVTX = new TH1F ("Denominator_NVTX","Denominator_NVTX", NVTX_N_bins, NVTX_Min, NVTX_Max);
       TH1F * EfficiencyRatio_NVTX = new TH1F ("EfficiencyRatio_NVTX","EfficiencyRatio_NVTX", NVTX_N_bins, NVTX_Min, NVTX_Max);

       TH1F * Numerator_Inclusive = new TH1F ("Numerator_Inclusive","Numerator_Inclusive", Inclusive_N_bins, Inclusive_Min, Inclusive_Max);
       TH1F * Denominator_Inclusive = new TH1F ("Denominator_Inclusive","Denominator_Inclusive", Inclusive_N_bins, Inclusive_Min, Inclusive_Max);
       TH1F * EfficiencyRatio_Inclusive = new TH1F ("EfficiencyRatio_Inclusive","EfficiencyRatio_Inclusive", Inclusive_N_bins, Inclusive_Min, Inclusive_Max);


       map< pair<int, int>, int > evtlist;
       //Event loop begin
       for(int entry=0; entry < root->GetEntries(); entry++) {
        int tot_entries = root->GetEntries();

        root->GetEntry(entry);
	

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
	int P_Index_NoElectronVeto[MAX_PHOTONS];
	int P_Index_TIGHT[MAX_PHOTONS];

	for(int m=0;m<MAX_LEPTONS/2;m++) M_Index[m] = 0;
	for(int e=0;e<MAX_LEPTONS/2;e++) E_Index[e] = 0;
	for(int l=0;l<MAX_LEPTONS/2*2;l++) L_Index[l] = 0;
	for(int j=0;j<MAX_PHOTONS;j++) J_Index[j] = 0;
	for(int p=0;p<MAX_PHOTONS;p++) P_Index[p] = 0;
	for(int p=0;p<MAX_PHOTONS;p++) P_Index_FO[p] = 0;
	for(int p=0;p<MAX_PHOTONS;p++) P_Index_NoElectronVeto[p] = 0;
	for(int p=0;p<MAX_PHOTONS;p++) P_Index_TIGHT[p] = 0;

        int NMuons = 0;
	int NElectrons = 0;
	int NLeptons = 0;
	int NJets = 0;
        int NPhotons = 0;
        int NPhotons_FO = 0;
        int NPhotons_NoElectronVeto = 0;
        int NPhotons_TIGHT = 0;
        float Zmass = 0.;

       	RecoLeptonSelection_low_pT_muons(EvtInfo, LepInfo, NMuons, M_Index, NElectrons, E_Index, NLeptons, L_Index);
       	RecoJetSelection(LepInfo, JetInfo, PhotonInfo, NMuons, M_Index, NElectrons, E_Index, NJets, J_Index, NPhotons, P_Index);
	RecoPhotonSelectionFO_NoPtCut(LepInfo, PhotonInfo, NMuons, M_Index, NElectrons, E_Index, NPhotons_FO, P_Index_FO, EvtInfo.RhoPU[0]);
	RecoPhotonSelectionNoElectronVeto_NoPtCut(LepInfo, PhotonInfo, NMuons, M_Index, NElectrons, E_Index, NPhotons_NoElectronVeto, P_Index_NoElectronVeto, EvtInfo.RhoPU[0]);
	RecoPhotonSelectionTIGHT_NoPtCut(LepInfo, PhotonInfo, NMuons, M_Index, NElectrons, E_Index, NPhotons_TIGHT, P_Index_TIGHT, EvtInfo.RhoPU[0]);

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


	if(NMuons == 2 && ( (NPhotons_FO == 1 && NPhotons_NoElectronVeto == 0) || (NPhotons_FO == 0 && NPhotons_NoElectronVeto == 1)) ){ //if1
	 for(int g=0;g<NPhotons_FO;g++) { // loop on photons
            gammatight_.SetPtEtaPhiM(PhotonInfo.Pt[P_Index_FO[g]],PhotonInfo.Eta[P_Index_FO[g]],PhotonInfo.Phi[P_Index_FO[g]],0);

	    for(int mu=0;mu<NMuons;mu++) { //loop on muons
	      if (mu == 0) muontight1_.SetPtEtaPhiM(LepInfo.Pt[M_Index[mu]],LepInfo.Eta[M_Index[mu]],LepInfo.Phi[M_Index[mu]],MUON_MASS);
	      if (mu == 1) muontight2_.SetPtEtaPhiM(LepInfo.Pt[M_Index[mu]],LepInfo.Eta[M_Index[mu]],LepInfo.Phi[M_Index[mu]],MUON_MASS);
	     } //muon loop end
  	     mumu4v =  muontight1_ + muontight2_;
 	     z4v = muontight1_ + muontight2_  +  gammatight_ ;
             Zmass = z4v.M();


             if(mumu4v.M() + Zmass < 180 && mumu4v.M() > 35){
             h_Zmass_Inclusive_noMuMuCut_noPtCut_noNJetsCut_FO->Fill(Zmass);
             if(PhotonInfo.Pt[P_Index_FO[g]]>30){
                 h_Zmass_Inclusive_noMuMuCut_noNJetsCut_FO->Fill(Zmass);
                 for(unsigned int i=0; i<5; i++){
                  for(unsigned int k=0; k<5; k++){
		    if(
		       PhotonInfo.Eta[P_Index_FO[g]] >= (Eta_Min + i * (Eta_Max - Eta_Min)/ 5) && PhotonInfo.Eta[P_Index_FO[g]] < (Eta_Min + (i+1) * (Eta_Max - Eta_Min) / 5) &&
		       PhotonInfo.Pt[P_Index_FO[g]] >= (PT_Min + k * (PT_Max - PT_Min)/ 5) && PhotonInfo.Pt[P_Index_FO[g]] < (PT_Min + (k+1) * (PT_Max - PT_Min) / 5)
		       )  h_Zmass_noMuMuCut_noNJetsCut_FO[i][k]->Fill(Zmass);
		  }
	         }
	     }
             if(NJets >=4 && PhotonInfo.Pt[P_Index_FO[g]]>30){
                 h_Zmass_Inclusive_noMuMuCut_FO->Fill(Zmass);
                 for(unsigned int i=0; i<5; i++){
                  for(unsigned int k=0; k<5; k++){
		    if(
		       PhotonInfo.Eta[P_Index_FO[g]] >= (Eta_Min + i * (Eta_Max - Eta_Min)/ 5) && PhotonInfo.Eta[P_Index_FO[g]] < (Eta_Min + (i+1) * (Eta_Max - Eta_Min) / 5) &&
		       PhotonInfo.Pt[P_Index_FO[g]] >= (PT_Min + k * (PT_Max - PT_Min)/ 5) && PhotonInfo.Pt[P_Index_FO[g]] < (PT_Min + (k+1) * (PT_Max - PT_Min) / 5)
		       )  h_Zmass_noMuMuCut_FO[i][k]->Fill(Zmass);
		  }
	         }
	     }
	     }

             if(mumu4v.M() < 80 && mumu4v.M() > 40){
              h_Zmass_Inclusive_noPtCut_noNJetsCut_FO->Fill(Zmass);
              if(PhotonInfo.Pt[P_Index_FO[g]]>30){
                 h_Zmass_Inclusive_noNJetsCut_FO->Fill(Zmass);
                 for(unsigned int i=0; i<5; i++){
                  for(unsigned int k=0; k<5; k++){
		    if(
		       PhotonInfo.Eta[P_Index_FO[g]] >= (Eta_Min + i * (Eta_Max - Eta_Min)/ 5) && PhotonInfo.Eta[P_Index_FO[g]] < (Eta_Min + (i+1) * (Eta_Max - Eta_Min) / 5) &&
		       PhotonInfo.Pt[P_Index_FO[g]] >= (PT_Min + k * (PT_Max - PT_Min)/ 5) && PhotonInfo.Pt[P_Index_FO[g]] < (PT_Min + (k+1) * (PT_Max - PT_Min) / 5)
		       )  h_Zmass_noNJetsCut_FO[i][k]->Fill(Zmass);
		  }
	         }
	      }
              if(NJets >=4 && PhotonInfo.Pt[P_Index_FO[g]]>30){
                 h_Zmass_Inclusive_FO->Fill(Zmass);
                 for(unsigned int i=0; i<5; i++){
                  for(unsigned int k=0; k<5; k++){
		    if(
		       PhotonInfo.Eta[P_Index_FO[g]] >= (Eta_Min + i * (Eta_Max - Eta_Min)/ 5) && PhotonInfo.Eta[P_Index_FO[g]] < (Eta_Min + (i+1) * (Eta_Max - Eta_Min) / 5) &&
		       PhotonInfo.Pt[P_Index_FO[g]] >= (PT_Min + k * (PT_Max - PT_Min)/ 5) && PhotonInfo.Pt[P_Index_FO[g]] < (PT_Min + (k+1) * (PT_Max - PT_Min) / 5)
		       )  h_Zmass_FO[i][k]->Fill(Zmass);
		  }
	         }
	      }
 	      if(Zmass < 105 && Zmass > 75) {
	        if(NJets >=4 && PhotonInfo.Pt[P_Index_FO[g]]>30)Denominator_Inclusive->Fill(0.);
	        if(PhotonInfo.Pt[P_Index_FO[g]]> 30){ 
                 Denominator_NVTX->Fill(NVertices);
                 Denominator_NJets->Fill(NJets);
                 Denominator_PT->Fill(PhotonInfo.Pt[P_Index_FO[g]]);
                 Denominator_Eta->Fill(PhotonInfo.Eta[P_Index_FO[g]]);
                 Denominator_Eta_PT->Fill(PhotonInfo.Eta[P_Index_FO[g]],PhotonInfo.Pt[P_Index_FO[g]]);
		}
              }
	     }



	 } //photon loop

	 for(int g=0;g<NPhotons_NoElectronVeto;g++) { // loop on photons
            gammatight_.SetPtEtaPhiM(PhotonInfo.Pt[P_Index_NoElectronVeto[g]],PhotonInfo.Eta[P_Index_NoElectronVeto[g]],PhotonInfo.Phi[P_Index_NoElectronVeto[g]],0);

	    for(int mu=0;mu<NMuons;mu++) { //loop on muons
	      if (mu == 0) muontight1_.SetPtEtaPhiM(LepInfo.Pt[M_Index[mu]],LepInfo.Eta[M_Index[mu]],LepInfo.Phi[M_Index[mu]],MUON_MASS);
	      if (mu == 1) muontight2_.SetPtEtaPhiM(LepInfo.Pt[M_Index[mu]],LepInfo.Eta[M_Index[mu]],LepInfo.Phi[M_Index[mu]],MUON_MASS);
	     } //muon loop end
  	     mumu4v =  muontight1_ + muontight2_;
 	     z4v = muontight1_ + muontight2_  +  gammatight_ ;
             Zmass = z4v.M();

             if(mumu4v.M() + Zmass < 180 && mumu4v.M() > 35){
             h_Zmass_Inclusive_noMuMuCut_noPtCut_noNJetsCut_NoElectronVeto->Fill(Zmass);
             if(PhotonInfo.Pt[P_Index_NoElectronVeto[g]]>30){
                 h_Zmass_Inclusive_noMuMuCut_noNJetsCut_NoElectronVeto->Fill(Zmass);
                 for(unsigned int i=0; i<5; i++){
                  for(unsigned int k=0; k<5; k++){
		    if(
		       PhotonInfo.Eta[P_Index_NoElectronVeto[g]] >= (Eta_Min + i * (Eta_Max - Eta_Min)/ 5) && PhotonInfo.Eta[P_Index_NoElectronVeto[g]] < (Eta_Min + (i+1) * (Eta_Max - Eta_Min) / 5) &&
		       PhotonInfo.Pt[P_Index_NoElectronVeto[g]] >= (PT_Min + k * (PT_Max - PT_Min)/ 5) && PhotonInfo.Pt[P_Index_NoElectronVeto[g]] < (PT_Min + (k+1) * (PT_Max - PT_Min) / 5)
		       )  h_Zmass_noMuMuCut_noNJetsCut_NoElectronVeto[i][k]->Fill(Zmass);
		  }
	         }
	     }
             if(NJets >=4 && PhotonInfo.Pt[P_Index_NoElectronVeto[g]]>30){
                 h_Zmass_Inclusive_noMuMuCut_NoElectronVeto->Fill(Zmass);
                 for(unsigned int i=0; i<5; i++){
                  for(unsigned int k=0; k<5; k++){
		    if(
		       PhotonInfo.Eta[P_Index_NoElectronVeto[g]] >= (Eta_Min + i * (Eta_Max - Eta_Min)/ 5) && PhotonInfo.Eta[P_Index_NoElectronVeto[g]] < (Eta_Min + (i+1) * (Eta_Max - Eta_Min) / 5) &&
		       PhotonInfo.Pt[P_Index_NoElectronVeto[g]] >= (PT_Min + k * (PT_Max - PT_Min)/ 5) && PhotonInfo.Pt[P_Index_NoElectronVeto[g]] < (PT_Min + (k+1) * (PT_Max - PT_Min) / 5)
		       )  h_Zmass_noMuMuCut_NoElectronVeto[i][k]->Fill(Zmass);
		  }
	         }
	     }
	     }

             if(mumu4v.M() < 80 && mumu4v.M() > 40){
              h_Zmass_Inclusive_noPtCut_noNJetsCut_NoElectronVeto->Fill(Zmass);
              if(PhotonInfo.Pt[P_Index_NoElectronVeto[g]]>30){
                 h_Zmass_Inclusive_noNJetsCut_NoElectronVeto->Fill(Zmass);
                 for(unsigned int i=0; i<5; i++){
                  for(unsigned int k=0; k<5; k++){
		    if(
		       PhotonInfo.Eta[P_Index_NoElectronVeto[g]] >= (Eta_Min + i * (Eta_Max - Eta_Min)/ 5) && PhotonInfo.Eta[P_Index_NoElectronVeto[g]] < (Eta_Min + (i+1) * (Eta_Max - Eta_Min) / 5) &&
		       PhotonInfo.Pt[P_Index_NoElectronVeto[g]] >= (PT_Min + k * (PT_Max - PT_Min)/ 5) && PhotonInfo.Pt[P_Index_NoElectronVeto[g]] < (PT_Min + (k+1) * (PT_Max - PT_Min) / 5)
		       )  h_Zmass_noNJetsCut_NoElectronVeto[i][k]->Fill(Zmass);
		  }
	         }
	      }
              if(NJets >=4 && PhotonInfo.Pt[P_Index_NoElectronVeto[g]]>30){
                 h_Zmass_Inclusive_NoElectronVeto->Fill(Zmass);
                 for(unsigned int i=0; i<5; i++){
                  for(unsigned int k=0; k<5; k++){
		    if(
		       PhotonInfo.Eta[P_Index_NoElectronVeto[g]] >= (Eta_Min + i * (Eta_Max - Eta_Min)/ 5) && PhotonInfo.Eta[P_Index_NoElectronVeto[g]] < (Eta_Min + (i+1) * (Eta_Max - Eta_Min) / 5) &&
		       PhotonInfo.Pt[P_Index_NoElectronVeto[g]] >= (PT_Min + k * (PT_Max - PT_Min)/ 5) && PhotonInfo.Pt[P_Index_NoElectronVeto[g]] < (PT_Min + (k+1) * (PT_Max - PT_Min) / 5)
		       )  h_Zmass_NoElectronVeto[i][k]->Fill(Zmass);
		  }
	         }
	      }

 	      if(Zmass < 105 && Zmass > 75) {
	        if(NJets >=4 && PhotonInfo.Pt[P_Index_NoElectronVeto[g]]>30)Denominator_Inclusive->Fill(0.);
	        if(PhotonInfo.Pt[P_Index_NoElectronVeto[g]]> 30){ 
                 Denominator_NVTX->Fill(NVertices);
                 Denominator_NJets->Fill(NJets);
                 Denominator_PT->Fill(PhotonInfo.Pt[P_Index_NoElectronVeto[g]]);
                 Denominator_Eta->Fill(PhotonInfo.Eta[P_Index_NoElectronVeto[g]]);
                 Denominator_Eta_PT->Fill(PhotonInfo.Eta[P_Index_NoElectronVeto[g]],PhotonInfo.Pt[P_Index_NoElectronVeto[g]]);
		}
              }
	     }
	 } //photon loop

	} // if1

        if(NMuons == 2 && NPhotons_TIGHT == 1){ //if1
	 for(int g=0;g<NPhotons_TIGHT;g++) { // loop on photons
            gammatight_.SetPtEtaPhiM(PhotonInfo.Pt[P_Index_TIGHT[g]],PhotonInfo.Eta[P_Index_TIGHT[g]],PhotonInfo.Phi[P_Index_TIGHT[g]],0);

	    for(int mu=0;mu<NMuons;mu++) { //loop on muons
	      if (mu == 0) muontight1_.SetPtEtaPhiM(LepInfo.Pt[M_Index[mu]],LepInfo.Eta[M_Index[mu]],LepInfo.Phi[M_Index[mu]],MUON_MASS);
	      if (mu == 1) muontight2_.SetPtEtaPhiM(LepInfo.Pt[M_Index[mu]],LepInfo.Eta[M_Index[mu]],LepInfo.Phi[M_Index[mu]],MUON_MASS);
	     } //muon loop end
  	     mumu4v =  muontight1_ + muontight2_;
 	     z4v = muontight1_ + muontight2_  +  gammatight_ ;
             Zmass = z4v.M();

             if(mumu4v.M() + Zmass < 180 && mumu4v.M() > 35){
             h_Zmass_Inclusive_noMuMuCut_noPtCut_noNJetsCut_TIGHT->Fill(Zmass);
             if(PhotonInfo.Pt[P_Index_TIGHT[g]]>30){
                 h_Zmass_Inclusive_noMuMuCut_noNJetsCut_TIGHT->Fill(Zmass);
                 for(unsigned int i=0; i<5; i++){
                  for(unsigned int k=0; k<5; k++){
		    if(
		       PhotonInfo.Eta[P_Index_TIGHT[g]] >= (Eta_Min + i * (Eta_Max - Eta_Min)/ 5) && PhotonInfo.Eta[P_Index_TIGHT[g]] < (Eta_Min + (i+1) * (Eta_Max - Eta_Min) / 5) &&
		       PhotonInfo.Pt[P_Index_TIGHT[g]] >= (PT_Min + k * (PT_Max - PT_Min)/ 5) && PhotonInfo.Pt[P_Index_TIGHT[g]] < (PT_Min + (k+1) * (PT_Max - PT_Min) / 5)
		       )  h_Zmass_noMuMuCut_noNJetsCut_TIGHT[i][k]->Fill(Zmass);
		  }
	         }
	     }
             if(NJets >=4 && PhotonInfo.Pt[P_Index_TIGHT[g]]>30){
                 h_Zmass_Inclusive_noMuMuCut_TIGHT->Fill(Zmass);
                 for(unsigned int i=0; i<5; i++){
                  for(unsigned int k=0; k<5; k++){
		    if(
		       PhotonInfo.Eta[P_Index_TIGHT[g]] >= (Eta_Min + i * (Eta_Max - Eta_Min)/ 5) && PhotonInfo.Eta[P_Index_TIGHT[g]] < (Eta_Min + (i+1) * (Eta_Max - Eta_Min) / 5) &&
		       PhotonInfo.Pt[P_Index_TIGHT[g]] >= (PT_Min + k * (PT_Max - PT_Min)/ 5) && PhotonInfo.Pt[P_Index_TIGHT[g]] < (PT_Min + (k+1) * (PT_Max - PT_Min) / 5)
		       )  h_Zmass_noMuMuCut_TIGHT[i][k]->Fill(Zmass);
		  }
	         }
	     }
	     }

             if(mumu4v.M() < 80 && mumu4v.M() > 40){
              h_Zmass_Inclusive_noPtCut_noNJetsCut_TIGHT->Fill(Zmass);
              if(PhotonInfo.Pt[P_Index_TIGHT[g]]> 30){
                 h_Zmass_Inclusive_noNJetsCut_TIGHT->Fill(Zmass);
                 for(unsigned int i=0; i<5; i++){
                  for(unsigned int k=0; k<5; k++){
		    if(
		       PhotonInfo.Eta[P_Index_TIGHT[g]] >= (Eta_Min + i * (Eta_Max - Eta_Min)/ 5) && PhotonInfo.Eta[P_Index_TIGHT[g]] < (Eta_Min + (i+1) * (Eta_Max - Eta_Min) / 5) &&
		       PhotonInfo.Pt[P_Index_TIGHT[g]] >= (PT_Min + k * (PT_Max - PT_Min)/ 5) && PhotonInfo.Pt[P_Index_TIGHT[g]] < (PT_Min + (k+1) * (PT_Max - PT_Min) / 5)
		       )  h_Zmass_noNJetsCut_TIGHT[i][k]->Fill(Zmass);
		  }
	         }
	      }
              if(NJets >=4 && PhotonInfo.Pt[P_Index_TIGHT[g]]> 30){
                 h_Zmass_Inclusive_TIGHT->Fill(Zmass);
                 for(unsigned int i=0; i<5; i++){
                  for(unsigned int k=0; k<5; k++){
		    if(
		       PhotonInfo.Eta[P_Index_TIGHT[g]] >= (Eta_Min + i * (Eta_Max - Eta_Min)/ 5) && PhotonInfo.Eta[P_Index_TIGHT[g]] < (Eta_Min + (i+1) * (Eta_Max - Eta_Min) / 5) &&
		       PhotonInfo.Pt[P_Index_TIGHT[g]] >= (PT_Min + k * (PT_Max - PT_Min)/ 5) && PhotonInfo.Pt[P_Index_TIGHT[g]] < (PT_Min + (k+1) * (PT_Max - PT_Min) / 5)
		       )  h_Zmass_TIGHT[i][k]->Fill(Zmass);
		  }
	         }
	      }
 	      if(Zmass < 105 && Zmass > 75) {
	          if(NJets >=4 && PhotonInfo.Pt[P_Index_TIGHT[g]]> 30)Numerator_Inclusive->Fill(0.);
	          if(PhotonInfo.Pt[P_Index_TIGHT[g]]> 30){
                   Numerator_NVTX->Fill(NVertices);
                   Numerator_NJets->Fill(NJets);
                   Numerator_PT->Fill(PhotonInfo.Pt[P_Index_TIGHT[g]]);
                   Numerator_Eta->Fill(PhotonInfo.Eta[P_Index_TIGHT[g]]);
                   Numerator_Eta_PT->Fill(PhotonInfo.Eta[P_Index_TIGHT[g]],PhotonInfo.Pt[P_Index_TIGHT[g]]);
		  }
              }
	     }
	 } //photon loop
	} // if1





       } //event loop end




       ////////////////////////////
       //  Computation after loops
       ////////////////////////////

       TFile* file_TPResults = new TFile("TagAndProbeEfficiencyResults.root","RECREATE");
       file_TPResults->cd();



       h_Zmass_Inclusive_FO->Write();
       h_Zmass_Inclusive_FO = 0;
       delete h_Zmass_Inclusive_FO;

       h_Zmass_Inclusive_NoElectronVeto->Write();
       h_Zmass_Inclusive_NoElectronVeto = 0;
       delete h_Zmass_Inclusive_NoElectronVeto;

       h_Zmass_Inclusive_TIGHT->Write();
       h_Zmass_Inclusive_TIGHT = 0;
       delete h_Zmass_Inclusive_TIGHT;



       h_Zmass_Inclusive_noPtCut_noNJetsCut_FO->Write();
       h_Zmass_Inclusive_noPtCut_noNJetsCut_FO = 0;
       delete h_Zmass_Inclusive_noPtCut_noNJetsCut_FO;

       h_Zmass_Inclusive_noPtCut_noNJetsCut_NoElectronVeto->Write();
       h_Zmass_Inclusive_noPtCut_noNJetsCut_NoElectronVeto = 0;
       delete h_Zmass_Inclusive_noPtCut_noNJetsCut_NoElectronVeto;

       h_Zmass_Inclusive_noPtCut_noNJetsCut_TIGHT->Write();
       h_Zmass_Inclusive_noPtCut_noNJetsCut_TIGHT = 0;
       delete h_Zmass_Inclusive_noPtCut_noNJetsCut_TIGHT;



       h_Zmass_Inclusive_noNJetsCut_FO->Write();
       h_Zmass_Inclusive_noNJetsCut_FO = 0;
       delete h_Zmass_Inclusive_noNJetsCut_FO;

       h_Zmass_Inclusive_noNJetsCut_NoElectronVeto->Write();
       h_Zmass_Inclusive_noNJetsCut_NoElectronVeto = 0;
       delete h_Zmass_Inclusive_noNJetsCut_NoElectronVeto;

       h_Zmass_Inclusive_noNJetsCut_TIGHT->Write();
       h_Zmass_Inclusive_noNJetsCut_TIGHT = 0;
       delete h_Zmass_Inclusive_noNJetsCut_TIGHT;





       h_Zmass_Inclusive_noMuMuCut_FO->Write();
       h_Zmass_Inclusive_noMuMuCut_FO = 0;
       delete h_Zmass_Inclusive_noMuMuCut_FO;

       h_Zmass_Inclusive_noMuMuCut_NoElectronVeto->Write();
       h_Zmass_Inclusive_noMuMuCut_NoElectronVeto = 0;
       delete h_Zmass_Inclusive_noMuMuCut_NoElectronVeto;

       h_Zmass_Inclusive_noMuMuCut_TIGHT->Write();
       h_Zmass_Inclusive_noMuMuCut_TIGHT = 0;
       delete h_Zmass_Inclusive_noMuMuCut_TIGHT;



       h_Zmass_Inclusive_noMuMuCut_noPtCut_noNJetsCut_FO->Write();
       h_Zmass_Inclusive_noMuMuCut_noPtCut_noNJetsCut_FO = 0;
       delete h_Zmass_Inclusive_noMuMuCut_noPtCut_noNJetsCut_FO;

       h_Zmass_Inclusive_noMuMuCut_noPtCut_noNJetsCut_NoElectronVeto->Write();
       h_Zmass_Inclusive_noMuMuCut_noPtCut_noNJetsCut_NoElectronVeto = 0;
       delete h_Zmass_Inclusive_noMuMuCut_noPtCut_noNJetsCut_NoElectronVeto;

       h_Zmass_Inclusive_noMuMuCut_noPtCut_noNJetsCut_TIGHT->Write();
       h_Zmass_Inclusive_noMuMuCut_noPtCut_noNJetsCut_TIGHT = 0;
       delete h_Zmass_Inclusive_noMuMuCut_noPtCut_noNJetsCut_TIGHT;



       h_Zmass_Inclusive_noMuMuCut_noNJetsCut_FO->Write();
       h_Zmass_Inclusive_noMuMuCut_noNJetsCut_FO = 0;
       delete h_Zmass_Inclusive_noMuMuCut_noNJetsCut_FO;

       h_Zmass_Inclusive_noMuMuCut_noNJetsCut_NoElectronVeto->Write();
       h_Zmass_Inclusive_noMuMuCut_noNJetsCut_NoElectronVeto = 0;
       delete h_Zmass_Inclusive_noMuMuCut_noNJetsCut_NoElectronVeto;

       h_Zmass_Inclusive_noMuMuCut_noNJetsCut_TIGHT->Write();
       h_Zmass_Inclusive_noMuMuCut_noNJetsCut_TIGHT = 0;
       delete h_Zmass_Inclusive_noMuMuCut_noNJetsCut_TIGHT;





       for(unsigned int i=0; i<5; i++){
        for(unsigned int k=0; k<5; k++){
          h_Zmass_NoElectronVeto[i][k]->Write();
          h_Zmass_NoElectronVeto[i][k] = 0;
          delete h_Zmass_NoElectronVeto[i][k];

          h_Zmass_FO[i][k]->Write();
          h_Zmass_FO[i][k] = 0;
          delete h_Zmass_FO[i][k];

          h_Zmass_TIGHT[i][k]->Write();
          h_Zmass_TIGHT[i][k] = 0;
          delete h_Zmass_TIGHT[i][k];


          h_Zmass_noNJetsCut_NoElectronVeto[i][k]->Write();
          h_Zmass_noNJetsCut_NoElectronVeto[i][k] = 0;
          delete h_Zmass_noNJetsCut_NoElectronVeto[i][k];

          h_Zmass_noNJetsCut_FO[i][k]->Write();
          h_Zmass_noNJetsCut_FO[i][k] = 0;
          delete h_Zmass_noNJetsCut_FO[i][k];

          h_Zmass_noNJetsCut_TIGHT[i][k]->Write();
          h_Zmass_noNJetsCut_TIGHT[i][k] = 0;
          delete h_Zmass_noNJetsCut_TIGHT[i][k];





          h_Zmass_noMuMuCut_NoElectronVeto[i][k]->Write();
          h_Zmass_noMuMuCut_NoElectronVeto[i][k] = 0;
          delete h_Zmass_noMuMuCut_NoElectronVeto[i][k];

          h_Zmass_noMuMuCut_FO[i][k]->Write();
          h_Zmass_noMuMuCut_FO[i][k] = 0;
          delete h_Zmass_noMuMuCut_FO[i][k];

          h_Zmass_noMuMuCut_TIGHT[i][k]->Write();
          h_Zmass_noMuMuCut_TIGHT[i][k] = 0;
          delete h_Zmass_noMuMuCut_TIGHT[i][k];


          h_Zmass_noMuMuCut_noNJetsCut_NoElectronVeto[i][k]->Write();
          h_Zmass_noMuMuCut_noNJetsCut_NoElectronVeto[i][k] = 0;
          delete h_Zmass_noMuMuCut_noNJetsCut_NoElectronVeto[i][k];

          h_Zmass_noMuMuCut_noNJetsCut_FO[i][k]->Write();
          h_Zmass_noMuMuCut_noNJetsCut_FO[i][k] = 0;
          delete h_Zmass_noMuMuCut_noNJetsCut_FO[i][k];

          h_Zmass_noMuMuCut_noNJetsCut_TIGHT[i][k]->Write();
          h_Zmass_noMuMuCut_noNJetsCut_TIGHT[i][k] = 0;
          delete h_Zmass_noMuMuCut_noNJetsCut_TIGHT[i][k];




	}
       }





       for(unsigned int i=0; i<Eta_N_bins; i++){
          float num_s = (float)Numerator_Eta->GetBinContent(i+1);
          float den_s = (float)Denominator_Eta->GetBinContent(i+1);
          float eff_s = 0.;
          float err_s = 0.;
          if(den_s != 0.) {
            eff_s = num_s/den_s;
            err_s = (sqrt(num_s*(1-(num_s/den_s)))/den_s);
          }
          EfficiencyRatio_Eta->SetBinContent(i+1, eff_s);
          EfficiencyRatio_Eta->SetBinError(i+1, err_s);
       }

       Numerator_Eta->Write();
       Numerator_Eta = 0;
       delete Numerator_Eta;

       Denominator_Eta->Write();
       Denominator_Eta = 0;
       delete Denominator_Eta;

       EfficiencyRatio_Eta->Write();
       EfficiencyRatio_Eta = 0;
       delete EfficiencyRatio_Eta;


       for(unsigned int i=0; i<PT_N_bins; i++){
          float num_s = (float)Numerator_PT->GetBinContent(i+1);
          float den_s = (float)Denominator_PT->GetBinContent(i+1);
          float eff_s = 0.;
          float err_s = 0.;
          if(den_s != 0.) {
            eff_s = num_s/den_s;
            err_s = (sqrt(num_s*(1-(num_s/den_s)))/den_s);
          }
          EfficiencyRatio_PT->SetBinContent(i+1, eff_s);
          EfficiencyRatio_PT->SetBinError(i+1, err_s);
       }

       Numerator_PT->Write();
       Numerator_PT = 0;
       delete Numerator_PT;

       Denominator_PT->Write();
       Denominator_PT = 0;
       delete Denominator_PT;

       EfficiencyRatio_PT->Write();
       EfficiencyRatio_PT = 0;
       delete EfficiencyRatio_PT;



       for(unsigned int i=0; i<Eta_N_bins; i++){
        for(unsigned int k=0; k<PT_N_bins; k++){
          float num_s = (float)Numerator_Eta_PT->GetBinContent(i+1,k+1);
          float den_s = (float)Denominator_Eta_PT->GetBinContent(i+1,k+1);
          float eff_s = 0.;
          float err_s = 0.;
          if(den_s != 0.) {
            eff_s = num_s/den_s;
            err_s = (sqrt(num_s*(1-(num_s/den_s)))/den_s);
          }
          EfficiencyRatio_Eta_PT->SetBinContent(i+1,k+1, eff_s);
	  EfficiencyRatio_Eta_PT->SetBinError(i+1,k+1, err_s);
	} 

      }

       Numerator_Eta_PT->Write();
       Numerator_Eta_PT = 0;
       delete Numerator_Eta_PT;

       Denominator_Eta_PT->Write();
       Denominator_Eta_PT = 0;
       delete Denominator_Eta_PT;

       EfficiencyRatio_Eta_PT->Write();
       EfficiencyRatio_Eta_PT = 0;
       delete EfficiencyRatio_Eta_PT;


       for(unsigned int i=0; i<NJets_N_bins; i++){
          float num_s = (float)Numerator_NJets->GetBinContent(i+1);
          float den_s = (float)Denominator_NJets->GetBinContent(i+1);
          float eff_s = 0.;
          float err_s = 0.;
          if(den_s != 0.) {
            eff_s = num_s/den_s;
            err_s = (sqrt(num_s*(1-(num_s/den_s)))/den_s);
          }
          EfficiencyRatio_NJets->SetBinContent(i+1, eff_s);
          EfficiencyRatio_NJets->SetBinError(i+1, err_s);
       }

       Numerator_NJets->Write();
       Numerator_NJets = 0;
       delete Numerator_NJets;

       Denominator_NJets->Write();
       Denominator_NJets = 0;
       delete Denominator_NJets;

       EfficiencyRatio_NJets->Write();
       EfficiencyRatio_NJets = 0;
       delete EfficiencyRatio_NJets;


       for(unsigned int i=0; i<NVTX_N_bins; i++){
          float num_s = (float)Numerator_NVTX->GetBinContent(i+1);
          float den_s = (float)Denominator_NVTX->GetBinContent(i+1);
          float eff_s = 0.;
          float err_s = 0.;
          if(den_s != 0.) {
            eff_s = num_s/den_s;
            err_s = (sqrt(num_s*(1-(num_s/den_s)))/den_s);
          }
          EfficiencyRatio_NVTX->SetBinContent(i+1, eff_s);
          EfficiencyRatio_NVTX->SetBinError(i+1, err_s);
       }

       Numerator_NVTX->Write();
       Numerator_NVTX = 0;
       delete Numerator_NVTX;

       Denominator_NVTX->Write();
       Denominator_NVTX = 0;
       delete Denominator_NVTX;

       EfficiencyRatio_NVTX->Write();
       EfficiencyRatio_NVTX = 0;
       delete EfficiencyRatio_NVTX;


       for(unsigned int i=0; i<Inclusive_N_bins; i++){
          float num_s = (float)Numerator_Inclusive->GetBinContent(i+1);
          float den_s = (float)Denominator_Inclusive->GetBinContent(i+1);
          float eff_s = 0.;
          float err_s = 0.;
          if(den_s != 0.) {
            eff_s = num_s/den_s;
            err_s = (sqrt(num_s*(1-(num_s/den_s)))/den_s);
          }
          EfficiencyRatio_Inclusive->SetBinContent(i+1, eff_s);
          EfficiencyRatio_Inclusive->SetBinError(i+1, err_s);
       }

       Numerator_Inclusive->Write();
       Numerator_Inclusive = 0;
       delete Numerator_Inclusive;

       Denominator_Inclusive->Write();
       Denominator_Inclusive = 0;
       delete Denominator_Inclusive;

       EfficiencyRatio_Inclusive->Write();
       EfficiencyRatio_Inclusive = 0;
       delete EfficiencyRatio_Inclusive;











       file_TPResults->Write();
       file_TPResults->Close();
       delete file_TPResults;








}
