#include "TTree.h"
#include "TH1F.h"
#include "TH3D.h"
#include "TH2D.h"
#include "TFile.h"
#include "interface/format.h"
#include "interface/MCTruth.h"
#include "interface/TriggerBooking.h"
#include "interface/HitFitInfoBranches.h"
#include "interface/DPHI.h"
#include "interface/DR.h"
//#include "interface/samples_tr.h"
#include "interface/samples_tr_1lepton4jets.h"
//#include "interface/samples.h"
#include "interface/DRAWSTACK.h"
#include "interface/HistMerge.h"
#include "interface/checkEvt.h"
#include "interface/RecoLeptonSelection.h"
#include "interface/RecoPhotonSelection.h"
#include "interface/RecoJetSelection.h"
#include "interface/ReduceTree.h"
//#include "interface/TMVAClassification_CutsD.class.C"
#include "TChain.h"
#include "TNtuple.h"
#include "TLorentzVector.h"
#include "interface/RecoZbosonFordiPhoton.h"
#include <math.h>
#include <string>
#include <iostream>
#include "TCanvas.h"
#include "TROOT.h"
#include "TStyle.h"
#include "THStack.h"
#include "TLegend.h"
#include "stdlib.h"
#include <fstream>
#include <map>
#include <vector>
#include <time.h>
#include <math.h>
#include "interface/RecoZboson.h"
#include "interface/RecoMoflljj.h"
#include "interface/RecoMZb.h"


int RunStatus_ = Normal;   // Normal, UncXsecPlus, UncXsecMinus, UncPUPlus, UncPUMinus

double Weight3D_[50][50][50];

enum plots_order{
    _NOfVertexb4PU,
    _NOfVertexafPU,
    _Nj,
    _Np,
    _Ne,
    _Nu,
    _PhotonPt,
    _JetPt,
    _ElectronPt,
    _MuonPt,
    _ST,
    _ST2p2j,
    _ST2p2j1l,
    _ST2p2j2l,
    _MR2p2j,
    _Mtstar,
    _check,
    _RT,
    _Zmass,
    _plots_order_size
};

struct plots_struct{
    char PlotName[128];
    char YaxisTitle_[128];
    char XaxisTitle_[128];
    char XUnit_[128];
    int Ndivide_;
    double XminBond_;
    double XmaxBond_;
    int rebin_;
};

struct plots_struct PLOTS[_plots_order_size] = {
    {"_NOfVertexb4PU","Yields","N(Vertices)","-",30,0,30,1},
    {"_NOfVertexafPU","Yields","N(Vertices)","-",30,0,30,1},
    {"_Nj","Yields","N(jets)","-",11,0,11,1},
    {"_Np","Yields","N(photons)","-",11,0,11,1},
    {"_Ne","Yields","N(electrons)","-",11,0,11,1},
    {"_Nu","Yields","N(muons)","-",11,0,11,1},
    {"_PhotonPt","Yields","Photon Pt","GeV/c",200,0,200,5},
    {"_JetPt","Yields","Jet Pt","GeV/c",200,0,200,5},
    {"_ElectronPt","Yields","Electron Pt","GeV/c",200,0,200,5},
    {"_MuonPt","Yields","Muon Pt","GeV/c",200,0,200,5},
    {"_ST","Yields","ST","GeV/c",1800,200,2000,100},
    {"_ST2p2j","Yields","ST(2#gamma+2j channel)","GeV/c",1500,0,3000,100},
    {"_ST2p2j1l","Yields","ST(2#gamma+2j+1l channel)","GeV/c",1500,0,3000,100},
    {"_ST2p2j2l","Yields","ST(2#gamma+2j+2l channel)","GeV/c",1500,0,3000,100},
    {"_MR2p2j","Yields","MR(2#gamma+2j channel)","GeV/c^{2}",1500,0,3000,100},
    {"_Mtstar","Yields","M(t*)","GeV/c^{2}",1000,0,2000,10},
    {"_check","Yields","1","-",2,0,2,1},
    {"_RT","Yields","RT","GeV/c",200,0,200,10},
    {"_Zmass","Yields","M(l^{+}l^{-})","GeV/c^{2}",180,20,200,5}
};

/*
   For Excited Quark : 
   (lepb_label+Wlep+gluon1_label) = (hadb_label+hadw1_label+hadw2_label+gluon2_label)
   (11 + Wlep + 16 ) = (12 + 13 + 14 + 17)
   */

void analyze(int sample_idx,TH1F *ExcitedQuarkPlots[], TH2D *ExcitedQuark2DPlots, double weight_)
{

    TChain *root = new TChain("bprimeKit/root");
    root->Add(SAMPLE[sample_idx].filename);

    EvtInfoBranches EvtInfo;
    EvtInfo.Register(root);
    GenInfoBranches GenInfo;
    GenInfo.Register(root);
    LepInfoBranches LepInfo;
    LepInfo.Register(root,"PFLepInfo");
    JetInfoBranches JetInfo;
    JetInfo.Register(root,"PFJetInfo");
    VertexInfoBranches VertexInfo;
    VertexInfo.Register(root);
    PhotonInfoBranches PhotonInfo;
    PhotonInfo.Register(root);

    ReduceTree(root);

    double weight = weight_;

    //for(int i=0;i<_plots_order_size;i++) ExcitedQuarkPlots[i]->Sumw2();

    map< pair<int, int>, int > evtlist;
    int nevents_total = root->GetEntries();	
    for(int entry=0;entry<root->GetEntries();entry++) {
        if ((entry%10000) == 0)	printf("Loading event #%d of %d.\n",entry,nevents_total);
        root->GetEntry(entry);

        // Trigger requirement -- start --
        bool Trigee = false;
        bool Trigmm = false;
        bool Trigem = false;
        char DATA_TAG[128] ="data";
        if(!strcmp(SAMPLE[sample_idx].tag,DATA_TAG)){
        //if(!EvtInfo.McFlag) {

            //if(EvtInfo.RunNo>173692) continue;  // 2180.3 /pb

            //DoublePh
            if(EvtInfo.TrgBook[HLT_Photon36_CaloId10_Iso50_Photon22_CaloId10_Iso50_v3]==1)    Trigee = true;
            if(EvtInfo.TrgBook[HLT_Photon36_CaloId10_Iso50_Photon22_CaloId10_Iso50_v4]==1)    Trigee = true;
            if(EvtInfo.TrgBook[HLT_Photon36_CaloId10_Iso50_Photon22_CaloId10_Iso50_v5]==1)    Trigee = true;
            if(EvtInfo.TrgBook[HLT_Photon36_CaloId10_Iso50_Photon22_CaloId10_Iso50_v6]==1)    Trigee = true;

            // remove duplicate event
            map< pair<int, int> , int>::iterator evtitr;
            evtitr = evtlist.find( pair<int, int>(EvtInfo.RunNo, EvtInfo.EvtNo) );
            if( evtitr == evtlist.end() )
                evtlist.insert( pair<pair<int, int>, int>(pair<int, int>(EvtInfo.RunNo, EvtInfo.EvtNo), 1));
            else
                continue;

            // pick up good events according to golden json file
            if(!isGoodEvt(EvtInfo.RunNo,EvtInfo.LumiNo)) continue;
        }else{
            // For MC
            if(EvtInfo.TrgBook[HLT_Photon36_CaloId10_Iso50_Photon22_CaloId10_Iso50_v3]==1)    Trigee = true;
            if(EvtInfo.TrgBook[HLT_Photon36_CaloId10_Iso50_Photon22_CaloId10_Iso50_v4]==1)    Trigee = true;
            if(EvtInfo.TrgBook[HLT_Photon36_CaloId10_Iso50_Photon22_CaloId10_Iso50_v5]==1)    Trigee = true;
            if(EvtInfo.TrgBook[HLT_Photon36_CaloId10_Iso50_Photon22_CaloId10_Iso50_v6]==1)    Trigee = true;
        }
        //if(!(Trigee||Trigmm||Trigem)) continue;
        Trigee = true; // turn off HLT, since the samples are passing through single lepton trigger
        if(!Trigee) continue;
        // Trigger requirement -- end --


        // Object selection -- start --
        int NMuons = 0; 
        int NElectrons = 0; 
        int NLeptons = 0; 
        int NPhotons = 0; 
        int NJets = 0; 
        int M_Index[MAX_LEPTONS/2];
        int E_Index[MAX_LEPTONS/2];
        int L_Index[MAX_LEPTONS/2*2];
        int P_Index[MAX_PHOTONS];
        int J_Index[MAX_JETS];
        for(int m=0;m<MAX_LEPTONS/2;m++) M_Index[m] = 0; 
        for(int e=0;e<MAX_LEPTONS/2;e++) E_Index[e] = 0; 
        for(int l=0;l<MAX_LEPTONS/2*2;l++) L_Index[l] = 0; 
        for(int p=0;p<MAX_PHOTONS;p++) P_Index[p] = 0; 
        for(int j=0;j<MAX_JETS;j++) J_Index[j] = 0; 
        RecoLeptonSelection(EvtInfo,LepInfo,NMuons,M_Index,NElectrons,E_Index,NLeptons,L_Index);
        RecoPhotonSelection(LepInfo,PhotonInfo,NMuons,M_Index,NElectrons,E_Index,NPhotons,P_Index,EvtInfo.RhoPU[0]);
        RecoJetSelection(LepInfo,JetInfo, PhotonInfo,NMuons,M_Index,NElectrons,E_Index,NJets,J_Index,NPhotons,P_Index);


        if(!((NPhotons>=2)&&NJets>=2)) continue;
        // Object selection -- end --

        // number of vertex -- start --
        int NOfVertex_=0;
        int V_Index[50];
        for(int v=0;v<50;v++) V_Index[v] = 0;
        for(int j=0;j<VertexInfo.Size;j++) {
            if(VertexInfo.isValid[j]!=1) continue; 
            if(VertexInfo.Type[j]!=0) continue; 
            if(VertexInfo.Ndof[j]<=4) continue; 
            if(fabs(VertexInfo.Rho[j])>=2) continue; 
            if(fabs(VertexInfo.z[j])>=24) continue; 
            V_Index[NOfVertex_] = j;
            NOfVertex_++;
        }
        if(NOfVertex_<1) continue;
        //if(strcmp(SAMPLE[sample_idx].tag,DATA_TAG)) weight = weight_*Weight3D_[EvtInfo.nPU[0]][EvtInfo.nPU[1]][EvtInfo.nPU[2]];
        // number of vertex -- end --
        double _Zmass_ = RecoZboson(LepInfo,NMuons,M_Index,NElectrons,E_Index);
        ExcitedQuarkPlots[_NOfVertexb4PU]->Fill(NOfVertex_,weight_);
        ExcitedQuarkPlots[_NOfVertexafPU]->Fill(NOfVertex_,weight);

        double MassRecoZbosonFordiPhoton_ = RecoZbosonFordiPhoton(PhotonInfo,NPhotons,P_Index);
        if(fabs(MassRecoZbosonFordiPhoton_-Z_MASS)<10) continue;

        ExcitedQuarkPlots[_Nj]->Fill(NJets,weight);
        ExcitedQuarkPlots[_Np]->Fill(NPhotons,weight);
        ExcitedQuarkPlots[_Ne]->Fill(NElectrons,weight);
        ExcitedQuarkPlots[_Nu]->Fill(NMuons,weight);

        double _ST_ = 0.;
        for(int j=0;j<NJets;j++) _ST_ += JetInfo.Pt[J_Index[j]];
        for(int m=0;m<NMuons;m++) _ST_ += LepInfo.Pt[M_Index[m]];
        for(int e=0;e<NElectrons;e++) _ST_ += LepInfo.Pt[E_Index[e]];
        for(int p=0;p<NPhotons;p++) _ST_ += PhotonInfo.Pt[P_Index[p]];
        ExcitedQuarkPlots[_ST]->Fill(_ST_,weight);

        for(int j=0;j<NJets;j++) ExcitedQuarkPlots[_JetPt]->Fill(JetInfo.Pt[J_Index[j]],weight);
        for(int p=0;p<NPhotons;p++) ExcitedQuarkPlots[_PhotonPt]->Fill(PhotonInfo.Pt[P_Index[p]],weight);
        for(int e=0;e<NElectrons;e++) ExcitedQuarkPlots[_ElectronPt]->Fill(LepInfo.Pt[E_Index[e]],weight);
        for(int m=0;m<NMuons;m++) ExcitedQuarkPlots[_MuonPt]->Fill(LepInfo.Pt[M_Index[m]],weight);

        //if(NJets>=2&&NPhotons>=2) ExcitedQuarkPlots[_ST2p2j]->Fill(_ST_,weight);
        if(NJets>=2&&NPhotons>=2&&(NMuons+NElectrons)==1) ExcitedQuarkPlots[_ST2p2j1l]->Fill(_ST_,weight);
        if(NJets>=2&&NPhotons>=2&&(NMuons+NElectrons)>=2) ExcitedQuarkPlots[_ST2p2j2l]->Fill(_ST_,weight);

        TLorentzVector photons[2];
        photons[0].SetPtEtaPhiM(PhotonInfo.Pt[P_Index[0]],
                PhotonInfo.Eta[P_Index[0]],
                PhotonInfo.Phi[P_Index[0]],
                0);
        photons[1].SetPtEtaPhiM(PhotonInfo.Pt[P_Index[1]],
                PhotonInfo.Eta[P_Index[1]],
                PhotonInfo.Phi[P_Index[1]],
                0);
        //double MR_ = sqrt(pow(photons[0].E()+photons[1].E(),2)-pow(photons[0].Pz()+photons[1].Pz(),2));
        double MR_ = 0.0;
        MR_ = sqrt(pow(photons[0].E()+photons[1].E(),2)-pow(photons[0].Pz()+photons[1].Pz(),2));
        if(NJets>=2&&NPhotons==2){
            ExcitedQuarkPlots[_check]->Fill(1.0,weight);
            ExcitedQuarkPlots[_MR2p2j]->Fill(MR_,weight);
            ExcitedQuarkPlots[_ST2p2j]->Fill(_ST_,weight);

            ExcitedQuarkPlots[_Mtstar]->Fill(0.5*(MR_+sqrt(MR_*MR_+4*top_MASS*top_MASS)),weight);
        }

        double _RT_ = _ST_ - JetInfo.Pt[J_Index[0]] - JetInfo.Pt[J_Index[1]] - LepInfo.Pt[L_Index[0]] - LepInfo.Pt[L_Index[1]];
        ExcitedQuarkPlots[_RT]->Fill(_RT_,weight);
        //double _Zmass_ = RecoZboson(LepInfo,NMuons,M_Index,NElectrons,E_Index);
        ExcitedQuarkPlots[_Zmass]->Fill(_Zmass_,weight);
    }
    root->Delete();
}

void integralWithCut(TH1F *h1,double cut){
    double leftNumber = 0;
    double rightNumber = 0;

    for(int i=0;i<h1->GetXaxis()->GetNbins();i++){
        if(h1->GetXaxis()->GetBinCenter(i)<cut){
            leftNumber += h1->GetBinContent(i);
        }else{
            rightNumber += h1->GetBinContent(i);
        }
    }
    std::cout<<"cut ( "<<cut<<" ) , rightNumber : "<<rightNumber<<" , leftNumber : "<<leftNumber<<std::endl;
}

void proj_DataAndMC_multiplots_T2TR(){

    double time1,time2,time3; time1=time(NULL);


    TFile *PUFile;
    switch(RunStatus_){
        case UncPUPlus:
            PUFile = new TFile("interface/Weight3DPlus.root");
            break;
        case UncPUMinus:
            PUFile = new TFile("interface/Weight3DMinus.root");
            break;
        default :
            PUFile = new TFile("interface/Weight3D.root");
            break;
    }
    TH3D *PUReweight_ = (TH3D*) PUFile->Get("WHist");
    for(int i=0;i<50;i++)
    for(int j=0;j<50;j++)
    for(int k=0;k<50;k++) Weight3D_[i][j][k] = (double)PUReweight_->GetBinContent(i+1,j+1,k+1); 


    gROOT->ProcessLine(".L interface/setTDRStyle.C");
    gROOT->ProcessLine("setTDRStyle()");
    gStyle->SetErrorX(0.5);

    string jsonfile = "interface/final_SingleLepton_193752-208686.json";
    MakeJsonMap(jsonfile);

    double weight[samples_order_size];    
    for(int i=0;i<samples_order_size;i++) {
        switch(RunStatus_){
            case UncXsecPlus:
                weight[i] = (1+SAMPLE[i].unc)*(SAMPLE[i].xsec*LUMINOSITY)/(SAMPLE[i].ngen);
                break;
            case UncXsecMinus:
                weight[i] = (1-SAMPLE[i].unc)*(SAMPLE[i].xsec*LUMINOSITY)/(SAMPLE[i].ngen);
                break;
            default:
                weight[i] = (SAMPLE[i].xsec*LUMINOSITY)/(SAMPLE[i].ngen);
                break;
        }
    }

    // histograms
    const int Nmerge = 5;
    char buffer_1[128];
    TH1F *ExcitedQuarkPlots[samples_order_size][_plots_order_size];
    TH1F *ExcitedQuarkPlotsSwap[_plots_order_size][samples_order_size];
    TH1F *ExcitedQuarkPlotsMerge[_plots_order_size][Nmerge];
    TH2D *ExcitedQuark2DPlots[samples_order_size];
    TCanvas *c[_plots_order_size]; 
    TLegend *legend_nm[_plots_order_size];
    THStack *Stacks1[_plots_order_size];
    THStack *Stacks1_[_plots_order_size];
    for(int i =0;i<_plots_order_size;i++) {
        sprintf(buffer_1,"c%i",i);
        c[i]= new TCanvas(buffer_1,"",640,640);
        sprintf(buffer_1,"Stacks1_%i",i);
        Stacks1[i] = new THStack(buffer_1,"");
        sprintf(buffer_1,"Stacks1_%i_",i);
        Stacks1_[i] = new THStack(buffer_1,"");
    }

    for(int i=0;i<samples_order_size;i++) {
        //if(i==Data) continue;
        //if(i==TTJets_MassiveBinDECAY_TuneZ2star_8TeV_madgraph_tauola_Summer12_DR53X_PU_S10_START53_V7A_v1) continue;
        std::cout<<"file : "<<SAMPLE[i].tag<<std::endl;
        for(int j=0;j<_plots_order_size;j++) {
            sprintf(buffer_1,"ExcitedQuarkPlots_%i_%i",i,j);
            ExcitedQuarkPlots[i][j] = new TH1F(buffer_1,"",PLOTS[j].Ndivide_,PLOTS[j].XminBond_,PLOTS[j].XmaxBond_);
        }
            sprintf(buffer_1,"ExcitedQuark2DPlots_%i",i);
            ExcitedQuark2DPlots[i] = new TH2D(buffer_1,"",
                    //PLOTS[_fisherResponse].Ndivide_,PLOTS[_fisherResponse].XminBond_,PLOTS[_fisherResponse].XmaxBond_,
                    PLOTS[_ST].Ndivide_,PLOTS[_ST].XminBond_,PLOTS[_ST].XmaxBond_,
                    PLOTS[_ST].Ndivide_,
                    PLOTS[_ST].XminBond_,PLOTS[_ST].XmaxBond_);

        analyze(i, ExcitedQuarkPlots[i], ExcitedQuark2DPlots[i] , weight[i]);
    }
    for(int i=0;i<_plots_order_size;i++) {
    for(int j=0;j<samples_order_size;j++) {
        ExcitedQuarkPlotsSwap[i][j] = (TH1F*) ExcitedQuarkPlots[j][i]->Clone();
    }
    }

    for(int i=0;i<_plots_order_size;i++) {
    for(int j=0;j<Nmerge;j++) {
        sprintf(buffer_1,"ExcitedQuarkPlotsMerge_%i_%i",i,j);
        ExcitedQuarkPlotsMerge[i][j] = new TH1F(buffer_1,"",PLOTS[i].Ndivide_,PLOTS[i].XminBond_,PLOTS[i].XmaxBond_);
    }
    }

    // For templates    -- start --
    // templates for limit
    int template_indx = _Mtstar;    // default = _ExcitedQuarkMass, test : _MR , _leading1jet, _leading2jets, _MfromMR
    sprintf(buffer_1,"hData%s",RunStatusNames[RunStatus_].c_str());
    TH1F *hData = new TH1F(buffer_1,"",
            PLOTS[template_indx].Ndivide_,PLOTS[template_indx].XminBond_,PLOTS[template_indx].XmaxBond_); 
    sprintf(buffer_1,"hSigMC_500%s",RunStatusNames[RunStatus_].c_str());
    TH1F *hSigMC_500 = new TH1F(buffer_1,"",
            PLOTS[template_indx].Ndivide_,PLOTS[template_indx].XminBond_,PLOTS[template_indx].XmaxBond_); 
    sprintf(buffer_1,"hSigMC_400%s",RunStatusNames[RunStatus_].c_str());
    TH1F *hSigMC_400 = new TH1F(buffer_1,"",
            PLOTS[template_indx].Ndivide_,PLOTS[template_indx].XminBond_,PLOTS[template_indx].XmaxBond_); 
    sprintf(buffer_1,"hMCBG%s",RunStatusNames[RunStatus_].c_str());
    TH1F *hMCBG = new TH1F(buffer_1,"",
            PLOTS[template_indx].Ndivide_,PLOTS[template_indx].XminBond_,PLOTS[template_indx].XmaxBond_); 
    hData->Add(ExcitedQuarkPlots[Data][template_indx]);
    hSigMC_500->Add(ExcitedQuarkPlots[Tgamma800GeV][template_indx]);
    hSigMC_400->Add(ExcitedQuarkPlots[Tgamma800GeV][template_indx]);
    for(int i= QCD_Pt_15to30_TuneZ2star_8TeV_pythia6_Summer12_DR53X_PU_S10_START53_V7A_v2;
            i<=TTZJets_8TeV_madgraph_v2_Summer12_DR53X_PU_S10_START53_V7A_v1;i++) 
        hMCBG->Add(ExcitedQuarkPlots[i][template_indx]);
    hData->Rebin(PLOTS[template_indx].rebin_);
    hSigMC_500->Rebin(PLOTS[template_indx].rebin_);
    hSigMC_400->Rebin(PLOTS[template_indx].rebin_);
    hMCBG->Rebin(PLOTS[template_indx].rebin_);

    std::cout<<"---------------------------------------"<<std::endl;
    std::cout<<"hData : "; integralWithCut(hData,0);
    std::cout<<"hMCBG : "; integralWithCut(hMCBG,0);
    std::cout<<"hSigMC_400 : "; integralWithCut(hSigMC_400,0);
    std::cout<<"hSigMC_500 : "; integralWithCut(hSigMC_500,0);
    std::cout<<"---------------------------------------"<<std::endl;
    /*
    for(int i=0;i<samples_order_size;i++) 
        std::cout<<SAMPLE[i].tag<<" : "<<ExcitedQuarkPlots[i][template_indx]->Integral() <<" ( "<<weight[i]<<" )"<<std::endl;
    std::cout<<"---------------------------------------"<<std::endl;
    for(int i=0;i<samples_order_size;i++) 
        std::cout<<SAMPLE[i].tag<<" : "<<ExcitedQuarkPlots[i][_NOfVertexb4PU]->Integral() <<" ( "<<weight[i]<<" )"<<std::endl;
    std::cout<<"---------------------------------------"<<std::endl;
    */
    for(int i=0;i<samples_order_size;i++) 
        std::cout<<SAMPLE[i].tag<<" : "<<ExcitedQuarkPlots[i][_ST2p2j]->Integral() <<" ( "<<weight[i]<<" )"<<std::endl;
    std::cout<<"---------------------------------------"<<std::endl;
    for(int i=0;i<samples_order_size;i++) 
        std::cout<<SAMPLE[i].tag<<" : "<<ExcitedQuarkPlots[i][_MR2p2j]->Integral() <<" ( "<<weight[i]<<" )"<<std::endl;
    std::cout<<"---------------------------------------"<<std::endl;
    for(int i=0;i<samples_order_size;i++) 
        std::cout<<SAMPLE[i].tag<<" : "<<ExcitedQuarkPlots[i][_check]->Integral() <<" ( "<<weight[i]<<" )"<<std::endl;
    std::cout<<"---------------------------------------"<<std::endl;

    hData->SaveAs("templates/hData.root");
    sprintf(buffer_1,"templates/hSigMC_500%s.root",RunStatusNames[RunStatus_].c_str());
    hSigMC_500->SaveAs(buffer_1);
    sprintf(buffer_1,"templates/hSigMC_400%s.root",RunStatusNames[RunStatus_].c_str());
    hSigMC_400->SaveAs(buffer_1);
    sprintf(buffer_1,"templates/hMCBG%s.root",RunStatusNames[RunStatus_].c_str());
    hMCBG->SaveAs(buffer_1);
    // For templates    -- end --

    for(int i =0;i<_plots_order_size;i++) {
        c[i]->cd();
        HistMerge(ExcitedQuarkPlotsSwap[i], ExcitedQuarkPlotsMerge[i]);
        DRAWSTACK(Stacks1[i],
                ExcitedQuarkPlotsMerge[i],
                ExcitedQuarkPlots[Tgamma800GeV][i],
                ExcitedQuarkPlots[Data][i], 
                legend_nm[i],
                PLOTS[i].YaxisTitle_,PLOTS[i].XaxisTitle_,PLOTS[i].XUnit_, PLOTS[i].rebin_);
        //sprintf(buffer_1,"PLOTS/%s_400GeV.pdf",PLOTS[i].PlotName);
        sprintf(buffer_1,"PLOTS/%s.root",PLOTS[i].PlotName);
        //sprintf(buffer_1,"PLOTS/%s.pdf",PLOTS[i].PlotName);
        c[i]->SaveAs(buffer_1);
    }
    TCanvas *checkpdf = new TCanvas("checkpdf","",640,640);
    checkpdf->cd();
    for(int i =0;i<_plots_order_size;i++) {
        DRAWSTACK(Stacks1_[i],
                ExcitedQuarkPlotsMerge[i],
                ExcitedQuarkPlots[Tgamma800GeV][i],
                ExcitedQuarkPlots[Data][i], 
                legend_nm[i],
                PLOTS[i].YaxisTitle_,PLOTS[i].XaxisTitle_,PLOTS[i].XUnit_, 1);
        if(_plots_order_size!=1){
            if(i==0){
                checkpdf->Print("checkpdf.pdf(");
            }else if(i==_plots_order_size-1){
                checkpdf->Print("checkpdf.pdf)");
            }else{
                checkpdf->Print("checkpdf.pdf");
            }
        }else{
            checkpdf->Print("checkpdf.pdf");
        }
    }
    delete checkpdf;

    time2=time(NULL); time3=time2-time1; cout<<"---- Spending time : " << (time3/60.0) <<" (mins) ----"<<endl;
    std::cout<<"done "<<std::endl;
}
