#include "RessortFixeParticule.h"

#include "Vecteur3D.h"
#include "Particule.h"

RessortFixeParticule::RessortFixeParticule(double k, double l0, Vecteur3D attache){
    this->k = k;
    this->l0 = l0;
    this->attache = attache;
}

void RessortFixeParticule::actualiserForce(Particule* particule, float duration){
    Vecteur3D distance = particule->position - this->attache;
    Vecteur3D force = distance.direction() * (-this->k * (distance.norme() - this->l0));
    particule->acceleration = particule->acceleration + force * particule->inverseMasse/* * duration*/;
}