#ifndef __GENERATEUR_CONTACT_PARTICULE_NAIVE_H__
#define __GENERATEUR_CONTACT_PARTICULE_NAIVE_H__

#include "GenerateurContactParticule.h"
#include "../Particules.h"

class GenerateurContactParticuleNaive : public GenerateurContactParticule
{
public:
	float longueurArete;

	Particules particules;

	GenerateurContactParticuleNaive(float longueurArete);
	GenerateurContactParticuleNaive(Particules& particules, float longueurArete);

	void ajouterParticule(Particule* particule);
	void ajouterContact(ContactParticules& contacts, unsigned int limit);
};

#endif