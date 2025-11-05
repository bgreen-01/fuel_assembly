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
/// \file B1/include/RunAction.hh
/// \brief Definition of the B1::RunAction class

#ifndef RunAction_h
#define RunAction_h 1

#include "G4UserRunAction.hh"
#include "G4Run.hh"
#include "G4Accumulable.hh"
#include "globals.hh"
#include <vector>

class G4Run;

namespace placeholder
{

//class EventAction;

/// Run action class
///
/// In EndOfRunAction(), it calculates the dose in the selected volume
/// from the energy deposit accumulated via stepping and event actions.
/// The computed dose is then printed on the screen.

class RunAction : public G4UserRunAction
{
  public:
    RunAction();
    ~RunAction() override = default;

    void BeginOfRunAction(const G4Run*) override;
    void   EndOfRunAction(const G4Run*) override;

    void AddEdep (G4float edep=0.);
    void AddNEdep (G4float Nedep=0.);
    
    void AddXlocN (G4float xlocN=0.);
    void AddYlocN (G4float ylocN=0.);
    void AddZlocN (G4float zlocN=0.);
    
    void AddXlocG (G4float xlocG=0.);
    void AddYlocG (G4float ylocG=0.);
    void AddZlocG (G4float zlocG=0.);
    
    void AddXloc (G4float xloc=0.);
    void AddYloc (G4float yloc=0.);
    void AddZloc (G4float zloc=0.);
    
    void detectorNumber (G4int detectorNumber=0);
    
    void StepNumber (G4int stepNumber=0);
    /*void Particle (std::string particle);
    void Process (std::string process);
    void Volume (std::string volume);*/
    void AddStepLength (G4float stepLength = 0.);
    
    //void passVector(std::vector<std::string> ProcVec) { fProcVec = ProcVec; }
	
	
  private: 	
  	//std::vector<std::string> fProcVec{};
  	
    G4Accumulable<G4float> fEdep = 0.;
    //G4Accumulable<G4float> fNEdep = 0.;
    
    G4Accumulable<G4float> fXlocN = 0.;
    G4Accumulable<G4float> fYlocN = 0.;
    G4Accumulable<G4float> fZlocN = 0.;
    
    G4Accumulable<G4float> fXlocG = 0.;
    G4Accumulable<G4float> fYlocG = 0.;
    G4Accumulable<G4float> fZlocG = 0.;
    
    G4Accumulable<G4float> fXloc = 0.;
    G4Accumulable<G4float> fYloc = 0.;
    G4Accumulable<G4float> fZloc = 0.;
    
    //G4Accumulable<G4int> fStep = 0.;
    //G4Accumulable<std::string> fParticle;
    //G4Accumulable<std::string> fProcess;
    //G4Accumulable<std::string> fVolume;
    //G4Accumulable<G4float> fStepLength = 0.;
    
};

}

#endif

