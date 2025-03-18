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

class G4Run;

namespace placeholder
{

/// Run action class
///
/// In EndOfRunAction(), it calculates the dose in the selected volume
/// from the energy deposit accumulated via stepping and event actions.
/// The computed dose is then printed on the screen.

class RunAction : public G4UserRunAction
{
  public:
    RunAction();
    ~RunAction();

    void BeginOfRunAction(const G4Run*) override;
    void   EndOfRunAction(const G4Run*) override;

    void AddEdep (G4float edep=0.);
    void AddNEdep (G4float Nedep=0.);
    
    void AddXlocN (G4float xlocN=0.);
    void AddYlocN (G4float ylocN=0.);
    void AddXlocG (G4float xlocG=0.);
    void AddYlocG (G4float ylocG=0.);
    void AddXloc (G4float xloc=0.);
    void AddYloc (G4float yloc=0.);
    
    void StepNumber (G4int stepNumber=0);
    void Particle (G4String particle);
    void Process (G4String process);
    void Volume (G4String volume);
    void AddStepLength (G4float stepLength = 0.);
    
	
	
  private:
    G4Accumulable<G4float> fEdep = 0.;
    G4Accumulable<G4float> fNEdep = 0.;
    
    G4Accumulable<G4float> fXlocN = 0.;
    G4Accumulable<G4float> fYlocN = 0.;
    G4Accumulable<G4float> fXlocG = 0.;
    G4Accumulable<G4float> fYlocG = 0.;
    G4Accumulable<G4float> fXloc = 0.;
    G4Accumulable<G4float> fYloc = 0.;
    
    G4Accumulable<G4int> fStep = 0.;
    G4Accumulable<G4String> fParticle;
    G4Accumulable<G4String> fProcess;
    G4Accumulable<G4String> fVolume;
    G4Accumulable<G4float> fStepLength = 0.;
    
};

}

#endif

