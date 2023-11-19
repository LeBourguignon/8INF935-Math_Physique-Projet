#include "Particule.h"

#include <iostream>
#include "../Constant.h"

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
    : position(position), velocite(velocite), acceleration(acceleration), force(), inverseMasse((masse == 0) ? 0 : 1 / masse)
{
}

void Particule::actualiser(double duration)
{
    // Mise à jour de l'accélération
    this->acceleration = this->force * this->inverseMasse;

    // Mise à jour de la position
    this->position = this->position + this->velocite * duration + this->acceleration * 0.5 * duration * duration;

    // Mise à jour de la vitesse
    this->velocite = this->velocite * Constant::facteurAmortissementLineaire + this->acceleration * duration;

    // Réinisilisation de la force
    this->force = Vecteur3D();
}

double Particule::getMass()
{
    return (this->inverseMasse == 0) ? Constant::masseInfinie : (1 / this->inverseMasse);
}
