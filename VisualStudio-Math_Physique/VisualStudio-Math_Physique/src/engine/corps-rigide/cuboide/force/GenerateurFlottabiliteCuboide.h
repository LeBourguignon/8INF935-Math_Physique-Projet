#ifndef __GENERATEUR_FLOTTABILITE_CUBOIDE_H__
#define __GENERATEUR_FLOTTABILITE_CUBOIDE_H__

#include "../../CorpsRigide.h"
#include "../../force/GenerateurForce.h"

class GenerateurFlottabiliteCuboide : public GenerateurForce
{
private:
	Vecteur3D dimensionCuboide;
	double niveauLiquide;
	double densiteLiquide;

public:
	GenerateurFlottabiliteCuboide(Vecteur3D dimensionCuboide, double niveauLiquide, double densiteLiquide);
	void actualiserForce(CorpsRigide* corps) override;
};

#endif