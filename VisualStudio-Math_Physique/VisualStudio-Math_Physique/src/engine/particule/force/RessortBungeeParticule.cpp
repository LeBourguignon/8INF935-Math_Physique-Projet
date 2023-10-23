#include "RessortBungeeParticule.h"

RessortBungeeParticule::RessortBungeeParticule(double k, double l0, Particule* attache) 
    : k(k), l0(l0), attache(attache)
{
}

void RessortBungeeParticule::actualiserForce(Particule* particule, float duration)
{
    Vecteur3D distance = particule->position - this->attache->position;

    if (distance.norme() > this->l0)
    {
        Vecteur3D force = distance.direction() * (-this->k * (distance.norme() - this->l0));
        particule->force = particule->force + force;
    }
}