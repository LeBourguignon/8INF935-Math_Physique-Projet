#ifndef __GENERATEUR_FLOTTABILITE_H__
#define __GENERATEUR_FLOTTABILITE_H__

#include "../CorpsRigide.h"
#include "GenerateurForce.h"


class GenerateurFlottabilite : public GenerateurForce
{
private:
	double hauteurObjet;
	double volumeObjet;
	double niveauLiquide;
	double densiteLiquide;

public:
	GenerateurFlottabilite(double hauteurObjet, double volumeObjet, double niveauLiquide, double densiteLiquide);
	void actualiserForce(CorpsRigide* corps) override;
	

};
#endif
