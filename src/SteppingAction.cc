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
/// \file B1/src/SteppingAction.cc
/// \brief Implementation of the B1::SteppingAction class

#include "SteppingAction.hh"
#include "EventAction.hh"
#include "construction.hh"

#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"
#include "G4Types.hh"

#include "G4Track.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"
#include "G4StepPoint.hh"
#include "G4TrackStatus.hh"
#include "G4ParticleTypes.hh"

namespace placeholder
{

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::SteppingAction(EventAction* eventAction) : fEventAction(eventAction)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void SteppingAction::UserSteppingAction(const G4Step *step)
{
  	
  	G4Track *track=step->GetTrack();
         
    std::string ParticleName = track->GetDynamicParticle()->GetParticleDefinition()->GetParticleName();
    //fEventAction->CurrentParticle(ParticleName);
    
    const G4VTouchable *touchable = step->GetPreStepPoint()->GetTouchable();
    	
	if (!fScoringVolume) 
	{
    	const auto detConstruction = static_cast<const MyDetectorConstruction*>(
    	G4RunManager::GetRunManager()->GetUserDetectorConstruction());
    	fScoringVolume = detConstruction->GetScoringVolume();
    }
	
	//get volume of the current step
	
	//G4String volumeName = volume->GetName();
	
	G4ThreeVector *loc = new G4ThreeVector();
	
	G4int stepNumber = track->GetCurrentStepNumber();
	
	G4StepPoint* preStepPoint = step->GetPreStepPoint();
	
	//G4float energy = track->GetKineticEnergy()/eV;
	
	if (ParticleName == "neutron" && stepNumber == 1)
	{
		
		*loc = preStepPoint->GetPosition();
		G4float xlocn = loc->getX()/mm;
		G4float ylocn = loc->getY()/mm;
		G4float zlocn = loc->getZ()/mm;
						
		fEventAction->AddXlocN(xlocn);
		fEventAction->AddYlocN(ylocn);	
		fEventAction->AddZlocN(zlocn);	
		
	}
	
	if (ParticleName == "gamma")
	{
		//G4float energy = track->GetKineticEnergy()/eV;
		//G4int energyMod = round(energy/1000);
		
		*loc = preStepPoint->GetPosition();
		G4float xlocg = loc->getX()/mm;
		G4float ylocg = loc->getY()/mm;
		G4float zlocg = loc->getZ()/mm;
		
		G4LogicalVolume* volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();
		G4int copyNumber = touchable->GetCopyNumber();
			
		/*
		if (stepNumber == 1)
		{
			fEventAction->(xlocg);
			fEventAction->AddYlocG(ylocg);
			fEventAction->AddZlocG(xlocg);
			fEventAction->AddEdep(energy);
		}*/
		
		if (volume == fScoringVolume)
		{
			
			G4double preStepTE = step->GetPreStepPoint()->GetTotalEnergy()/keV;
			G4double postStepTE = step->GetPostStepPoint()->GetTotalEnergy()/keV;

			G4double deltaTE = preStepTE - postStepTE;
			
			G4double depositedEnergy = step->GetTotalEnergyDeposit()/MeV;
			
			//G4cout << "Detector number (angle pos): " << copyNumber << G4endl;
			//G4cout << "Change in TE: " << deltaTE << G4endl;
			
			fEventAction->AddDetector(copyNumber);
			fEventAction->AddEdep(depositedEnergy);
			//track->SetTrackStatus(fStopAndKill); 
		}
		
	}
	
	/*
	
	G4String currentProc = step->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName();
	
	if (ParticleName == "gamma" && currentProc == "initStep"){
	
		G4float energy = track->GetKineticEnergy()/eV;
		G4int energyMod = round(energy/1000);
		if (energyMod == 2223)
		{
			G4bool fCheck2 = true;
			
			fEventAction->writeCheck2(fCheck2);
			*loc = track->GetPosition();
			G4float xloc = loc->getX();
			G4float yloc = loc->getY();
			
			fEventAction->Addenergy(energy);
			fEventAction->AddXloc(xloc);
			fEventAction->AddYloc(yloc);
	
	
		}
	}
	//process, volume, steplength
	
	
	if (ParticleName == "neutron")
	{
		G4bool check = true;		
		
		G4String currentProc = step->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName();
		G4double currentStepL = track->GetStepLength();
		G4int stepNumber = track->GetCurrentStepNumber();
		
		G4int particleID = track->GetTrackID();
		*loc = track->GetPosition();
		G4float xloc = loc->getX();
		G4float yloc = loc->getY();
		
		procList.push_back(currentProc);
		pidList.push_back(particleID);
		volList.push_back(volumeName);
		stepLenList.push_back(currentStepL);
		xlocList.push_back(xloc);
		ylocList.push_back(yloc);
		
			
		
		G4cout << "\nNeutron Step Report:" << G4endl;
		G4cout << "Particle ID: " << particleID << G4endl;	
		G4cout << "Volume: " << volumeName << G4endl;
		G4cout << "Process: " << currentProc << G4endl;
		G4cout << "Step length: " << currentStepL << G4endl;
		
		
		fEventAction->writeCheck(check);
		fEventAction->GetPID(pidList);
		fEventAction->GetProcess(currentProc);
		fEventAction->GetVolume(volumeName);
		fEventAction->GetStepLength(currentStepL);
		fEventAction->GetParticleID(particleID);
		fEventAction->AddXloc(xloc);
		fEventAction->AddYloc(yloc);
		
		fEventAction->GetProcessList(procList);
		fEventAction->GetPIDList(pidList);
		fEventAction->GetVolumeList(volList);
		fEventAction->GetStepLenList(stepLenList);
		fEventAction->GetXlocList(xlocList);
		fEventAction->GetYlocList(ylocList);
		
	}*/
	
	delete loc;
	
	//if (volume != fScoringVolume) return;
	//else return;
	
}
	

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

}
