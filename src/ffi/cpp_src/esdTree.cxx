#define esdTree_cxx
// The class definition in esdTree.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


#include "esdTree.h"
#include <TTreeReader.h>
#include "TFile.h"
#include "TTree.h"

esdTree::esdTree(const char* path)
{
  gErrorIgnoreLevel = kFatal;
  fFile = TFile::Open(path);
  if (!fFile) {
    // Loading the first event will return 0 and avoid a crash
    // Sorry about this, future me :P
    // std::cerr << "Could not open " << path << std::endl;
  } else {
    TTree *tree = 0;
    fFile->GetObject("esdTree",tree);
    Init(tree);
  }
}

void esdTree::Init(TTree *tree)
{
  // The Init() function is called when the selector needs to initialize
  // a new tree or chain. Typically here the reader is initialized.
  // It is normally not necessary to make changes to the generated
  // code, but the routine can be extended by the user if needed.
  // Init() will be called many times when running on PROOF
  // (once per file to be processed).

  fReader->SetTree(tree);
}
