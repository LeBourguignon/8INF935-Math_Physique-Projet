#include "Particule.h"

#include <iostream>
#include "Constant.h"

Particule::Particule()  
    : Particule(Vecteur3D(), Vecteur3D(), Vecteur3D(), 0)
{
}

Particule::Particule(Vecteur3D position, Vecteur3D velocite , Vecteur3D acceleration)
    : Particule(position, velocite, acceleration, 0)
{
}

Particule::Particule(double masse)
    : Particule(Vecteur3D(), Vecteur3D(), Vecteur3D(), masse)
{
}

Particule::Particule(Vecteur3D position, Vecteur3D velocite, Vecteur3D acceleration, double masse)
{
    this->position      = position;
    this->velocite      = velocite;
    this->acceleration  = acceleration;

    if (masse == 0)
    {
        // Message d'erreur
        std::cout << "Erreur : Masse nulle, masse defini a 'infini' par defaut" << std::endl;
        this->inverseMasse = 0;         // Masse = infini -> inverseMasse = 0
    }
    else
    {
        this->inverseMasse = 1 / masse;
    }
}

void Particule::actualiser(double duration)
{
    // Mise à jour position
    this->position = this->position + this->velocite * duration + this->acceleration * 0.5 * duration * duration;
    // Mise à jour vitesse
    this->velocite = this->velocite * facteurAmortissement + this->acceleration * duration;
}