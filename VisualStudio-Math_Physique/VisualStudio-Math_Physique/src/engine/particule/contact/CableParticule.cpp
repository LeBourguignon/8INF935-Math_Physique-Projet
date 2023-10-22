#include "CableParticule.h"

CableParticule::CableParticule(Particule* particules[2], float longueurMax, float restitution)
	: longueurMax(longueurMax), restitution(restitution)
{
	this->particules[0] = particules[0];
	this->particules[1] = particules[1];
}

void CableParticule::ajouterContact(ContactParticules& contacts, unsigned int limit)
{
	if (contacts.size() < limit && longueurActuelle() > longueurMax)
	{
		contacts.push_back(new ContactParticule(particules, restitution, longueurActuelle() - longueurMax, (particules[0]->position - particules[1]->position).direction()));
	}
}
