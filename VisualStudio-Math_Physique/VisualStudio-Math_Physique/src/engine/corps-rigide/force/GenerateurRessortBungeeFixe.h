#ifndef __GENERATEUR_RESSORT_BUNGEE_FIXE_H__
#define __GENERATEUR_RESSORT_BUNGEE_FIXE_H__

#include "../CorpsRigide.h"
#include "GenerateurForce.h"

class GenerateurRessortBungeeFixe: public GenerateurForce
{
private:
	Vecteur3D attacheLocale;
	Vecteur3D autreAttache;
	double k;
	double l0;

public:
	GenerateurRessortBungeeFixe(Vecteur3D attacheLocale, Vecteur3D autreAttache, double k, double l0); // autreAttache en coordonnées du monde
	void actualiserForce(CorpsRigide *corps) override;
};

#endif