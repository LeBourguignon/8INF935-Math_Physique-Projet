#include "RessortFixeParticule.h"
#include "Vecteur3D.h"
#include "Particule.h"


RessortFixeParticule::RessortFixeParticule(double k, double l0, Vecteur3D attache){
    this->k = k;
    this->l0 = l0;
    this->attache = attache;
}

void RessortFixeParticule::ActualiserForce(Particule* p, float duration){
    Vecteur3D distance = p->position - this->attache;
    Vecteur3D force = distance.direction() * (-this->k * (distance.norme() - this->l0));
    p->acceleration = p->acceleration + force * p->inverseMasse;
}
