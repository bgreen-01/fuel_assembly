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
#include <vector>

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
    void AddEdep2(G4float edep2=0.) { fEdep2 += edep2; }
    void AddEdep3(G4float edep3=0.) { fEdep3 += edep3; }
    void AddEdep4(G4float edep4=0.) { fEdep4 += edep4; }
    void AddEdep5(G4float edep5=0.) { fEdep5 += edep5; }
    void AddEdep6(G4float edep6=0.) { fEdep6 += edep6; }
    void AddEdep7(G4float edep7=0.) { fEdep7 += edep7; }
    void AddEdep8(G4float edep8=0.) { fEdep8 += edep8; }
    void AddEdep9(G4float edep9=0.) { fEdep9 += edep9; }
    void AddEdep10(G4float edep10=0.) { fEdep10 += edep10; }
    void AddEdep11(G4float edep11=0.) { fEdep11 += edep11; }
    void AddEdep12(G4float edep12=0.) { fEdep12 += edep12; }
 
    
    void AddNEdep(G4float Nedep=0.) { fNEdep += Nedep; }
    
   
    void AddXlocN(G4float xlocN=0.) { fXlocN += xlocN; }
    void AddYlocN(G4float ylocN=0.) { fYlocN += ylocN; }
    void AddZlocN(G4float zlocN=0.) { fZlocN += zlocN; }
    
    void AddDetector(G4int detectorNo=0) { fDetectorNumber = detectorNo; }
    
    /*void Addenergy(G4float energy=0.) { fEnergy += energy; }
    void GetStep(G4int currentstep=0.) { fStep = currentstep; }
    void GetProcess(G4String Nprocess) { fProcess = Nprocess; }
    void GetVolume(G4String NVolume) { fVolume = NVolume; }
    void GetStepLength(G4float Nstep=0.) { fStepLength += Nstep; }
    void GetParticleID(G4int NpID) { fpID = NpID; }
    void CurrentParticle(std::string NParticle) { fParticle = NParticle; }
    void writeCheck(G4bool check=false) { fCheck = check; }
    void writeCheck2(G4bool check2=false) { fCheck2 = check2; }
    
    void GetProcessList(std::vector<G4String> ProcList) { fProcessList = ProcList; }
    void GetPIDList(std::vector<G4int> PIDList) { fPIDList = PIDList; }
    void GetVolumeList(std::vector<G4String> VolList) { fVolumeList = VolList; }
    void GetStepLenList(std::vector<G4float> LenList) { fStepLengthList = LenList; }
    void GetXlocList(std::vector<G4float> XlocList) {fXlocList = XlocList; }
    void GetYlocList(std::vector<G4float> YlocList) {fYlocList = YlocList; }*/
    
    
    //void passVector(std::vector<std::string> ProcVec) { fProcVec = ProcVec; }
	
  private:
    RunAction* fRunAction = nullptr;
    G4float fEdep = 0.;
    G4float fEdep2 = 0.;
    G4float fEdep3 = 0.;
    G4float fEdep4 = 0.;
    G4float fEdep5 = 0.;
    G4float fEdep6 = 0.;
    G4float fEdep7 = 0.;
    G4float fEdep8 = 0.;
    G4float fEdep9 = 0.;
    G4float fEdep10 = 0.;
    G4float fEdep11 = 0.;
    G4float fEdep12 = 0.;
    
    G4float fNEdep = 0.;
    G4float fEnergy = 0.;
    

    
    G4float fXlocN = 0.;
    G4float fYlocN = 0.;
    G4float fZlocN = 0.;
    
    G4int fDetectorNumber = 0;
    /*
    G4bool fCheck = false;
    G4bool fCheck2 = false;
    
    G4String fParticle;
    G4int fStep = 0;
 	G4float fStepLength = 0.;
 	G4String fVolume;
 	G4String fProcess;
 	G4int fpID = 0;
 	
    std::vector<G4String> fProcessList{};
    std::vector<G4String> ProcList{};
    std::vector<G4String> fVolumeList{};
    std::vector<G4String> VolList{};
    std::vector<G4int> fPIDList{};
    std::vector<G4int> PIDList{};
    std::vector<G4float> fStepLengthList{};
    std::vector<G4float> LenList{};
    std::vector<G4float> fXlocList{};
    std::vector<G4float> XlocList{};
    std::vector<G4float> fYlocList{};
    std::vector<G4float> YlocList{};*/
};

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif


