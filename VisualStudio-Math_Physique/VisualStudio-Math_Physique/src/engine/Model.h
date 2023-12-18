#ifndef __MODEL_H__
#define __MODEL_H__

#include "particule/Particules.h"
#include "particule/force/RegistreForceParticule.h"
#include "particule/contact/GenerateursContactParticule.h"
#include "particule/contact/GenerateurContactParticuleNaive.h"

#include "corps-rigide/CorpsRigides.h"
#include "corps-rigide/force/RegistreForce.h"

#include "corps-rigide/contact/BoundingVolumeSphere.h"
#include "corps-rigide/contact/GenerateursContact.h"

// Model physique
class Model
{
private:
	// Particule
	Particules particules;
	RegistreForceParticule registreForceParticule;
	GenerateursContactParticule generateursContactParticule;

	GenerateurContactParticuleNaive* generateurContactParticuleNaive;

	// Corps Rigide
	CorpsRigides corpsRigides;
	RegistreForce registreForce;
	// TODO Octree
	// TODO constGenerateursContact

public:
	// Initilisation du model
	Model();

	// Réinitialisation du model
	void reinitialisation();

	// Liste des particules du model
	Particules getParticules();
	// Ajout d'une particule avec son champs gravitationnel
	void ajouterParticule(Particule* particule, Vecteur3D gravite);

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

	// Liste des CorpsRigides du model
	CorpsRigides getCorpsRigides();
	// Ajout d'une cuboide
	void ajouterCuboide(Cuboide* cuboide, Vecteur3D gravite = Vecteur3D());

	// Démo Cuboide 1
	void startDemoCuboide1();


	// Actualisation du model d'un dt
	void actualiser(float duration);
};

#endif