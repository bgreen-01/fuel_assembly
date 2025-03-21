#include "generator.hh"

MyPrimaryGenerator::MyPrimaryGenerator()
{
	fParticleGun = new G4GeneralParticleSource();
	//fParticleGun = new G4ParticleGun();
	/*
	G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
	G4ParticleDefinition *particle = particleTable->FindParticle("geantino");
	
	G4ThreeVector pos(0.,0.,0.);
	G4ThreeVector mom(0.,0.,1.);
	
	fParticleGun->SetParticlePosition(pos);
	fParticleGun->GetParticleMomentumDirection(mom);
	fParticleGun->SetParticleMomentum(0.*keV);
	fParticleGun->SetParticleDefinition(particle); */
}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
	delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
	/*G4ParticleDefinition *particle = fParticleGun->GetParticleDefinition();
	
	if(particle == G4Geantino::Geantino())
	{
		G4int Z = 98;
		G4int A = 252;
		
		G4double charge = 0.*eplus;
		G4double energy = 0.*keV;
		
		G4ParticleDefinition *ion = G4IonTable::GetIonTable()->GetIon(Z, A, energy);
		
		fParticleGun->SetParticleDefinition(ion);
		fParticleGun->SetParticleCharge(charge);
	}
	*/
	fParticleGun->GeneratePrimaryVertex(anEvent); 
	
	
	
}

