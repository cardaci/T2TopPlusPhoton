#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "interface/format.h"
#include "interface/RecoLeptonSelection.h"
#include "interface/RecoPhotonSelectionFO.h"
#include "interface/RecoPhotonSelection.h"
#include "interface/RecoPhotonSelectionNoElectronVeto.h"
#include "interface/RecoPhotonSelection_NoPtCut.h"
#include "interface/RecoPhotonSelectionFO_NoPtCut.h"              
#include "interface/RecoPhotonSelectionNoElectronVeto_NoPtCut.h"
#include "interface/RecoLeptonSelectionNoElectronPt.h" 
#include "interface/RecoLeptonSelection.h"
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

void do_reduce(char *datatag = NULL);

void reduce_SingleMuon()
{
do_reduce("SingleMu_Run2012A-22Jan2013-v1_190645-193621");

do_reduce("SingleMu_Run2012B-22Jan2013-v1_195834-196531");
do_reduce("SingleMu_Run2012B-22Jan2013-v1_193834-194833");
}

void do_reduce(char *datatag)
{      

    char buffer[1024];
    string sample_style_ = "reduce";
    string SAMPLE_folder="/BprimeKitNtuples/Production_CMSSW5311/CMSSW_5_3_11_data_8TeV_22Jan2013ReReco_AOD_v4/";
    string folder = SAMPLE_folder+datatag;
    TChain *root = new TChain("bprimeKit/root");
    sprintf(buffer,"%s/*.root",folder.c_str());

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


    sprintf(buffer,"./REDUCE_DATA/%s_%s.root",sample_style_.c_str(),datatag);
    std::cout<<buffer<<" " << datatag <<std::endl;

    TFile *newfile = new TFile(buffer,"recreate");
    newfile->mkdir("bprimeKit");
    newfile->cd("bprimeKit");
    TTree *newtree = root->CloneTree(0);

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

	int NPhotons_FO = 0;
	int P_Index_FO[MAX_PHOTONS];
	for(int p=0;p<MAX_PHOTONS;p++) P_Index_FO[p] = 0; 
	RecoPhotonSelectionFO(LepInfo,PhotonInfo,NMuons,M_Index,NElectrons,E_Index,NPhotons_FO,P_Index_FO,EvtInfo.RhoPU[0]);
        /*
	int NPhotons_FO = 0;
	int P_Index_FO[MAX_PHOTONS];
	for(int p=0;p<MAX_PHOTONS;p++) P_Index_FO[p] = 0; 
	RecoPhotonSelectionFO_NoPtCut(LepInfo,PhotonInfo,NMuons,M_Index,NElectrons,E_Index,NPhotons_FO,P_Index_FO,EvtInfo.RhoPU[0]);
	*/

	int NPhotons_NO_ELECTRON_VETO = 0;
	int P_Index_NO_ELECTRON_VETO[MAX_PHOTONS];
	for(int p=0;p<MAX_PHOTONS;p++) P_Index_NO_ELECTRON_VETO[p] = 0; 
	RecoPhotonSelectionNoElectronVeto(LepInfo,PhotonInfo,NMuons,M_Index,NElectrons,E_Index,NPhotons_NO_ELECTRON_VETO,P_Index_NO_ELECTRON_VETO,EvtInfo.RhoPU[0]);
        /*
	int NPhotons_NO_ELECTRON_VETO = 0;
	int P_Index_NO_ELECTRON_VETO[MAX_PHOTONS];
	for(int p=0;p<MAX_PHOTONS;p++) P_Index_NO_ELECTRON_VETO[p] = 0; 
	RecoPhotonSelectionNoElectronVeto_NoPtCut(LepInfo,PhotonInfo,NMuons,M_Index,NElectrons,E_Index,NPhotons_NO_ELECTRON_VETO,P_Index_NO_ELECTRON_VETO,EvtInfo.RhoPU[0]);
	*/

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

	if(!( NPhotons_NO_ELECTRON_VETO >= 1 || NPhotons_FO >= 1 || NPhotons_LOOSE == 2 )) continue;



        newtree->Fill(); // book this event to the new tree			
        nevents++;
    }

    printf("Finished - %d events saved from %d events.\n",nevents,nevents_total); 	
    newtree->Write();

    delete newtree;
    delete newfile;
}

