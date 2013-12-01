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
#include "interface/RecoPhotonSelectionAntiElectronVeto.h"
#include "interface/RecoPhotonSelectionNoElectronVeto.h"
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

void Ratio_Factors_j4_MC_removal()
{
    gROOT->ProcessLine(".L interface/setTDRStyle.C");
    gROOT->ProcessLine("setTDRStyle()");
    gStyle->SetPalette(1);

    TChain * root[26]; 

    for(unsigned int i=0; i<26; i++){
     root[i] = new TChain("bprimeKit/root");
    }

      float Lumi = 19.6;

      float set_of_number_of_events[26] = {0};
      float set_of_xsections[26] = {0};
       
      //Data SinleElectron
      root[0]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_SingleElectron*.root");
      set_of_number_of_events[0] = Lumi;
      set_of_xsections[0] = 1;

      //Data SingleMu
      root[1]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_SingleMu*.root");
      set_of_number_of_events[1] = Lumi;
      set_of_xsections[1] = 1;

      //QCD
      root[2]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_MC_QCD_Pt_20_30_EMEnriched_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1.root");         
      set_of_number_of_events[2] = 27212467;
      set_of_xsections[2] = 288600000 * 0.0101;

      root[3]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_MC_stableQCD_Pt_30_80_EMEnriched_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1.root"); 
      set_of_number_of_events[3] = 16867284;
      set_of_xsections[3] = 74330000 * 0.0621;

      root[4]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_MC_QCD_Pt_80_170_EMEnriched_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1.root");        
      set_of_number_of_events[4] = 12557989;
      set_of_xsections[4] = 1191000 * 0.1539;

      root[5]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_MC_QCD_Pt_170_250_EMEnriched_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1.root");       
      set_of_number_of_events[5] = 2705404;
      set_of_xsections[5] = 30990 * 0.148;

      root[6]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_MC_QCD_Pt_250_350_EMEnriched_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1.root");       
      set_of_number_of_events[6] = 1506866;
      set_of_xsections[6] = 4250 * 0.131;

      root[7]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_MC_QCD_Pt_350_EMEnriched_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1.root");           
      set_of_number_of_events[7] = 26292910;
      set_of_xsections[7] = 810 * 0.11;


      //TTJets
      root[8]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_MC_TTJets_MassiveBinDECAY_TuneZ2star_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1.root");  
      set_of_number_of_events[8] = 6866660;
      set_of_xsections[8] = 227;

      // DYJets
      root[9]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_MC_DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball_Summer12_DR53X-PU_S10_START53_V7A-v1.root");       
      set_of_number_of_events[9] = 19028293;
      set_of_xsections[9] = 3512.103509;

      //WJets
      root[10]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_MC_WJetsToLNu_TuneZ2Star_8TeV-madgraph-tarball_Summer12_DR53X-PU_S10_START53_V7A-v2.root");
      set_of_number_of_events[10] = 40528256;
      set_of_xsections[10] = 35640;


      //SingleTop
      root[11]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_MC_T_s-channel_TuneZ2star_8TeV-powheg-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1.root");              
      set_of_number_of_events[11] = 259180;
      set_of_xsections[11] = 3.79;

      root[12]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_MC_T_t-channel_TuneZ2star_8TeV-powheg-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1.root");              
      set_of_number_of_events[12] = 3728236;
      set_of_xsections[12] = 56.4;

      root[13]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_MC_T_tW-channel-DR_TuneZ2star_8TeV-powheg-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1.root");           
      set_of_number_of_events[13] = 495571;
      set_of_xsections[13] = 11.1;

      root[14]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_MC_Tbar_s-channel_TuneZ2star_8TeV-powheg-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1.root");            
      set_of_number_of_events[14] = 139604;
      set_of_xsections[14] = 1.76;

      root[15]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_MC_Tbar_t-channel_TuneZ2star_8TeV-powheg-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1.root");            
      set_of_number_of_events[15] = 1910249;
      set_of_xsections[15] = 30.7;

      root[16]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_MC_Tbar_tW-channel-DR_TuneZ2star_8TeV-powheg-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1.root");        
      set_of_number_of_events[16] = 491471;
      set_of_xsections[16] = 11.1;

      //Bosons
      root[17]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_MC_DiPhotonJets_8TeV-madgraph-tarball-v2_Summer12_DR53X-PU_S10_START53_V7A-v1.root");
      set_of_number_of_events[17] = 1072669;
      set_of_xsections[17] = 75.39;

      root[18]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_MC_WGToLNuG_TuneZ2star_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1.root");                
      set_of_number_of_events[18] = 4995727;
      set_of_xsections[18] = 461.6;

      root[19]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_MC_ZGToLLG_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1.root");                                   
      set_of_number_of_events[19] = 5737153;
      set_of_xsections[19] = 132.6;

      root[20]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_MC_WW_TuneZ2star_8TeV_pythia6_tauola_Summer12_DR53X-PU_S10_START53_V7A-v1.root");                       
      set_of_number_of_events[20] = 160134;
      set_of_xsections[20] = 69.9;

      root[21]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_MC_ZZ_TuneZ2star_8TeV_pythia6_tauola_Summer12_DR53X-PU_S10_START53_V7A-v1.root");                       
      set_of_number_of_events[21] = 4231406;
      set_of_xsections[21] = 8.4;

      //TT+Boson
      root[22]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_MC_TTWJets_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1.root");                                   
      set_of_number_of_events[22] = 194231;
      set_of_xsections[22] = 0.232;

      root[23]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_MC_TTGJets_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1.root");                                   
      set_of_number_of_events[23] = 71049;
      set_of_xsections[23] = 1.444;

      root[24]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_MC_TTH_Inclusive_M-125_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1.root");                        
      set_of_number_of_events[24] = 35324;
      set_of_xsections[24] = 0.13;

      root[25]->Add("/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/reduce_MC_TTZJets_8TeV-madgraph_v2_Summer12_DR53X-PU_S10_START53_V7A-v1.root");                                
      set_of_number_of_events[25] = 208118;
      set_of_xsections[25] = 0.2057;






    float set_of_weights[26] = {0};


    EvtInfoBranches EvtInfo;
    GenInfoBranches GenInfo;
    LepInfoBranches LepInfo;
    JetInfoBranches JetInfo;
    PhotonInfoBranches PhotonInfo;
    VertexInfoBranches VertexInfo;


        float N_tight_AND_anti_electron_veto = 0;

        float N_tight_AND_fo_q = 0;
        float N_tight_AND_fo_g = 0;

        float N_fo_q_AND_fo_g = 0;

        float N_anti_electron_veto_AND_fo_q = 0;
        float N_anti_electron_veto_AND_fo_g = 0;

        float N_2_anti_electron_veto = 0;

        float N_2_fo_q = 0;
        float N_2_fo_g = 0;



        float N_tight_AND_anti_electron_veto_j4 = 0;

        float N_tight_AND_fo_q_j4 = 0;
        float N_tight_AND_fo_g_j4 = 0;

        float N_fo_q_AND_fo_g_j4 = 0;

        float N_anti_electron_veto_AND_fo_q_j4 = 0;
        float N_anti_electron_veto_AND_fo_g_j4 = 0;

        float N_2_anti_electron_veto_j4 = 0;

        float N_2_fo_q_j4 = 0;
        float N_2_fo_g_j4 = 0;


        float N_tight_AND_anti_electron_veto_j4_l = 0;

        float N_tight_AND_fo_q_j4_l = 0;
        float N_tight_AND_fo_g_j4_l = 0;

        float N_fo_q_AND_fo_g_j4_l = 0;

        float N_anti_electron_veto_AND_fo_q_j4_l = 0;
        float N_anti_electron_veto_AND_fo_g_j4_l = 0;

        float N_2_anti_electron_veto_j4_l = 0;

        float N_2_fo_q_j4_l = 0;
        float N_2_fo_g_j4_l = 0;









        float err_N_tight_AND_anti_electron_veto = 0;

        float err_N_tight_AND_fo_q = 0;
        float err_N_tight_AND_fo_g = 0;

        float err_N_fo_q_AND_fo_g = 0;

        float err_N_anti_electron_veto_AND_fo_q = 0;
        float err_N_anti_electron_veto_AND_fo_g = 0;

        float err_N_2_anti_electron_veto = 0;

        float err_N_2_fo_q = 0;
        float err_N_2_fo_g = 0;



        float err_N_tight_AND_anti_electron_veto_j4 = 0;

        float err_N_tight_AND_fo_q_j4 = 0;
        float err_N_tight_AND_fo_g_j4 = 0;

        float err_N_fo_q_AND_fo_g_j4 = 0;

        float err_N_anti_electron_veto_AND_fo_q_j4 = 0;
        float err_N_anti_electron_veto_AND_fo_g_j4 = 0;

        float err_N_2_anti_electron_veto_j4 = 0;

        float err_N_2_fo_q_j4 = 0;
        float err_N_2_fo_g_j4 = 0;


        float err_N_tight_AND_anti_electron_veto_j4_l = 0;

        float err_N_tight_AND_fo_q_j4_l = 0;
        float err_N_tight_AND_fo_g_j4_l = 0;

        float err_N_fo_q_AND_fo_g_j4_l = 0;

        float err_N_anti_electron_veto_AND_fo_q_j4_l = 0;
        float err_N_anti_electron_veto_AND_fo_g_j4_l = 0;

        float err_N_2_anti_electron_veto_j4_l = 0;

        float err_N_2_fo_q_j4_l = 0;
        float err_N_2_fo_g_j4_l = 0;



    for(int sample_index=0;sample_index<26;sample_index++){


      set_of_weights[sample_index] = Lumi * set_of_xsections[sample_index] / set_of_number_of_events[sample_index];

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

   



	int NMuons = 0; 
	int NElectrons = 0; 
	int NLeptons = 0; 
	int M_Index[MAX_LEPTONS/2];
	int E_Index[MAX_LEPTONS/2];
	int L_Index[MAX_LEPTONS/2*2];
	for(int m=0;m<MAX_LEPTONS/2;m++) M_Index[m] = 0;
	for(int e=0;e<MAX_LEPTONS/2;e++) E_Index[e] = 0;
	for(int l=0;l<MAX_LEPTONS/2*2;l++) L_Index[l] = 0;
	RecoLeptonSelection(EvtInfo,LepInfo,NMuons,M_Index,NElectrons,E_Index,NLeptons,L_Index);
	//RecoLeptonSelectionNoElectronPt(EvtInfo,LepInfo,NMuons,M_Index,NElectrons,E_Index,NLeptons,L_Index);



	int NPhotons = 0;
	int P_Index[MAX_PHOTONS];
	for(int p=0;p<MAX_PHOTONS;p++) P_Index[p] = 0;
	RecoPhotonSelectionNoSigmaIetaIeta(LepInfo,PhotonInfo,NMuons,M_Index,NElectrons,E_Index,NPhotons,P_Index,EvtInfo.RhoPU[0]);


	int NJets = 0;
	int J_Index[MAX_JETS];
       	RecoJetSelection(LepInfo, JetInfo, PhotonInfo, NMuons, M_Index, NElectrons, E_Index, NJets, J_Index, NPhotons, P_Index);

	int NPhotons_FO = 0;
	int P_Index_FO[MAX_PHOTONS];
	for(int p=0;p<MAX_PHOTONS;p++) P_Index_FO[p] = 0; 
	RecoPhotonSelectionFONoSigmaIetaIeta(LepInfo,PhotonInfo,JetInfo,NJets,J_Index,NMuons,M_Index,NElectrons,E_Index,NPhotons_FO,P_Index_FO,EvtInfo.RhoPU[0]);
        /*
	int NPhotons_FO = 0;
	int P_Index_FO[MAX_PHOTONS];
	for(int p=0;p<MAX_PHOTONS;p++) P_Index_FO[p] = 0; 
	RecoPhotonSelectionFONoPt(LepInfo,PhotonInfo,NMuons,M_Index,NElectrons,E_Index,NPhotons_FO,P_Index_FO,EvtInfo.RhoPU[0]);
        */

	int NPhotons_NO_ELECTRON_VETO = 0;
	int P_Index_NO_ELECTRON_VETO[MAX_PHOTONS];
	for(int p=0;p<MAX_PHOTONS;p++) P_Index_NO_ELECTRON_VETO[p] = 0; 
	RecoPhotonSelectionNoElectronVeto(LepInfo,PhotonInfo,NMuons,M_Index,NElectrons,E_Index,NPhotons_NO_ELECTRON_VETO,P_Index_NO_ELECTRON_VETO,EvtInfo.RhoPU[0]);
	/*
	int NPhotons_NO_ELECTRON_VETO = 0;
	int P_Index_NO_ELECTRON_VETO[MAX_PHOTONS];
	for(int p=0;p<MAX_PHOTONS;p++) P_Index_NO_ELECTRON_VETO[p] = 0; 
	RecoPhotonSelectionNoElectronVetoNoPt(LepInfo,PhotonInfo,NMuons,M_Index,NElectrons,E_Index,NPhotons_NO_ELECTRON_VETO,P_Index_NO_ELECTRON_VETO,EvtInfo.RhoPU[0]);
	*/

	int NPhotons_ANTI_ELECTRON_VETO = 0;
	int P_Index_ANTI_ELECTRON_VETO[MAX_PHOTONS];
	for(int p=0;p<MAX_PHOTONS;p++) P_Index_ANTI_ELECTRON_VETO[p] = 0; 
	RecoPhotonSelectionAntiElectronVeto(LepInfo,PhotonInfo,NMuons,M_Index,NElectrons,E_Index,NPhotons_ANTI_ELECTRON_VETO,P_Index_ANTI_ELECTRON_VETO,EvtInfo.RhoPU[0]);



     	    bool dist_TIGHT = true;
	    for(int g=0;g<NPhotons;g++) { // loop on FO photons
     	      double dR = 0.3;
              if(NLeptons == 1){
 	         double dphi = DPHI(PhotonInfo.Phi[P_Index[g]], LepInfo.Phi[L_Index[0]]);
	         double deta = fabs(PhotonInfo.Eta[P_Index[g]]- LepInfo.Eta[L_Index[0]]);
                 dR   = pow(dphi*dphi+deta*deta, 0.5);
	      }
              if(dR < 0.3) dist_TIGHT = false;
	    }


     	    bool dist_FO = true;
	    for(int g=0;g<NPhotons_FO;g++) { // loop on FO photons
     	      double dR = 0.3;
              if(NLeptons == 1){
 	         double dphi = DPHI(PhotonInfo.Phi[P_Index_FO[g]], LepInfo.Phi[L_Index[0]]);
	         double deta = fabs(PhotonInfo.Eta[P_Index_FO[g]]- LepInfo.Eta[L_Index[0]]);
                 dR   = pow(dphi*dphi+deta*deta, 0.5);
	      }
              if(dR < 0.3) dist_FO = false;
	    }


     	    bool dist_NO_ELECTRON_VETO = true;
	    for(int g=0;g<NPhotons_NO_ELECTRON_VETO;g++) { // loop on NO_ELECTRON_VETO photons
     	      double dR = 0.3;
              if(NLeptons == 1){
 	         double dphi = DPHI(PhotonInfo.Phi[P_Index_NO_ELECTRON_VETO[g]], LepInfo.Phi[L_Index[0]]);
	         double deta = fabs(PhotonInfo.Eta[P_Index_NO_ELECTRON_VETO[g]]- LepInfo.Eta[L_Index[0]]);
                 dR   = pow(dphi*dphi+deta*deta, 0.5);
	      }
              if(dR < 0.3) dist_NO_ELECTRON_VETO = false;
	    }


     	    bool dist_ANTI_ELECTRON_VETO = true;
	    for(int g=0;g<NPhotons_NO_ELECTRON_VETO;g++) { // loop on ANTI_ELECTRON_VETO photons
     	      double dR = 0.3;
              if(NLeptons == 1){
 	         double dphi = DPHI(PhotonInfo.Phi[P_Index_ANTI_ELECTRON_VETO[g]], LepInfo.Phi[L_Index[0]]);
	         double deta = fabs(PhotonInfo.Eta[P_Index_ANTI_ELECTRON_VETO[g]]- LepInfo.Eta[L_Index[0]]);
                 dR   = pow(dphi*dphi+deta*deta, 0.5);
	      }
              if(dR < 0.3) dist_ANTI_ELECTRON_VETO = false;
	    }



            int NPhotons_FO_q = 0;
            int NPhotons_FO_g = 0;


	    for(int g=0;g<NPhotons_FO;g++) { // loop on FO photons

     	      double dR_aux = 0.5;
              int jindex;
	      for(int j=0;j<NJets;j++) { // loop on jets
 	         double dphi = DPHI(PhotonInfo.Phi[P_Index_FO[g]], JetInfo.Phi[J_Index[j]]);
	         double deta = fabs(PhotonInfo.Eta[P_Index_FO[g]]- JetInfo.Eta[J_Index[j]]);
                 double dR   = pow(dphi*dphi+deta*deta, 0.5);
                 if(dR < dR_aux){ dR_aux = dR; jindex = j;}
	      }


              if(dR_aux < 0.5 && JetInfo.QGTagsLikelihood[J_Index[jindex]] > 0.9) NPhotons_FO_q++;
              if(dR_aux < 0.5 && JetInfo.QGTagsLikelihood[J_Index[jindex]] < 0.9) NPhotons_FO_g++;

	    }





        if(!EvtInfo.McFlag) {



	if(NPhotons == 1 && NPhotons_ANTI_ELECTRON_VETO == 1) N_tight_AND_anti_electron_veto += set_of_weights[sample_index];

	if(NPhotons == 1 && NPhotons_FO_q == 1) N_tight_AND_fo_q += set_of_weights[sample_index];
	if(NPhotons == 1 && NPhotons_FO_g == 1) N_tight_AND_fo_g += set_of_weights[sample_index];

	if(NPhotons_FO_q == 1 && NPhotons_FO_g == 1) N_fo_q_AND_fo_g += set_of_weights[sample_index];

	if(NPhotons_ANTI_ELECTRON_VETO == 1 && NPhotons_FO_q == 1) N_anti_electron_veto_AND_fo_q += set_of_weights[sample_index];
	if(NPhotons_ANTI_ELECTRON_VETO == 1 && NPhotons_FO_g == 1) N_anti_electron_veto_AND_fo_g += set_of_weights[sample_index];

	if(NPhotons_ANTI_ELECTRON_VETO == 2) N_2_anti_electron_veto += set_of_weights[sample_index];

	if(NPhotons_FO_q == 2) N_2_fo_q += set_of_weights[sample_index];
	if(NPhotons_FO_g == 2) N_2_fo_g += set_of_weights[sample_index];



        if(NJets >= 4){

	  if(NPhotons == 1 && NPhotons_ANTI_ELECTRON_VETO == 1) N_tight_AND_anti_electron_veto_j4 += set_of_weights[sample_index];

	  if(NPhotons == 1 && NPhotons_FO_q == 1) N_tight_AND_fo_q_j4 += set_of_weights[sample_index];
	  if(NPhotons == 1 && NPhotons_FO_g == 1) N_tight_AND_fo_g_j4 += set_of_weights[sample_index];

	  if(NPhotons_FO_q == 1 && NPhotons_FO_g == 1) N_fo_q_AND_fo_g_j4 += set_of_weights[sample_index];

	  if(NPhotons_ANTI_ELECTRON_VETO == 1 && NPhotons_FO_q == 1) N_anti_electron_veto_AND_fo_q_j4 += set_of_weights[sample_index];
	  if(NPhotons_ANTI_ELECTRON_VETO == 1 && NPhotons_FO_g == 1) N_anti_electron_veto_AND_fo_g_j4 += set_of_weights[sample_index];

	  if(NPhotons_ANTI_ELECTRON_VETO == 2) N_2_anti_electron_veto_j4 += set_of_weights[sample_index];

	  if(NPhotons_FO_q == 2) N_2_fo_q_j4 += set_of_weights[sample_index];
	  if(NPhotons_FO_g == 2) N_2_fo_g_j4 += set_of_weights[sample_index];

	}



        if(NJets >= 4 && dist_FO == true && dist_TIGHT == true && dist_NO_ELECTRON_VETO == true && dist_ANTI_ELECTRON_VETO == true){

	  if(NPhotons == 1 && NPhotons_ANTI_ELECTRON_VETO == 1) N_tight_AND_anti_electron_veto_j4_l += set_of_weights[sample_index];

	  if(NPhotons == 1 && NPhotons_FO_q == 1) N_tight_AND_fo_q_j4_l += set_of_weights[sample_index];
	  if(NPhotons == 1 && NPhotons_FO_g == 1) N_tight_AND_fo_g_j4_l += set_of_weights[sample_index];

	  if(NPhotons_FO_q == 1 && NPhotons_FO_g == 1) N_fo_q_AND_fo_g_j4_l += set_of_weights[sample_index];

	  if(NPhotons_ANTI_ELECTRON_VETO == 1 && NPhotons_FO_q == 1) N_anti_electron_veto_AND_fo_q_j4_l += set_of_weights[sample_index];
	  if(NPhotons_ANTI_ELECTRON_VETO == 1 && NPhotons_FO_g == 1) N_anti_electron_veto_AND_fo_g_j4_l += set_of_weights[sample_index];

	  if(NPhotons_ANTI_ELECTRON_VETO == 2) N_2_anti_electron_veto_j4_l += set_of_weights[sample_index];

	  if(NPhotons_FO_q == 2) N_2_fo_q_j4_l += set_of_weights[sample_index];
	  if(NPhotons_FO_g == 2) N_2_fo_g_j4_l += set_of_weights[sample_index];

	}





	if(NPhotons == 1 && NPhotons_ANTI_ELECTRON_VETO == 1) err_N_tight_AND_anti_electron_veto += set_of_weights[sample_index];

	if(NPhotons == 1 && NPhotons_FO_q == 1) err_N_tight_AND_fo_q += set_of_weights[sample_index];
	if(NPhotons == 1 && NPhotons_FO_g == 1) err_N_tight_AND_fo_g += set_of_weights[sample_index];

	if(NPhotons_FO_q == 1 && NPhotons_FO_g == 1) err_N_fo_q_AND_fo_g += set_of_weights[sample_index];

	if(NPhotons_ANTI_ELECTRON_VETO == 1 && NPhotons_FO_q == 1) err_N_anti_electron_veto_AND_fo_q += set_of_weights[sample_index];
	if(NPhotons_ANTI_ELECTRON_VETO == 1 && NPhotons_FO_g == 1) err_N_anti_electron_veto_AND_fo_g += set_of_weights[sample_index];

	if(NPhotons_ANTI_ELECTRON_VETO == 2) err_N_2_anti_electron_veto += set_of_weights[sample_index];

	if(NPhotons_FO_q == 2) err_N_2_fo_q += set_of_weights[sample_index];
	if(NPhotons_FO_g == 2) err_N_2_fo_g += set_of_weights[sample_index];



        if(NJets >= 4){

	  if(NPhotons == 1 && NPhotons_ANTI_ELECTRON_VETO == 1) err_N_tight_AND_anti_electron_veto_j4 += set_of_weights[sample_index];

	  if(NPhotons == 1 && NPhotons_FO_q == 1) err_N_tight_AND_fo_q_j4 += set_of_weights[sample_index];
	  if(NPhotons == 1 && NPhotons_FO_g == 1) err_N_tight_AND_fo_g_j4 += set_of_weights[sample_index];

	  if(NPhotons_FO_q == 1 && NPhotons_FO_g == 1) err_N_fo_q_AND_fo_g_j4 += set_of_weights[sample_index];

	  if(NPhotons_ANTI_ELECTRON_VETO == 1 && NPhotons_FO_q == 1) err_N_anti_electron_veto_AND_fo_q_j4 += set_of_weights[sample_index];
	  if(NPhotons_ANTI_ELECTRON_VETO == 1 && NPhotons_FO_g == 1) err_N_anti_electron_veto_AND_fo_g_j4 += set_of_weights[sample_index];

	  if(NPhotons_ANTI_ELECTRON_VETO == 2) err_N_2_anti_electron_veto_j4 += set_of_weights[sample_index];

	  if(NPhotons_FO_q == 2) err_N_2_fo_q_j4 += set_of_weights[sample_index];
	  if(NPhotons_FO_g == 2) err_N_2_fo_g_j4 += set_of_weights[sample_index];

	}



        if(NJets >= 4 && dist_FO == true && dist_TIGHT == true && dist_NO_ELECTRON_VETO == true && dist_ANTI_ELECTRON_VETO == true){

	  if(NPhotons == 1 && NPhotons_ANTI_ELECTRON_VETO == 1) err_N_tight_AND_anti_electron_veto_j4_l += set_of_weights[sample_index];

	  if(NPhotons == 1 && NPhotons_FO_q == 1) err_N_tight_AND_fo_q_j4_l += set_of_weights[sample_index];
	  if(NPhotons == 1 && NPhotons_FO_g == 1) err_N_tight_AND_fo_g_j4_l += set_of_weights[sample_index];

	  if(NPhotons_FO_q == 1 && NPhotons_FO_g == 1) err_N_fo_q_AND_fo_g_j4_l += set_of_weights[sample_index];

	  if(NPhotons_ANTI_ELECTRON_VETO == 1 && NPhotons_FO_q == 1) err_N_anti_electron_veto_AND_fo_q_j4_l += set_of_weights[sample_index];
	  if(NPhotons_ANTI_ELECTRON_VETO == 1 && NPhotons_FO_g == 1) err_N_anti_electron_veto_AND_fo_g_j4_l += set_of_weights[sample_index];

	  if(NPhotons_ANTI_ELECTRON_VETO == 2) err_N_2_anti_electron_veto_j4_l += set_of_weights[sample_index];

	  if(NPhotons_FO_q == 2) err_N_2_fo_q_j4_l += set_of_weights[sample_index];
	  if(NPhotons_FO_g == 2) err_N_2_fo_g_j4_l += set_of_weights[sample_index];

	}






	}




        if(EvtInfo.McFlag) {

          

	  int NPhotons_MC = 0;
	  int NPhotons_ANTI_ELECTRON_VETO_MC = 0;
	  int NPhotons_FO_q_MC = 0;
	  int NPhotons_FO_g_MC = 0;

          for(int nl=0;nl<PhotonInfo.Size;nl++){


     	      double dR_aux = 0.5;
              int jindex;
	      for(int j=0;j<NJets;j++) { // loop on jets
 	         double dphi = DPHI(PhotonInfo.Phi[nl], JetInfo.Phi[J_Index[j]]);
	         double deta = fabs(PhotonInfo.Eta[nl]- JetInfo.Eta[J_Index[j]]);
                 double dR   = pow(dphi*dphi+deta*deta, 0.5);
                 if(dR < dR_aux){ dR_aux = dR; jindex = j;}
	      }

               double dR_aux2 = 0.5;
               int mindex;
               for(int m=0;m<GenInfo.Size ;m++) { // loop on GenInfo
                 double dphi = DPHI(PhotonInfo.Phi[nl], GenInfo.Phi[m]);
                 double deta = fabs(PhotonInfo.Eta[nl]-GenInfo.Eta[m]);
                 double dR   = pow(dphi*dphi+deta*deta, 0.5);
                 if(dR < dR_aux2){ dR_aux2 = dR; mindex = m;}
                 
               }

	       if( (dR_aux2 < 0.5) && (GenInfo.PhotonFlag[mindex] == 0) ) NPhotons_MC++;
	       if( (dR_aux2 < 0.5) && (GenInfo.PhotonFlag[mindex] == 3) && (!PhotonInfo.passelectronveto[nl])) NPhotons_ANTI_ELECTRON_VETO_MC++;
	       if( (dR_aux2 < 0.5) && (GenInfo.PhotonFlag[mindex] == 1) && (dR_aux < 0.5) && (JetInfo.QGTagsLikelihood[J_Index[jindex]] > 0.9)) NPhotons_FO_q_MC++;
	       if( (dR_aux2 < 0.5) && (GenInfo.PhotonFlag[mindex] == 1) && (dR_aux < 0.5) && (JetInfo.QGTagsLikelihood[J_Index[jindex]] < 0.9)) NPhotons_FO_g_MC++;

	  }




	if(NPhotons == 1 && NPhotons_ANTI_ELECTRON_VETO == 1 && (!(NPhotons_MC == 1 && NPhotons_ANTI_ELECTRON_VETO_MC == 1))) N_tight_AND_anti_electron_veto -= set_of_weights[sample_index];

	if(NPhotons == 1 && NPhotons_FO_q == 1 && (!(NPhotons_MC == 1 && NPhotons_FO_q_MC == 1))) N_tight_AND_fo_q -= set_of_weights[sample_index];
	if(NPhotons == 1 && NPhotons_FO_g == 1 && (!(NPhotons_MC == 1 && NPhotons_FO_g_MC == 1))) N_tight_AND_fo_g -= set_of_weights[sample_index];

	if(NPhotons_FO_q == 1 && NPhotons_FO_g == 1 && (!(NPhotons_FO_q_MC == 1 && NPhotons_FO_g_MC == 1))) N_fo_q_AND_fo_g -= set_of_weights[sample_index];

	if(NPhotons_ANTI_ELECTRON_VETO == 1 && NPhotons_FO_q == 1 && (!(NPhotons_ANTI_ELECTRON_VETO_MC == 1 && NPhotons_FO_q_MC == 1))) N_anti_electron_veto_AND_fo_q -= set_of_weights[sample_index];
	if(NPhotons_ANTI_ELECTRON_VETO == 1 && NPhotons_FO_g == 1 && (!(NPhotons_ANTI_ELECTRON_VETO_MC == 1 && NPhotons_FO_g_MC == 1))) N_anti_electron_veto_AND_fo_g -= set_of_weights[sample_index];

	if(NPhotons_ANTI_ELECTRON_VETO == 2 && (!(NPhotons_ANTI_ELECTRON_VETO_MC == 2))) N_2_anti_electron_veto -= set_of_weights[sample_index];

	if(NPhotons_FO_q == 2 && (!(NPhotons_FO_q_MC == 2))) N_2_fo_q -= set_of_weights[sample_index];
	if(NPhotons_FO_g == 2 && (!(NPhotons_FO_g_MC == 2))) N_2_fo_g -= set_of_weights[sample_index];



        if(NJets >= 4){

	  if(NPhotons == 1 && NPhotons_ANTI_ELECTRON_VETO == 1 && (!(NPhotons_MC == 1 && NPhotons_ANTI_ELECTRON_VETO_MC == 1))) N_tight_AND_anti_electron_veto_j4 -= set_of_weights[sample_index];

	  if(NPhotons == 1 && NPhotons_FO_q == 1 && (!(NPhotons_MC == 1 && NPhotons_FO_q_MC == 1))) N_tight_AND_fo_q_j4 -= set_of_weights[sample_index];
	  if(NPhotons == 1 && NPhotons_FO_g == 1 && (!(NPhotons_MC == 1 && NPhotons_FO_g_MC == 1))) N_tight_AND_fo_g_j4 -= set_of_weights[sample_index];

	  if(NPhotons_FO_q == 1 && NPhotons_FO_g == 1 && (!(NPhotons_FO_q_MC == 1 && NPhotons_FO_g_MC == 1))) N_fo_q_AND_fo_g_j4 -= set_of_weights[sample_index];

	  if(NPhotons_ANTI_ELECTRON_VETO == 1 && NPhotons_FO_q == 1 && (!(NPhotons_ANTI_ELECTRON_VETO_MC == 1 && NPhotons_FO_q_MC == 1))) N_anti_electron_veto_AND_fo_q_j4 -= set_of_weights[sample_index];
	  if(NPhotons_ANTI_ELECTRON_VETO == 1 && NPhotons_FO_g == 1 && (!(NPhotons_ANTI_ELECTRON_VETO_MC == 1 && NPhotons_FO_g_MC == 1))) N_anti_electron_veto_AND_fo_g_j4 -= set_of_weights[sample_index];

	  if(NPhotons_ANTI_ELECTRON_VETO == 2 && (!(NPhotons_ANTI_ELECTRON_VETO_MC == 2))) N_2_anti_electron_veto_j4 -= set_of_weights[sample_index];

	  if(NPhotons_FO_q == 2 && (!(NPhotons_FO_q_MC == 2))) N_2_fo_q_j4 -= set_of_weights[sample_index];
	  if(NPhotons_FO_g == 2 && (!(NPhotons_FO_g_MC == 2))) N_2_fo_g_j4 -= set_of_weights[sample_index];

	}



        if(NJets >= 4 && dist_FO == true && dist_TIGHT == true && dist_NO_ELECTRON_VETO == true && dist_ANTI_ELECTRON_VETO == true){

	  if(NPhotons == 1 && NPhotons_ANTI_ELECTRON_VETO == 1 && (!(NPhotons_MC == 1 && NPhotons_ANTI_ELECTRON_VETO_MC == 1))) N_tight_AND_anti_electron_veto_j4_l -= set_of_weights[sample_index];

	  if(NPhotons == 1 && NPhotons_FO_q == 1 && (!(NPhotons_MC == 1 && NPhotons_FO_q_MC == 1))) N_tight_AND_fo_q_j4_l -= set_of_weights[sample_index];
	  if(NPhotons == 1 && NPhotons_FO_g == 1 && (!(NPhotons_MC == 1 && NPhotons_FO_g_MC == 1))) N_tight_AND_fo_g_j4_l -= set_of_weights[sample_index];

	  if(NPhotons_FO_q == 1 && NPhotons_FO_g == 1 && (!(NPhotons_FO_q_MC == 1 && NPhotons_FO_g_MC == 1))) N_fo_q_AND_fo_g_j4_l -= set_of_weights[sample_index];

	  if(NPhotons_ANTI_ELECTRON_VETO == 1 && NPhotons_FO_q == 1 && (!(NPhotons_ANTI_ELECTRON_VETO_MC == 1 && NPhotons_FO_q_MC == 1))) N_anti_electron_veto_AND_fo_q_j4_l -= set_of_weights[sample_index];
	  if(NPhotons_ANTI_ELECTRON_VETO == 1 && NPhotons_FO_g == 1 && (!(NPhotons_ANTI_ELECTRON_VETO_MC == 1 && NPhotons_FO_g_MC == 1))) N_anti_electron_veto_AND_fo_g_j4_l -= set_of_weights[sample_index];

	  if(NPhotons_ANTI_ELECTRON_VETO == 2 && (!(NPhotons_ANTI_ELECTRON_VETO_MC == 2))) N_2_anti_electron_veto_j4_l -= set_of_weights[sample_index];

	  if(NPhotons_FO_q == 2 && (!(NPhotons_FO_q_MC == 2))) N_2_fo_q_j4_l -= set_of_weights[sample_index];
	  if(NPhotons_FO_g == 2 && (!(NPhotons_FO_g_MC == 2))) N_2_fo_g_j4_l -= set_of_weights[sample_index];

	}







	if(NPhotons == 1 && NPhotons_ANTI_ELECTRON_VETO == 1 && (!(NPhotons_MC == 1 && NPhotons_ANTI_ELECTRON_VETO_MC == 1))) err_N_tight_AND_anti_electron_veto += set_of_weights[sample_index]*set_of_weights[sample_index];

	if(NPhotons == 1 && NPhotons_FO_q == 1 && (!(NPhotons_MC == 1 && NPhotons_FO_q_MC == 1))) err_N_tight_AND_fo_q += set_of_weights[sample_index]*set_of_weights[sample_index];
	if(NPhotons == 1 && NPhotons_FO_g == 1 && (!(NPhotons_MC == 1 && NPhotons_FO_g_MC == 1))) err_N_tight_AND_fo_g += set_of_weights[sample_index]*set_of_weights[sample_index];

	if(NPhotons_FO_q == 1 && NPhotons_FO_g == 1 && (!(NPhotons_FO_q_MC == 1 && NPhotons_FO_g_MC == 1))) err_N_fo_q_AND_fo_g += set_of_weights[sample_index]*set_of_weights[sample_index];

	if(NPhotons_ANTI_ELECTRON_VETO == 1 && NPhotons_FO_q == 1 && (!(NPhotons_ANTI_ELECTRON_VETO_MC == 1 && NPhotons_FO_q_MC == 1))) err_N_anti_electron_veto_AND_fo_q += set_of_weights[sample_index]*set_of_weights[sample_index];
	if(NPhotons_ANTI_ELECTRON_VETO == 1 && NPhotons_FO_g == 1 && (!(NPhotons_ANTI_ELECTRON_VETO_MC == 1 && NPhotons_FO_g_MC == 1))) err_N_anti_electron_veto_AND_fo_g += set_of_weights[sample_index]*set_of_weights[sample_index];

	if(NPhotons_ANTI_ELECTRON_VETO == 2 && (!(NPhotons_ANTI_ELECTRON_VETO_MC == 2))) err_N_2_anti_electron_veto += set_of_weights[sample_index]*set_of_weights[sample_index];

	if(NPhotons_FO_q == 2 && (!(NPhotons_FO_q_MC == 2))) err_N_2_fo_q += set_of_weights[sample_index]*set_of_weights[sample_index];
	if(NPhotons_FO_g == 2 && (!(NPhotons_FO_g_MC == 2))) err_N_2_fo_g += set_of_weights[sample_index]*set_of_weights[sample_index];



        if(NJets >= 4){

	  if(NPhotons == 1 && NPhotons_ANTI_ELECTRON_VETO == 1 && (!(NPhotons_MC == 1 && NPhotons_ANTI_ELECTRON_VETO_MC == 1))) err_N_tight_AND_anti_electron_veto_j4 += set_of_weights[sample_index]*set_of_weights[sample_index];

	  if(NPhotons == 1 && NPhotons_FO_q == 1 && (!(NPhotons_MC == 1 && NPhotons_FO_q_MC == 1))) err_N_tight_AND_fo_q_j4 += set_of_weights[sample_index]*set_of_weights[sample_index];
	  if(NPhotons == 1 && NPhotons_FO_g == 1 && (!(NPhotons_MC == 1 && NPhotons_FO_g_MC == 1))) err_N_tight_AND_fo_g_j4 += set_of_weights[sample_index]*set_of_weights[sample_index];

	  if(NPhotons_FO_q == 1 && NPhotons_FO_g == 1 && (!(NPhotons_FO_q_MC == 1 && NPhotons_FO_g_MC == 1))) err_N_fo_q_AND_fo_g_j4 += set_of_weights[sample_index]*set_of_weights[sample_index];

	  if(NPhotons_ANTI_ELECTRON_VETO == 1 && NPhotons_FO_q == 1 && (!(NPhotons_ANTI_ELECTRON_VETO_MC == 1 && NPhotons_FO_q_MC == 1))) err_N_anti_electron_veto_AND_fo_q_j4 += set_of_weights[sample_index]*set_of_weights[sample_index];
	  if(NPhotons_ANTI_ELECTRON_VETO == 1 && NPhotons_FO_g == 1 && (!(NPhotons_ANTI_ELECTRON_VETO_MC == 1 && NPhotons_FO_g_MC == 1))) err_N_anti_electron_veto_AND_fo_g_j4 += set_of_weights[sample_index]*set_of_weights[sample_index];

	  if(NPhotons_ANTI_ELECTRON_VETO == 2 && (!(NPhotons_ANTI_ELECTRON_VETO_MC == 2))) err_N_2_anti_electron_veto_j4 += set_of_weights[sample_index]*set_of_weights[sample_index];

	  if(NPhotons_FO_q == 2 && (!(NPhotons_FO_q_MC == 2))) err_N_2_fo_q_j4 += set_of_weights[sample_index]*set_of_weights[sample_index];
	  if(NPhotons_FO_g == 2 && (!(NPhotons_FO_g_MC == 2))) err_N_2_fo_g_j4 += set_of_weights[sample_index]*set_of_weights[sample_index];

	}



        if(NJets >= 4 && dist_FO == true && dist_TIGHT == true && dist_NO_ELECTRON_VETO == true && dist_ANTI_ELECTRON_VETO == true){

	  if(NPhotons == 1 && NPhotons_ANTI_ELECTRON_VETO == 1 && (!(NPhotons_MC == 1 && NPhotons_ANTI_ELECTRON_VETO_MC == 1))) err_N_tight_AND_anti_electron_veto_j4_l += set_of_weights[sample_index]*set_of_weights[sample_index];

	  if(NPhotons == 1 && NPhotons_FO_q == 1 && (!(NPhotons_MC == 1 && NPhotons_FO_q_MC == 1))) err_N_tight_AND_fo_q_j4_l += set_of_weights[sample_index]*set_of_weights[sample_index];
	  if(NPhotons == 1 && NPhotons_FO_g == 1 && (!(NPhotons_MC == 1 && NPhotons_FO_g_MC == 1))) err_N_tight_AND_fo_g_j4_l += set_of_weights[sample_index]*set_of_weights[sample_index];

	  if(NPhotons_FO_q == 1 && NPhotons_FO_g == 1 && (!(NPhotons_FO_q_MC == 1 && NPhotons_FO_g_MC == 1))) err_N_fo_q_AND_fo_g_j4_l += set_of_weights[sample_index]*set_of_weights[sample_index];

	  if(NPhotons_ANTI_ELECTRON_VETO == 1 && NPhotons_FO_q == 1 && (!(NPhotons_ANTI_ELECTRON_VETO_MC == 1 && NPhotons_FO_q_MC == 1))) err_N_anti_electron_veto_AND_fo_q_j4_l += set_of_weights[sample_index]*set_of_weights[sample_index];
	  if(NPhotons_ANTI_ELECTRON_VETO == 1 && NPhotons_FO_g == 1 && (!(NPhotons_ANTI_ELECTRON_VETO_MC == 1 && NPhotons_FO_g_MC == 1))) err_N_anti_electron_veto_AND_fo_g_j4_l += set_of_weights[sample_index]*set_of_weights[sample_index];

	  if(NPhotons_ANTI_ELECTRON_VETO == 2 && (!(NPhotons_ANTI_ELECTRON_VETO_MC == 2))) err_N_2_anti_electron_veto_j4_l += set_of_weights[sample_index]*set_of_weights[sample_index];

	  if(NPhotons_FO_q == 2 && (!(NPhotons_FO_q_MC == 2))) err_N_2_fo_q_j4_l += set_of_weights[sample_index]*set_of_weights[sample_index];
	  if(NPhotons_FO_g == 2 && (!(NPhotons_FO_g_MC == 2))) err_N_2_fo_g_j4_l += set_of_weights[sample_index]*set_of_weights[sample_index];

	}








	}




       } //event loop end






    } // sample loop end





       ////////////////////////////
       //  Computation after loops
       ////////////////////////////





    cout << "N_tight_AND_anti_electron_veto: " << N_tight_AND_anti_electron_veto << endl;
    cout << "N_tight_AND_fo_q: " << N_tight_AND_fo_q << endl;
    cout << "N_tight_AND_fo_g: " << N_tight_AND_fo_g << endl;
    cout << "N_fo_q_AND_fo_g: " << N_fo_q_AND_fo_g << endl;
    cout << "N_anti_electron_veto_AND_fo_g: " << N_anti_electron_veto_AND_fo_g << endl;
    cout << "N_anti_electron_veto_AND_fo_q: " << N_anti_electron_veto_AND_fo_q << endl;
    cout << "N_2_anti_electron_veto: " << N_2_anti_electron_veto << endl;
    cout << "N_2_fo_q: " << N_2_fo_q << endl;
    cout << "N_2_fo_g: " << N_2_fo_g << endl;


    cout << "R^{lg/lq}=  " << N_anti_electron_veto_AND_fo_g / N_anti_electron_veto_AND_fo_q << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_g) + sqrt(err_N_anti_electron_veto_AND_fo_q) * N_anti_electron_veto_AND_fo_g / N_anti_electron_veto_AND_fo_q) / N_anti_electron_veto_AND_fo_q  << endl;
    cout << "R^{ll/lq}=  " << N_2_anti_electron_veto / N_anti_electron_veto_AND_fo_q << " +/- " << (sqrt(err_N_2_anti_electron_veto) + sqrt(err_N_anti_electron_veto_AND_fo_q) * N_2_anti_electron_veto / N_anti_electron_veto_AND_fo_q) / N_anti_electron_veto_AND_fo_q << endl;
    cout << "R^{qq/lq}=  " << N_2_fo_q / N_anti_electron_veto_AND_fo_q << " +/- " << (sqrt(err_N_2_fo_q) + sqrt(err_N_anti_electron_veto_AND_fo_q) * N_2_fo_q / N_anti_electron_veto_AND_fo_q) / N_anti_electron_veto_AND_fo_q << endl;
    cout << "R^{gg/lq}=  " << N_2_fo_g / N_anti_electron_veto_AND_fo_q << " +/- " << (sqrt(err_N_2_fo_g) + sqrt(err_N_anti_electron_veto_AND_fo_q) * N_2_fo_g / N_anti_electron_veto_AND_fo_q) / N_anti_electron_veto_AND_fo_q << endl;
    cout << "R^{qg/lq}=  " << N_fo_q_AND_fo_g / N_anti_electron_veto_AND_fo_q << " +/- " << (sqrt(err_N_fo_q_AND_fo_g) + sqrt(err_N_anti_electron_veto_AND_fo_q) * N_fo_q_AND_fo_g / N_anti_electron_veto_AND_fo_q) / N_anti_electron_veto_AND_fo_q << endl; cout << endl;

    cout << "R^{lq/lg}=  " << N_anti_electron_veto_AND_fo_q / N_anti_electron_veto_AND_fo_g << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_q) + sqrt(err_N_anti_electron_veto_AND_fo_g) * N_anti_electron_veto_AND_fo_q / N_anti_electron_veto_AND_fo_g) / N_anti_electron_veto_AND_fo_g << endl;
    cout << "R^{ll/lg}=  " << N_2_anti_electron_veto / N_anti_electron_veto_AND_fo_g << " +/- " << (sqrt(err_N_2_anti_electron_veto) + sqrt(err_N_anti_electron_veto_AND_fo_g) * N_2_anti_electron_veto / N_anti_electron_veto_AND_fo_g) / N_anti_electron_veto_AND_fo_g << endl;
    cout << "R^{qq/lg}=  " << N_2_fo_q / N_anti_electron_veto_AND_fo_g << " +/- " << (sqrt(err_N_2_fo_q) + sqrt(err_N_anti_electron_veto_AND_fo_g) * N_2_fo_q / N_anti_electron_veto_AND_fo_g) / N_anti_electron_veto_AND_fo_g << endl;
    cout << "R^{gg/lg}=  " << N_2_fo_g / N_anti_electron_veto_AND_fo_g << " +/- " << (sqrt(err_N_2_fo_g) + sqrt(err_N_anti_electron_veto_AND_fo_g) * N_2_fo_g / N_anti_electron_veto_AND_fo_g) / N_anti_electron_veto_AND_fo_g << endl;
    cout << "R^{qg/lg}=  " << N_fo_q_AND_fo_g / N_anti_electron_veto_AND_fo_g << " +/- " << (sqrt(err_N_fo_q_AND_fo_g) + sqrt(err_N_anti_electron_veto_AND_fo_g) * N_fo_q_AND_fo_g / N_anti_electron_veto_AND_fo_g) / N_anti_electron_veto_AND_fo_g << endl; cout << endl;

    cout << "R^{lq/ll}=  " << N_anti_electron_veto_AND_fo_q / N_2_anti_electron_veto << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_q) + sqrt(err_N_2_anti_electron_veto) * N_anti_electron_veto_AND_fo_q / N_2_anti_electron_veto) / N_2_anti_electron_veto << endl;
cout << "R^{lg/ll}=  " << N_anti_electron_veto_AND_fo_g / N_2_anti_electron_veto << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_g) + sqrt(err_N_2_anti_electron_veto) * N_anti_electron_veto_AND_fo_g / N_2_anti_electron_veto) / N_2_anti_electron_veto << endl;
    cout << "R^{qq/ll}=  " << N_2_fo_q / N_2_anti_electron_veto << " +/- " << (sqrt(err_N_2_fo_q) + sqrt(err_N_2_anti_electron_veto) * N_2_fo_q / N_2_anti_electron_veto) / N_2_anti_electron_veto << endl;
    cout << "R^{gg/ll}=  " << N_2_fo_g / N_2_anti_electron_veto << " +/- " << (sqrt(err_N_2_fo_g) + sqrt(err_N_2_anti_electron_veto) * N_2_fo_g / N_2_anti_electron_veto) / N_2_anti_electron_veto << endl;
    cout << "R^{qg/ll}=  " << N_fo_q_AND_fo_g / N_2_anti_electron_veto << " +/- " << (sqrt(err_N_fo_q_AND_fo_g) + sqrt(err_N_2_anti_electron_veto) * N_fo_q_AND_fo_g / N_2_anti_electron_veto) / N_2_anti_electron_veto << endl; cout << endl;

    cout << "R^{lq/qq}=  " << N_anti_electron_veto_AND_fo_q / N_2_fo_q << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_q) + sqrt(err_N_2_fo_q) * N_anti_electron_veto_AND_fo_q / N_2_fo_q) / N_2_fo_q << endl;
    cout << "R^{lg/qq}=  " << N_anti_electron_veto_AND_fo_g / N_2_fo_q << " +/- " <<(sqrt(err_N_anti_electron_veto_AND_fo_g) + sqrt(err_N_2_fo_q) * N_anti_electron_veto_AND_fo_g / N_2_fo_q) / N_2_fo_q << endl;
    cout << "R^{ll/qq}=  " << N_2_anti_electron_veto / N_2_fo_q << " +/- " << (sqrt(err_N_2_anti_electron_veto) + sqrt(err_N_2_fo_q) * N_2_anti_electron_veto / N_2_fo_q) / N_2_fo_q << endl;
    cout << "R^{gg/qq}=  " << N_2_fo_g / N_2_fo_q << " +/- " << (sqrt(err_N_2_fo_g) + sqrt(err_N_2_fo_q) * N_2_fo_g / N_2_fo_q) / N_2_fo_q << endl;
    cout << "R^{qg/qq}=  " << N_fo_q_AND_fo_g / N_2_fo_q << " +/- " << (sqrt(err_N_fo_q_AND_fo_g) + sqrt(err_N_2_fo_q) * N_fo_q_AND_fo_g / N_2_fo_q) / N_2_fo_q << endl; cout << endl;

    cout << "R^{lq/gg}=  " << N_anti_electron_veto_AND_fo_q / N_2_fo_g << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_q) + sqrt(err_N_2_fo_g) * N_anti_electron_veto_AND_fo_q / N_2_fo_g) / N_2_fo_g << endl;
    cout << "R^{lg/gg}=  " << N_anti_electron_veto_AND_fo_g / N_2_fo_g << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_g) + sqrt(err_N_2_fo_g) * N_anti_electron_veto_AND_fo_g / N_2_fo_g) / N_2_fo_g << endl;
    cout << "R^{ll/gg}=  " << N_2_anti_electron_veto / N_2_fo_g << " +/- " << (sqrt(err_N_2_anti_electron_veto) + sqrt(err_N_2_fo_g) * N_2_anti_electron_veto / N_2_fo_g) / N_2_fo_g << endl;
    cout << "R^{qq/gg}=  " << N_2_fo_q / N_2_fo_g << " +/- " << (sqrt(err_N_2_fo_q) + sqrt(err_N_2_fo_g) * N_2_fo_q / N_2_fo_g) / N_2_fo_g  << endl;
    cout << "R^{qg/gg}=  " << N_fo_q_AND_fo_g / N_2_fo_g << " +/- " << (sqrt(err_N_fo_q_AND_fo_g) + sqrt(err_N_2_fo_g) * N_fo_q_AND_fo_g / N_2_fo_g) / N_2_fo_g << endl; cout << endl;

    cout << "R^{lq/qg}=  " << N_anti_electron_veto_AND_fo_q / N_fo_q_AND_fo_g << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_q) + sqrt(err_N_fo_q_AND_fo_g) * N_anti_electron_veto_AND_fo_q / N_fo_q_AND_fo_g) / N_fo_q_AND_fo_g << endl;
    cout << "R^{lg/qg}=  " << N_anti_electron_veto_AND_fo_g / N_fo_q_AND_fo_g << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_g) + sqrt(err_N_fo_q_AND_fo_g) * N_anti_electron_veto_AND_fo_g / N_fo_q_AND_fo_g) / N_fo_q_AND_fo_g << endl;
    cout << "R^{ll/qg}=  " << N_2_anti_electron_veto / N_fo_q_AND_fo_g << " +/- " << (sqrt(err_N_2_anti_electron_veto) + sqrt(err_N_fo_q_AND_fo_g) * N_2_anti_electron_veto / N_fo_q_AND_fo_g) / N_fo_q_AND_fo_g << endl;
    cout << "R^{qq/qg}=  " << N_2_fo_q / N_fo_q_AND_fo_g << " +/- " << (sqrt(err_N_2_fo_q) + sqrt(err_N_fo_q_AND_fo_g) * N_2_fo_q / N_fo_q_AND_fo_g) / N_fo_q_AND_fo_g << endl;
    cout << "R^{gg/qg}=  " << N_2_fo_g / N_fo_q_AND_fo_g << " +/- " << (sqrt(err_N_2_fo_g) + sqrt(err_N_fo_q_AND_fo_g) * N_2_fo_g / N_fo_q_AND_fo_g) / N_fo_q_AND_fo_g << endl; cout << endl;

    cout << "R^{sg/sq}=  " << N_tight_AND_fo_g / N_tight_AND_fo_g << " +/- " << (sqrt(err_N_tight_AND_fo_g) + sqrt(err_N_tight_AND_fo_g) * N_tight_AND_fo_g / N_tight_AND_fo_g) / N_tight_AND_fo_g << endl;
    cout << "R^{sl/sq}=  " << N_tight_AND_anti_electron_veto / N_tight_AND_fo_q << " +/- " << (sqrt(err_N_tight_AND_anti_electron_veto) + sqrt(err_N_tight_AND_fo_q) * N_tight_AND_anti_electron_veto / N_tight_AND_fo_q) / N_tight_AND_fo_q << endl; cout << endl;

    cout << "R^{sg/sq}=  " << N_tight_AND_fo_g / N_tight_AND_fo_q << " +/- " << (sqrt(err_N_tight_AND_fo_g) + sqrt(err_N_tight_AND_fo_q) * N_anti_electron_veto_AND_fo_g / N_2_fo_g) / N_2_fo_g << endl;
    cout << "R^{sl/sq}=  " << N_tight_AND_anti_electron_veto / N_tight_AND_fo_q << " +/- " << (sqrt(err_N_tight_AND_anti_electron_veto) + sqrt(err_N_tight_AND_fo_q) * N_tight_AND_anti_electron_veto / N_tight_AND_fo_q) / N_tight_AND_fo_q << endl; cout << endl;

    cout << "R^{sq/sg}=  " << N_tight_AND_fo_q / N_tight_AND_fo_g << " +/- " << (sqrt(err_N_tight_AND_fo_q) + sqrt(err_N_tight_AND_fo_g) * N_tight_AND_fo_q / N_tight_AND_fo_g) / N_tight_AND_fo_g << endl;
    cout << "R^{sl/sg}=  " << N_tight_AND_anti_electron_veto / N_tight_AND_fo_g << " +/- " << (sqrt(err_N_tight_AND_anti_electron_veto) + sqrt(err_N_tight_AND_fo_g) * N_tight_AND_anti_electron_veto / N_tight_AND_fo_g) / N_tight_AND_fo_g << endl; cout << endl;

    cout << "R^{sq/sl}=  " << N_tight_AND_fo_q / N_tight_AND_anti_electron_veto << " +/- " << (sqrt(err_N_tight_AND_fo_q) + sqrt(err_N_tight_AND_anti_electron_veto) * N_tight_AND_fo_q / N_tight_AND_anti_electron_veto) / N_tight_AND_anti_electron_veto << endl;
    cout << "R^{sg/sl}=  " << N_tight_AND_fo_g / N_tight_AND_anti_electron_veto << " +/- " <<  (sqrt(err_N_tight_AND_fo_g) + sqrt(err_N_tight_AND_anti_electron_veto) *  N_tight_AND_fo_g / N_tight_AND_anti_electron_veto) / N_tight_AND_anti_electron_veto  << endl; cout << endl;



 

    cout << "*********************" << endl;

    cout << "N_tight_AND_anti_electron_veto_j4: " << N_tight_AND_anti_electron_veto_j4 << endl;
    cout << "N_tight_AND_fo_q_j4: " << N_tight_AND_fo_q_j4 << endl;
    cout << "N_tight_AND_fo_g_j4: " << N_tight_AND_fo_g_j4 << endl;
    cout << "N_fo_q_AND_fo_g_j4: " << N_fo_q_AND_fo_g_j4 << endl;
    cout << "N_anti_electron_veto_AND_fo_g_j4: " << N_anti_electron_veto_AND_fo_g_j4 << endl;
    cout << "N_anti_electron_veto_AND_fo_q_j4: " << N_anti_electron_veto_AND_fo_q_j4 << endl;
    cout << "N_2_anti_electron_veto_j4: " << N_2_anti_electron_veto_j4 << endl;
    cout << "N_2_fo_q_j4: " << N_2_fo_q_j4 << endl;
    cout << "N_2_fo_g_j4: " << N_2_fo_g_j4 << endl;




   cout << "R^{lg/lq}=  " << N_anti_electron_veto_AND_fo_g_j4 / N_anti_electron_veto_AND_fo_q_j4 << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_g_j4) + sqrt(err_N_anti_electron_veto_AND_fo_q_j4) * N_anti_electron_veto_AND_fo_g_j4 / N_anti_electron_veto_AND_fo_q_j4) / N_anti_electron_veto_AND_fo_q_j4  << endl;
    cout << "R^{ll/lq}=  " << N_2_anti_electron_veto_j4 / N_anti_electron_veto_AND_fo_q_j4 << " +/- " << (sqrt(err_N_2_anti_electron_veto_j4) + sqrt(err_N_anti_electron_veto_AND_fo_q_j4) * N_2_anti_electron_veto_j4 / N_anti_electron_veto_AND_fo_q_j4) / N_anti_electron_veto_AND_fo_q_j4 << endl;
    cout << "R^{qq/lq}=  " << N_2_fo_q_j4 / N_anti_electron_veto_AND_fo_q_j4 << " +/- " << (sqrt(err_N_2_fo_q_j4) + sqrt(err_N_anti_electron_veto_AND_fo_q_j4) * N_2_fo_q_j4 / N_anti_electron_veto_AND_fo_q_j4) / N_anti_electron_veto_AND_fo_q_j4 << endl;
    cout << "R^{gg/lq}=  " << N_2_fo_g_j4 / N_anti_electron_veto_AND_fo_q_j4 << " +/- " << (sqrt(err_N_2_fo_g_j4) + sqrt(err_N_anti_electron_veto_AND_fo_q_j4) * N_2_fo_g_j4 / N_anti_electron_veto_AND_fo_q_j4) / N_anti_electron_veto_AND_fo_q_j4 << endl;
    cout << "R^{qg/lq}=  " << N_fo_q_AND_fo_g_j4 / N_anti_electron_veto_AND_fo_q_j4 << " +/- " << (sqrt(err_N_fo_q_AND_fo_g_j4) + sqrt(err_N_anti_electron_veto_AND_fo_q_j4) * N_fo_q_AND_fo_g_j4 / N_anti_electron_veto_AND_fo_q_j4) / N_anti_electron_veto_AND_fo_q_j4 << endl; cout << endl;

    cout << "R^{lq/lg}=  " << N_anti_electron_veto_AND_fo_q_j4 / N_anti_electron_veto_AND_fo_g_j4 << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_q_j4) + sqrt(err_N_anti_electron_veto_AND_fo_g_j4) * N_anti_electron_veto_AND_fo_q_j4 / N_anti_electron_veto_AND_fo_g_j4) / N_anti_electron_veto_AND_fo_g_j4 << endl;
    cout << "R^{ll/lg}=  " << N_2_anti_electron_veto_j4 / N_anti_electron_veto_AND_fo_g_j4 << " +/- " << (sqrt(err_N_2_anti_electron_veto_j4) + sqrt(err_N_anti_electron_veto_AND_fo_g_j4) * N_2_anti_electron_veto_j4 / N_anti_electron_veto_AND_fo_g_j4) / N_anti_electron_veto_AND_fo_g_j4 << endl;
    cout << "R^{qq/lg}=  " << N_2_fo_q_j4 / N_anti_electron_veto_AND_fo_g_j4 << " +/- " << (sqrt(err_N_2_fo_q_j4) + sqrt(err_N_anti_electron_veto_AND_fo_g_j4) * N_2_fo_q_j4 / N_anti_electron_veto_AND_fo_g_j4) / N_anti_electron_veto_AND_fo_g_j4 << endl;
    cout << "R^{gg/lg}=  " << N_2_fo_g_j4 / N_anti_electron_veto_AND_fo_g_j4 << " +/- " << (sqrt(err_N_2_fo_g_j4) + sqrt(err_N_anti_electron_veto_AND_fo_g_j4) * N_2_fo_g_j4 / N_anti_electron_veto_AND_fo_g_j4) / N_anti_electron_veto_AND_fo_g_j4 << endl;
    cout << "R^{qg/lg}=  " << N_fo_q_AND_fo_g_j4 / N_anti_electron_veto_AND_fo_g_j4 << " +/- " << (sqrt(err_N_fo_q_AND_fo_g_j4) + sqrt(err_N_anti_electron_veto_AND_fo_g_j4) * N_fo_q_AND_fo_g_j4 / N_anti_electron_veto_AND_fo_g_j4) / N_anti_electron_veto_AND_fo_g_j4 << endl; cout << endl;

    cout << "R^{lq/ll}=  " << N_anti_electron_veto_AND_fo_q_j4 / N_2_anti_electron_veto_j4 << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_q_j4) + sqrt(err_N_2_anti_electron_veto_j4) * N_anti_electron_veto_AND_fo_q_j4 / N_2_anti_electron_veto_j4) / N_2_anti_electron_veto_j4 << endl;
cout << "R^{lg/ll}=  " << N_anti_electron_veto_AND_fo_g_j4 / N_2_anti_electron_veto_j4 << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_g_j4) + sqrt(err_N_2_anti_electron_veto_j4) * N_anti_electron_veto_AND_fo_g_j4 / N_2_anti_electron_veto_j4) / N_2_anti_electron_veto_j4 << endl;
    cout << "R^{qq/ll}=  " << N_2_fo_q_j4 / N_2_anti_electron_veto_j4 << " +/- " << (sqrt(err_N_2_fo_q_j4) + sqrt(err_N_2_anti_electron_veto_j4) * N_2_fo_q_j4 / N_2_anti_electron_veto_j4) / N_2_anti_electron_veto_j4 << endl;
    cout << "R^{gg/ll}=  " << N_2_fo_g_j4 / N_2_anti_electron_veto_j4 << " +/- " << (sqrt(err_N_2_fo_g_j4) + sqrt(err_N_2_anti_electron_veto_j4) * N_2_fo_g_j4 / N_2_anti_electron_veto_j4) / N_2_anti_electron_veto_j4 << endl;
    cout << "R^{qg/ll}=  " << N_fo_q_AND_fo_g_j4 / N_2_anti_electron_veto_j4 << " +/- " << (sqrt(err_N_fo_q_AND_fo_g_j4) + sqrt(err_N_2_anti_electron_veto_j4) * N_fo_q_AND_fo_g_j4 / N_2_anti_electron_veto_j4) / N_2_anti_electron_veto_j4 << endl; cout << endl;

    cout << "R^{lq/qq}=  " << N_anti_electron_veto_AND_fo_q_j4 / N_2_fo_q_j4 << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_q_j4) + sqrt(err_N_2_fo_q_j4) * N_anti_electron_veto_AND_fo_q_j4 / N_2_fo_q_j4) / N_2_fo_q_j4 << endl;
    cout << "R^{lg/qq}=  " << N_anti_electron_veto_AND_fo_g_j4 / N_2_fo_q_j4 << " +/- " <<(sqrt(err_N_anti_electron_veto_AND_fo_g_j4) + sqrt(err_N_2_fo_q_j4) * N_anti_electron_veto_AND_fo_g_j4 / N_2_fo_q_j4) / N_2_fo_q_j4 << endl;
    cout << "R^{ll/qq}=  " << N_2_anti_electron_veto_j4 / N_2_fo_q_j4 << " +/- " << (sqrt(err_N_2_anti_electron_veto_j4) + sqrt(err_N_2_fo_q_j4) * N_2_anti_electron_veto_j4 / N_2_fo_q_j4) / N_2_fo_q_j4 << endl;
    cout << "R^{gg/qq}=  " << N_2_fo_g_j4 / N_2_fo_q_j4 << " +/- " << (sqrt(err_N_2_fo_g_j4) + sqrt(err_N_2_fo_q_j4) * N_2_fo_g_j4 / N_2_fo_q_j4) / N_2_fo_q_j4 << endl;
    cout << "R^{qg/qq}=  " << N_fo_q_AND_fo_g_j4 / N_2_fo_q_j4 << " +/- " << (sqrt(err_N_fo_q_AND_fo_g_j4) + sqrt(err_N_2_fo_q_j4) * N_fo_q_AND_fo_g_j4 / N_2_fo_q_j4) / N_2_fo_q_j4 << endl; cout << endl;

    cout << "R^{lq/gg}=  " << N_anti_electron_veto_AND_fo_q_j4 / N_2_fo_g_j4 << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_q_j4) + sqrt(err_N_2_fo_g_j4) * N_anti_electron_veto_AND_fo_q_j4 / N_2_fo_g_j4) / N_2_fo_g_j4 << endl;
    cout << "R^{lg/gg}=  " << N_anti_electron_veto_AND_fo_g_j4 / N_2_fo_g_j4 << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_g_j4) + sqrt(err_N_2_fo_g_j4) * N_anti_electron_veto_AND_fo_g_j4 / N_2_fo_g_j4) / N_2_fo_g_j4 << endl;
    cout << "R^{ll/gg}=  " << N_2_anti_electron_veto_j4 / N_2_fo_g_j4 << " +/- " << (sqrt(err_N_2_anti_electron_veto_j4) + sqrt(err_N_2_fo_g_j4) * N_2_anti_electron_veto_j4 / N_2_fo_g_j4) / N_2_fo_g_j4 << endl;
    cout << "R^{qq/gg}=  " << N_2_fo_q_j4 / N_2_fo_g_j4 << " +/- " << (sqrt(err_N_2_fo_q_j4) + sqrt(err_N_2_fo_g_j4) * N_2_fo_q_j4 / N_2_fo_g_j4) / N_2_fo_g_j4  << endl;
    cout << "R^{qg/gg}=  " << N_fo_q_AND_fo_g_j4 / N_2_fo_g_j4 << " +/- " << (sqrt(err_N_fo_q_AND_fo_g_j4) + sqrt(err_N_2_fo_g_j4) * N_fo_q_AND_fo_g_j4 / N_2_fo_g_j4) / N_2_fo_g_j4 << endl; cout << endl;

    cout << "R^{lq/qg}=  " << N_anti_electron_veto_AND_fo_q_j4 / N_fo_q_AND_fo_g_j4 << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_q_j4) + sqrt(err_N_fo_q_AND_fo_g_j4) * N_anti_electron_veto_AND_fo_q_j4 / N_fo_q_AND_fo_g_j4) / N_fo_q_AND_fo_g_j4 << endl;
    cout << "R^{lg/qg}=  " << N_anti_electron_veto_AND_fo_g_j4 / N_fo_q_AND_fo_g_j4 << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_g_j4) + sqrt(err_N_fo_q_AND_fo_g_j4) * N_anti_electron_veto_AND_fo_g_j4 / N_fo_q_AND_fo_g_j4) / N_fo_q_AND_fo_g_j4 << endl;
    cout << "R^{ll/qg}=  " << N_2_anti_electron_veto_j4 / N_fo_q_AND_fo_g_j4 << " +/- " << (sqrt(err_N_2_anti_electron_veto_j4) + sqrt(err_N_fo_q_AND_fo_g_j4) * N_2_anti_electron_veto_j4 / N_fo_q_AND_fo_g_j4) / N_fo_q_AND_fo_g_j4 << endl;
    cout << "R^{qq/qg}=  " << N_2_fo_q_j4 / N_fo_q_AND_fo_g_j4 << " +/- " << (sqrt(err_N_2_fo_q_j4) + sqrt(err_N_fo_q_AND_fo_g_j4) * N_2_fo_q_j4 / N_fo_q_AND_fo_g_j4) / N_fo_q_AND_fo_g_j4 << endl;
    cout << "R^{gg/qg}=  " << N_2_fo_g_j4 / N_fo_q_AND_fo_g_j4 << " +/- " << (sqrt(err_N_2_fo_g_j4) + sqrt(err_N_fo_q_AND_fo_g_j4) * N_2_fo_g_j4 / N_fo_q_AND_fo_g_j4) / N_fo_q_AND_fo_g_j4 << endl; cout << endl;

    cout << "R^{sg/sq}=  " << N_tight_AND_fo_g_j4 / N_tight_AND_fo_g_j4 << " +/- " << (sqrt(err_N_tight_AND_fo_g_j4) + sqrt(err_N_tight_AND_fo_g_j4) * N_tight_AND_fo_g_j4 / N_tight_AND_fo_g_j4) / N_tight_AND_fo_g_j4 << endl;
    cout << "R^{sl/sq}=  " << N_tight_AND_anti_electron_veto_j4 / N_tight_AND_fo_q_j4 << " +/- " << (sqrt(err_N_tight_AND_anti_electron_veto_j4) + sqrt(err_N_tight_AND_fo_q_j4) * N_tight_AND_anti_electron_veto_j4 / N_tight_AND_fo_q_j4) / N_tight_AND_fo_q_j4 << endl; cout << endl;

    cout << "R^{sg/sq}=  " << N_tight_AND_fo_g_j4 / N_tight_AND_fo_q_j4 << " +/- " << (sqrt(err_N_tight_AND_fo_g_j4) + sqrt(err_N_tight_AND_fo_q_j4) * N_anti_electron_veto_AND_fo_g_j4 / N_2_fo_g_j4) / N_2_fo_g_j4 << endl;
    cout << "R^{sl/sq}=  " << N_tight_AND_anti_electron_veto_j4 / N_tight_AND_fo_q_j4 << " +/- " << (sqrt(err_N_tight_AND_anti_electron_veto_j4) + sqrt(err_N_tight_AND_fo_q_j4) * N_tight_AND_anti_electron_veto_j4 / N_tight_AND_fo_q_j4) / N_tight_AND_fo_q_j4 << endl; cout << endl;

    cout << "R^{sq/sg}=  " << N_tight_AND_fo_q_j4 / N_tight_AND_fo_g_j4 << " +/- " << (sqrt(err_N_tight_AND_fo_q_j4) + sqrt(err_N_tight_AND_fo_g_j4) * N_tight_AND_fo_q_j4 / N_tight_AND_fo_g_j4) / N_tight_AND_fo_g_j4 << endl;
    cout << "R^{sl/sg}=  " << N_tight_AND_anti_electron_veto_j4 / N_tight_AND_fo_g_j4 << " +/- " << (sqrt(err_N_tight_AND_anti_electron_veto_j4) + sqrt(err_N_tight_AND_fo_g_j4) * N_tight_AND_anti_electron_veto_j4 / N_tight_AND_fo_g_j4) / N_tight_AND_fo_g_j4 << endl; cout << endl;

    cout << "R^{sq/sl}=  " << N_tight_AND_fo_q_j4 / N_tight_AND_anti_electron_veto_j4 << " +/- " << (sqrt(err_N_tight_AND_fo_q_j4) + sqrt(err_N_tight_AND_anti_electron_veto_j4) * N_tight_AND_fo_q_j4 / N_tight_AND_anti_electron_veto_j4) / N_tight_AND_anti_electron_veto_j4 << endl;
    cout << "R^{sg/sl}=  " << N_tight_AND_fo_g_j4 / N_tight_AND_anti_electron_veto_j4 << " +/- " <<  (sqrt(err_N_tight_AND_fo_g_j4) + sqrt(err_N_tight_AND_anti_electron_veto_j4) *  N_tight_AND_fo_g_j4 / N_tight_AND_anti_electron_veto_j4) / N_tight_AND_anti_electron_veto_j4  << endl; cout << endl;




    cout << "*********************" << endl;

    cout << "N_tight_AND_anti_electron_veto_j4_l: " << N_tight_AND_anti_electron_veto_j4_l << endl;
    cout << "N_tight_AND_fo_q_j4_l: " << N_tight_AND_fo_q_j4_l << endl;
    cout << "N_tight_AND_fo_g_j4_l: " << N_tight_AND_fo_g_j4_l << endl;
    cout << "N_fo_q_AND_fo_g_j4_l: " << N_fo_q_AND_fo_g_j4_l << endl;
    cout << "N_anti_electron_veto_AND_fo_g_j4_l: " << N_anti_electron_veto_AND_fo_g_j4_l << endl;
    cout << "N_anti_electron_veto_AND_fo_q_j4_l: " << N_anti_electron_veto_AND_fo_q_j4_l << endl;
    cout << "N_2_anti_electron_veto_j4_l: " << N_2_anti_electron_veto_j4_l << endl;
    cout << "N_2_fo_q_j4_l: " << N_2_fo_q_j4_l << endl;
    cout << "N_2_fo_g_j4_l: " << N_2_fo_g_j4_l << endl;

   cout << "R^{lg/lq}=  " << N_anti_electron_veto_AND_fo_g_j4_l / N_anti_electron_veto_AND_fo_q_j4_l << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_g_j4_l) + sqrt(err_N_anti_electron_veto_AND_fo_q_j4_l) * N_anti_electron_veto_AND_fo_g_j4_l / N_anti_electron_veto_AND_fo_q_j4_l) / N_anti_electron_veto_AND_fo_q_j4_l  << endl;
    cout << "R^{ll/lq}=  " << N_2_anti_electron_veto_j4_l / N_anti_electron_veto_AND_fo_q_j4_l << " +/- " << (sqrt(err_N_2_anti_electron_veto_j4_l) + sqrt(err_N_anti_electron_veto_AND_fo_q_j4_l) * N_2_anti_electron_veto_j4_l / N_anti_electron_veto_AND_fo_q_j4_l) / N_anti_electron_veto_AND_fo_q_j4_l << endl;
    cout << "R^{qq/lq}=  " << N_2_fo_q_j4_l / N_anti_electron_veto_AND_fo_q_j4_l << " +/- " << (sqrt(err_N_2_fo_q_j4_l) + sqrt(err_N_anti_electron_veto_AND_fo_q_j4_l) * N_2_fo_q_j4_l / N_anti_electron_veto_AND_fo_q_j4_l) / N_anti_electron_veto_AND_fo_q_j4_l << endl;
    cout << "R^{gg/lq}=  " << N_2_fo_g_j4_l / N_anti_electron_veto_AND_fo_q_j4_l << " +/- " << (sqrt(err_N_2_fo_g_j4_l) + sqrt(err_N_anti_electron_veto_AND_fo_q_j4_l) * N_2_fo_g_j4_l / N_anti_electron_veto_AND_fo_q_j4_l) / N_anti_electron_veto_AND_fo_q_j4_l << endl;
    cout << "R^{qg/lq}=  " << N_fo_q_AND_fo_g_j4_l / N_anti_electron_veto_AND_fo_q_j4_l << " +/- " << (sqrt(err_N_fo_q_AND_fo_g_j4_l) + sqrt(err_N_anti_electron_veto_AND_fo_q_j4_l) * N_fo_q_AND_fo_g_j4_l / N_anti_electron_veto_AND_fo_q_j4_l) / N_anti_electron_veto_AND_fo_q_j4_l << endl; cout << endl;

    cout << "R^{lq/lg}=  " << N_anti_electron_veto_AND_fo_q_j4_l / N_anti_electron_veto_AND_fo_g_j4_l << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_q_j4_l) + sqrt(err_N_anti_electron_veto_AND_fo_g_j4_l) * N_anti_electron_veto_AND_fo_q_j4_l / N_anti_electron_veto_AND_fo_g_j4_l) / N_anti_electron_veto_AND_fo_g_j4_l << endl;
    cout << "R^{ll/lg}=  " << N_2_anti_electron_veto_j4_l / N_anti_electron_veto_AND_fo_g_j4_l << " +/- " << (sqrt(err_N_2_anti_electron_veto_j4_l) + sqrt(err_N_anti_electron_veto_AND_fo_g_j4_l) * N_2_anti_electron_veto_j4_l / N_anti_electron_veto_AND_fo_g_j4_l) / N_anti_electron_veto_AND_fo_g_j4_l << endl;
    cout << "R^{qq/lg}=  " << N_2_fo_q_j4_l / N_anti_electron_veto_AND_fo_g_j4_l << " +/- " << (sqrt(err_N_2_fo_q_j4_l) + sqrt(err_N_anti_electron_veto_AND_fo_g_j4_l) * N_2_fo_q_j4_l / N_anti_electron_veto_AND_fo_g_j4_l) / N_anti_electron_veto_AND_fo_g_j4_l << endl;
    cout << "R^{gg/lg}=  " << N_2_fo_g_j4_l / N_anti_electron_veto_AND_fo_g_j4_l << " +/- " << (sqrt(err_N_2_fo_g_j4_l) + sqrt(err_N_anti_electron_veto_AND_fo_g_j4_l) * N_2_fo_g_j4_l / N_anti_electron_veto_AND_fo_g_j4_l) / N_anti_electron_veto_AND_fo_g_j4_l << endl;
    cout << "R^{qg/lg}=  " << N_fo_q_AND_fo_g_j4_l / N_anti_electron_veto_AND_fo_g_j4_l << " +/- " << (sqrt(err_N_fo_q_AND_fo_g_j4_l) + sqrt(err_N_anti_electron_veto_AND_fo_g_j4_l) * N_fo_q_AND_fo_g_j4_l / N_anti_electron_veto_AND_fo_g_j4_l) / N_anti_electron_veto_AND_fo_g_j4_l << endl; cout << endl;

    cout << "R^{lq/ll}=  " << N_anti_electron_veto_AND_fo_q_j4_l / N_2_anti_electron_veto_j4_l << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_q_j4_l) + sqrt(err_N_2_anti_electron_veto_j4_l) * N_anti_electron_veto_AND_fo_q_j4_l / N_2_anti_electron_veto_j4_l) / N_2_anti_electron_veto_j4_l << endl;
cout << "R^{lg/ll}=  " << N_anti_electron_veto_AND_fo_g_j4_l / N_2_anti_electron_veto_j4_l << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_g_j4_l) + sqrt(err_N_2_anti_electron_veto_j4_l) * N_anti_electron_veto_AND_fo_g_j4_l / N_2_anti_electron_veto_j4_l) / N_2_anti_electron_veto_j4_l << endl;
    cout << "R^{qq/ll}=  " << N_2_fo_q_j4_l / N_2_anti_electron_veto_j4_l << " +/- " << (sqrt(err_N_2_fo_q_j4_l) + sqrt(err_N_2_anti_electron_veto_j4_l) * N_2_fo_q_j4_l / N_2_anti_electron_veto_j4_l) / N_2_anti_electron_veto_j4_l << endl;
    cout << "R^{gg/ll}=  " << N_2_fo_g_j4_l / N_2_anti_electron_veto_j4_l << " +/- " << (sqrt(err_N_2_fo_g_j4_l) + sqrt(err_N_2_anti_electron_veto_j4_l) * N_2_fo_g_j4_l / N_2_anti_electron_veto_j4_l) / N_2_anti_electron_veto_j4_l << endl;
    cout << "R^{qg/ll}=  " << N_fo_q_AND_fo_g_j4_l / N_2_anti_electron_veto_j4_l << " +/- " << (sqrt(err_N_fo_q_AND_fo_g_j4_l) + sqrt(err_N_2_anti_electron_veto_j4_l) * N_fo_q_AND_fo_g_j4_l / N_2_anti_electron_veto_j4_l) / N_2_anti_electron_veto_j4_l << endl; cout << endl;

    cout << "R^{lq/qq}=  " << N_anti_electron_veto_AND_fo_q_j4_l / N_2_fo_q_j4_l << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_q_j4_l) + sqrt(err_N_2_fo_q_j4_l) * N_anti_electron_veto_AND_fo_q_j4_l / N_2_fo_q_j4_l) / N_2_fo_q_j4_l << endl;
    cout << "R^{lg/qq}=  " << N_anti_electron_veto_AND_fo_g_j4_l / N_2_fo_q_j4_l << " +/- " <<(sqrt(err_N_anti_electron_veto_AND_fo_g_j4_l) + sqrt(err_N_2_fo_q_j4_l) * N_anti_electron_veto_AND_fo_g_j4_l / N_2_fo_q_j4_l) / N_2_fo_q_j4_l << endl;
    cout << "R^{ll/qq}=  " << N_2_anti_electron_veto_j4_l / N_2_fo_q_j4_l << " +/- " << (sqrt(err_N_2_anti_electron_veto_j4_l) + sqrt(err_N_2_fo_q_j4_l) * N_2_anti_electron_veto_j4_l / N_2_fo_q_j4_l) / N_2_fo_q_j4_l << endl;
    cout << "R^{gg/qq}=  " << N_2_fo_g_j4_l / N_2_fo_q_j4_l << " +/- " << (sqrt(err_N_2_fo_g_j4_l) + sqrt(err_N_2_fo_q_j4_l) * N_2_fo_g_j4_l / N_2_fo_q_j4_l) / N_2_fo_q_j4_l << endl;
    cout << "R^{qg/qq}=  " << N_fo_q_AND_fo_g_j4_l / N_2_fo_q_j4_l << " +/- " << (sqrt(err_N_fo_q_AND_fo_g_j4_l) + sqrt(err_N_2_fo_q_j4_l) * N_fo_q_AND_fo_g_j4_l / N_2_fo_q_j4_l) / N_2_fo_q_j4_l << endl; cout << endl;

    cout << "R^{lq/gg}=  " << N_anti_electron_veto_AND_fo_q_j4_l / N_2_fo_g_j4_l << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_q_j4_l) + sqrt(err_N_2_fo_g_j4_l) * N_anti_electron_veto_AND_fo_q_j4_l / N_2_fo_g_j4_l) / N_2_fo_g_j4_l << endl;
    cout << "R^{lg/gg}=  " << N_anti_electron_veto_AND_fo_g_j4_l / N_2_fo_g_j4_l << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_g_j4_l) + sqrt(err_N_2_fo_g_j4_l) * N_anti_electron_veto_AND_fo_g_j4_l / N_2_fo_g_j4_l) / N_2_fo_g_j4_l << endl;
    cout << "R^{ll/gg}=  " << N_2_anti_electron_veto_j4_l / N_2_fo_g_j4_l << " +/- " << (sqrt(err_N_2_anti_electron_veto_j4_l) + sqrt(err_N_2_fo_g_j4_l) * N_2_anti_electron_veto_j4_l / N_2_fo_g_j4_l) / N_2_fo_g_j4_l << endl;
    cout << "R^{qq/gg}=  " << N_2_fo_q_j4_l / N_2_fo_g_j4_l << " +/- " << (sqrt(err_N_2_fo_q_j4_l) + sqrt(err_N_2_fo_g_j4_l) * N_2_fo_q_j4_l / N_2_fo_g_j4_l) / N_2_fo_g_j4_l  << endl;
    cout << "R^{qg/gg}=  " << N_fo_q_AND_fo_g_j4_l / N_2_fo_g_j4_l << " +/- " << (sqrt(err_N_fo_q_AND_fo_g_j4_l) + sqrt(err_N_2_fo_g_j4_l) * N_fo_q_AND_fo_g_j4_l / N_2_fo_g_j4_l) / N_2_fo_g_j4_l << endl; cout << endl;

    cout << "R^{lq/qg}=  " << N_anti_electron_veto_AND_fo_q_j4_l / N_fo_q_AND_fo_g_j4_l << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_q_j4_l) + sqrt(err_N_fo_q_AND_fo_g_j4_l) * N_anti_electron_veto_AND_fo_q_j4_l / N_fo_q_AND_fo_g_j4_l) / N_fo_q_AND_fo_g_j4_l << endl;
    cout << "R^{lg/qg}=  " << N_anti_electron_veto_AND_fo_g_j4_l / N_fo_q_AND_fo_g_j4_l << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_g_j4_l) + sqrt(err_N_fo_q_AND_fo_g_j4_l) * N_anti_electron_veto_AND_fo_g_j4_l / N_fo_q_AND_fo_g_j4_l) / N_fo_q_AND_fo_g_j4_l << endl;
    cout << "R^{ll/qg}=  " << N_2_anti_electron_veto_j4_l / N_fo_q_AND_fo_g_j4_l << " +/- " << (sqrt(err_N_2_anti_electron_veto_j4_l) + sqrt(err_N_fo_q_AND_fo_g_j4_l) * N_2_anti_electron_veto_j4_l / N_fo_q_AND_fo_g_j4_l) / N_fo_q_AND_fo_g_j4_l << endl;
    cout << "R^{qq/qg}=  " << N_2_fo_q_j4_l / N_fo_q_AND_fo_g_j4_l << " +/- " << (sqrt(err_N_2_fo_q_j4_l) + sqrt(err_N_fo_q_AND_fo_g_j4_l) * N_2_fo_q_j4_l / N_fo_q_AND_fo_g_j4_l) / N_fo_q_AND_fo_g_j4_l << endl;
    cout << "R^{gg/qg}=  " << N_2_fo_g_j4_l / N_fo_q_AND_fo_g_j4_l << " +/- " << (sqrt(err_N_2_fo_g_j4_l) + sqrt(err_N_fo_q_AND_fo_g_j4_l) * N_2_fo_g_j4_l / N_fo_q_AND_fo_g_j4_l) / N_fo_q_AND_fo_g_j4_l << endl; cout << endl;

    cout << "R^{sg/sq}=  " << N_tight_AND_fo_g_j4_l / N_tight_AND_fo_g_j4_l << " +/- " << (sqrt(err_N_tight_AND_fo_g_j4_l) + sqrt(err_N_tight_AND_fo_g_j4_l) * N_tight_AND_fo_g_j4_l / N_tight_AND_fo_g_j4_l) / N_tight_AND_fo_g_j4_l << endl;
    cout << "R^{sl/sq}=  " << N_tight_AND_anti_electron_veto_j4_l / N_tight_AND_fo_q_j4_l << " +/- " << (sqrt(err_N_tight_AND_anti_electron_veto_j4_l) + sqrt(err_N_tight_AND_fo_q_j4_l) * N_tight_AND_anti_electron_veto_j4_l / N_tight_AND_fo_q_j4_l) / N_tight_AND_fo_q_j4_l << endl; cout << endl;

    cout << "R^{sg/sq}=  " << N_tight_AND_fo_g_j4_l / N_tight_AND_fo_q_j4_l << " +/- " << (sqrt(err_N_tight_AND_fo_g_j4_l) + sqrt(err_N_tight_AND_fo_q_j4_l) * N_anti_electron_veto_AND_fo_g_j4_l / N_2_fo_g_j4_l) / N_2_fo_g_j4_l << endl;
    cout << "R^{sl/sq}=  " << N_tight_AND_anti_electron_veto_j4_l / N_tight_AND_fo_q_j4_l << " +/- " << (sqrt(err_N_tight_AND_anti_electron_veto_j4_l) + sqrt(err_N_tight_AND_fo_q_j4_l) * N_tight_AND_anti_electron_veto_j4_l / N_tight_AND_fo_q_j4_l) / N_tight_AND_fo_q_j4_l << endl; cout << endl;

    cout << "R^{sq/sg}=  " << N_tight_AND_fo_q_j4_l / N_tight_AND_fo_g_j4_l << " +/- " << (sqrt(err_N_tight_AND_fo_q_j4_l) + sqrt(err_N_tight_AND_fo_g_j4_l) * N_tight_AND_fo_q_j4_l / N_tight_AND_fo_g_j4_l) / N_tight_AND_fo_g_j4_l << endl;
    cout << "R^{sl/sg}=  " << N_tight_AND_anti_electron_veto_j4_l / N_tight_AND_fo_g_j4_l << " +/- " << (sqrt(err_N_tight_AND_anti_electron_veto_j4_l) + sqrt(err_N_tight_AND_fo_g_j4_l) * N_tight_AND_anti_electron_veto_j4_l / N_tight_AND_fo_g_j4_l) / N_tight_AND_fo_g_j4_l << endl; cout << endl;

    cout << "R^{sq/sl}=  " << N_tight_AND_fo_q_j4_l / N_tight_AND_anti_electron_veto_j4_l << " +/- " << (sqrt(err_N_tight_AND_fo_q_j4_l) + sqrt(err_N_tight_AND_anti_electron_veto_j4_l) * N_tight_AND_fo_q_j4_l / N_tight_AND_anti_electron_veto_j4_l) / N_tight_AND_anti_electron_veto_j4_l << endl;
    cout << "R^{sg/sl}=  " << N_tight_AND_fo_g_j4_l / N_tight_AND_anti_electron_veto_j4_l << " +/- " <<  (sqrt(err_N_tight_AND_fo_g_j4_l) + sqrt(err_N_tight_AND_anti_electron_veto_j4_l) *  N_tight_AND_fo_g_j4_l / N_tight_AND_anti_electron_veto_j4_l) / N_tight_AND_anti_electron_veto_j4_l  << endl; cout << endl;   cout << "R^{lg/lq}=  " << N_anti_electron_veto_AND_fo_g_j4_l / N_anti_electron_veto_AND_fo_q_j4_l << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_g_j4_l) + sqrt(err_N_anti_electron_veto_AND_fo_q_j4_l) * N_anti_electron_veto_AND_fo_g_j4_l / N_anti_electron_veto_AND_fo_q_j4_l) / N_anti_electron_veto_AND_fo_q_j4_l  << endl;
    cout << "R^{ll/lq}=  " << N_2_anti_electron_veto_j4_l / N_anti_electron_veto_AND_fo_q_j4_l << " +/- " << (sqrt(err_N_2_anti_electron_veto_j4_l) + sqrt(err_N_anti_electron_veto_AND_fo_q_j4_l) * N_2_anti_electron_veto_j4_l / N_anti_electron_veto_AND_fo_q_j4_l) / N_anti_electron_veto_AND_fo_q_j4_l << endl;
    cout << "R^{qq/lq}=  " << N_2_fo_q_j4_l / N_anti_electron_veto_AND_fo_q_j4_l << " +/- " << (sqrt(err_N_2_fo_q_j4_l) + sqrt(err_N_anti_electron_veto_AND_fo_q_j4_l) * N_2_fo_q_j4_l / N_anti_electron_veto_AND_fo_q_j4_l) / N_anti_electron_veto_AND_fo_q_j4_l << endl;
    cout << "R^{gg/lq}=  " << N_2_fo_g_j4_l / N_anti_electron_veto_AND_fo_q_j4_l << " +/- " << (sqrt(err_N_2_fo_g_j4_l) + sqrt(err_N_anti_electron_veto_AND_fo_q_j4_l) * N_2_fo_g_j4_l / N_anti_electron_veto_AND_fo_q_j4_l) / N_anti_electron_veto_AND_fo_q_j4_l << endl;
    cout << "R^{qg/lq}=  " << N_fo_q_AND_fo_g_j4_l / N_anti_electron_veto_AND_fo_q_j4_l << " +/- " << (sqrt(err_N_fo_q_AND_fo_g_j4_l) + sqrt(err_N_anti_electron_veto_AND_fo_q_j4_l) * N_fo_q_AND_fo_g_j4_l / N_anti_electron_veto_AND_fo_q_j4_l) / N_anti_electron_veto_AND_fo_q_j4_l << endl; cout << endl;

    cout << "R^{lq/lg}=  " << N_anti_electron_veto_AND_fo_q_j4_l / N_anti_electron_veto_AND_fo_g_j4_l << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_q_j4_l) + sqrt(err_N_anti_electron_veto_AND_fo_g_j4_l) * N_anti_electron_veto_AND_fo_q_j4_l / N_anti_electron_veto_AND_fo_g_j4_l) / N_anti_electron_veto_AND_fo_g_j4_l << endl;
    cout << "R^{ll/lg}=  " << N_2_anti_electron_veto_j4_l / N_anti_electron_veto_AND_fo_g_j4_l << " +/- " << (sqrt(err_N_2_anti_electron_veto_j4_l) + sqrt(err_N_anti_electron_veto_AND_fo_g_j4_l) * N_2_anti_electron_veto_j4_l / N_anti_electron_veto_AND_fo_g_j4_l) / N_anti_electron_veto_AND_fo_g_j4_l << endl;
    cout << "R^{qq/lg}=  " << N_2_fo_q_j4_l / N_anti_electron_veto_AND_fo_g_j4_l << " +/- " << (sqrt(err_N_2_fo_q_j4_l) + sqrt(err_N_anti_electron_veto_AND_fo_g_j4_l) * N_2_fo_q_j4_l / N_anti_electron_veto_AND_fo_g_j4_l) / N_anti_electron_veto_AND_fo_g_j4_l << endl;
    cout << "R^{gg/lg}=  " << N_2_fo_g_j4_l / N_anti_electron_veto_AND_fo_g_j4_l << " +/- " << (sqrt(err_N_2_fo_g_j4_l) + sqrt(err_N_anti_electron_veto_AND_fo_g_j4_l) * N_2_fo_g_j4_l / N_anti_electron_veto_AND_fo_g_j4_l) / N_anti_electron_veto_AND_fo_g_j4_l << endl;
    cout << "R^{qg/lg}=  " << N_fo_q_AND_fo_g_j4_l / N_anti_electron_veto_AND_fo_g_j4_l << " +/- " << (sqrt(err_N_fo_q_AND_fo_g_j4_l) + sqrt(err_N_anti_electron_veto_AND_fo_g_j4_l) * N_fo_q_AND_fo_g_j4_l / N_anti_electron_veto_AND_fo_g_j4_l) / N_anti_electron_veto_AND_fo_g_j4_l << endl; cout << endl;

    cout << "R^{lq/ll}=  " << N_anti_electron_veto_AND_fo_q_j4_l / N_2_anti_electron_veto_j4_l << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_q_j4_l) + sqrt(err_N_2_anti_electron_veto_j4_l) * N_anti_electron_veto_AND_fo_q_j4_l / N_2_anti_electron_veto_j4_l) / N_2_anti_electron_veto_j4_l << endl;
cout << "R^{lg/ll}=  " << N_anti_electron_veto_AND_fo_g_j4_l / N_2_anti_electron_veto_j4_l << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_g_j4_l) + sqrt(err_N_2_anti_electron_veto_j4_l) * N_anti_electron_veto_AND_fo_g_j4_l / N_2_anti_electron_veto_j4_l) / N_2_anti_electron_veto_j4_l << endl;
    cout << "R^{qq/ll}=  " << N_2_fo_q_j4_l / N_2_anti_electron_veto_j4_l << " +/- " << (sqrt(err_N_2_fo_q_j4_l) + sqrt(err_N_2_anti_electron_veto_j4_l) * N_2_fo_q_j4_l / N_2_anti_electron_veto_j4_l) / N_2_anti_electron_veto_j4_l << endl;
    cout << "R^{gg/ll}=  " << N_2_fo_g_j4_l / N_2_anti_electron_veto_j4_l << " +/- " << (sqrt(err_N_2_fo_g_j4_l) + sqrt(err_N_2_anti_electron_veto_j4_l) * N_2_fo_g_j4_l / N_2_anti_electron_veto_j4_l) / N_2_anti_electron_veto_j4_l << endl;
    cout << "R^{qg/ll}=  " << N_fo_q_AND_fo_g_j4_l / N_2_anti_electron_veto_j4_l << " +/- " << (sqrt(err_N_fo_q_AND_fo_g_j4_l) + sqrt(err_N_2_anti_electron_veto_j4_l) * N_fo_q_AND_fo_g_j4_l / N_2_anti_electron_veto_j4_l) / N_2_anti_electron_veto_j4_l << endl; cout << endl;

    cout << "R^{lq/qq}=  " << N_anti_electron_veto_AND_fo_q_j4_l / N_2_fo_q_j4_l << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_q_j4_l) + sqrt(err_N_2_fo_q_j4_l) * N_anti_electron_veto_AND_fo_q_j4_l / N_2_fo_q_j4_l) / N_2_fo_q_j4_l << endl;
    cout << "R^{lg/qq}=  " << N_anti_electron_veto_AND_fo_g_j4_l / N_2_fo_q_j4_l << " +/- " <<(sqrt(err_N_anti_electron_veto_AND_fo_g_j4_l) + sqrt(err_N_2_fo_q_j4_l) * N_anti_electron_veto_AND_fo_g_j4_l / N_2_fo_q_j4_l) / N_2_fo_q_j4_l << endl;
    cout << "R^{ll/qq}=  " << N_2_anti_electron_veto_j4_l / N_2_fo_q_j4_l << " +/- " << (sqrt(err_N_2_anti_electron_veto_j4_l) + sqrt(err_N_2_fo_q_j4_l) * N_2_anti_electron_veto_j4_l / N_2_fo_q_j4_l) / N_2_fo_q_j4_l << endl;
    cout << "R^{gg/qq}=  " << N_2_fo_g_j4_l / N_2_fo_q_j4_l << " +/- " << (sqrt(err_N_2_fo_g_j4_l) + sqrt(err_N_2_fo_q_j4_l) * N_2_fo_g_j4_l / N_2_fo_q_j4_l) / N_2_fo_q_j4_l << endl;
    cout << "R^{qg/qq}=  " << N_fo_q_AND_fo_g_j4_l / N_2_fo_q_j4_l << " +/- " << (sqrt(err_N_fo_q_AND_fo_g_j4_l) + sqrt(err_N_2_fo_q_j4_l) * N_fo_q_AND_fo_g_j4_l / N_2_fo_q_j4_l) / N_2_fo_q_j4_l << endl; cout << endl;

    cout << "R^{lq/gg}=  " << N_anti_electron_veto_AND_fo_q_j4_l / N_2_fo_g_j4_l << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_q_j4_l) + sqrt(err_N_2_fo_g_j4_l) * N_anti_electron_veto_AND_fo_q_j4_l / N_2_fo_g_j4_l) / N_2_fo_g_j4_l << endl;
    cout << "R^{lg/gg}=  " << N_anti_electron_veto_AND_fo_g_j4_l / N_2_fo_g_j4_l << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_g_j4_l) + sqrt(err_N_2_fo_g_j4_l) * N_anti_electron_veto_AND_fo_g_j4_l / N_2_fo_g_j4_l) / N_2_fo_g_j4_l << endl;
    cout << "R^{ll/gg}=  " << N_2_anti_electron_veto_j4_l / N_2_fo_g_j4_l << " +/- " << (sqrt(err_N_2_anti_electron_veto_j4_l) + sqrt(err_N_2_fo_g_j4_l) * N_2_anti_electron_veto_j4_l / N_2_fo_g_j4_l) / N_2_fo_g_j4_l << endl;
    cout << "R^{qq/gg}=  " << N_2_fo_q_j4_l / N_2_fo_g_j4_l << " +/- " << (sqrt(err_N_2_fo_q_j4_l) + sqrt(err_N_2_fo_g_j4_l) * N_2_fo_q_j4_l / N_2_fo_g_j4_l) / N_2_fo_g_j4_l  << endl;
    cout << "R^{qg/gg}=  " << N_fo_q_AND_fo_g_j4_l / N_2_fo_g_j4_l << " +/- " << (sqrt(err_N_fo_q_AND_fo_g_j4_l) + sqrt(err_N_2_fo_g_j4_l) * N_fo_q_AND_fo_g_j4_l / N_2_fo_g_j4_l) / N_2_fo_g_j4_l << endl; cout << endl;

    cout << "R^{lq/qg}=  " << N_anti_electron_veto_AND_fo_q_j4_l / N_fo_q_AND_fo_g_j4_l << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_q_j4_l) + sqrt(err_N_fo_q_AND_fo_g_j4_l) * N_anti_electron_veto_AND_fo_q_j4_l / N_fo_q_AND_fo_g_j4_l) / N_fo_q_AND_fo_g_j4_l << endl;
    cout << "R^{lg/qg}=  " << N_anti_electron_veto_AND_fo_g_j4_l / N_fo_q_AND_fo_g_j4_l << " +/- " << (sqrt(err_N_anti_electron_veto_AND_fo_g_j4_l) + sqrt(err_N_fo_q_AND_fo_g_j4_l) * N_anti_electron_veto_AND_fo_g_j4_l / N_fo_q_AND_fo_g_j4_l) / N_fo_q_AND_fo_g_j4_l << endl;
    cout << "R^{ll/qg}=  " << N_2_anti_electron_veto_j4_l / N_fo_q_AND_fo_g_j4_l << " +/- " << (sqrt(err_N_2_anti_electron_veto_j4_l) + sqrt(err_N_fo_q_AND_fo_g_j4_l) * N_2_anti_electron_veto_j4_l / N_fo_q_AND_fo_g_j4_l) / N_fo_q_AND_fo_g_j4_l << endl;
    cout << "R^{qq/qg}=  " << N_2_fo_q_j4_l / N_fo_q_AND_fo_g_j4_l << " +/- " << (sqrt(err_N_2_fo_q_j4_l) + sqrt(err_N_fo_q_AND_fo_g_j4_l) * N_2_fo_q_j4_l / N_fo_q_AND_fo_g_j4_l) / N_fo_q_AND_fo_g_j4_l << endl;
    cout << "R^{gg/qg}=  " << N_2_fo_g_j4_l / N_fo_q_AND_fo_g_j4_l << " +/- " << (sqrt(err_N_2_fo_g_j4_l) + sqrt(err_N_fo_q_AND_fo_g_j4_l) * N_2_fo_g_j4_l / N_fo_q_AND_fo_g_j4_l) / N_fo_q_AND_fo_g_j4_l << endl; cout << endl;

    cout << "R^{sg/sq}=  " << N_tight_AND_fo_g_j4_l / N_tight_AND_fo_g_j4_l << " +/- " << (sqrt(err_N_tight_AND_fo_g_j4_l) + sqrt(err_N_tight_AND_fo_g_j4_l) * N_tight_AND_fo_g_j4_l / N_tight_AND_fo_g_j4_l) / N_tight_AND_fo_g_j4_l << endl;
    cout << "R^{sl/sq}=  " << N_tight_AND_anti_electron_veto_j4_l / N_tight_AND_fo_q_j4_l << " +/- " << (sqrt(err_N_tight_AND_anti_electron_veto_j4_l) + sqrt(err_N_tight_AND_fo_q_j4_l) * N_tight_AND_anti_electron_veto_j4_l / N_tight_AND_fo_q_j4_l) / N_tight_AND_fo_q_j4_l << endl; cout << endl;

    cout << "R^{sg/sq}=  " << N_tight_AND_fo_g_j4_l / N_tight_AND_fo_q_j4_l << " +/- " << (sqrt(err_N_tight_AND_fo_g_j4_l) + sqrt(err_N_tight_AND_fo_q_j4_l) * N_anti_electron_veto_AND_fo_g_j4_l / N_2_fo_g_j4_l) / N_2_fo_g_j4_l << endl;
    cout << "R^{sl/sq}=  " << N_tight_AND_anti_electron_veto_j4_l / N_tight_AND_fo_q_j4_l << " +/- " << (sqrt(err_N_tight_AND_anti_electron_veto_j4_l) + sqrt(err_N_tight_AND_fo_q_j4_l) * N_tight_AND_anti_electron_veto_j4_l / N_tight_AND_fo_q_j4_l) / N_tight_AND_fo_q_j4_l << endl; cout << endl;

    cout << "R^{sq/sg}=  " << N_tight_AND_fo_q_j4_l / N_tight_AND_fo_g_j4_l << " +/- " << (sqrt(err_N_tight_AND_fo_q_j4_l) + sqrt(err_N_tight_AND_fo_g_j4_l) * N_tight_AND_fo_q_j4_l / N_tight_AND_fo_g_j4_l) / N_tight_AND_fo_g_j4_l << endl;
    cout << "R^{sl/sg}=  " << N_tight_AND_anti_electron_veto_j4_l / N_tight_AND_fo_g_j4_l << " +/- " << (sqrt(err_N_tight_AND_anti_electron_veto_j4_l) + sqrt(err_N_tight_AND_fo_g_j4_l) * N_tight_AND_anti_electron_veto_j4_l / N_tight_AND_fo_g_j4_l) / N_tight_AND_fo_g_j4_l << endl; cout << endl;

    cout << "R^{sq/sl}=  " << N_tight_AND_fo_q_j4_l / N_tight_AND_anti_electron_veto_j4_l << " +/- " << (sqrt(err_N_tight_AND_fo_q_j4_l) + sqrt(err_N_tight_AND_anti_electron_veto_j4_l) * N_tight_AND_fo_q_j4_l / N_tight_AND_anti_electron_veto_j4_l) / N_tight_AND_anti_electron_veto_j4_l << endl;
    cout << "R^{sg/sl}=  " << N_tight_AND_fo_g_j4_l / N_tight_AND_anti_electron_veto_j4_l << " +/- " <<  (sqrt(err_N_tight_AND_fo_g_j4_l) + sqrt(err_N_tight_AND_anti_electron_veto_j4_l) *  N_tight_AND_fo_g_j4_l / N_tight_AND_anti_electron_veto_j4_l) / N_tight_AND_anti_electron_veto_j4_l  << endl; cout << endl;







}
