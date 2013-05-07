void ReduceTree(TTree *root)
{
	root->SetBranchStatus("*"        ,0);

	root->SetBranchStatus("EvtInfo.RunNo"        ,1);
	root->SetBranchStatus("EvtInfo.EvtNo"        ,1);
	root->SetBranchStatus("EvtInfo.LumiNo"        ,1);
	root->SetBranchStatus("EvtInfo.PDFid1"       ,1);
	root->SetBranchStatus("EvtInfo.PDFid2"       ,1);
	root->SetBranchStatus("EvtInfo.PDFx1"        ,1);
	root->SetBranchStatus("EvtInfo.PDFx2"        ,1);
	root->SetBranchStatus("EvtInfo.PDFscale"     ,1);
	root->SetBranchStatus("EvtInfo.PDFv1"        ,1);
	root->SetBranchStatus("EvtInfo.PDFv2"        ,1);
	root->SetBranchStatus("EvtInfo.PFMET"          ,1);
	root->SetBranchStatus("EvtInfo.PFMETPhi"       ,1);
	root->SetBranchStatus("EvtInfo.TrgBook"      ,1);
	root->SetBranchStatus("EvtInfo.RhoPU"      ,1);
	root->SetBranchStatus("EvtInfo.nBX"      ,1);
	root->SetBranchStatus("EvtInfo.nPU"      ,1);
	root->SetBranchStatus("EvtInfo.BXPU"      ,1);
	root->SetBranchStatus("EvtInfo.TrueIT"      ,1);
	root->SetBranchStatus("GenInfo.*"			   ,1);
	root->SetBranchStatus("PhotonInfo*"			   ,1);
	root->SetBranchStatus("PFLepInfo.*"			   ,1);
	root->SetBranchStatus("PFJetInfo.*"			 ,1);
	root->SetBranchStatus("VertexInfo.Size"        ,1);
	root->SetBranchStatus("VertexInfo.isValid"     ,1);
	root->SetBranchStatus("VertexInfo.Type"     ,1);
	root->SetBranchStatus("VertexInfo.Ndof"        ,1);
	root->SetBranchStatus("VertexInfo.z"        ,1);
	root->SetBranchStatus("VertexInfo.Rho"        ,1);
	root->SetBranchStatus("VertexInfo.Pt_Sum"        ,1);


}
