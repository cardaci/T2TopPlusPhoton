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
#include "interface/RecoPhotonSelectionNoElectronVeto.h"
#include "interface/RecoJetSelection.h"
//#include "interface/SolutionOfWNeutrino.h"
//#include "Math.h"
#include "interface/ConstantNumbers.h"
#include "TLorentzVector.h"
#include <string>
#include <iostream>
#include <vector>

void TagAndProbe()
{
    gROOT->ProcessLine(".L interface/setTDRStyle.C");
    gROOT->ProcessLine("setTDRStyle()");
    gStyle->SetPalette(1);

    TChain *root = new TChain("bprimeKit/root");
    //root->Add("/afs/cern.ch/work/c/cardaci/Photon_Run2012A-20Nov2012-v2_190456-193686/*");
    root->Add("/afs/cern.ch/work/c/cardaci/SingleElectron_Run2012A-22Jan2013-v1_190456-193686/*");
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


       TH1F *h_Zmass_Inclusive_NoElectronVeto_Denominator = new TH1F("Zmass_Inclusive_NoElectronVeto_Denominator","Zmass_Inclusive_NoElectronVeto_Denominator",200,0,200);
       TH1F *h_Zmass_Inclusive_NoElectronVeto_Numerator = new TH1F("Zmass_Inclusive_NoElectronVeto_Numerator","Zmass_Inclusive_NoElectronVeto_Numerator",200,0,200);

       TH1F *h_Zmass_Inclusive_noNJetsCut_NoElectronVeto_Denominator = new TH1F("Zmass_Inclusive_noNJetsCut_NoElectronVeto_Denominator","Zmass_Inclusive_noNJetsCut_NoElectronVeto_Denominator",200,0,200);
       TH1F *h_Zmass_Inclusive_noNJetsCut_NoElectronVeto_Numerator = new TH1F("Zmass_Inclusive_noNJetsCut_NoElectronVeto_Numerator","Zmass_Inclusive_noNJetsCut_NoElectronVeto_Numerator",200,0,200);

	
       TLorentzVector gammatight_ , electight_ , z4v ;

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




       TH1F * h_Zmass_NoElectronVeto_Denominator[5][5];
       TH1F * h_Zmass_NoElectronVeto_Numerator[5][5];

       h_Zmass_NoElectronVeto_Denominator[0][0] = new TH1F("Zmass_NoElectronVeto_Denominator_Eta_0_PT_0_Zmass", "Zmass_NoElectronVeto_Denominator_Eta_0_PT_0_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Denominator[1][0] = new TH1F("Zmass_NoElectronVeto_Denominator_Eta_1_PT_0_Zmass", "Zmass_NoElectronVeto_Denominator_Eta_1_PT_0_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Denominator[2][0] = new TH1F("Zmass_NoElectronVeto_Denominator_Eta_2_PT_0_Zmass", "Zmass_NoElectronVeto_Denominator_Eta_2_PT_0_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Denominator[3][0] = new TH1F("Zmass_NoElectronVeto_Denominator_Eta_3_PT_0_Zmass", "Zmass_NoElectronVeto_Denominator_Eta_3_PT_0_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Denominator[4][0] = new TH1F("Zmass_NoElectronVeto_Denominator_Eta_4_PT_0_Zmass", "Zmass_NoElectronVeto_Denominator_Eta_4_PT_0_Zmass",200, 0, 200);

       h_Zmass_NoElectronVeto_Denominator[0][1] = new TH1F("Zmass_NoElectronVeto_Denominator_Eta_0_PT_1_Zmass", "Zmass_NoElectronVeto_Denominator_Eta_0_PT_1_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Denominator[1][1] = new TH1F("Zmass_NoElectronVeto_Denominator_Eta_1_PT_1_Zmass", "Zmass_NoElectronVeto_Denominator_Eta_1_PT_1_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Denominator[2][1] = new TH1F("Zmass_NoElectronVeto_Denominator_Eta_2_PT_1_Zmass", "Zmass_NoElectronVeto_Denominator_Eta_2_PT_1_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Denominator[3][1] = new TH1F("Zmass_NoElectronVeto_Denominator_Eta_3_PT_1_Zmass", "Zmass_NoElectronVeto_Denominator_Eta_3_PT_1_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Denominator[4][1] = new TH1F("Zmass_NoElectronVeto_Denominator_Eta_4_PT_1_Zmass", "Zmass_NoElectronVeto_Denominator_Eta_4_PT_1_Zmass",200, 0, 200);

       h_Zmass_NoElectronVeto_Denominator[0][2] = new TH1F("Zmass_NoElectronVeto_Denominator_Eta_0_PT_2_Zmass", "Zmass_NoElectronVeto_Denominator_Eta_0_PT_2_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Denominator[1][2] = new TH1F("Zmass_NoElectronVeto_Denominator_Eta_1_PT_2_Zmass", "Zmass_NoElectronVeto_Denominator_Eta_1_PT_2_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Denominator[2][2] = new TH1F("Zmass_NoElectronVeto_Denominator_Eta_2_PT_2_Zmass", "Zmass_NoElectronVeto_Denominator_Eta_2_PT_2_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Denominator[3][2] = new TH1F("Zmass_NoElectronVeto_Denominator_Eta_3_PT_2_Zmass", "Zmass_NoElectronVeto_Denominator_Eta_3_PT_2_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Denominator[4][2] = new TH1F("Zmass_NoElectronVeto_Denominator_Eta_4_PT_2_Zmass", "Zmass_NoElectronVeto_Denominator_Eta_4_PT_2_Zmass",200, 0, 200);

       h_Zmass_NoElectronVeto_Denominator[0][3] = new TH1F("Zmass_NoElectronVeto_Denominator_Eta_0_PT_3_Zmass", "Zmass_NoElectronVeto_Denominator_Eta_0_PT_3_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Denominator[1][3] = new TH1F("Zmass_NoElectronVeto_Denominator_Eta_1_PT_3_Zmass", "Zmass_NoElectronVeto_Denominator_Eta_1_PT_3_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Denominator[2][3] = new TH1F("Zmass_NoElectronVeto_Denominator_Eta_2_PT_3_Zmass", "Zmass_NoElectronVeto_Denominator_Eta_2_PT_3_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Denominator[3][3] = new TH1F("Zmass_NoElectronVeto_Denominator_Eta_3_PT_3_Zmass", "Zmass_NoElectronVeto_Denominator_Eta_3_PT_3_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Denominator[4][3] = new TH1F("Zmass_NoElectronVeto_Denominator_Eta_4_PT_3_Zmass", "Zmass_NoElectronVeto_Denominator_Eta_4_PT_3_Zmass",200, 0, 200);

       h_Zmass_NoElectronVeto_Denominator[0][4] = new TH1F("Zmass_NoElectronVeto_Denominator_Eta_0_PT_4_Zmass", "Zmass_NoElectronVeto_Denominator_Eta_0_PT_4_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Denominator[1][4] = new TH1F("Zmass_NoElectronVeto_Denominator_Eta_1_PT_4_Zmass", "Zmass_NoElectronVeto_Denominator_Eta_1_PT_4_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Denominator[2][4] = new TH1F("Zmass_NoElectronVeto_Denominator_Eta_2_PT_4_Zmass", "Zmass_NoElectronVeto_Denominator_Eta_2_PT_4_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Denominator[3][4] = new TH1F("Zmass_NoElectronVeto_Denominator_Eta_3_PT_4_Zmass", "Zmass_NoElectronVeto_Denominator_Eta_3_PT_4_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Denominator[4][4] = new TH1F("Zmass_NoElectronVeto_Denominator_Eta_4_PT_4_Zmass", "Zmass_NoElectronVeto_Denominator_Eta_4_PT_4_Zmass",200, 0, 200);



       h_Zmass_NoElectronVeto_Numerator[0][0] = new TH1F("Zmass_NoElectronVeto_Numerator_Eta_0_PT_0_Zmass", "Zmass_NoElectronVeto_Numerator_Eta_0_PT_0_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Numerator[1][0] = new TH1F("Zmass_NoElectronVeto_Numerator_Eta_1_PT_0_Zmass", "Zmass_NoElectronVeto_Numerator_Eta_1_PT_0_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Numerator[2][0] = new TH1F("Zmass_NoElectronVeto_Numerator_Eta_2_PT_0_Zmass", "Zmass_NoElectronVeto_Numerator_Eta_2_PT_0_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Numerator[3][0] = new TH1F("Zmass_NoElectronVeto_Numerator_Eta_3_PT_0_Zmass", "Zmass_NoElectronVeto_Numerator_Eta_3_PT_0_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Numerator[4][0] = new TH1F("Zmass_NoElectronVeto_Numerator_Eta_4_PT_0_Zmass", "Zmass_NoElectronVeto_Numerator_Eta_4_PT_0_Zmass",200, 0, 200);

       h_Zmass_NoElectronVeto_Numerator[0][1] = new TH1F("Zmass_NoElectronVeto_Numerator_Eta_0_PT_1_Zmass", "Zmass_NoElectronVeto_Numerator_Eta_0_PT_1_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Numerator[1][1] = new TH1F("Zmass_NoElectronVeto_Numerator_Eta_1_PT_1_Zmass", "Zmass_NoElectronVeto_Numerator_Eta_1_PT_1_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Numerator[2][1] = new TH1F("Zmass_NoElectronVeto_Numerator_Eta_2_PT_1_Zmass", "Zmass_NoElectronVeto_Numerator_Eta_2_PT_1_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Numerator[3][1] = new TH1F("Zmass_NoElectronVeto_Numerator_Eta_3_PT_1_Zmass", "Zmass_NoElectronVeto_Numerator_Eta_3_PT_1_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Numerator[4][1] = new TH1F("Zmass_NoElectronVeto_Numerator_Eta_4_PT_1_Zmass", "Zmass_NoElectronVeto_Numerator_Eta_4_PT_1_Zmass",200, 0, 200);

       h_Zmass_NoElectronVeto_Numerator[0][2] = new TH1F("Zmass_NoElectronVeto_Numerator_Eta_0_PT_2_Zmass", "Zmass_NoElectronVeto_Numerator_Eta_0_PT_2_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Numerator[1][2] = new TH1F("Zmass_NoElectronVeto_Numerator_Eta_1_PT_2_Zmass", "Zmass_NoElectronVeto_Numerator_Eta_1_PT_2_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Numerator[2][2] = new TH1F("Zmass_NoElectronVeto_Numerator_Eta_2_PT_2_Zmass", "Zmass_NoElectronVeto_Numerator_Eta_2_PT_2_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Numerator[3][2] = new TH1F("Zmass_NoElectronVeto_Numerator_Eta_3_PT_2_Zmass", "Zmass_NoElectronVeto_Numerator_Eta_3_PT_2_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Numerator[4][2] = new TH1F("Zmass_NoElectronVeto_Numerator_Eta_4_PT_2_Zmass", "Zmass_NoElectronVeto_Numerator_Eta_4_PT_2_Zmass",200, 0, 200);

       h_Zmass_NoElectronVeto_Numerator[0][3] = new TH1F("Zmass_NoElectronVeto_Numerator_Eta_0_PT_3_Zmass", "Zmass_NoElectronVeto_Numerator_Eta_0_PT_3_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Numerator[1][3] = new TH1F("Zmass_NoElectronVeto_Numerator_Eta_1_PT_3_Zmass", "Zmass_NoElectronVeto_Numerator_Eta_1_PT_3_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Numerator[2][3] = new TH1F("Zmass_NoElectronVeto_Numerator_Eta_2_PT_3_Zmass", "Zmass_NoElectronVeto_Numerator_Eta_2_PT_3_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Numerator[3][3] = new TH1F("Zmass_NoElectronVeto_Numerator_Eta_3_PT_3_Zmass", "Zmass_NoElectronVeto_Numerator_Eta_3_PT_3_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Numerator[4][3] = new TH1F("Zmass_NoElectronVeto_Numerator_Eta_4_PT_3_Zmass", "Zmass_NoElectronVeto_Numerator_Eta_4_PT_3_Zmass",200, 0, 200);

       h_Zmass_NoElectronVeto_Numerator[0][4] = new TH1F("Zmass_NoElectronVeto_Numerator_Eta_0_PT_4_Zmass", "Zmass_NoElectronVeto_Numerator_Eta_0_PT_4_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Numerator[1][4] = new TH1F("Zmass_NoElectronVeto_Numerator_Eta_1_PT_4_Zmass", "Zmass_NoElectronVeto_Numerator_Eta_1_PT_4_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Numerator[2][4] = new TH1F("Zmass_NoElectronVeto_Numerator_Eta_2_PT_4_Zmass", "Zmass_NoElectronVeto_Numerator_Eta_2_PT_4_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Numerator[3][4] = new TH1F("Zmass_NoElectronVeto_Numerator_Eta_3_PT_4_Zmass", "Zmass_NoElectronVeto_Numerator_Eta_3_PT_4_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_Numerator[4][4] = new TH1F("Zmass_NoElectronVeto_Numerator_Eta_4_PT_4_Zmass", "Zmass_NoElectronVeto_Numerator_Eta_4_PT_4_Zmass",200, 0, 200);






       TH1F * h_Zmass_NoElectronVeto_noNJetsCut_Denominator[5][5];
       TH1F * h_Zmass_NoElectronVeto_noNJetsCut_Numerator[5][5];

       h_Zmass_NoElectronVeto_noNJetsCut_Denominator[0][0] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_0_PT_0_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_0_PT_0_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Denominator[1][0] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_1_PT_0_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_1_PT_0_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Denominator[2][0] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_2_PT_0_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_2_PT_0_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Denominator[3][0] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_3_PT_0_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_3_PT_0_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Denominator[4][0] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_4_PT_0_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_4_PT_0_Zmass",200, 0, 200);

       h_Zmass_NoElectronVeto_noNJetsCut_Denominator[0][1] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_0_PT_1_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_0_PT_1_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Denominator[1][1] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_1_PT_1_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_1_PT_1_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Denominator[2][1] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_2_PT_1_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_2_PT_1_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Denominator[3][1] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_3_PT_1_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_3_PT_1_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Denominator[4][1] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_4_PT_1_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_4_PT_1_Zmass",200, 0, 200);

       h_Zmass_NoElectronVeto_noNJetsCut_Denominator[0][2] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_0_PT_2_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_0_PT_2_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Denominator[1][2] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_1_PT_2_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_1_PT_2_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Denominator[2][2] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_2_PT_2_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_2_PT_2_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Denominator[3][2] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_3_PT_2_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_3_PT_2_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Denominator[4][2] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_4_PT_2_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_4_PT_2_Zmass",200, 0, 200);

       h_Zmass_NoElectronVeto_noNJetsCut_Denominator[0][3] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_0_PT_3_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_0_PT_3_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Denominator[1][3] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_1_PT_3_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_1_PT_3_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Denominator[2][3] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_2_PT_3_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_2_PT_3_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Denominator[3][3] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_3_PT_3_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_3_PT_3_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Denominator[4][3] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_4_PT_3_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_4_PT_3_Zmass",200, 0, 200);

       h_Zmass_NoElectronVeto_noNJetsCut_Denominator[0][4] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_0_PT_4_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_0_PT_4_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Denominator[1][4] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_1_PT_4_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_1_PT_4_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Denominator[2][4] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_2_PT_4_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_2_PT_4_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Denominator[3][4] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_3_PT_4_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_3_PT_4_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Denominator[4][4] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_4_PT_4_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Denominator_Eta_4_PT_4_Zmass",200, 0, 200);



       h_Zmass_NoElectronVeto_noNJetsCut_Numerator[0][0] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_0_PT_0_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_0_PT_0_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Numerator[1][0] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_1_PT_0_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_1_PT_0_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Numerator[2][0] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_2_PT_0_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_2_PT_0_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Numerator[3][0] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_3_PT_0_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_3_PT_0_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Numerator[4][0] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_4_PT_0_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_4_PT_0_Zmass",200, 0, 200);

       h_Zmass_NoElectronVeto_noNJetsCut_Numerator[0][1] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_0_PT_1_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_0_PT_1_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Numerator[1][1] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_1_PT_1_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_1_PT_1_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Numerator[2][1] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_2_PT_1_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_2_PT_1_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Numerator[3][1] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_3_PT_1_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_3_PT_1_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Numerator[4][1] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_4_PT_1_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_4_PT_1_Zmass",200, 0, 200);

       h_Zmass_NoElectronVeto_noNJetsCut_Numerator[0][2] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_0_PT_2_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_0_PT_2_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Numerator[1][2] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_1_PT_2_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_1_PT_2_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Numerator[2][2] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_2_PT_2_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_2_PT_2_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Numerator[3][2] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_3_PT_2_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_3_PT_2_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Numerator[4][2] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_4_PT_2_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_4_PT_2_Zmass",200, 0, 200);

       h_Zmass_NoElectronVeto_noNJetsCut_Numerator[0][3] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_0_PT_3_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_0_PT_3_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Numerator[1][3] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_1_PT_3_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_1_PT_3_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Numerator[2][3] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_2_PT_3_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_2_PT_3_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Numerator[3][3] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_3_PT_3_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_3_PT_3_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Numerator[4][3] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_4_PT_3_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_4_PT_3_Zmass",200, 0, 200);

       h_Zmass_NoElectronVeto_noNJetsCut_Numerator[0][4] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_0_PT_4_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_0_PT_4_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Numerator[1][4] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_1_PT_4_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_1_PT_4_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Numerator[2][4] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_2_PT_4_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_2_PT_4_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Numerator[3][4] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_3_PT_4_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_3_PT_4_Zmass",200, 0, 200);
       h_Zmass_NoElectronVeto_noNJetsCut_Numerator[4][4] = new TH1F("Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_4_PT_4_Zmass", "Zmass_NoElectronVeto_noNJetsCut_Numerator_Eta_4_PT_4_Zmass",200, 0, 200);













       TH1F * Numerator_NoElectronVeto_NJets = new TH1F ("Numerator_NoElectronVeto_NJets","Numerator_NoElectronVeto_NJets", NJets_N_bins, NJets_Min, NJets_Max);
       TH1F * Denominator_NoElectronVeto_NJets = new TH1F ("Denominator_NoElectronVeto_NJets","Denominator_NoElectronVeto_NJets", NJets_N_bins, NJets_Min, NJets_Max);
       TH1F * FakeRateRatio_NoElectronVeto_NJets = new TH1F ("FakeRateRatio_NoElectronVeto_NJets","FakeRateRatio_NoElectronVeto_NJets", NJets_N_bins, NJets_Min, NJets_Max);


       TH1F * Numerator_NoElectronVeto_Eta = new TH1F ("Numerator_NoElectronVeto_Eta","Numerator_NoElectronVeto_Eta", Eta_N_bins, Eta_Min, Eta_Max);
       TH1F * Denominator_NoElectronVeto_Eta = new TH1F ("Denominator_NoElectronVeto_Eta","Denominator_NoElectronVeto_Eta", Eta_N_bins, Eta_Min, Eta_Max);
       TH1F * FakeRateRatio_NoElectronVeto_Eta = new TH1F ("FakeRateRatio_NoElectronVeto_Eta","FakeRateRatio_NoElectronVeto_Eta", Eta_N_bins, Eta_Min, Eta_Max);

       TH1F * Numerator_NoElectronVeto_PT = new TH1F ("Numerator_NoElectronVeto_PT","Numerator_NoElectronVeto_PT", PT_N_bins, PT_Min, PT_Max);
       TH1F * Denominator_NoElectronVeto_PT = new TH1F ("Denominator_NoElectronVeto_PT","Denominator_NoElectronVeto_PT", PT_N_bins, PT_Min, PT_Max);
       TH1F * FakeRateRatio_NoElectronVeto_PT = new TH1F ("FakeRateRatio_NoElectronVeto_PT","FakeRateRatio_NoElectronVeto_PT", PT_N_bins, PT_Min, PT_Max);


       TH2F * Numerator_NoElectronVeto_Eta_PT = new TH2F ("Numerator_NoElectronVeto_Eta_PT","Numerator_NoElectronVeto_Eta_PT", Eta_N_bins, Eta_Min, Eta_Max, PT_N_bins, PT_Min, PT_Max);
       TH2F * Denominator_NoElectronVeto_Eta_PT = new TH2F ("Denominator_NoElectronVeto_Eta_PT","Denominator_NoElectronVeto_Eta_PT", Eta_N_bins, Eta_Min, Eta_Max, PT_N_bins, PT_Min, PT_Max);
       TH2F * FakeRateRatio_NoElectronVeto_Eta_PT = new TH2F ("FakeRateRatio_NoElectronVeto_Eta_PT","FakeRateRatio_NoElectronVeto_Eta_PT", Eta_N_bins, Eta_Min, Eta_Max, PT_N_bins, PT_Min, PT_Max);

       TH1F * Numerator_NoElectronVeto_NVTX = new TH1F ("Numerator_NoElectronVeto_NVTX","Numerator_NoElectronVeto_NVTX", NVTX_N_bins, NVTX_Min, NVTX_Max);
       TH1F * Denominator_NoElectronVeto_NVTX = new TH1F ("Denominator_NoElectronVeto_NVTX","Denominator_NoElectronVeto_NVTX", NVTX_N_bins, NVTX_Min, NVTX_Max);
       TH1F * FakeRateRatio_NoElectronVeto_NVTX = new TH1F ("FakeRateRatio_NoElectronVeto_NVTX","FakeRateRatio_NoElectronVeto_NVTX", NVTX_N_bins, NVTX_Min, NVTX_Max);

       TH1F * Numerator_NoElectronVeto_Inclusive = new TH1F ("Numerator_NoElectronVeto_Inclusive","Numerator_NoElectronVeto_Inclusive", Inclusive_N_bins, Inclusive_Min, Inclusive_Max);
       TH1F * Denominator_NoElectronVeto_Inclusive = new TH1F ("Denominator_NoElectronVeto_Inclusive","Denominator_NoElectronVeto_Inclusive", Inclusive_N_bins, Inclusive_Min, Inclusive_Max);
       TH1F * FakeRateRatio_NoElectronVeto_Inclusive = new TH1F ("FakeRateRatio_NoElectronVeto_Inclusive","FakeRateRatio_NoElectronVeto_Inclusive", Inclusive_N_bins, Inclusive_Min, Inclusive_Max);



	
       //Event loop begin
       for(int entry=0; entry < root->GetEntries(); entry++) {
        int tot_entries = root->GetEntries();

        root->GetEntry(entry);
	

        if (entry % 500 == 0) cout << "Entry: " << entry << " / " << tot_entries << endl;

   	
	int E_Index[MAX_LEPTONS];
	int M_Index[MAX_LEPTONS];
	int L_Index[MAX_LEPTONS];
	int J_Index[MAX_JETS];
	int P_Index[MAX_PHOTONS];
	int P_Index_NoElectronVeto[MAX_PHOTONS];

	for(int m=0;m<MAX_LEPTONS/2;m++) M_Index[m] = 0;
	for(int e=0;e<MAX_LEPTONS/2;e++) E_Index[e] = 0;
	for(int l=0;l<MAX_LEPTONS/2*2;l++) L_Index[l] = 0;
	for(int j=0;j<MAX_PHOTONS;j++) J_Index[j] = 0;
	for(int p=0;p<MAX_PHOTONS;p++) P_Index[p] = 0;
	for(int p=0;p<MAX_PHOTONS;p++) P_Index_NoElectronVeto[p] = 0;

        int NMuons = 0;
	int NElectrons = 0;
	int NLeptons = 0;
	int NJets = 0;
        int NPhotons = 0;
        int NPhotons_NoElectronVeto = 0;
        float Zmass = 0.;

       	RecoLeptonSelection(EvtInfo, LepInfo, NMuons, M_Index, NElectrons, E_Index, NLeptons, L_Index);
       	RecoJetSelection(LepInfo, JetInfo, PhotonInfo, NMuons, M_Index, NElectrons, E_Index, NJets, J_Index, NPhotons, P_Index);
	RecoPhotonSelectionNoElectronVeto(LepInfo, PhotonInfo, NMuons, M_Index, NElectrons, E_Index, NPhotons_NoElectronVeto, P_Index_NoElectronVeto, EvtInfo.RhoPU[0]);

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

        if(NElectrons == 1 && NPhotons_NoElectronVeto == 1){ //if1
	 for(int g=0;g<NPhotons_NoElectronVeto;g++) { // loop on photons
            gammatight_.SetPtEtaPhiM(PhotonInfo.Pt[P_Index_NoElectronVeto[g]],PhotonInfo.Eta[P_Index_NoElectronVeto[g]],PhotonInfo.Phi[P_Index_NoElectronVeto[g]],0);
	    for(int el=0;el<NElectrons;el++) { //loop on electrons
	       electight_.SetPtEtaPhiM(LepInfo.Pt[E_Index[el]],LepInfo.Eta[E_Index[el]],LepInfo.Phi[E_Index[el]],ELECTRON_MASS);
	       z4v = electight_  +  gammatight_ ;
               Zmass = z4v.M();
	     } //elec loop end
             h_Zmass_Inclusive_noNJetsCut_NoElectronVeto_Denominator->Fill(Zmass);
             for(unsigned int i=0; i<5; i++){
              for(unsigned int k=0; k<5; k++){
		  if(
		     PhotonInfo.Eta[P_Index_NoElectronVeto[g]] >= (Eta_Min + i * (Eta_Max - Eta_Min)/ 5) && PhotonInfo.Eta[P_Index_NoElectronVeto[g]] < (Eta_Min + (i+1) * (Eta_Max - Eta_Min) / 5) &&
		     PhotonInfo.Pt[P_Index_NoElectronVeto[g]] >= (PT_Min + k * (PT_Max - PT_Min)/ 5) && PhotonInfo.Pt[P_Index_NoElectronVeto[g]] < (PT_Min + (k+1) * (PT_Max - PT_Min) / 5)
		     )  h_Zmass_NoElectronVeto_noNJetsCut_Denominator[i][k]->Fill(Zmass);
	      }
	     }
	     if(NJets >=4){
               h_Zmass_Inclusive_NoElectronVeto_Denominator->Fill(Zmass);
               for(unsigned int i=0; i<5; i++){
                for(unsigned int k=0; k<5; k++){
		  if(
		     PhotonInfo.Eta[P_Index_NoElectronVeto[g]] >= (Eta_Min + i * (Eta_Max - Eta_Min)/ 5) && PhotonInfo.Eta[P_Index_NoElectronVeto[g]] < (Eta_Min + (i+1) * (Eta_Max - Eta_Min) / 5) &&
		     PhotonInfo.Pt[P_Index_NoElectronVeto[g]] >= (PT_Min + k * (PT_Max - PT_Min)/ 5) && PhotonInfo.Pt[P_Index_NoElectronVeto[g]] < (PT_Min + (k+1) * (PT_Max - PT_Min) / 5)
		     )  h_Zmass_NoElectronVeto_Denominator[i][k]->Fill(Zmass);
		}
	       }
	     }
 	     if(Zmass < 105 && Zmass > 75) {
	        if(NJets >=4)Denominator_NoElectronVeto_Inclusive->Fill(0.);
                Denominator_NoElectronVeto_NVTX->Fill(NVertices);
                Denominator_NoElectronVeto_NJets->Fill(NJets);
                Denominator_NoElectronVeto_PT->Fill(PhotonInfo.Pt[P_Index_NoElectronVeto[g]]);
                Denominator_NoElectronVeto_Eta->Fill(PhotonInfo.Eta[P_Index_NoElectronVeto[g]]);
                Denominator_NoElectronVeto_Eta_PT->Fill(PhotonInfo.Eta[P_Index_NoElectronVeto[g]],PhotonInfo.Pt[P_Index_NoElectronVeto[g]]);
             }	     

             if(PhotonInfo.passelectronveto[P_Index_NoElectronVeto[g]] == true){
               h_Zmass_Inclusive_noNJetsCut_NoElectronVeto_Numerator->Fill(Zmass);
               for(unsigned int i=0; i<5; i++){
                 for(unsigned int k=0; k<5; k++){
		   if(
		      PhotonInfo.Eta[P_Index_NoElectronVeto[g]] >= (Eta_Min + i * (Eta_Max - Eta_Min)/ 5) && PhotonInfo.Eta[P_Index_NoElectronVeto[g]] < (Eta_Min + (i+1) * (Eta_Max - Eta_Min) / 5) &&
		      PhotonInfo.Pt[P_Index_NoElectronVeto[g]] >= (PT_Min + k * (PT_Max - PT_Min)/ 5) && PhotonInfo.Pt[P_Index_NoElectronVeto[g]] < (PT_Min + (k+1) * (PT_Max - PT_Min) / 5)
		      )  h_Zmass_NoElectronVeto_noNJetsCut_Numerator[i][k]->Fill(Zmass);
		 }
	       }
               if(NJets >=4){
                 h_Zmass_Inclusive_NoElectronVeto_Numerator->Fill(Zmass);
                 for(unsigned int i=0; i<5; i++){
                    for(unsigned int k=0; k<5; k++){
		     if(
		        PhotonInfo.Eta[P_Index_NoElectronVeto[g]] >= (Eta_Min + i * (Eta_Max - Eta_Min)/ 5) && PhotonInfo.Eta[P_Index_NoElectronVeto[g]] < (Eta_Min + (i+1) * (Eta_Max - Eta_Min) / 5) &&
		        PhotonInfo.Pt[P_Index_NoElectronVeto[g]] >= (PT_Min + k * (PT_Max - PT_Min)/ 5) && PhotonInfo.Pt[P_Index_NoElectronVeto[g]] < (PT_Min + (k+1) * (PT_Max - PT_Min) / 5)
		        )  h_Zmass_NoElectronVeto_Numerator[i][k]->Fill(Zmass);
		    }
	         }
	       }
 	       if(Zmass < 105 && Zmass > 75) {
                  if(NJets >=4)Numerator_NoElectronVeto_Inclusive->Fill(0.);
                  Numerator_NoElectronVeto_NVTX->Fill(NVertices);
                  Numerator_NoElectronVeto_NJets->Fill(NJets);
                  Numerator_NoElectronVeto_PT->Fill(PhotonInfo.Pt[P_Index_NoElectronVeto[g]]);
                  Numerator_NoElectronVeto_Eta->Fill(PhotonInfo.Eta[P_Index_NoElectronVeto[g]]);
                  Numerator_NoElectronVeto_Eta_PT->Fill(PhotonInfo.Eta[P_Index_NoElectronVeto[g]],PhotonInfo.Pt[P_Index_NoElectronVeto[g]]);
 	       }
	     }
	 } //photon loop
	} // if1

       } //event loop end


       ////////////////////////////
       //  Computation after loops
       ////////////////////////////

       TFile* file_TPResults = new TFile("TagAndProbeResults.root","RECREATE");
       file_TPResults->cd();


       h_Zmass_Inclusive_NoElectronVeto_Denominator->Write();
       h_Zmass_Inclusive_NoElectronVeto_Denominator = 0;
       delete h_Zmass_Inclusive_NoElectronVeto_Denominator;


       h_Zmass_Inclusive_NoElectronVeto_Numerator->Write();
       h_Zmass_Inclusive_NoElectronVeto_Numerator = 0;
       delete h_Zmass_Inclusive_NoElectronVeto_Numerator;



       h_Zmass_Inclusive_noNJetsCut_NoElectronVeto_Denominator->Write();
       h_Zmass_Inclusive_noNJetsCut_NoElectronVeto_Denominator = 0;
       delete h_Zmass_Inclusive_noNJetsCut_NoElectronVeto_Denominator;


       h_Zmass_Inclusive_noNJetsCut_NoElectronVeto_Numerator->Write();
       h_Zmass_Inclusive_noNJetsCut_NoElectronVeto_Numerator = 0;
       delete h_Zmass_Inclusive_noNJetsCut_NoElectronVeto_Numerator;





       for(unsigned int i=0; i<5; i++){
        for(unsigned int k=0; k<5; k++){

          h_Zmass_NoElectronVeto_Denominator[i][k]->Write();
          h_Zmass_NoElectronVeto_Denominator[i][k] = 0;
          delete h_Zmass_NoElectronVeto_Denominator[i][k];

          h_Zmass_NoElectronVeto_Numerator[i][k]->Write();
          h_Zmass_NoElectronVeto_Numerator[i][k] = 0;
          delete h_Zmass_NoElectronVeto_Numerator[i][k];

          h_Zmass_NoElectronVeto_noNJetsCut_Denominator[i][k]->Write();
          h_Zmass_NoElectronVeto_noNJetsCut_Denominator[i][k] = 0;
          delete h_Zmass_NoElectronVeto_noNJetsCut_Denominator[i][k];

          h_Zmass_NoElectronVeto_noNJetsCut_Numerator[i][k]->Write();
          h_Zmass_NoElectronVeto_noNJetsCut_Numerator[i][k] = 0;
          delete h_Zmass_NoElectronVeto_noNJetsCut_Numerator[i][k];


	}
       }











       for(unsigned int i=0; i<Eta_N_bins; i++){
          float num_s = (float)Numerator_NoElectronVeto_Eta->GetBinContent(i+1);
          float den_s = (float)Denominator_NoElectronVeto_Eta->GetBinContent(i+1);
          float eff_s = 0.;
          float err_s = 0.;
          if(den_s != 0.) {
            eff_s = num_s/den_s;
            err_s = (sqrt(num_s*(1-(num_s/den_s)))/den_s);
          }
          FakeRateRatio_NoElectronVeto_Eta->SetBinContent(i+1, eff_s);
          FakeRateRatio_NoElectronVeto_Eta->SetBinError(i+1, err_s);
       }

       Numerator_NoElectronVeto_Eta->Write();
       Numerator_NoElectronVeto_Eta = 0;
       delete Numerator_NoElectronVeto_Eta;

       Denominator_NoElectronVeto_Eta->Write();
       Denominator_NoElectronVeto_Eta = 0;
       delete Denominator_NoElectronVeto_Eta;

       FakeRateRatio_NoElectronVeto_Eta->Write();
       FakeRateRatio_NoElectronVeto_Eta = 0;
       delete FakeRateRatio_NoElectronVeto_Eta;


       for(unsigned int i=0; i<PT_N_bins; i++){
          float num_s = (float)Numerator_NoElectronVeto_PT->GetBinContent(i+1);
          float den_s = (float)Denominator_NoElectronVeto_PT->GetBinContent(i+1);
          float eff_s = 0.;
          float err_s = 0.;
          if(den_s != 0.) {
            eff_s = num_s/den_s;
            err_s = (sqrt(num_s*(1-(num_s/den_s)))/den_s);
          }
          FakeRateRatio_NoElectronVeto_PT->SetBinContent(i+1, eff_s);
          FakeRateRatio_NoElectronVeto_PT->SetBinError(i+1, err_s);
       }

       Numerator_NoElectronVeto_PT->Write();
       Numerator_NoElectronVeto_PT = 0;
       delete Numerator_NoElectronVeto_PT;

       Denominator_NoElectronVeto_PT->Write();
       Denominator_NoElectronVeto_PT = 0;
       delete Denominator_NoElectronVeto_PT;

       FakeRateRatio_NoElectronVeto_PT->Write();
       FakeRateRatio_NoElectronVeto_PT = 0;
       delete FakeRateRatio_NoElectronVeto_PT;


       for(unsigned int i=0; i<Eta_N_bins; i++){
        for(unsigned int k=0; k<PT_N_bins; k++){
          float num_s = (float)Numerator_NoElectronVeto_Eta_PT->GetBinContent(i+1,k+1);
          float den_s = (float)Denominator_NoElectronVeto_Eta_PT->GetBinContent(i+1,k+1);
          float eff_s = 0.;
          float err_s = 0.;
          if(den_s != 0.) {
            eff_s = num_s/den_s;
            err_s = (sqrt(num_s*(1-(num_s/den_s)))/den_s);
          }
          FakeRateRatio_NoElectronVeto_Eta_PT->SetBinContent(i+1,k+1, eff_s);
	  FakeRateRatio_NoElectronVeto_Eta_PT->SetBinError(i+1,k+1, err_s);
	} 

      }

       Numerator_NoElectronVeto_Eta_PT->Write();
       Numerator_NoElectronVeto_Eta_PT = 0;
       delete Numerator_NoElectronVeto_Eta_PT;

       Denominator_NoElectronVeto_Eta_PT->Write();
       Denominator_NoElectronVeto_Eta_PT = 0;
       delete Denominator_NoElectronVeto_Eta_PT;

       FakeRateRatio_NoElectronVeto_Eta_PT->Write();
       FakeRateRatio_NoElectronVeto_Eta_PT = 0;
       delete FakeRateRatio_NoElectronVeto_Eta_PT;




       for(unsigned int i=0; i<NJets_N_bins; i++){
          float num_s = (float)Numerator_NoElectronVeto_NJets->GetBinContent(i+1);
          float den_s = (float)Denominator_NoElectronVeto_NJets->GetBinContent(i+1);
          float eff_s = 0.;
          float err_s = 0.;
          if(den_s != 0.) {
            eff_s = num_s/den_s;
            err_s = (sqrt(num_s*(1-(num_s/den_s)))/den_s);
          }
          FakeRateRatio_NoElectronVeto_NJets->SetBinContent(i+1, eff_s);
          FakeRateRatio_NoElectronVeto_NJets->SetBinError(i+1, err_s);
       }

       Numerator_NoElectronVeto_NJets->Write();
       Numerator_NoElectronVeto_NJets = 0;
       delete Numerator_NoElectronVeto_NJets;

       Denominator_NoElectronVeto_NJets->Write();
       Denominator_NoElectronVeto_NJets = 0;
       delete Denominator_NoElectronVeto_NJets;

       FakeRateRatio_NoElectronVeto_NJets->Write();
       FakeRateRatio_NoElectronVeto_NJets = 0;
       delete FakeRateRatio_NoElectronVeto_NJets;


       for(unsigned int i=0; i<NVTX_N_bins; i++){
          float num_s = (float)Numerator_NoElectronVeto_NVTX->GetBinContent(i+1);
          float den_s = (float)Denominator_NoElectronVeto_NVTX->GetBinContent(i+1);
          float eff_s = 0.;
          float err_s = 0.;
          if(den_s != 0.) {
            eff_s = num_s/den_s;
            err_s = (sqrt(num_s*(1-(num_s/den_s)))/den_s);
          }
          FakeRateRatio_NoElectronVeto_NVTX->SetBinContent(i+1, eff_s);
          FakeRateRatio_NoElectronVeto_NVTX->SetBinError(i+1, err_s);
       }

       Numerator_NoElectronVeto_NVTX->Write();
       Numerator_NoElectronVeto_NVTX = 0;
       delete Numerator_NoElectronVeto_NVTX;

       Denominator_NoElectronVeto_NVTX->Write();
       Denominator_NoElectronVeto_NVTX = 0;
       delete Denominator_NoElectronVeto_NVTX;

       FakeRateRatio_NoElectronVeto_NVTX->Write();
       FakeRateRatio_NoElectronVeto_NVTX = 0;
       delete FakeRateRatio_NoElectronVeto_NVTX;


       for(unsigned int i=0; i<Inclusive_N_bins; i++){
          float num_s = (float)Numerator_NoElectronVeto_Inclusive->GetBinContent(i+1);
          float den_s = (float)Denominator_NoElectronVeto_Inclusive->GetBinContent(i+1);
          float eff_s = 0.;
          float err_s = 0.;
          if(den_s != 0.) {
            eff_s = num_s/den_s;
            err_s = (sqrt(num_s*(1-(num_s/den_s)))/den_s);
          }
          FakeRateRatio_NoElectronVeto_Inclusive->SetBinContent(i+1, eff_s);
          FakeRateRatio_NoElectronVeto_Inclusive->SetBinError(i+1, err_s);
       }

       Numerator_NoElectronVeto_Inclusive->Write();
       Numerator_NoElectronVeto_Inclusive = 0;
       delete Numerator_NoElectronVeto_Inclusive;

       Denominator_NoElectronVeto_Inclusive->Write();
       Denominator_NoElectronVeto_Inclusive = 0;
       delete Denominator_NoElectronVeto_Inclusive;

       FakeRateRatio_NoElectronVeto_Inclusive->Write();
       FakeRateRatio_NoElectronVeto_Inclusive = 0;
       delete FakeRateRatio_NoElectronVeto_Inclusive;


       file_TPResults->Write();
       file_TPResults->Close();
       delete file_TPResults;


}
