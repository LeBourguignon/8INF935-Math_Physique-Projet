#ifndef __GENERATEUR_RESSORT_BUNGEE_H__
#define __GENERATEUR_RESSORT_BUNGEE_H__

#include "../CorpsRigide.h"
#include "GenerateurForce.h"

class GenerateurRessortBungee: public GenerateurForce
{
private:
	Vecteur3D attache;
	CorpsRigide *autreCorps = nullptr;
	Vecteur3D autreCorpsAttache;
	double k;
	double l0;

public:
	GenerateurRessortBungee(Vecteur3D attache, CorpsRigide* autreCorps, Vecteur3D autreCorpsAttache, double k, double l0);
	void actualiserForce(CorpsRigide *corps) override;
};

#endif