#include <iostream>
#include <iomanip>
#include <fstream>

#include "RooRealVar.h"
#include "RooDataHist.h"
#include "RooFormulaVar.h"
#include "RooFFTConvPdf.h"
#include "RooPlot.h"
#include "RooHist.h"
#include "TCanvas.h"
//#include "TAxis.h"
#include "TH1F.h"

/*
#include "TROOT.h"
#include "TSystem.h"
#include "TFile.h"
#include "RooBreitWigner.h"
#include "RooCBShape.h"
#include "RooCMSShape.h"
#include "RooAddPdf.h"

using namespace std ;
*/

using namespace RooFit ;


double residual( double datum, double pdf )
{
    double chi2 = 0.;
 
    if ( pdf > 0 )
        chi2 += 2. * ( pdf - datum );
 
    if ( datum > 0 && pdf > 0 )
              chi2=(datum/pdf)-1;
              //chi2 += 2. * datum * log( datum / pdf );

   // return ( ( datum >= pdf ) ? sqrt( chi2 ) : -sqrt( chi2 ) );
    return ( ( datum >= pdf ) ? chi2 :  chi2 );
    
}
/*
double residual_error( double error_data, double pdf )
{
    double chi2 = 0.;
 
    if ( pdf > 0 )
        chi2 += 2. * ( pdf - error_data );
 
    if ( error_data > 0 && pdf > 0 )
        chi2=(error_data/pdf);
        //chi2 += 2. * error_data * log( error_data / error_pdf );

   // return ( ( error_data >= pdf ) ? sqrt( chi2 ) : -sqrt( chi2 ) );
   // return ( ( error_data >= pdf ) ? chi2 :  chi2 );
    return ( chi2 );
}
*/

TH1D* residualHist( const RooHist* rhist, const RooCurve* curve )
{
    double r = 0.2;
    double sr = 1. / r;
 
    // Grab info from the histogram.
    int     n = rhist->GetN();
    double* x = rhist->GetX();
    double* y = rhist->GetY();
    //rhist->Sumw2();
//   double e;
    
	// Create residual histogram.
    double xMin = x[ 0     ];
    double xMax = x[ n - 1 ];
    TH1D* residuals_temp = new TH1D( "r", "", n, xMin, xMax );
 
    double datum = 0.;
    double pdf   = 0.;
    double error_data = 0.;
    
	// Fill the histogram.
    if ( curve )
        for ( int bin = 0; bin < n; bin++ )
        {
            datum = y[ bin ];
            pdf   = curve->Eval( x[ bin ] );
	    error_data = rhist->GetErrorY(bin); 

//            error_pdf = curve->Eval( x[ bin ] );

	    residuals_temp->SetBinContent( bin + 1, residual( datum, pdf ) );
  //          residuals_temp->SetBinError  ( bin + 1, residual_error( error_data, pdf ) );
            residuals_temp->SetBinError  ( bin + 1, error_data / pdf );
        }
 
    residuals_temp->SetMinimum    ( -2.   );
    residuals_temp->SetMaximum    (  2.   );
    residuals_temp->SetStats      ( false );
    residuals_temp->SetMarkerStyle( 8     );
    residuals_temp->SetMarkerSize ( .8    );
 
    TAxis* xAxis = residuals_temp->GetXaxis();
    xAxis->SetTickLength ( 2.5 * xAxis->GetTickLength()  );
    xAxis->SetLabelSize  ( 2.5 * xAxis->GetLabelSize()   );
    xAxis->SetLabelOffset( 2.5 * xAxis->GetLabelOffset() );
 
    TAxis* yAxis = residuals_temp->GetYaxis();
    //yAxis->SetNdivisions ( 500                          );
    //yAxis->SetLabelSize  ( 10*sr * yAxis->GetLabelSize()   );
    yAxis->SetLabelSize  ( 2.5 * yAxis->GetLabelSize()  );

    yAxis->SetTitle("  (DATA - FIT) / FIT");
    yAxis->SetTitleSize  ( 0.09  );
    yAxis->SetTitleOffset( 0.35  );

    return residuals_temp;
}
// To draw lines in the residual histograms:
TLine* midLine;
TLine* uppLine;
TLine* lowLine;
 
void Lines( double xMin, double xMax )
{
    midLine = new TLine( xMin,  0., xMax,  0. );
    uppLine = new TLine( xMin,  0.5, xMax,  0.5 );
    lowLine = new TLine( xMin, -0.5, xMax, -0.5 );
 
    uppLine->SetLineColor( kRed );
    lowLine->SetLineColor( kRed );
 
    midLine->Draw( "same" );
    uppLine->Draw( "same" );
    lowLine->Draw( "same" );
}
 
void Lines( const TH1D* resid )
{
    double xMin = resid->GetXaxis()->GetXmin();
    double xMax = resid->GetXaxis()->GetXmax();
 
    midLine = new TLine( xMin,  0., xMax,  0. );
    uppLine = new TLine( xMin,  0.5, xMax,  0.5 );
    lowLine = new TLine( xMin, -0.5, xMax, -0.5 );
 
    uppLine->SetLineColor( kRed );
    lowLine->SetLineColor( kRed );
 
    midLine->Draw( "same" );
    uppLine->Draw( "same" );
    lowLine->Draw( "same" );
}


void RooFitMacroEff()
//int main()
{	
        gROOT->Reset();
        gSystem->Load("libRooFit");
        gROOT->LoadMacro("RooCMSShape.cc+");

	//gStyle->SetOptStat(111111);
	//gROOT->ProcessLine(".x ~/rootlogon.C");

	TFile f("TagAndProbeEfficiencyResults_low_pT_muons_no_dupl.root");
	
        // We use the noNJetsCut because there is no dependence w.r.t. jet multiplicity
	TH1F * Z_mass = new TH1F("Z","Z" , 1000, 0, 1000);
        Z_mass = (TH1F*)f.Get("Zmass_Inclusive_noNJetsCut_NoElectronVeto;1");
	//Z_mass = (TH1F*)f.Get("Zmass_Inclusive_noNJetsCut_FO;1");
	//Z_mass = (TH1F*)f.Get("Zmass_Inclusive_noNJetsCut_TIGHT;1");



	Z_mass->Rebin(1.5);

	double hmin = 70;
	double hmax = 120;

	double r  = .25;
        double sl = 1. / ( 1. - r );



	//	double hmin = Z_mass->GetXaxis()->GetXmin();
	//	double hmax = Z_mass->GetXaxis()->GetXmax();
	
	// Declare observable x
	RooRealVar x("x","x",hmin,hmax) ;
	RooDataHist dh("dh","dh",x,Import(*Z_mass)) ;

	//(Signal:) Breit-Wigner Lineshape 
	RooRealVar  M("M_{Z^{0}}", "Z0 Resonance  Mass", 91.188, 85.0, 95.0, "GeV/c^{2}");
	RooRealVar  gamma("#Gamma", "#Gamma", 2.4952, 2.0, 3.0, "GeV/c^{2}");
	//M.setConstant();
	//gamma.setConstant();
	RooBreitWigner bw("bw", "A Breit-Wigner Distribution", x, M, gamma);

	//(Signal:) Mass resolution model - Crystal Ball Lineshape
	RooRealVar  M_CB("#Delta m_{0}", "Bias", 5.0, 4.0, 10.0, "GeV/c^{2}");
	RooRealVar  sigma("#sigma_{CB}", "Width", 0.15, 0.1, 0.5, "GeV/c^{2}");
	RooRealVar  alpha("#alpha", "Cut", 0.0, 0.0, 1.5);
	RooRealVar  n("n", "Power", 1.0, 0.0, 100.0);
	RooCBShape  cb("resCBF", "A  Crystal Ball Lineshape", x, M_CB, sigma, alpha, n);

        RooRealVar mean("mean","mean of gaussian", 5.0, 4.0, 10.0, "GeV/c^{2}");
        RooRealVar sigma_g("sigma_g","width of gaussian", 0.45, 0.4, 0.5, "GeV/c^{2}");

        RooGaussian gauss("gauss","gaussian PDF", x, mean, sigma_g);
	//(Background:) RooCMSShape p.d.f.
        RooRealVar cms_alpha("alpha", "alpha", 80, 50, 110);
        RooRealVar cms_beta("beta", "beta", 0.01, 0.001, 0.10);
        RooRealVar cms_gamma("gamma", "gamma", 0.05, 0.0, 0.5);
        RooRealVar peak("peak", "peak", 90, 70, 110);
        RooCMSShape bag("bag", "RooCMSShape", x, cms_alpha, cms_beta, cms_gamma, peak);

        //Convolution to obtain Signal model
	RooFFTConvPdf signal("signal", "Convolution", x, bw, gauss);

    
        //Background + Signal
	//RooRealVar signal_yield("signal_yield", "signal_yield", 100, 0, 1000000);
        //RooRealVar bag_yield("bag_yield", "bag_yield", 100, 0, 1000000);

        RooRealVar signal_yield("signal_yield", "signal_yield", 100, 0, Z_mass->Integral());
        RooRealVar bag_yield("bag_yield", "bag_yield", 0, 0, Z_mass->Integral());

        RooArgList shapes;
        RooArgList yields;
        shapes.add(signal);  
	shapes.add(bag);
        yields.add(signal_yield);
	yields.add(bag_yield);


        RooRealVar fsig("fsig", "fsig", 0, 0, 1.);
        //RooAddPdf model("model","model",shapes,yields);

        // model = fsig x signal + (1-fsig) x bag
        RooAddPdf model("model","model",shapes,fsig,kTRUE);


	//RooRealVar  frac("frac", "f", 0.01, 0, 1.0);
	//Signal p.d.f.
	//RooFFTConvPdf sum("sum", "Convolution", x, bw, cb);
	//RooAddPdf sum("sum","sum",bw,cb,frac);
	//RooAddPdf model("model","model",RooArgList(sum, bag),frac);
	//RooFFTConvPdf model("model","model",x,sum,bag);
	//RooFitResult* filters = sum.fitTo(dh,Range(0,200),"qr");
	//filters->Print("v");


	//RooFitResult* filters = model.fitTo(dh,Range(60,120),"qr");
	RooFitResult* filters = model.fitTo(dh, RooFit::Minimizer("Minuit", "migradimproved"), RooFit::NumCPU(4), RooFit::Save(true), RooFit::Extended(false), RooFit::PrintLevel(-1));
	//RooFitResult* filters = cb.fitTo(dh,Range(0,200),"qr");
	//RooFitResult* filters = bw.fitTo(dh,Range(0,100),"qr");
	//RooFitResult* filters = bag.fitTo(dh,"qr");
	//

	TCanvas* canvas = new TCanvas("ZmassHisto","ZmassHisto",0, 0, 800,600) ;
	canvas->cd() ; //gPad->SetLeftMargin(0.15);
		//	gPad->SetLogy();
	RooPlot* frame = x.frame(Title("#mu #mu #gamma invariant mass fit")) ;
	//	dh.plotOn(frame,MarkerSize(0.5));  //this will show histogram data points on canvas
	dh.plotOn(frame,MarkerSize(0.5),Name("data_hist"));  //this will show histogram data points on canvas


        dh.statOn(frame,Layout(0.15,0.37,0.85),What("N")) ;

	//dh.statOn(frame);  //this will display hist stat on canvas
	
	//sum.plotOn(frame,LineColor(4));//this will show fit overlay on canvas
	//sum.paramOn(frame); //this will display the fit parameters on canvas

	//bag.plotOn(frame,LineColor(2));//this will show fit overlay on canvas 
	//bag.paramOn(frame); //this will display the fit parameters on canvas

	model.plotOn(frame,Components(bag),LineColor(kRed));//this will show fit overlay on canvas 
	model.plotOn(frame,Components(signal),LineColor(kGreen));//this will show fit overlay on canvas 
	//	model.plotOn(frame,LineColor(kBlue));//this will show fit overlay on canvas 
	model.plotOn(frame,LineColor(kBlue),Name("main_curve"));//this will show fit overlay on canvas 

	model.paramOn(frame, Layout(0.6, 0.95, 0.92)); //this will display the fit parameters on canvas


	//	model.paramOn(frame, Layout(0.57, 0.95, 0.90)); //this will display the fit parameters on canvas

	RooHist* histogram = frame->getHist("data_hist");
        RooCurve* curve = frame->getCurve("main_curve");
	TH1D* hresidual  = residualHist(histogram,curve);
	hresidual->Sumw2();
	canvas->Divide( 1, 2, .1, .1 );
	TPad* padHisto = (TPad*) canvas->cd(1);
        TPad* padResid = (TPad*) canvas->cd(2);
	double small = 0.1;
        padHisto->SetPad( 0., r , 1., 1. );
        padHisto->SetBottomMargin( small );
        padResid->SetPad( 0., 0., 1., r  );
        padResid->SetBottomMargin( 0.3  );
        padResid->SetTopMargin   ( small );
        padHisto->cd();



//	model.plotOn(frame,LineColor(4));//this will show fit overlay on canvas 
//	model.paramOn(frame); //this will display the fit parameters on canvas

	//cb.plotOn(frame,LineColor(2));//this will show fit overlay on canvas 
	//cb.paramOn(frame); //this will display the fit parameters on canvas

	//bw.plotOn(frame,LineColor(4));//this will show fit overlay on canvas 
	//bw.paramOn(frame); //this will display the fit parameters on canvas
	
	//gPad->SetLogy();
	cout << "chisquare : " << frame->chiSquare() << endl ;

        //cout << "Total Number of events: " << Z_mass->Integral() << endl;
        //cout << "Number of signal events: " << fsig.getVal() *  Z_mass->Integral() << endl;
        //cout << "Number of background events: " << (1 - fsig.getVal()) * Z_mass->Integral() << endl;

	//Draw all frames on a canvas

	//TPaveLabel *label1 = new TPaveLabel(1,500,15,700,"Chisquare:");
	frame->GetXaxis()->SetTitle("Invariant mass w/ NoElectronVeto photon (in GeV/c^{2})");  
	//frame->GetXaxis()->SetTitle("Invariant mass w/ FO photon (in GeV/c^{2})");  
	//frame->GetXaxis()->SetTitle("Invariant mass w/ TIGHT photon (in GeV/c^{2})");  
        frame->GetXaxis()->SetTitleOffset(1.2);
	//float binsize = Z_mass->GetBinWidth(1);
        //char Bsize[50]; 
	//sprintf(Bsize,"Events per %2.2f",binsize);
	//frame->GetYaxis()->SetTitle(Bsize);  
	//frame->GetYaxis()->SetTitleOffset(1.2);

	frame->Draw();


	padResid->cd();
        hresidual->Draw();
        Lines( hresidual );
        hresidual->Draw( "SAME" );

	
	canvas->Update();
	title->Draw("same");


	canvas->SaveAs("pdf_TagAndProbeEff/Zmass_NoElectronVeto.pdf");
	//canvas->SaveAs("pdf_TagAndProbeEff/Zmass_FO.pdf");
	//canvas->SaveAs("pdf_TagAndProbeEff/Zmass_TIGHT.pdf");
	
}
