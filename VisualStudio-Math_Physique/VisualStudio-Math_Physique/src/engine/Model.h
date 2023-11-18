#ifndef __MODEL_H__
#define __MODEL_H__

#include "particule/Particules.h"
#include "particule/force/RegistreForceParticule.h"
#include "particule/contact/GenerateursContactParticule.h"
#include "particule/contact/GenerateurContactParticuleNaive.h"

#include "corps-rigide/CorpsRigide.h"
#include "corps-rigide/force/RegistreForce.h"

#include "corps-rigide/cuboide/Cuboides.h"

// Model physique
class Model
{
private:
	// Particule
	Particules particules;
	RegistreForceParticule registreForceParticule;
	GenerateursContactParticule generateursContact;

	GenerateurContactParticuleNaive* generateurContactParticuleNaive;

	// Corps Rigide
	Cuboides cuboides;
	RegistreForce registreForce;

public:
	// Initilisation du model
	Model();

	// Liste des particules du model
	Particules getParticules();
	// Ajout d'une particule avec son champs gravitationnel
	void ajouterParticule(Particule* particule, Vecteur3D gravite);

	// Liste des cuboides du model
	Cuboides getCuboides();
	// Ajout d'une cuboide
	void ajouterCuboide(Cuboide* cuboide, Vecteur3D gravite);

	// Réinitialisation du model
	void reinitialisation();

	// Démo Particule 1 - gravitee/collision
	void startDemoParticule1();
	// Démo Particule 2 - ressort
	void startDemoParticule2();
	// Démo Particule 3 - ressort/masse
	void startDemoParticule3();
	// Démo Particule 4 - cable(chaine)
	void startDemoParticule4();
	// Démo Particule 5 - tige(pendule)
	void startDemoParticule5();
	// Démo Particule 6 - cable(chaine2)
	void startDemoParticule6();
	// Démo Particule 7 - frottement
	void startDemoParticule7();
	// Démo Particule 8 - flottabilite
	void startDemoParticule8();

	// Actualisation du model d'un dt
	void actualiser(float duration);
};

#endif