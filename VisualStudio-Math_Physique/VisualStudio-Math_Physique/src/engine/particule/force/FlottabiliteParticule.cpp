#include "FlottabiliteParticule.h"
#include "../../Vecteur3D.h"
#include "../Particule.h"


FlottabiliteParticule::FlottabiliteParticule(double hauteurObjet, double volumeObjet, double niveauLiquide, double densiteLiquide){
    this->hauteurObjet = hauteurObjet;
    this->volumeObjet = volumeObjet;
    this->niveauLiquide = niveauLiquide;
    this->densiteLiquide = densiteLiquide;
}

void FlottabiliteParticule::actualiserForce(Particule* particule, float duration){
    double d = -(particule->position.y - this->niveauLiquide - this->hauteurObjet) / (2 * this->hauteurObjet);
    Vecteur3D force = Vecteur3D();
    if (d <= 0)
    {
        force.y = 0;
    }else if (d >= 1)
    {
        force.y = this->volumeObjet * this->densiteLiquide;
    }else
    {
        force.y = d * this->volumeObjet * this->densiteLiquide;
    }
    particule->force = particule->force + force;
}
