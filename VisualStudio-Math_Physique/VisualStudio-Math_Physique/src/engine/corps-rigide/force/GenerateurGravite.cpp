#include "GenerateurGravite.h"

GenerateurGravite::GenerateurGravite(Vecteur3D gravite)
    : gravite(gravite)
{
}

void GenerateurGravite::actualiserForce(CorpsRigide* corps)
{
    corps->ajouterForce(gravite * corps->getMass());
}