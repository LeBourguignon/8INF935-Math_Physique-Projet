#ifndef __MODEL_H__
#define __MODEL_H__

#include "particule/Particules.h"
#include "particule/force/RegistreForceParticule.h"
#include "particule/contact/GenerateursContactParticule.h"
#include "particule/contact/GenerateurContactParticuleNaive.h"

// Model physique
class Model
{
private:
	Particules particules;
	RegistreForceParticule registreForceParticule;
	GenerateursContactParticule generateursContact;

	GenerateurContactParticuleNaive* generateurContactParticuleNaive;

public:
	// Initilisation du model
	Model();

	// Liste des particules du model
	Particules getParticules();
	// Ajout d'une particule avec son champs gravitationnel
	void ajouterParticule(Particule* particule, Vecteur3D gravite);
	// Réinitialisation du model (Suppression de toutes les particules, des forces et des générateurs)
	void reinitialisation();

	// Démo 1 - gravitee/collision
	void startDemo1();
	// Démo 2 - ressort
	void startDemo2();
	// Démo 3 - ressort/masse
	void startDemo3();
	// Démo 4 - cable(chaine)
	void startDemo4();
	// Démo 5 - tige(pendule)
	void startDemo5();
	// Démo 6 - cable(chaine2)
	void startDemo6();
	// Démo 7 - frottement
	void startDemo7();
	// Démo 8 - flottabilite
	void startDemo8();

	// Actualisation du model d'un dt
	void actualiser(float duration);
};

#endif