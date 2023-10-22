#include "TraineeParticule.h"

TraineeParticule::TraineeParticule(double k1, double k2)
	: k1(k1), k2(k2)
{
}

void TraineeParticule::actualiserForce(Particule* particule, float duration)
{
	// forceTrainee = - P.direction * ( k1 * P.norme + k2 * P.norme * P.norme)
	Vecteur3D ForceTrainee = -particule->velocite.direction() * (k1 * particule->velocite.norme() + k2 * particule->velocite.norme() * particule->velocite.norme());
	particule->force = particule->force + ForceTrainee;
	
}


