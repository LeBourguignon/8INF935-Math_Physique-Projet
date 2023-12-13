#ifndef __GENERATEUR_FLOTTABILITE_CUBOIDE_H__
#define __GENERATEUR_FLOTTABILITE_CUBOIDE_H__

#include "../../cuboide/Cuboide.h"
#include "../../force/GenerateurForce.h"

class GenerateurFlottabiliteCuboide : public GenerateurForce
{
private:
	double niveauLiquide;
	double densiteLiquide;

public:
	GenerateurFlottabiliteCuboide(double niveauLiquide, double densiteLiquide);
	void actualiserForce(CorpsRigide* corps) override;
};

#endif