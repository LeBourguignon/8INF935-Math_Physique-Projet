#include "GenerateurTrainee.h"

GenerateurTrainee::GenerateurTrainee(double k1, double k2)
	: k1(k1), k2(k2)
{
}

void GenerateurTrainee::actualiserForce(CorpsRigide* corps)
{
	Vecteur3D forceTrainee = -corps->velocite.direction() * (k1 * corps->velocite.norme() + k2 * corps->velocite.norme() * corps->velocite.norme());
	corps->ajouterForce(forceTrainee);
}
