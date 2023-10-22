#include "TigeParticule.h"

TigeParticule::TigeParticule(Particule* particules[2], float longueur)
	: longueur(longueur)
{
	this->particules[0] = particules[0];
	this->particules[1] = particules[1];
}

void TigeParticule::ajouterContact(ContactParticules& contacts, unsigned int limit)
{
	if (contacts.size() < limit)
	{
		contacts.push_back(new ContactParticule(particules, 1, longueurActuelle(), (particules[0]->position - particules[1]->position).direction()));
	}
}
