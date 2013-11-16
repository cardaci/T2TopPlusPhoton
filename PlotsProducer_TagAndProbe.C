PlotsProducer_TagAndProbe(){

  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);

  TFile * file_Input   = new TFile("TagAndProbeResults_Marco.root");

  file_Input->cd();

  h_Zmass_Inclusive_NoElectronVeto_Denominator = (TH1F*)gDirectory->Get("Zmass_Inclusive_NoElectronVeto_Denominator");
  h_Zmass_Inclusive_NoElectronVeto_Numerator = (TH1F*)gDirectory->Get("Zmass_Inclusive_NoElectronVeto_Numerator");

  h_Zmass_Inclusive_noNJetsCut_NoElectronVeto_Denominator = (TH1F*)gDirectory->Get("Zmass_Inclusive_noNJetsCut_NoElectronVeto_Denominator");
  h_Zmass_Inclusive_noNJetsCut_NoElectronVeto_Numerator = (TH1F*)gDirectory->Get("Zmass_Inclusive_noNJetsCut_NoElectronVeto_Numerator");

  h_FakeRateRatio_NoElectronVeto_NJets = (TH1F*)gDirectory->Get("FakeRateRatio_NoElectronVeto_NJets");
  h_FakeRateRatio_NoElectronVeto_Eta = (TH1F*)gDirectory->Get("FakeRateRatio_NoElectronVeto_Eta");
  h_FakeRateRatio_NoElectronVeto_Eta_PT = (TH2F*)gDirectory->Get("FakeRateRatio_NoElectronVeto_Eta_PT");
  h_FakeRateRatio_NoElectronVeto_PT = (TH1F*)gDirectory->Get("FakeRateRatio_NoElectronVeto_PT");
  h_FakeRateRatio_NoElectronVeto_NVTX = (TH1F*)gDirectory->Get("FakeRateRatio_NoElectronVeto_NVTX");



  TLegend* qw_Zmass_Inclusive_noNJetsCut = 0;
  qw_Zmass_Inclusive_noNJetsCut = new TLegend(0.75,0.99,0.99,0.88);
  qw_Zmass_Inclusive_noNJetsCut->SetFillColor(kWhite);

  h_Zmass_Inclusive_noNJetsCut_NoElectronVeto_Denominator->GetXaxis()->SetTitle("Mass");
  h_Zmass_Inclusive_noNJetsCut_NoElectronVeto_Denominator->GetXaxis()->SetTitleSize(0.045);
  h_Zmass_Inclusive_noNJetsCut_NoElectronVeto_Denominator->GetYaxis()->SetTitle("Entries");
  h_Zmass_Inclusive_noNJetsCut_NoElectronVeto_Denominator->GetYaxis()->SetTitleSize(0.045);
  h_Zmass_Inclusive_noNJetsCut_NoElectronVeto_Denominator->SetTitle("Photon-Electron Invariant Mass");
  h_Zmass_Inclusive_noNJetsCut_NoElectronVeto_Denominator->GetYaxis()->SetLabelSize(0.025);
  h_Zmass_Inclusive_noNJetsCut_NoElectronVeto_Denominator->SetLineColor(kBlue);
  h_Zmass_Inclusive_noNJetsCut_NoElectronVeto_Denominator->SetMarkerStyle(8);
  h_Zmass_Inclusive_noNJetsCut_NoElectronVeto_Denominator->SetMarkerColor(kBlue);

  h_Zmass_Inclusive_noNJetsCut_NoElectronVeto_Numerator->SetLineColor(kRed);
  h_Zmass_Inclusive_noNJetsCut_NoElectronVeto_Numerator->SetMarkerStyle(8);
  h_Zmass_Inclusive_noNJetsCut_NoElectronVeto_Numerator->SetMarkerColor(kRed);

  TCanvas *Canvas_Zmass_Inclusive_noNJetsCut = new TCanvas("Canvas_Zmass_Inclusive_noNJetsCut","Canvas_Zmass_Inclusive_noNJetsCut",0,0,600,800);
  Canvas_Zmass_Inclusive_noNJetsCut->cd();
  h_Zmass_Inclusive_noNJetsCut_NoElectronVeto_Denominator->Draw();
  h_Zmass_Inclusive_noNJetsCut_NoElectronVeto_Numerator->Draw("same");
  qw_Zmass_Inclusive_noNJetsCut->AddEntry(h_Zmass_Inclusive_noNJetsCut_NoElectronVeto_Denominator,"All ID Cuts (Den)","pl");
  qw_Zmass_Inclusive_noNJetsCut->AddEntry(h_Zmass_Inclusive_noNJetsCut_NoElectronVeto_Numerator,"All ID Cuts (Num)","pl");
  qw_Zmass_Inclusive_noNJetsCut->Draw("same");
  Canvas_Zmass_Inclusive_noNJetsCut->Update();
  title->Draw("same");
  Canvas_Zmass_Inclusive_noNJetsCut->SaveAs("plots_TagAndProbe/Zmass_Inclusive_noNJetsCut.pdf");




  TLegend* qw_Zmass_Inclusive = 0;
  qw_Zmass_Inclusive = new TLegend(0.75,0.99,0.99,0.88);
  qw_Zmass_Inclusive->SetFillColor(kWhite);

  h_Zmass_Inclusive_NoElectronVeto_Denominator->GetXaxis()->SetTitle("Mass");
  h_Zmass_Inclusive_NoElectronVeto_Denominator->GetXaxis()->SetTitleSize(0.045);
  h_Zmass_Inclusive_NoElectronVeto_Denominator->GetYaxis()->SetTitle("Entries");
  h_Zmass_Inclusive_NoElectronVeto_Denominator->GetYaxis()->SetTitleSize(0.045);
  h_Zmass_Inclusive_NoElectronVeto_Denominator->SetTitle("Photon-Electron Invariant Mass");
  h_Zmass_Inclusive_NoElectronVeto_Denominator->GetYaxis()->SetLabelSize(0.025);
  h_Zmass_Inclusive_NoElectronVeto_Denominator->SetLineColor(kBlue);
  h_Zmass_Inclusive_NoElectronVeto_Denominator->SetMarkerStyle(8);
  h_Zmass_Inclusive_NoElectronVeto_Denominator->SetMarkerColor(kBlue);

  h_Zmass_Inclusive_NoElectronVeto_Numerator->SetLineColor(kRed);
  h_Zmass_Inclusive_NoElectronVeto_Numerator->SetMarkerStyle(8);
  h_Zmass_Inclusive_NoElectronVeto_Numerator->SetMarkerColor(kRed);

  TCanvas *Canvas_Zmass_Inclusive = new TCanvas("Canvas_Zmass_Inclusive","Canvas_Zmass_Inclusive",0,0,600,800);
  Canvas_Zmass_Inclusive->cd();
  h_Zmass_Inclusive_NoElectronVeto_Denominator->Draw();
  h_Zmass_Inclusive_NoElectronVeto_Numerator->Draw("same");
  qw_Zmass_Inclusive->AddEntry(h_Zmass_Inclusive_NoElectronVeto_Denominator,"All ID Cuts (Den)","pl");
  qw_Zmass_Inclusive->AddEntry(h_Zmass_Inclusive_NoElectronVeto_Numerator,"All ID Cuts (Num)","pl");
  qw_Zmass_Inclusive->Draw("same");
  Canvas_Zmass_Inclusive->Update();
  title->Draw("same");
  Canvas_Zmass_Inclusive->SaveAs("plots_TagAndProbe/Zmass_Inclusive.pdf");


  h_FakeRateRatio_NoElectronVeto_NJets->GetXaxis()->SetTitle("Jet multiplicity");
  h_FakeRateRatio_NoElectronVeto_NJets->GetXaxis()->SetTitleSize(0.045);
  h_FakeRateRatio_NoElectronVeto_NJets->GetYaxis()->SetTitle("Ratio");
  h_FakeRateRatio_NoElectronVeto_NJets->GetYaxis()->SetTitleSize(0.045);
  h_FakeRateRatio_NoElectronVeto_NJets->SetTitle("#varepsilon_{l} (electron-veto to no-electron-veto ratio)");
  h_FakeRateRatio_NoElectronVeto_NJets->GetYaxis()->SetLabelSize(0.025);
  h_FakeRateRatio_NoElectronVeto_NJets->SetLineColor(kBlack);
  h_FakeRateRatio_NoElectronVeto_NJets->GetYaxis()->SetRangeUser(0.,1.);
  h_FakeRateRatio_NoElectronVeto_NJets->SetMarkerStyle(8);
  h_FakeRateRatio_NoElectronVeto_NJets->SetMarkerColor(kBlack);

  TCanvas *Canvas_FakeRateRatio_NJets = new TCanvas("Canvas_FakeRateRatio_NJets","Canvas_FakeRateRatio_NJets",0,0,600,800);
  Canvas_FakeRateRatio_NJets->cd();
  h_FakeRateRatio_NoElectronVeto_NJets->Draw();
  Canvas_FakeRateRatio_NJets->Update();
  title->Draw("same");
  Canvas_FakeRateRatio_NJets->SaveAs("plots_TagAndProbe/FakeRateRatio_NJets.pdf");






  h_FakeRateRatio_NoElectronVeto_Eta->GetXaxis()->SetTitle("#eta");
  h_FakeRateRatio_NoElectronVeto_Eta->GetXaxis()->SetTitleSize(0.045);
  h_FakeRateRatio_NoElectronVeto_Eta->GetYaxis()->SetTitle("Ratio");
  h_FakeRateRatio_NoElectronVeto_Eta->GetYaxis()->SetTitleSize(0.045);
  h_FakeRateRatio_NoElectronVeto_Eta->SetTitle("#varepsilon_{l} (electron-veto to no-electron-veto ratio)");
  h_FakeRateRatio_NoElectronVeto_Eta->GetYaxis()->SetLabelSize(0.025);
  h_FakeRateRatio_NoElectronVeto_Eta->SetLineColor(kBlack);
  h_FakeRateRatio_NoElectronVeto_Eta->GetYaxis()->SetRangeUser(0.,1.);
  h_FakeRateRatio_NoElectronVeto_Eta->SetMarkerStyle(8);
  h_FakeRateRatio_NoElectronVeto_Eta->SetMarkerColor(kBlack);

  TCanvas *Canvas_FakeRateRatio_Eta = new TCanvas("Canvas_FakeRateRatio_Eta","Canvas_FakeRateRatio_Eta",0,0,600,800);
  Canvas_FakeRateRatio_Eta->cd();
  h_FakeRateRatio_NoElectronVeto_Eta->Draw();
  Canvas_FakeRateRatio_Eta->Update();
  title->Draw("same");
  Canvas_FakeRateRatio_Eta->SaveAs("plots_TagAndProbe/FakeRateRatio_Eta.pdf");







  h_FakeRateRatio_NoElectronVeto_PT->GetXaxis()->SetTitle("p_{T}");
  h_FakeRateRatio_NoElectronVeto_PT->GetXaxis()->SetTitleSize(0.045);
  h_FakeRateRatio_NoElectronVeto_PT->GetYaxis()->SetTitle("Ratio");
  h_FakeRateRatio_NoElectronVeto_PT->GetYaxis()->SetTitleSize(0.045);
  h_FakeRateRatio_NoElectronVeto_PT->SetTitle("#varepsilon_{l} (electron-veto to no-electron-veto ratio)");
  h_FakeRateRatio_NoElectronVeto_PT->GetYaxis()->SetLabelSize(0.025);
  h_FakeRateRatio_NoElectronVeto_PT->SetLineColor(kBlack);
  h_FakeRateRatio_NoElectronVeto_PT->GetYaxis()->SetRangeUser(0.,1.);
  h_FakeRateRatio_NoElectronVeto_PT->GetXaxis()->SetRangeUser(0.,300.);
  h_FakeRateRatio_NoElectronVeto_PT->SetMarkerStyle(8);
  h_FakeRateRatio_NoElectronVeto_PT->SetMarkerColor(kBlack);



  TCanvas *Canvas_FakeRateRatio_PT = new TCanvas("Canvas_FakeRateRatio_PT","Canvas_FakeRateRatio_PT",0,0,600,800);
  Canvas_FakeRateRatio_PT->cd();
  h_FakeRateRatio_NoElectronVeto_PT->Draw();
  Canvas_FakeRateRatio_PT->Update();
  title->Draw("same");
  Canvas_FakeRateRatio_PT->SaveAs("plots_TagAndProbe/FakeRateRatio_PT.pdf");








  h_FakeRateRatio_NoElectronVeto_Eta_PT->GetXaxis()->SetTitle("#eta");
  h_FakeRateRatio_NoElectronVeto_Eta_PT->GetXaxis()->SetTitleSize(0.045);
  h_FakeRateRatio_NoElectronVeto_Eta_PT->GetYaxis()->SetTitle("p_{T}");
  h_FakeRateRatio_NoElectronVeto_Eta_PT->GetYaxis()->SetTitleSize(0.045);
  h_FakeRateRatio_NoElectronVeto_Eta_PT->SetTitle("#varepsilon_{l} (electron-veto to no-electron-veto ratio)");
  h_FakeRateRatio_NoElectronVeto_Eta_PT->GetYaxis()->SetLabelSize(0.025);
  h_FakeRateRatio_NoElectronVeto_Eta_PT->SetLineColor(kBlack);
  h_FakeRateRatio_NoElectronVeto_Eta_PT->GetYaxis()->SetRangeUser(0.,300.);
  h_FakeRateRatio_NoElectronVeto_Eta_PT->SetMarkerStyle(8);
  h_FakeRateRatio_NoElectronVeto_Eta_PT->SetMarkerColor(kBlack);



  TCanvas *Canvas_FakeRateRatio_Eta_PT = new TCanvas("Canvas_FakeRateRatio_Eta_PT","Canvas_FakeRateRatio_Eta_PT",0,0,900,600);
  Canvas_FakeRateRatio_Eta_PT->cd();
  h_FakeRateRatio_NoElectronVeto_Eta_PT->Draw("colz");
  Canvas_FakeRateRatio_Eta_PT->Update();
  title->Draw("same");
  Canvas_FakeRateRatio_Eta_PT->SaveAs("plots_TagAndProbe/FakeRateRatio_Eta_PT.pdf");





  h_FakeRateRatio_NoElectronVeto_NVTX->GetXaxis()->SetTitle("Vertex Multiplicity");
  h_FakeRateRatio_NoElectronVeto_NVTX->GetXaxis()->SetTitleSize(0.045);
  h_FakeRateRatio_NoElectronVeto_NVTX->GetYaxis()->SetTitle("Ratio");
  h_FakeRateRatio_NoElectronVeto_NVTX->GetYaxis()->SetTitleSize(0.045);
  h_FakeRateRatio_NoElectronVeto_NVTX->SetTitle("#varepsilon_{l} (electron-veto to no-electron-veto ratio)");
  h_FakeRateRatio_NoElectronVeto_NVTX->GetYaxis()->SetLabelSize(0.025);
  h_FakeRateRatio_NoElectronVeto_NVTX->SetLineColor(kBlack);
  h_FakeRateRatio_NoElectronVeto_NVTX->GetYaxis()->SetRangeUser(0.,1.);
  h_FakeRateRatio_NoElectronVeto_NVTX->SetMarkerStyle(8);
  h_FakeRateRatio_NoElectronVeto_NVTX->SetMarkerColor(kBlack);


  TCanvas *Canvas_FakeRateRatio_NVTX = new TCanvas("Canvas_FakeRateRatio_NVTX","Canvas_FakeRateRatio_NVTX",0,0,600,800);
  Canvas_FakeRateRatio_NVTX->cd();
  h_FakeRateRatio_NoElectronVeto_NVTX->Draw();
  Canvas_FakeRateRatio_NVTX->Update();
  title->Draw("same");
  Canvas_FakeRateRatio_NVTX->SaveAs("plots_TagAndProbe/FakeRateRatio_NVTX.pdf");





}
