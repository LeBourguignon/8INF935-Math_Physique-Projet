#include "GenerateurFlottabilite.h"


GenerateurFlottabilite::GenerateurFlottabilite(double hauteurObjet, double volumeObjet, double niveauLiquide, double densiteLiquide)
    : hauteurObjet(hauteurObjet), volumeObjet(volumeObjet), niveauLiquide(niveauLiquide), densiteLiquide(densiteLiquide)
{
}

void GenerateurFlottabilite::actualiserForce(CorpsRigide* corps)
{
    double d = -(corps->position.y -this->niveauLiquide - this->hauteurObjet) / (2 * this->hauteurObjet);
    Vecteur3D force = Vecteur3D();
    if (d <= 0)
    {
        force.y = 0;
    }
    else if (d >= 1)
    {
        force.y = this->volumeObjet * this->densiteLiquide;
    }
    else
    {
        force.y = d * this->volumeObjet * this->densiteLiquide;
    }
    corps->ajouterForce(force);
}

