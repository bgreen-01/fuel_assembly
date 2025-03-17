#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "DetectorMessenger.hh"

#include "G4VUserDetectorConstruction.hh"
#include "G4NistManager.hh"
#include "G4Material.hh"
#include "G4Isotope.hh"
#include "G4VSolid.hh"
#include "G4SubtractionSolid.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4LogicalVolume.hh"
#include "G4RotationMatrix.hh"
#include "G4Transform3D.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4SystemOfUnits.hh"
#include "G4GenericMessenger.hh"

#include "math.h"

#include "detector.hh"

class MyDetectorConstruction : public G4VUserDetectorConstruction
{
public:
	MyDetectorConstruction();
	~MyDetectorConstruction();
	
	G4LogicalVolume *GetScoringVolume() const { return fScoringVolume; }
	
	virtual G4VPhysicalVolume *Construct();
	
	void SetTargetMaterial(const G4String&);
    G4Material* GetTargetMaterial() const { return fTargetMaterial; }
    
    void SetAnnulusWater(const G4String&);
    G4Material* GetAnnulusWater() const { return fAnnulusMaterial; }
    
    void SetCladWater(const G4String&);
    G4Material* GetCladWater() const { return fCladMaterial; }
    
    void SetTargetCompA(const G4double&);
    G4double GetTargetCompA() const { return fCompA; }
    
    void SetTargetCompB(const G4double&);
    G4double GetTargetCompB() const { return fCompB; }
    
    void SetTargetDensity(const G4double&);
    G4double GetTargetDensity() const { return fTargetDensity; }
    
    void SetTargetThickness(const G4double&);
    G4double GetTargetThickness() const { return fTargetThickness; }
	
private:
	
	virtual void ConstructSDandField();
	
	G4GenericMessenger *fMessenger;
	DetectorMessenger* fDetectorMessenger = nullptr;
	
	G4Material* fTargetMaterial = nullptr;
	G4Material* fAnnulusMaterial = nullptr;
	G4Material* fCladMaterial = nullptr;
	G4double fCompA = 1.;
	G4double fCompB = 0.;
	G4double fTargetDensity = 10.;
	G4double fTargetThickness = 5.;
	
	G4LogicalVolume *fScoringVolume, *logicWorld, *logicFuel, *logicDetector, *logicClad, *logicCap, *logicWaterC, *logicWaterA;
	G4VSolid *solidWorld, *solidFuel, *solidDetector, *solidClad, *solidCap, *solidWaterC, *solidWaterA;
	G4VPhysicalVolume *physWorld, *physDetector, *physFuel, *physClad, *physTCap, *physBCap, *physWaterA, *physWaterC;
	
	G4Isotope *U235, *U238, *U236, *Pu239, *Pu240, *Pu241, *U234, *Np237, *Pu242, *Pu238, *Am241, *Np239, *Am243, *Cm242, *Cm244, *U237;
	G4Element *enrichedU, *spentU, *spentPu, *spentNp, *spentAm, *spentCm;
	
	G4Material *H2O, *air, *Al2O3, *SS2520, *spentFuel, *zinc;
	
	void DefineMaterials();
};
#endif
