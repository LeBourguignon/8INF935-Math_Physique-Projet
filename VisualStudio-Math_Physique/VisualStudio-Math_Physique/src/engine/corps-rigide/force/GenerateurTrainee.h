#ifndef __GENERATEUR_TRAINEE_H__
#define __GENERATEUR_TRAINEE_H__

#include "GenerateurForce.h"

class GenerateurTrainee : public GenerateurForce
{
private:
	double k1, k2;

public:
	GenerateurTrainee(double k1, double k2);
	void actualiserForce(CorpsRigide* corps) override;
};
#endif