#ifndef __GENERATEUR_GRAVITE_H__
#define __GENERATEUR_GRAVITE_H__

#include "GenerateurForce.h"

class GenerateurGravite : public GenerateurForce
{
private:
	Vecteur3D gravite;

public:
	GenerateurGravite(Vecteur3D gravite);

	void actualiserForce(CorpsRigide* corps) override;
};

#endif