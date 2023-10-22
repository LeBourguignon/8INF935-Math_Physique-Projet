#include "TigeParticule.h"

TigeParticule::TigeParticule(Particule* particules[2], float longueur)
	: longueur(longueur)
{
	this->particules[0] = particules[0];
	this->particules[1] = particules[1];
}

void TigeParticule::ajouterContact(ContactParticules& contacts, unsigned int limit)
{
	if (contacts.size() < limit && longueurActuelle() > longueur)
	{
		contacts.push_back(new ContactParticule(particules, 1, longueurActuelle() - longueur, (particules[0]->position - particules[1]->position).direction()));
	}
}
