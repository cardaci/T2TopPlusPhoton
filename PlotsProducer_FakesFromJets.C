PlotsProducer_FakesFromJets(){

  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);

  TFile * file_Input   = new TFile("FakesFromJetsResults.root");

  file_Input->cd();


  h_Inclusive_QGTagsMLP_Matched_FO = (TH1F*)gDirectory->Get("Inclusive_QGTagsMLP_Matched_FO");
  h_Inclusive_QGTagsMLP_Matched_TIGHT = (TH1F*)gDirectory->Get("Inclusive_QGTagsMLP_Matched_TIGHT");
  h_Inclusive_QGTagsLikelihood_Matched_FO = (TH1F*)gDirectory->Get("Inclusive_QGTagsLikelihood_Matched_FO");
  h_Inclusive_QGTagsLikelihood_Matched_TIGHT = (TH1F*)gDirectory->Get("Inclusive_QGTagsLikelihood_Matched_TIGHT");

  h_Inclusive_Sigma_Ieta_Ieta_TIGHT_Gluon = (TH1F*)gDirectory->Get("Inclusive_Sigma_Ieta_Ieta_TIGHT_Gluon");
  h_Inclusive_Sigma_Ieta_Ieta_TIGHT_Quark = (TH1F*)gDirectory->Get("Inclusive_Sigma_Ieta_Ieta_TIGHT_Quark");
  h_Inclusive_Sigma_Ieta_Ieta_FO_Gluon = (TH1F*)gDirectory->Get("Inclusive_Sigma_Ieta_Ieta_FO_Gluon");
  h_Inclusive_Sigma_Ieta_Ieta_FO_Quark = (TH1F*)gDirectory->Get("Inclusive_Sigma_Ieta_Ieta_FO_Quark");

  h_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Gluon = (TH1F*)gDirectory->Get("Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Gluon");
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark = (TH1F*)gDirectory->Get("Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark");
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Gluon = (TH1F*)gDirectory->Get("Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Gluon");
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Quark = (TH1F*)gDirectory->Get("Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Quark");

  h_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Gluon = (TH1F*)gDirectory->Get("Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Gluon");
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Quark = (TH1F*)gDirectory->Get("Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Quark");
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Gluon = (TH1F*)gDirectory->Get("Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Gluon");
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Quark = (TH1F*)gDirectory->Get("Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Quark");



  h_Inclusive_noNJetsCut_QGTagsMLP_Matched_FO = (TH1F*)gDirectory->Get("Inclusive_noNJetsCut_QGTagsMLP_Matched_FO");
  h_Inclusive_noNJetsCut_QGTagsMLP_Matched_TIGHT = (TH1F*)gDirectory->Get("Inclusive_noNJetsCut_QGTagsMLP_Matched_TIGHT");
  h_Inclusive_noNJetsCut_QGTagsLikelihood_Matched_FO = (TH1F*)gDirectory->Get("Inclusive_noNJetsCut_QGTagsLikelihood_Matched_FO");
  h_Inclusive_noNJetsCut_QGTagsLikelihood_Matched_TIGHT = (TH1F*)gDirectory->Get("Inclusive_noNJetsCut_QGTagsLikelihood_Matched_TIGHT");

  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Gluon = (TH1F*)gDirectory->Get("Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Gluon");
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Quark = (TH1F*)gDirectory->Get("Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Quark");
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Gluon = (TH1F*)gDirectory->Get("Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Gluon");
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Quark = (TH1F*)gDirectory->Get("Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Quark");




  h_Efficiency_TIGHT_Matching = (TH1F*)gDirectory->Get("Efficiency_TIGHT_Matching");
  h_Efficiency_FO_Matching = (TH1F*)gDirectory->Get("Efficiency_FO_Matching");

  h_FakeRateRatio_Gluon_NJets = (TH1F*)gDirectory->Get("FakeRateRatio_Gluon_NJets");
  h_FakeRateRatio_Quark_NJets = (TH1F*)gDirectory->Get("FakeRateRatio_Quark_NJets");

  h_FakeRateRatio_Gluon_Eta = (TH1F*)gDirectory->Get("FakeRateRatio_Gluon_Eta");
  h_FakeRateRatio_Quark_Eta = (TH1F*)gDirectory->Get("FakeRateRatio_Quark_Eta");

  h_FakeRateRatio_Gluon_PT = (TH1F*)gDirectory->Get("FakeRateRatio_Gluon_PT");
  h_FakeRateRatio_Quark_PT = (TH1F*)gDirectory->Get("FakeRateRatio_Quark_PT");


  h_FakeRateRatio_Gluon_Eta_PT = (TH1F*)gDirectory->Get("FakeRateRatio_Gluon_Eta_PT");
  h_FakeRateRatio_Quark_Eta_PT = (TH1F*)gDirectory->Get("FakeRateRatio_Quark_Eta_PT");


  h_FakeRateRatio_Gluon_NVTX = (TH1F*)gDirectory->Get("FakeRateRatio_Gluon_NVTX");
  h_FakeRateRatio_Quark_NVTX = (TH1F*)gDirectory->Get("FakeRateRatio_Quark_NVTX");




  TLegend* qw_sigma = 0;
  qw_sigma = new TLegend(0.75,0.99,0.99,0.88);
  qw_sigma->SetFillColor(kWhite);

  h_Inclusive_Sigma_Ieta_Ieta_TIGHT_Quark->GetXaxis()->SetTitle("#sigma_{i#eta i#eta}");
  h_Inclusive_Sigma_Ieta_Ieta_TIGHT_Quark->GetXaxis()->SetTitleSize(0.045);
  h_Inclusive_Sigma_Ieta_Ieta_TIGHT_Quark->GetYaxis()->SetTitle("Entries");
  h_Inclusive_Sigma_Ieta_Ieta_TIGHT_Quark->GetYaxis()->SetTitleSize(0.045);
  h_Inclusive_Sigma_Ieta_Ieta_TIGHT_Quark->SetTitle("#sigma_{i#eta i#eta} for TIGHT objects");
  h_Inclusive_Sigma_Ieta_Ieta_TIGHT_Quark->GetYaxis()->SetLabelSize(0.025);
  h_Inclusive_Sigma_Ieta_Ieta_TIGHT_Quark->GetXaxis()->SetLabelSize(0.025);
  h_Inclusive_Sigma_Ieta_Ieta_TIGHT_Quark->SetLineColor(kBlue);
  h_Inclusive_Sigma_Ieta_Ieta_TIGHT_Quark->GetXaxis()->SetRangeUser(0.,0.1);
  h_Inclusive_Sigma_Ieta_Ieta_TIGHT_Quark->SetMarkerStyle(8);
  h_Inclusive_Sigma_Ieta_Ieta_TIGHT_Quark->SetMarkerColor(kBlue);

  h_Inclusive_Sigma_Ieta_Ieta_TIGHT_Gluon->SetLineColor(kRed);
  h_Inclusive_Sigma_Ieta_Ieta_TIGHT_Gluon->SetMarkerStyle(8);
  h_Inclusive_Sigma_Ieta_Ieta_TIGHT_Gluon->SetMarkerColor(kRed);

  TCanvas *Canvas_Inclusive_Sigma_Ieta_Ieta_TIGHT = new TCanvas("Canvas_Inclusive_Sigma_Ieta_Ieta_TIGHT","Canvas_Inclusive_Sigma_Ieta_Ieta_TIGHT",0,0,600,800);
  Canvas_Inclusive_Sigma_Ieta_Ieta_TIGHT->cd();
  h_Inclusive_Sigma_Ieta_Ieta_TIGHT_Quark->Draw("histe");
  h_Inclusive_Sigma_Ieta_Ieta_TIGHT_Gluon->Draw("histesame");
  qw_sigma->AddEntry(h_Inclusive_Sigma_Ieta_Ieta_TIGHT_Quark,"Quark-like","pl");
  qw_sigma->AddEntry(h_Inclusive_Sigma_Ieta_Ieta_TIGHT_Gluon,"Gluon-like","pl");
  qw_sigma->Draw("same");
  Canvas_Inclusive_Sigma_Ieta_Ieta_TIGHT->Update();
  title->Draw("same");
  Canvas_Inclusive_Sigma_Ieta_Ieta_TIGHT->SaveAs("plots_FakesFromJets/Inclusive_Sigma_Ieta_Ieta_TIGHT.pdf");



  h_Inclusive_Sigma_Ieta_Ieta_FO_Quark->GetXaxis()->SetTitle("#sigma_{i#eta i#eta}");
  h_Inclusive_Sigma_Ieta_Ieta_FO_Quark->GetXaxis()->SetTitleSize(0.045);
  h_Inclusive_Sigma_Ieta_Ieta_FO_Quark->GetYaxis()->SetTitle("Entries");
  h_Inclusive_Sigma_Ieta_Ieta_FO_Quark->GetYaxis()->SetTitleSize(0.045);
  h_Inclusive_Sigma_Ieta_Ieta_FO_Quark->SetTitle("#sigma_{i#eta i#eta} for FO");
  h_Inclusive_Sigma_Ieta_Ieta_FO_Quark->GetYaxis()->SetLabelSize(0.025);
  h_Inclusive_Sigma_Ieta_Ieta_FO_Quark->GetXaxis()->SetLabelSize(0.025);
  h_Inclusive_Sigma_Ieta_Ieta_FO_Quark->SetLineColor(kBlue);
  h_Inclusive_Sigma_Ieta_Ieta_FO_Quark->GetXaxis()->SetRangeUser(0.,0.1);
  h_Inclusive_Sigma_Ieta_Ieta_FO_Quark->SetMarkerStyle(8);
  h_Inclusive_Sigma_Ieta_Ieta_FO_Quark->SetMarkerColor(kBlue);

  h_Inclusive_Sigma_Ieta_Ieta_FO_Gluon->SetLineColor(kRed);
  h_Inclusive_Sigma_Ieta_Ieta_FO_Gluon->SetMarkerStyle(8);
  h_Inclusive_Sigma_Ieta_Ieta_FO_Gluon->SetMarkerColor(kRed);

  TCanvas *Canvas_Inclusive_Sigma_Ieta_Ieta_FO = new TCanvas("Canvas_Inclusive_Sigma_Ieta_Ieta_FO","Canvas_Inclusive_Sigma_Ieta_Ieta_FO",0,0,600,800);
  Canvas_Inclusive_Sigma_Ieta_Ieta_FO->cd();
  h_Inclusive_Sigma_Ieta_Ieta_FO_Quark->Draw("histe");
  h_Inclusive_Sigma_Ieta_Ieta_FO_Gluon->Draw("histesame");
  qw_sigma->Draw("same");
  Canvas_Inclusive_Sigma_Ieta_Ieta_FO->Update();
  title->Draw("same");
  Canvas_Inclusive_Sigma_Ieta_Ieta_FO->SaveAs("plots_FakesFromJets/Inclusive_Sigma_Ieta_Ieta_FO.pdf");






  h_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark->GetXaxis()->SetTitle("#sigma_{i#eta i#eta}");
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark->GetXaxis()->SetTitleSize(0.045);
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark->GetYaxis()->SetTitle("Entries");
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark->GetYaxis()->SetTitleSize(0.045);
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark->SetTitle("#sigma_{i#eta i#eta} for TIGHT objects");
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark->GetYaxis()->SetLabelSize(0.025);
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark->GetXaxis()->SetLabelSize(0.025);
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark->SetLineColor(kBlue);
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark->GetXaxis()->SetRangeUser(0.,0.1);
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark->SetMarkerStyle(8);
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark->SetMarkerColor(kBlue);

  h_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Gluon->SetLineColor(kRed);
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Gluon->SetMarkerStyle(8);
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Gluon->SetMarkerColor(kRed);

  TCanvas *Canvas_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT = new TCanvas("Canvas_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT","Canvas_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT",0,0,600,800);
  Canvas_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT->cd();
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Quark->Draw("histe");
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT_Gluon->Draw("histesame");
  qw_sigma->Draw("same");
  Canvas_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT->Update();
  title->Draw("same");
  Canvas_Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT->SaveAs("plots_FakesFromJets/Inclusive_Barrel_Sigma_Ieta_Ieta_TIGHT.pdf");



  h_Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Quark->GetXaxis()->SetTitle("#sigma_{i#eta i#eta}");
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Quark->GetXaxis()->SetTitleSize(0.045);
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Quark->GetYaxis()->SetTitle("Entries");
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Quark->GetYaxis()->SetTitleSize(0.045);
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Quark->SetTitle("#sigma_{i#eta i#eta} for FO");
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Quark->GetYaxis()->SetLabelSize(0.025);
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Quark->GetXaxis()->SetLabelSize(0.025);
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Quark->SetLineColor(kBlue);
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Quark->GetXaxis()->SetRangeUser(0.,0.1);
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Quark->SetMarkerStyle(8);
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Quark->SetMarkerColor(kBlue);

  h_Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Gluon->SetLineColor(kRed);
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Gluon->SetMarkerStyle(8);
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Gluon->SetMarkerColor(kRed);

  TCanvas *Canvas_Inclusive_Barrel_Sigma_Ieta_Ieta_FO = new TCanvas("Canvas_Inclusive_Barrel_Sigma_Ieta_Ieta_FO","Canvas_Inclusive_Barrel_Sigma_Ieta_Ieta_FO",0,0,600,800);
  Canvas_Inclusive_Barrel_Sigma_Ieta_Ieta_FO->cd();
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Quark->Draw("histe");
  h_Inclusive_Barrel_Sigma_Ieta_Ieta_FO_Gluon->Draw("histesame");
  qw_sigma->Draw("same");
  Canvas_Inclusive_Barrel_Sigma_Ieta_Ieta_FO->Update();
  title->Draw("same");
  Canvas_Inclusive_Barrel_Sigma_Ieta_Ieta_FO->SaveAs("plots_FakesFromJets/Inclusive_Barrel_Sigma_Ieta_Ieta_FO.pdf");






  h_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Quark->GetXaxis()->SetTitle("#sigma_{i#eta i#eta}");
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Quark->GetXaxis()->SetTitleSize(0.045);
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Quark->GetYaxis()->SetTitle("Entries");
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Quark->GetYaxis()->SetTitleSize(0.045);
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Quark->SetTitle("#sigma_{i#eta i#eta} for TIGHT objects");
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Quark->GetYaxis()->SetLabelSize(0.025);
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Quark->GetXaxis()->SetLabelSize(0.025);
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Quark->SetLineColor(kBlue);
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Quark->GetXaxis()->SetRangeUser(0.,0.1);
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Quark->SetMarkerStyle(8);
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Quark->SetMarkerColor(kBlue);

  h_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Gluon->SetLineColor(kRed);
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Gluon->SetMarkerStyle(8);
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Gluon->SetMarkerColor(kRed);

  TCanvas *Canvas_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT = new TCanvas("Canvas_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT","Canvas_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT",0,0,600,800);
  Canvas_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT->cd();
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Quark->Draw("histe");
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT_Gluon->Draw("histesame");
  qw_sigma->Draw("same");
  Canvas_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT->Update();
  title->Draw("same");
  Canvas_Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT->SaveAs("plots_FakesFromJets/Inclusive_Endcap_Sigma_Ieta_Ieta_TIGHT.pdf");



  h_Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Quark->GetXaxis()->SetTitle("#sigma_{i#eta i#eta}");
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Quark->GetXaxis()->SetTitleSize(0.045);
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Quark->GetYaxis()->SetTitle("Entries");
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Quark->GetYaxis()->SetTitleSize(0.045);
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Quark->SetTitle("#sigma_{i#eta i#eta} for FO");
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Quark->GetYaxis()->SetLabelSize(0.025);
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Quark->GetXaxis()->SetLabelSize(0.025);
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Quark->SetLineColor(kBlue);
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Quark->GetXaxis()->SetRangeUser(0.,0.1);
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Quark->SetMarkerStyle(8);
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Quark->SetMarkerColor(kBlue);

  h_Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Gluon->SetLineColor(kRed);
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Gluon->SetMarkerStyle(8);
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Gluon->SetMarkerColor(kRed);

  TCanvas *Canvas_Inclusive_Endcap_Sigma_Ieta_Ieta_FO = new TCanvas("Canvas_Inclusive_Endcap_Sigma_Ieta_Ieta_FO","Canvas_Inclusive_Endcap_Sigma_Ieta_Ieta_FO",0,0,600,800);
  Canvas_Inclusive_Endcap_Sigma_Ieta_Ieta_FO->cd();
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Quark->Draw("histe");
  h_Inclusive_Endcap_Sigma_Ieta_Ieta_FO_Gluon->Draw("histesame");
  qw_sigma->Draw("same");
  Canvas_Inclusive_Endcap_Sigma_Ieta_Ieta_FO->Update();
  title->Draw("same");
  Canvas_Inclusive_Endcap_Sigma_Ieta_Ieta_FO->SaveAs("plots_FakesFromJets/Inclusive_Endcap_Sigma_Ieta_Ieta_FO.pdf");










  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Quark->GetXaxis()->SetTitle("#sigma_{i#eta i#eta}");
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Quark->GetXaxis()->SetTitleSize(0.045);
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Quark->GetYaxis()->SetTitle("Entries");
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Quark->GetYaxis()->SetTitleSize(0.045);
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Quark->SetTitle("#sigma_{i#eta i#eta} for TIGHT objects");
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Quark->GetYaxis()->SetLabelSize(0.025);
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Quark->GetXaxis()->SetLabelSize(0.025);
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Quark->SetLineColor(kBlue);
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Quark->GetXaxis()->SetRangeUser(0.,0.1);
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Quark->SetMarkerStyle(8);
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Quark->SetMarkerColor(kBlue);

  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Gluon->SetLineColor(kRed);
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Gluon->SetMarkerStyle(8);
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Gluon->SetMarkerColor(kRed);

  TCanvas *Canvas_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT = new TCanvas("Canvas_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT","Canvas_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT",0,0,600,800);
  Canvas_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT->cd();
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Quark->Draw("histe");
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT_Gluon->Draw("histesame");
  qw_sigma->Draw("same");
  Canvas_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT->Update();
  title->Draw("same");
  Canvas_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT->SaveAs("plots_FakesFromJets/Inclusive_noNJetsCut_Sigma_Ieta_Ieta_TIGHT.pdf");



  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Quark->GetXaxis()->SetTitle("#sigma_{i#eta i#eta}");
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Quark->GetXaxis()->SetTitleSize(0.045);
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Quark->GetYaxis()->SetTitle("Entries");
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Quark->GetYaxis()->SetTitleSize(0.045);
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Quark->SetTitle("#sigma_{i#eta i#eta} for FO");
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Quark->GetYaxis()->SetLabelSize(0.025);
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Quark->GetXaxis()->SetLabelSize(0.025);
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Quark->SetLineColor(kBlue);
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Quark->GetXaxis()->SetRangeUser(0.,0.1);
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Quark->SetMarkerStyle(8);
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Quark->SetMarkerColor(kBlue);

  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Gluon->SetLineColor(kRed);
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Gluon->SetMarkerStyle(8);
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Gluon->SetMarkerColor(kRed);

  TCanvas *Canvas_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO = new TCanvas("Canvas_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO","Canvas_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO",0,0,600,800);
  Canvas_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO->cd();
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Quark->Draw("histe");
  h_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO_Gluon->Draw("histesame");
  qw_sigma->Draw("same");
  Canvas_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO->Update();
  title->Draw("same");
  Canvas_Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO->SaveAs("plots_FakesFromJets/Inclusive_noNJetsCut_Sigma_Ieta_Ieta_FO.pdf");









  TLegend* qw = 0;
  qw = new TLegend(0.75,0.99,0.99,0.88);
  qw->SetFillColor(kWhite);

  h_Inclusive_QGTagsMLP_Matched_TIGHT->GetXaxis()->SetTitle("Tagger Value");
  h_Inclusive_QGTagsMLP_Matched_TIGHT->GetXaxis()->SetTitleSize(0.045);
  h_Inclusive_QGTagsMLP_Matched_TIGHT->GetYaxis()->SetTitle("Entries");
  h_Inclusive_QGTagsMLP_Matched_TIGHT->GetYaxis()->SetTitleSize(0.045);
  h_Inclusive_QGTagsMLP_Matched_TIGHT->SetTitle("Quark-Gluon Tagger MLP");
  h_Inclusive_QGTagsMLP_Matched_TIGHT->GetYaxis()->SetLabelSize(0.025);
  h_Inclusive_QGTagsMLP_Matched_TIGHT->GetXaxis()->SetLabelSize(0.025);
  h_Inclusive_QGTagsMLP_Matched_TIGHT->SetLineColor(kBlue);
  h_Inclusive_QGTagsMLP_Matched_TIGHT->GetXaxis()->SetRangeUser(-0.1,1.1);
  h_Inclusive_QGTagsMLP_Matched_TIGHT->SetMarkerStyle(8);
  h_Inclusive_QGTagsMLP_Matched_TIGHT->SetMarkerColor(kBlue);


  h_Inclusive_QGTagsMLP_Matched_FO->SetLineColor(kRed);
  h_Inclusive_QGTagsMLP_Matched_FO->SetMarkerStyle(8);
  h_Inclusive_QGTagsMLP_Matched_FO->SetMarkerColor(kRed);

  TCanvas *Canvas_Inclusive_QGTagsMLP_Matched = new TCanvas("Canvas_Inclusive_QGTagsMLP_Matched","Canvas_Inclusive_QGTagsMLP_Matched",0,0,600,800);
  Canvas_Inclusive_QGTagsMLP_Matched->cd();
  h_Inclusive_QGTagsMLP_Matched_TIGHT->Draw("histe");
  h_Inclusive_QGTagsMLP_Matched_FO->Draw("histesame");
  qw->AddEntry(h_Inclusive_QGTagsMLP_Matched_TIGHT,"TIGHT","pl");
  qw->AddEntry(h_Inclusive_QGTagsMLP_Matched_FO,"FO","pl");
  qw->Draw("same");
  Canvas_Inclusive_QGTagsMLP_Matched->Update();
  title->Draw("same");
  Canvas_Inclusive_QGTagsMLP_Matched->SaveAs("plots_FakesFromJets/Inclusive_QGTagsMLP_Matched.pdf");




  h_Inclusive_QGTagsLikelihood_Matched_FO->GetXaxis()->SetTitle("Tagger Value");
  h_Inclusive_QGTagsLikelihood_Matched_FO->GetXaxis()->SetTitleSize(0.045);
  h_Inclusive_QGTagsLikelihood_Matched_FO->GetYaxis()->SetTitle("Entries");
  h_Inclusive_QGTagsLikelihood_Matched_FO->GetYaxis()->SetTitleSize(0.045);
  h_Inclusive_QGTagsLikelihood_Matched_FO->SetTitle("Quark-Gluon Tagger Likelihood");
  h_Inclusive_QGTagsLikelihood_Matched_FO->GetYaxis()->SetLabelSize(0.025);
  h_Inclusive_QGTagsLikelihood_Matched_FO->GetXaxis()->SetLabelSize(0.025);
  h_Inclusive_QGTagsLikelihood_Matched_FO->SetLineColor(kBlue);
  h_Inclusive_QGTagsLikelihood_Matched_FO->GetXaxis()->SetRangeUser(-0.1,1.1);
  h_Inclusive_QGTagsLikelihood_Matched_FO->SetMarkerStyle(8);
  h_Inclusive_QGTagsLikelihood_Matched_FO->SetMarkerColor(kBlue);


  h_Inclusive_QGTagsLikelihood_Matched_TIGHT->SetLineColor(kRed);
  h_Inclusive_QGTagsLikelihood_Matched_TIGHT->SetMarkerStyle(8);
  h_Inclusive_QGTagsLikelihood_Matched_TIGHT->SetMarkerColor(kRed);

  TCanvas *Canvas_Inclusive_QGTagsLikelihood_Matched = new TCanvas("Canvas_Inclusive_QGTagsLikelihood_Matched","Canvas_Inclusive_QGTagsLikelihood_Matched",0,0,600,800);
  Canvas_Inclusive_QGTagsLikelihood_Matched->cd();
  h_Inclusive_QGTagsLikelihood_Matched_FO->Draw("histe");
  h_Inclusive_QGTagsLikelihood_Matched_TIGHT->Draw("histesame");
  qw->Draw("same");
  Canvas_Inclusive_QGTagsLikelihood_Matched->Update();
  title->Draw("same");
  Canvas_Inclusive_QGTagsLikelihood_Matched->SaveAs("plots_FakesFromJets/Inclusive_QGTagsLikelihood_Matched.pdf");




  h_Inclusive_noNJetsCut_QGTagsMLP_Matched_TIGHT->GetXaxis()->SetTitle("Tagger Value");
  h_Inclusive_noNJetsCut_QGTagsMLP_Matched_TIGHT->GetXaxis()->SetTitleSize(0.045);
  h_Inclusive_noNJetsCut_QGTagsMLP_Matched_TIGHT->GetYaxis()->SetTitle("Entries");
  h_Inclusive_noNJetsCut_QGTagsMLP_Matched_TIGHT->GetYaxis()->SetTitleSize(0.045);
  h_Inclusive_noNJetsCut_QGTagsMLP_Matched_TIGHT->SetTitle("Quark-Gluon Tagger MLP");
  h_Inclusive_noNJetsCut_QGTagsMLP_Matched_TIGHT->GetYaxis()->SetLabelSize(0.025);
  h_Inclusive_noNJetsCut_QGTagsMLP_Matched_TIGHT->GetXaxis()->SetLabelSize(0.025);
  h_Inclusive_noNJetsCut_QGTagsMLP_Matched_TIGHT->SetLineColor(kBlue);
  h_Inclusive_noNJetsCut_QGTagsMLP_Matched_TIGHT->GetXaxis()->SetRangeUser(-0.1,1.1);
  h_Inclusive_noNJetsCut_QGTagsMLP_Matched_TIGHT->SetMarkerStyle(8);
  h_Inclusive_noNJetsCut_QGTagsMLP_Matched_TIGHT->SetMarkerColor(kBlue);


  h_Inclusive_noNJetsCut_QGTagsMLP_Matched_FO->SetLineColor(kRed);
  h_Inclusive_noNJetsCut_QGTagsMLP_Matched_FO->SetMarkerStyle(8);
  h_Inclusive_noNJetsCut_QGTagsMLP_Matched_FO->SetMarkerColor(kRed);

  TCanvas *Canvas_Inclusive_noNJetsCut_QGTagsMLP_Matched = new TCanvas("Canvas_Inclusive_noNJetsCut_QGTagsMLP_Matched","Canvas_Inclusive_noNJetsCut_QGTagsMLP_Matched",0,0,600,800);
  Canvas_Inclusive_noNJetsCut_QGTagsMLP_Matched->cd();
  h_Inclusive_noNJetsCut_QGTagsMLP_Matched_TIGHT->Draw("histe");
  h_Inclusive_noNJetsCut_QGTagsMLP_Matched_FO->Draw("histesame");
  qw->Draw("same");
  Canvas_Inclusive_noNJetsCut_QGTagsMLP_Matched->Update();
  title->Draw("same");
  Canvas_Inclusive_noNJetsCut_QGTagsMLP_Matched->SaveAs("plots_FakesFromJets/Inclusive_noNJetsCut_QGTagsMLP_Matched.pdf");




  h_Inclusive_noNJetsCut_QGTagsLikelihood_Matched_FO->GetXaxis()->SetTitle("Tagger Value");
  h_Inclusive_noNJetsCut_QGTagsLikelihood_Matched_FO->GetXaxis()->SetTitleSize(0.045);
  h_Inclusive_noNJetsCut_QGTagsLikelihood_Matched_FO->GetYaxis()->SetTitle("Entries");
  h_Inclusive_noNJetsCut_QGTagsLikelihood_Matched_FO->GetYaxis()->SetTitleSize(0.045);
  h_Inclusive_noNJetsCut_QGTagsLikelihood_Matched_FO->SetTitle("Quark-Gluon Tagger Likelihood");
  h_Inclusive_noNJetsCut_QGTagsLikelihood_Matched_FO->GetYaxis()->SetLabelSize(0.025);
  h_Inclusive_noNJetsCut_QGTagsLikelihood_Matched_FO->GetXaxis()->SetLabelSize(0.025);
  h_Inclusive_noNJetsCut_QGTagsLikelihood_Matched_FO->SetLineColor(kBlue);
  h_Inclusive_noNJetsCut_QGTagsLikelihood_Matched_FO->GetXaxis()->SetRangeUser(-0.1,1.1);
  h_Inclusive_noNJetsCut_QGTagsLikelihood_Matched_FO->SetMarkerStyle(8);
  h_Inclusive_noNJetsCut_QGTagsLikelihood_Matched_FO->SetMarkerColor(kBlue);


  h_Inclusive_noNJetsCut_QGTagsLikelihood_Matched_TIGHT->SetLineColor(kRed);
  h_Inclusive_noNJetsCut_QGTagsLikelihood_Matched_TIGHT->SetMarkerStyle(8);
  h_Inclusive_noNJetsCut_QGTagsLikelihood_Matched_TIGHT->SetMarkerColor(kRed);

  TCanvas *Canvas_Inclusive_noNJetsCut_QGTagsLikelihood_Matched = new TCanvas("Canvas_Inclusive_noNJetsCut_QGTagsLikelihood_Matched","Canvas_Inclusive_noNJetsCut_QGTagsLikelihood_Matched",0,0,600,800);
  Canvas_Inclusive_noNJetsCut_QGTagsLikelihood_Matched->cd();
  h_Inclusive_noNJetsCut_QGTagsLikelihood_Matched_FO->Draw("histe");
  h_Inclusive_noNJetsCut_QGTagsLikelihood_Matched_TIGHT->Draw("histesame");
  qw->Draw("same");
  Canvas_Inclusive_noNJetsCut_QGTagsLikelihood_Matched->Update();
  title->Draw("same");
  Canvas_Inclusive_noNJetsCut_QGTagsLikelihood_Matched->SaveAs("plots_FakesFromJets/Inclusive_noNJetsCut_QGTagsLikelihood_Matched.pdf");









  h_Efficiency_FO_Matching->GetXaxis()->SetTitleSize(0.045);
  h_Efficiency_FO_Matching->GetYaxis()->SetTitle("Efficiency");
  h_Efficiency_FO_Matching->GetYaxis()->SetTitleSize(0.045);
  h_Efficiency_FO_Matching->SetTitle("Matching Efficiency");
  h_Efficiency_FO_Matching->GetYaxis()->SetLabelSize(0.025);
  h_Efficiency_FO_Matching->GetXaxis()->SetLabelSize(0.025);
  h_Efficiency_FO_Matching->SetLineColor(kBlue);
  h_Efficiency_FO_Matching->GetYaxis()->SetRangeUser(0,1);
  h_Efficiency_FO_Matching->SetMarkerStyle(8);
  h_Efficiency_FO_Matching->SetMarkerColor(kBlue);


  h_Efficiency_TIGHT_Matching->SetLineColor(kRed);
  h_Efficiency_TIGHT_Matching->SetMarkerStyle(8);
  h_Efficiency_TIGHT_Matching->SetMarkerColor(kRed);

  TCanvas *Canvas_Matching_Efficiency = new TCanvas("Canvas_Matching_Efficiency","Canvas_Matching_Efficiency",0,0,600,800);
  Canvas_Matching_Efficiency->cd();
  h_Efficiency_FO_Matching->Draw();
  h_Efficiency_TIGHT_Matching->Draw("same");
  qw->Draw("same");
  Canvas_Matching_Efficiency->Update();
  title->Draw("same");
  Canvas_Matching_Efficiency->SaveAs("plots_FakesFromJets/Matching_Efficiency.pdf");



  TLegend* qw2 = 0;
  qw2 = new TLegend(0.75,0.99,0.99,0.88);
  qw2->SetFillColor(kWhite);



  h_FakeRateRatio_Gluon_NJets->GetXaxis()->SetTitle("Jet multiplicity");
  h_FakeRateRatio_Gluon_NJets->GetXaxis()->SetTitleSize(0.045);
  h_FakeRateRatio_Gluon_NJets->GetYaxis()->SetTitle("Ratio");
  h_FakeRateRatio_Gluon_NJets->GetYaxis()->SetTitleSize(0.045);
  h_FakeRateRatio_Gluon_NJets->SetTitle("#varepsilon_{j} (TIGHT to FO ratio)");
  h_FakeRateRatio_Gluon_NJets->GetYaxis()->SetLabelSize(0.025);
  h_FakeRateRatio_Gluon_NJets->GetXaxis()->SetLabelSize(0.025);
  h_FakeRateRatio_Gluon_NJets->SetLineColor(kRed);
  h_FakeRateRatio_Gluon_NJets->GetYaxis()->SetRangeUser(0.,1.);
  h_FakeRateRatio_Gluon_NJets->SetMarkerStyle(8);
  h_FakeRateRatio_Gluon_NJets->SetMarkerColor(kRed);


  h_FakeRateRatio_Quark_NJets->SetLineColor(kBlue);
  h_FakeRateRatio_Quark_NJets->SetMarkerStyle(8);
  h_FakeRateRatio_Quark_NJets->SetMarkerColor(kBlue);

  TCanvas *Canvas_FakeRateRatio_NJets = new TCanvas("Canvas_FakeRateRatio_NJets","Canvas_FakeRateRatio_NJets",0,0,600,800);
  Canvas_FakeRateRatio_NJets->cd();
  h_FakeRateRatio_Gluon_NJets->Draw();
  h_FakeRateRatio_Quark_NJets->Draw("same");
  qw2->AddEntry(h_FakeRateRatio_Quark_NJets,"Quark-like","pl");
  qw2->AddEntry(h_FakeRateRatio_Gluon_NJets,"Gluon-like","pl");
  qw2->Draw("same");
  Canvas_FakeRateRatio_NJets->Update();
  title->Draw("same");
  Canvas_FakeRateRatio_NJets->SaveAs("plots_FakesFromJets/FakeRateRatio_NJets.pdf");





  h_FakeRateRatio_Gluon_Eta->GetXaxis()->SetTitle("#eta");
  h_FakeRateRatio_Gluon_Eta->GetXaxis()->SetTitleSize(0.045);
  h_FakeRateRatio_Gluon_Eta->GetYaxis()->SetTitle("Ratio");
  h_FakeRateRatio_Gluon_Eta->GetYaxis()->SetTitleSize(0.045);
  h_FakeRateRatio_Gluon_Eta->SetTitle("#varepsilon_{j} (TIGHT to FO ratio)");
  h_FakeRateRatio_Gluon_Eta->GetYaxis()->SetLabelSize(0.025);
  h_FakeRateRatio_Gluon_Eta->GetXaxis()->SetLabelSize(0.025);
  h_FakeRateRatio_Gluon_Eta->SetLineColor(kRed);
  h_FakeRateRatio_Gluon_Eta->GetYaxis()->SetRangeUser(0.,1.);
  h_FakeRateRatio_Gluon_Eta->SetMarkerStyle(8);
  h_FakeRateRatio_Gluon_Eta->SetMarkerColor(kRed);


  h_FakeRateRatio_Quark_Eta->SetLineColor(kBlue);
  h_FakeRateRatio_Quark_Eta->SetMarkerStyle(8);
  h_FakeRateRatio_Quark_Eta->SetMarkerColor(kBlue);

  TCanvas *Canvas_FakeRateRatio_Eta = new TCanvas("Canvas_FakeRateRatio_Eta","Canvas_FakeRateRatio_Eta",0,0,600,800);
  Canvas_FakeRateRatio_Eta->cd();
  h_FakeRateRatio_Gluon_Eta->Draw();
  h_FakeRateRatio_Quark_Eta->Draw("same");
  qw2->Draw("same");
  Canvas_FakeRateRatio_Eta->Update();
  title->Draw("same");
  Canvas_FakeRateRatio_Eta->SaveAs("plots_FakesFromJets/FakeRateRatio_Eta.pdf");







  h_FakeRateRatio_Gluon_PT->GetXaxis()->SetTitle("p_{T}");
  h_FakeRateRatio_Gluon_PT->GetXaxis()->SetTitleSize(0.045);
  h_FakeRateRatio_Gluon_PT->GetYaxis()->SetTitle("Ratio");
  h_FakeRateRatio_Gluon_PT->GetYaxis()->SetTitleSize(0.045);
  h_FakeRateRatio_Gluon_PT->SetTitle("#varepsilon_{j} (TIGHT to FO ratio)");
  h_FakeRateRatio_Gluon_PT->GetYaxis()->SetLabelSize(0.025);
  h_FakeRateRatio_Gluon_PT->GetXaxis()->SetLabelSize(0.025);
  h_FakeRateRatio_Gluon_PT->SetLineColor(kRed);
  h_FakeRateRatio_Gluon_PT->GetYaxis()->SetRangeUser(0.,1.);
  h_FakeRateRatio_Gluon_PT->GetXaxis()->SetRangeUser(0.,1000.);
  h_FakeRateRatio_Gluon_PT->SetMarkerStyle(8);
  h_FakeRateRatio_Gluon_PT->SetMarkerColor(kRed);


  h_FakeRateRatio_Quark_PT->SetLineColor(kBlue);
  h_FakeRateRatio_Quark_PT->SetMarkerStyle(8);
  h_FakeRateRatio_Quark_PT->SetMarkerColor(kBlue);

  TCanvas *Canvas_FakeRateRatio_PT = new TCanvas("Canvas_FakeRateRatio_PT","Canvas_FakeRateRatio_PT",0,0,600,800);
  Canvas_FakeRateRatio_PT->cd();
  h_FakeRateRatio_Gluon_PT->Draw();
  h_FakeRateRatio_Quark_PT->Draw("same");
  qw2->Draw("same");
  Canvas_FakeRateRatio_PT->Update();
  title->Draw("same");
  Canvas_FakeRateRatio_PT->SaveAs("plots_FakesFromJets/FakeRateRatio_PT.pdf");








  h_FakeRateRatio_Gluon_Eta_PT->GetXaxis()->SetTitle("#eta");
  h_FakeRateRatio_Gluon_Eta_PT->GetXaxis()->SetTitleSize(0.045);
  h_FakeRateRatio_Gluon_Eta_PT->GetYaxis()->SetTitle("p_{T}");
  h_FakeRateRatio_Gluon_Eta_PT->GetYaxis()->SetTitleSize(0.045);
  h_FakeRateRatio_Gluon_Eta_PT->SetTitle("#varepsilon_{j} (TIGHT to FO ratio) for Gluon-like");
  h_FakeRateRatio_Gluon_Eta_PT->GetYaxis()->SetLabelSize(0.025);
  h_FakeRateRatio_Gluon_Eta_PT->GetXaxis()->SetLabelSize(0.025);
  h_FakeRateRatio_Gluon_Eta_PT->GetZaxis()->SetLabelSize(0.025);
  h_FakeRateRatio_Gluon_Eta_PT->SetLineColor(kRed);
  h_FakeRateRatio_Gluon_Eta_PT->GetYaxis()->SetRangeUser(0.,1000.);
  h_FakeRateRatio_Gluon_Eta_PT->SetMarkerStyle(8);
  h_FakeRateRatio_Gluon_Eta_PT->SetMarkerColor(kRed);


  TCanvas *Canvas_FakeRateRatio_Eta_PT = new TCanvas("Canvas_FakeRateRatio_Gluon_Eta_PT","Canvas_FakeRateRatio_Gluon_Eta_PT",0,0,900,600);
  Canvas_FakeRateRatio_Gluon_Eta_PT->cd();
  h_FakeRateRatio_Gluon_Eta_PT->Draw("colz");
  Canvas_FakeRateRatio_Gluon_Eta_PT->Update();
  title->Draw("same");
  Canvas_FakeRateRatio_Gluon_Eta_PT->SaveAs("plots_FakesFromJets/FakeRateRatio_Gluon_Eta_PT.pdf");





  h_FakeRateRatio_Quark_Eta_PT->GetXaxis()->SetTitle("#eta");
  h_FakeRateRatio_Quark_Eta_PT->GetXaxis()->SetTitleSize(0.045);
  h_FakeRateRatio_Quark_Eta_PT->GetYaxis()->SetTitle("p_{T}");
  h_FakeRateRatio_Quark_Eta_PT->GetYaxis()->SetTitleSize(0.045);
  h_FakeRateRatio_Quark_Eta_PT->SetTitle("#varepsilon_{j} (TIGHT to FO ratio) for Quark-like");
  h_FakeRateRatio_Quark_Eta_PT->GetYaxis()->SetLabelSize(0.025);
  h_FakeRateRatio_Quark_Eta_PT->GetXaxis()->SetLabelSize(0.025);
  h_FakeRateRatio_Quark_Eta_PT->GetZaxis()->SetLabelSize(0.025);
  h_FakeRateRatio_Quark_Eta_PT->SetLineColor(kRed);
  h_FakeRateRatio_Quark_Eta_PT->GetYaxis()->SetRangeUser(0.,1000.);
  h_FakeRateRatio_Quark_Eta_PT->SetMarkerStyle(8);
  h_FakeRateRatio_Quark_Eta_PT->SetMarkerColor(kRed);


  TCanvas *Canvas_FakeRateRatio_Eta_PT = new TCanvas("Canvas_FakeRateRatio_Quark_Eta_PT","Canvas_FakeRateRatio_Quark_Eta_PT",0,0,900,600);
  Canvas_FakeRateRatio_Quark_Eta_PT->cd();
  h_FakeRateRatio_Quark_Eta_PT->Draw("colz");
  Canvas_FakeRateRatio_Quark_Eta_PT->Update();
  title->Draw("same");
  Canvas_FakeRateRatio_Quark_Eta_PT->SaveAs("plots_FakesFromJets/FakeRateRatio_Quark_Eta_PT.pdf");








  h_FakeRateRatio_Gluon_NVTX->GetXaxis()->SetTitle("Vertex Multiplicity");
  h_FakeRateRatio_Gluon_NVTX->GetXaxis()->SetTitleSize(0.045);
  h_FakeRateRatio_Gluon_NVTX->GetYaxis()->SetTitle("Ratio");
  h_FakeRateRatio_Gluon_NVTX->GetYaxis()->SetTitleSize(0.045);
  h_FakeRateRatio_Gluon_NVTX->SetTitle("#varepsilon_{j} (TIGHT to FO ratio)");
  h_FakeRateRatio_Gluon_NVTX->GetYaxis()->SetLabelSize(0.025);
  h_FakeRateRatio_Gluon_NVTX->GetXaxis()->SetLabelSize(0.025);
  h_FakeRateRatio_Gluon_NVTX->SetLineColor(kRed);
  h_FakeRateRatio_Gluon_NVTX->GetYaxis()->SetRangeUser(0.,1.);
  h_FakeRateRatio_Gluon_NVTX->SetMarkerStyle(8);
  h_FakeRateRatio_Gluon_NVTX->SetMarkerColor(kRed);


  h_FakeRateRatio_Quark_NVTX->SetLineColor(kBlue);
  h_FakeRateRatio_Quark_NVTX->SetMarkerStyle(8);
  h_FakeRateRatio_Quark_NVTX->SetMarkerColor(kBlue);

  TCanvas *Canvas_FakeRateRatio_NVTX = new TCanvas("Canvas_FakeRateRatio_NVTX","Canvas_FakeRateRatio_NVTX",0,0,600,800);
  Canvas_FakeRateRatio_NVTX->cd();
  h_FakeRateRatio_Gluon_NVTX->Draw();
  h_FakeRateRatio_Quark_NVTX->Draw("same");
  qw2->Draw("same");
  Canvas_FakeRateRatio_NVTX->Update();
  title->Draw("same");
  Canvas_FakeRateRatio_NVTX->SaveAs("plots_FakesFromJets/FakeRateRatio_NVTX.pdf");

 

}
