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

	// Ajout d'une particule avec son champs gravitationnel
	void ajouterParticule(Particule* particule, Vecteur3D gravite);
	// Liste des particules du model
	Particules getParticules();

	// Actualisation du model d'un dt
	void actualiser(float duration);
};

#endif