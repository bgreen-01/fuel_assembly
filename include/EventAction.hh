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
/// \file B1/include/EventAction.hh
/// \brief Definition of the B1::EventAction class

#ifndef B1EventAction_h
#define B1EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"

namespace placeholder
{

class RunAction;

/// Event action class

class EventAction : public G4UserEventAction
{
  public:
    EventAction(RunAction* runAction);
    ~EventAction() override = default;

    void BeginOfEventAction(const G4Event* event) override;
    void EndOfEventAction(const G4Event* event) override;

    void AddEdep(G4float edep=0.) { fEdep += edep; }
    void AddNEdep(G4float Nedep=0.) { fNEdep += Nedep; }
    void AddXloc(G4float xloc=0.) { fXloc += xloc; }
    void AddYloc(G4float yloc=0.) { fYloc += yloc; }
    void Addenergy(G4float energy=0.) { fEnergy += energy; }
    void CurrentStep(G4int currentstep=0.) { fStep = currentstep; }
    void CurrentProcess(std::string Nprocess) { fProcess = Nprocess; }
    void CurrentVolume(std::string NVolume) { fVolume = NVolume; }
    void StepLength(G4float Nstep=0.) { fStepLength += Nstep; }

  private:
    RunAction* fRunAction = nullptr;
    G4float fEdep = 0.;
    G4float fNEdep = 0.;
    G4float fEnergy = 0.;
    
    G4float fXloc = 0.;
    G4float fYloc = 0.;
    
    G4int fStep = 0;
 	G4float fStepLength = 0.;
    std::string fProcess;
    std::string fVolume;
    
};

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif


