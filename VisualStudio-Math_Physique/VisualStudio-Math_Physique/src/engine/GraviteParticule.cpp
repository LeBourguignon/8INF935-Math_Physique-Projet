#include "GraviteParticule.h"

GraviteParticule::GraviteParticule(Vecteur3D gravite)
    : gravite(gravite)
{
}

void GraviteParticule::actualiserForce(Particule* particule, float duration)
{
    particule->force = particule->force + (gravite * particule->getMass());
}