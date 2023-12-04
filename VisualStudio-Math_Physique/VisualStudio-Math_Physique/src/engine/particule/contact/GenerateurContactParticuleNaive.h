#ifndef __GENERATEUR_CONTACT_PARTICULE_NAIVE_H__
#define __GENERATEUR_CONTACT_PARTICULE_NAIVE_H__

#include "GenerateurContactParticule.h"
#include "../Particules.h"

class GenerateurContactParticuleNaive : public GenerateurContactParticule
{
public:
	double radius;

	Particules particules;

	GenerateurContactParticuleNaive(double radius);
	GenerateurContactParticuleNaive(Particules& particules, double radius);

	void ajouterParticule(Particule* particule);
	void ajouterContact(ContactParticules& contacts, unsigned int limit);
};

#endif