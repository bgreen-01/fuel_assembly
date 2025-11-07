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
/// \file B1/src/EventAction.cc
/// \brief Implementation of the B1::EventAction class

#include "EventAction.hh"
#include "action.hh"
#include "construction.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4AnalysisManager.hh"

#include "G4SystemOfUnits.hh"
#include "G4ParticleTypes.hh"
#include "G4StepPoint.hh"
#include "G4TrackStatus.hh"
#include "G4Track.hh"

namespace placeholder
{

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EventAction::EventAction(RunAction *runAction) : fRunAction(runAction)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::BeginOfEventAction(const G4Event* anEvent)
{
  /*G4float fEdep = 0.;
  G4float fNEdep = 0.;
  G4float fXloc = 0.;
  G4float fYloc = 0.;*/
  
    
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::EndOfEventAction(const G4Event* anEvent)
{
	// get analysis manager
    auto analysisManager = G4AnalysisManager::Instance();
    
    
    //neutron generation location tuple
   	if (fXlocN != 0 || fYlocN != 0)
   	{
		analysisManager->FillNtupleDColumn(0, 0, fXlocN);
		analysisManager->FillNtupleDColumn(0, 1, fYlocN);
  		analysisManager->FillNtupleDColumn(0, 2, fZlocN);
  		analysisManager->AddNtupleRow(0);	
	}
	
	//G4cout << "Detector number: " << fDetectorNumber << G4endl;
	
	//gamma detection location 
	if (fEdep > 0)
	{
		//G4cout << "Hit in detector 0" << G4endl;
  		analysisManager->FillNtupleDColumn(1, 0, fEdep);
  		analysisManager->AddNtupleRow(1);
	}
	
	if (fEdep2 > 0)
	{
		//G4cout << "Hit in detector 30" << G4endl;
  		analysisManager->FillNtupleDColumn(2, 0, fEdep2);
  		analysisManager->AddNtupleRow(2);
	}
	
	if (fEdep3 > 0)
	{
		//G4cout << "Hit in detector 60" << G4endl;
  		analysisManager->FillNtupleDColumn(3, 0, fEdep3);
  		analysisManager->AddNtupleRow(3);
	}
	
	if (fEdep4 > 0)
	{
		//G4cout << "Hit in detector 90" << G4endl;
  		analysisManager->FillNtupleDColumn(4, 0, fEdep4);
  		analysisManager->AddNtupleRow(4);
	}
	
	if (fEdep5 > 0)
	{
		//G4cout << "Hit in detector 120" << G4endl;
  		analysisManager->FillNtupleDColumn(5, 0, fEdep5);
  		analysisManager->AddNtupleRow(5);
	}
	
	if (fEdep6 > 0)
	{
		//G4cout << "Hit in detector 150" << G4endl;
  		analysisManager->FillNtupleDColumn(6, 0, fEdep6);
  		analysisManager->AddNtupleRow(6);
	}
	
	if (fEdep7 > 0)
	{
		//G4cout << "Hit in detector 180" << G4endl;
  		analysisManager->FillNtupleDColumn(7, 0, fEdep7);
  		analysisManager->AddNtupleRow(7);
	}
	
	if (fEdep8 > 0)
	{
		//G4cout << "Hit in detector 210" << G4endl;
  		analysisManager->FillNtupleDColumn(8, 0, fEdep8);
  		analysisManager->AddNtupleRow(8);
	}
	
	if (fEdep9 > 0)
	{
		//G4cout << "Hit in detector 240" << G4endl;
  		analysisManager->FillNtupleDColumn(9, 0, fEdep9);
  		analysisManager->AddNtupleRow(9);
	}
	
	if (fEdep10 > 0)
	{
		//G4cout << "Hit in detector 270" << G4endl;
  		analysisManager->FillNtupleDColumn(10, 0, fEdep10);
  		analysisManager->AddNtupleRow(10);
	}
	
	if (fEdep11 > 0)
	{
		//G4cout << "Hit in detector 300" << G4endl;
  		analysisManager->FillNtupleDColumn(11, 0, fEdep11);
  		analysisManager->AddNtupleRow(11);
	}
	
	if (fEdep12 > 0)
	{
		//G4cout << "Hit in detector 330" << G4endl;
  		analysisManager->FillNtupleDColumn(12, 0, fEdep12);
  		analysisManager->AddNtupleRow(12);
	}
	
	/*
	
	
}	
	if (fCheck == true)
	{
		G4cout << "Writing neutron data" << G4endl;
		
		
		G4String concfpID = "";
		for (int strA : fPIDList) 
		{
			concfpID += std::to_string(strA) + ",";  			
		}
		
		
		G4String concfVol = "";
		for (const auto& strB : fVolumeList) 
		{
			concfVol += strB + ",";  
		}
		
		G4String concProc = "";
		for (const auto& strC : fProcessList) 
		{
			concProc += strC + ",";  
		}
		
		G4String concStepLen = "";
		for (const auto& strD : fStepLengthList) 
		{
			concStepLen += std::to_string(strD) + ",";  
		}
		
		G4String concXloc = "";
		for (const auto& strE : fXlocList) 
		{
			concXloc += std::to_string(strE) + ",";  
		}
		
		G4String concYloc = "";
		for (const auto& strF : fYlocList) 
		{
			concYloc += std::to_string(strF) + ",";  
		}
		
		analysisManager->FillNtupleSColumn(3, 0, concfpID);
		analysisManager->FillNtupleSColumn(3, 1, concfVol);
		analysisManager->FillNtupleSColumn(3, 2, concProc);
		analysisManager->FillNtupleSColumn(3, 3, concStepLen);
		analysisManager->FillNtupleSColumn(3, 4, concXloc);
		analysisManager->FillNtupleSColumn(3, 5, concYloc);
		analysisManager->AddNtupleRow(3);
		//fRunAction->passVector(fProcessList);
	}
	*/
    fEdep = 0.;
    fEdep2 = 0.;
    fEdep3 = 0.;
    fEdep4 = 0.;
    fEdep5 = 0.;
    fEdep6 = 0.;
    fEdep7 = 0.;
    fEdep8 = 0.;
    fEdep9 = 0.;
    fEdep10 = 0.;
    fEdep11 = 0.;
    fEdep12 = 0.;

    
    fDetectorNumber = 0;
    /*fNEdep = 0.;
    fXloc = 0.;
    fYloc = 0.;
    fEnergy = 0.;
    fStepLength = 0.;
    fCheck = false;
    
    fPIDList.clear();
    fVolumeList.clear();
    fProcessList.clear();
    fStepLengthList.clear();
    fXlocList.clear();
    fYlocList.clear();*/
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

}
