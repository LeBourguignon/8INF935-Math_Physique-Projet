#include "RessortBungeeParticule.h"
#include "Vecteur3D.h"
#include "Particule.h"

void RessortBungeeParticule::ActualiserForce(Particule* p, float duration)
{
    Vecteur3D distance = p->position - this->attache->position;
    Vecteur3D force = distance.direction() * (-this->k * (distance.norme() - this->l0));
    p->acceleration = p->acceleration + force;
}
