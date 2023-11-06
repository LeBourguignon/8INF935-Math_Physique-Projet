#include "CorpsRigide.h"
#include "../Constant.h"

CorpsRigide::CorpsRigide()
	: CorpsRigide(Vecteur3D(), Quaternion(), 0)
{
}

CorpsRigide::CorpsRigide(Vecteur3D position, Quaternion orientation, double masse)
	: CorpsRigide(position, orientation, Vecteur3D(), Vecteur3D(), masse)
{
}

CorpsRigide::CorpsRigide(Vecteur3D position, Quaternion orientation, Vecteur3D velocite, Vecteur3D velociteAngulaire, double masse)
	: position(position), velocite(velocite), acceleration(Vecteur3D()), force(Vecteur3D()),
	orientation(orientation), velociteAngulaire(velociteAngulaire), accelerationAngulaire(Vecteur3D()), torque(Vecteur3D()),
	inverseMasse((masse == 0) ? 0 : 1 / masse)
{
}

void CorpsRigide::actualiser(double duration)
{
	// Mise � jour de l'acc�l�ration
	this->acceleration = this->force * this->inverseMasse;

	// Mise � jour de l'acc�l�ration angulaire
	// TODO


	// Mise � jour de la position
	this->position = this->position + this->velocite * duration + this->acceleration * 0.5 * duration * duration;

	// Mise � jour de l'orientation
	this->orientation.actualisationParVelociteAngulaire(this->velociteAngulaire, duration); // TODO



	// Mise � jour de la vitesse
	this->velocite = this->velocite * Constant::facteurAmortissement + this->acceleration * duration;

	// Mise � jour de la rotation
	this->velociteAngulaire = this->velociteAngulaire * Constant::facteurAmortissement + this->accelerationAngulaire * duration;



	// R�inisilisation de la force
	this->force = Vecteur3D();

	// R�inisilisation du torque
	this->torque = Vecteur3D();
}

double CorpsRigide::getMass()
{
	return (this->inverseMasse == 0) ? Constant::masseInfinie : (1 / this->inverseMasse);
}

Matrix34 CorpsRigide::getTransformMatrix() const
{
	return Matrix34(); // TODO
}
