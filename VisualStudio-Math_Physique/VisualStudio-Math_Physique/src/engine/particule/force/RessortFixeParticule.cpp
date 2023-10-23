#include "RessortFixeParticule.h"

RessortFixeParticule::RessortFixeParticule(double k, double l0, Vecteur3D attache)
    : k(k), l0(l0), attache(attache)
{
}

void RessortFixeParticule::actualiserForce(Particule* particule, float duration)
{
    Vecteur3D distance = particule->position - this->attache;
    Vecteur3D force = distance.direction() * (-this->k * (distance.norme() - this->l0));
    particule->force = particule->force + force;
}