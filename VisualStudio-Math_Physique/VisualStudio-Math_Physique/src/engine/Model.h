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
	// R�initialisation du model (Suppression de toutes les particules, des forces et des g�n�rateurs)
	void reinitialisation();

	// D�mo 1
	void startDemo1();
	// D�mo 2
	void startDemo2();
	// D�mo 3
	void startDemo3();
	// D�mo 4
	void startDemo4();
	// D�mo 5
	void startDemo5();
	// D�mo 6
	void startDemo6();

	// Actualisation du model d'un dt
	void actualiser(float duration);
};

#endif