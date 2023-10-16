#include "RessortParticule.h"
#include "Vecteur3D.h"
#include "Particule.h"


RessortParticule::RessortParticule(double k, double l0, Particule *attache){
    this->k = k;
    this->l0 = l0;
    this->attache = attache;
    this->fixe = false;
}

RessortParticule::RessortParticule(double k, double l0, Vecteur3D attache){
    this->k = k;
    this->l0 = l0;
    this->attache = new Particule(attache, Vecteur3D(), Vecteur3D());
    this->fixe = true;
}

RessortParticule::~RessortParticule(){
    if (this->fixe){
        delete this->attache;
    }
}

void RessortParticule::ActualiserForce(Particule* p, float duration){
    Vecteur3D distance = p->position - this->attache->position;
    Vecteur3D force = distance.direction() * (-this->k * (distance.norme() - this->l0));
    p->acceleration = p->acceleration + force;
}
