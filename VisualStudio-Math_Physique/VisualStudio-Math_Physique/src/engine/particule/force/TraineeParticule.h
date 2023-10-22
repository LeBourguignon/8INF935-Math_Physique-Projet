#ifndef __TRAINEE_PARTICULE_H__
#define __TRAINEE_PARTICULE_H__

#include "GenerateurForceParticule.h"

class TraineeParticule : public GenerateurForceParticule
{
private:
	double k1, k2;
public:
	TraineeParticule(double k1, double k2);
	void actualiserForce(Particule* particule, float duration);

};

#endif