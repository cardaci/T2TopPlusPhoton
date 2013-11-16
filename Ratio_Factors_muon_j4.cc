#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "interface/format.h"
#include "interface/RecoLeptonSelection.h"
#include "interface/RecoPhotonSelectionFO.h"
#include "interface/RecoPhotonSelection.h"
#include "interface/RecoPhotonSelectionNoElectronVeto.h"
#include "interface/RecoPhotonSelectionAntiElectronVeto.h"
#include "interface/RecoJetSelection.h"
#include "iostream"
#include "vector"
#include "TStyle.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "string.h"
#include "TLorentzVector.h"
#include "math.h"
#include "TROOT.h"
#include "TSystem.h"
#include <exception>
#include "fstream"
#include <map>

using namespace std;

void count_over_newfile(char *datatag = NULL);

void Ratio_Factors_muon_j4()
{
count_over_newfile("");
}

void count_over_newfile(char *datatag)
{      

    char buffer[1024];
    string sample_style_ = "reduce";
    string SAMPLE_folder="/data4/cardaci/skimmingFromJacky2/test/REDUCE_DATA2/";
    string folder = SAMPLE_folder+datatag;
    TChain *root = new TChain("bprimeKit/root");
    sprintf(buffer,"%s/reduce_SingleMu*.root",folder.c_str());

    std::cout<<"buffer : "<<buffer<<std::endl; 
    root->Add(buffer);

    printf("loading %s...\n",buffer);	

    EvtInfoBranches EvtInfo;
    LepInfoBranches LepInfo;
    JetInfoBranches JetInfo;
    PhotonInfoBranches PhotonInfo;
    EvtInfo.Register(root);
    LepInfo.Register(root,"PFLepInfo");
    JetInfo.Register(root,"PFJetInfo");
    PhotonInfo.Register(root,"PhotonInfo");
    VertexInfoBranches VertexInfo;
    VertexInfo.Register(root);

    int nevents = 0;
    int nevents_total = root->GetEntries();	
    printf("test entries : %i \n",nevents_total);


//    sprintf(buffer,"./REDUCE_DATA/%s_%s.root",sample_style_.c_str(),datatag);
//    std::cout<<buffer<<" " << datatag <<std::endl;

    /*
    TFile *newfile = new TFile(buffer,"recreate");
    newfile->mkdir("bprimeKit");
    newfile->cd("bprimeKit");
    TTree *newtree = root->CloneTree(0);
    */

        int N_tight_AND_anti_electron_veto = 0;

        int N_tight_AND_fo_q = 0;
        int N_tight_AND_fo_g = 0;

        int N_fo_q_AND_fo_g = 0;

        int N_anti_electron_veto_AND_fo_q = 0;
        int N_anti_electron_veto_AND_fo_g = 0;

        int N_2_anti_electron_veto = 0;

        int N_2_fo_q = 0;
        int N_2_fo_g = 0;



        int N_tight_AND_anti_electron_veto_j4 = 0;

        int N_tight_AND_fo_q_j4 = 0;
        int N_tight_AND_fo_g_j4 = 0;

        int N_fo_q_AND_fo_g_j4 = 0;

        int N_anti_electron_veto_AND_fo_q_j4 = 0;
        int N_anti_electron_veto_AND_fo_g_j4 = 0;

        int N_2_anti_electron_veto_j4 = 0;

        int N_2_fo_q_j4 = 0;
        int N_2_fo_g_j4 = 0;


        int N_tight_AND_anti_electron_veto_j4_l = 0;

        int N_tight_AND_fo_q_j4_l = 0;
        int N_tight_AND_fo_g_j4_l = 0;

        int N_fo_q_AND_fo_g_j4_l = 0;

        int N_anti_electron_veto_AND_fo_q_j4_l = 0;
        int N_anti_electron_veto_AND_fo_g_j4_l = 0;

        int N_2_anti_electron_veto_j4_l = 0;

        int N_2_fo_q_j4_l = 0;
        int N_2_fo_g_j4_l = 0;






    map< pair<int, int>, int > evtlist;
    for(int entry=0;entry<nevents_total;entry++) {		
        if ((entry%10000) == 0) 
            printf("Loading event #%d of %d.\n",entry,nevents_total);

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
	RecoPhotonSelection(LepInfo,PhotonInfo,NMuons,M_Index,NElectrons,E_Index,NPhotons,P_Index,EvtInfo.RhoPU[0]);


	int NJets = 0;
	int J_Index[MAX_JETS];
       	RecoJetSelection(LepInfo, JetInfo, PhotonInfo, NMuons, M_Index, NElectrons, E_Index, NJets, J_Index, NPhotons, P_Index);

	int NPhotons_FO = 0;
	int P_Index_FO[MAX_PHOTONS];
	for(int p=0;p<MAX_PHOTONS;p++) P_Index_FO[p] = 0; 
	RecoPhotonSelectionFO(LepInfo,PhotonInfo,NMuons,M_Index,NElectrons,E_Index,NPhotons_FO,P_Index_FO,EvtInfo.RhoPU[0]);
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


	int NPhotons_LOOSE = 0; 
	int P_Index_LOOSE[MAX_PHOTONS];
	for(int p=0;p<MAX_PHOTONS;p++) P_Index_LOOSE[p] = 0; 

	for(int p=0;p<NPhotons_FO;p++) { P_Index_LOOSE[NPhotons_LOOSE] = P_Index_FO[p]; NPhotons_LOOSE++;} 
	for(int p=0;p<NPhotons_NO_ELECTRON_VETO;p++) { 

		bool isduplicate = false;
		for(int p1=0;p1<NPhotons_FO;p1++){
			if(P_Index_NO_ELECTRON_VETO[p] == P_Index_FO[p1])
				isduplicate = true;
		} 

		if(!isduplicate){
			P_Index_LOOSE[NPhotons_LOOSE] = P_Index_NO_ELECTRON_VETO[p]; 
			NPhotons_LOOSE++;
		}
	} 



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









	if(NPhotons == 1 && NPhotons_ANTI_ELECTRON_VETO == 1) N_tight_AND_anti_electron_veto++;

	if(NPhotons == 1 && NPhotons_FO_q == 1) N_tight_AND_fo_q++;
	if(NPhotons == 1 && NPhotons_FO_g == 1) N_tight_AND_fo_g++;

	if(NPhotons_FO_q == 1 && NPhotons_FO_g == 1) N_fo_q_AND_fo_g++;

	if(NPhotons_ANTI_ELECTRON_VETO == 1 && NPhotons_FO_q == 1) N_anti_electron_veto_AND_fo_q++;
	if(NPhotons_ANTI_ELECTRON_VETO == 1 && NPhotons_FO_g == 1) N_anti_electron_veto_AND_fo_g++;

	if(NPhotons_ANTI_ELECTRON_VETO == 2) N_2_anti_electron_veto++;

	if(NPhotons_FO_q == 2) N_2_fo_q++;
	if(NPhotons_FO_g == 2) N_2_fo_g++;



        if(NJets >= 4){

	  if(NPhotons == 1 && NPhotons_ANTI_ELECTRON_VETO == 1) N_tight_AND_anti_electron_veto_j4++;

	  if(NPhotons == 1 && NPhotons_FO_q == 1) N_tight_AND_fo_q_j4++;
	  if(NPhotons == 1 && NPhotons_FO_g == 1) N_tight_AND_fo_g_j4++;

	  if(NPhotons_FO_q == 1 && NPhotons_FO_g == 1) N_fo_q_AND_fo_g_j4++;

	  if(NPhotons_ANTI_ELECTRON_VETO == 1 && NPhotons_FO_q == 1) N_anti_electron_veto_AND_fo_q_j4++;
	  if(NPhotons_ANTI_ELECTRON_VETO == 1 && NPhotons_FO_g == 1) N_anti_electron_veto_AND_fo_g_j4++;

	  if(NPhotons_ANTI_ELECTRON_VETO == 2) N_2_anti_electron_veto_j4++;

	  if(NPhotons_FO_q == 2) N_2_fo_q_j4++;
	  if(NPhotons_FO_g == 2) N_2_fo_g_j4++;

	}



        if(NJets >= 4 && dist_FO == true && dist_TIGHT == true && dist_NO_ELECTRON_VETO == true && dist_ANTI_ELECTRON_VETO == true){

	  if(NPhotons == 1 && NPhotons_ANTI_ELECTRON_VETO == 1) N_tight_AND_anti_electron_veto_j4_l++;

	  if(NPhotons == 1 && NPhotons_FO_q == 1) N_tight_AND_fo_q_j4_l++;
	  if(NPhotons == 1 && NPhotons_FO_g == 1) N_tight_AND_fo_g_j4_l++;

	  if(NPhotons_FO_q == 1 && NPhotons_FO_g == 1) N_fo_q_AND_fo_g_j4_l++;

	  if(NPhotons_ANTI_ELECTRON_VETO == 1 && NPhotons_FO_q == 1) N_anti_electron_veto_AND_fo_q_j4_l++;
	  if(NPhotons_ANTI_ELECTRON_VETO == 1 && NPhotons_FO_g == 1) N_anti_electron_veto_AND_fo_g_j4_l++;

	  if(NPhotons_ANTI_ELECTRON_VETO == 2) N_2_anti_electron_veto_j4_l++;

	  if(NPhotons_FO_q == 2) N_2_fo_q_j4_l++;
	  if(NPhotons_FO_g == 2) N_2_fo_g_j4_l++;

	}





	//        newtree->Fill(); // book this event to the new tree			
        nevents++;
    }

    cout << "N_tight_AND_anti_electron_veto: " << N_tight_AND_anti_electron_veto << endl;
    cout << "N_tight_AND_fo_q: " << N_tight_AND_fo_q << endl;
    cout << "N_tight_AND_fo_g: " << N_tight_AND_fo_g << endl;
    cout << "N_fo_q_AND_fo_g: " << N_fo_q_AND_fo_g << endl;
    cout << "N_anti_electron_veto_AND_fo_g: " << N_anti_electron_veto_AND_fo_g << endl;
    cout << "N_anti_electron_veto_AND_fo_q: " << N_anti_electron_veto_AND_fo_q << endl;
    cout << "N_2_anti_electron_veto: " << N_2_anti_electron_veto << endl;
    cout << "N_2_fo_q: " << N_2_fo_q << endl;
    cout << "N_2_fo_g: " << N_2_fo_g << endl;

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




//    printf("Finished - %d events saved from %d events.\n",nevents,nevents_total); 	
    //    newtree->Write();

    //    delete newtree;
    //    delete newfile;
}

