#ifndef __GENERATEUR_RESSORT_FIXE_H__
#define __GENERATEUR_RESSORT_FIXE_H__

#include "../CorpsRigide.h"
#include "GenerateurForce.h"

class GenerateurRessortFixe: public GenerateurForce
{
private:
	Vecteur3D attacheLocale;
	Vecteur3D autreAttache;
	double k;
	double l0;

public:
	GenerateurRessortFixe(Vecteur3D attacheLocale, Vecteur3D autreAttache, double k, double l0); // autreAttache en coordonnées du monde
	void actualiserForce(CorpsRigide *corps) override;
};

#endif