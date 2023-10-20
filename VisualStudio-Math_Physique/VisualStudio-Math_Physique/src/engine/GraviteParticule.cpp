#include "GraviteParticule.h"
#include "Vecteur3D.h"

void GraviteParticule::actualiserForce(Particule* particule, float duration)
{
    Vecteur3D force = m_gravite * particule->getMass();

    particule->acceleration = particule->acceleration + ( force * particule->inverseMasse );
    // mise à jour de la position et de le vitesse
    //particule->actualiser(duration); 
}


    /*
    p->position     = depend de la vitesse en fonction du temps
    p->velocite     = depend de l'acc en fonction du temps
    p->acceleration = depend de la force en fonction du temps
    */