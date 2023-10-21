#include "Model.h"

#include "GraviteParticule.h"

Model::Model()
{
}


void Model::ajouterParticule(Particule* particule, Vecteur3D gravite = Vecteur3D())
{
	this->particules.push_back(particule);
	this->registreForceParticule.ajouterForceParticule(particule, new GraviteParticule(gravite));
}

Particules Model::getParticules()
{
	return particules;
}


void Model::actualiser(float duration)
{
	// Mise à jour des forces sur les particules
	this->registreForceParticule.actualiserForce(duration);

	// Mise à jour des particules
	for (auto particule : this->particules)
	{
		particule->actualiser(duration);
	}

	// Génerer les contacts
	// Résoudre les contacts
}