//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
/// \file B1/src/RunAction.cc
/// \brief Implementation of the B1::RunAction class

#include "RunAction.hh"
#include "generator.hh"
#include "construction.hh"
#include "EventAction.hh"
// #include "Run.hh"

#include "G4RunManager.hh"
#include "G4Navigator.hh"
#include "G4AnalysisManager.hh"
#include "G4Run.hh"
#include "G4AccumulableManager.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

namespace placeholder
{

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RunAction::RunAction()
{
	
  //G4RunManager::GetRunManager()->SetPrintProgress(1);

  // Create analysis manager
  // The choice of the output format is done via the specified
  // file extension.
    auto analysisManager = G4AnalysisManager::Instance();
    
  // Create directories
  //analysisManager->SetHistoDirectoryName("histograms");
  //analysisManager->SetNtupleDirectoryName("ntuple");
    analysisManager->SetVerboseLevel(0);
    analysisManager->SetNtupleMerging(true);
  
 
    // Note: merging ntuples is available only with Root output
	analysisManager->SetDefaultFileType("root");    
    analysisManager->SetFileName("Outputfile");
    
    analysisManager->CreateNtuple("Neutrons", "Neutron generation location");
    analysisManager->CreateNtupleDColumn("fXlocN");
    analysisManager->CreateNtupleDColumn("fYlocN");
    analysisManager->CreateNtupleDColumn("fZlocN");
    analysisManager->FinishNtuple(0);
    
    analysisManager->CreateNtuple("Detector 0", "Recorded energy spectrum");
    analysisManager->CreateNtupleDColumn("fEdep");
    analysisManager->FinishNtuple(1);
    
    analysisManager->CreateNtuple("Detector 30", "Recorded energy spectrum");
    analysisManager->CreateNtupleDColumn("fEdep");
    analysisManager->FinishNtuple(2);
    
    analysisManager->CreateNtuple("Detector 60", "Recorded energy spectrum");
    analysisManager->CreateNtupleDColumn("fEdep");
    analysisManager->FinishNtuple(3);
    
    analysisManager->CreateNtuple("Detector 90", "Recorded energy spectrum");
    analysisManager->CreateNtupleDColumn("fEdep");
    analysisManager->FinishNtuple(4);
    
    analysisManager->CreateNtuple("Detector 120", "Recorded energy spectrum");
    analysisManager->CreateNtupleDColumn("fEdep");
    analysisManager->FinishNtuple(5);
    
    analysisManager->CreateNtuple("Detector 150", "Recorded energy spectrum");
    analysisManager->CreateNtupleDColumn("fEdep");
    analysisManager->FinishNtuple(6);
    
    analysisManager->CreateNtuple("Detector 180", "Recorded energy spectrum");
    analysisManager->CreateNtupleDColumn("fEdep");
    analysisManager->FinishNtuple(7);
    
    analysisManager->CreateNtuple("Detector 210", "Recorded energy spectrum");
    analysisManager->CreateNtupleDColumn("fEdep");
    analysisManager->FinishNtuple(8);
    
    analysisManager->CreateNtuple("Detector 240", "Recorded energy spectrum");
    analysisManager->CreateNtupleDColumn("fEdep");
    analysisManager->FinishNtuple(9);
    
    analysisManager->CreateNtuple("Detector 270", "Recorded energy spectrum");
    analysisManager->CreateNtupleDColumn("fEdep");
    analysisManager->FinishNtuple(10);
    
    analysisManager->CreateNtuple("Detector 300", "Recorded energy spectrum");
    analysisManager->CreateNtupleDColumn("fEdep");
    analysisManager->FinishNtuple(11);
    
    analysisManager->CreateNtuple("Detector 330", "Recorded energy spectrum");
    analysisManager->CreateNtupleDColumn("fEdep");
    analysisManager->FinishNtuple(12);
    
    /*analysisManager->CreateNtuple("Gammas", "Gamma generation location");
    analysisManager->CreateNtupleDColumn("fXlocG");
    analysisManager->CreateNtupleDColumn("fYlocG");
    analysisManager->CreateNtupleDColumn("fZlocG");
    analysisManager->FinishNtuple(2);*/
    
    //std::vector<G4int>
	
    /*
    //neutron file
    integer - particle id
    string - volume
    string - process
    double - step len
    double - x loc
    double - y loc
    
    
	analysisManager->CreateNtuple("NeutronTracking", "Track Properties");
	analysisManager->CreateNtupleSColumn("pID");
    analysisManager->CreateNtupleSColumn("Volume");
	analysisManager->CreateNtupleSColumn("Process");
    analysisManager->CreateNtupleSColumn("StepLen");
	analysisManager->CreateNtupleSColumn("fXloc");
    analysisManager->CreateNtupleSColumn("fYloc");
    analysisManager->FinishNtuple(0);
   */
        
 	// reg accumulable to the accumulable manager
	G4AccumulableManager* accumulableManager = G4AccumulableManager::Instance();
	accumulableManager->Register(fEdep);
	accumulableManager->Register(fEdep2);
	accumulableManager->Register(fEdep3);
	accumulableManager->Register(fEdep4);
	accumulableManager->Register(fEdep5);
	accumulableManager->Register(fEdep6);
	accumulableManager->Register(fEdep7);
	accumulableManager->Register(fEdep8);
	accumulableManager->Register(fEdep9);
	accumulableManager->Register(fEdep10);
	accumulableManager->Register(fEdep11);
	accumulableManager->Register(fEdep12);
	
	accumulableManager->Register(fDetectorNumber);
	//accumulableManager->RegisterAccumulable(fNEdep);
	accumulableManager->Register(fXlocN);
	accumulableManager->Register(fYlocN);
	accumulableManager->Register(fZlocN);
	/*accumulableManager->Register(fXlocG);
	accumulableManager->Register(fYlocG);
	accumulableManager->Register(fXloc);
	accumulableManager->Register(fYloc);
	accumulableManager->RegisterAccumulable(fStep);
	accumulableManager->Register(fParticle);
	accumulableManager->Register(fProcess);
	accumulableManager->Register(fVolume);
	accumulableManager->Register(fStepLength);*/
}
/*
RunAction::~RunAction()
{
 
}
*/
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::BeginOfRunAction(const G4Run* run)
{


	// Get analysis manager
	auto analysisManager = G4AnalysisManager::Instance();

	// inform the runManager to save random number seed
	G4RunManager::GetRunManager()->SetRandomNumberStore(false);

	// reset accumulables to their initial values
	G4AccumulableManager* accumulableManager = G4AccumulableManager::Instance();
	accumulableManager->Reset();

	analysisManager->OpenFile();

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::EndOfRunAction(const G4Run *run)
{
	
	auto analysisManager = G4AnalysisManager::Instance();
		
	analysisManager->Write();
    analysisManager->CloseFile();
    
   

 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

}

}
