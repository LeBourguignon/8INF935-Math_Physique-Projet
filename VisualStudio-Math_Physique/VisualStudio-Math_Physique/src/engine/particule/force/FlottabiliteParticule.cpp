#include "FlottabiliteParticule.h"
#include "../../Vecteur3D.h"
#include "../Particule.h"


FlottabiliteParticule::FlottabiliteParticule(double profondeurMaxObjet, double volumeObjet, double niveauLiquide, double densiteLiquide){
    this->profondeurMaxObjet = profondeurMaxObjet;
    this->volumeObjet = volumeObjet;
    this->niveauLiquide = niveauLiquide;
    this->densiteLiquide = densiteLiquide;
}

void FlottabiliteParticule::ActualiserForce(Particule* p, float duration){
    double d = (p->position.y - this->niveauLiquide - this->profondeurMaxObjet) / (2 * this->profondeurMaxObjet);
    Vecteur3D force = Vecteur3D();
    if (d <= 0){
        force.y = 0;
    }else if (d >= 1){
        force.y = this->volumeObjet * this->densiteLiquide;
    }else{
        force.y = d * this->volumeObjet * this->densiteLiquide;
    }
    p->acceleration = p->acceleration + force * p->inverseMasse;
}
