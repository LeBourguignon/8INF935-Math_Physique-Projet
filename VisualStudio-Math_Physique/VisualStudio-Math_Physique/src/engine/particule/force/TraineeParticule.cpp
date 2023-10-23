#include "TraineeParticule.h"

TraineeParticule::TraineeParticule(double k1, double k2)
	: k1(k1), k2(k2)
{
}

void TraineeParticule::actualiserForce(Particule* particule, float duration)
{
	Vecteur3D forceTrainee = -particule->velocite.direction() * (k1 * particule->velocite.norme() + k2 * particule->velocite.norme() * particule->velocite.norme());
	particule->force = particule->force + forceTrainee;
}


