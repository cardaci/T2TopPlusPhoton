#include "TTree.h"
#include "TROOT.h"
#include "TRandom.h"
#include "TStyle.h"
#include "TH1F.h"
#include "TH2F.h"
#include "interface/format.h"
#include "TChain.h"
#include "TCanvas.h"
#include "interface/DPHI.h"
#include "interface/RecoLeptonSelection.h"
#include "interface/RecoPhotonSelectionFONoSigmaIetaIeta.h"
#include "interface/RecoJetSelection.h"
#include "interface/ConstantNumbers.h"
#include "TLorentzVector.h"
#include <string>
#include <iostream>
#include <vector>
#include <TFile.h>
#include "interface/EffectiveAreaPhoton.h"

void MatrixMethod()
{

     float Nss[3];
     float Nsf[3];
     float Nff[3];

     TRandom ranN1, ranN2, ranN3, ranEpsS, ranEpsQ, ranEpsG, ranEpsL;
     TRandom ranR_lglq, ranR_lllq, ranR_qqlq, ranR_gglq, ranR_qglq;
     TRandom ranR_lqlg, ranR_lllg, ranR_qqlg, ranR_gglg, ranR_qglg;
     TRandom ranR_lqll, ranR_lgll, ranR_qqll, ranR_ggll, ranR_qgll;
     TRandom ranR_lqqq, ranR_lgqq, ranR_llqq, ranR_ggqq, ranR_qgqq;
     TRandom ranR_lqgg, ranR_lggg, ranR_llgg, ranR_qqgg, ranR_qggg;
     TRandom ranR_lqqg, ranR_lgqg, ranR_llqg, ranR_qqqg, ranR_ggqg;
     TRandom ranR_sgsq, ranR_slsq;
     TRandom ranR_sqsg, ranR_slsg;
     TRandom ranR_sqsl, ranR_sgsl;

     TH1F * h_Nss[3];
     TH1F * h_Nsf[3];
     TH1F * h_Nff[3];

     h_Nss[0] = new TH1F("Nss_L", "Nss_L", 100, -15., 20.);
     h_Nss[1] = new TH1F("Nss_M", "Nss_M", 100, -12, 22);
     h_Nss[2] = new TH1F("Nss_T", "Nss_T", 100, -10, 20);

     h_Nsf[0] = new TH1F("Nsf_L", "Nsf_L", 100, -15., 60.);
     h_Nsf[1] = new TH1F("Nsf_M", "Nsf_M", 100, -20, 60);
     h_Nsf[2] = new TH1F("Nsf_T", "Nsf_T", 100, -5, 12);

     h_Nff[0] = new TH1F("Nff_L", "Nff_L", 100, 35, 125);
     h_Nff[1] = new TH1F("Nff_M", "Nff_M", 100, 10, 50);
     h_Nff[2] = new TH1F("Nff_T", "Nff_T", 100, 1., 6);



     for(int pseudoexp_index = 0; pseudoexp_index < 100000; pseudoexp_index++){


       // Initial values


       float NL = 100.;
       float NM = 50.;
       float NT = 10.;


       float EpsilonS = 0.95;
       float EpsilonQ = 0.20;
       float EpsilonG = 0.20;
       float EpsilonL = 0.20;


       float err_EpsilonS = .01;
       float err_EpsilonQ = .01;
       float err_EpsilonG = .01;
       float err_EpsilonL = .01;


       float R_lglq = 1.38921;
       float R_lllq = 0.0448255;
       float R_qqlq = 2.89116;
       float R_gglq = 1.07981;
       float R_qglq = 3.96235;


       float R_lqlg = 0.719833 ;
       float R_lllg = 0.0322669;
       float R_qqlg = 2.08115;
       float R_gglg = 0.777286;
       float R_qglg = 2.85223;


       float R_lqll = 22.3087;
       float R_lgll = 30.9915;
       float R_qqll = 64.498 ;
       float R_ggll =  24.0893 ;
       float R_qgll = 88.395;

       float R_lqqq = 0.345882;
       float R_lgqq = 0.480503;
       float R_llqq = 0.0155044;
       float R_ggqq = 0.373489;
       float R_qgqq = 1.37051;

       float R_lqgg = 0.926085;
       float R_lggg = 1.28653;
       float R_llgg = 0.0415122;
       float R_qqgg = 2.67746;
       float R_qggg = 3.66947;

       float R_lqqg = 0.252375;
       float R_lgqg = 0.350603;
       float R_llqg = 0.0113129;
       float R_qqqg = 0.729657;
       float R_ggqg =  0.272519;

       float R_sgsq = 1.35793;
       float R_slsq = 0.029224;

       float R_sqsg = 0.736414;
       float R_slsg = 0.021521;

       float R_sqsl = 34.2184 ;
       float R_sgsl = 46.4663;


       float err_R_lglq = 0.0180327;
       float err_R_lllq = 0.00179572;
       float err_R_qqlq = 0.0323378;
       float err_R_gglq = 0.0148807;
       float err_R_qglq = 0.0418771;

       float err_R_lqlg = 0.00934384;
       float err_R_lllg = 0.0012582;
       float err_R_qqlg = 0.0210578;
       float err_R_gglg = 0.00988246;
       float err_R_qglg = 0.0271019;

       float err_R_lqll = 0.893694;
       float err_R_lgll = 1.20847;
       float err_R_qqll = 2.3992;
       float err_R_ggll = 0.958604;
       float err_R_qgll = 3.23364;

       float err_R_lqqq = 0.00386872;
       float err_R_lgqq = 0.00486189;
       float err_R_llqq = 0.000576732;
       float err_R_ggqq = 0.00407796;
       float err_R_qgqq = 0.0105618;

       float err_R_lqgg = 0.0127622;
       float err_R_lggg = 0.016357;
       float err_R_llgg = 0.00165193;
       float err_R_qqgg = 0.029234;
       float err_R_qggg = 0.0378038;

       float err_R_lqqg = 0.00266729;
       float err_R_lgqg = 0.00333142;
       float err_R_llqg = 0.000413844;
       float err_R_qqqg = 0.0056231;
       float err_R_ggqg = 0.00280755;

       float err_R_sgsq = 0.0193986;
       float err_R_slsq = 0.00115801;

       float err_R_sqsg = 0.00797521;
       float err_R_slsg = 0.000834555;

       float err_R_sqsl = 1.35591;
       float err_R_sgsl = 1.8019;







       // Pseudo-experiments


       float N3 = NT;
       float N2 = NM - N3;
       float N1 = NL - N2 - N3;

       N1 = ranN1.Poisson(N1);
       N2 = ranN2.Poisson(N2);
       N3 = ranN3.Poisson(N3);

       NT = N3;
       NM = N2 + N3;
       NL = N1 + N2 + N3;

      
       float EpsilonS_0 = EpsilonS;
       float EpsilonQ_0 = EpsilonQ;
       float EpsilonG_0 = EpsilonG;
       float EpsilonL_0 = EpsilonL;

       EpsilonS = ranEpsS.Gaus(EpsilonS_0, err_EpsilonS);
       EpsilonQ = ranEpsQ.Gaus(EpsilonQ_0, err_EpsilonQ);
       EpsilonG = ranEpsG.Gaus(EpsilonG_0, err_EpsilonG);
       EpsilonL = ranEpsL.Gaus(EpsilonL_0, err_EpsilonL);


       float R_lglq_0 = R_lglq; 
       float R_lllq_0 =  R_lllq; 
       float R_qqlq_0 =  R_qqlq; 
       float R_gglq_0 =  R_gglq; 
       float R_qglq_0 =  R_qglq;

       float R_lqlg_0 = R_lqlg; 
       float R_lllg_0 = R_lllg; 
       float R_qqlg_0 = R_qqlg; 
       float R_gglg_0 = R_gglg; 
       float R_qglg_0 = R_qglg;

       float R_lqll_0 =  R_lqll; 
       float R_lgll_0 =  R_lgll; 
       float R_qqll_0 =  R_qqll; 
       float R_ggll_0 =  R_ggll; 
       float R_qgll_0 =  R_qgll;

       float R_lqqq_0 = R_lqqq;
       float R_lgqq_0 = R_lgqq;  
       float R_llqq_0 = R_llqq;
       float R_ggqq_0 = R_ggqq;
       float R_qgqq_0 = R_qgqq;

       float R_lqgg_0 =  R_lqgg; 
       float R_lggg_0 =  R_lggg; 
       float R_llgg_0 =  R_llgg; 
       float R_qqgg_0 =  R_qqgg; 
       float R_qggg_0 =  R_qggg;

       float R_lqqg_0 = R_lqqg; 
       float R_lgqg_0 = R_lgqg;
       float R_llqg_0 = R_llqg;
       float R_qqqg_0 = R_qqqg;
       float R_ggqg_0 = R_ggqg;

       float R_sgsq_0 =  R_sgsq; 
       float R_slsq_0 =  R_slsq;

       float R_sqsg_0 = R_sqsg;
       float R_slsg_0 = R_slsg;

       float R_sqsl_0 =  R_sqsl; 
       float R_sgsl_0 = R_sgsl;



       R_lglq = ranR_lglq.Gaus(R_lglq_0, err_R_lglq);
       R_lllq = ranR_lllq.Gaus(R_lllq_0, err_R_lllq);
       R_qqlq = ranR_qqlq.Gaus(R_qqlq_0, err_R_qqlq);
       R_gglq = ranR_gglq.Gaus(R_gglq_0, err_R_gglq); 
       R_qglq = ranR_qglq.Gaus(R_qglq_0, err_R_qglq);

       R_lqlg = ranR_lqlg.Gaus(R_lqlg_0, err_R_lqlg); 
       R_lllg = ranR_lllg.Gaus(R_lllg_0, err_R_lllg);
       R_qqlg = ranR_qqlg.Gaus(R_qqlg_0, err_R_qqlg); 
       R_gglg = ranR_gglg.Gaus(R_gglg_0, err_R_gglg); 
       R_qglg = ranR_qglg.Gaus(R_qglg_0, err_R_qglg); 


       R_lqll = ranR_lqll.Gaus(R_lqll_0, err_R_lqll); 
       R_lgll = ranR_lgll.Gaus(R_lgll_0, err_R_lgll); 
       R_qqll = ranR_qqll.Gaus(R_qqll_0, err_R_qqll);
       R_ggll = ranR_ggll.Gaus(R_ggll_0, err_R_ggll);
       R_qgll = ranR_qgll.Gaus(R_qgll_0, err_R_qgll);

       R_lqqq = ranR_lqqq.Gaus(R_lqqq_0, err_R_lqqq); 
       R_lgqq = ranR_lgqq.Gaus(R_lgqq_0, err_R_lgqq); 
       R_llqq = ranR_llqq.Gaus(R_llqq_0, err_R_llqq);
       R_ggqq = ranR_ggqq.Gaus(R_ggqq_0, err_R_ggqq); 
       R_qgqq = ranR_qgqq.Gaus(R_qgqq_0, err_R_qgqq); 

       R_lqgg = ranR_lqgg.Gaus(R_lqgg_0, err_R_lqgg);
       R_lggg = ranR_lggg.Gaus(R_lggg_0, err_R_lggg);
       R_llgg = ranR_llgg.Gaus(R_llgg_0, err_R_llgg);
       R_qqgg = ranR_qqgg.Gaus(R_qqgg_0, err_R_qqgg); 
       R_qggg = ranR_qggg.Gaus(R_qggg_0, err_R_qggg); 

       R_lqqg = ranR_lqqg.Gaus(R_lqqg_0, err_R_lqqg); 
       R_lgqg = ranR_lgqg.Gaus(R_lgqg_0, err_R_lgqg);
       R_llqg = ranR_llqg.Gaus(R_llqg_0, err_R_llqg); 
       R_qqqg = ranR_qqqg.Gaus(R_qqqg_0, err_R_qqqg); 
       R_ggqg = ranR_ggqg.Gaus(R_ggqg_0, err_R_ggqg); 

       R_sgsq = ranR_sgsq.Gaus(R_sgsq_0, err_R_sgsq);
       R_slsq = ranR_slsq.Gaus(R_slsq_0, err_R_slsq); 

       R_sqsg = ranR_sqsg.Gaus(R_sqsg_0, err_R_sqsg);
       R_slsg = ranR_slsg.Gaus(R_slsg_0, err_R_slsg);

       R_sqsl = ranR_sqsl.Gaus(R_sqsl_0, err_R_sqsl);
       R_sgsl = ranR_sgsl.Gaus(R_sgsl_0, err_R_sgsl); 



       // Equations
      
      float Eff_LTlq = EpsilonL * EpsilonQ * 1 / ( 1 + R_lglq + R_lllq + R_qqlq + R_gglq + R_qglq);
      float Eff_LTlg = EpsilonL * EpsilonG * 1 / ( 1 + R_lqlg + R_lllg + R_qqlg + R_gglg + R_qglg);
      float Eff_LTll = EpsilonL * EpsilonQ * 1 / ( 1 + R_lqll + R_lgll + R_qqll + R_ggll + R_qgll);
      float Eff_LTqq = EpsilonL * EpsilonL * 1 / ( 1 + R_lqqq + R_lgqq + R_llqq + R_ggqq + R_qgqq);
      float Eff_LTgg = EpsilonG * EpsilonG * 1 / ( 1 + R_lqgg + R_lggg + R_llgg + R_qqgg + R_qggg);
      float Eff_LTqg = EpsilonQ * EpsilonG * 1 / ( 1 + R_lqqg + R_lgqg + R_llqg + R_qqqg + R_ggqg);

      float Eff_LMlq = (EpsilonL + EpsilonQ - EpsilonL * EpsilonQ) * 1 / ( 1 + R_lglq + R_lllq + R_qqlq + R_gglq + R_qglq);
      float Eff_LMlg = (EpsilonL + EpsilonG - EpsilonL * EpsilonG) * 1 / ( 1 + R_lqlg + R_lllg + R_qqlg + R_gglg + R_qglg);
      float Eff_LMll = (EpsilonL + EpsilonQ - EpsilonL * EpsilonQ) * 1 / ( 1 + R_lqll + R_lgll + R_qqll + R_ggll + R_qgll);
      float Eff_LMqq = (EpsilonQ + EpsilonQ - EpsilonQ * EpsilonQ) * 1 / ( 1 + R_lqqq + R_lgqq + R_llqq + R_ggqq + R_qgqq);
      float Eff_LMgg = (EpsilonG + EpsilonG - EpsilonG * EpsilonG) * 1 / ( 1 + R_lqgg + R_lggg + R_llgg + R_qqgg + R_qggg);
      float Eff_LMqg = (EpsilonQ + EpsilonG - EpsilonQ * EpsilonG) * 1 / ( 1 + R_lqqg + R_lgqg + R_llqg + R_qqqg + R_ggqg);

      float Eff_LTsq = EpsilonS * EpsilonQ * 1 / (1 + R_sgsq + R_slsq);
      float Eff_LTsg = EpsilonS * EpsilonG * 1 / (1 + R_sqsg + R_slsg);
      float Eff_LTsl = EpsilonS * EpsilonL * 1 / (1 + R_sqsl + R_sgsl);

      float Eff_LMsq = (EpsilonS + EpsilonQ - EpsilonS * EpsilonQ) * 1 / (1 + R_sgsq + R_slsq);
      float Eff_LMsg = (EpsilonS + EpsilonG - EpsilonS * EpsilonG) * 1 / (1 + R_sqsg + R_slsg);
      float Eff_LMsl = (EpsilonS + EpsilonL - EpsilonS * EpsilonL) * 1 / (1 + R_sqsl + R_sgsl);

      float Eff_LTss   = EpsilonS * EpsilonS;
      float Eff_LTsf   = Eff_LTsg + Eff_LTsq + Eff_LTsl;
      float Eff_LTff   = Eff_LTlq + Eff_LTlg + Eff_LTll + Eff_LTqq + Eff_LTgg + Eff_LTqg;

      float Eff_LMss   = 2 * EpsilonS - EpsilonS * EpsilonS;
      float Eff_LMsf   = Eff_LMsg + Eff_LMsq + Eff_LMsl;
      float Eff_LMff   = Eff_LMlq + Eff_LMlg + Eff_LMll + Eff_LMqq + Eff_LMgg + Eff_LMqg;

      // Solving the system

      TMatrixF theEffmatrix(3,3); // A
      TMatrixF solutions(3,1);    // x
      TMatrixF mesured(3,1);      // b

      float eff[9] ;  // A

      eff[0] = Eff_LTss;
      eff[1] = Eff_LTsf;
      eff[2] = Eff_LTff ;
      
      eff[3] = Eff_LMss;
      eff[4] = Eff_LMsf;
      eff[5] = Eff_LMff;
      
      eff[6] = 1.;
      eff[7] = 1.;
      eff[8] = 1.; //1 
      
      theEffmatrix.SetMatrixArray(eff);
      theEffmatrix.Invert();

      float ArrayMes[3] ; // b
      ArrayMes[0] = NT;
      ArrayMes[1] = NM;
      ArrayMes[2] = NL;

      mesured.SetMatrixArray(ArrayMes);
      solutions = theEffmatrix*mesured; 

      Nss[2] = solutions(0,0)*Eff_LTss;
      Nsf[2] = solutions(1,0)*Eff_LTsf;
      Nff[2] = solutions(2,0)*Eff_LTff;
     
      Nss[1] = solutions(0,0)*Eff_LMss;
      Nsf[1] = solutions(1,0)*Eff_LMsf;
      Nff[1] = solutions(2,0)*Eff_LMff;
      
      Nss[0] = solutions(0,0);
      Nsf[0] = solutions(1,0);
      Nff[0] = solutions(2,0);   


      h_Nss[2]->Fill(Nss[2]);
      h_Nss[1]->Fill(Nss[1]);
      h_Nss[0]->Fill(Nss[0]);

      h_Nsf[2]->Fill(Nsf[2]);
      h_Nsf[1]->Fill(Nsf[1]);
      h_Nsf[0]->Fill(Nsf[0]);

      h_Nff[2]->Fill(Nff[2]);
      h_Nff[1]->Fill(Nff[1]);
      h_Nff[0]->Fill(Nff[0]);


      for(int i = 0; i < 3; i++){
       cout << "Nss[" << i << "] = " << Nss[i] << endl;
       cout << "Nsf[" << i << "] = " << Nsf[i] << endl;
       cout << "Nff[" << i << "] = " << Nff[i] << endl;
      }

     }




     TCanvas * Canvas_Nss_L = new TCanvas("Canvas_Nss_L", "Canvas_Nss_L", 0, 0, 600, 800);
     Canvas_Nss_L->cd();        
     h_Nss[0]->Draw();
     Canvas_Nss_L->SaveAs("MatrixMethod/Canvas_Nss_L.pdf");

     TCanvas * Canvas_Nss_M = new TCanvas("Canvas_Nss_M", "Canvas_Nss_M", 0, 0, 600, 800);
     Canvas_Nss_M->cd();        
     h_Nss[1]->Draw();
     Canvas_Nss_M->SaveAs("MatrixMethod/Canvas_Nss_M.pdf");

     TCanvas * Canvas_Nss_T = new TCanvas("Canvas_Nss_T", "Canvas_Nss_T", 0, 0, 600, 800);
     Canvas_Nss_T->cd();        
     h_Nss[2]->Draw();
     Canvas_Nss_T->SaveAs("MatrixMethod/Canvas_Nss_T.pdf");



     TCanvas * Canvas_Nsf_L = new TCanvas("Canvas_Nsf_L", "Canvas_Nsf_L", 0, 0, 600, 800);
     Canvas_Nsf_L->cd();        
     h_Nsf[0]->Draw();
     Canvas_Nsf_L->SaveAs("MatrixMethod/Canvas_Nsf_L.pdf");

     TCanvas * Canvas_Nsf_M = new TCanvas("Canvas_Nsf_M", "Canvas_Nsf_M", 0, 0, 600, 800);
     Canvas_Nsf_M->cd();        
     h_Nsf[1]->Draw();
     Canvas_Nsf_M->SaveAs("MatrixMethod/Canvas_Nsf_M.pdf");

     TCanvas * Canvas_Nsf_T = new TCanvas("Canvas_Nsf_T", "Canvas_Nsf_T", 0, 0, 600, 800);
     Canvas_Nsf_T->cd();        
     h_Nsf[2]->Draw();
     Canvas_Nsf_T->SaveAs("MatrixMethod/Canvas_Nsf_T.pdf");




     TCanvas * Canvas_Nff_L = new TCanvas("Canvas_Nff_L", "Canvas_Nff_L", 0, 0, 600, 800);
     Canvas_Nff_L->cd();        
     h_Nff[0]->Draw();
     Canvas_Nff_L->SaveAs("MatrixMethod/Canvas_Nff_L.pdf");


     TCanvas * Canvas_Nff_M = new TCanvas("Canvas_Nff_M", "Canvas_Nff_M",0, 0, 600, 800);
     Canvas_Nff_M->cd();        
     h_Nff[1]->Draw();
     Canvas_Nff_M->SaveAs("MatrixMethod/Canvas_Nff_M.pdf");


     TCanvas * Canvas_Nff_T = new TCanvas("Canvas_Nff_T", "Canvas_Nff_T",0, 0, 600, 800);
     Canvas_Nff_T->cd();        
     h_Nff[2]->Draw();
     Canvas_Nff_T->SaveAs("MatrixMethod/Canvas_Nff_T.pdf");



}
