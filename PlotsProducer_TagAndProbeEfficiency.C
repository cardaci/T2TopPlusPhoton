PlotsProducer_TagAndProbeEfficiency(){

  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);

  TFile * file_Input   = new TFile("TagAndProbeEfficiencyResults.root");

  file_Input->cd();

  h_Zmass_Inclusive_FO = (TH1F*)gDirectory->Get("Zmass_Inclusive_FO");
  h_Zmass_Inclusive_NoElectronVeto = (TH1F*)gDirectory->Get("Zmass_Inclusive_NoElectronVeto");
  h_Zmass_Inclusive_TIGHT = (TH1F*)gDirectory->Get("Zmass_Inclusive_TIGHT");

  h_Zmass_Inclusive_FO->Rebin(10);
  h_Zmass_Inclusive_NoElectronVeto->Rebin(10);
  h_Zmass_Inclusive_TIGHT->Rebin(10);


  h_Zmass_Inclusive_noNJetsCut_FO = (TH1F*)gDirectory->Get("Zmass_Inclusive_noNJetsCut_FO");
  h_Zmass_Inclusive_noNJetsCut_NoElectronVeto = (TH1F*)gDirectory->Get("Zmass_Inclusive_noNJetsCut_NoElectronVeto");
  h_Zmass_Inclusive_noNJetsCut_TIGHT = (TH1F*)gDirectory->Get("Zmass_Inclusive_noNJetsCut_TIGHT");

  h_Zmass_Inclusive_noNJetsCut_FO->Rebin(10);
  h_Zmass_Inclusive_noNJetsCut_NoElectronVeto->Rebin(10);
  h_Zmass_Inclusive_noNJetsCut_TIGHT->Rebin(10);


  h_Zmass_Inclusive_noPtCut_noNJetsCut_FO = (TH1F*)gDirectory->Get("Zmass_Inclusive_noPtCut_noNJetsCut_FO");
  h_Zmass_Inclusive_noPtCut_noNJetsCut_NoElectronVeto = (TH1F*)gDirectory->Get("Zmass_Inclusive_noPtCut_noNJetsCut_NoElectronVeto");
  h_Zmass_Inclusive_noPtCut_noNJetsCut_TIGHT = (TH1F*)gDirectory->Get("Zmass_Inclusive_noPtCut_noNJetsCut_TIGHT");

  h_Zmass_Inclusive_noPtCut_noNJetsCut_FO->Rebin(10);
  h_Zmass_Inclusive_noPtCut_noNJetsCut_NoElectronVeto->Rebin(10);
  h_Zmass_Inclusive_noPtCut_noNJetsCut_TIGHT->Rebin(10);



  h_EfficiencyRatio_NJets = (TH1F*)gDirectory->Get("EfficiencyRatio_NJets");
  h_EfficiencyRatio_Eta = (TH1F*)gDirectory->Get("EfficiencyRatio_Eta");
  h_EfficiencyRatio_PT = (TH1F*)gDirectory->Get("EfficiencyRatio_PT");
  h_EfficiencyRatio_Eta_PT = (TH2F*)gDirectory->Get("EfficiencyRatio_Eta_PT");
  h_EfficiencyRatio_NVTX = (TH1F*)gDirectory->Get("EfficiencyRatio_NVTX");


  TLegend* qw_Inclusive = 0;
  qw_Inclusive = new TLegend(0.75,0.99,0.99,0.88);
  qw_Inclusive->SetFillColor(kWhite);

  h_Zmass_Inclusive_NoElectronVeto->GetXaxis()->SetTitle("Mass");
  h_Zmass_Inclusive_NoElectronVeto->GetXaxis()->SetTitleSize(0.045);
  h_Zmass_Inclusive_NoElectronVeto->GetYaxis()->SetTitle("Entries");
  h_Zmass_Inclusive_NoElectronVeto->GetYaxis()->SetTitleSize(0.045);
  h_Zmass_Inclusive_NoElectronVeto->SetTitle("Photon-Muon-Muon Invariant Mass");
  h_Zmass_Inclusive_NoElectronVeto->GetYaxis()->SetLabelSize(0.025);
  h_Zmass_Inclusive_NoElectronVeto->GetXaxis()->SetRangeUser(0.,300.);
  h_Zmass_Inclusive_NoElectronVeto->SetLineColor(kBlue);
  h_Zmass_Inclusive_NoElectronVeto->SetMarkerStyle(8);
  h_Zmass_Inclusive_NoElectronVeto->SetMarkerColor(kBlue);

  h_Zmass_Inclusive_FO->SetLineColor(kRed);
  h_Zmass_Inclusive_FO->SetMarkerStyle(8);
  h_Zmass_Inclusive_FO->SetMarkerColor(kRed);

  h_Zmass_Inclusive_TIGHT->SetLineColor(kGreen);
  h_Zmass_Inclusive_TIGHT->SetMarkerStyle(8);
  h_Zmass_Inclusive_TIGHT->SetMarkerColor(kGreen);

  TCanvas *Canvas_Zmass_Inclusive = new TCanvas("Canvas_Zmass_Inclusive","Canvas_Zmass_Inclusive",0,0,600,800);
  Canvas_Zmass_Inclusive->cd();
  h_Zmass_Inclusive_NoElectronVeto->Draw();
  h_Zmass_Inclusive_FO->Draw("same");
  h_Zmass_Inclusive_TIGHT->Draw("same");
  qw_Inclusive->AddEntry(h_Zmass_Inclusive_FO,"FO (Den)","pl");
  qw_Inclusive->AddEntry(h_Zmass_Inclusive_NoElectronVeto,"No-electron-veto (Den)","pl");
  qw_Inclusive->AddEntry(h_Zmass_Inclusive_TIGHT,"TIGHT (Num)","pl");
  qw_Inclusive->Draw("same");
  Canvas_Zmass_Inclusive->Update();
  title->Draw("same");
  Canvas_Zmass_Inclusive->SaveAs("plots_TagAndProbeEfficiency/Zmass_Inclusive.pdf");




  TLegend* qw_Inclusive_noNJetsCut = 0;
  qw_Inclusive_noNJetsCut = new TLegend(0.75,0.99,0.99,0.88);
  qw_Inclusive_noNJetsCut->SetFillColor(kWhite);

  h_Zmass_Inclusive_noNJetsCut_NoElectronVeto->GetXaxis()->SetTitle("Mass");
  h_Zmass_Inclusive_noNJetsCut_NoElectronVeto->GetXaxis()->SetTitleSize(0.045);
  h_Zmass_Inclusive_noNJetsCut_NoElectronVeto->GetYaxis()->SetTitle("Entries");
  h_Zmass_Inclusive_noNJetsCut_NoElectronVeto->GetYaxis()->SetTitleSize(0.045);
  h_Zmass_Inclusive_noNJetsCut_NoElectronVeto->SetTitle("Photon-Muon-Muon Invariant Mass");
  h_Zmass_Inclusive_noNJetsCut_NoElectronVeto->GetYaxis()->SetLabelSize(0.025);
  h_Zmass_Inclusive_noNJetsCut_NoElectronVeto->GetXaxis()->SetRangeUser(0.,300.);
  h_Zmass_Inclusive_noNJetsCut_NoElectronVeto->SetLineColor(kBlue);
  h_Zmass_Inclusive_noNJetsCut_NoElectronVeto->SetMarkerStyle(8);
  h_Zmass_Inclusive_noNJetsCut_NoElectronVeto->SetMarkerColor(kBlue);

  h_Zmass_Inclusive_noNJetsCut_FO->SetLineColor(kRed);
  h_Zmass_Inclusive_noNJetsCut_FO->SetMarkerStyle(8);
  h_Zmass_Inclusive_noNJetsCut_FO->SetMarkerColor(kRed);

  h_Zmass_Inclusive_noNJetsCut_TIGHT->SetLineColor(kGreen);
  h_Zmass_Inclusive_noNJetsCut_TIGHT->SetMarkerStyle(8);
  h_Zmass_Inclusive_noNJetsCut_TIGHT->SetMarkerColor(kGreen);

  TCanvas *Canvas_Zmass_Inclusive_noNJetsCut = new TCanvas("Canvas_Zmass_Inclusive_noNJetsCut","Canvas_Zmass_Inclusive_noNJetsCut",0,0,600,800);
  Canvas_Zmass_Inclusive_noNJetsCut->cd();
  h_Zmass_Inclusive_noNJetsCut_NoElectronVeto->Draw();
  h_Zmass_Inclusive_noNJetsCut_FO->Draw("same");
  h_Zmass_Inclusive_noNJetsCut_TIGHT->Draw("same");
  qw_Inclusive_noNJetsCut->AddEntry(h_Zmass_Inclusive_noNJetsCut_FO,"FO (Den)","pl");
  qw_Inclusive_noNJetsCut->AddEntry(h_Zmass_Inclusive_noNJetsCut_NoElectronVeto,"No-electron-veto (Den)","pl");
  qw_Inclusive_noNJetsCut->AddEntry(h_Zmass_Inclusive_noNJetsCut_TIGHT,"TIGHT (Num)","pl");
  qw_Inclusive_noNJetsCut->Draw("same");
  Canvas_Zmass_Inclusive_noNJetsCut->Update();
  title->Draw("same");
  Canvas_Zmass_Inclusive_noNJetsCut->SaveAs("plots_TagAndProbeEfficiency/Zmass_Inclusive_noNJetsCut.pdf");









  TLegend* qw_Inclusive_noPtCut_noNJetsCut = 0;
  qw_Inclusive_noPtCut_noNJetsCut = new TLegend(0.75,0.99,0.99,0.88);
  qw_Inclusive_noPtCut_noNJetsCut->SetFillColor(kWhite);

  h_Zmass_Inclusive_noPtCut_noNJetsCut_NoElectronVeto->GetXaxis()->SetTitle("Mass");
  h_Zmass_Inclusive_noPtCut_noNJetsCut_NoElectronVeto->GetXaxis()->SetTitleSize(0.045);
  h_Zmass_Inclusive_noPtCut_noNJetsCut_NoElectronVeto->GetYaxis()->SetTitle("Entries");
  h_Zmass_Inclusive_noPtCut_noNJetsCut_NoElectronVeto->GetYaxis()->SetTitleSize(0.045);
  h_Zmass_Inclusive_noPtCut_noNJetsCut_NoElectronVeto->SetTitle("Photon-Muon-Muon Invariant Mass");
  h_Zmass_Inclusive_noPtCut_noNJetsCut_NoElectronVeto->GetYaxis()->SetLabelSize(0.025);
  h_Zmass_Inclusive_noPtCut_noNJetsCut_NoElectronVeto->GetXaxis()->SetRangeUser(0.,300.);
  h_Zmass_Inclusive_noPtCut_noNJetsCut_NoElectronVeto->SetLineColor(kBlue);
  h_Zmass_Inclusive_noPtCut_noNJetsCut_NoElectronVeto->SetMarkerStyle(8);
  h_Zmass_Inclusive_noPtCut_noNJetsCut_NoElectronVeto->SetMarkerColor(kBlue);

  h_Zmass_Inclusive_noPtCut_noNJetsCut_FO->SetLineColor(kRed);
  h_Zmass_Inclusive_noPtCut_noNJetsCut_FO->SetMarkerStyle(8);
  h_Zmass_Inclusive_noPtCut_noNJetsCut_FO->SetMarkerColor(kRed);

  h_Zmass_Inclusive_noPtCut_noNJetsCut_TIGHT->SetLineColor(kGreen);
  h_Zmass_Inclusive_noPtCut_noNJetsCut_TIGHT->SetMarkerStyle(8);
  h_Zmass_Inclusive_noPtCut_noNJetsCut_TIGHT->SetMarkerColor(kGreen);

  TCanvas *Canvas_Zmass_Inclusive_noPtCut_noNJetsCut = new TCanvas("Canvas_Zmass_Inclusive_noPtCut_noNJetsCut","Canvas_Zmass_Inclusive_noPtCut_noNJetsCut",0,0,600,800);
  Canvas_Zmass_Inclusive_noPtCut_noNJetsCut->cd();
  h_Zmass_Inclusive_noPtCut_noNJetsCut_NoElectronVeto->Draw();
  h_Zmass_Inclusive_noPtCut_noNJetsCut_FO->Draw("same");
  h_Zmass_Inclusive_noPtCut_noNJetsCut_TIGHT->Draw("same");
  qw_Inclusive_noPtCut_noNJetsCut->AddEntry(h_Zmass_Inclusive_noPtCut_noNJetsCut_FO,"FO (Den)","pl");
  qw_Inclusive_noPtCut_noNJetsCut->AddEntry(h_Zmass_Inclusive_noPtCut_noNJetsCut_NoElectronVeto,"No-electron-veto (Den)","pl");
  qw_Inclusive_noPtCut_noNJetsCut->AddEntry(h_Zmass_Inclusive_noPtCut_noNJetsCut_TIGHT,"TIGHT (Num)","pl");
  qw_Inclusive_noPtCut_noNJetsCut->Draw("same");
  Canvas_Zmass_Inclusive_noPtCut_noNJetsCut->Update();
  title->Draw("same");
  Canvas_Zmass_Inclusive_noPtCut_noNJetsCut->SaveAs("plots_TagAndProbeEfficiency/Zmass_Inclusive_noPtCut_noNJetsCut.pdf");







  h_EfficiencyRatio_NJets->GetXaxis()->SetTitle("Jet multiplicity");
  h_EfficiencyRatio_NJets->GetXaxis()->SetTitleSize(0.045);
  h_EfficiencyRatio_NJets->GetYaxis()->SetTitle("Ratio");
  h_EfficiencyRatio_NJets->GetYaxis()->SetTitleSize(0.045);
  h_EfficiencyRatio_NJets->SetTitle("#varepsilon_{s} (TIGHT to FO-plus-no-electron-veto ratio)");
  h_EfficiencyRatio_NJets->GetYaxis()->SetLabelSize(0.025);
  h_EfficiencyRatio_NJets->SetLineColor(kBlack);
  h_EfficiencyRatio_NJets->GetYaxis()->SetRangeUser(0.,1.);
  h_EfficiencyRatio_NJets->SetMarkerStyle(8);
  h_EfficiencyRatio_NJets->SetMarkerColor(kBlack);



  TCanvas *Canvas_EfficiencyRatio_NJets = new TCanvas("Canvas_EfficiencyRatio_NJets","Canvas_EfficiencyRatio_NJets",0,0,600,800);
  Canvas_EfficiencyRatio_NJets->cd();
  h_EfficiencyRatio_NJets->Draw();
  Canvas_EfficiencyRatio_NJets->Update();
  title->Draw("same");
  Canvas_EfficiencyRatio_NJets->SaveAs("plots_TagAndProbeEfficiency/EfficiencyRatio_NJets.pdf");






  h_EfficiencyRatio_Eta->GetXaxis()->SetTitle("#eta");
  h_EfficiencyRatio_Eta->GetXaxis()->SetTitleSize(0.045);
  h_EfficiencyRatio_Eta->GetYaxis()->SetTitle("Ratio");
  h_EfficiencyRatio_Eta->GetYaxis()->SetTitleSize(0.045);
  h_EfficiencyRatio_Eta->SetTitle("#varepsilon_{s} (TIGHT to FO-plus-no-electron-veto ratio)");
  h_EfficiencyRatio_Eta->GetYaxis()->SetLabelSize(0.025);
  h_EfficiencyRatio_Eta->SetLineColor(kBlack);
  h_EfficiencyRatio_Eta->GetYaxis()->SetRangeUser(0.,1.);
  h_EfficiencyRatio_Eta->SetMarkerStyle(8);
  h_EfficiencyRatio_Eta->SetMarkerColor(kBlack);



  TCanvas *Canvas_EfficiencyRatio_Eta = new TCanvas("Canvas_EfficiencyRatio_Eta","Canvas_EfficiencyRatio_Eta",0,0,600,800);
  Canvas_EfficiencyRatio_Eta->cd();
  h_EfficiencyRatio_Eta->Draw();
  Canvas_EfficiencyRatio_Eta->Update();
  title->Draw("same");
  Canvas_EfficiencyRatio_Eta->SaveAs("plots_TagAndProbeEfficiency/EfficiencyRatio_Eta.pdf");







  h_EfficiencyRatio_PT->GetXaxis()->SetTitle("p_{T}");
  h_EfficiencyRatio_PT->GetXaxis()->SetTitleSize(0.045);
  h_EfficiencyRatio_PT->GetYaxis()->SetTitle("Ratio");
  h_EfficiencyRatio_PT->GetYaxis()->SetTitleSize(0.045);
  h_EfficiencyRatio_PT->SetTitle("#varepsilon_{s} (TIGHT to FO-plus-no-electron-veto ratio)");
  h_EfficiencyRatio_PT->GetYaxis()->SetLabelSize(0.025);
  h_EfficiencyRatio_PT->SetLineColor(kBlack);
  h_EfficiencyRatio_PT->GetYaxis()->SetRangeUser(0.,1.);
  h_EfficiencyRatio_PT->GetXaxis()->SetRangeUser(0.,300.);
  h_EfficiencyRatio_PT->SetMarkerStyle(8);
  h_EfficiencyRatio_PT->SetMarkerColor(kBlack);

  TCanvas *Canvas_EfficiencyRatio_PT = new TCanvas("Canvas_EfficiencyRatio_PT","Canvas_EfficiencyRatio_PT",0,0,600,800);
  Canvas_EfficiencyRatio_PT->cd();
  h_EfficiencyRatio_PT->Draw();
  Canvas_EfficiencyRatio_PT->Update();
  title->Draw("same");
  Canvas_EfficiencyRatio_PT->SaveAs("plots_TagAndProbeEfficiency/EfficiencyRatio_PT.pdf");








  h_EfficiencyRatio_Eta_PT->GetXaxis()->SetTitle("#eta");
  h_EfficiencyRatio_Eta_PT->GetXaxis()->SetTitleSize(0.045);
  h_EfficiencyRatio_Eta_PT->GetYaxis()->SetTitle("p_{T}");
  h_EfficiencyRatio_Eta_PT->GetYaxis()->SetTitleSize(0.045);
  h_EfficiencyRatio_Eta_PT->SetTitle("#varepsilon_{s} (TIGHT to FO-plus-no-electron-veto ratio)");
  h_EfficiencyRatio_Eta_PT->GetYaxis()->SetLabelSize(0.025);
  h_EfficiencyRatio_Eta_PT->SetLineColor(kBlack);
  h_EfficiencyRatio_Eta_PT->GetYaxis()->SetRangeUser(0.,70.);
  h_EfficiencyRatio_Eta_PT->SetMarkerStyle(8);
  h_EfficiencyRatio_Eta_PT->SetMarkerColor(kBlack);

  TCanvas *Canvas_EfficiencyRatio_Eta_PT = new TCanvas("Canvas_EfficiencyRatio_Eta_PT","Canvas_EfficiencyRatio_Eta_PT",0,0,900,600);
  Canvas_EfficiencyRatio_Eta_PT->cd();
  h_EfficiencyRatio_Eta_PT->Draw("colz");
  Canvas_EfficiencyRatio_Eta_PT->Update();
  title->Draw("same");
  Canvas_EfficiencyRatio_Eta_PT->SaveAs("plots_TagAndProbeEfficiency/EfficiencyRatio_Eta_PT.pdf");








  h_EfficiencyRatio_NVTX->GetXaxis()->SetTitle("Vertex Multiplicity");
  h_EfficiencyRatio_NVTX->GetXaxis()->SetTitleSize(0.045);
  h_EfficiencyRatio_NVTX->GetYaxis()->SetTitle("Ratio");
  h_EfficiencyRatio_NVTX->GetYaxis()->SetTitleSize(0.045);
  h_EfficiencyRatio_NVTX->SetTitle("#varepsilon_{s} (TIGHT to FO-plus-no-electron-veto ratio)");
  h_EfficiencyRatio_NVTX->GetYaxis()->SetLabelSize(0.025);
  h_EfficiencyRatio_NVTX->SetLineColor(kBlack);
  h_EfficiencyRatio_NVTX->GetYaxis()->SetRangeUser(0.,1.);
  h_EfficiencyRatio_NVTX->SetMarkerStyle(8);
  h_EfficiencyRatio_NVTX->SetMarkerColor(kBlack);

  TCanvas *Canvas_EfficiencyRatio_NVTX = new TCanvas("Canvas_EfficiencyRatio_NVTX","Canvas_EfficiencyRatio_NVTX",0,0,600,800);
  Canvas_EfficiencyRatio_NVTX->cd();
  h_EfficiencyRatio_NVTX->Draw();
  Canvas_EfficiencyRatio_NVTX->Update();
  title->Draw("same");
  Canvas_EfficiencyRatio_NVTX->SaveAs("plots_TagAndProbeEfficiency/EfficiencyRatio_NVTX.pdf");





}
