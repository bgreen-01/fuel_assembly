#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{
	/*fMessenger = new G4GenericMessenger(this, "/detector/", "Detector Construction");
	
	fMessenger->DeclareProperty("xPos", xPosDet, "Adjust x-position of detector. Default 67.045 (cm)");
	fMessenger->DeclareProperty("yPos", yPosDet, "Adjust y-position of detector. Default -10 (cm)");
	fMessenger->DeclareProperty("zPos", zPosDet, "Adjust z-position of detector. Default 30 (cm)");
	
	/*xPosDet = 67.045;
	yPosDet = 7.;
	zPosDet = 30.;*/
	
	DefineMaterials();
	fDetectorMessenger = new DetectorMessenger(this);	
}

MyDetectorConstruction::~MyDetectorConstruction()
{
	delete fDetectorMessenger;
}

void MyDetectorConstruction::DefineMaterials()
{
	G4NistManager *nist = G4NistManager::Instance();
	
	//Build materials
	////germanium
	HPGe = new G4Material("HPGe", 5.32*g/cm3, 1);
	HPGe->AddElement(nist->FindOrBuildElement("Ge"), 1);
	
	
	////water
	H2O = new G4Material("H2O", 2.3*g/cm3, 2);
	H2O->AddElement(nist->FindOrBuildElement("H"), 2);
	H2O->AddElement(nist->FindOrBuildElement("O"), 1);
	
	//alumina for end caps
	Al2O3 = new G4Material("Al2O3", 3.987*g/cm3, 2);
	Al2O3->AddElement(nist->FindOrBuildElement("Al"), 2);
	Al2O3->AddElement(nist->FindOrBuildElement("O"), 3);
	
	//cladding steel
	SS2520 = new G4Material("SS2520", 8*g/cm3, 8);
	SS2520->AddElement(nist->FindOrBuildElement("Fe"), 49.635*perCent);
	SS2520->AddElement(nist->FindOrBuildElement("Cr"), 25.5*perCent);
	SS2520->AddElement(nist->FindOrBuildElement("Ni"), 20.*perCent);
	SS2520->AddElement(nist->FindOrBuildElement("Mo"), .5*perCent);
	SS2520->AddElement(nist->FindOrBuildElement("Cu"), .5*perCent);
	SS2520->AddElement(nist->FindOrBuildElement("Si"), 2.*perCent);
	SS2520->AddElement(nist->FindOrBuildElement("Mn"), 1.75*perCent);
	SS2520->AddElement(nist->FindOrBuildElement("C"), 0.115*perCent);
	
	////slotted can steel
	SS316L = new G4Material("SS316L", 8*g/cm3, 6);
	SS316L->AddElement(nist->FindOrBuildElement("Fe"), 65.245*perCent);
	SS316L->AddElement(nist->FindOrBuildElement("Cr"), 18*perCent);
	SS316L->AddElement(nist->FindOrBuildElement("Ni"), 14*perCent);
	SS316L->AddElement(nist->FindOrBuildElement("Mo"), 2.625*perCent);
	SS316L->AddElement(nist->FindOrBuildElement("N"), 0.1*perCent);
	SS316L->AddElement(nist->FindOrBuildElement("C"), 0.03*perCent);
	
	//spent uo2
	U235 = new G4Isotope("U235", 92, 235);
	U238 = new G4Isotope("U238", 92, 238);
	U236 = new G4Isotope("U236", 92, 236);
	Pu239 = new G4Isotope("Pu239", 94, 239);
	Pu240 = new G4Isotope("Pu240", 94, 240);
	Pu241 = new G4Isotope("Pu241", 94, 241);
	U234 = new G4Isotope("U234", 92, 234);
	Np237 = new G4Isotope("Np237", 93, 237);
	Pu242 = new G4Isotope("Pu242", 94, 242);
	Pu238 = new G4Isotope("Pu238", 94, 238);
	Am241 = new G4Isotope("Am241", 95, 241);
	Np239 = new G4Isotope("Np239", 93, 239);
	Am243 = new G4Isotope("Am243", 95, 243);
	Cm242 = new G4Isotope("Cm242", 96, 242);
	Cm244 = new G4Isotope("Cm244", 96, 244);
	U237 = new G4Isotope("U237", 92, 237);
	
	spentU = new G4Element("spentU", "sU", 5);
	spentU->AddIsotope(U238, 98.0793*perCent);
	spentU->AddIsotope(U235, 1.31456*perCent);
	spentU->AddIsotope(U236, 0.57607*perCent);
	spentU->AddIsotope(U234, 0.02984*perCent);
	spentU->AddIsotope(U237, 0.00022*perCent);
	
	spentPu = new G4Element("spentPu", "sPu", 5);
	spentPu->AddIsotope(Pu239, 50.23386*perCent);
	spentPu->AddIsotope(Pu240, 32.72203*perCent);
	spentPu->AddIsotope(Pu241, 10.0826*perCent);
	spentPu->AddIsotope(Pu242, 3.706*perCent);
	spentPu->AddIsotope(Pu238, 1.2555*perCent);
	
	spentNp = new G4Element("spentNp", "sNp", 2);
	spentNp->AddIsotope(Np237, 89.93439*perCent);
	spentNp->AddIsotope(Np239, 10.06561*perCent);
	
	spentAm = new G4Element("spentAm", "sAm", 2);
	spentAm->AddIsotope(Am241, 57.49067*perCent);
	spentAm->AddIsotope(Am243, 42.50933*perCent);

	spentCm = new G4Element("spentCm", "sCm", 2);
	spentCm->AddIsotope(Cm242, 59.92516*perCent);
	spentCm->AddIsotope(Cm244, 40.07484*perCent);
		
	
	spentFuel = new G4Material("spentFuel", 10*g/cm3, 5);
	spentFuel->AddElement(spentU, 99.39059*perCent);
	spentFuel->AddElement(spentPu, 0.57675*perCent);
	spentFuel->AddElement(spentNp, 0.00579*perCent);
	spentFuel->AddElement(spentAm, 0.02574*perCent);
	spentFuel->AddElement(spentCm, 0.00113*perCent);
	
	///zinc
	zinc = new G4Material("zinc", 7.14*g/cm3, 1);
	zinc->AddElement(nist->FindOrBuildElement("Zn"), 1);
	
	//set world material
	air = new G4Material("air", 0.001293*g/cm3,1);
	air->AddMaterial((nist->FindOrBuildMaterial("G4_AIR")), 1);
	
	fTargetMaterial = spentFuel;
	fAnnulusMaterial = H2O;
	fCladMaterial = air;
	

}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
	G4RotationMatrix *Rotation = new G4RotationMatrix();
	Rotation->rotateX(90*deg);
	Rotation->rotateY(0*deg);
	Rotation->rotateZ(0*deg);
	
	//set world dimensions and properties
	solidWorld =  new G4Box("solidWorld", .25*m, .75*m, .25*m);
	logicWorld = new G4LogicalVolume(solidWorld, air, "logicWorld");
	physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true);
	
	//AGR 'slotted' can - using solid can as will be used experimentally
	//external dimension of can is size of fuel element 
	solidCan = new G4Tubs("solidCan", 95*mm, 97*mm, 500.*mm, 0.*deg, 360.*deg);
	logicCan = new G4LogicalVolume(solidCan, SS316L, "logicCan");
	physCan = new G4PVPlacement(Rotation, G4ThreeVector(0.,0.,0.), logicCan, "physCan", logicWorld, false, 0, true);
	
	//dimensions from end cap deformation paper, AGR description and email with David Hambley
	//pellets - as a solid rod to reduce objects uo2 and analogue(s)
	solidFuel = new G4Tubs("solidFuel", 3.25*mm, 7.25*mm, 480.*mm, 0.*deg, 360.*deg);
	logicFuel = new G4LogicalVolume(solidFuel, spentFuel, "logicFuel");
	
	//clad 25/20 SS
	solidClad = new G4Tubs("solidClad", 7.5*mm, 7.88*mm, 495.*mm, 0.*deg, 360.*deg);
	logicClad = new G4LogicalVolume(solidClad, SS2520, "logicClad");
	
	//endcaps - made of al2o3 alumina
	solidCap = new G4Tubs("solidFuel", 0.*mm, 7.5*mm, 3.8*mm, 0.*deg, 360.*deg);
	logicCap = new G4LogicalVolume(solidCap, Al2O3, "logicCap");
	
	//central annulus water
	solidWaterA = new G4Tubs("solidWaterA", 0*mm, 3.25*mm, 480.*mm, 0.*deg, 360.*deg);
	logicWaterA = new G4LogicalVolume(solidWaterA, fAnnulusMaterial, "logicWaterA");
	
	////set location of flooded pin
	//see below loops for the necessary radius 
	//change j for position around the ring (0-6, 0-12, 0-18) -> with appropriate r value
	G4int j = 0;
	G4double r = 25.0857*mm;
	G4double theta = (j*(360/6))*(M_PI/180); //IMPORTANT -> set 360/6 for inner ring, 
											 //360/12 for mid, 360/18 for outer
	G4double x = sin(theta)*r;
	G4double z = cos(theta)*r;
	physWaterA = new G4PVPlacement(Rotation, G4ThreeVector(x, 0., z), logicWaterA, "physWaterA", logicWorld, false, 0, true);
	
	//clad/fuel gap water
	//solidWaterC = new G4Tubs("solidWaterC", 7.25*mm, 7.5*mm, 480.*mm, 0.*deg, 360.*deg);
	//logicWaterC = new G4LogicalVolume(solidWaterC, fCladMaterial, "logicWaterC");
		
	
	////place fuel + clad in element arrangement
	////add water to inside &/or outside as required - include in loop for all
	for(G4int j=0; j<6; j++)
	{
		G4double r = 25.0857*mm;
		G4double theta = (j*(360/6))*(M_PI/180);
		G4double x = sin(theta)*r;
		G4double z = cos(theta)*r;

		physFuel = new G4PVPlacement(Rotation, G4ThreeVector(x, 0., z), logicFuel, "physFuel", logicWorld, false, 0, true);
		physClad = new G4PVPlacement(Rotation, G4ThreeVector(x, 0., z), logicClad, "physClad", logicWorld, false, 0, true);
		
		physTCap = new G4PVPlacement(Rotation, G4ThreeVector(x, 483.8*mm, z), logicCap, "physTCap", logicWorld, false, 0, true);
		physBCap = new G4PVPlacement(Rotation, G4ThreeVector(x, -483.8*mm, z), logicCap, "physBCap", logicWorld, false, 0, true);
		
		//physWaterA = new G4PVPlacement(Rotation, G4ThreeVector(x, 0., z), logicWaterA, "physWaterA", logicWorld, false, 0, true);
		//physWaterC = new G4PVPlacement(Rotation, G4ThreeVector(x, 0., z), logicWaterC, "physWaterC", logicWorld, false, 0, true);
			
	}
		
	for(G4int j=0; j<12; j++)
	{
		G4double r = 53.0514*mm;
		G4double theta = (j*(360/12))*(M_PI/180);
		G4double x = sin(theta)*r;
		G4double z = cos(theta)*r;

		physFuel = new G4PVPlacement(Rotation, G4ThreeVector(x, 0., z), logicFuel, "physFuel", logicWorld, false, 0, true);
		physClad = new G4PVPlacement(Rotation, G4ThreeVector(x, 0., z), logicClad, "physClad", logicWorld, false, 0, true);
		
		physTCap = new G4PVPlacement(Rotation, G4ThreeVector(x, 483.8*mm, z), logicCap, "physTCap", logicWorld, false, 0, true);
		physBCap = new G4PVPlacement(Rotation, G4ThreeVector(x, -483.8*mm, z), logicCap, "physBCap", logicWorld, false, 0, true);
		
		//physWaterA = new G4PVPlacement(Rotation, G4ThreeVector(x, 0., z), logicWaterA, "physWaterA", logicWorld, false, 0, true);
		//physWaterC = new G4PVPlacement(Rotation, G4ThreeVector(x, 0., z), logicWaterC, "physWaterC", logicWorld, false, 0, true);		
	}
	
	for(G4int j=0; j<18; j++)
	{
		G4double r = 81.0171*mm;
		G4double theta = (j*(360/18))*(M_PI/180);
		G4double x = sin(theta)*r;
		G4double z = cos(theta)*r;

		physFuel = new G4PVPlacement(Rotation, G4ThreeVector(x, 0., z), logicFuel, "physFuel", logicWorld, false, 0, true);
		physClad = new G4PVPlacement(Rotation, G4ThreeVector(x, 0., z), logicClad, "physClad", logicWorld, false, 0, true);
		
		physTCap = new G4PVPlacement(Rotation, G4ThreeVector(x, 483.8*mm, z), logicCap, "physTCap", logicWorld, false, 0, true);
		physBCap = new G4PVPlacement(Rotation, G4ThreeVector(x, -483.8*mm, z), logicCap, "physBCap", logicWorld, false, 0, true);
		
		//physWaterA = new G4PVPlacement(Rotation, G4ThreeVector(x, 0., z), logicWaterA, "physWaterA", logicWorld, false, 0, true);
		//physWaterC = new G4PVPla/ment(Rotation, G4ThreeVector(x, 0., z), logicWaterC, "physWaterC", logicWorld, false, 0, true);
	}
		
	//ring of detectors
	solidDetector = new G4Tubs("solidDetector", 0*mm, 32.2*mm, 31.65*mm, 0.*deg, 360.*deg);
	logicDetector = new G4LogicalVolume(solidDetector, HPGe, "logicDetector");
	

	for(G4int j=0; j<12; j++)
	{
		G4double r = 152*mm;
		G4double theta = (j*(360/12))*(M_PI/180);
		G4int detLoc = (j*(360/12));
		G4double x = sin(theta)*r;
		G4double z = cos(theta)*r;
		
		G4RotationMatrix *Rotation2 = new G4RotationMatrix();
		Rotation2->rotateX(0*deg);
		Rotation2->rotateY((-1)*(theta));
		Rotation2->rotateZ(0*deg);
		
		physDetector = new G4PVPlacement(Rotation2, G4ThreeVector(x, 0., z), logicDetector, "physDetector", logicWorld, false, detLoc, true);
	}
	
	//detector
    /*	
	solidDetector = new G4Tubs("solidDetector", 97*mm, 98*mm, 750*mm, 0.*deg, 360.*deg);
	logicDetector = new G4LogicalVolume(solidDetector, air, "logicDetector");
	physDetector = new G4PVPlacement(Rotation, G4ThreeVector(0., 0., 0.), logicDetector, "physDetector", logicWorld, false, 0, true);
	*/
	fScoringVolume = logicDetector;
		
	G4cout << "\n" << "Target material: " << fTargetMaterial->GetName() << G4endl;
	G4cout << "Annulus material: " << fAnnulusMaterial->GetName() << G4endl;
	G4cout << "Clad-fuel gap material: " << fCladMaterial->GetName() << G4endl;
		
	return physWorld;
		
}

void MyDetectorConstruction::ConstructSDandField()
{
	MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDetector");
	
	logicDetector->SetSensitiveDetector(sensDet);
};

///sets fuel pin material
void MyDetectorConstruction::SetTargetMaterial(const G4String& mat)
{
  G4Material* pmat = G4NistManager::Instance()->FindOrBuildMaterial(mat);
  if(pmat && fTargetMaterial != pmat)
  {
    fTargetMaterial = pmat;
    if(logicFuel)
    {
      logicFuel->SetMaterial(fTargetMaterial);
    }
    
    
    G4RunManager::GetRunManager()->PhysicsHasBeenModified();
    G4RunManager::GetRunManager()->GeometryHasBeenModified();
    
    G4cout << "Target material set to: " << fTargetMaterial->GetName() << G4endl;
  }
}

/// sets annular volumes defined in fuel pins to be water or air
void MyDetectorConstruction::SetAnnulusWater(const G4String& AnnWaterPresent)
{
	G4Material* Amat = G4NistManager::Instance()->FindOrBuildMaterial(AnnWaterPresent);
	G4cout << "Current fAnnulusMaterial: " << fAnnulusMaterial->GetName() << G4endl;

	fAnnulusMaterial = Amat;
	if(logicWaterA)
	{
		logicWaterA->SetMaterial(fAnnulusMaterial);
	}
	G4RunManager::GetRunManager()->PhysicsHasBeenModified();
	G4RunManager::GetRunManager()->GeometryHasBeenModified();
	G4cout << "New Fuel pin annulus material: " << fAnnulusMaterial->GetName() <<  "\n" << G4endl;
  

}

/// sets clad-fuel volumes defined in fuel pins to be water or air
void MyDetectorConstruction::SetCladWater(const G4String& CladWaterPresent)
{
  	G4Material* Cmat = G4NistManager::Instance()->FindOrBuildMaterial(CladWaterPresent);
	G4cout << "Current fCladMaterial: " << fCladMaterial->GetName() << G4endl;
	
	fCladMaterial = Cmat;
	if(logicWaterC)
	{
		logicWaterC->SetMaterial(fCladMaterial);
	}
		
	G4RunManager::GetRunManager()->PhysicsHasBeenModified();
	G4RunManager::GetRunManager()->GeometryHasBeenModified();
	G4cout << "New Fuel pin clad-fuel gap material: " << fCladMaterial->GetName() << "\n" << G4endl;


}

void MyDetectorConstruction::SetTargetCompA(const G4double& CompA)
{
  
  G4double pCompA = CompA;
  if(pCompA && fCompA != pCompA)
  {
    fCompA = pCompA;
    
    G4RunManager::GetRunManager()->PhysicsHasBeenModified();    
    G4RunManager::GetRunManager()->GeometryHasBeenModified();
    
    G4cout << "Material A wtperCent set to " << fCompA << G4endl;
  }
}

void MyDetectorConstruction::SetTargetCompB(const G4double& CompB)
{
  
  G4double pCompB = CompB;
  if(pCompB && fCompB != pCompB)
  {
    fCompB = pCompB;
    
    G4RunManager::GetRunManager()->PhysicsHasBeenModified();    
    G4RunManager::GetRunManager()->GeometryHasBeenModified();
    
    G4cout << "Boron wtperCent set to " << fCompB << G4endl;
  }
}

void MyDetectorConstruction::SetTargetDensity(const G4double& targetDensity)
{
  
    fTargetDensity = targetDensity;
    
    G4RunManager::GetRunManager()->PhysicsHasBeenModified();    
    G4RunManager::GetRunManager()->GeometryHasBeenModified();
    
    G4cout << "Density set to " << fTargetDensity << " g/cm3" << G4endl;
  
}

void MyDetectorConstruction::SetTargetThickness(const G4double& targetThickness)
{
  
  G4double pTargetThickness = targetThickness;
  if(pTargetThickness && fTargetThickness != pTargetThickness)
  {
    fTargetThickness = pTargetThickness;
    
    G4RunManager::GetRunManager()->PhysicsHasBeenModified();    
    G4RunManager::GetRunManager()->GeometryHasBeenModified();
    //G4RunManager::GetRunManager()->ReinitializeGeometry();
    double actualThickness = fTargetThickness*2;
    
    G4cout << "Target thickness set to " << actualThickness << " mm" <<G4endl;
  }
}

